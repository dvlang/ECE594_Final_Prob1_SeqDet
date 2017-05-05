#include "datapath.h"
#include "controller.h"

SC_MODULE(seqdet)
{
	sc_in<sc_logic> clk, rst;
	sc_inout<sc_lv<4> > databusA;
	sc_inout<sc_lv<4> > databusB;

	sc_out<sc_lv<4>> Wbus;
	sc_signal <sc_logic> ffen;

	datapath* datapathInst;
	controller* controllerInst;	

	SC_CTOR(seqdet)
	{
				
		datapathInst = new datapath("datapathInst");
			datapathInst->clk(clk);
			datapathInst->rst(rst);		
			datapathInst->ffen(ffen);
			datapathInst->dataA(databusA);
			datapathInst->dataB(databusB);
			datapathInst->Wbus_q(Wbus);

		controllerInst = new controller("controllerInst");
			controllerInst->clk(clk);
			controllerInst->rst(rst);
			controllerInst->ffen(ffen);
			

	}
};
