#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

void swap(int v[],int a,int b)
{
     int temp = v[a];
    v[a] = v[b];
    v[b] = temp;

}

int pivotar(int v[], int izq, int der)
{
    int posPivote=(izq+der)/2;
    int valPivote=v[posPivote];
    int A;
    swap(v,posPivote,der);
    A=izq;
    for(int L=izq; L<der;L++)
        {
            if(v[L]<=valPivote)
            {
                swap(v,L,A);
                A++;
            }
        }
        swap(v,A,der);
        return A;
}

void quicksort(int v[], int izq, int der)
{
    int pivote;
    if(izq<der)
    {
        pivote=pivotar(v,izq,der);
        quicksort(v,izq,pivote-1);
        quicksort(v,pivote+1,der);
    }
}

main()
{
	int i, opc, ar[5];
	do
	{
	system("cls");
	printf("Programa que ordene un conjunto de numeros utilizando el metodo Quicksort, metodo estatico\n");
	printf("\n");
	for(i=0;i<5;i++)
	{
		printf("\nIngrese el dato %d:\t",i);
		scanf("%d",&ar[i]);
	}
	system("cls");
	printf("\tEsta es el arreglo en el orden en que se ingresaron los datos\n");

	for(i=0;i<5;i++)
	{
		printf("a[%d]= %d\n",i,ar[i]);

	}
	quicksort(ar, 0, 4);
	printf("\n\n\n\n");
		printf("\t\tEsta es el arreglo orden ascendente\n");

	for(i=0;i<5;i++)
	{
		printf("a[%d]= %d\n",i,ar[i]);

	}
	system ("pause");
	system ("cls");
	printf("Desea relaizar nuevamente la ejecucion: \nSI=1 \nNO=2 \n");
	scanf("%d", &opc);
	}while (opc==1);
	return 0;
}
