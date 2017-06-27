#include <stdlib.h>
#include <stdio.h>

int potencia(int x, int n);

int main()
{
    int x,y,res;
    printf("Potencia\n");
    printf("Ingresa la base\n");
    scanf("%d",&x);
    while(x<=0)
    {
        printf("La base no pude ser 0, por favor ingresa otro numero \n");
        scanf("%d",&x);
        if(x > 0)
            break;
    }
    printf("Ingresa la potencia\n");
    scanf("%d",&y);
    res = potencia(x,y);
    printf("El resultado es  %d \n",res);
    system("pause");
    return 0;
}

int potencia(int x, int n)
{
    if(n == 1)
        return x;

    else if (n % 2 == 0)
        return potencia(x*x, n/2);

    else
        return x * potencia(x, n-1);
}