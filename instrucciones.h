/**
* \brief titulo
* \n prototipo de la funcion  suma que  va a operar los registros
*/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void flags(uint32_t a, uint32_t b, uint32_t c, char *p);

void CMN(uint32_t a, uint32_t b, char *p);

void CMP(uint32_t a, uint32_t b, char *p);

uint32_t MUL(uint32_t a, uint32_t b, char *p);

void TST(uint32_t a, uint32_t b, char *p);

uint32_t add(uint32_t a, uint32_t b);

/**
*  prototipo de la funcion  resta que  va a operar los registros
*/

uint32_t sub(uint32_t a, uint32_t b);

/**
*  prototipo de la funcion  mover que  va a operar los registros
*/

uint32_t Mov( uint32_t b);

/**
*  prototipo de la funcion  And que  va a operar los registros
*/

uint32_t And(uint32_t a, uint32_t b);

/**
*  prototipo de la funcion  Eor que  va a operar los registros
*/

uint32_t Eor(uint32_t a, uint32_t b);

/**
*  prototipo de la funcion  Orr que  va a operar los registros
*/

uint32_t Orr(uint32_t a, uint32_t b);
