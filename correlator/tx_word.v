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

module TX_WORD(
	TX,
	tx_data,
	clk,
	done,
	enable
	);

parameter RESOLUTION=32;
parameter TOTAL_NIBBLES=RESOLUTION/4;

output wire TX;
input wire [RESOLUTION-1:0] tx_data;
input wire enable;
output reg done;
input wire clk;

reg signed [31:0] tidx;
wire TXIF;
reg [7:0] TXREG;

uart_tx tx_block(
	TX,
	TXREG,
	TXIF,
	enable,
	clk
);

always@(posedge TXIF) begin
	if(tidx>=0) begin
		if(tx_data[tidx*4+:4] < 4'ha) TXREG <= tx_data[tidx*4+:4] | 8'h30;
		else TXREG <= (tx_data[tidx*4+:4]-4'ha) | 8'h41;
		tidx <= tidx-1;
		done <= 0;
	end else begin
		TXREG <= 8'h0d;
		tidx <= TOTAL_NIBBLES-1;
		done <= 1;
	end
end
endmodule
