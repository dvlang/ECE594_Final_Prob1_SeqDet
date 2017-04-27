#include "multiplier_TB.h"

void multiplier_TB::clocking() {
	int i;
	wait(0,SC_NS);
	clk=sc_logic('0');
	wait(50,SC_NS);
	for(i=0;i<=400;i++) {
			cout << "**********CLOCK TICK**********" << '\n';
			clk = (sc_logic)'1';
		wait(50,SC_NS);
			clk = (sc_logic)'0';
		wait(50,SC_NS);
    }
}
void multiplier_TB::outputting() {

	if (ready == '1') {

		multiplier_result = Wbus.read();

	}

}

void multiplier_TB::bussing() {

	
}

void multiplier_TB::resetting(){			
	rst = (sc_logic)'0';	
	wait(30,SC_NS);
	rst = (sc_logic)'1';
	wait(30,SC_NS);
	rst = (sc_logic)'0';	
}

void multiplier_TB::starting() {
	go = (sc_logic)'0';

	wait(110,SC_NS);
	for(int i = 0; i < 1; i++){		
			go = (sc_logic)'1';
		wait(70,SC_NS);
			go = (sc_logic)'0';
		wait(1350,SC_NS);
	}	

}

void multiplier_TB::inputting() {
	int i, val; 

	for(i=0; i < 1; i++) {
		wait(150,SC_NS);


		databusA = "1111";
		databusB = "1111";

		
	}
	wait(200,SC_NS);		
}

void multiplier_TB::displaying() {
	cout <<"At: "<<sc_time_stamp()<<" multiplier result changes to: "<<multiplier_result<<'\n';

}


void multiplier_TB::stopping() {
	cout << '\n' << "****Press 2 to continue, 1 to quit ****"<< '\n';
	cin >> done;
	if (done == 1) {
		sc_stop();

	}
}