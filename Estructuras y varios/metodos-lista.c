#include <stdlib.h>
#include <stdio.h>

typedef struct Cancion {
  int    pista;
  char   nombre;
  struct Cancion *siguiente;
}Cancion;

typedef struct ListaIdentificar {
  Cancion *inicio;
  Cancion *fin;
  int numcanciones;
}Listac;

void Generalista (Listac *listac){
  lista->inicio = NULL;
  lista->fin = NULL;
  numcanciones = 0;
}

int Crea_lista_nueva (Listac * listac, char *nombre){
  Cancion *nueva_cancion;
  if ((nueva_cancion = (Cancion *) malloc (sizeof (Cancion))) == NULL)
    return -1;
  if ((nueva _cancion->nombre = (char *) malloc (50 * sizeof (char)))
      == NULL)
    return -1;
  strcpy (nueva_cancion->nombre, nombre);
  nueva_cancion->pista=1;

  nuevo_elemento->siguiente = NULL;
  listac->inicio = nueva_cancion;
  listac->fin = nueva_cancion;
  listac->numcanciones++;
  return 0;
}
int ins_cancion (Listac * listac, Cancion * actual, char *nombre){
  Cancion *nueva_cancion;
  if ((nueva_cancion = (Cancion *) malloc (sizeof (Cancion))) == NULL)
    return -1;
  if ((nueva_cancion->nombre = (char *) malloc (50 * sizeof (char)))
      == NULL)
    return -1;
  strcpy (nueva_cancion->nombre, nombre);
  nueva_cancion->pista=listac->numcanciones++;

  actual->siguiente = nueva_cancion;
  nueva_cancion->siguiente = NULL;

  listac->fin = nueva_cancion;

  listac->numcanciones++;
  return 0;
}

void imprimeLista (Listac * listac){
  Cancion *actual;
  actual = listac->inicio;
  while (actual != NULL){
      printf("%d",actual->pista); 
      printf ("%p - %s\n", actual, actual->nombre);
      actual = actual->siguiente;
  }
}