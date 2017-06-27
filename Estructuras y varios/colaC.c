#include <stdio.h>
#include <stdlib.h>
#include "colaC.h"

bool colaLlena(Cola *c)
{
	return(c->n == c->nmax);

}
bool colaVacia(Cola *c)
{
	return(c->n == 0);

}
dato desEncolar(Cola *c)
{
	dato aux;
	int i;
	if(!colaVacia(c))
	{
		i = c->frente;//primer elemento de la cola 
		aux = c->datos[i]; //Valor del primer elemento 
		i = (i+1)%(c->nmax);
		x->frente = i;
		--(x->n);
		return aux;
	}
	return NULL;
}
void encolar(Cola*c, dato y)
{
	int i;
	if(!colaLlena(c))
	{
		i = (c->frente + c->n) % (x->nmax); //Indice del dato nuevo
		x->datos[i] = y; //Guardamos el dato
		++(c->n); //aumentamos el tamaño de la cola

	}
}
void crear(Cola *c, int max)
{
	dato *aux;
	aux = (dato*)malloc(max * sizeof(dato));
	c->frente = 0;
	c->n = 0;
	c->nmax = max;
	c->datos = aux;
}
