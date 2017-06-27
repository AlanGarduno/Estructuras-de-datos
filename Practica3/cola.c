#include<stdio.h>
#include<stdlib.h>
#include "cola.h"

void encolar(int dato, Cola *c)
{
    Nodo *temp =(Nodo*)malloc(sizeof(Nodo));
    temp->dato=dato;
    temp->siguiente=NULL;
    if(c->frente == NULL && c->tras == NULL)
    {
        c->frente=c->tras=temp;
        return;
    }
    c->tras->siguiente=temp;
    c->tras=temp;
}

int desencolar(Cola *c)
{
    if(c->frente)
    {
        int y;
        y = c->frente->dato;
        Nodo *temp = c->frente;
        c->frente = c->frente->siguiente;
        free(temp);
        if(!c->frente)
        {
            c->tras = NULL;
        }
        return y;
    }
    else
        return 0;
}

int frente(Cola *c)
{
    if(c->frente == NULL)
    {
        printf("La cola esta vacia\n");
    }
    return c->frente->dato;
}

void print(Cola *c)
{
    Nodo *temp = c->frente;
    while(temp != NULL)
    {
        printf("%d\t",temp->dato);
        temp = temp->siguiente;
    }
    printf("\n");
}

void crearCola(Cola *c)
{
    c->frente = NULL;
    c->tras = NULL;
}
