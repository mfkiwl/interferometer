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

module pulse_counter (
	in,
	n_pulses,
	reset
);

parameter RESOLUTION = 32;

input wire in;
output wire [RESOLUTION-1:0] n_pulses;
input wire reset;

COUNTER #(.RESOLUTION(RESOLUTION)) counter (
		(64'd1<<RESOLUTION)-1,
		n_pulses,
		1'd1,
		,
		in,
		reset
	);

endmodule
