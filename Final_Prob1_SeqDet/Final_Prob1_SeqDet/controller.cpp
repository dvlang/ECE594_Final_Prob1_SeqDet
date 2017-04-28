#include "controller.h"

void controller::comb_func ()
{


   n_state = waitforgo; 
   ffen = SC_LOGIC_0;
      
   //pld = SC_LOGIC_0;
   //parin = "0000";


   switch (p_state) {
		 case (waitforgo)	: 

			 if(rst == '1'){				 
				 n_state = waitforgo;
				// clr = SC_LOGIC_1;
			 }else if (rst == '0') {
				// clr = SC_LOGIC_1;
				 ffen = SC_LOGIC_1;
				 n_state = load;
			 }
			 break;

		 case (load)	:
			 //sel_input = SC_LOGIC_0;
			 if (rst == '0') {
				 ffen = SC_LOGIC_1;
				 n_state = load;
			 }
			 else if (rst == '1') {
				 ffen = SC_LOGIC_0;
				 n_state = waitforgo;
			 }
			 break;

		 default		:
			 ffen = SC_LOGIC_0;
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
			//cout << "At: " << sc_time_stamp() << "	cp:	p_state became	" << p_state << '\n';

      wait ();
   }
}
