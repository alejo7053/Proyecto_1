#include "instrucciones.h"


void flags(uint32_t a, uint32_t b, uint32_t c, char *p) //declaracion del tipo de la funcion void y variables tipo unsigned long int y char el puntero
{
    uint32_t aux=2147483648UL;
    //Bandera N
    if(c<aux)
    {
        *p=0;
    }
    else
    {
        *p=1;
    }
    //Bandera Z
    if(c==0)
    {
        *(p+1)=1;
    }
    else
    {
        *(p+1)=0;
    }
    //Bandera C
    if(((a>=aux) & (b<aux) & (c<aux))||((b>=aux) & (a<aux) & (c<aux))||((a>=aux) & (b>=aux)))
    {
        *(p+2)=1;
    }
    else
    {
        *(p+2)=0;
    }
    //Bandera V
    if(((a>=aux) & (b>=aux) & (c<aux))||((a<aux) & (b<aux)) & (c>=aux))
    {
        *(p+3)=1;
    }
    else
    {
        *(p+3)=0;
    }
}

void CMN(uint32_t a, uint32_t b, char *p)
{
    flags(a, b, a+b, p);
}

void CMP(uint32_t a, uint32_t b, char *p)
{
    flags(a, b, a-b, p);
}

uint32_t MUL(uint32_t a, uint32_t b, char *p)
{
    flags(a, b, a*b, p);
    return a*b;
}

void TST(uint32_t a, uint32_t b, char *p)
{
    flags(a, b, a&b, p);
}

uint32_t add(uint32_t a, uint32_t b) //declaracion del tipo de la funcion y variables tipo unsigned long int 
{
    return a+b; // operacion suma  que se realiza y su retorno
}

uint32_t sub(uint32_t a, uint32_t b)
{
    return a-b;// operacion mover  que se realiza y su retorno
}


uint32_t Mov(uint32_t b)
{
    return b; // operacion mover  que se realiza y su retorno
}

uint32_t And(uint32_t a, uint32_t b)
{
    return a&b; // operacion And  que se realiza y su retorno
}

uint32_t Eor(uint32_t a, uint32_t b)
{
    return a^b; // operacion Eor  que se realiza y su retorno
}

uint32_t Orr(uint32_t a, uint32_t b)
{
    return a|b;// operacion Oor  que se realiza y su retorno
}
