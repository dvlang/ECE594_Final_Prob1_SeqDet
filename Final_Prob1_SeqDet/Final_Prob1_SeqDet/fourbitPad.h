// 4bitPad: pad a input vector by 4bits

#include <systemc.h>

SC_MODULE(fourbitPad)
{

	sc_in<sc_lv<4> > ain;
	sc_out<sc_lv<8> > yout;

	SC_CTOR(fourbitPad)
	{
		SC_METHOD(padding);
		sensitive << ain;
	}
	void padding();
};
