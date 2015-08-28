#include "imprimir.h"
#include "instrucciones.h"
//el siguiente archivo es para probar las librerias hechas
//para mantenerlas en una carpeta aparte
int main()
{
     uint32_t reg[12], v,a,b;
    int op,oc;
    printf("escoja la libreria a probar\n1:\t para probar libreria imprimir\n2:\tpara probar libreria instrucciones\n");
    scanf("%d",&op);
    system("cls");
    switch(op)
    {
    case 1:

        valor_registro(reg);
    break;
    case 2:
        printf("ingrese los valores de los dos registros a operar\nvalor del primer registro 1:\t");
        scanf("%d",&a);
        printf("\nvalor del segundo registro 2:\t");
        scanf("%d",&b);
        printf("escoja los valores para probar las funciones\n1:\tadd\n2:\tsub\n3:\tMov\n4:\tAnd\n5:\tEor\n6:\tOrr\n");
        scanf("%d",&oc);
        system("cls");
        switch(oc)
        {
        case 1:
         v=add(a, b);
            break;
        case 2:
         v=sub(a, b);
            break;
        case 3:
             v=Mov(b);
            break;
        case 4:
             v=And(a, b);
            break;
        case 5:
             v=Eor(a, b);
            break;
        case 6:
             v=Orr(a, b);
            break;
        }
        printf("el resusltado de la operacion es: %d",v);
        break;
    }

    return 0;
}

