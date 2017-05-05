#include "seqdet.h"

SC_MODULE(SeqDet_TB)
{

	sc_signal<sc_logic> clk, rst;
	int done = 0;
	bool hold = false;

	sc_signal_rv<4> databusA;
	sc_signal_rv<4> databusB;
	sc_signal_rv<4>Wbus;

	sc_lv<4>  count_result;
	
	seqdet* seqDet;

	void starting();
	void resetting();
	void inputting();
	void outputting();
	void clocking();
	void bussing();
	void displaying();
	void stopping();

	SC_CTOR(SeqDet_TB)
	{
		seqDet = new seqdet("seq_Instance");
			seqDet->clk(clk);
			seqDet->rst(rst);
			seqDet->databusA(databusA);
			seqDet->databusB(databusB);
			seqDet->Wbus(Wbus);

		SC_THREAD(starting);				
		SC_THREAD(resetting);				
		SC_THREAD(clocking);
		SC_THREAD(inputting);
		sensitive << clk;
		SC_METHOD(outputting);
		sensitive << Wbus;
		SC_METHOD(stopping);	
		sensitive  << clk.posedge_event();
		SC_THREAD(bussing); 
		SC_METHOD(displaying); 
		sensitive << clk.posedge_event();
	}
};
