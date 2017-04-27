#include <systemc.h>
#include "uCounterRaEL.h"

SC_MODULE (controller) {
	sc_in<sc_logic> clk, go, rst;
	sc_in<sc_lv<4>> databusB;
	sc_out<sc_logic> clr_out, load_out, sel_input, load_tmp, load_in, clr,ready;
	    
	enum states {waitforgo, load, checkval, calc, store, loadout, readyst};
    sc_signal <states> p_state, n_state;	
	sc_signal <sc_logic> enable_Count, pld;
	sc_signal <sc_lv<4> > cnt_Out, parin;	

   
	uCounterRaEL* counter;

    SC_CTOR (controller) {
		counter = new uCounterRaEL("counter_Instance");
			counter->cen(enable_Count);
			counter->clk(clk);
			counter->cntout(cnt_Out);
			counter->parin(parin);
			counter->pld(pld);
			counter->rst(rst);			

        SC_METHOD (comb_func);
        sensitive << p_state << go << cnt_Out;

        SC_THREAD (seq_func);
        sensitive << clk.pos();
    }
    void comb_func ();
	void seq_func ();
};


