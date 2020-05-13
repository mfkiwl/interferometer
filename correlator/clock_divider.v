/*
    AHP Interferometer - a telescope array firmware
    Copyright (C) 2020  Ilia Platone

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

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
