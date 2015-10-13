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
#define TAM_SRAM 255

int main(void)
{
	uint8_t SRAM[TAM_SRAM], *dir_SRAM=SRAM;
	uint32_t R[16], *dir_reg=R; //declaracion registro y puntero al registro
	int i=0,t=0,l=0, op=3;
	char APSR[4], *dir_flags=APSR, ch=0, ch2='a';//orden Banderas APSR: N,Z,C,V
	int IRQ[5]={0,0,0,0,0}; // se declara con 1 cuando hay una interrupcion
	int interrupcion=0; // contador de interrupciones

for(i=0;i<=4;i++)
{
	if(IRQ[i]==1)
	{
		interrupcion++;
	}
}
if(interrupcion==1)
{
			fu(IRQ, SRAM, dir_reg, dir_flags);
}
else
{
// codigo principal	
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
	SRAM[TAM_SRAM-129]=03; //borrar esto
	SRAM[TAM_SRAM-156]=50; //borrar esto
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
		if(ch2=='a'||ch=='p'||ch=='r'||ch=='P'||ch=='R'||ch=='M'||ch=='m'){	//Solo se ejecuta con las teclas indicadas
		
			if(ch2=='a'||ch=='p'||ch=='r'||ch=='P'||ch=='R'){
				erase();
				border( ACS_VLINE, ACS_VLINE, 
					ACS_HLINE, ACS_HLINE, 
					ACS_ULCORNER, ACS_URCORNER,
					ACS_LLCORNER, ACS_LRCORNER);	//dibuja los bordes
					
				instruction = getInstruction(instructions[dir_reg[PC]]);	//Obtiene la instruccion de acuerdo al registro PC
				decodeInstruction(instruction, dir_reg, dir_flags, dir_SRAM, &op); 
				
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
				mvprintw(23,3,"P: Paso a Paso   A: Automatico   Q: Salir   R: Reiniciar  M: Memoria");
				refresh();
				attroff(COLOR_PAIR(1));	/* DEshabilita los colores Pair 1 */
			}
			
			if(ch=='m'||ch=='M'){
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
				mvprintw(23,3,"M: Registros");
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
					mvprintw(j,27,"%.2X %.2X %.2X %.2X",SRAM[i-128],SRAM[(i-128)-1],SRAM[(i-128)-2],SRAM[(i-128)-3]);
					mvprintw(j,47,"%.2X %.2X %.2X %.2X",SRAM[i-128],SRAM[(i-128)-1],SRAM[(i-128)-2],SRAM[(i-128)-3]);
					mvprintw(j,67,"%.2X %.2X %.2X %.2X",SRAM[i-192],SRAM[(i-192)-1],SRAM[(i-192)-2],SRAM[(i-192)-3]);
					attroff(COLOR_PAIR(3));
					j++;
				}
				ch=getch();
				if(ch=='m'||ch=='M'){
					l++;
					t= l % 2;
					ch2='o';
					erase();
					break;
				}
				if(ch!='m'||ch!='M')
				{
					ch='m';
				}
			}
			if(ch2=='o') //Regresar a la pantalla anterior luego de mostrar la memoria SRAM
			{
				border( ACS_VLINE, ACS_VLINE, 
					ACS_HLINE, ACS_HLINE, 
					ACS_ULCORNER, ACS_URCORNER,
					ACS_LLCORNER, ACS_LRCORNER);
				
				switch(op) //Imprime las instrucciones de acuerdo a la cantidad de parametros 1, 2 o 3
				{
					case 1:
						if(instruction.op1_type=='#')
							mvprintw(4,1,"%s %c%d", instruction.mnemonic, instruction.op1_type, instruction.op1_value);
						else
							mvprintw(4,1,"%s %c%d", instruction.mnemonic, instruction.op1_type, instruction.op1_value);
						break;	
					
					case 2:
					if(instruction.op2_type=='#')
						mvprintw(4,1,"%s %c%d,%c%d", instruction.mnemonic, instruction.op1_type, instruction.op1_value, instruction.op2_type, instruction.op2_value);
					else
						mvprintw(4,1,"%s %c%d,%c%d", instruction.mnemonic, instruction.op1_type, instruction.op1_value, instruction.op2_type, instruction.op2_value);
					break;
					
					case 3:		
						if( instruction.op3_type=='#' || instruction.op2_type=='#')
							mvprintw(4,1,"%s %c%d,%c%d,%c%d", instruction.mnemonic, instruction.op1_type, instruction.op1_value, instruction.op2_type, instruction.op2_value, instruction.op3_type, instruction.op3_value);
						else
							mvprintw(4,1,"%s %c%d,%c%d,%c%d", instruction.mnemonic, instruction.op1_type, instruction.op1_value, instruction.op2_type, instruction.op2_value, instruction.op3_type, instruction.op3_value);
						break;
						
					case 4:
						mvprintw(4,1,"BX LR");
						break;
						
					case 5:
						mvprintw(4,1,"NOP");
						break;
				}
				
				attron(COLOR_PAIR(1)); 
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
				mvprintw(23,3,"P: Paso a Paso   A: Automatico   Q: Salir   R: Reiniciar  M: Memoria");
				refresh();
				attroff(COLOR_PAIR(1));	/* DEshabilita los colores Pair 1 */
			}
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
			for(i=0;i<=TAM_SRAM;i++)
			{
				SRAM[i]=255;
			}
		//l++;
		//t=l % 2;
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