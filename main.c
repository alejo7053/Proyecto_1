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

int main(void)
{
	uint32_t R[16], *dir_reg=R; //declaracion registro y puntero al registro
	int i=0;
	char APSR[4], *dir_flags=APSR, ch=0, ch2='a';//orden Banderas APSR: N,Z,C,V
	for(i=0;i<16;i++) //inicializacion de registro y banderas en 0
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
	init_pair(1, COLOR_WHITE, COLOR_BLACK); //Color texto blanco, fondo negro
	init_pair(2,COLOR_RED, COLOR_BLACK); //Color texto rojo, fondo negro
	init_pair(3,COLOR_GREEN, COLOR_BLACK); //Color texto verde, fondo negro

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
	
	
	while(ch!='q'&&ch!='Q'){
		
		if(ch=='a'||ch=='A'){
			timeout(500);
			ch2='a';
		}
		
		if(ch=='p'||ch=='P'){
			timeout(-1);
			ch2='p';
		}
		
		if(ch2=='a'||ch=='p'||ch=='r'||ch=='P'||ch=='R'){
			erase();
			
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
			mvprintw(23,7,"P: Paso a Paso\tA: Automatico\tQ: Salir\tR: Reiniciar");
			refresh();
			attroff(COLOR_PAIR(1));	/* DEshabilita los colores Pair 1 */
		}
		ch=getch();
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