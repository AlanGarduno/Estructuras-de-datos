#include <stdlib.h>
#include <stdio.h>
#include "Lista.h"

Nodo *crearNodo(char *cad)
{
    Nodo *aux =(Nodo*)malloc(sizeof(Nodo));
    nodo->cadena = cad;
    aux->siguiente = NULL;
    return aux;
}

void detruirNodo(Nodo * nodo)
{
    free(nodo);
}

void lista_Agregar(Lista *lista, char *cad)
{
    Nodo *nodo=crearNodo(cad);
    if(lista->inicio == NULL)
    {
        lista->inicio = nodo;
    }
    else
    {
        Nodo *puntero = lista->incio;
        while(puntero->siguiente)
        {
            puntero = puntero->siguiente;
        }
        puntero->siguiente = nodo;
    }
    lista->longitud++;
}

Lista *lista_crear()
{
    Lista *axu;
    axu->inicio = NULL;
    aux->lonitud = 0;
    return aux;
}