`timescale 1 ns / 1 ps

module main (
	TX,
	RX,
	pulse_in,
	clk,
	sample_clk_pulse,
	reset_correlator,
	active_line
);

parameter SECOND = 1000000000;
parameter CLK_FREQUENCY = 400000000;
parameter BAUD_RATE = 230400;
parameter BAUD_TIME = SECOND/BAUD_RATE;

parameter INITIAL_ACTIVE_LINE = 0;
parameter INITIAL_SAMPLE_TIME = 100;
parameter[0:0] INITIAL_TRANSMIT_ENABLE = 1'b0;
parameter[0:0] INITIAL_SAMPLE_CLOCK_ENABLE = 1'b0;

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
output wire sample_clk_pulse;
output wire reset_correlator;

wire [7:0] RXREG;
wire RXIF;
wire[(RESOLUTION*(DELAY_LINES*NUM_CORRELATORS+NUM_INPUTS))-1:0] pulse_t;
reg[32+(RESOLUTION*(DELAY_LINES*NUM_CORRELATORS+NUM_INPUTS))-1:0] tx_data;
reg[7:0] ridx;
wire[NUM_INPUTS-1:0] delay_lines [0:DELAY_LINES-1];

wire uart_clk;
wire uart_clk_pulse;

output reg[31:0] active_line = INITIAL_ACTIVE_LINE;
reg[63:0] sample_time = INITIAL_SAMPLE_TIME;
reg transmit_enable = INITIAL_TRANSMIT_ENABLE;
reg sample_clock_enable = INITIAL_SAMPLE_CLOCK_ENABLE;

reg[31:0] _active_line = INITIAL_ACTIVE_LINE;
reg[63:0] _sample_time = INITIAL_SAMPLE_TIME;
reg _transmit_enable = INITIAL_TRANSMIT_ENABLE;
reg _sample_clock_enable = INITIAL_SAMPLE_CLOCK_ENABLE;

wire sample_clk;
wire integration_clk;

initial begin
	active_line <= INITIAL_ACTIVE_LINE;
	sample_time <= INITIAL_SAMPLE_TIME;
	transmit_enable <= INITIAL_TRANSMIT_ENABLE;
	sample_clock_enable <= INITIAL_SAMPLE_CLOCK_ENABLE;

	_active_line <= INITIAL_ACTIVE_LINE;
	_sample_time <= INITIAL_SAMPLE_TIME;
	_transmit_enable <= INITIAL_TRANSMIT_ENABLE;
	_sample_clock_enable <= INITIAL_SAMPLE_CLOCK_ENABLE;
end

CLK_GEN #(.RESOLUTION(64), .CLK_FREQUENCY(CLK_FREQUENCY)) uart_clock_block(
	BAUD_TIME,
	uart_clk,
	clk,
	uart_clk_pulse,
	1'b1
);

TX_WORD #(.RESOLUTION(32+RESOLUTION*(DELAY_LINES*NUM_CORRELATORS+NUM_INPUTS))) tx_block(
	TX,
	tx_data,
	uart_clk_pulse,
	1'd1
);
	
wire reset_delayed;
delay1 reset_delay(clk, reset_correlator, reset_delayed);
integer k;

always@(posedge reset_correlator) begin
	if(transmit_enable) begin
		tx_data[7:0] = 8'h0;
		tx_data[15:8] = DELAY_LINES;
		tx_data[23:16] = NUM_INPUTS;
		tx_data[31:24] = RESOLUTION;
		tx_data[32+:(NUM_CORRELATORS*DELAY_LINES+NUM_INPUTS)*RESOLUTION] <= pulse_t;
	end else
		for (k=0;k<(NUM_CORRELATORS*DELAY_LINES+NUM_INPUTS)*RESOLUTION/4+8;k=k+1)
			tx_data[k*4+:4] <= 4'h5;
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
	SET_SAMPLE_TIME = 1,
	SET_ACTIVE_LINE = 2,
	ENABLE_MODULES = 12,
	COMMIT = 13;
	
always@(posedge RXIF) begin
	if (RXREG[3:0] == RESET) begin
		if (RXREG[7:4] == SET_SAMPLE_TIME) begin
			_sample_time <= INITIAL_SAMPLE_TIME;
		end
		if (RXREG[7:4] == SET_ACTIVE_LINE) begin
			_active_line <= INITIAL_ACTIVE_LINE;
		end
		if (RXREG[7:4] == ENABLE_MODULES) begin
			_transmit_enable <= INITIAL_TRANSMIT_ENABLE;
			_sample_clock_enable <= INITIAL_SAMPLE_CLOCK_ENABLE;
		end
		ridx <= 0;
	end else if (RXREG[3:0] == COMMIT) begin
		sample_time <= _sample_time;
		active_line <= _active_line;
		transmit_enable <= _transmit_enable;
		sample_clock_enable <= _sample_clock_enable;
		ridx <= 0;
	end else if (RXREG[3:0] == SET_SAMPLE_TIME) begin
		_sample_time[ridx+:4] <= RXREG[7:4];
		ridx <= ridx+3'd4;
	end else if (RXREG[3:0] == SET_ACTIVE_LINE) begin
		_active_line[ridx+:4] <= RXREG[7:4];
		ridx <= ridx+3'd4;
	end else if (RXREG[3:0] == ENABLE_MODULES) begin
		_transmit_enable <= RXREG[4];
		_sample_clock_enable <= RXREG[5];
	end
end

CLK_GEN #(.RESOLUTION(64), .CLK_FREQUENCY(CLK_FREQUENCY)) sample_clock_block
(
	sample_time,
	sample_clk,
	clk,
	sample_clk_pulse,
	sample_clock_enable
);

CLK_GEN #(.RESOLUTION(64), .CLK_FREQUENCY(CLK_FREQUENCY)) integration_clock_block
(
	INTEGRATION_TIME,
	integration_clk,
	clk,
	reset_correlator,
	sample_clock_enable
);

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
			delay1(clk, pulse_in[l], delay_lines[f][l]);
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
