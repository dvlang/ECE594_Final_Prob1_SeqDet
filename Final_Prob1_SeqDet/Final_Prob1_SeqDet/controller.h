#include <systemc.h>
//#include "uCounterRaEL.h"

SC_MODULE (controller) {
	sc_in<sc_logic> clk, rst;
	sc_out<sc_logic> ffen;
	    
	enum states {waitforgo, load};
    sc_signal <states> p_state, n_state;	


    SC_CTOR (controller) {

        SC_METHOD (comb_func);
        sensitive << p_state << rst;

        SC_THREAD (seq_func);
        sensitive << clk.pos();
    }
    void comb_func ();
	void seq_func ();
};


