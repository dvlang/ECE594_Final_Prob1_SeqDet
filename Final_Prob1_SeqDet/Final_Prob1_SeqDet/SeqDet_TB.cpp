#include "SeqDet_TB.h"
#include <stdlib.h>
#include <time.h>

void SeqDet_TB::clocking() {
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
void SeqDet_TB::outputting() {

	//if (ready == '1') {

		count_result = Wbus.read();

//	}

}

void SeqDet_TB::bussing() {

	
}

void SeqDet_TB::resetting(){
	rst = (sc_logic)'0';	
	wait(30,SC_NS);
	rst = (sc_logic)'1';
	wait(30,SC_NS);
	rst = (sc_logic)'0';	
}

void SeqDet_TB::starting() {
	wait(10, SC_NS);
	
	/*go = (sc_logic)'0';

	wait(110,SC_NS);
	for(int i = 0; i < 1; i++){		
			go = (sc_logic)'1';
		wait(70,SC_NS);
			go = (sc_logic)'0';
		wait(1350,SC_NS);
	}	*/

}

void SeqDet_TB::inputting() {
	int i,rnd; 

	for(i=0; i < 10; i++) {
		wait(150,SC_NS);
		
		//databusA = "1111";
		//databusB = "1001";
		if (hold) {
			databusA = databusB;
			databusB = databusB;
		}
		else {
			srand(4453 * (unsigned)time(NULL));
			rnd = rand() % 16;
			databusA = (sc_lv<4>)rnd;
			srand(695 * (unsigned)time(NULL));
			rnd = rand() % 16;
			databusB = (sc_lv<4>)rnd;
		}
	}
	wait(200,SC_NS);		
}

void SeqDet_TB::displaying() {
	//cout <<"At: "<<sc_time_stamp()<<" SeqDet_TB result changes to: "<< count_result <<'\n';

}


void SeqDet_TB::stopping() {
	cout << '\n' << "****Press 2 to continue (new value), 3 to continue with same, 1 to quit ****"<< '\n';
	cin >> done;
	if (done == 1) {
		sc_stop();

	}
	else if(done == 3)
	{
		hold = true;
	}
}