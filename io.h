#ifndef _IO_H_
#define	_IO_H_

#include <stdint.h>
#include <curses.h>

#define XINIT 10
#define YINIT 5

/*===================================================*/

#define HIGH	1
#define LOW		0	

#define Read	1
#define Write	0

#define BLUEBLACK	10	/*Text Blue Background Black*/
#define REDBLACK	20	/*Text Red Background Black*/
#define WHITEBLACK	30  /*Text White Background White*/
uint8_t IRQ[16];
typedef struct{
	uint8_t DDR;
	uint8_t PORT;
	uint8_t PIN;
	uint8_t Pins;
	uint8_t Interrupts;
}port_t;

/**
	\brief 
	Escribe datos en el DDRB
	\param address direccion de memoria
	\param data puntero al dato
	\param r_w lee o escribe
*/
void IOAccess(uint8_t address, uint8_t* data, uint8_t r_w);

/**
	\brief 
	Cambia el valor de los puertos A
	\param pin numero del pin
	\param value valor del pin
*/
void changePinPortA(uint8_t pin, uint8_t value);

/**
	\brief 
	Cambia el valor de los puertos B
	\param pin numero del pin
	\param value valor del pin
*/
void changePinPortB(uint8_t pin, uint8_t value);

/**
	\brief 
	Inicializa los puertos de Entrada y Salida
*/
void initIO(void);

/**
	\brief 
	Muestra los puertos en la interfaz.
*/
void showPorts(void);

/**
	\brief 
	Organiza la interfaz de los puertos.
	\param x coordenada X
	\param y coordenada Y
	\param w 
	\param h
*/
void showFrame(int x,int y,int w,int h);

#endif /*_IO_H_*/
