// and gate

#include <systemc.h>

SC_MODULE(comparitor)
{
	sc_in<sc_lv<4> > ain, bin;
	sc_out<sc_logic > y;

	SC_CTOR(comparitor)
	{
		SC_METHOD(comparitorFunc);
		sensitive << ain << bin ;
	}
	void comparitorFunc();
};

