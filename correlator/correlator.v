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

parameter RESOLUTION = 32;
parameter NUM_INPUTS = 16;
parameter MAX_DELAY = 250;

output wire TX;
input wire RX;
input wire[NUM_INPUTS-1:0] pulse_in;
output wire sample_clk_pulse;
output wire integration_clk_pulse;
input wire clki;

wire clk;
pll pll_block(
		clki,
		clk
	);
	
main #(.CLK_FREQUENCY(CLK_FREQUENCY), .RESOLUTION(RESOLUTION), .NUM_INPUTS(NUM_INPUTS), .BAUD_RATE(BAUD_RATE), .MAX_DELAY(MAX_DELAY)) main_block(
	TX,
	RX,
	in,
	clki,
	sample_clk_pulse,
	integration_clk_pulse
);
endmodule
