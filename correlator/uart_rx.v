module uart_rx(
	rx,
	dout,
	rx_done,
	clk
);

parameter SHIFT=4;
parameter WORD_WIDTH=8;
parameter STOP_BITS=1;

input wire rx;
output reg [WORD_WIDTH-1:0] dout;
output reg rx_done;
input wire clk;

reg [5+SHIFT:0] bit_count = (WORD_WIDTH+STOP_BITS)<<SHIFT;

always@(posedge clk) begin
	case(bit_count[SHIFT+:6])
		WORD_WIDTH+STOP_BITS:
		begin
			rx_done <= 0;
			if(!rx) begin
				bit_count <= 0;
				dout <= 0;
			end
		end
		WORD_WIDTH:
		begin
			rx_done <= 1;
			bit_count <= bit_count + 1;
		end
		default:
		begin
			rx_done <= 0;
			dout[bit_count[SHIFT+:6]] <= rx;
			bit_count <= bit_count + 1;
		end
	endcase
end

endmodule
