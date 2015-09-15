#include <curses.h>
#include "imprimir.h"
#include "instrucciones.h"
#include "instruc_desplazamiento.h"
#include "salto.h"
#define N 0
#define Z 1
#define C 2
#define V 3
#define LR 14
#define PC 15

int main(void)
{
	uint32_t R[16];
	int i;
	char APSR[4], *dir_flags=APSR;//orden Banderas APSR: N,Z,C,V
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
	for(i=0; i<18; i++)
	{
		border( ACS_VLINE, ACS_VLINE, 
				ACS_HLINE, ACS_HLINE, 
				ACS_ULCORNER, ACS_URCORNER,
				ACS_LLCORNER, ACS_LRCORNER);
		
		attron(COLOR_PAIR(1));	/* Activa el color verde para el 
								   texto y negro para el fondo Pair 1*/
		move(2, 34);	/* Mueve el cursor a la posición y=2, x=34*/
		printw("EMULADOR");
		if(i>0&&i!=2)
			R[PC]+=2;
		switch(i)
		{
		case 0:
			mvprintw(4,1,"MOVS R0,#36");
			refresh();
			R[0]=MOV(36, dir_flags);
			break;
			
		case 1:
			mvprintw(4,1,"MOVS R1,#6");
			refresh();
			R[1]=MOV(6, dir_flags);
			break;
		
		case 2:
			R[PC]+=4;
			mvprintw(4,1,"BL function");
			refresh();
			if(R[LR]==8)
			{
				i=100;
				break;
			}
			R[LR]=MOV(R[PC]+2, dir_flags);
			break;

		case 3:
			R[PC]+=2;
			mvprintw(4,1,"MOV R2,R0");
			refresh();
			R[2]=MOV(R[0], dir_flags);
			break;
			
		case 4:
			mvprintw(4,1,"MOVS R3,#1");
			R[3]=MOV(1, dir_flags);
			break;
		
		case 5:
			mvprintw(4,1,"LSLS R3,R3,#31");
			R[3]=LSL(R[3],3,dir_flags);
			break;
			
		case 6:
			mvprintw(4,1,"MOVS R0,#0");
			R[0]=MOV(0, dir_flags);
			break;
			
		case 7:
			mvprintw(4,1,"MOVS R4,#0");
			R[4]=MOV(0, dir_flags);
			break;
			
		case 8:
			mvprintw(4,1,"LSLS R2,R2,#1");
			R[2]=LSL(R[2],1, dir_flags);
			break;
			
		case 9:
			mvprintw(4,1,"ADCS R4,R4,R4");
			break;
			
		case 10:
			mvprintw(4,1,"CMP R4,R1");
			CMP(R[4],R[1],dir_flags);
			break;
			
		case 11:
			mvprintw(4,1,"BCC function_lessthan");
			if(BCC(dir_flags))
				i=13;
			break;
			
		case 12:
			mvprintw(4,1,"ADDS R0,R0,R3");
			R[0]=ADD(R[0],R[3],dir_flags);
			break;
			
		case 13:
			mvprintw(4,1,"SUBS R4,R4,R1");
			R[4]=SUB(R[4],R[1],dir_flags);
			break;
			
		case 14:
			mvprintw(4,1,"LSRS R3,R3,#1");
			R[3]=LSR(R[3],1,dir_flags);
			break;
			
		case 15:
			mvprintw(4,1,"BNE function_loop");
			if(BNE(dir_flags))
			{
				i=7; //case 8
				R[PC]=20; //PC=20
				break;
			}
			break;
			
		case 16:
			mvprintw(4,1,"MOV R1,R4");
			R[1]=MOV(R[4], dir_flags);
			break;
			
		case 17:
			mvprintw(4,1,"BX LR");
			i=1; //salta a function y sale de la ejecucion
			R[PC]=4; //reinicia PC
			if(1)
				break;
			break;
		}
		attron(COLOR_PAIR(2));
		valor_registro(R);
		attroff(COLOR_PAIR(2));
		attron(COLOR_PAIR(3));
		mvprintw(6,30,"Banderas");
		mvprintw(8,20,"N: %d\tZ: %d\tC: %d\tV: %d",APSR[N],APSR[Z],APSR[C],APSR[V]);
		getch();
		attroff(COLOR_PAIR(3));
		attroff(COLOR_PAIR(1));	/* DEshabilita los colores Pair 1 */
		erase();
	}
	endwin();	/* Finaliza el modo curses */
	return 0;
}