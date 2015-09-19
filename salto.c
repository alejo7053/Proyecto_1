#include "salto.h"
#define N 0
#define Z 1
#define C 2
#define V 3
#define LR 14
#define PC 15

void B(uint32_t label, uint32_t *dir_reg)
{
	dir_reg[PC]=label;
}

void BL(uint32_t label, uint32_t *dir_reg)
{
	dir_reg[LR]=label+1;
	dir_reg[PC]+=2;
}

void BX(uint32_t *dir_reg)
{
	dir_reg[PC]=dir_reg[LR];
}

void BNE(uint32_t label, uint32_t *dir_reg, char *dir_flags)
{
	if(dir_flags[Z]==0)
		dir_reg[PC]+=label;
	else
		dir_reg[PC]++;
}

void BCC(uint32_t label, uint32_t *dir_reg, char *dir_flags)
{
	if(dir_flags[C]==0)
		dir_reg[PC]+=label;
	else
		dir_reg[PC]++;
}