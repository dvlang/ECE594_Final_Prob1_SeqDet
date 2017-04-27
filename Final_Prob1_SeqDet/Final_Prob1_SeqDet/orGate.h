// or gate

#include <systemc.h>

SC_MODULE(orGate)
{
	sc_in<sc_logic > a, b;
	sc_out<sc_logic > y;

	SC_CTOR(orGate)
	{
		SC_METHOD(orFunc);
		sensitive << a << b ;
	}
	void orFunc();
};

