#ifndef LISTAC_LISTA_H
#define LISTAC_LISTA_H

typedef struct Nodo
{
    char *cadena;
    struct Nodo siguiente;
}Nodo;

typedef struct Lista
{
    Nodo *inicio;
    int longitud;
};

Nodo *crearNodo();
void detruirNodo(Nodo * nodo);
void lista_Agregar(Lista *lista, char *cad);

#endif //LISTAC_LISTA_H
