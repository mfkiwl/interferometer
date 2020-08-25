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
	pulse_out,
	leds,
	integration_clk_pulse,
	active_line,
	clki
	);

parameter SECOND = 1000000000;
parameter CLK_FREQUENCY = 50000000;
parameter PLL_FREQUENCY = 400000000;

parameter BAUD_RATE = 57600;
parameter SHIFT = 1;

parameter DELAY_SIZE = 200;
parameter RESOLUTION = 16;
parameter NUM_INPUTS = 12;
parameter NUM_CORRELATORS = NUM_INPUTS*(NUM_INPUTS-1)/2;

output wire TX;
input wire RX;
input wire[NUM_INPUTS-1:0] pulse_in;
output wire[NUM_INPUTS-1:0] pulse_out;
output reg[7:0] leds;
output wire integration_clk_pulse;
output wire[31:0] active_line;
input wire clki;
wire clk;
wire pll_clk;
wire[NUM_INPUTS-1:0] in;
wire[NUM_INPUTS-1:0] out;
reg[7:0] sine[0:100];
wire pwm_clk;
wire sin_clk;
wire[NUM_INPUTS-1:0] overflow;
wire[NUM_INPUTS-1:0] pwm_out;
reg[6:0] pwm_idx;
reg[3:0] x;
pll pll_block (clki, pll_clk);

delay1 #(.RESOLUTION(NUM_INPUTS)) delay(clk, ~pulse_in, in);
assign out = ~in&~pulse_in;
assign pulse_out = pwm_out&~overflow;
main #(.CLK_FREQUENCY(CLK_FREQUENCY), .PLL_FREQUENCY(PLL_FREQUENCY), .SHIFT(SHIFT), .RESOLUTION(RESOLUTION), .NUM_INPUTS(NUM_INPUTS), .BAUD_RATE(BAUD_RATE), .DELAY_SIZE(DELAY_SIZE)) main_block(
	TX,
	RX,
	out,
	overflow,
	pll_clk,
	clk,
	clki,
	integration_clk_pulse,
	active_line
);

CLK_GEN #(.CLK_FREQUENCY(PLL_FREQUENCY)) pwm_clock(
	5000,
	pwm_clk,
	pll_clk,
	,
	1'b1
);

CLK_GEN #(.CLK_FREQUENCY(100000)) sin_clock(
	50000000,
	sin_clk,
	pwm_clk,
	,
	1'b1
);

always @(posedge sin_clk) begin
	pwm_idx <= pwm_idx+1;
	if(pwm_idx == 99) begin
		pwm_idx <= 0;
	end
end

generate
genvar i;
	for(i = 0; i < NUM_INPUTS; i=i+1) begin
		PWM #(.RESOLUTION(8)) pwm(
			sine[(pwm_idx+(100/NUM_INPUTS)*i)%100]+32,
			pwm_out[NUM_INPUTS-1-i],
			pwm_clk,
			1'b1
		);
	end
endgenerate

always@(*) begin
	leds <= 8'hff;
	sine[0] <= 95;
	sine[1] <= 101;
	sine[2] <= 107;
	sine[3] <= 113;
	sine[4] <= 119;
	sine[5] <= 125;
	sine[6] <= 130;
	sine[7] <= 136;
	sine[8] <= 141;
	sine[9] <= 146;
	sine[10] <= 151;
	sine[11] <= 156;
	sine[12] <= 160;
	sine[13] <= 165;
	sine[14] <= 169;
	sine[15] <= 172;
	sine[16] <= 176;
	sine[17] <= 179;
	sine[18] <= 181;
	sine[19] <= 184;
	sine[20] <= 186;
	sine[21] <= 187;
	sine[22] <= 189;
	sine[23] <= 190;
	sine[24] <= 190;
	sine[25] <= 190;
	sine[26] <= 190;
	sine[27] <= 190;
	sine[28] <= 189;
	sine[29] <= 188;
	sine[30] <= 186;
	sine[31] <= 184;
	sine[32] <= 181;
	sine[33] <= 179;
	sine[34] <= 176;
	sine[35] <= 172;
	sine[36] <= 169;
	sine[37] <= 165;
	sine[38] <= 160;
	sine[39] <= 156;
	sine[40] <= 151;
	sine[41] <= 146;
	sine[42] <= 141;
	sine[43] <= 136;
	sine[44] <= 130;
	sine[45] <= 125;
	sine[46] <= 119;
	sine[47] <= 113;
	sine[48] <= 107;
	sine[49] <= 101;
	sine[50] <= 95;
	sine[51] <= 89;
	sine[52] <= 83;
	sine[53] <= 77;
	sine[54] <= 71;
	sine[55] <= 65;
	sine[56] <= 60;
	sine[57] <= 54;
	sine[58] <= 49;
	sine[59] <= 44;
	sine[60] <= 39;
	sine[61] <= 34;
	sine[62] <= 30;
	sine[63] <= 25;
	sine[64] <= 21;
	sine[65] <= 18;
	sine[66] <= 14;
	sine[67] <= 11;
	sine[68] <= 9;
	sine[69] <= 6;
	sine[70] <= 4;
	sine[71] <= 3;
	sine[72] <= 1;
	sine[73] <= 0;
	sine[74] <= 0;
	sine[75] <= 0;
	sine[76] <= 0;
	sine[77] <= 0;
	sine[78] <= 1;
	sine[79] <= 2;
	sine[80] <= 4;
	sine[81] <= 6;
	sine[82] <= 9;
	sine[83] <= 11;
	sine[84] <= 14;
	sine[85] <= 18;
	sine[86] <= 21;
	sine[87] <= 25;
	sine[88] <= 30;
	sine[89] <= 34;
	sine[90] <= 39;
	sine[91] <= 44;
	sine[92] <= 49;
	sine[93] <= 54;
	sine[94] <= 60;
	sine[95] <= 65;
	sine[96] <= 71;
	sine[97] <= 77;
	sine[98] <= 83;
	sine[99] <= 89;
end

endmodule
