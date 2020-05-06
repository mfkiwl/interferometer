`timescale 1 ns / 1 ps

module main (
	TX,
	RX,
	pulse_in,
	clki,
	clk,
	integration_clk,
	leds
);

parameter SHIFT = 1;
parameter SECOND = 1000000000;
parameter CLK_FREQUENCY = 50000000;
parameter PLL_FREQUENCY = 400000000;
parameter BAUD_RATE = 230400;

parameter RESOLUTION = 16;
parameter MAX_DELAY = 21;
parameter DELAY_LINES = MAX_DELAY|1;
parameter NUM_INPUTS = 4;

parameter NUM_CORRELATORS=NUM_INPUTS*(NUM_INPUTS-1)/2;
parameter MAX_COUNT=(1<<RESOLUTION);
parameter TOTAL_NIBBLES=NUM_CORRELATORS*RESOLUTION/4;

output wire TX;
input wire RX;
input wire[NUM_INPUTS-1:0] pulse_in;
input wire clk;
input wire clki;
output wire integration_clk;
output reg[31:0] leds;

wire [7:0] RXREG;
wire RXIF;
wire[(RESOLUTION*(DELAY_LINES*NUM_CORRELATORS+NUM_INPUTS))-1:0] pulse_t;
reg[((NUM_CORRELATORS*DELAY_LINES+NUM_INPUTS)*RESOLUTION+64)-1:0] tx_data;
reg[7:0] ridx;
wire[NUM_INPUTS-1:0] delay_lines [0:DELAY_LINES-1];

wire uart_clk;
wire uart_clk_pulse;

reg transmit_enable = 0;
reg[3:0] active_line = 0;

CLK_GEN #(.RESOLUTION(64), .CLK_FREQUENCY(CLK_FREQUENCY), .FREQUENCY(BAUD_RATE<<SHIFT)) uart_clock_block(
	uart_clk,
	clki,
	uart_clk_pulse,
	1'b1
);

TX_WORD #(.SHIFT(SHIFT), .RESOLUTION((NUM_CORRELATORS*DELAY_LINES+NUM_INPUTS)*RESOLUTION+64)) tx_block(
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
	tx_data[0+:(NUM_CORRELATORS*DELAY_LINES+NUM_INPUTS)*RESOLUTION] <= pulse_t;
	tx_data[(NUM_CORRELATORS*DELAY_LINES+NUM_INPUTS)*RESOLUTION+:32] <= active_line;
	tx_data[(NUM_CORRELATORS*DELAY_LINES+NUM_INPUTS)*RESOLUTION+32+:8] <= DELAY_LINES;
	tx_data[(NUM_CORRELATORS*DELAY_LINES+NUM_INPUTS)*RESOLUTION+32+8+:8] <= NUM_INPUTS;
	tx_data[(NUM_CORRELATORS*DELAY_LINES+NUM_INPUTS)*RESOLUTION+32+8+8+:8] <= RESOLUTION;
	tx_data[(NUM_CORRELATORS*DELAY_LINES+NUM_INPUTS)*RESOLUTION+32+8+8+8+:8] <= 0;
end

uart_rx #(.SHIFT(SHIFT)) rx_block(
	RX,
	RXREG,
	RXIF,
	uart_clk_pulse
);

parameter[3:0]
	SET_ACTIVE_LINE = 1,
	SET_LEDS = 2,
	ENABLE_CAPTURE = 13;
	
always@(posedge RXIF) begin
	if (RXREG[3:0] == ENABLE_CAPTURE) begin
		transmit_enable <= RXREG[4];
	end else if (RXREG[3:0] == SET_ACTIVE_LINE) begin
		active_line <= RXREG[7:4];
	end else if (RXREG[3:0] == SET_LEDS) begin
		leds[active_line*2+:2] <= RXREG[5:4];
	end
end

generate
	genvar i;
	genvar j;
	for (i=0; i<NUM_INPUTS; i=i+1) begin : counters_initial_block
		pulse_counter #(.RESOLUTION(RESOLUTION)) counters_block (
			pulse_in[i],
			pulse_t[(NUM_CORRELATORS*DELAY_LINES+i)*RESOLUTION+:RESOLUTION],
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
	for(d=1; d<DELAY_LINES; d=d+1) begin : delay_initial_block
		delay1 #(.RESOLUTION(NUM_INPUTS)) delay_line(clk, delay_lines[d-1], delay_lines[d]);
	end
	for (a=0; a<NUM_INPUTS; a=a+1) begin : correlators_initial_block
		for (b=a+1; b<NUM_INPUTS; b=b+1) begin : correlators_block
			for(l=0; l<DELAY_LINES; l=l+1) begin : delay_initial_block2
				pulse_counter #(.RESOLUTION(RESOLUTION)) counters_block (
					delay_lines[l][a]&delay_lines[DELAY_LINES-1-l][b],
					pulse_t[(a*(NUM_INPUTS+NUM_INPUTS-a-1)/2+b-a-1)*RESOLUTION*DELAY_LINES+l*RESOLUTION+:RESOLUTION],
					reset_delayed
				);
			end
		end
	end
endgenerate

endmodule
