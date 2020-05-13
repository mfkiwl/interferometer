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
