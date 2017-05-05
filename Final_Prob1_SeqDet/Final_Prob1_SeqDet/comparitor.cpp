#include "comparitor.h"

void comparitor::comparitorFunc() {

	if ((sc_uint<4>)ain == (sc_uint<4>)bin) {
		eq = SC_LOGIC_1;
	}
	else{
		eq = SC_LOGIC_0;
	}
}
