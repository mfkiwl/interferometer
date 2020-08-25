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

module uart_tx(
	tx,
	din,
	tx_done,
	tx_start,
	clk
);

parameter SHIFT=0;
parameter WORD_WIDTH=8;
parameter STOP_BITS=1;

output reg tx;
input wire [WORD_WIDTH-1:0] din;
output reg tx_done;
input wire tx_start;
input wire clk;

reg [5+SHIFT:0] bit_count = (WORD_WIDTH+STOP_BITS)<<SHIFT;

always@(posedge clk) begin
	case(bit_count[SHIFT+:6])
		WORD_WIDTH+STOP_BITS:
		begin
			tx_done <= 0;
			if(tx_start) begin
				bit_count <= 0;
				tx <= 0;
			end else begin
				tx <= 1;
			end
		end
		WORD_WIDTH:
		begin
			tx_done <= 1;
			tx <= 1;
			bit_count <= bit_count+1;
		end
		default:
		begin
			tx_done <= 0;
			tx <= din[bit_count[SHIFT+:6]];
			bit_count <= bit_count+1;
		end
	endcase
end

endmodule
