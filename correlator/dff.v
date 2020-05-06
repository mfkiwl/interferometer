`timescale 1 ns / 1 ps

module delay1 (
	clk,
	d,
	q
);
parameter RESOLUTION=1;
input wire clk;
input wire[RESOLUTION-1:0] d;
output reg[RESOLUTION-1:0] q;

always @ ( posedge clk)
	begin
		q <= d;
	end
endmodule

