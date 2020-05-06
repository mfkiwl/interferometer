`timescale 1 ns / 1 ps

module CLK_GEN 
	(
		clk_out,
		clk,
		overflow,
		enable
	);
	parameter[63:0] CLK_FREQUENCY = 64'd420000000;
	parameter[63:0] FREQUENCY = 64'd1000000000;
	parameter[63:0] UNIT = CLK_FREQUENCY/FREQUENCY;
	parameter[63:0] RESOLUTION = 64;
	
	output reg clk_out;
	input wire clk;
	input wire enable;
	
	output reg overflow;

	reg [63:0] nanoseconds;
	
	always @(posedge clk)
	begin
		if(enable) begin
			if(nanoseconds >= UNIT) begin
				clk_out <= ~clk_out;
				nanoseconds <= 0;
				overflow <= 1;
			end else begin
				overflow <= 0;
				nanoseconds <= nanoseconds+1;
			end
		end else begin
			overflow <= 0;
			clk_out <= 0;
		end
	end
endmodule
