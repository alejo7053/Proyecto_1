#include "instrucciones.h"
#define N 0
#define Z 1
#define C 2
#define V 3
#define PC 15

void flags(uint32_t Rn, uint32_t Rm, uint32_t Rd, char *dir_flags) 
//declaracion del tipo de la funcion void y variables tipo unsigned long int y char el puntero
{
	uint32_t aux=2147483648UL;
	//Bandera N
	if(Rd<aux)
		dir_flags[N]=0;
	else
		dir_flags[N]=1;
	//Bandera Z
	if(Rd==0)
		dir_flags[Z]=1;
	else
		dir_flags[Z]=0;
	//Bandera C
	if(((Rn>=aux) & (Rm<aux) & (Rd<aux))||((Rm>=aux) & (Rn<aux) & (Rd<aux))||((Rn>=aux) & (Rm>=aux)))
		dir_flags[C]=1;
	else
		dir_flags[C]=0;
	//Bandera V
	if(((Rn>=aux) & (Rm>=aux) & (Rd<aux))||((Rn<aux) & (Rm<aux)) & (Rd>=aux))
		dir_flags[V]=1;
	else
		dir_flags[V]=0;
}

void flag_N(uint32_t Rd, char *dir_flag_N)
{
	uint32_t aux=2147483648UL;
	if(Rd<aux)
		*dir_flag_N=0;
	else
		*dir_flag_N=1;
}

void flag_Z(uint32_t Rd, char *dir_flag_Z)
{
	if(Rd==0)
		*dir_flag_Z=1;
	else
		*dir_flag_Z=0;
}

void flag_C(uint32_t Rn, uint32_t Rm, uint32_t Rd, char *dir_flag_C)
{
	uint32_t aux=2147483648UL;
	if(((Rn>=aux) && (Rm<aux) && (Rd<aux))||((Rm>=aux) && (Rn<aux) && (Rd<aux))||((Rn>=aux) && (Rm>=aux)))
		*dir_flag_C=1;
	else
		*dir_flag_C=0;
}

void flag_V(uint32_t Rn, uint32_t Rm, uint32_t Rd, char *dir_flag_V)
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
	flags(Rn, Rm, Rn+(~Rm + 1), dir_flags);
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

uint32_t ADD(uint32_t Rn, uint32_t Rm, char *dir_flags) //declaracion del tipo de la funcion y variables tipo unsigned long int 
{
	flags(Rn, Rm, Rn+Rm, dir_flags);
	return Rn+Rm; // operacion suma  que se realiza y su retorno
}

uint32_t ADC(uint32_t Rn,uint32_t Rm, char *dir_flags) 
{
	uint32_t aux=Rn+Rm+dir_flags[C];
	flags(Rn,Rm,aux, dir_flags);
	return aux;
}

uint32_t SUB(uint32_t Rn, uint32_t Rm,char *dir_flags)
{
	flags(Rn, Rm, Rn-Rm, dir_flags);
	return Rn+(~Rm + 1);// operacion mover  que se realiza y su retorno
}

uint32_t SBC(uint32_t Rn,uint32_t Rm, char *dir_flags)
{
	flags(Rn,(~Rm),Rn+(~Rm)+dir_flags[C], dir_flags);
	return Rn+(~Rm)+dir_flags[C];
	
}
uint32_t MOV(uint32_t Rn, char *dir_flags)
{
	flag_N(Rn, &dir_flags[N]); //Revisar
	flag_Z(Rn, &dir_flags[Z]); //Revisar
	return Rn; // operacion mover  que se realiza y su retorno
}

uint32_t AND(uint32_t Rn, uint32_t Rm, char *dir_flags)
{
	flag_N(Rn&Rm, &dir_flags[N]);
	flag_Z(Rn&Rm, &dir_flags[Z]);
	flag_C(Rn, Rm, Rn&Rm, &dir_flags[C]);
	return Rn&Rm; // operacion And  que se realiza y su retorno
}

uint32_t EOR(uint32_t Rn, uint32_t Rm, char *dir_flags)
{
	flag_N(Rn^Rm, &dir_flags[N]);
	flag_Z(Rn^Rm, &dir_flags[Z]);
	flag_C(Rn, Rm, Rn^Rm, &dir_flags[C]);
	return Rn^Rm; // operacion Eor  que se realiza y su retorno
}

uint32_t ORR(uint32_t Rn, uint32_t Rm, char *dir_flags)
{
	flag_N(Rn|Rm, &dir_flags[N]);
	flag_Z(Rn|Rm, &dir_flags[Z]);
	flag_C(Rn, Rm, Rn|Rm, &dir_flags[C]);
	return Rn|Rm;// operacion Oor  que se realiza y su retorno
}

void NOP(uint32_t *dir_reg)
{
	dir_reg[PC]++;
}