#include "imprimir.h"
void valor_registro( uint32_t  valores[])
{
	int i,j=0;	
	for(i=0;i<14;i++)	//Imprime en pantalla los registros 0-13
	{
		if(i<10)
			mvprintw(6+i,1,"R%d:  %.10u",i,valores[i]);
		else{
			mvprintw(6+j,20,"R%d: %.10u",i,valores[i]);
			j++;
		}
	}
	mvprintw(8+j,20,"LR:  %.10u",valores[i]*2);
	mvprintw(9+j,20,"PC:  %.10u",valores[i+1]*2); //Se impremen en pantalla LR y PC
}
