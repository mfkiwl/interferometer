module TX_WORD(
	TX,
	tx_data,
	clk,
	enable
	);

parameter RESOLUTION=32;
parameter TOTAL_NIBBLES=RESOLUTION/4;

output wire TX;
input wire [RESOLUTION-1:0] tx_data;
input wire enable;
input wire clk;

reg signed [31:0] tidx;
wire TXIF;
reg [7:0] TXREG;

uart_tx tx_block(
	TX,
	TXREG,
	6'd8,
	TXIF,
	enable,
	clk
);

always@(posedge TXIF) begin
	if(tidx>=0) begin
		if(tx_data[tidx*4+:4] < 4'ha) TXREG <= tx_data[tidx*4+:4] | 8'h30;
		else TXREG <= (tx_data[tidx*4+:4]-4'ha) | 8'h41;
		tidx <= tidx-1;
	end else begin
		TXREG <= 8'h0d;
		tidx <= TOTAL_NIBBLES-1;
	end
end
endmodule
