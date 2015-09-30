/**
	\def N
		\brief Macro que define la posicion de la bandera \a \b N en el puntero \b dir_flags
	\def Z
		\brief Macro que define la posicion de la bandera \a \b Z en el puntero \b dir_flags
	\def C
		\brief Macro que define la posicion de la bandera \a \b C en el puntero \b dir_flags
	\def V
		\brief Macro que define la posicion de la bandera \a \b V en el puntero \b dir_flags
	\def LR
		\brief Macro que define la posicion del registro \a \b LR en el puntero \b dir_reg
	\def PC
		\brief Macro que define la posicion del registro \a \b PC en el puntero \b dir_reg
*/

#include "salto.h"
#define N 0
#define Z 1
#define C 2
#define V 3
#define LR 14
#define PC 15

void B(uint32_t label, uint32_t *dir_reg)
{
	dir_reg[PC]+=label;
}

void BL(uint32_t label, uint32_t *dir_reg)
{
	dir_reg[LR]=dir_reg[PC]+2;
	dir_reg[PC]+=label;
}

void BX(uint32_t *dir_reg)
{
	dir_reg[PC]=dir_reg[LR];
}
void BEQ(uint32_t label, uint32_t *dir_reg, char *dir_flags)
{
	if(dir_flags[Z]==1)
		dir_reg[PC]+=label;
	else
		dir_reg[PC]++;
}

void BNE(uint32_t label, uint32_t *dir_reg, char *dir_flags)
{
	if(dir_flags[Z]==0)
		dir_reg[PC]+=label;
	else
		dir_reg[PC]++;
}
void BCS(uint32_t label, uint32_t *dir_reg, char *dir_flags)
{
	if(dir_flags[C]==1)
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

void BMI(uint32_t label, uint32_t *dir_reg, char *dir_flags)
{
	if(dir_flags[N]==1)
		dir_reg[PC]+=label;
	else
		dir_reg[PC]++;
}

void BPL(uint32_t label, uint32_t *dir_reg, char *dir_flags)
{
	if(dir_flags[N]==0)
		dir_reg[PC]+=label;
	else
		dir_reg[PC]++;
}

void BVS(uint32_t label, uint32_t *dir_reg, char *dir_flags)
{
	if(dir_flags[V]==1)
		dir_reg[PC]+=label;
	else
		dir_reg[PC]++;
}

void BVC(uint32_t label, uint32_t *dir_reg, char *dir_flags)
{
	if(dir_flags[V]==0)
		dir_reg[PC]+=label;
	else
		dir_reg[PC]++;
}
void BHI(uint32_t label, uint32_t *dir_reg, char *dir_flags)
{
	if((dir_flags[C]==1)&&(dir_flags[Z]==0))
		dir_reg[PC]+=label;
	else
		dir_reg[PC]++;
}

void BLS(uint32_t label, uint32_t *dir_reg, char *dir_flags)
{
	if((dir_flags[C]==0)||(dir_flags[Z]==1))
		dir_reg[PC]+=label;
	else
		dir_reg[PC]++;
}

void BGE(uint32_t label, uint32_t *dir_reg, char *dir_flags)
{
	if(dir_flags[N]==dir_flags[V])
		dir_reg[PC]+=label;
	else
		dir_reg[PC]++;
}

void BLT(uint32_t label, uint32_t *dir_reg, char *dir_flags)
{
	if(dir_flags[N]!=dir_flags[V])
		dir_reg[PC]+=label;
	else
		dir_reg[PC]++;
}


void BGT(uint32_t label, uint32_t *dir_reg, char *dir_flags)
{
	if((dir_flags[Z]==0)&&(dir_flags[N]==dir_flags[V]))
		dir_reg[PC]+=label;
	else
		dir_reg[PC]++;
}

void BLE(uint32_t label, uint32_t *dir_reg, char *dir_flags)
{
	if((dir_flags[Z]==1)||(dir_flags[N]!=dir_flags[V]))
		dir_reg[PC]+=label;
	else
		dir_reg[PC]++;
}

void BAL(uint32_t label, uint32_t *dir_reg)
{
	dir_reg[PC]+=label;
}