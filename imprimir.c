#include "imprimir.h"
void valor_registro( uint32_t  valores[])
{
	int i;	
	for(i=0;i<14;i++)
	{
		if(i<10)
			mvprintw(6+i,1,"R%d:  %d",i,valores[i]);
		else
			mvprintw(6+i,1,"R%d: %d",i,valores[i]);
	}
	mvprintw(6+i,1,"LR:  %d",valores[i]);
	mvprintw(7+i,1,"PC:  %d",valores[i+1]);
	
	}
