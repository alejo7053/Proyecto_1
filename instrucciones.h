
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/**
*\brief  
  <center><b>flags</b></center> \n  
  <small>prototipo de la funcion  flags que  va a operar los registros</small> \n   
 \param  a <small>operando ingresado</small> \n
 \param  b <small>operando ingresado</small> \n 
 \param  p <small> puntero hacia  arreglo regf.</small> \n 
*/
void flags(uint32_t a, uint32_t b, uint32_t c, char *p);

/**
*\brief  
  <center><b>CMN</b></center> \n  
  <small>prototipo de la funcion  CMN que  va a operar los registros</small> \n   
 \param  a <small>operando ingresado</small> \n
 \param  b <small>operando ingresado</small> \n 
 \param  p <small>puntero hacia  arreglo regf.</small> \n
  */
void CMN(uint32_t a, uint32_t b, char *p);
/**
*\brief  
  <center><b>CMP</b></center> \n  
  <small>prototipo de la funcion  CMP que  va a operar los registros</small> \n   
 \param  a <small>operando ingresado</small> \n
 \param  b <small>operando ingresado</small> \n 
 \param  p <small>puntero hacia  arreglo regf.> \n
  */
void CMP(uint32_t a, uint32_t b, char *p);

/**
*\brief  
  <center><MUL>flags</b></center> \n  
  <small>prototipo de la funcion  MUL que  va a operar los registros</small> \n   
 \param  a <small>operando ingresado</small> \n
 \param  b <small>operando ingresado</small> \n 
 \param  p <small>puntero hacia  arreglo regf.> \n
 \return <small>retorna  el resultado de la operacion de las MUL</small> \n 
*/
uint32_t MUL(uint32_t a, uint32_t b, char *p);

/**
*\brief  
  <center><b>TST</b></center> \n  
  <small>prototipo de la funcion  TST que  va a operar los registros</small> \n   
 \param  a <small>operando ingresado</small> \n
 \param  b <small>operando ingresado</small> \n 
 \param  p <small>puntero hacia  arreglo regf.</small> \n
  */
void TST(uint32_t a, uint32_t b, char *p);



/**
*\brief     
  <center><b>ADD</b></center>  \n  
  <small>prototipo de la funcion  ADD que  va a operar los registros</small>  \n
  \param a <small>operando ingresado</small> \n
  \param b <small>operando ingresaaado</small> \n
  \return  <small>retorna  el resultado de la ADD</small> \n
*/
uint32_t add(uint32_t Rd, uint32_t Rm);

/**
*\brief                          
  <center><b>SUB</b></center>  \n
  <small>prototipo de la funcion  SUB que  va a operar los registros</small> \n 
 \param  a <small>operando ingresado</small> \n
 \param  b <small>operando ingresado</small> \n
 \return <small>retorna  el resultado de la SUB</small> \n
*/
uint32_t sub(uint32_t Rd, uint32_t Rm);

/**
*\brief  
  <center><b>MOV</b></center> \n  
  <small>prototipo de la funcion  MOV que  va a operar los registros</small> \n   
 \param  b <small>operando ingresado</small> \n 
 \return <small>retorna  el resultado de la operacion MOV</small> \n 
*/
uint32_t Mov( uint32_t Rdn);


/**
*\brief  
 <center><b>AND</b></center> \n
 <small>prototipo de la funcion  AND que  va a operar los registros</small> 
 \param  a <small>operando ingresado</small> 
 \param  b <small>operando ingresado</small> 
 \return <small>retorna  el resultado de la operacion AND</small>
*/
uint32_t And(uint32_t Rd, uint32_t Rm);

/**
*\brief 
  <center><b>EOR</b></center> \n
 <small>prototipo de la funcion  EOR que  va a operar los registros</small> 
 \param a <small>operando ingresado</small> 
 \param  b <small>operando ingresado</small> 
 \return <small>retorna  el resultado de la operacion EOR</small>
*/
uint32_t Eor(uint32_t Rdn, uint32_t Rm);


/**
*\brief
  <center><b>ORR</b></center> \n
  <small>prototipo de la funcion  ORR que  va a operar los registros</small> 
 \param a <small>operando ingresado</small> 
 \param b <small>operando ingresado</small> 
 \return <small>retorna  el resultado de la operacion ORR</small>
*/
uint32_t Orr(uint32_t Rd, uint32_t Rm);
