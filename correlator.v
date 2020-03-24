module correlator (
	TX,
	RX,
	in,
	clki,
	clko
	);

parameter SECOND = 1000000000;
parameter BAUDRATE = 230400;
parameter UART_TAU = SECOND/BAUDRATE;
parameter CLK_FREQUENCY = 50000000;
parameter RESOLUTION = 12;
parameter ADC_RESOLUTION = 8;
parameter NUM_INPUTS = 10;

output wire TX;
input wire RX;
input wire[NUM_INPUTS-1:0] in;
input wire clki;
output wire clko;

wire uart_clk;
wire uart_clk_pulse;

CLK_GEN #(.CLK_FREQUENCY(CLK_FREQUENCY)) uart_clock_block(
	UART_TAU,
	uart_clk,
	clki,
	uart_clk_pulse,
	1'b1
);

main #(.CLK_FREQUENCY(CLK_FREQUENCY), .RESOLUTION(RESOLUTION), .ADC_RESOLUTION(ADC_RESOLUTION), .NUM_INPUTS(NUM_INPUTS)) main_block(
	TX,
	RX,
	in,
	clki,
	clko,
	uart_clk_pulse
);
endmodule
