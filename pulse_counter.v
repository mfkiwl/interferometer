`timescale 1 ns / 1 ps

module pulse_counter (
	in,
	n_pulses,
	clk,
	reset
);

parameter DATA_WIDTH=1;
parameter RESOLUTION = 32;

input wire[DATA_WIDTH-1:0] in;
output wire [RESOLUTION-1:0] n_pulses;
input wire clk;
input wire reset;

COUNTER #(.RESOLUTION(RESOLUTION)) counter (
		(64'd1<<RESOLUTION)-1,
		n_pulses,
		in,
		,
		clk,
		reset
	);

endmodule
