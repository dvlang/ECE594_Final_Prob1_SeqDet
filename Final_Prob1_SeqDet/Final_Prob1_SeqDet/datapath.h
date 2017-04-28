
#include "andGate.h"
#include "notGate.h"
#include "comparitor.h"
#include "dFF.h"
#include "uCounterRaEL.h"

SC_MODULE(datapath)
{
	//***************INPUTS*****************
	sc_in<sc_logic> rst, clk, ffen;

	//***************IN / OUTS**************
	sc_inout<sc_lv<4>> dataA;
	sc_inout<sc_lv<4>> dataB;

	//***************OUTPUTS****************
	sc_out<sc_lv<4>> Wbus_q;
		
	//***********SIGNALS********************
	sc_signal<sc_logic> compout, notcompout, regA_q, regB_q, cnt_en, pld;
	sc_signal <sc_lv<4> > parin;

	//***Instanciations***
	dFF* regA;
	dFF* regB;
	andGate* andA;
	notGate* notComp;
	comparitor* comp;
	uCounterRaEL* counter;
	
	void datapath_func();
	void datapath_disp();
	
	SC_CTOR(datapath)
	{
		comp = new comparitor("comp_Instance");
			comp->ain(dataA);
			comp->bin(dataB);
			comp->eq(compout);

		notComp = new notGate("notG_Instance");
			notComp->a(compout);
			notComp->y(notcompout);

		regA = new dFF("dffA_Instance");
			regA->rst(rst);
			regA->clk(clk);
			regA->cen(ffen);
			regA->din(notcompout);
			regA->qout(regA_q);

		regB = new dFF("dffB_Instance");
			regB->rst(rst);
			regB->clk(clk);
			regB->cen(ffen);
			regB->din(regA_q);
			regB->qout(regB_q);

		andA = new andGate("andG_Instance");
			andA->a(regA_q);
			andA->b(regB_q);
			andA->c(notcompout);
			andA->y(cnt_en);

		counter = new uCounterRaEL("counter_Instance");
			counter->cen(cnt_en);
			counter->clk(clk);
			counter->cntout(Wbus_q);
			counter->parin(parin);
			counter->pld(pld);
			counter->rst(rst);

		SC_METHOD(datapath_func); 
		sensitive << rst;

		SC_METHOD(datapath_disp); 
		sensitive << clk.pos();
	}
};
