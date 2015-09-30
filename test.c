/**
	\def N
		\brief Macro que define la posicion de la bandera \a \b N en el registro\a \b regf
	\def Z
		\brief Macro que define la posicion de la bandera \a \b Z en el registro\a \b regf
	\def C
		\brief Macro que define la posicion de la bandera \a \b C en el registro \a \b regf
	\def V
		\brief Macro que define la posicion de la bandera \a \b V en el registro \a \b regf
*/

#include "imprimir.h"
#include "instrucciones.h"
#include "instruc_desplazamiento.h"
#include <curses.h>
#define N 0
#define Z 1
#define C 2
#define V 3

/**
*\brief
 <center><b>TEXT</b></center> \n
 <b><small>Este archivo es para probar las librerias.</small></b>  
*/
int main()
{
	uint32_t reg[12], v=0,a,b; //declaracion de variables tipo unsigned long int
	char regf[4], *f=regf;//orden regf: N,Z,C,V
	int op,oc; // declaracion de variables tipo int		
	printf("escoja la libreria a probar\n1:\t para probar libreria imprimir\n2:\tpara probar libreria instrucciones\n3:\tpara probar libreria instrucciones de desplazamiento\n");// imprime en pantalla para que se escoja la opcion de que libreria se va a usar		
	scanf("%d",&op);// se ingresa la  opcion para elegir la libreria a usar			
	system("cls");
	switch(op)// ingresa a la opcion elegida 
	{
	// se utiliza la libreria imprimir	
	case 1:		
		valor_registro(reg);
		break;
	// se utiliza la libreria instrucciones	
	case 2:
		printf("ingrese los valores de los dos registros a operar\nvalor del primer registro 1:\t");   
		scanf("%d",&a);
		printf("\nvalor del segundo registro 2:\t");	
		scanf("%d",&b);
		printf("escoja los valores para probar las funciones\n1:\tADD\n2:\tSUB\n3:\tMOV\n4:\tAND\n5:\tEor\n6:\tOrr\n7:\tCMN\n8:\tCMP\n9:\tMUL\n10:\tTST");	
		scanf("%d",&oc);		
		system("cls");
		switch(oc) // se elige la operacion que se va a realizar con los registros
		{
		case 1:		
			v=ADD(a, b, f);
			break;
		
		case 2:
			v=SUB(a, b, f);
			break;
		
		case 3:
			v=MOV(b, f);
			break;
        
		case 4:
			v=AND(a, b, f);	
			break;
        
		case 5:
			v=EOR(a, b, f);
			break;
		
		case 6:
			v=ORR(a, b, f);
			break;
		
		case 7:
			CMN(a,b,f);
			break;
		
		case 8:
			CMP(a, b, f);
			break;
		
		case 9:
			v=MUL(a, b, f);
			break;
		
		case 10:
			TST(a, b, f);
			break;
		}
		printf("el resusltado de la operacion es: %d\n\nBanderas:\nN: %d\nZ: %d\nC: %d\nV: %d\n",v, regf[N],regf[Z],regf[C],regf[V]);
		break;
		// muestra el resultado de la operacion
        //libreria instrucciones de desplazamiento
		case 3:
			printf("ingrese los valores de los dos registros a operar\nvalor del primer registro 1:\t");
			scanf("%d",&a);
			printf("\nvalor del segundo registro 2:\t");
			scanf("%d",&b);
			printf("Recuerde que en algunas funciones de desplazamiento el valor del primer\nregistro es el registro a operar y valor del segundo es el valor operando");
			printf("\n asi tambien como hay funciones que solo necesitan el valor del primer registro para operar\n escoja la funcion siguiendo los terminos pasados");
			printf("\nescoja los valores para probar las funciones\n1:\tLSL\n2:\tLSR\n3:\tROR\n4:\tASR\n5:\tBIC\n6:\tMVN\n7:\tRSB\n8:\tREV\n9:\tREVG\n10:\tREVSH");
			scanf("%d",&oc);
			system("cls");
			switch(oc) // se elige la operacion que se va a realizar con los registros
			{
			case 1:	
				v=LSL(a,b, f);
				break;
				
			case 2:
				v=LSR(a,b, f);
				break;
			
			case 3:
				v=ROR(a,b, f);
				break;
			
			case 4:
				v=ASR(a,b, f);
				break;
			
			case 5:
				v=BIC(a,b, f);
				break;
			
			case 6:
				v=MVN(a, f);
				break;
			
			case 7:
				v=RSB(a, f);
				break;
			
			case 8:
				v=REV(a);
				break;
			
			case 9:
				v=REVG(a);
				break;
			
			case 10:
				v=REVSH(a);
				break;
			}
			printf("el resultado de la funcion que se opero es: \n %d",v);
			break;
	}
return 0;
}