#ifndef LISTA_H
#define LISTA_H

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


#endif // LISTA_H
