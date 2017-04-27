#include "datapath.h"

void datapath::datapath_func() {

	ci = SC_LOGIC_0;
}

void datapath::datapath_disp(){

	cout << "At: " << sc_time_stamp() << "	dp:	dataA	" << dataA << '\n';
	cout << "At: " << sc_time_stamp() << "	dp:	clr_out	" << clr_out << '\n';
	cout << "At: " << sc_time_stamp() << "	dp:	load_out	" << load_out << '\n';
	cout << "At: " << sc_time_stamp() << "	dp:	sel_input	" << sel_input << '\n';
	cout << "At: " << sc_time_stamp() << "	dp:	load_tmp	" << load_tmp << '\n';
	cout << "At: " << sc_time_stamp() << "	dp:	load_in	" << load_in << '\n';
	cout << "At: " << sc_time_stamp() << "	dp:	clr	" << clr << '\n';
	cout << "At: " << sc_time_stamp() << "	dp:	Wbus_q	" << Wbus_q << '\n';
	cout << "At: " << sc_time_stamp() << "	dp:	orOut	" << orOut << '\n';
	cout << "At: " << sc_time_stamp() << "	dp:	paddeddataA	" << paddeddataA << '\n';
	cout << "At: " << sc_time_stamp() << "	dp:	muxedinputtotmp	" << muxedinputtotmp << '\n';
	cout << "At: " << sc_time_stamp() << "	dp:	tmpOut_q	" << tmpOut_q << '\n';
	cout << "At: " << sc_time_stamp() << "	dp:	adderout	" << adderout << '\n';



	

}
