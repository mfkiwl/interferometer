module intensity_correlator(
	in1,
	in2,
	out,
	clk,
	reset
);
	parameter MAX_DELAY = 501;
	parameter RESOLUTION = 32;
	
	input wire in1;
	input wire in2;
	output reg [RESOLUTION*MAX_DELAY-1:0] out;
	input wire clk;
	input wire reset;
	reg _reset;
	wire [MAX_DELAY-1:0] line1;
	wire [MAX_DELAY-1:0] line2;
	assign line1[0] = in1;
	assign line2[0] = in2;
	generate
		genvar i;
		for (i=0; i<MAX_DELAY; i=i+1) begin : intensity_correlator_block
			if(i > 0) begin
				delay1 #(.RESOLUTION(1)) delay_1_block(clk, line1[i-1], line1[i]);
				delay1 #(.RESOLUTION(1)) delay_2_block(clk, line2[i-1], line2[i]);
			end
			always @ (posedge (line1[i]&line2[MAX_DELAY-1-i])) begin
				if(~_reset) begin
					if (out[i*RESOLUTION+:RESOLUTION] < (1<<RESOLUTION))
						out[i*RESOLUTION+:RESOLUTION] <= out[i*RESOLUTION+:RESOLUTION] + 1;
				end else begin
					out[i*RESOLUTION+:RESOLUTION] <= 0;
				end
			end
		end
	endgenerate
	
	always @(*) begin
		if(reset)
			_reset <= 1;
		else if(!out)
			_reset <= 0;
		else
			_reset <= 0;
	end
endmodule
