#include <stdio.h>
#include <stdlib.h>

int Com(int n, int k);
int com1(int n, int k);
int com2(int n,int k);
int Factorial(int n);

int main()
{
    int n, k, opc;
    do
    {
        system("cls");
        printf("\n Introduce el valor de n: ");
        scanf("%d", &n);
        printf("\n Introduce el valor de k: ");
        scanf("%d", &k);

        if (n>=1)
        {
            if(k>=1)
            {
                Com(n,k);
            }else printf("\nDebe ser numeros arriba de 1.");
        }else printf("\nDebe ser numeros arriba de 1.");
        printf("\nHay %d combinaciones de %d elementos tomados de %d en %d \n", Com(n,k), n, k, k);
        system("pause");
        system("cls");
        printf("¿Desea repetir el ciclo?\nsi = 1\nno = 2\n");
        scanf("%d", &opc);
    }
    while(opc==1);
    return 0;
}
int Com(int n, int k)
{
    if (k==0 && k==n)
        return 1;
    if (k>n)
        return 0;
    int a, b;
    a= com1(n,k);
    b= com2(n,k);
    return(a+b);
}

int Factorial(int n)
{
    int i, fact=1;
    for(i=2; i<=n; i++)
        fact=fact*i;
    return fact;
}

int com2(int n,int k)
{
    return (Factorial(n-1)/(Factorial(k-1)*Factorial(n-k)));
}

int com1(int n, int k)
{
    return (Factorial(n-1)/(Factorial(n-k-1)*Factorial(k)));
}
