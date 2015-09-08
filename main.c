#include <curses.h>
#include "imprimir.h"
#include "instrucciones.h"
#include "instruc_desplazamiento.h"

int main(void)
{
	uint32_t Reg[13];
	initscr();		/* Inicia modo curses */
	curs_set(0);	/* Cursor Invisible */
	raw();			/* Activa modo raw */
	keypad(stdscr, TRUE);	/* Obtener F1, F2, etc */
	noecho();		/* No imprimir los caracteres leidos */
	
	start_color();	/* Permite manejar colores */
	
	init_pair(1, COLOR_WHITE, COLOR_BLACK);	/* Pair 1 -> Texto verde
											   fondo Negro */	
	
	
	border( ACS_VLINE, ACS_VLINE, 
			ACS_HLINE, ACS_HLINE, 
			ACS_ULCORNER, ACS_URCORNER,
			ACS_LLCORNER, ACS_LRCORNER	);
	
	attron(COLOR_PAIR(1));	/* Activa el color verde para el 
							   texto y negro para el fondo Pair 1*/
	
	move(2, 34);	/* Mueve el cursor a la posición y=2, x=34*/
	printw("EMULADOR");	
	refresh();	/* Imprime en la pantalla
					Sin esto el printw no es mostrado */
	move(4, 1);
	printw("ADDS");
	Reg[0]=add(2,4);
	move(5,1);
	init_pair(2,COLOR_BLUE, COLOR_BLACK);
	attron(COLOR_PAIR(2));
	printw("%d", Reg[0]);
	refresh();
	attroff(COLOR_PAIR(2));
	
	getch();	/* Espera entrada del usuario */
	move(4,1);
	printw("SUBS");
	Reg[1]=sub(4,2);
	move(5,1);
	refresh();
	attron(COLOR_PAIR(2));
	printw("%d", Reg[1]);
	attroff(COLOR_PAIR(2));
	
	getch();
	move(4,1);
	printw("MOV");
	refresh();
	Reg[2]=Mov(Reg[0]);
	move(5,1);
	attron(COLOR_PAIR(2));
	printw("%d", Reg[2]);
	attroff(COLOR_PAIR(2));
	attroff(COLOR_PAIR(1));	/* DEshabilita los colores Pair 1 */
	
	getch();
	endwin();	/* Finaliza el modo curses */

	return 0;
}