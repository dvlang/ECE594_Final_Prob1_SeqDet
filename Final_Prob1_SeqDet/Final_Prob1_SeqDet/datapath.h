#include "dRegisterRaE.h"
#include "andGate.h"
#include "nBitAdder.h"
#include "octalMux2to1.h"
#include "fourbitPad.h"
#include "orGate.h"

SC_MODULE(datapath)
{
	//***************INPUTS*****************

	
		//+++++++new inputsignals
	sc_in<sc_logic> rst, clk;
	sc_in<sc_logic>clr_out, load_out, sel_input, load_tmp, load_in, clr;
		//+++++++new input signals

	//***************IN / OUTS**************

	sc_inout<sc_lv<4>> dataA;

	//***************OUTPUTS****************


		//+++++++new output signals
	sc_out<sc_lv<8>> Wbus_q;
		//+++++++new output signals
	
	//***********SIGNALS********************

	sc_signal<sc_logic> co,ci;


		//++++new signals for my multiplier
	sc_signal<sc_logic>orOut;
	sc_signal<sc_lv<8> >paddeddataA, regA_q, muxedinputtotmp, tmpOut_q, tmpOut, adderout;
		//end new signals for my multiplier

	
	nBitAdder* adder;
	octalMux2to1* mux;
	fourbitPad* padA;
	orGate* orG;
	dRegisterRaE* regA;
	dRegisterRaE* regOut;
	dRegisterRaE* regTmp;


	void datapath_func();
	void datapath_disp();
	
	SC_CTOR(datapath)
	{
		//Padding gate
		padA = new fourbitPad("PadA_Instance");
			padA->ain(dataA);
			padA->yout(paddeddataA);
		
		regA = new dRegisterRaE("regA_Instance");
			regA->rst(clr);
			regA->clk(clk);
			regA->cen(load_in);
			regA->regin(paddeddataA);
			regA->regout(regA_q);

		regTmp = new dRegisterRaE("regTmp_Instance");
			regTmp->rst(clr);
			regTmp->clk(clk);
			regTmp->cen(orOut);
			regTmp->regin(muxedinputtotmp);
			regTmp->regout(tmpOut_q);
		
		regOut = new dRegisterRaE("regOut_Instance");
			regOut->rst(clr_out);
			regOut->clk(clk);
			regOut->cen(load_out);
			regOut->regin(tmpOut_q);
			regOut->regout(Wbus_q);

		adder = new nBitAdder("adder_Instance");
			adder->ain(regA_q);
			adder->bin(tmpOut_q);
			adder->ci(ci);
			adder->addout(adderout);
			adder->co(co);
		
		mux = new octalMux2to1("mux_Instance");
			mux->sel(sel_input);
			mux->ain(paddeddataA);
			mux->bin(adderout);
			mux->yout(muxedinputtotmp);

		orG = new orGate("orG_Instance");
			orG->a(load_in);
			orG->b(load_tmp);
			orG->y(orOut);


		SC_METHOD(datapath_func); 
		sensitive << clr;

		SC_METHOD(datapath_disp); 
		sensitive << clk.pos();
	}
};
