#ifndef COLA_H
#define COLA_H

#include<stdio.h>

typedef struct Nodo
{
    int dato;
    struct Nodo* siguiente;

}Nodo;

typedef struct Cola
{
    Nodo *frente;
    Nodo *tras;
}Cola;

void encolar(int dato, Cola *c);
int desencolar(Cola *c);
int frente(Cola *c);
void print(Cola *c);
void crearCola(Cola *c);


#endif // COLA_H
