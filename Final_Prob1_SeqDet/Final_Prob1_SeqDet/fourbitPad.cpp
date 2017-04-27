#include "fourbitPad.h"

void fourbitPad::padding() {

	sc_lv<8> eightbitsout;
	
	//eightbitsout = ("0000", (sc_lv<4>)ain);  //explicitly set upper bits to zeros
	eightbitsout = (sc_lv<4>)ain;		//implicitly set upper bits to zeros (smaller vector assigned to larger will auto fill to zeros)
	yout = eightbitsout;
}
