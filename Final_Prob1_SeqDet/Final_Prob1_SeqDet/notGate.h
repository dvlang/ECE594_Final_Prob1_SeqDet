// not gate

#include <systemc.h>

SC_MODULE(notGate)
{
	sc_in<sc_logic> a;
	sc_out<sc_logic> y;

	SC_CTOR(notGate)
	{
		SC_METHOD(notFunc);
		sensitive << a ;
	}
	void notFunc();
};

