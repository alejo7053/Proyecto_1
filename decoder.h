#ifndef _DECODER_H_
#define	_DECODER_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "instrucciones.h"
#include "instruc_desplazamiento.h"
#include "io.h"
#include "salto.h"
#include <curses.h>


typedef struct
{
	char** array;
}ins_t;

typedef struct
{
	char mnemonic[10]; //Guarda la instruccion
	char op1_type;	//Guarda tipo de operando , registro o inmediato
	char op2_type;	//Guarda tipo de operando , registro o inmediato
	char op3_type;	//Guarda tipo de operando , registro o inmediato
	uint32_t op1_value;	//Guarda valor de operando , registro o inmediato
	uint32_t op2_value;	//Guarda valor de operando , registro o inmediato
	uint32_t op3_value;	//Guarda valor de operando , registro o inmediato
	uint8_t registers_list[16];
}instruction_t;


/** \fn void decodeInstruction(instruction_t instruction)
    \brief Decodifica la instrucción y la ejecuta.
    \param instruction instrucción a decodificar y ejecutar.
*/
void decodeInstruction(instruction_t instruction, uint32_t *dir_reg, char *dir_flags, uint8_t *SRAM, uint16_t *dec);

/** \fn instruction_t getInstruction(char* instStr)
    \brief Obtiene la instrucción separada por partes.
    \param instStr cadena que contiene la instrucción.
	\return instruction_t la instrucción separada por partes.
*/
instruction_t getInstruction(char* instStr);

/** \fn int readFile(char** instructions)
    \brief Lee instrucciones de un archivo.
    \param filename Nombre del archivo.
    \param instructions estructura con arreglo con las instrucciones leidas.
	\return Entero indicando la cantidad de líneas.
*/
int readFile(char* filename, ins_t* instructions);

/** \fn int countLines(FILE fp)
    \brief Cuenta la cantidad de líneas de un archivo.
    \param fp Puntero al archivo.
	\return Entero con la cantidad de líneas del archivo.
*/
int countLines(FILE* fp);

#endif /*_DECODER_H_*/
