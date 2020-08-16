
/*
    AHP Interferometer - a telescope array firmware
    Copyright (C) 2020  Ilia Platone

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

`timescale 1 ns / 1 ps

module main (
	TX,
	RX,
	pulse_in,
	pll_clk,
	clki,
	clko,
	integration_clk,
	leds
);

parameter SECOND = 1000000000;
parameter CLK_FREQUENCY = 14800000;
parameter PLL_FREQUENCY = 448000000;

parameter BAUD_RATE = 57600;
parameter SHIFT = 1;

parameter MAX_DELAY = 200;
parameter RESOLUTION = 16;
parameter NUM_INPUTS = 8;
parameter MAX_JITTER = 1;
parameter NUM_CORRELATORS = NUM_INPUTS*(NUM_INPUTS-1)/2;

parameter BAUD_TIME = (SECOND>>SHIFT)/BAUD_RATE;
 
parameter JITTER_LINES = MAX_JITTER|1;

parameter MAX_COUNT=(1<<RESOLUTION);
parameter TOTAL_NIBBLES=NUM_CORRELATORS*RESOLUTION/4;

output wire TX;
input wire RX;
input wire[NUM_INPUTS-1:0] pulse_in;
input wire pll_clk;
input wire clki;
output wire clko;
output wire integration_clk;
output reg[31:0] leds;

wire clk_pulse;
wire [7:0] RXREG;
wire RXIF;
wire[(RESOLUTION*(JITTER_LINES*NUM_CORRELATORS+NUM_INPUTS+NUM_INPUTS*MAX_DELAY))-1:0] pulse_t;
reg[((NUM_CORRELATORS*JITTER_LINES+NUM_INPUTS+NUM_INPUTS*MAX_DELAY)*RESOLUTION+64)-1:0] tx_data;
reg[7:0] ridx;
wire[NUM_INPUTS-1:0] jitter_lines [0:JITTER_LINES-1];
wire[NUM_INPUTS-1:0] delay_lines [0:MAX_DELAY-1];
reg [31:0] delay [0:NUM_INPUTS-1];
wire uart_clk;
wire uart_clk_pulse;

reg transmit_enable = 0;
reg[3:0] index = 0;
reg[3:0] baud_rate = 0;
reg[3:0] clock_divider = 0;

CLK_GEN #(.RESOLUTION(64), .CLK_FREQUENCY(CLK_FREQUENCY)) divider_block(
	64'd5<<clock_divider,
	clko,
	pll_clk,
	clk_pulse,
	1'b1
);

CLK_GEN #(.RESOLUTION(64), .CLK_FREQUENCY(CLK_FREQUENCY)) uart_clock_block(
	(BAUD_TIME>>baud_rate),
	uart_clk,
	clki,
	uart_clk_pulse,
	1'b1
);

TX_WORD #(.SHIFT(SHIFT), .RESOLUTION((NUM_INPUTS*MAX_DELAY+NUM_CORRELATORS*JITTER_LINES+NUM_INPUTS)*RESOLUTION+64)) tx_block(
	TX,
	tx_data,
	uart_clk_pulse,
	integration_clk,
	transmit_enable
);

wire reset_delayed;
delay1 reset_delay(clko, integration_clk, reset_delayed);
integer k;

always@(posedge integration_clk) begin
	tx_data[0+:(NUM_CORRELATORS*JITTER_LINES+NUM_INPUTS+NUM_INPUTS*MAX_DELAY)*RESOLUTION] <= pulse_t;
	tx_data[(NUM_CORRELATORS*JITTER_LINES+NUM_INPUTS+NUM_INPUTS*MAX_DELAY)*RESOLUTION+:28] <= 200000000>>clock_divider;
	tx_data[(NUM_CORRELATORS*JITTER_LINES+NUM_INPUTS+NUM_INPUTS*MAX_DELAY)*RESOLUTION+28+:12] <= MAX_DELAY;
	tx_data[(NUM_CORRELATORS*JITTER_LINES+NUM_INPUTS+NUM_INPUTS*MAX_DELAY)*RESOLUTION+40+:8] <= JITTER_LINES;
	tx_data[(NUM_CORRELATORS*JITTER_LINES+NUM_INPUTS+NUM_INPUTS*MAX_DELAY)*RESOLUTION+40+8+:8] <= NUM_INPUTS;
	tx_data[(NUM_CORRELATORS*JITTER_LINES+NUM_INPUTS+NUM_INPUTS*MAX_DELAY)*RESOLUTION+40+8+8+:8] <= RESOLUTION;
end

uart_rx #(.SHIFT(SHIFT)) rx_block(
	RX,
	RXREG,
	RXIF,
	uart_clk_pulse
);

parameter[3:0]
	CLEAR = 0,
	SET_INDEX = 1,
	SET_LEDS = 2,
	SET_BAUD_RATE = 3,
	SET_DELAY = 4,
	SET_FREQ_DIV = 5,
	ENABLE_CAPTURE = 13;
	
always@(posedge RXIF) begin
	if (RXREG[3:0] == CLEAR) begin
		ridx <= 0;
	end else if (RXREG[3:0] == ENABLE_CAPTURE) begin
		transmit_enable <= RXREG[4];
	end else if (RXREG[3:0] == SET_INDEX) begin
		index <= RXREG[7:4];
	end else if (RXREG[3:0] == SET_LEDS) begin
		leds[index*2+:2] <= RXREG[5:4];
	end else if (RXREG[3:0] == SET_DELAY) begin
		delay[index][ridx+:4] <= RXREG[5:4];
		ridx <= ridx+4;
	end else if (RXREG[3:0] == SET_BAUD_RATE) begin
		baud_rate <= RXREG[7:4];
	end else if (RXREG[3:0] == SET_FREQ_DIV) begin
		clock_divider <= RXREG[7:4];
	end
end

generate
	genvar i;
	genvar j;
	for (i=0; i<NUM_INPUTS; i=i+1) begin : counters_initial_block
		pulse_counter #(.RESOLUTION(RESOLUTION)) counters_block (
			pulse_in[i],
			pulse_t[(NUM_CORRELATORS*JITTER_LINES+i+NUM_INPUTS*MAX_DELAY)*RESOLUTION+:RESOLUTION],
			reset_delayed
		);
	end
endgenerate

assign delay_lines[0] = pulse_in;
generate
	genvar a;
	genvar b;
	genvar l;
	genvar d;
	genvar f;
	genvar s;
	genvar c;
	for(f=0; f<MAX_DELAY-1; f=f+2000) begin : delay_iteration_block
		for(d=f; d<MAX_DELAY-1 && d<f+1999; d=d+1) begin : delay_initial_block
			delay1 #(.RESOLUTION(NUM_INPUTS)) delay_line(clko, delay_lines[d], delay_lines[d+1]);
			for (c=0; c<NUM_INPUTS; c=c+1) begin : spectrograph_initial_block
				pulse_counter #(.RESOLUTION(RESOLUTION)) counters_block (
					delay_lines[0][c]&delay_lines[d][c],
					pulse_t[RESOLUTION*(c*MAX_DELAY+d)+:RESOLUTION],
					reset_delayed
				);
			end
		end
	end
	for (a=0; a<NUM_INPUTS; a=a+1) begin : correlators_initial_block
		delay1 #(.RESOLUTION(1)) jitter_line(clko, delay_lines[delay[a]][a], jitter_lines[0][a]);
		for(s=1; s<JITTER_LINES; s=s+1) begin : jitter_initial_block
			delay1 #(.RESOLUTION(1)) jitter_line(clko, jitter_lines[s-1][a], jitter_lines[s][a]);
		end
		for (b=a+1; b<NUM_INPUTS; b=b+1) begin : correlators_block
			for(l=0; l<JITTER_LINES; l=l+1) begin : jitter_initial_block2
				pulse_counter #(.RESOLUTION(RESOLUTION)) counters_block (
					jitter_lines[l][a]&jitter_lines[JITTER_LINES-1-l][b],
					pulse_t[(a*(NUM_INPUTS+NUM_INPUTS-a-1)/2+b-a-1)*RESOLUTION*JITTER_LINES+l*RESOLUTION+NUM_INPUTS*MAX_DELAY*RESOLUTION+:RESOLUTION],
					reset_delayed
				);
			end
		end
	end
endgenerate

endmodule
