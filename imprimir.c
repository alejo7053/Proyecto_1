#include "imprimir.h"
void valor_registro( uint32_t  valores[])
{
    int i;
    for(i=0;i<12;i++)
    {
        printf("Registro %d: %d\n",i,valores[i]);
    }
}
