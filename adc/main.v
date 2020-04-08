module HSP17 (
	comparator_in,
	out,
	clk,
	underflow,
	overflow,
	enable
);

parameter RESOLUTION = 24;
parameter CLK_FREQUENCY = 50000000;

output wire [RESOLUTION-1:0] out;
input wire comparator_in;
input wire clk;
output wire underflow;
output wire overflow;
input wire enable;
	
ADC #(.RESOLUTION(RESOLUTION)) adc_block(
	comparator_in,
	out,
	clk,
	underflow,
	overflow,
	enable
);

endmodule
