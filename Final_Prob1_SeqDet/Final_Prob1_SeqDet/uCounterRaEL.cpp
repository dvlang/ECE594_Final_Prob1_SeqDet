#include "uCounterRaEL.h"

void uCounterRaEL::counting()
{
	if (rst=='1')
		{
			cntout = sc_lv<4>(0);
		}
		else if (clk->event() && (clk=='1'))
		{
			if(pld=='1') cntout = parin;
			else if(cen=='1') 
				cntout=(sc_uint<4>)cntout+1;
		}
}