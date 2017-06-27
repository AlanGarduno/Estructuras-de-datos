#include <stdio.h>
#include "lista.h"
#include "lenguajes.h"
#include <conio.h>
#include <stdlib.h>

void menu(void);

int main(void)
{
    int loop;
    char opcion;
    Lista *l1,*l2,*res;
    l1 = crearLsita();
    l2 = crearLsita();
    res = crearLsita();
    listaAgregar(l1,"a");
    listaAgregar(l1,"b");
    //listaAgregar(l1,"c");
    listaAgregar(l2,"d");
    listaAgregar(l2,"e");
    //listaAgregar(l2,"f");
    do{
           menu();
           opcion = getch();
           switch( opcion )
           {
               case '1':
                    printf("Union Lenguajes\n");
                    res = unir(l1,l2);
                    listaVer(res);
                    //free(res);
               break;
           case '2':
               printf("Concatenacion Lenguajes\n");
               res = concatenar(l1,l2);
               listaVer(res);
               //free(res);
           break;

           default:
                  printf("OPCION NO VALIDA");
           }
           printf("1.Volver al menu\n2.Salir\n");
           scanf("%d",&loop);
           system("CLS");
           system("PAUSE");
    }while(loop == 1);
    return 0;
}

void menu(void)
{
    system("CLS");
    printf("\nOperaciones\n");
    printf("1.Unir\n");
    printf("2.Concatenar\n");
    printf("3.Potencia\n");
    printf("4.Cerradura positiva\n");
    printf("5.Cerradura estrella\n");
    printf("6.Reflexion\n");
}
