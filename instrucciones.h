#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/**
*\brief  
  <center><b>flags</b></center> \n  
  <small>prototipo de la funcion  flags que  va a operar los registros</small> \n   
 \param  a <small>operando ingresado</small> \n
 \param  b <small>operando ingresado</small> \n 
 \param  p <small> puntero hacia  arreglo regf.</small> \n 
*/
void flags(uint32_t Rn, uint32_t Rm, uint32_t Rd, char *dir_flags);
void flag_N(uint32_t Rd, char *dir_flag_N);
void flag_Z(uint32_t Rd, char *dir_flag_Z);
void flag_C(uint32_t Rn, uint32_t Rm, uint32_t Rd, char *dir_flag_C);
void flag_V(uint32_t Rn, uint32_t Rm, uint32_t Rd, char *dir_flag_V);
/**
*\brief  
  <center><b>CMN</b></center> \n  
  <small>prototipo de la funcion  CMN que  va a operar los registros</small> \n   
 \param  a <small>operando ingresado</small> \n
 \param  b <small>operando ingresado</small> \n 
 \param  p <small>puntero hacia  arreglo regf.</small> \n
  */
void CMN(uint32_t Rn, uint32_t Rm, char *dir_flags);
/**
*\brief  
  <center><b>CMP</b></center> \n  
  <small>prototipo de la funcion  CMP que  va a operar los registros</small> \n   
 \param  a <small>operando ingresado</small> \n
 \param  b <small>operando ingresado</small> \n 
 \param  p <small>puntero hacia  arreglo regf.> \n
  */
void CMP(uint32_t Rn, uint32_t Rm, char *dir_flags);

/**
*\brief  
  <center><MUL>flags</b></center> \n  
  <small>prototipo de la funcion  MUL que  va a operar los registros</small> \n   
 \param  a <small>operando ingresado</small> \n
 \param  b <small>operando ingresado</small> \n 
 \param  p <small>puntero hacia  arreglo regf.> \n
 \return <small>retorna  el resultado de la operacion de las MUL</small> \n 
*/
uint32_t MUL(uint32_t Rn, uint32_t Rm, char *dir_flags);

/**
*\brief  
  <center><b>TST</b></center> \n  
  <small>prototipo de la funcion  TST que  va a operar los registros</small> \n   
 \param  a <small>operando ingresado</small> \n
 \param  b <small>operando ingresado</small> \n 
 \param  p <small>puntero hacia  arreglo regf.</small> \n
  */
void TST(uint32_t Rn, uint32_t Rm, char *dir_flags);

/**
*\brief     
  <center><b>ADD</b></center>  \n  
  <small>prototipo de la funcion  ADD que  va a operar los registros</small>  \n
  \param Rd <small>operando ingresado</small> \n
  \param Rm <small>operando ingresaaado</small> \n
  \return  <small>retorna  el resultado de la ADD</small> \n
*/
uint32_t ADD(uint32_t Rn, uint32_t Rm, char *dir_flags);

/**
*\brief                          
  <center><b>SUB</b></center>  \n
  <small>prototipo de la funcion  SUB que  va a operar los registros</small> \n 
 \param  Rd <small>operando ingresado</small> \n
 \param  Rm <small>operando ingresado</small> \n
 \return <small>retorna  el resultado de la SUB</small> \n
*/
uint32_t SUB(uint32_t Rn, uint32_t Rm,char *dir_flags);

/**
*\brief  
  <center><b>MOV</b></center> \n  
  <small>prototipo de la funcion  MOV que  va a operar los registros</small> \n   
 \param  Rdn <small>operando ingresado</small> \n 
 \return <small>retorna  el resultado de la operacion MOV</small> \n 
*/
uint32_t MOV( uint32_t Rn);

/**
*\brief  
 <center><b>AND</b></center> \n
 <small>prototipo de la funcion  AND que  va a operar los registros</small> 
 \param  Rd <small>operando ingresado</small> 
 \param  Rm <small>operando ingresado</small> 
 \return <small>retorna  el resultado de la operacion AND</small>
*/
uint32_t AND(uint32_t Rn, uint32_t Rm, char *dir_flags);

/**
*\brief 
  <center><b>EOR</b></center> \n
 <small>prototipo de la funcion  EOR que  va a operar los registros</small> 
 \param Rdn <small>operando ingresado</small> 
 \param  Rm <small>operando ingresado</small> 
 \return <small>retorna  el resultado de la operacion EOR</small>
*/
uint32_t EOR(uint32_t Rn, uint32_t Rm, char *dir_flags);

/**
*\brief
  <center><b>ORR</b></center> \n
  <small>prototipo de la funcion  ORR que  va a operar los registros</small> 
 \param Rd <small>operando ingresado</small> 
 \param Rm <small>operando ingresado</small> 
 \return <small>retorna  el resultado de la operacion ORR</small>
*/
uint32_t ORR(uint32_t Rn, uint32_t Rm, char *dir_flags);
