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
#include "io.h"
#include <time.h>
#define N 0 
#define Z 1
#define C 2
#define V 3
#define LR 14
#define PC 15
#define SP 13
#define TAM_SRAM 255

int main(void)
{
	uint8_t SRAM[TAM_SRAM], *dir_SRAM=SRAM;
	uint16_t cod;
	uint32_t R[16], *dir_reg=R; //declaracion registro y puntero al registro
	int i=0,t=0;
	char APSR[4], *dir_flags=APSR, ch=0, ch2='a';//orden Banderas APSR: N,Z,C,V
for(i=0;i<=15;i++)
{
	if(IRQ[i]==1)
	{
		NVIC(IRQ, SRAM, dir_reg, dir_flags);
		
	}
}


	for(i=0;i<16;i++) //inicializacion de registro y banderas en 0
	{
		R[i]=0;
		if(i>=0&&i<4)
			APSR[i]=0;
	}
	for(i=0;i<=TAM_SRAM;i++)
	{
		SRAM[i]=255;
	}
	dir_reg[SP]=TAM_SRAM;
	initscr();		/* Inicia modo curses */
	curs_set(0);	/* Cursor Invisible */
	raw();			/* Activa modo raw */
	keypad(stdscr, TRUE);	/* Obtener F1, F2, etc */
	noecho();		/* No imprimir los caracteres leidos */
	start_color();	/* Permite manejar colores */
	initIO();
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
	ch='p';
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
		if(ch2=='a'||ch=='p'||ch=='r'||ch=='P'||ch=='R'||ch=='A'||ch=='M'||ch=='m'||ch=='i'||ch=='I'){	//Solo se ejecuta con las teclas indicadas
		
			if(ch2=='a'||ch=='p'||ch=='r'||ch=='P'||ch=='R'||ch=='A'){
				erase();
				
				mvprintw(4,1,"%s",instructions[dir_reg[PC]]);
				
				border( ACS_VLINE, ACS_VLINE, 
					ACS_HLINE, ACS_HLINE, 
					ACS_ULCORNER, ACS_URCORNER,
					ACS_LLCORNER, ACS_LRCORNER);	//dibuja los bordes
				
				instruction = getInstruction(instructions[dir_reg[PC]]);	//Obtiene la instruccion de acuerdo al registro PC
				decodeInstruction(instruction, dir_reg, dir_flags, dir_SRAM, &cod); 
				mvprintw(4,22,"%.4X",cod);
				
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
				mvprintw(23,1,"P: Paso a Paso  A: Automatico  Q: Salir  R: Reiniciar  M: Memoria  I: Puertos");
				refresh();
				attroff(COLOR_PAIR(1));	/* DEshabilita los colores Pair 1 */
			}
			
			if(ch=='m'||ch=='M'||ch=='i'||ch=='I'){
					t= 0;
			}
			while((ch=='m'||ch=='M')&&(t==0)){
				erase();
				attron(COLOR_PAIR(1));
				border( ACS_VLINE, ACS_VLINE, 
					ACS_HLINE, ACS_HLINE, 
					ACS_ULCORNER, ACS_URCORNER,
					ACS_LLCORNER, ACS_LRCORNER);	//dibuja los bordes
					
				mvprintw(1,2,"EMULADOR CORTEX-M0");
				mvprintw(23,3,"M: Registros  I: Puertos  Q: Salir");
				attroff(COLOR_PAIR(1));
				attron(COLOR_PAIR(3));
				mvprintw(1,22,"SRAM");
				attroff(COLOR_PAIR(3));
				int j=4;
				uint8_t aux=TAM_SRAM;

				for(i=aux;i>191;i=i-4){
					attron(COLOR_PAIR(2));
					mvprintw(j,3,"%X",i);
					mvprintw(j,23,"%X",i-64);
					mvprintw(j,43,"%X",i-128);
					mvprintw(j,63,"%.2X",i-192);
					attroff(COLOR_PAIR(2));
					attron(COLOR_PAIR(3));
					mvprintw(j,7,"%.2X %.2X %.2X %.2X",SRAM[i],SRAM[i-1],SRAM[i-2],SRAM[i-3]);
					mvprintw(j,27,"%.2X %.2X %.2X %.2X",SRAM[i-64],SRAM[(i-64)-1],SRAM[(i-64)-2],SRAM[(i-64)-3]);
					mvprintw(j,47,"%.2X %.2X %.2X %.2X",SRAM[i-128],SRAM[(i-128)-1],SRAM[(i-128)-2],SRAM[(i-128)-3]);
					mvprintw(j,67,"%.2X %.2X %.2X %.2X",SRAM[i-192],SRAM[(i-192)-1],SRAM[(i-192)-2],SRAM[(i-192)-3]);
					attroff(COLOR_PAIR(3));
					j++;
				}
				ch=getch();
				if(ch=='m'||ch=='M'||ch=='I'||ch=='i'||ch=='q'||ch=='Q'){
					t= 1;
					ch2='o';
					if(ch=='q'||ch=='Q'){
						ch2='q';
					}
					erase();
					break;
				}
				if(ch!='m'||ch!='M')
				{
					ch='m';
				}
			}
			if(ch=='i'||ch=='I'){
				t=0;
			}
			while((ch=='i'||ch=='I')&&(t==0)){
				
				erase();
				border( ACS_VLINE, ACS_VLINE, 
					ACS_HLINE, ACS_HLINE, 
					ACS_ULCORNER, ACS_URCORNER,
					ACS_LLCORNER, ACS_LRCORNER);
				
				mvprintw(1,2,"EMULADOR CORTEX-M0");				
				showPorts();
				mvprintw(23,3,"I: Registros  M: Memoria  Q: Salir");
				ch=getch();
				uint8_t data;
			if(ch=='1')
			{
			data = 0x3C;
			IOAccess(0,&data, Write);
			data = 0x0F ;
			IOAccess(1,&data, Write);
			data = 0xF0;
			IOAccess(2,&data, Write);
			changePinPortA(0,1);
			changePinPortA(3,1);
			changePinPortA(5,1);
			changePinPortA(6,1);
			}
			
			if(ch=='2')
			{	
			data = 0xAA;
			IOAccess(10,&data, Write);
			data = 0XCC;
			IOAccess(11,&data, Write);
			data = 0XC3;
			IOAccess(12,&data, Write);
			changePinPortB(0,1);
			changePinPortB(4,1);
			changePinPortB(3,1);
			changePinPortB(6,1);
			}	
				if(ch=='i'||ch=='I'||ch=='m'||ch=='M'||ch=='q'||ch=='Q'){
					t= 1;
					if(ch=='i'||ch=='I'){
						ch2='o';}
					if(ch=='M'||ch=='m'){
						ch2='n';
					}
					if(ch=='q'||ch=='Q'){
						ch2='q';
					}
					erase();
					break;
				}
				if(ch!='i'||ch!='I')
				{
					ch='i';
				}
			}
						
			if(ch2=='o') //Regresar a la pantalla anterior luego de mostrar la memoria SRAM
			{
				erase();
				
				attron(COLOR_PAIR(1)); 
				mvprintw(2,30,"EMULADOR CORTEX-M0");
				mvprintw(4,1,"%s",instructions[dir_reg[PC]-1]);
				
				border( ACS_VLINE, ACS_VLINE, 
					ACS_HLINE, ACS_HLINE, 
					ACS_ULCORNER, ACS_URCORNER,
					ACS_LLCORNER, ACS_LRCORNER);
				
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
				mvprintw(23,1,"P: Paso a Paso  A: Automatico  Q: Salir  R: Reiniciar  M: Memoria  I: Puertos");
				mvprintw(4,20,"%.4X",cod);
				refresh();
				attroff(COLOR_PAIR(1));	/* DEshabilita los colores Pair 1 */
			}
		}
		
		if(ch2!='n'&&ch2!='q'){
			ch=getch();}	//lee caracter del teclado
			
		if(ch=='r'||ch=='R') //Presionando la tecla R reinicia la ejecucion del codigo
		{
			for(i=0;i<16;i++)
			{
				R[i]=0;
				if(i>=0&&i<4)
					APSR[i]=0;
				if(i==13)
					R[i]=TAM_SRAM;
			}
			for(i=0;i<=TAM_SRAM;i++)
			{
				SRAM[i]=255;
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