#include "instruc_desplazamiento.h"

uint32_t LSL(uint32_t Rdn, uint32_t Rm)
{
 Rdn=Rdn<<Rm;
return Rdn;
}
uint32_t LSR(uint32_t Rdn, uint32_t Rm)
{
	Rdn=Rdn>>Rm;
	return Rdn;
}
uint32_t ROR(uint32_t Rdn,uint32_t Rm)
{
    uint32_t j,k;
    int t;

	j=Rdn>>Rm;
	t=32-Rm;
	k=Rdn<<t;
	Rdn=j+k;

	return Rdn;
}
 uint32_t ASR(uint32_t Rdn,uint32_t Rm)
 {
	unsigned d=0;
	int t;
	t=Rdn>>31;
	if(t==0)
		Rdn=Rdn>>Rm;
	else
	{
		Rdn=Rdn>>Rm;
		d=~d<<Rm;
		Rdn=Rdn+d;
	}

	return Rdn;
 }
 uint32_t BIC(uint32_t Rdn, uint32_t Rm)
 {
     return Rdn&(~Rm);
 }
 uint32_t MVN(uint32_t Rdn)
 {
     return ~Rdn;
 }
 uint32_t RSB(uint32_t Rdn)
 {
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
