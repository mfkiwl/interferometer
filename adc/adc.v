/*
 *   SDR - Verilog code for a software defined radio using an FPGA
 *   Copyright (C) 2017  Ilia Platone <info@iliaplatone.com>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WAR

RANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

`timescale 1 ns / 1 ps

module ADC (
	comparator_in,
	out,
	clk,
	underflow,
	overflow,
	enable
);
	parameter RESOLUTION = 10;
	
	input wire comparator_in;
	output reg[RESOLUTION-1:0] out;
	input wire clk;
	output reg underflow;
	output reg overflow;
	input wire enable;
	
	always @ (negedge clk) begin
		if(enable) begin
			if(comparator_in) begin
				if(out>0) begin
					out <= out-1;
					underflow <= 0;
					overflow <= 0;
				end else begin
					underflow <= 1;
					overflow <= 0;
				end 
			end else begin
				if(out<(1<<RESOLUTION)-1) begin
					out <= out+1;
					underflow <= 0;
					overflow <= 0;
				end else begin
					underflow <= 0;
					overflow <= 1;
				end 
			end
		end
	end
	
endmodule
