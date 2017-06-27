#include <stdio.h>
#include <stdlib.h>

void suma(int a[], int b[]); // funcion que recibe 2 arreglos comp parametros
void mult(int escalar, int a []); // un entero y un arreglo

int main()
{
    int i,j,res;
    int vec1[2],vec2[2];
    printf("Que deseas hacer\n1.Suma de 2 vectores\n2.Multiplicaion de un vector por escalar\n");
    scanf("%d",&res);
    switch (res)
    {
        case 1:
            printf("ingresa el primer vector\n");
            for(i=0;i<=2;i++)
            {
                printf("Ingrese el componenete\n");
                scanf("%d",&vec1[i]);
            }
            printf("Ingrese el segundo vector");
            for(j=0;j<=2;j++)
            {
                printf("Ingrese el componenete\n");
                scanf("%d",&vec2[i]);
            }

            suma(vec1,vec2);

            break;
        case 2:
            int escalar;
            printf("Ingrese el escalar\n");
            scanf("%d",&escalar);
            printf("Ingresa el vector\n");
            for(i=0;i<=2;i++)
            {
                printf("Ingrese el componenete\n");
                scanf("%d",&vec1[i]);
            }

             mult(escalar,vec1);
            break;
        default:
            printf("Opcion inexistente");
    }


}

void suma(int a[], int b[] )
{
    int aux[2];
    aux[0]=a[0] + b[0];
    aux[1]=a[1] + b[1];
    aux[2]=a[2] + b[2];
    printf("El resultado es: %di + %dj + %dk",aux[0],aux[1],aux[2]);

}

void mult(int escalar, int a[])
{
    int aux[2];
    aux[0]=a[0] * escalar;
    aux[1]=a[1] * escalar;
    aux[2]=a[2] * escalar;
    printf("El resultado es: %di + %dj + %dk",aux[0],aux[1],aux[2]);

}