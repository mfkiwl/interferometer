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
