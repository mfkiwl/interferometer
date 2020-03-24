`timescale 1 ns / 1 ps

module main (
	TX,
	RX,
	in,
	clk,
	sample_clk,
	uart_clk
);

parameter CLK_FREQUENCY = 50000000;
parameter RESOLUTION = 16;
parameter ADC_RESOLUTION = 8;
parameter NUM_INPUTS=8;
parameter NUM_CORRELATORS=NUM_INPUTS*(NUM_INPUTS-1)/2;
parameter INITIAL_INTEGRATION = 64'd1000000000;
parameter MAX_COUNT=(1<<RESOLUTION);
parameter TOTAL_NIBBLES=NUM_CORRELATORS*RESOLUTION/4;

output wire TX;
input wire RX;
input wire[NUM_INPUTS-1:0] in;
input wire clk;
input wire uart_clk;
output wire sample_clk;

wire[NUM_INPUTS-1:0] sample_received;
wire [NUM_INPUTS-1:0] conversion_completed;
wire [(NUM_INPUTS*ADC_RESOLUTION)-1:0] adc_out;
wire [7:0] RXREG;
wire RXIF;
wire[(RESOLUTION*(NUM_INPUTS+NUM_CORRELATORS))-1:0] pulse_t;
reg[(RESOLUTION*(NUM_INPUTS+NUM_CORRELATORS))-1:0] tx_data;
reg[7:0] ridx;

wire uart_clk_pulse;

reg[63:0] active_line = 0;
reg[63:0] sample_time = 20;
reg[63:0] integration_time = 20000;
reg transmit_enable = 0;
reg sample_clock_enable = 0;
reg integration_clock_enable = 0;

reg[63:0] _active_line = 0;
reg[63:0] _sample_time = 20;
reg[63:0] _integration_time = 20000;
reg _transmit_enable = 0;
reg _sample_clock_enable = 0;
reg _integration_clock_enable = 0;

wire sample_clk_pulse;
wire integration_clk;
wire integration_clk_pulse;
reg reset_correlator = 0;

initial begin
active_line = 0;
sample_time = 20;
integration_time = 20000;
transmit_enable = 0;
sample_clock_enable = 0;
integration_clock_enable = 0;

_active_line = 0;
_sample_time = 20;
_integration_time = 20000;
_transmit_enable = 0;
_sample_clock_enable = 0;
_integration_clock_enable = 0;
end

TX_WORD #(.RESOLUTION(RESOLUTION*(NUM_CORRELATORS+NUM_INPUTS))) tx_block(
	TX,
	tx_data,
	uart_clk,
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
    RXIF,
    uart_clk
);

parameter[3:0]
	RESET = 0,
	SET_INTEGRATION_TIME = 1,
	SET_SAMPLE_TIME = 2,
	SET_ACTIVE_LINE = 3,
	ENABLE_MODULES = 12,
	COMMIT = 13;
	
always@(posedge RXIF) begin
	if (RXREG[3:0] == RESET) begin
		if (RXREG[7:4] == SET_SAMPLE_TIME) begin
			_sample_time <= 0;
		end
		if (RXREG[7:4] == SET_INTEGRATION_TIME) begin
			_integration_time <= 0;
		end
		if (RXREG[7:4] == SET_ACTIVE_LINE) begin
			_active_line <= 0;
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
	end else if (RXREG[3:0] == SET_SAMPLE_TIME) begin
		_sample_time[ridx+:4] <= RXREG[7:4];
		ridx <= ridx+3'd4;
	end else if (RXREG[3:0] == SET_ACTIVE_LINE) begin
		_active_line[ridx+:4] <= RXREG[7:4];
		ridx <= ridx+3'd4;
	end else if (RXREG[3:0] == SET_INTEGRATION_TIME) begin
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
	sample_time/20,
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
		uart_rx input_block(
			in[i],
			adc_out[i*ADC_RESOLUTION+:ADC_RESOLUTION],
			sample_received[i],
			sample_clk
		);
		pulse_counter #(.RESOLUTION(RESOLUTION),.DATA_WIDTH(ADC_RESOLUTION)) counters_block (
			adc_out[i*ADC_RESOLUTION+:ADC_RESOLUTION],
			pulse_t[RESOLUTION*(NUM_CORRELATORS+i)+:RESOLUTION],
			sample_received[i],
			reset_correlator
		);
		for (j=i+1; j<NUM_INPUTS; j=j+1) begin : correlators_block
			pulse_counter #(.RESOLUTION(RESOLUTION),.DATA_WIDTH(ADC_RESOLUTION)) correlator_block (
				adc_out[j*ADC_RESOLUTION+:ADC_RESOLUTION]*adc_out[i*ADC_RESOLUTION+:ADC_RESOLUTION],
				pulse_t[RESOLUTION*(i*(NUM_INPUTS+NUM_INPUTS-i-3)/2+j-1)+:RESOLUTION],
				sample_received[i],
				reset_correlator
			);
		end
	end
endgenerate

endmodule
