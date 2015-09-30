/**
	\def N
		\brief Macro que define la posicion de la bandera \a \b N en el registro\a \b APSR
	\def Z
		\brief Macro que define la posicion de la bandera \a \b Z en el registro\a \b APSR
	\def C
		\brief Macro que define la posicion de la bandera \a \b C en el registro \a \b APSR
	\def V
		\brief Macro que define la posicion de la bandera \a \b V en el registro \a \b APSR
	\def SP
		\brief Macro que define la posicion del registro \a \b SP en el arreglo \a \b R
	\def LR
		\brief Macro que define la posicion del registro \a \b LR en el arreglo \a \b R
	\def PC
		\brief Macro que define la posicion del registro \a \b PC en el arreglo \a \b R
	\def TAM_SRAM
		\brief Macro que define el tamaño del arreglo que emula la memoria \a \b SRAM
*/

#include <curses.h>
#include "imprimir.h"
#include "instrucciones.h"
#include "instruc_desplazamiento.h"
#include "salto.h"
#include "decoder.h"
#include <time.h>
#define N 0 
#define Z 1
#define C 2
#define V 3
#define LR 14
#define PC 15
#define SP 13
#define TAM_SRAM 40

int main(void)
{
	uint8_t SRAM[TAM_SRAM], *dir_SRAM=SRAM;
	uint32_t R[16], *dir_reg=R; //declaracion registro y puntero al registro
	int i=0;
	char APSR[4], *dir_flags=APSR, ch=0, ch2='a';//orden Banderas APSR: N,Z,C,V
	for(i=0;i<16;i++) //inicializacion de registro y banderas en 0
	{
		R[i]=0;
		if(i>=0&&i<4)
			APSR[i]=0;
	}
	dir_reg[SP]=TAM_SRAM;
	initscr();		/* Inicia modo curses */
	curs_set(0);	/* Cursor Invisible */
	raw();			/* Activa modo raw */
	keypad(stdscr, TRUE);	/* Obtener F1, F2, etc */
	noecho();		/* No imprimir los caracteres leidos */
	start_color();	/* Permite manejar colores */
	init_pair(1, COLOR_WHITE, COLOR_BLACK); //Color texto blanco, fondo negro
	init_pair(2,COLOR_RED, COLOR_BLACK); //Color texto rojo, fondo negro
	init_pair(3,COLOR_GREEN, COLOR_BLACK); //Color texto verde, fondo negro

	attron(COLOR_PAIR(1));	/* Activa el color blanco para el 
							   texto y negro para el fondo Pair 1*/
	//------- No modificar ------//	
	int num_instructions;
	ins_t read;
	char** instructions;
	instruction_t instruction;

	num_instructions = readFile("code.txt", &read);
	if(num_instructions==-1)
		return 0;

	if(read.array==NULL)
		return 0;

	instructions = read.array; /* Arreglo con las instrucciones */
	//---------------------------//	
	
	//ciclo para leer e imprimir las instrucciones, termina al presionar la tecla Q
	while(ch!='q'&&ch!='Q'){
		
		if(ch=='a'||ch=='A'){	//Presiona tecla A y se inicia el modo automatico
			timeout(500);
			ch2='a';
		}
		
		if(ch=='p'||ch=='P'){	//Presiona tecla P y se inicia modo paso a paso
			timeout(-1);
			ch2='p';
		}
		
		if(ch2=='a'||ch=='p'||ch=='r'||ch=='P'||ch=='R'){	//Solo se ejecuta con las teclas indicadas
			erase();
			
			border( ACS_VLINE, ACS_VLINE, 
					ACS_HLINE, ACS_HLINE, 
					ACS_ULCORNER, ACS_URCORNER,
					ACS_LLCORNER, ACS_LRCORNER);	//dibuja los bordes
			
			instruction = getInstruction(instructions[dir_reg[PC]]);	//Obtiene la instruccion de acuerdo al registro PC
			decodeInstruction(instruction, dir_reg, dir_flags, dir_SRAM); 
			
			mvprintw(2,30,"EMULADOR CORTEX-M0");
			attron(COLOR_PAIR(2));
			valor_registro(R);
			attroff(COLOR_PAIR(2));
			attron(COLOR_PAIR(3));
			mvprintw(6,50,"Banderas");
			mvprintw(8,50,"N: %d",APSR[N]);
			mvprintw(9,50,"Z: %d",APSR[Z]);
			mvprintw(10,50,"C: %d",APSR[C]);
			mvprintw(11,50,"V: %d",APSR[V]);
			attroff(COLOR_PAIR(3));
			mvprintw(23,7,"P: Paso a Paso\tA: Automatico\tQ: Salir\tR: Reiniciar");
			refresh();
			attroff(COLOR_PAIR(1));	/* DEshabilita los colores Pair 1 */
		}

		ch=getch();	//lee caracter del teclado
		if(ch=='r'||ch=='R') //Presionando la tecla R reinicia la ejecucion del codigo
		{
			for(i=0;i<16;i++)
			{
				R[i]=0;
				if(i>=0&&i<4)
					APSR[i]=0;
			}
		}
	}
	

		//------- No modificar ------//	
	/* Libera la memoria reservada para las instrucciones */ //ERROR LA LIBERAR MEMORIA
	for(i=0; i<num_instructions; i++){
		free(read.array[i]);
	}	
	free(read.array);
	//---------------------------//
	endwin();	/* Finaliza el modo curses */
	return 0;
}