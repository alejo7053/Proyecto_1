#include <curses.h>
#include "imprimir.h"
#include "instrucciones.h"
#include "instruc_desplazamiento.h"

int main(void)
{
	uint32_t Reg[13];
	int i;
	char regf[4], *f=regf;//orden Banderas regf: N,Z,C,V
	for(i=0;i<13;i++)
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
	
	init_pair(1, COLOR_WHITE, COLOR_BLACK);	/* Pair 1 -> Texto verde
											   fondo Negro */	
	
	init_pair(2,COLOR_RED, COLOR_BLACK);
	init_pair(3,COLOR_GREEN, COLOR_BLACK);
	
	for(i=0; i<5; i++)
	{
		border( ACS_VLINE, ACS_VLINE, 
				ACS_HLINE, ACS_HLINE, 
				ACS_ULCORNER, ACS_URCORNER,
				ACS_LLCORNER, ACS_LRCORNER	);
		
		attron(COLOR_PAIR(1));	/* Activa el color verde para el 
								   texto y negro para el fondo Pair 1*/
		move(2, 34);	/* Mueve el cursor a la posición y=2, x=34*/
		printw("EMULADOR");
		switch(i)
		{
			case 0:
				move(4,1);
				printw("MOV(R0,6)");
				refresh();
				Reg[0]=Mov(6);
				move(5,1);
				attron(COLOR_PAIR(2));
				valor_registro(Reg);
				attroff(COLOR_PAIR(2));
				break;
				
			case 1:
				move(4,1);
				printw("MOV(R1,2)");
				refresh();
				Reg[1]=Mov(2);
				move(5,1);
				attron(COLOR_PAIR(2));
				valor_registro(Reg);
				attroff(COLOR_PAIR(2));
				break;
				
			case 2:
				move(4, 1);
				printw("ADDS(R2,R0,R1)");
				Reg[2]=add(Reg[0],Reg[1]);
				flags(Reg[0],Reg[1],Reg[2],f);
				attron(COLOR_PAIR(2));
				valor_registro(Reg);
				attroff(COLOR_PAIR(2));
				break;
				
			case 3:
				move(4,1);
				printw("SUBS(R3,R0,R1)");
				Reg[3]=sub(Reg[0],Reg[1]);
				flags(Reg[0],Reg[1],Reg[3],f);
				move(5,1);
				attron(COLOR_PAIR(2));
				valor_registro(Reg);
				attroff(COLOR_PAIR(2));
				break;
			
			case 4:
				move(4,1);
				printw("SUBS(R4,R1,R0)");
				Reg[4]=sub(Reg[1],Reg[0]);
				flags(Reg[0],Reg[1],Reg[4],f);
				move(5,1);
				attron(COLOR_PAIR(2));
				valor_registro(Reg);
				attroff(COLOR_PAIR(2));
				break;

		}
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