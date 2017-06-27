#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

typedef struct Nodo
{
    char cadena[50];
    struct Nodo * siguiente;
}Nodo;

typedef struct Lista
{
    Nodo *cabeza;
    int tam;
};

void menu(void);
void ingresar_elemento(Lista *lis);
void mostrar_lenguaje();
int tam(Lista *lis);
void ingresar_lenguajes();

Nodo *primero,*ultimo;
int main(void)
{
    char opcion;
    primero =(Nodo*)NULL;
    ultimo=(Nodo*)NULL;
    ingresar_lenguajes();
    do
    {
        menu();
        opcion = getch();
        switch (opcion)
        {
            case '1':
                break;
        }
    }while(opcion != '4');

}


void menu(void)
{
    printf("1.Unir lenuajes\n");

}

void ingresar_elemento(Lista *lis)
{
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    if(nuevo == NULL)
        printf("ERROR DE MEMORIA");

    printf("Cadena: ");
    fflush(stdout);
    gets(nuevo->cadena);
    nuevo->siguiente=NULL;
    if(primero == NULL)
    {
        printf( "Primer elemento\n");
        primero = nuevo;
        ultimo = nuevo;
        lis->cabeza=nuevo;
    }
    else
    {
        ultimo->siguiente = nuevo;
        ultimo = nuevo;
    }
    lis->tam++;

}

int tam(Lista *lis)
{
    return  lis->tam;
}

void ingresar_lenguajes()
{
    int re,res;
    Lista *l1,*l2;
    printf("Ingresa el primer lenguaje\n");
    do
    {
        printf("Ingresa una cadena perteneciaente al lenguaje 1\n");
        ingresar_elemento(l1);
        printf("Deseas ingresar otra cadena\n1.Si\n2.No");
        scanf("%d",&res);
    }while(res == 1);

    printf("Ingresa el segundo lenguaje\n");

    do
    {
        printf("Ingresa una cadena perteneciaente al lenguaje 1\n");
        ingresar_elemento(l2);
        printf("Deseas ingresar otra cadena\n1.Si\n2.No");
        scanf("%d",&re);

    }while(re == 1);
}

void mostrar_lenguaje(Lista *lis)
{
    Nodo *aux;
    int i=0;
    aux=lis->cabeza;
    printf("Lenguaje completo\n");
    while(aux != NULL)
    {
        printf("%s",aux->cadena);
        aux = aux->siguiente;
        i++;
    }
    if(i==0)
        printf("El lenguaje esta vacio");
}