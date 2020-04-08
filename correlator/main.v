`timescale 1 ns / 1 ps

module main (
	TX,
	RX,
	in,
	clk,
	sample_clk_pulse,
	integration_clk_pulse
);

parameter SECOND = 1000000000;
parameter INITIAL_ACTIVE_LINE = 0;
parameter INITIAL_SAMPLE_TIME = 20;
parameter INITIAL_INTEGRATION_TIME = 20000;
parameter[0:0] INITIAL_TRANSMIT_ENABLE = 1'b0;
parameter[0:0] INITIAL_SAMPLE_CLOCK_ENABLE = 1'b0;
parameter[0:0] INITIAL_INTEGRATION_CLOCK_ENABLE = 1'b0;

parameter CLK_FREQUENCY = 50000000;
parameter RESOLUTION = 12;
parameter MAX_DELAY = 500;
parameter DELAY_LINES = MAX_DELAY|1;
parameter NUM_INPUTS = 8;
parameter BAUD_RATE = 230400;

parameter BAUD_TIME = SECOND/BAUD_RATE;
parameter NUM_CORRELATORS=NUM_INPUTS*(NUM_INPUTS-1)/2;
parameter MAX_COUNT=(1<<RESOLUTION);
parameter TOTAL_NIBBLES=NUM_CORRELATORS*RESOLUTION/4;

output wire TX;
input wire RX;
input wire[NUM_INPUTS-1:0] in;
input wire clk;
output wire sample_clk_pulse;
output wire integration_clk_pulse;

wire [7:0] RXREG;
wire RXIF;
wire[(RESOLUTION*NUM_INPUTS*DELAY_LINES*NUM_CORRELATORS)-1:0] pulse_t;
reg[(RESOLUTION*NUM_INPUTS*DELAY_LINES*NUM_CORRELATORS)-1:0] tx_data;
reg[7:0] ridx;

wire uart_clk;
wire uart_clk_pulse;

reg[63:0] active_line = INITIAL_ACTIVE_LINE;
reg[63:0] sample_time = INITIAL_SAMPLE_TIME;
reg[63:0] integration_time = INITIAL_INTEGRATION_TIME;
reg transmit_enable = INITIAL_TRANSMIT_ENABLE;
reg sample_clock_enable = INITIAL_SAMPLE_CLOCK_ENABLE;
reg integration_clock_enable = INITIAL_INTEGRATION_CLOCK_ENABLE;

reg[63:0] _active_line = INITIAL_ACTIVE_LINE;
reg[63:0] _sample_time = INITIAL_SAMPLE_TIME;
reg[63:0] _integration_time = INITIAL_INTEGRATION_TIME;
reg _transmit_enable = INITIAL_TRANSMIT_ENABLE;
reg _sample_clock_enable = INITIAL_SAMPLE_CLOCK_ENABLE;
reg _integration_clock_enable = INITIAL_INTEGRATION_CLOCK_ENABLE;

wire sample_clk;
wire integration_clk;
reg reset_correlator = 0;

initial begin
active_line <= INITIAL_ACTIVE_LINE;
sample_time <= INITIAL_SAMPLE_TIME;
integration_time <= INITIAL_INTEGRATION_TIME;
transmit_enable <= INITIAL_TRANSMIT_ENABLE;
sample_clock_enable <= INITIAL_SAMPLE_CLOCK_ENABLE;
integration_clock_enable <= INITIAL_INTEGRATION_CLOCK_ENABLE;

_active_line <= INITIAL_ACTIVE_LINE;
_sample_time <= INITIAL_SAMPLE_TIME;
_integration_time <= INITIAL_INTEGRATION_TIME;
_transmit_enable <= INITIAL_TRANSMIT_ENABLE;
_sample_clock_enable <= INITIAL_SAMPLE_CLOCK_ENABLE;
_integration_clock_enable <= INITIAL_INTEGRATION_CLOCK_ENABLE;
end

CLK_GEN #(.CLK_FREQUENCY(CLK_FREQUENCY)) uart_clock_block(
	BAUD_TIME,
	uart_clk,
	clk,
	uart_clk_pulse,
	1'b1
);

TX_WORD #(.RESOLUTION(RESOLUTION*(NUM_CORRELATORS+NUM_INPUTS))) tx_block(
	TX,
	tx_data,
	uart_clk_pulse,
	transmit_enable
);
	
always@(negedge clk) begin
	if(integration_clk_pulse) begin
		tx_data <= pulse_t;
		reset_correlator <= 1;
	end else
		reset_correlator <= 0;
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
	SET_INITIAL_INTEGRATION_TIME = 1,
	SET_INITIAL_SAMPLE_TIME = 2,
	SET_INITIAL_ACTIVE_LINE = 3,
	ENABLE_MODULES = 12,
	COMMIT = 13;
	
always@(posedge RXIF) begin
	if (RXREG[3:0] == RESET) begin
		if (RXREG[7:4] == SET_INITIAL_SAMPLE_TIME) begin
			_sample_time <= INITIAL_ACTIVE_LINE;
		end
		if (RXREG[7:4] == SET_INITIAL_INTEGRATION_TIME) begin
			_integration_time <= INITIAL_INTEGRATION_TIME;
		end
		if (RXREG[7:4] == SET_INITIAL_ACTIVE_LINE) begin
			_active_line <= INITIAL_ACTIVE_LINE;
		end
		if (RXREG[7:4] == ENABLE_MODULES) begin
			_transmit_enable <= INITIAL_TRANSMIT_ENABLE;
			_integration_clock_enable <= INITIAL_INTEGRATION_CLOCK_ENABLE;
			_sample_clock_enable <= INITIAL_SAMPLE_CLOCK_ENABLE;
		end
		ridx <= 0;
	end else if (RXREG[3:0] == COMMIT) begin
		sample_time <= _sample_time;
		active_line <= _active_line;
		integration_time <= _integration_time;
		transmit_enable <= _transmit_enable;
		integration_clock_enable <= _integration_clock_enable;
		sample_clock_enable <= _sample_clock_enable;
		ridx <= 0;
	end else if (RXREG[3:0] == SET_INITIAL_SAMPLE_TIME) begin
		_sample_time[ridx+:4] <= RXREG[7:4];
		ridx <= ridx+3'd4;
	end else if (RXREG[3:0] == SET_INITIAL_ACTIVE_LINE) begin
		_active_line[ridx+:4] <= RXREG[7:4];
		ridx <= ridx+3'd4;
	end else if (RXREG[3:0] == SET_INITIAL_INTEGRATION_TIME) begin
		_integration_time[ridx+:4] <= RXREG[7:4];
		ridx <= ridx+3'd4;
	end else if (RXREG[3:0] == ENABLE_MODULES) begin
		_transmit_enable <= RXREG[6];
		_integration_clock_enable <= RXREG[5];
		_sample_clock_enable <= RXREG[4];
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
	integration_time,
	integration_clk,
	clk,
	integration_clk_pulse,
	integration_clock_enable
);
	
generate
	genvar i;
	genvar j;
	genvar l;
	genvar d;
	for (i=0; i<NUM_INPUTS; i=i+1) begin : correlators_initial_block
		pulse_counter #(.RESOLUTION(RESOLUTION), .DATA_WIDTH(1)) counters_block (
			in[i],
			pulse_t[RESOLUTION*(NUM_CORRELATORS*DELAY_LINES+i)+:RESOLUTION],
			sample_clk_pulse,
			reset_correlator
		);
		for (j=i+1; j<NUM_INPUTS; j=j+1) begin : correlators_block
			intensity_correlator #(.RESOLUTION(RESOLUTION), .MAX_DELAY(DELAY_LINES), .DATA_WIDTH(1)) correlator(
				in[i],
				in[j],
				pulse_t[(RESOLUTION*DELAY_LINES)*(i*(NUM_INPUTS+(NUM_INPUTS-i-3))/2+j-1)+:RESOLUTION*DELAY_LINES],
				sample_clk_pulse,
				reset_correlator
			);
		end
	end
endgenerate

endmodule
