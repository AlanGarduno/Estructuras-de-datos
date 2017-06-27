#include <stdlib.h>
#include <stdio.h>

int main()
{
    int items[20]={'-'};
    int res,op,pos = 1,i=0,re;
    printf("Arboles Binarios Casi Completo de enteros\n");
    printf("Ingresa el nodo padre\n");
    scanf("%d",&items[pos]);
    while(re != 2)
    {
        printf("Quieres insetar un hijo?\n1.Si\n2.No\n");
        scanf("%d",&re);
        if(re == 1)
        {
            printf("Ingresa el nodo donde deseas insertalo\n");
            scanf("%d",&pos);
            printf("1-Insetar a la derecha 2-Insertar a la izquierda\n");
            scanf("%d",&op);
            if(op == 1)
            {
                printf("Ingresa el hijo derecho\n");
                fflush(stdin);
                scanf("%d",&items[2* pos + 1]);
            }
            else if( op == 2)
            {
                printf("Ingresa el hijo iquierdo\n");
                fflush(stdin);
                scanf("%d",&items[2 *pos]);
            }
        }


    }
    printf("Los elementos del Arbol son\n");
    for(i;i<=20;i++)
    {
        printf("%d\t",items[i]);
    }
    system("pause");
    return  0;
}