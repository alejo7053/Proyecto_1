#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/**
*\brief  
  <center><b>flags</b></center> \n  
  <small>prototipo de la funcion  flags que va a operar los registros de las banderas</small> \n   
 \param  Rn <small>operando ingresado</small> \n
 \param  Rm <small>operando ingresado</small> \n
 \param  Rd <small>operando ingresado</small> \n 
 \param  dir_flags <small> puntero que tiene la direccion de las banderas</small> \n 
*/
void flags(uint32_t Rn, uint32_t Rm, uint32_t Rd, char *dir_flags);



/**
*\brief  
  <center><b>flag_N</b></center> \n  
  <small>prototipo de la funcion  flag_N que va a operar el registro de la bandera N</small> \n   
 \param  Rd <small>operando ingresado</small> \n
 \param  dir_flag_N <small> puntero que tiene la direccion de las banderas</small> \n 
*/
void flag_N(uint32_t Rd, char *dir_flag_N);


/**
*\brief  
  <center><b>flag_Z</b></center> \n  
  <small>prototipo de la funcion  flag_Z que va a operar el registro de la bandera Z</small> \n   
 \param  Rd <small>operando ingresado</small> \n
 \param  dir_flag_Z <small> puntero que tiene la direccion de las banderas</small> \n 
*/
void flag_Z(uint32_t Rd, char *dir_flag_Z);


/**
*\brief  
  <center><b>flag_C</b></center> \n  
  <small>prototipo de la funcion  flag_C que va a operar el registro de la bandera C</small> \n   
 \param  Rn <small>operando ingresado</small> \n
 \param  Rm <small>operando ingresado</small> \n
 \param  Rd <small>operando ingresado</small> \n 
 \param  dir_flag_C <small> puntero que tiene la direccion de las banderas</small> \n 
*/
void flag_C(uint32_t Rn, uint32_t Rm, uint32_t Rd, char *dir_flag_C);


/**
*\brief  
  <center><b>flag_V</b></center> \n  
  <small>prototipo de la funcion  flag_V que va a operar el registro de la bandera V</small> \n   
 \param  Rn <small>operando ingresado</small> \n
 \param  Rm <small>operando ingresado</small> \n
 \param  Rd <small>operando ingresado</small> \n 
  \param  dir_flag_V <small> puntero que tiene la direccion de las banderas</small> \n 
*/
void flag_V(uint32_t Rn, uint32_t Rm, uint32_t Rd, char *dir_flag_V);
/**
*\brief  
  <center><b>CMN</b></center> \n  
  <small>prototipo de la funcion  CMN que  va a operar los registros</small> \n   
 \param  Rn <small>operando ingresado</small> \n
 \param  Rm <small>operando ingresado</small> \n 
 \param  dir_flags <small>puntero que tiene la direccion de las banderas</small> \n
 */
void CMN(uint32_t Rn, uint32_t Rm, char *dir_flags);

/**
*\brief  
  <center><b>CMP</b></center> \n  
  <small>prototipo de la funcion  CMP que  va a operar los registros</small> \n   
 \param  Rn <small>operando ingresado</small> \n
 \param  Rm <small>operando ingresado</small> \n 
 \param  dir_flags <small>puntero que tiene la direccion de las banderas</small> \n
 */
void CMP(uint32_t Rn, uint32_t Rm, char *dir_flags);

/**
*\brief  
  <center><b>MUL</b></center> \n  
  <small>prototipo de la funcion  MUL que  va a operar los registros</small> \n   
 \param  Rn <small>operando ingresado</small> \n
 \param  Rm <small>operando ingresado</small> \n 
 \param  dir_flags <small>puntero que tiene la direccion de las banderas</small> \n
 \return <small>retorna  el resultado de la operacion de las MUL</small> \n 
*/
uint32_t MUL(uint32_t Rn, uint32_t Rm, char *dir_flags);

/**
*\brief  
  <center><b>TST</b></center> \n  
  <small>prototipo de la funcion  TST que  va a operar los registros</small> \n   
 \param  Rn <small>operando ingresado</small> \n
 \param  Rm <small>operando ingresado</small> \n 
 \param  dir_flags <small>puntero que tiene la direccion de las banderas</small> \n 
 */
void TST(uint32_t Rn, uint32_t Rm, char *dir_flags);

/**
*\brief     
  <center><b>ADD</b></center>  \n  
  <small>prototipo de la funcion  ADD que  va a operar los registros</small>  \n
  \param Rn <small>operando ingresado</small> \n
  \param Rm <small>operando ingresaaado</small> \n
   \param  dir_flags <small>puntero que tiene la direccion de las banderas</small> \n
  \return  <small>retorna  el resultado de la ADD</small> \n
*/
uint32_t ADD(uint32_t Rn, uint32_t Rm, char *dir_flags);

/**
*\brief     
  <center><b>ADC</b></center>  \n  
  <small>prototipo de la funcion  ADC que  va a operar los registros</small>  \n
  \param Rn <small>operando ingresado</small> \n
  \param Rm <small>operando ingresaaado</small> \n
   \param  dir_flags <small>puntero que tiene la direccion de las banderas</small> \n
  \return  <small>retorna  el resultado de la ADC</small> \n
*/
uint32_t ADC(uint32_t Rn,uint32_t Rm, char *dir_flags);

/**
*\brief                          
  <center><b>SUB</b></center>  \n
  <small>prototipo de la funcion  SUB que  va a operar los registros</small> \n 
 \param  Rn <small>operando ingresado</small> \n
 \param  Rm <small>operando ingresado</small> \n
  \param  dir_flags <small>puntero que tiene la direccion de las banderas</small> \n
  \return <small>retorna  el resultado de la SUB</small> \n
*/
uint32_t SUB(uint32_t Rn, uint32_t Rm,char *dir_flags);

/**
*\brief     
  <center><b>SBC</b></center>  \n  
  <small>prototipo de la funcion  SBC que  va a operar los registros</small>  \n
  \param Rn <small>operando ingresado</small> \n
  \param Rm <small>operando ingresaaado</small> \n
   \param  dir_flags <small>puntero que tiene la direccion de las banderas</small> \n
  \return  <small>retorna  el resultado de la SBC</small> \n
*/
uint32_t SBC(uint32_t Rn,uint32_t Rm, char *dir_flags);

/**
*\brief  
  <center><b>MOV</b></center> \n  
  <small>prototipo de la funcion  MOV que  va a operar los registros</small> \n   
 \param  Rn <small>operando ingresado</small> \n 
  \param  dir_flags <small>puntero que tiene la direccion de las banderas</small> \n
 \return <small>retorna  el resultado de la operacion MOV</small> \n 
*/
uint32_t MOV( uint32_t Rn, char *dir_flags);

/**
*\brief  
 <center><b>AND</b></center> \n
 <small>prototipo de la funcion  AND que  va a operar los registros</small> 
 \param  Rn <small>operando ingresado</small> 
 \param  Rm <small>operando ingresado</small> 
  \param  dir_flags <small>puntero que tiene la direccion de las banderas</small> \n
 \return <small>retorna  el resultado de la operacion AND</small>
*/
uint32_t AND(uint32_t Rn, uint32_t Rm, char *dir_flags);

/**
*\brief 
  <center><b>EOR</b></center> \n
 <small>prototipo de la funcion  EOR que  va a operar los registros</small> 
 \param Rn <small>operando ingresado</small> 
 \param  Rm <small>operando ingresado</small> 
  \param  dir_flags <small>puntero que tiene la direccion de las banderas</small> \n
 \return <small>retorna  el resultado de la operacion EOR</small>
*/
uint32_t EOR(uint32_t Rn, uint32_t Rm, char *dir_flags);

/**
*\brief
  <center><b>ORR</b></center> \n
  <small>prototipo de la funcion  ORR que  va a operar los registros</small> 
 \param Rn <small>operando ingresado</small> 
 \param Rm <small>operando ingresado</small> 
  \param  dir_flags <small>puntero que tiene la direccion de las banderas</small> \n
 \return <small>retorna  el resultado de la operacion ORR</small>
*/
uint32_t ORR(uint32_t Rn, uint32_t Rm, char *dir_flags);

/**
*\brief
  <center><b>NOP</b></center> \n
  <small>prototipo de la funcion  NOP que  va a operar los registros</small>
  \param  dir_reg <small>puntero que tiene la direccion de los registros</small> \n
*/
void NOP(uint32_t *dir_reg);