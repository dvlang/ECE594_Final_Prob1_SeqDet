#include "multiplier.h"

SC_MODULE(multiplier_TB)
{

	sc_signal<sc_logic> clk, ready, go, rst;
	int done = 0;

	sc_signal_rv<4> databusA;
	sc_signal_rv<4> databusB;
	sc_signal_rv<8>Wbus;
	sc_signal<sc_lv<8> > temp_data;
	sc_lv<8>  multiplier_result;
	
	multiplier* mult;

	void starting();
	void resetting();
	void inputting();
	void outputting();
	void clocking();
	void bussing();
	void displaying();
	void stopping();

	SC_CTOR(multiplier_TB)
	{
		mult = new multiplier("mult_Instance");
			mult->clk(clk);
			mult->rst(rst);
			mult->go(go);
			mult->databusA(databusA);
			mult->databusB(databusB);
			mult->ready(ready);
			mult->Wbus(Wbus);

		SC_THREAD(starting);				
		SC_THREAD(resetting);				
		SC_THREAD(clocking);
		SC_THREAD(inputting);
		SC_METHOD(outputting);
		sensitive << ready;
		SC_METHOD(stopping);	
		sensitive << ready;
		SC_THREAD(bussing); 
		SC_METHOD(displaying); 
		sensitive << ready.posedge_event();
	}
};
