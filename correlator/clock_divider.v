/******************************************************************************
**  Verilog 12-channel intensity correlator
**  Copyright (C) 2018-2020  Ilia Platone

**  This program is free software: you can redistribute it and/or modify
**  it under the terms of the GNU General Public License as published by
**  the Free Software Foundation, either version 3 of the License, or
**  (at your option) any later version.

**  This program is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**  GNU General Public License for more details.

**  You should have received a copy of the GNU General Public License
**  along with this program.  If not, see <https://www.gnu.org/licenses/>.
******************************************************************************/

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
