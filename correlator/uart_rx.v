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

module uart_rx(
	rx,
	dout,
	rx_done,
	clk
);

input wire rx;
output reg [7:0] dout;
output reg rx_done;
input wire clk;

reg [4:0] state;
reg [5:0] bit_count;

parameter [5:0]
    IDLE   = 5'd0,
    DATA  = 5'd1,
    STOP  = 5'd2;

always@(posedge clk) begin
	case(state)
		IDLE:
		begin
			rx_done <= 0;
			if(!rx) begin
				bit_count <= 4'd0;
				dout <= 0;
               state <= DATA;
			end
		end
		STOP:
		begin
			rx_done <= 1;
			state <= IDLE;
		end
		DATA:
		begin
			rx_done <= 0;
			dout[bit_count] <= rx;
			bit_count <= bit_count + 4'd1;
			if(bit_count == 7) begin
				rx_done <= 1;
				state <= IDLE;
			end
		end
	endcase
end

endmodule

