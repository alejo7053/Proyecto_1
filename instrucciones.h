
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/**
*\brief
  <center><b>FLAGS</b></center> \n
  <small>prototipo de la funcion  fLAGS que  va a operar los registros</small> 
*/
void flags(uint32_t a, uint32_t b, uint32_t c, char *p);


/**
*\brief     
  <center><b>ADD</b></center>  \n  
  <small>prototipo de la funcion  ADD que  va a operar los registros</small>  \n
  \param a <small>operando ingresado</small> \n
  \param b <small>operando ingresaaado</small> \n
  \return  <small>retorna  el resultado de la ADD</small> \n
*/
uint32_t add(uint32_t a, uint32_t b);

/**
*\brief                          
  <center><b>SUB</b></center>  \n
  <small>prototipo de la funcion  SUB que  va a operar los registros</small> \n 
 \param  a <small>operando ingresado</small> \n
 \param  b <small>operando ingresado</small> \n
 \return <small>retorna  el resultado de la SUB</small> \n
*/
uint32_t sub(uint32_t a, uint32_t b);

/**
*\brief  
  <center><b>MOV</b></center> \n  
  <small>prototipo de la funcion  MOV que  va a operar los registros</small> \n   
 \param  b <small>operando ingresado</small> \n 
 \return <small>retorna  el resultado de la operacion MOV</small> \n 
*/
uint32_t Mov( uint32_t b);


/**
*\brief  
 <center><b>AND</b></center> \n
 <small>prototipo de la funcion  AND que  va a operar los registros</small> 
 \param  a <small>operando ingresado</small> 
 \param  b <small>operando ingresado</small> 
 \return <small>retorna  el resultado de la operacion AND</small>
*/
uint32_t And(uint32_t a, uint32_t b);

/**
*\brief 
  <center><b>EOR</b></center> \n
 <small>prototipo de la funcion  EOR que  va a operar los registros</small> 
 \param a <small>operando ingresado</small> 
 \param  b <small>operando ingresado</small> 
 \return <small>retorna  el resultado de la operacion EOR</small>
*/
uint32_t Eor(uint32_t a, uint32_t b);


/**
*\brief
  <center><b>ORR</b></center> \n
  <small>prototipo de la funcion  ORR que  va a operar los registros</small> 
 \param a <small>operando ingresado</small> 
 \param b <small>operando ingresado</small> 
 \return <small>retorna  el resultado de la operacion ORR</small>
*/
uint32_t Orr(uint32_t a, uint32_t b);
