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

module COUNTER (
		counter_max,
		counter_out,
		increment,
		overflow,
		clk,
		reset
	);
	parameter RESOLUTION=64;
	input wire [RESOLUTION-1:0] counter_max;
	output reg [RESOLUTION-1:0] counter_out;
	input wire [RESOLUTION-1:0] increment;
	output wire overflow;
	input wire clk;
	input wire reset;
	assign overflow = (counter_out == counter_max);
	reg _reset;
	always @(posedge (_reset^clk))
	begin
		if(~_reset) begin
			if (counter_out < counter_max)
				counter_out <= counter_out + increment;
		end else begin
			counter_out <= 0;
		end
	end
	
	always @(*) begin
		if(reset)
			_reset <= 1;
		else if(!counter_out)
			_reset <= 0;
	end
		
endmodule
