#include <stdio.h>

int factorial(int x);
int factorialCiclo(int x);

int main( )
{
	int x;
	printf("Ingresa un numero\n");
	scanf("%d",&x);
	printf("%d\n",factorial(x));
	printf("Factorial Ciclo\n");
	printf("%d\n",factorialCiclo(x));	
	return 0;
}


int factorial(int x)
{

	if(x == 1)
		return x;
	return x*factorial(x-1);
}

int factorialCiclo(int x)
{
	int i,aux = 1;
	for (i = x; i>x;x--)
	{
		aux *= x;
	}
	return aux;
}
