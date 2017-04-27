#include "controller.h"

void controller::comb_func ()
{


   n_state = waitforgo; 
   clr_out = SC_LOGIC_0;
   load_out = SC_LOGIC_0;
   sel_input = SC_LOGIC_1;
   load_tmp = SC_LOGIC_0;
   load_in = SC_LOGIC_0;
   clr = SC_LOGIC_0;
   ready = SC_LOGIC_0;
   enable_Count = SC_LOGIC_0;
   pld = SC_LOGIC_0;
   parin = "0000";


   switch (p_state) {
		 case (waitforgo)	: 

			 if(go == '0'){				 
				 n_state = waitforgo;
				 clr = SC_LOGIC_1;
			 }else if (go == '1') {
				 clr = SC_LOGIC_1;
				 clr_out = SC_LOGIC_1;
				 n_state = load;
			 }
			 break;

		 case (load)	:
			 sel_input = SC_LOGIC_0;
			 load_in = SC_LOGIC_1;
			 n_state = checkval;
			 break;

		 case (checkval)		:

			 //convert B to int and check to see if it is 1 or 0, if not then go mult
			 if ((sc_uint<8>)databusB == 1) n_state = store;
				//do something, done
			 if ((sc_uint<8>)databusB == 0) n_state = readyst;
				// do something, output is zero

			 else n_state = calc; //go to calc state
			 break;
			 
		 case (calc):
			 enable_Count = SC_LOGIC_1;
			 n_state = store;
			 break;


		 case (store)	:

			 if ((sc_uint<8>)cnt_Out.read() == (sc_uint<8>)databusB) {
	
				 n_state = loadout;
			 }
			 else {
				 load_tmp = SC_LOGIC_1;
				 n_state = calc;
			 }
			 break;

	
		 case (loadout)	:
			 load_out = SC_LOGIC_1;
			
			 n_state = readyst;
			 break;

		 case (readyst):
			 ready = SC_LOGIC_1;
			
			 n_state = waitforgo;
			 break;
		 default		:

			 clr_out = SC_LOGIC_0;
			 load_out = SC_LOGIC_0;
			 sel_input = SC_LOGIC_1;
			 load_tmp = SC_LOGIC_0;
			 load_in = SC_LOGIC_0;
			 clr = SC_LOGIC_0;
			 ready = SC_LOGIC_0;
			 enable_Count = SC_LOGIC_0;
			 pld = SC_LOGIC_0;
			 break;		
   }   

}


void controller::seq_func ()
{
   while (1) {
      if (rst == '1') 
		  p_state = waitforgo;
      else		  
		  p_state = n_state;
			cout << "At: " << sc_time_stamp() << "	cp:	p_state became	" << p_state << '\n';
			cout << "At: " << sc_time_stamp() << "  cp:	Ready: " << ready << '\n';
			cout << "At: " << sc_time_stamp() << "  cp:	GO: " << go << '\n';
      wait ();
   }
}
