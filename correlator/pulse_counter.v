`timescale 1 ns / 1 ps

module pulse_counter (
	in,
	n_pulses,
	reset
);

parameter RESOLUTION = 32;

input wire in;
output wire [RESOLUTION-1:0] n_pulses;
input wire reset;

COUNTER #(.RESOLUTION(RESOLUTION)) counter (
		(64'd1<<RESOLUTION)-1,
		n_pulses,
		1'd1,
		,
		in,
		reset
	);

endmodule
