#include "SeqDet_TB.h"

int sc_main(int argc, char ** argv)
{
	SeqDet_TB seqdetTB1 ("SeqDetTB1_Instance");

	sc_trace_file* VCDFile;
	VCDFile = sc_create_vcd_trace_file("seqdet");
			sc_trace(VCDFile, seqdetTB1.clk, "clk");
			sc_trace(VCDFile, seqdetTB1.rst, "rst");
		//	sc_trace(VCDFile, multTB1.go, "go");
			sc_trace(VCDFile, seqdetTB1.databusA, "dataA");
			sc_trace(VCDFile, seqdetTB1.databusB, "dataB");
			sc_trace(VCDFile, seqdetTB1.Wbus, "Wbus");
	//		sc_trace(VCDFile, multTB1.ready, "ready");


	sc_start(3700,SC_NS);

	return 0;
}
