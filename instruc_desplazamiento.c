#include "instruc_desplazamiento.h"
#define N 0
#define Z 1
#define C 2
#define V 3

// funciones de desplazamiento
uint32_t LSL(uint32_t Rdn, uint32_t Rm, char *dir_flags)
{
	uint32_t j;
	flag_N(Rdn<<Rm, &dir_flags[N]);
	
	flag_Z(Rdn<<Rm, &dir_flags[Z]);
	j=(Rdn<<(Rm-1)&(1<<31));
	if(j==0)
		dir_flags[C]=0;
	else
		dir_flags[C]=1;
	Rdn=Rdn<<Rm;
	return Rdn;
}

uint32_t LSR(uint32_t Rdn, uint32_t Rm,char *dir_flags)
{
	uint32_t j;
	flag_N(Rdn>>Rm, &dir_flags[N]);
	flag_Z(Rdn>>Rm, &dir_flags[Z]);
	j=(Rdn>>(Rm-1)&(1));
	if(j==0)
		dir_flags[C]=0;
	else
		dir_flags[C]=1;
	Rdn=Rdn>>Rm;
	return Rdn;
}

uint32_t ROR(uint32_t Rdn,uint32_t Rm, char *dir_flags)
{
	uint32_t j,k,q;
	int t;
	j=Rdn>>Rm;
	t=32-Rm;
	k=Rdn<<t;
	flag_N(j+k, &dir_flags[N]);
	flag_Z(j+k, &dir_flags[Z]);
	q=(Rdn<<(Rm-1)&(1<<31));
	if(q==0)
		dir_flags[C]=0;
	else
		dir_flags[C]=1;
	
	Rdn=j+k;
	return Rdn;
}

uint32_t ASR(uint32_t Rdn,uint32_t Rm, char *dir_flags)
{
	uint32_t d=0,Rn=0,j;
	int t;
	t=Rdn>>31;
	if(t==0)
	{
		flag_N(Rdn>>Rm, &dir_flags[N]);
		flag_Z(Rdn>>Rm, &dir_flags[Z]);
		j=(Rdn>>(Rm-1)&(1));
	if(j==0)
		dir_flags[C]=0;
	else
		dir_flags[C]=1;
		Rdn=Rdn>>Rm;
	}
	else
	{
		Rn=Rdn>>Rm;
		d=~d<<Rm;
		flag_N(Rn+d, &dir_flags[N]);
		flag_Z(Rn+d, &dir_flags[Z]);
		j=(Rdn>>(Rm-1)&(1));
	if(j==0)
		dir_flags[C]=0;
	else
		dir_flags[C]=1;
		Rdn=Rn+d;
	}
	return Rdn;
}

uint32_t BIC(uint32_t Rdn, uint32_t Rm, char *dir_flags)
{
	flag_N(Rdn&(~Rm), &dir_flags[N]);
	flag_Z(Rdn&(~Rm), &dir_flags[Z]);
	flag_C(Rdn, Rm,Rdn&(~Rm), &dir_flags[C]);
	return Rdn&(~Rm);
}

uint32_t MVN(uint32_t Rdn, char *dir_flags)
{
	flag_N(Rdn, &dir_flags[N]);
	flag_Z(Rdn, &dir_flags[Z]);
	return ~Rdn;
}

uint32_t RSB(uint32_t Rdn, char *dir_flags)
{
	flags(Rdn,Rdn,~Rdn+1, dir_flags);
	return ~Rdn+1;
}

uint32_t REV(uint32_t Rdn)
{
	uint32_t j[4];
	int i,k=0;		
	for(i=32;i<<8;i-=8)
	{
		j[k]=((Rdn<<(32-i))>>24);			
		k=k+1;
	}
	for (i=8;i>=33;i+=8)
	{
		j[k]=j[k]<<(32-i);
		k=k-1;
	}
	return j[0]+j[1]+j[2]+j[3];
}

uint32_t REVG(uint32_t Rdn)
{
	uint32_t j[4];
	int i,k=0;
	for(i=32;i<<16;i-=16)
	{
		j[k]=((Rdn<<(32-i))>>16);
		k=k+1;
	}
	for (i=16;i>=33;i+=8)
	{
		j[k]=j[k]<<(32-i);
		k=k-1;
	}
	return j[0]+j[1];
}

uint32_t REVSH(uint32_t Rdn)
{
	uint32_t j,d=~0;
	uint8_t k;
	j=Rdn<<16;
	k=Rdn;
	k=k>>7;
	if(k==0)
	{
		j=Rdn>>24;
	}
	else
	{
		j=Rdn>>24;
		d=d<<8;
		j=j+d;
	}
	return j;
}
