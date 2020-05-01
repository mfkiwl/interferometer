`timescale 1 ns / 1 ps

module main (
	TX,
	RX,
	pulse_in,
	clki,
	clk,
	integration_clk,
	active_line
);

parameter SECOND = 1000000000;
parameter CLK_FREQUENCY = 12000000;
parameter PLL_FREQUENCY = 420000000;
parameter BAUD_RATE = 230400;
parameter BAUD_TIME = SECOND/BAUD_RATE;

parameter RESOLUTION = 8;
parameter MAX_DELAY = 50;
parameter DELAY_LINES = MAX_DELAY|1;
parameter NUM_INPUTS = 8;

parameter NUM_CORRELATORS=NUM_INPUTS*(NUM_INPUTS-1)/2;
parameter MAX_COUNT=(1<<RESOLUTION);
parameter TOTAL_NIBBLES=NUM_CORRELATORS*RESOLUTION/4;

parameter INTEGRATION_TIME = BAUD_TIME*10*RESOLUTION*DELAY_LINES*(NUM_CORRELATORS+NUM_INPUTS);

output wire TX;
input wire RX;
input wire[NUM_INPUTS-1:0] pulse_in;
input wire clk;
input wire clki;
output wire integration_clk;

wire [7:0] RXREG;
wire RXIF;
wire[(RESOLUTION*(DELAY_LINES*NUM_CORRELATORS+NUM_INPUTS))-1:0] pulse_t;
reg[((NUM_CORRELATORS*DELAY_LINES+NUM_INPUTS)*RESOLUTION+64)-1:0] tx_data;
reg[7:0] ridx;
wire[NUM_INPUTS-1:0] delay_lines [0:DELAY_LINES-1];

wire uart_clk;
wire uart_clk_pulse;

output reg[31:0] active_line = 0;
reg[63:0] integration_time = 0;
reg transmit_enable = 0;

reg[31:0] _active_line = 0;
reg[63:0] _integration_time = 0;
reg _transmit_enable = 0;

reg[63:0] timeleft = 0;

wire sample_clk;

initial begin
	active_line <= 0;
	_active_line <= 0;
end

CLK_GEN #(.RESOLUTION(64), .CLK_FREQUENCY(CLK_FREQUENCY)) uart_clock_block(
	BAUD_TIME,
	uart_clk,
	clki,
	uart_clk_pulse,
	1'b1
);

TX_WORD #(.RESOLUTION((NUM_CORRELATORS*DELAY_LINES+NUM_INPUTS)*RESOLUTION+64)) tx_block(
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

uart_rx rx_block(
	RX,
	RXREG,
	6'd8,
	RXIF,
	uart_clk_pulse
);

parameter[3:0]
	RESET = 0,
	SET_INTEGRATION_TIME = 1,
	SET_ACTIVE_LINE = 2,
	SET_LEDS = 3,
	ENABLE_MODULES = 12,
	COMMIT = 13;
	
always@(posedge RXIF) begin
	if (RXREG[3:0] == RESET) begin
		if (RXREG[7:4] == SET_INTEGRATION_TIME) begin
			_integration_time <= 0;
		end
		if (RXREG[7:4] == ENABLE_MODULES) begin
			_transmit_enable <= 0;
		end
		ridx <= 0;
	end else if (RXREG[3:0] == COMMIT) begin
		integration_time <= _integration_time;
		transmit_enable <= _transmit_enable;
		ridx <= 0;
	end else if (RXREG[3:0] == SET_INTEGRATION_TIME) begin
		_integration_time[ridx+:4] <= RXREG[7:4];
		ridx <= ridx+3'd4;
	end else if (RXREG[3:0] == ENABLE_MODULES) begin
		_transmit_enable <= RXREG[4];
	end else if (RXREG[3:0] == SET_ACTIVE_LINE) begin
		_active_line <= RXREG[7:4];
	end else if (RXREG[3:0] == SET_LEDS) begin
		active_line[_active_line*2+:2] <= RXREG[5:4];
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
generate
	genvar f;
	genvar l;
	genvar d;
	for (l=0; l<NUM_INPUTS; l=l+1) begin : correlators_initial_block
		for(f=0; f<DELAY_LINES; f=f+1) begin : delay_initial_block
			delay1 delay_line(clk, pulse_in[l], delay_lines[f][l]);
		end
		for (d=l+1; d<NUM_INPUTS; d=d+1) begin : correlators_block
			for(f=0; f<DELAY_LINES; f=f+1) begin : delay_initial_block2
				pulse_counter #(.RESOLUTION(RESOLUTION)) counters_block (
					delay_lines[f][l]&delay_lines[DELAY_LINES-1-f][d],
					pulse_t[(l*(NUM_INPUTS+NUM_INPUTS-l-1)/2+d-l-1)*RESOLUTION*DELAY_LINES+f*RESOLUTION+:RESOLUTION],
					reset_delayed
				);
			end
		end
	end
endgenerate

endmodule
