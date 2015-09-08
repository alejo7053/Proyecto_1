#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/**
*\brief     
  <center><b>LSL</b></center>  \n  
  <small>prototipo de la funcion  de desplazamiento LSL que  va a operar los registros.</small>  \n
  \param a <small>operando ingresado</small> \n
  \param b <small>operando ingresaaado</small> \n
  \return  <small>retorna  el resultado de la operacion LSL</small> \n
*/
 uint32_t LSL(uint32_t Rdn, uint32_t Rm);

/**
*\brief     
  <center><b>LSR</b></center>  \n  
  <small>prototipo de la funcion  de desplazamiento LSR que  va a operar los registros</small>  \n
  \param a <small>operando ingresado</small> \n
  \param b <small>operando ingresaaado</small> \n
  \return  <small>retorna  el resultado de la operacion LSR</small> \n
*/
 uint32_t LSR(uint32_t Rdn, uint32_t Rm); 
 
/**
*\brief     
  <center><b>ROR</b></center>  \n  
  <small>prototipo de la funcion  de desplazamiento ROR que  va a operar los registros</small>  \n
  \param a <small>operando ingresado</small> \n
  \param b <small>operando ingresaaado</small> \n
  \return  <small>retorna  el resultado de la operacion ROR</small> \n
*/
uint32_t ROR(uint32_t Rdn,uint32_t Rm);

/**
*\brief     
  <center><b>ASR</b></center>  \n  
  <small>prototipo de la funcion  de desplazamiento ASR que  va a operar los registros</small>  \n
  \param a <small>operando ingresado</small> \n
  \param b <small>operando ingresaaado</small> \n
  \return  <small>retorna  el resultado de la operacion ASR</small> \n
*/
 uint32_t ASR(uint32_t Rdn,uint32_t Rm);

/**
*\brief     
  <center><b>BIC</b></center>  \n  
  <small>prototipo de la funcion  de desplazamiento BIC que  va a operar los registros</small>  \n
  \param a <small>operando ingresado</small> \n
  \param b <small>operando ingresaaado</small> \n
  \return  <small>retorna  el resultado de la operacion BIC</small> \n
*/
uint32_t BIC(uint32_t Rdn, uint32_t Rm);

/**
*\brief     
  <center><b>MVN</b></center>  \n  
  <small>prototipo de la funcion  de desplazamiento MVN que  va a operar los registros</small>  \n
  \param a <small>operando ingresado</small> \n
  \return  <small>retorna  el resultado de la operacion MVN</small> \n
*/
uint32_t MVN(uint32_t Rdn);

/**
*\brief     
  <center><b>RSB</b></center>  \n  
  <small>prototipo de la funcion  de desplazamiento RSB que  va a operar los registros</small>  \n
  \param a <small>operando ingresado</small> \n
  \return  <small>retorna  el resultado de la operacion RSB</small> \n
*/
uint32_t RSB(uint32_t Rdn);


/**
*\brief     
  <center><b>REV</b></center>  \n  
  <small>prototipo de la funcion  de desplazamiento REV que  va a operar los registros</small>  \n
  \param a <small>operando ingresado</small> \n
  \return  <small>retorna  el resultado de la operacion REV</small> \n
*/
uint32_t REV(uint32_t Rdn);


/**
*\brief     
  <center><b>REVG</b></center>  \n  
  <small>prototipo de la funcion  de desplazamiento REV que  va a operar los registros</small>  \n
  \param a <small>operando ingresado</small> \n
  \return  <small>retorna  el resultado de la operacion REVG</small> \n
*/
uint32_t REVG(uint32_t Rdn);

/**
*\brief     
  <center><b>REVSH</b></center>  \n  
  <small>prototipo de la funcion  de desplazamiento REV que  va a operar los registros</small>  \n
  \param a <small>operando ingresado</small> \n
  \return  <small>retorna  el resultado de la operacion REVSH</small> \n
*/
uint32_t REVSH(uint32_t Rdn);
