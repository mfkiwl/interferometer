module intensity_correlator(
	in1,
	in2,
	out,
	clk,
	reset
);
	parameter MAX_DELAY = 501;
	parameter RESOLUTION = 32;
	parameter DATA_WIDTH = 1;
	
	input wire [DATA_WIDTH-1:0] in1;
	input wire [DATA_WIDTH-1:0] in2;
	output wire [RESOLUTION*MAX_DELAY-1:0] out;
	input wire clk;
	input wire reset;
	
	wire [MAX_DELAY*RESOLUTION-1:0] line1;
	wire [MAX_DELAY*RESOLUTION-1:0] line2;
	assign line1[0+:RESOLUTION] = in1;
	assign line2[0+:RESOLUTION] = in2;
	generate
		genvar i;
		for (i=0; i<MAX_DELAY; i=i+1) begin : intensity_correlator_block
			if(i > 0) begin
				delay1 #(.RESOLUTION(RESOLUTION)) delay_1_block(clk, line1[RESOLUTION*(i-1)+:RESOLUTION], line1[RESOLUTION*i+:RESOLUTION]);
				delay1 #(.RESOLUTION(RESOLUTION)) delay_2_block(clk, line2[RESOLUTION*(i-1)+:RESOLUTION], line2[RESOLUTION*i+:RESOLUTION]);
			end
			COUNTER #(.RESOLUTION(RESOLUTION)) counter_block(
				(1<<RESOLUTION)-1,
				out[RESOLUTION*i+:RESOLUTION],
				line1[RESOLUTION*(i)+:RESOLUTION]*line2[RESOLUTION*(MAX_DELAY-i-1)+:RESOLUTION],
				overflow,
				clk,
				reset
			);
		end
	endgenerate
endmodule
