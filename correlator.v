module correlator (
	TX,
	RX,
	in,
	clk,
	sample_clk_pulse,
	integration_clk_pulse
	);

parameter SECOND = 1000000000;

parameter CLK_FREQUENCY = 50000000;
parameter RESOLUTION = 12;
parameter NUM_INPUTS = 12;
parameter ADC_RESOLUTION = 6;
parameter BAUD_RATE = 230400;

output wire TX;
input wire RX;
input wire[NUM_INPUTS*ADC_RESOLUTION-1:0] in;
input wire clk;
output wire sample_clk_pulse;
output wire integration_clk_pulse;

main #(.CLK_FREQUENCY(CLK_FREQUENCY), .RESOLUTION(RESOLUTION), .NUM_INPUTS(NUM_INPUTS), .ADC_RESOLUTION(ADC_RESOLUTION), .BAUD_RATE(BAUD_RATE)) main_block(
	TX,
	RX,
	in,
	clk,
	sample_clk_pulse,
	integration_clk_pulse
);
endmodule
