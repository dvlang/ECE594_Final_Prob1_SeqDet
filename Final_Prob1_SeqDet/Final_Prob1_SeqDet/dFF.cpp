#include "dFF.h"

void dFF::registering()
{
	if (rst=='1')
		{
			qout = SC_LOGIC_0;
		}
		else if (clk->event() && (clk=='1'))
		{
			if(cen=='1') qout = din;
		}	
}