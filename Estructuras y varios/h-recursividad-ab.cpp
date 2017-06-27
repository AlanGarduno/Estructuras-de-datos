#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

long pot(int a, int b);
int main()
{
	int a, b, res, opc;
	do
	{
		res=0;
		system("cls");
		printf("\nh) Programa que dado dos numeros a y b determinar recursivamente a elevado a la b");
		printf("\n\nIngrese el valor de a:");
		scanf("%d", &a);
		printf("\n\nIngrese el valor de b:");
		scanf("%d", &b);
		if (b>=0)
		{
		res= pot(a,b);
		} else	printf("\n Dato erroneo");
	
		printf("\n%d\n", res);
		printf("\n\n");
		system("pause");
		system("cls");
		printf("\nDesea Realizar Nuevamente La Ejecucion: \n\nsi=1 \nno=2\n\n");
		scanf("%d", &opc);
	} while (opc==1);	
	return 0;
}


long pot(int a, int b){
	if (b==0){
		return(1);
	}else
	{
		return(a*pot(a,b-1));
	}
}
