#ifndef LENGUAJES_H
#define LENGUAJES_H
#include "lista.h"

void introducir_Lenguaje(Lista *l);
int existe(char *a,char *b);
Lista *unir(Lista* l, Lista*l2);
Lista *concatenar(Lista *l1, Lista* l2);

#endif // LENGUAJES_H
