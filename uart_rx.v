module uart_rx(
input wire rx,
output reg [7:0] dout,
output reg rx_done,
input wire clk
);


reg [4:0] state;
reg [4:0] bit_count;

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
				dout <= 3'b0;
               state <= DATA;
			end
		end
		DATA:
		begin
			rx_done <= 0;
			dout[bit_count] <= rx;
			bit_count <= bit_count + 4'd1;
            if(bit_count == 4'd7)
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

