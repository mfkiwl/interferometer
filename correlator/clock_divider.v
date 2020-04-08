`timescale 1 ns / 1 ps

module CLK_GEN 
	(
		ns,
		clk_out,
		clk,
		overflow,
		enable
	);
	parameter[63:0] CLK_FREQUENCY = 64'd420000000;
	parameter[63:0] SECOND = 64'd1000000000;
	parameter[63:0] UNIT = SECOND/CLK_FREQUENCY;
	parameter[63:0] RESOLUTION = 64;
	
	input wire [63:0] ns;
	output reg clk_out;
	input wire clk;
	input wire enable;
	
	output reg overflow;

	reg [63:0] nanoseconds;
	
	always @(posedge clk)
	begin
		if(enable) begin
			if(nanoseconds >= ns) begin
				clk_out <= ~clk_out;
				nanoseconds <= 0;
				overflow <= 1;
			end else begin
				overflow <= 0;
				nanoseconds <= nanoseconds+UNIT;
			end
		end else begin
			overflow <= 0;
			clk_out <= 0;
		end
	end
endmodule
