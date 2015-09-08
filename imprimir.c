#include "imprimir.h"
void valor_registro( uint32_t  valores[])
{
    int i;
    for(i=0;i<13;i++)
    {
        mvprintw(6+i,1,"R%d: %d",i,valores[i]);
    }
}
