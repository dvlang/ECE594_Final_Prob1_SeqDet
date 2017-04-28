// dFF: Dflip flop Register with an asynchronous Reset and an Enable

#include <systemc.h>

SC_MODULE(dFF)
{
	sc_in<sc_logic> rst, clk, cen, din;
	//sc_in<sc_lv<8> > regin;
	//sc_out<sc_lv<8> > regout;
	sc_out<sc_logic> qout;

	SC_CTOR(dFF)
	{
		SC_METHOD(registering);
		sensitive << rst << clk;
	}
	void registering();
};
