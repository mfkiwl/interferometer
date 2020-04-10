module correlator (
	TX,
	RX,
	pulse_in,
	npulse_in,
	bunch_out,
	clki,
	sample_clk_pulse,
	integration_clk_pulse
	);

parameter SECOND = 1000000000;

parameter CLK_FREQUENCY = 50000000;
parameter BAUD_RATE = 230400;

parameter RESOLUTION = 20;
parameter NUM_INPUTS = 10;
parameter MAX_DELAY = 250;
parameter NUM_CORRELATORS=NUM_INPUTS*(NUM_INPUTS-1)/2;

output wire TX;
input wire RX;
input wire[NUM_INPUTS-1:0] pulse_in;
input wire[NUM_INPUTS-1:0] npulse_in;
output wire[NUM_CORRELATORS-1:0] bunch_out;
output wire sample_clk_pulse;
output wire integration_clk_pulse;
input wire clki;

reg [NUM_INPUTS-1:0] in;

always @(*) begin
	in <= pulse_in | ~npulse_in;
end

wire clk;
pll pll_block(
	clki,
	clk
);

main #(.CLK_FREQUENCY(CLK_FREQUENCY), .RESOLUTION(RESOLUTION), .NUM_INPUTS(NUM_INPUTS), .BAUD_RATE(BAUD_RATE), .MAX_DELAY(MAX_DELAY)) main_block(
	TX,
	RX,
	in,
	bunch_out,
	clk,
	sample_clk_pulse,
	integration_clk_pulse
);
endmodule
