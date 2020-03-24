module uart_tx(
	output reg tx,
	input wire [7:0] din,
	output reg tx_done,
	input wire tx_start,
	input wire clk
);

reg [4:0] state;
reg [3:0] bit_count;

parameter [5:0]
    IDLE   = 5'd0,
    DATA  = 5'd2,
    STOP  = 5'd3,
    DONE  = 5'd4;

always@(posedge clk) begin
	case(state)
		IDLE:
		begin
			tx_done <= 0;
			if(tx_start) begin
				bit_count <= 4'd0;
				tx <= 1'b0;
               state <= DATA;
			end else begin
				tx <= 1'b1;
				bit_count <= 4'd0;
				state <= IDLE;
			end
		end
		DATA:
		begin
			tx_done <= 0;
			tx <= din[bit_count];
			bit_count <= bit_count + 4'd1;
            if(bit_count == 4'd7)
				state <= STOP;
		end
		STOP:
		begin
			tx_done <= 0;
			tx <= 1'b1;
			bit_count <= 4'd0;
			state <= DONE;
		end
		DONE:
		begin
			tx_done <= 1;
			tx <= 1'b1;
			bit_count <= 4'd0;
			state <= IDLE;
		end
	endcase
end

endmodule
