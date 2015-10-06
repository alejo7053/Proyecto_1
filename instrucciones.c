/**
	\def N
		\brief Macro que define la posicion de la bandera \a \b N en el puntero \b dir_flags
	\def Z
		\brief Macro que define la posicion de la bandera \a \b Z en el puntero \b dir_flags
	\def C
		\brief Macro que define la posicion de la bandera \a \b C en el puntero \b dir_flags
	\def V
		\brief Macro que define la posicion de la bandera \a \b V en el puntero \b dir_flags
	\def SP
		\brief Macro que define la posicion del registro \a \b SP en el puntero \b dir_reg
	\def LR
		\brief Macro que define la posicion del registro \a \b LR en el puntero \b dir_reg
	\def PC
		\brief Macro que define la posicion del registro \a \b PC en el puntero \b dir_reg
*/

#include "instrucciones.h"
/* Macros para asignacion de las banderas */
#define N 0
#define Z 1
#define C 2
#define V 3
#define PC 15
#define LR 14
#define SP 13

void flags(uint32_t Rn, uint32_t Rm, uint32_t Rd, char *dir_flags) 	//Funcion que modifica las banderas
{
	uint32_t aux=2147483648UL;
	//Modifica Bandera N
	if(Rd<aux)
		dir_flags[N]=0;
	else
		dir_flags[N]=1;
	//Modifica Bandera Z
	if(Rd==0)
		dir_flags[Z]=1;
	else
		dir_flags[Z]=0;
	//Modifica Bandera C
	if(((Rn>=aux) && (Rm<aux) && (Rd<aux))||((Rm>=aux) && (Rn<aux) && (Rd<aux))||((Rn>=aux) && (Rm>=aux)))
		dir_flags[C]=1;
	else
		dir_flags[C]=0;
	//Modifica Bandera V
	if(((Rn>=aux) && (Rm>=aux) && (Rd<aux))||((Rn<aux) && (Rm<aux) && (Rd>=aux)))
		dir_flags[V]=1;
	else
		dir_flags[V]=0;
}

void flag_N(uint32_t Rd, char *dir_flag_N)	//Funcion que modifica la bandera N
{
	uint32_t aux=2147483648UL;
	if(Rd<aux)
		*dir_flag_N=0;
	else
		*dir_flag_N=1;
}

void flag_Z(uint32_t Rd, char *dir_flag_Z)	//Funcion que modifica la bandera Z
{
	if(Rd==0)
		*dir_flag_Z=1;
	else
		*dir_flag_Z=0;
}

void flag_C(uint32_t Rn, uint32_t Rm, uint32_t Rd, char *dir_flag_C)	//Funcion que modifica la bandera C
{
	uint32_t aux=2147483648UL;
	if(((Rn>=aux) && (Rm<aux) && (Rd<aux))||((Rm>=aux) && (Rn<aux) && (Rd<aux))||((Rn>=aux) && (Rm>=aux)))
		*dir_flag_C=1;
	else
		*dir_flag_C=0;
}

void flag_V(uint32_t Rn, uint32_t Rm, uint32_t Rd, char *dir_flag_V)	//Funcion que modifica la bandera V
{
	uint32_t aux=2147483648UL;
	if(((Rn>=aux) && (Rm>=aux) && (Rd<aux))||((Rn<aux) && (Rm<aux) && (Rd>=aux)))
		*dir_flag_V=1;
	else
		*dir_flag_V=0;
}

void CMN(uint32_t Rn, uint32_t Rm, char *dir_flags)
{
	flags(Rn, Rm, Rn+Rm, dir_flags);
}

void CMP(uint32_t Rn, uint32_t Rm, char *dir_flags)
{
	flags(Rn, (~Rm + 1), Rn+(~Rm + 1), dir_flags);
}

uint32_t MUL(uint32_t Rn, uint32_t Rm, char *dir_flags)
{
	flag_N(Rn*Rm, &dir_flags[N]);
	flag_Z(Rn*Rm, &dir_flags[Z]);
	return Rn*Rm;
}

void TST(uint32_t Rn, uint32_t Rm, char *dir_flags)
{
	flag_N(Rn&Rm, &dir_flags[N]);
	flag_Z(Rn&Rm, &dir_flags[Z]);
	flag_C(Rn, Rm, Rn&Rm, &dir_flags[C]);
}

uint32_t ADD(uint32_t Rn, uint32_t Rm, char *dir_flags) 
{
	flags(Rn, Rm, Rn+Rm, dir_flags);
	return Rn+Rm; 
}

uint32_t ADC(uint32_t Rn,uint32_t Rm, char *dir_flags) 
{
	uint32_t aux=Rn+Rm+dir_flags[C];
	flags(Rn,Rm,aux, dir_flags);
	return aux;
}

uint32_t SUB(uint32_t Rn, uint32_t Rm,char *dir_flags)
{
	flags(Rn, (~Rm + 1), Rn+(~Rm + 1), dir_flags);
	return Rn+(~Rm + 1);
}

uint32_t SBC(uint32_t Rn,uint32_t Rm, char *dir_flags)
{
	flags(Rn,(~Rm),Rn+(~Rm)+dir_flags[C], dir_flags);
	return Rn+(~Rm)+dir_flags[C];
	
}
uint32_t MOV(uint32_t Rn, char *dir_flags)
{
	flag_N(Rn, &dir_flags[N]);
	flag_Z(Rn, &dir_flags[Z]);
	return Rn;
}

uint32_t AND(uint32_t Rn, uint32_t Rm, char *dir_flags)
{
	flag_N(Rn&Rm, &dir_flags[N]);
	flag_Z(Rn&Rm, &dir_flags[Z]);
	flag_C(Rn, Rm, Rn&Rm, &dir_flags[C]);
	return Rn&Rm;
}

uint32_t EOR(uint32_t Rn, uint32_t Rm, char *dir_flags)
{
	flag_N(Rn^Rm, &dir_flags[N]);
	flag_Z(Rn^Rm, &dir_flags[Z]);
	flag_C(Rn, Rm, Rn^Rm, &dir_flags[C]);
	return Rn^Rm;
}

uint32_t ORR(uint32_t Rn, uint32_t Rm, char *dir_flags)
{
	flag_N(Rn|Rm, &dir_flags[N]);
	flag_Z(Rn|Rm, &dir_flags[Z]);
	flag_C(Rn, Rm, Rn|Rm, &dir_flags[C]);
	return Rn|Rm;
}

void NOP(uint32_t *dir_reg)	//No hace nada durante un ciclo de reloj
{
	dir_reg[PC]++;
}

//uint32_t R[16], *dir_reg=R; //declaracion registro y puntero al registro

void PUSH(uint8_t *SRAM, uint32_t *dir_reg, uint8_t *R_activos )
{  
	int i=0;  
	uint8_t address=0;
	address=dir_reg[SP]-4*bitcount(R_activos); //address queda en la posiccion 38
	for(i=0;R_activos[i]<=14;i++)
	{
		if(R_activos[i]==1)
		{
			SRAM[address]=(uint8_t)dir_reg[i]; 
			SRAM[address+1]=((uint8_t)dir_reg[i]>>8);
			SRAM[address+2]=((uint8_t)dir_reg[i]>>16);
			SRAM[address+3]=((uint8_t)dir_reg[i]>>24);
			address+=4;         
		}
	}
	dir_reg[SP]=dir_reg[SP]-4*bitcount(R_activos);  //
}

uint32_t bitcount(uint8_t *R)
{
	int activos=0,i=0;
	for(i=0;i<=15;i++)
	{
		if(i<=7||i==14)
		{
			if(R[i]==1)
			{
				activos++;
			}
		}
	}
	return activos;
}

void POP(uint8_t *SRAM, uint32_t *dir_reg, uint8_t *R_activos )
{
	uint8_t address;
	int i;
	address=dir_reg[SP];
	for(i=0;R_activos[i]<=14;i++)
	{
		if(R_activos[i]==1)
		{
			dir_reg[i]=SRAM[address+3];
			dir_reg[i]<<=8;
			dir_reg[i]=SRAM[address+2];
			dir_reg[i]<<=16;
			dir_reg[i]=SRAM[address+1];
			dir_reg[i]<<=24;
			dir_reg[i]=SRAM[address];
		}
	}
    if(R_activos[15]==1)
	{
		//loadwritePC(SRAM[address,4]);
		dir_reg[SP]=dir_reg[SP]+4*bitcount(R_activos);
	}
}

uint32_t LDR(uint32_t Rn, uint32_t Rm, uint8_t *SRAM)
{
	//Solo para Rm=imm5
	uint32_t Rt, address;
	Rm<<=2;
	address = Rn+Rm;
	Rt=SRAM[address+3] | SRAM[address+2] | SRAM[address+1] | SRAM[address];
	return Rt;
}

uint32_t LDRB(uint32_t Rn, uint32_t Rm, uint8_t *SRAM)
{
	//solo para Rm=imm5
	uint32_t Rt, address;
	address=Rn+Rm;
	Rt=SRAM[address];
	return Rt;
}

uint32_t LDRH(uint32_t Rn, uint32_t Rm, uint8_t *SRAM)
{
	//Solo para  Rm=imm5
	uint32_t Rt, address;
	Rm<<=1;
	address=Rn+Rm;
	Rt=SRAM[address] | SRAM[address+1];
	return Rt;
}

uint32_t LDRSB(uint32_t Rn, uint32_t Rm, uint8_t *SRAM)
{
	uint32_t Rt, address;
	address=Rn+Rm;
	//Hacer extension de signos
	Rt=SRAM[address];
	return Rt;
}

uint32_t LDRSH(uint32_t Rn, uint32_t Rm, uint8_t *SRAM)
{
	uint32_t Rt, address;
	address=Rn+Rm;
	//Hacer extension de signos
	Rt=SRAM[address] | SRAM[address+1];
	return Rt;
}

void STR(uint32_t Rt, uint32_t Rn, uint32_t Rm, uint8_t *SRAM)
{
	//Solo para Rm=imm5
	uint32_t address;
	Rm<<=2;
	address=Rn+Rm;
	SRAM[address]=(uint8_t)Rt; 
	SRAM[address+1]=((uint8_t)Rt>>8);
	SRAM[address+2]=((uint8_t)Rt>>16);
	SRAM[address+3]=((uint8_t)Rt>>24);
}

void STRB(uint32_t Rt, uint32_t Rn, uint32_t Rm, uint8_t *SRAM)
{
	uint32_t address;
	address=Rn+Rm;
	SRAM[address]=(uint8_t)Rt;
}

void STRH(uint32_t Rt, uint32_t Rn, uint32_t Rm, uint8_t *SRAM)
{
	uint32_t address;
	Rm<<=1;
	address=Rn+Rm;
	SRAM[address]=(uint8_t)Rt; 
	SRAM[address+1]=((uint8_t)Rt>>8);
}