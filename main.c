#include <curses.h>
#include "imprimir.h"
#include "instrucciones.h"
#include "instruc_desplazamiento.h"
#include "salto.h"

int main(void)
{
	uint32_t Reg[16];
	int i;
	char regf[4], *f=regf;//orden Banderas regf: N,Z,C,V
	for(i=0;i<16;i++)
	{
		Reg[i]=0;
		if(i>=0&&i<4)
			regf[i]=0;
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
			Reg[15]+=2;
		switch(i)
		{
		case 0:
			mvprintw(4,1,"MOVS R0,#36");
			refresh();
			Reg[0]=Mov(36);
			break;
			
		case 1:
			mvprintw(4,1,"MOVS R1,#6");
			refresh();
			Reg[1]=Mov(6);
			break;
		
		case 2:
			Reg[15]+=4;
			mvprintw(4,1,"BL function");
			refresh();
			if(Reg[14]==8)
			{
				i=100;
				break;
			}
			Reg[14]=Mov(Reg[15]+2);
			break;

		case 3:
			Reg[15]+=2;
			mvprintw(4,1,"MOV R2,R0");
			refresh();
			Reg[2]=Mov(Reg[0]);
			break;
			
		case 4:
			mvprintw(4,1,"MOVS R3,#1");
			Reg[3]=Mov(1);
			break;
		
		case 5:
			mvprintw(4,1,"LSLS R3,R3,#31");
			Reg[3]=LSL(Reg[3],3);
			flags(Reg[0],Reg[1],Reg[4],f);
			break;
			
		case 6:
			mvprintw(4,1,"MOVS R0,#0");
			Reg[0]=Mov(0);
			break;
			
		case 7:
			mvprintw(4,1,"MOVS R4,#0");
			Reg[4]=Mov(0);
			break;
			
		case 8:
			mvprintw(4,1,"LSLS R2,R2,#1");
			Reg[2]=LSL(Reg[2],1);
			break;
			
		case 9:
			mvprintw(4,1,"ADCS R4,R4,R4");
			break;
			
		case 10:
			mvprintw(4,1,"CMP R4,R1");
			CMP(Reg[4],Reg[1],f);
			break;
			
		case 11:
			mvprintw(4,1,"BCC function_lessthan");
			if(BCC(f))
				i=13;
			break;
			
		case 12:
			mvprintw(4,1,"ADDS R0,R0,R3");
			Reg[0]=add(Reg[0],Reg[3]);
			break;
			
		case 13:
			mvprintw(4,1,"SUBS R4,R4,R1");
			Reg[4]=sub(Reg[4],Reg[1]);
			break;
			
		case 14:
			mvprintw(4,1,"LSRS R3,R3,#1");
			Reg[3]=LSR(Reg[3],1);
			break;
			
		case 15:
			mvprintw(4,1,"BNE function_loop");
			if(BNE(f))
			{
				i=7; //case 8
				Reg[15]=20; //PC=20
				break;
			}
			break;
			
		case 16:
			mvprintw(4,1,"MOV R1,R4");
			Reg[1]=Mov(Reg[4]);
			break;
			
		case 17:
			mvprintw(4,1,"BX LR");
			i=1; //salta a function y sale de la ejecucion
			Reg[15]=4; //reinicia PC
			if(1)
				break;
			break;
		}
		attron(COLOR_PAIR(2));
		valor_registro(Reg);
		attroff(COLOR_PAIR(2));
		attron(COLOR_PAIR(3));
		mvprintw(6,30,"Banderas");
		mvprintw(8,20,"N: %d\tZ: %d\tC: %d\tV: %d",regf[0],regf[1],regf[2],regf[3]);
		getch();
		attroff(COLOR_PAIR(3));
		attroff(COLOR_PAIR(1));	/* DEshabilita los colores Pair 1 */
		erase();
	}
	endwin();	/* Finaliza el modo curses */
	return 0;
}