#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/**
*\brief  
  <center><b>B</b></center> \n  
  <small>prototipo de la funcion  B que va a modificar el registro PC</small> \n   
 \param  label <small>operando ingresado</small> \n 
 \param  dir_reg <small> puntero que tiene la direccion de los registros</small> \n 
*/
void B(uint32_t label, uint32_t *dir_reg);

/**
*\brief  
  <center><b>BL</b></center> \n  
  <small>prototipo de la funcion  BL que va a modificar el registro PC</small> \n   
 \param  label <small>operando ingresado</small> \n 
 \param  dir_reg <small> puntero que tiene la direccion de los registros</small> \n 
*/
void BL(uint32_t label, uint32_t *dir_reg);

/**
*\brief  
  <center><b>BX</b></center> \n  
  <small>prototipo de la funcion  BX que va a modificar el registro PC</small> \n    
 \param  dir_reg <small> puntero que tiene la direccion de los registros</small> \n 
*/
void BX(uint32_t *dir_reg);

/**
*\brief  
  <center><b>BEQ</b></center> \n  
  <small>prototipo de la funcion  BEQ que va a modificar el registro PC</small> \n   
 \param  label <small>operando ingresado</small> \n 
 \param  dir_reg <small> puntero que tiene la direccion de los registros</small> \n 
 \param  dir_flags <small> puntero que tiene la direccion de las banderas</small> \n
*/
void BEQ(uint32_t label, uint32_t *dir_reg, char *dir_flags);

/**
*\brief  
  <center><b>BNE</b></center> \n  
  <small>prototipo de la funcion  BNE que va a modificar el registro PC</small> \n   
 \param  label <small>operando ingresado</small> \n 
 \param  dir_reg <small> puntero que tiene la direccion de los registros</small> \n 
 \param  dir_flags <small> puntero que tiene la direccion de las banderas</small> \n
*/
void BNE(uint32_t label, uint32_t *dir_reg, char *dir_flags);

/**
*\brief  
  <center><b>BCS</b></center> \n  
  <small>prototipo de la funcion  BCS que va a modificar el registro PC</small> \n   
 \param  label <small>operando ingresado</small> \n 
 \param  dir_reg <small> puntero que tiene la direccion de los registros</small> \n 
 \param  dir_flags <small> puntero que tiene la direccion de las banderas</small> \n
*/
void BCS(uint32_t label, uint32_t *dir_reg, char *dir_flags);

/**
*\brief  
  <center><b>BCC</b></center> \n  
  <small>prototipo de la funcion  BCC que va a modificar el registro PC</small> \n   
 \param  label <small>operando ingresado</small> \n 
 \param  dir_reg <small> puntero que tiene la direccion de los registros</small> \n 
 \param  dir_flags <small> puntero que tiene la direccion de las banderas</small> \n
*/
void BCC(uint32_t label, uint32_t *dir_reg, char *dir_flags);

/**
*\brief  
  <center><b>BMI</b></center> \n  
  <small>prototipo de la funcion  BMI que va a modificar el registro PC</small> \n   
 \param  label <small>operando ingresado</small> \n 
 \param  dir_reg <small> puntero que tiene la direccion de los registros</small> \n 
 \param  dir_flags <small> puntero que tiene la direccion de las banderas</small> \n
*/
void BMI(uint32_t label, uint32_t *dir_reg, char *dir_flags);

/**
*\brief  
  <center><b>BPL</b></center> \n  
  <small>prototipo de la funcion  BPL que va a modificar el registro PC</small> \n   
 \param  label <small>operando ingresado</small> \n 
 \param  dir_reg <small> puntero que tiene la direccion de los registros</small> \n 
 \param  dir_flags <small> puntero que tiene la direccion de las banderas</small> \n
*/
void BPL(uint32_t label, uint32_t *dir_reg, char *dir_flags);

/**
*\brief  
  <center><b>BVS</b></center> \n  
  <small>prototipo de la funcion  BVS que va a modificar el registro PC</small> \n   
 \param  label <small>operando ingresado</small> \n 
 \param  dir_reg <small> puntero que tiene la direccion de los registros</small> \n 
 \param  dir_flags <small> puntero que tiene la direccion de las banderas</small> \n
*/
void BVS(uint32_t label, uint32_t *dir_reg, char *dir_flags);

/**
*\brief  
  <center><b>BVC</b></center> \n  
  <small>prototipo de la funcion  BVC que va a modificar el registro PC</small> \n   
 \param  label <small>operando ingresado</small> \n 
 \param  dir_reg <small> puntero que tiene la direccion de los registros</small> \n 
 \param  dir_flags <small> puntero que tiene la direccion de las banderas</small> \n
*/
void BVC(uint32_t label, uint32_t *dir_reg, char *dir_flags);

/**
*\brief  
  <center><b>BHI</b></center> \n  
  <small>prototipo de la funcion  BHI que va a modificar el registro PC</small> \n   
 \param  label <small>operando ingresado</small> \n 
 \param  dir_reg <small> puntero que tiene la direccion de los registros</small> \n 
 \param  dir_flags <small> puntero que tiene la direccion de las banderas</small> \n
*/
void BHI(uint32_t label, uint32_t *dir_reg, char *dir_flags);

/**
*\brief  
  <center><b>BLS</b></center> \n  
  <small>prototipo de la funcion  BLS que va a modificar el registro PC</small> \n   
 \param  label <small>operando ingresado</small> \n 
 \param  dir_reg <small> puntero que tiene la direccion de los registros</small> \n 
 \param  dir_flags <small> puntero que tiene la direccion de las banderas</small> \n
*/
void BLS(uint32_t label, uint32_t *dir_reg, char *dir_flags);

/**
*\brief  
  <center><b>BGE</b></center> \n  
  <small>prototipo de la funcion  BGE que va a modificar el registro PC</small> \n   
 \param  label <small>operando ingresado</small> \n 
 \param  dir_reg <small> puntero que tiene la direccion de los registros</small> \n 
 \param  dir_flags <small> puntero que tiene la direccion de las banderas</small> \n
*/
void BGE(uint32_t label, uint32_t *dir_reg, char *dir_flags);

/**
*\brief  
  <center><b>BLT</b></center> \n  
  <small>prototipo de la funcion  BLT que va a modificar el registro PC</small> \n   
 \param  label <small>operando ingresado</small> \n 
 \param  dir_reg <small> puntero que tiene la direccion de los registros</small> \n 
 \param  dir_flags <small> puntero que tiene la direccion de las banderas</small> \n
*/
void BLT(uint32_t label, uint32_t *dir_reg, char *dir_flags);

/**
*\brief  
  <center><b>BGT</b></center> \n  
  <small>prototipo de la funcion  BGT que va a modificar el registro PC</small> \n   
 \param  label <small>operando ingresado</small> \n 
 \param  dir_reg <small> puntero que tiene la direccion de los registros</small> \n 
 \param  dir_flags <small> puntero que tiene la direccion de las banderas</small> \n
*/
void BGT(uint32_t label, uint32_t *dir_reg, char *dir_flags);

/**
*\brief  
  <center><b>BLE</b></center> \n  
  <small>prototipo de la funcion  BLE que va a modificar el registro PC</small> \n   
 \param  label <small>operando ingresado</small> \n 
 \param  dir_reg <small> puntero que tiene la direccion de los registros</small> \n 
 \param  dir_flags <small> puntero que tiene la direccion de las banderas</small> \n
*/
void BLE(uint32_t label, uint32_t *dir_reg, char *dir_flags);

/**
*\brief  
  <center><b>BAL</b></center> \n  
  <small>prototipo de la funcion  BAL que va a modificar el registro PC</small> \n   
 \param  label <small>operando ingresado</small> \n 
 \param  dir_reg <small> puntero que tiene la direccion de los registros</small> \n 
*/
void BAL(uint32_t label, uint32_t *dir_reg);