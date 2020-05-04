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

module correlator (
	TX,
	RX,
	pulse_in,
	pulse_out,
	clki,
	integration_clk_pulse,
	active_line
	);

parameter SECOND = 1000000000;
parameter CLK_FREQUENCY = 50000000;
parameter PLL_FREQUENCY = 400000000;
parameter BAUD_RATE = 230400;

parameter RESOLUTION = 16;
parameter NUM_INPUTS = 12;
parameter MAX_DELAY = 1;
parameter NUM_CORRELATORS = NUM_INPUTS*(NUM_INPUTS-1)/2;

output wire TX;
input wire RX;
input wire[NUM_INPUTS-1:0] pulse_in;
output wire[NUM_INPUTS-1:0] pulse_out;
output wire integration_clk_pulse;
output wire[31:0] active_line;
input wire clki;
wire clk;
wire[NUM_INPUTS-1:0] in;

pll pll_block (clki, clk);


delay1 #(.RESOLUTION(NUM_INPUTS)) delay(clk, ~pulse_in, in);
assign pulse_out = ~in&~pulse_in;

main #(.CLK_FREQUENCY(CLK_FREQUENCY), .PLL_FREQUENCY(PLL_FREQUENCY), .RESOLUTION(RESOLUTION), .NUM_INPUTS(NUM_INPUTS), .BAUD_RATE(BAUD_RATE), .MAX_DELAY(MAX_DELAY)) main_block(
	TX,
	RX,
	pulse_out,
	clki,
	clk,
	integration_clk_pulse,
	active_line
);
endmodule
