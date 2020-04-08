// pll.v

// Generated using ACDS version 13.0 156 at 2020.03.31.04:13:02

`timescale 1 ps / 1 ps
module pll (
		input  wire  clki_clk,    //  clki.clk
		output wire  clko_clk    //  clko.clk
	);

	pll_altpll_0 altpll_0 (
		.clk       (clki_clk),    //       inclk_interface.clk
		.reset     (1'b1), // inclk_interface_reset.reset
		.read      (),            //             pll_slave.read
		.write     (),            //                      .write
		.address   (),            //                      .address
		.readdata  (),            //                      .readdata
		.writedata (),            //                      .writedata
		.c0        (clko_clk),    //                    c0.clk
		.areset    (),            //        areset_conduit.export
		.locked    (),            //        locked_conduit.export
		.phasedone ()             //     phasedone_conduit.export
	);

endmodule
