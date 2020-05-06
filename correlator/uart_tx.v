module uart_tx(
	tx,
	din,
	tx_done,
	tx_start,
	clk
);

parameter SHIFT=4;
parameter WORD_WIDTH=8;
parameter STOP_BITS=1;

output reg tx;
input wire [WORD_WIDTH-1:0] din;
output reg tx_done;
input wire tx_start;
input wire clk;

reg [5+SHIFT:0] bit_count = (WORD_WIDTH+STOP_BITS)<<SHIFT;

always@(posedge clk) begin
	case(bit_count[SHIFT+:6])
		WORD_WIDTH+STOP_BITS:
		begin
			tx_done <= 0;
			if(tx_start) begin
				bit_count <= 0;
				tx <= 0;
			end else begin
				tx <= 1;
			end
		end
		WORD_WIDTH:
		begin
			tx_done <= 1;
			tx <= 1;
			bit_count <= bit_count+1;
		end
		default:
		begin
			tx_done <= 0;
			tx <= din[bit_count[SHIFT+:6]];
			bit_count <= bit_count+1;
		end
	endcase
end

endmodule
