#include "imprimir.h"
#include <stdio.h>
void valor_registro( unsigned long int valores[])
{


    int i;
    for(i=0;i<12;i++)
    {
        printf("Registro %d: %ld\n",i,valores[i]);
    }
}
