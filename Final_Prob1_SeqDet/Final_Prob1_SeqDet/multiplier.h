#include "datapath.h"
#include "controller.h"

SC_MODULE(multiplier)
{
	sc_in<sc_logic> clk, rst, go;
	sc_inout<sc_lv<4> > databusA;
	sc_inout<sc_lv<4> > databusB;
	sc_out<sc_logic> ready;
	sc_out<sc_lv<8>> Wbus;
	sc_signal <sc_logic> clr_out, load_out, sel_input, load_tmp, load_in, clr;

	datapath* datapathInst;
	controller* controllerInst;	

	SC_CTOR(multiplier)
	{
				
		datapathInst = new datapath("datapathInst");
			datapathInst->clk(clk);
			datapathInst->rst(rst);
			datapathInst->clr_out(clr_out);
			datapathInst->load_out(load_out);
			datapathInst->sel_input(sel_input);
			datapathInst->load_tmp(load_tmp);
			datapathInst->load_in(load_in);
			datapathInst->clr(clr);
			datapathInst->dataA(databusA);
			datapathInst->Wbus_q(Wbus);

		controllerInst = new controller("controllerInst");
			controllerInst->clk(clk);
			controllerInst->rst(rst);
			controllerInst->go(go);
			controllerInst->databusB(databusB);
			controllerInst->ready(ready);
			controllerInst->clr_out(clr_out);
			controllerInst->load_out(load_out);
			controllerInst->load_tmp(load_tmp);
			controllerInst->load_in(load_in);
			controllerInst->clr(clr);
			controllerInst->sel_input(sel_input);

	}
};
