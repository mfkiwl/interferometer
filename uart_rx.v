module uart_rx(
	rx,
	dout,
	rx_bits,
	rx_done,
	clk
);

parameter MAX_WORD_SIZE = 8;

input wire rx;
output reg [MAX_WORD_SIZE-1:0] dout;
input wire [5:0] rx_bits;
output reg rx_done;
input wire clk;

reg [4:0] state;
reg [5:0] bit_count;

parameter [5:0]
    IDLE   = 5'd0,
    DATA  = 5'd1,
    STOP  = 5'd2,
    DONE  = 5'd3;

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
		DATA:
		begin
			rx_done <= 0;
			dout[bit_count] <= rx;
			bit_count <= bit_count + 4'd1;
            if(bit_count == rx_bits-1)
				state <= STOP;
		end
		STOP:
		begin
			rx_done <= 0;
			if(rx)
				state <= DONE;
			else
				state <= IDLE;
		end
		DONE:
		begin
			rx_done <= 1;
			state <= IDLE;
		end
	endcase
end

endmodule

