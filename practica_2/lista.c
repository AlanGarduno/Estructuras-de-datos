#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "lista.h"

Nodo* crearNodo(char *cadena)
{
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->cad = cadena;
    nodo->siguiente=NULL;
    return nodo;
}

void destritNodo(Nodo* nodo)
{
    free(nodo);
}

Lista* crearLsita(void)
{
    Lista *aux;
    aux =(Lista*)malloc(sizeof(Lista));
    aux->inico=NULL;
    aux->longitud=0;
    return aux;
}

void listaAgregar(Lista* lista, char* cadena)
{
    Nodo *nodo = crearNodo(cadena);
    if(lista->inico == NULL)
    {
        lista->inico= nodo;
    }
    else
    {
        Nodo *puntero = lista->inico;
        while(puntero->siguiente)
        {
            puntero = puntero->siguiente;
        }
        puntero->siguiente=nodo;
    }
    lista->longitud++;
}

void listaVer(const Lista *lista)
{
    Nodo *aux;
    aux = lista->inico;
    printf("{\t");
    while(aux != NULL)
    {
        printf("%s\t",aux->cad);
        aux = aux->siguiente;
    }
    printf("}\n");
    getch();
}
