#include "datapath.h"

void datapath::datapath_func() {

	//ci = SC_LOGIC_0;
}

void datapath::datapath_disp(){

	cout << "At: " << sc_time_stamp() << "	dp:	dataA	" << dataA << '\n';
	cout << "At: " << sc_time_stamp() << "	dp:	dataB	" << dataB << '\n';
	//cout << "At: " << sc_time_stamp() << "	dp:	clr	" << rst << '\n';
	cout << "At: " << sc_time_stamp() << "	dp:	Wbus_q	" << Wbus_q << '\n';
	//cout << "At: " << sc_time_stamp() << "	dp:	compout	" << compout << '\n';
	//cout << "At: " << sc_time_stamp() << "	dp:	notcompout	" << notcompout << '\n';
	//cout << "At: " << sc_time_stamp() << "	dp:	reqA_q	" << regA_q << '\n';
	//cout << "At: " << sc_time_stamp() << "	dp:	reqB_q	" << regB_q << '\n';
	//cout << "At: " << sc_time_stamp() << "	dp:	cnt_en	" << cnt_en << '\n';
	
}
