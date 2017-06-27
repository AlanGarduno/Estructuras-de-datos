#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo
{
    char cadena[50];
    struct Nodo *siguinete;
}Nodo;

typedef struct Lista
{
    Nodo *cabeza;
    int tam;
}Lista;

void insertar(Lista *lis, char cadena[]);
//Nodo * crear_nodo(char cadena[]);
int longitud(Lista *lis);
void mostrar(Lista *lis);

int main()
{
    Lista *l1,*l2;
    char cadena[50];
    int res;
    do
    {
        printf("Ingresa la cadena a insetar\n");
        scanf("%s",cadena);
        insertar(l1,cadena);
        printf("Ingresar otro carcter\n1.Si\n2:salir");
        scanf("%d",&res);
        system("CLS");
        system("PAUSE");
    }while(res == 1);
    mostrar(l1);
    system(EXIT_SUCCESS);

}

/*Nodo * crear_nodo(char cadena[])
{
    Nodo * temp =(Nodo*)malloc(sizeof(Nodo));
    strncpy(temp->cadena,cadena,50);
    temp->siguinete=NULL;
    return temp;

}*/
void insertar(Lista *lis,char cadena[])
{
    Nodo * temp = (Nodo*)malloc(sizeof(Nodo));
    strncpy(temp->cadena,cadena,50);
    temp->siguinete=NULL;
    if(lis->cabeza == NULL)
    {
        lis->cabeza=temp;
    }
    else
    {

        Nodo *puntero = lis->cabeza;
        while (puntero != NULL)
        {
            puntero = puntero->siguinete;
        }
        puntero->siguinete = temp;
    }
    lis->tam++;

}

int longitud(Lista *lis)
{
    return lis->tam;
}

void mostrar(Lista *lis)
{
    Nodo *aux;
    if(longitud(lis) == 0)
        printf("El lenguaje esta vacio");

    aux=lis->cabeza;
    while(aux != NULL)
    {
        printf("%s\t",aux->cadena);
        aux=aux->siguinete;
    }
}