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
	pulse_out,
	pll_clk,
	clk,
	clki,
	integration_clk,
	leds
);

parameter SECOND = 1000000000;
parameter CLK_FREQUENCY = 15200000;
parameter PLL_FREQUENCY = 448000000;
parameter TICK_FREQUENCY = 448000000;

parameter BAUD_RATE = 57600;
parameter SHIFT = 1;

parameter DELAY_SIZE = 200;
parameter RESOLUTION = 16;
parameter NUM_INPUTS = 8;
parameter NUM_BASELINES = NUM_INPUTS*(NUM_INPUTS-1)/2;
parameter[63:0] UNIT = SECOND/TICK_FREQUENCY;

parameter CORRELATIONS_SIZE = NUM_BASELINES;
parameter PAYLOAD_SIZE = (CORRELATIONS_SIZE+NUM_INPUTS+NUM_INPUTS)*RESOLUTION;
parameter HEADER_SIZE = 64;
parameter PACKET_SIZE = HEADER_SIZE+PAYLOAD_SIZE;

parameter BAUD_TIME = (SECOND>>SHIFT)/BAUD_RATE;

parameter MAX_COUNT=(1<<RESOLUTION);
parameter TOTAL_NIBBLES=NUM_BASELINES*RESOLUTION/4;

output wire TX;
input wire RX;
input wire[NUM_INPUTS-1:0] pulse_in;
output reg[NUM_INPUTS-1:0] pulse_out;
input wire pll_clk;
input wire clki;
output wire clk;
output wire integration_clk;
output reg[31:0] leds;
wire [NUM_INPUTS-1:0] overflow;

wire clk_pulse;
wire [7:0] RXREG;
wire RXIF;
wire[PAYLOAD_SIZE-1:0] pulse_t;
reg[PACKET_SIZE-1:0] tx_data;
wire[NUM_INPUTS-1:0] delay_lines [0:DELAY_SIZE-1];
reg [15:0] delay [0:NUM_INPUTS-1];
wire uart_clk;
wire uart_clk_pulse;

reg transmit_enable = 0;
reg[3:0] index = 0;
reg[3:0] baud_rate = 0;
reg[3:0] clock_divider = 0;

CLK_GEN #(.CLK_FREQUENCY(PLL_FREQUENCY)) divider_block(
	UNIT<<clock_divider,
	clk,
	pll_clk,
	clk_pulse,
	1'b1
);

CLK_GEN #(.CLK_FREQUENCY(CLK_FREQUENCY)) data_clock_block(
	BAUD_TIME>>baud_rate,
	uart_clk,
	clki,
	uart_clk_pulse,
	1'b1
);

TX_WORD #(.SHIFT(SHIFT), .RESOLUTION(PACKET_SIZE)) tx_block(
	TX,
	tx_data,
	uart_clk_pulse,
	integration_clk,
	transmit_enable
);
 
wire reset_delayed;
delay1 reset_delay(clk, integration_clk, reset_delayed);
integer k;

always@(posedge integration_clk) begin
	pulse_out <= overflow;
	tx_data[0+:PAYLOAD_SIZE] <= pulse_t;
	tx_data[PAYLOAD_SIZE+:32] <= (TICK_FREQUENCY>>clock_divider);
	tx_data[PAYLOAD_SIZE+32+:12] <= DELAY_SIZE;
	tx_data[PAYLOAD_SIZE+32+12+:8] <= 1;
	tx_data[PAYLOAD_SIZE+32+12+8+:4] <= NUM_INPUTS-1;
	tx_data[PAYLOAD_SIZE+32+12+8+4+:8] <= RESOLUTION;
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
	SET_FREQ_DIV = 8,
	ENABLE_CAPTURE = 13;
	
always@(posedge RXIF) begin
	if (RXREG[3:0] == CLEAR) begin
		delay[index] <= 0;
	end else if (RXREG[3:0] == ENABLE_CAPTURE) begin
		transmit_enable <= RXREG[4];
	end else if (RXREG[3:0] == SET_INDEX) begin
		index <= RXREG[7:4];
	end else if (RXREG[3:0] == SET_LEDS) begin
		leds[index*2+:2] <= RXREG[5:4];
	end else if (RXREG[3:0] == SET_BAUD_RATE) begin
		baud_rate <= RXREG[7:4];
	end else if (RXREG[2]) begin
		delay[index][(RXREG[4+:2]*4)+:4] <= RXREG[7:4];
	end else if (RXREG[3])  begin
		clock_divider <= RXREG[7:4]|(RXREG[2:0]<<4);
	end
end

assign delay_lines[0] = pulse_in;
generate
	genvar a;
	genvar b;
	genvar d;
	for(d=1; d<DELAY_SIZE; d=d+1) begin : delay_iteration_block
		delay1 #(.RESOLUTION(NUM_INPUTS)) delay_line(clk, delay_lines[d-1], delay_lines[d]);
	end
	for (a=0; a<NUM_INPUTS; a=a+1) begin : correlators_initial_block
		COUNTER #(.RESOLUTION(RESOLUTION)) counters_block (
			(1<<RESOLUTION)-1,
			pulse_t[RESOLUTION*(CORRELATIONS_SIZE+NUM_INPUTS+a)+:RESOLUTION],
			overflow[a],
			delay_lines[0][a],
			reset_delayed
		);
		COUNTER #(.RESOLUTION(RESOLUTION)) spectra_block (
			(1<<RESOLUTION)-1,
			pulse_t[RESOLUTION*(CORRELATIONS_SIZE+a)+:RESOLUTION],
			,
			delay_lines[0][a]&delay_lines[(delay[a]<DELAY_SIZE?delay[a]:(DELAY_SIZE-1))][a],
			reset_delayed
		);
		for (b=a+1; b<NUM_INPUTS; b=b+1) begin : correlators_block
			COUNTER #(.RESOLUTION(RESOLUTION)) counters_block (
				(1<<RESOLUTION)-1,
				pulse_t[(a*(NUM_INPUTS+NUM_INPUTS-a-1)/2+b-a-1)*RESOLUTION+:RESOLUTION],
				,
				delay_lines[(delay[a]<DELAY_SIZE?delay[a]:(DELAY_SIZE-1))][a]&delay_lines[(delay[b]<DELAY_SIZE?delay[b]:(DELAY_SIZE-1))][b],
				reset_delayed
			);
		end
	end
endgenerate

endmodule
