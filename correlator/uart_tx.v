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

module uart_tx(
	tx,
	din,
	tx_done,
	tx_start,
	clk
);

output reg tx;
input wire [7:0] din;
output reg tx_done;
input wire tx_start;
input wire clk;

reg [4:0] state;
reg [5:0] bit_count;

parameter [5:0]
    IDLE   = 5'd0,
    DATA  = 5'd2,
    STOP  = 5'd3;

always@(posedge clk) begin
	case(state)
		IDLE:
		begin
			tx_done <= 0;
			if(tx_start) begin
				bit_count <= 4'd0;
				tx <= 1'b0;
               state <= DATA;
			end else begin
				tx <= 1'b1;
				bit_count <= 4'd0;
				state <= IDLE;
			end
		end
		DATA:
		begin
			tx_done <= 0;
			tx <= din[bit_count];
			bit_count <= bit_count + 4'd1;
            if(bit_count == 7)
				state <= STOP;
		end
		STOP:
		begin
			tx_done <= 1;
			tx <= 1'b1;
			bit_count <= 4'd0;
			state <= IDLE;
		end
	endcase
end

endmodule
