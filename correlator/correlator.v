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

module correlator (
	TX,
	RX,
	pulse_in,
	pwr_leds,
	leds,
	integration_clk_pulse,
	active_line,
	clki
	);

parameter SECOND = 1000000000;
parameter CLK_FREQUENCY = 14800000;
parameter PLL_FREQUENCY = 448000000;

parameter BAUD_RATE = 57600;
parameter SHIFT = 1;

parameter MAX_DELAY = 256;
parameter RESOLUTION = 20;
parameter NUM_INPUTS = 8;
parameter MAX_JITTER = 200;
parameter NUM_CORRELATORS = NUM_INPUTS*(NUM_INPUTS-1)/2;

output wire TX;
input wire RX;
input wire[NUM_INPUTS-1:0] pulse_in;
output reg[NUM_INPUTS-1:0] pwr_leds;
output reg[7:0] leds;
output wire integration_clk_pulse;
output wire[31:0] active_line;
input wire clki;
wire clko;
wire[NUM_INPUTS-1:0] in;
wire[NUM_INPUTS-1:0] out;

pll pll_block (clki, pll_clk);

delay1 #(.RESOLUTION(NUM_INPUTS)) delay(clko, ~pulse_in, in);
assign out = ~in&~pulse_in;

always@(*) begin
	pwr_leds <= 8'hff;
	leds <= 8'hff;
end

main #(.CLK_FREQUENCY(CLK_FREQUENCY), .PLL_FREQUENCY(PLL_FREQUENCY), .SHIFT(SHIFT), .RESOLUTION(RESOLUTION), .NUM_INPUTS(NUM_INPUTS), .BAUD_RATE(BAUD_RATE), .MAX_JITTER(MAX_JITTER), .MAX_DELAY(MAX_DELAY)) main_block(
	TX,
	RX,
	out,
	pll_clk,
	clki,
	clko,
	integration_clk_pulse,
	active_line
);
endmodule
