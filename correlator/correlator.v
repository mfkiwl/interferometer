module correlator (
	TX,
	RX,
	pulse_in,
	clki,
	sample_clk_pulse,
	integration_clk_pulse
	);

parameter SECOND = 1000000000;

parameter CLK_FREQUENCY = 50000000;
parameter BAUD_RATE = 230400;

parameter RESOLUTION = 16;
parameter NUM_INPUTS = 14;
parameter MAX_DELAY = 1;
parameter NUM_CORRELATORS = NUM_INPUTS*(NUM_INPUTS-1)/2;

output wire TX;
input wire RX;
input wire[NUM_INPUTS-1:0] pulse_in;
output wire sample_clk_pulse;
output wire integration_clk_pulse;
input wire clki;

wire[NUM_INPUTS-1:0] in;

main #(.CLK_FREQUENCY(CLK_FREQUENCY), .RESOLUTION(RESOLUTION), .NUM_INPUTS(NUM_INPUTS), .BAUD_RATE(BAUD_RATE), .MAX_DELAY(MAX_DELAY)) main_block(
	TX,
	RX,
	~pulse_in,
	clki,
	sample_clk_pulse,
	integration_clk_pulse
);
endmodule
