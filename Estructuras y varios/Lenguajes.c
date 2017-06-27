#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Nodo
{
    char *cad;
    struct Nodo *siguiente;
}Nodo;

typedef struct Lista
{
    Nodo *inico;
    int longitud;
}Lista;

Nodo* crearNodo(char *cadena);
void destritNodo(Nodo* nodo);
Lista* crearLsita(void);
void listaAgregar(Lista* lista, char* cadena);
void listaVer(const Lista* lista);
Lista* potencia(Lista*l1,int potencia);


int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}


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
    printf("{");
    while(aux != NULL)
    {
        printf("%s",aux->cad);
        aux = aux->siguiente;
        printf(",");
    }
    printf("}\n");
    getch();
}

Lista *potencia(Lista*l1,int potencia)
{
	Nodo*aux = l1->inico;
	Nodo*aux2 = l1->inico;
	Lista *lista_aux = crearLsita();
	if(potencia == 1)
	{
		listaVer(l1);
		return;
	}
	else
	{
		while(aux->siguiente != NULL)
		{
			listaAgregar(lista_aux,strcat(l1->cad,l1->cad));
		}
	}
}