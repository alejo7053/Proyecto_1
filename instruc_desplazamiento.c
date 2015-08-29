#include "instruc_desplazamiento.h"
uint32_t LSL(uint32_t a, uint32_t b)
{
    a=a<<b;
    return a;
}
uint32_t LSR(uint32_t a, uint32_t b)
{
a=a>>b;
return a;
}
uint32_t ROR(uint32_t a,uint32_t b)
{
    uint32_t j,k;
    int t;
j=a>>b;
t=32-b;
k=a<<t;
a=j+k;
return a;
}
 uint32_t ASR(uint32_t a,uint32_t b)
 { unsigned d=0;
     int t;
     t=a>>31;
     if(t==0)
     {
       a=a>>b;
     }
       else
       {
           a=a>>b;
         d=~d<<b;
         a=a+d;
       }

     return a; 
 }
 uint32_t BIC(uint32_t a, uint32_t b)
 {
     return a&(~b);
 }
 uint32_t MVN(uint32_t a)
 {
     return ~a;
 }
 uint32_t RSB(uint32_t a)
 {
     return ~a+1;
 }
 uint32_t REV(uint32_t a)
 {
     uint32_t j[4];
     int i,k=0;
     for(i=32;i<<8;i-=8)
     {
         j[k]=((a<<(32-i))>>24);
         k=k+1;
     }
     for (i=8;i>=33;i+=8)
     {
         j[k]=j[k]<<(32-i);
         k=k-1;
     }
     return j[0]+j[1]+j[2]+j[3];
 }
 uint32_t REVG(uint32_t a)
 {
uint32_t j[4];
 int i,k=0;
     for(i=32;i<<16;i-=16)
     {
         j[k]=((a<<(32-i))>>16);
         k=k+1;
     }
     for (i=16;i>=33;i+=8)
     {
         j[k]=j[k]<<(32-i);
         k=k-1;
     }
     return j[0]+j[1];
 }
  uint32_t REVSH(uint32_t a)
  {
      uint32_t j,d=~0;
      uint8_t k;
      j=a<<16;
      k=a;
      k=k>>7;
      if(k==0)
      {
          j=a>>24;
      }
      else
      {
          j=a>>24;
          d=d<<8;
          j=j+d;

      }
        return j;

  }
