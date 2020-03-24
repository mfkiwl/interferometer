`timescale 1 ns / 1 ps

module delay1 (
	clk,
	d,
	q
);
parameter BPS=1;
input wire clk;
input wire[BPS-1:0] d;
output reg[BPS-1:0] q;

always @ ( posedge clk)
	begin
		q <= d;
	end
endmodule

