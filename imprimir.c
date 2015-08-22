#include "imprimir.h"

void valor_registro( long int valores[])
{


    int i;
    for(i=0;i<12;i++)
    {
        printf("Registro %d: %d\n",i,valores[i]);
    }
}
