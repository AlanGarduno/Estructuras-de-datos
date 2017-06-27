#include <stdio.h> 
#include <stdlib.h>
#include <iostream>

 int main(int argc, char** argv) {
    
	int ABB[30]={'-'}; 
	int i, x, y;
	int opc;
	int ref=1;
	do
	{
		system("cls");
		system("color f9");
		printf("\t Arboles binarios casi completos, utilizando arreglos \n");
		printf("Ingresa el valor que tengra la raiz:  \n");
		scanf("%d", &ABB[ref]);
		while(x!=2)
			{ 
				system("cls");
				printf("\n Deseas ingresar algun otro valor (hijo)? 1. SI 2.- NO \n ");
				scanf("%d",&x); 
				if(x==1)
					{ 
						system("cls");
						printf("\n De que nivel quieres que sea el hijo: \n"); 
						scanf("%d",&ref);
						printf(" \n En que posicion deseas colocarlo: \n\n1.- Izquierda 2.- Derecha 3.- Izquierda & Derecha \n "); 
						scanf("%d",&y); 
						if(y==1)
							{ 
								system("cls");
								printf("\nIngresa el valor del hijo del lado izquierdo: \n");
								fflush(stdin);//Limpia el buffer
								scanf("%d", &ABB[2*ref]); 
							} 
							else if (y==2)
							{ 
								system("cls");
								printf("\nIngresa el valor del hijo del lado derecho:\n"); 
								fflush(stdin); //Limpia el buffer
								scanf("%d", &ABB[2*ref+1]); 
							} 
							else
								{ 
									system("cls");
								 	printf("\n Ingresa el valor del hijo del lado izquierdo:\n");
									fflush(stdin); 
									scanf("%d", &ABB[2*ref]);
									printf("\n Ingresa el valor del hijo del lado derecho\n");              
									fflush(stdin);//Limpia el buffer
									scanf("%d", &ABB[2*ref+1]); 
								} 
					} 
			} 
				printf("Los valores que contiene el arbol son: \n"); 
				for(i=1;i<=25;i++)
				{ 
				printf("%d ",ABB[i]);
				}
			system("pause");
			system("cls");
			printf("Desea relaizar nuevamente la ejecucion: \nSI=1 \nNO=2 \n");
			scanf("%d", &opc);
			}while (opc==1);	
			return 0; 
}
