#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
typedef struct Nodo{
    char dato;
    struct Nodo* sig;
    
}Nodo;
typedef struct Pila{
    Nodo *tope;
    int largo;
}Pila;
Nodo* crear_nodo(char c);
void destruir_nodo(Nodo*nodo);
Pila* crear_pila();
void destruir_pila(Pila*pila);
void push(Pila*pila,char c);
void pop(Pila*p);
char tope(Pila*p);
int esta_vacia(Pila*p);
void print(Pila*pila);
int main(int argc, char const *argv[])
{
	int i=0;
	Pila*miPila = crear_pila();
	 char* s = (char *)malloc(10240 * sizeof(char));
    scanf("%s",s);
	push(miPila,s[i]);
	print(miPila);
	return 0;
}
Nodo* crear_nodo(char c){
    Nodo*aux = (Nodo*)malloc(sizeof(Nodo));
    aux->dato = c;
    aux->sig = NULL;
    return aux;
    
}
void destruir_nodo(Nodo*nodo){
    nodo->sig = NULL;
    free(nodo);
}
Pila* crear_pila(){
    Pila* aux=(Pila*)malloc(sizeof(Pila));
    aux->tope = NULL;
    aux->largo = 0;
    return aux;
}
void destruir_pila(Pila*pila){
    while(!esta_vacia(pila)){
        pop(pila);
    }
    free(pila);
}
void push(Pila*pila,char c){
    Nodo* aux = crear_nodo(c);
    aux->sig = pila->tope;
    pila->tope = aux;
}
void pop(Pila*p){
    if(p->largo > 0)
    {
    Nodo* eliminar = p->tope;
    p->tope = p->tope->sig;
    destruir_nodo(eliminar);
    }
    else
    {
        return;
    }
}
char tope(Pila*p){
    return p->tope->dato;
}
int esta_vacia(Pila*p){
     if(p->largo == 0)
         return 1;
    else
        return 0;
}

void print(Pila*pila)
{

	while(pila->tope != NULL)
	{
		printf("%c",pila->tope->dato);
		pila->tope = pila->tope->sig;
	}

}