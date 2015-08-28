#include "instrucciones.h"

uint32_t add(uint32_t a, uint32_t b)
{
    return a+b;
}

uint32_t sub(uint32_t a, uint32_t b)
{
    return a-b;
}

uint32_t Mov(uint32_t b)
{
    return b;
}

uint32_t And(uint32_t a, uint32_t b)
{
    return a&b;
}

uint32_t Eor(uint32_t a, uint32_t b)
{
    return a^b;
}

uint32_t Orr(uint32_t a, uint32_t b)
{
    return a|b;
}
