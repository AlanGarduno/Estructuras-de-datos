#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define TAM 10

typedef struct {
	int datos[TAM];
	int inicio;
	int final;
}Cola;

int eliminar(Cola *ccola);
int insertar (Cola *ccola, int dato);
int vacia(Cola ccola);
int llena(Cola ccola);

void CrearCola(Cola *ccola)
{
	ccola->inicio=0;
	ccola->final=-1;
}


int eliminar(Cola *ccola)
{
	int aux;
	if(vacia(*ccola)==0)
	{
		aux=ccola->datos[ccola->inicio];
		ccola->datos[ccola->inicio]=0;
		ccola->inicio++;
		return aux;
	}
	return 0;
}

int insertar (Cola *ccola, int dato)
{
	if(llena(*ccola)==0)
	{
	ccola->final++;
	ccola->datos[ccola->final]=dato;
	return 1;
    }
    return 0;
}

int vacia(Cola ccola)
{
	if(ccola.final<ccola.inicio)
	return 1;
	return 0;
}

int llena(Cola ccola)
{
	if(ccola.final==TAM-1)
	return 1;
	return 0;
}
