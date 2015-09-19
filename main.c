#include <curses.h>
#include "imprimir.h"
#include "instrucciones.h"
#include "instruc_desplazamiento.h"
#include "salto.h"
#include "decoder.h"
#define N 0
#define Z 1
#define C 2
#define V 3
#define LR 14
#define PC 15

int main(void)
{
	uint32_t R[16], *dir_reg=R;
	int i=0;
	char APSR[4], *dir_flags=APSR, ch=0;//orden Banderas APSR: N,Z,C,V
	for(i=0;i<16;i++)
	{
		R[i]=0;
		if(i>=0&&i<4)
			APSR[i]=0;
	}
	
	initscr();		/* Inicia modo curses */
	curs_set(0);	/* Cursor Invisible */
	raw();			/* Activa modo raw */
	keypad(stdscr, TRUE);	/* Obtener F1, F2, etc */
	noecho();		/* No imprimir los caracteres leidos */
	start_color();	/* Permite manejar colores */
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2,COLOR_RED, COLOR_BLACK);
	init_pair(3,COLOR_GREEN, COLOR_BLACK);

	attron(COLOR_PAIR(1));	/* Activa el color verde para el 
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

	/* Ejemplo de uso 
		Llama la función que separa el mnemonico y los operandos
		Llama la instrucción que decodifica y ejecuta la instrucción
	*/
	// Esto debe ser ciclico para la lectura de todas las instrucciones, de acuerdo
	// al valor del PC (Program Counter)
	i=0;
	while(ch!='q'&&ch!='Q'){
		border( ACS_VLINE, ACS_VLINE, 
			ACS_HLINE, ACS_HLINE, 
			ACS_ULCORNER, ACS_URCORNER,
			ACS_LLCORNER, ACS_LRCORNER);
			
		instruction = getInstruction(instructions[dir_reg[PC]]);
		decodeInstruction(instruction, dir_reg, dir_flags); // Debe ser modificada de acuerdo a cada código

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
		mvprintw(23,7,"P: Paso a Paso\tC: Completo\tQ: Salir\tR: Reiniciar");
		refresh();
		attroff(COLOR_PAIR(1));	/* DEshabilita los colores Pair 1 */
		ch=getch();
		while(ch!='q'&&ch!='Q'&&ch!='r'&&ch!='R'&&ch!='c'&&ch!='C'&&ch!='P'&&ch!='p')
			ch=getch();
		if(ch=='r'||ch=='R')
		{
			for(i=0;i<16;i++)
			{
				R[i]=0;
				if(i>=0&&i<4)
					APSR[i]=0;
			}
		}
		erase();
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