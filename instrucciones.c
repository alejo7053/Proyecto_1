#include "instrucciones.h"

long int Suma(long int a, long int b)
{
    return a+b;
}

long int Resta(long int a, long int b)
{
    return a-b;
}

long int Mover(long int b)
{
    return b;
}

long int And(long int a, long int b)
{
    return a&b;
}

long int Eor(long int a, long int b)
{
    return a^b;
}

long int Orr(long int a, long int b)
{
    return a|b;
}
