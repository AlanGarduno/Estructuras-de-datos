#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

/* Estructuras y tipos */
typedef struct _nodo {
   int dato;
   struct _nodo *derecho;
   struct _nodo *izquierdo;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Arbol;

/* Insertar en árbol ordenado: */
void Insertar(Arbol *a, int dat);
/* Función de búsqueda: */
int Buscar(Arbol a, int dat);
/* Comprobar si el árbol está vacío: */
int Vacio(Arbol r);
/* Comprobar si es un nodo hoja: */
int EsHoja(pNodo r);
/* Contar número de nodos: */
int NumeroNodos(Arbol a, int* c);
/* Calcular la altura de un árbol: */
int AlturaArbol(Arbol a, int* altura);
/* Calcula la suma de los valores de los nodos*/
int sumacont(Arbol a, int* sum);
/* Calcular altura de un dato: */
int Altura(Arbol a, int dat);
/* Aplicar una función a cada elemento del árbol: */
void InOrden(Arbol, void (*func)(int*));
void PreOrden(Arbol, void (*func)(int*));
void PostOrden(Arbol, void (*func)(int*));

/* Funciones auxiliares: */
void eliminar(Arbol *a);
void auxContador(Arbol a, int*);
void auxAltura(Arbol a, int, int*);

void Mostrar(int *d);

/* Programa de ejemplo */
int main()
{
   Arbol ArbolInt=NULL;
   int altura;
   int nnodos;
   
   printf("El conjunto de datos son: \n10, 5, 12, 4, 7, 3, 6, 9, 8, 11, 14, 13, 2, 1, 15, 10, 17, 18, 16 \n\n");	
    
   /* Inserción de nodos en árbol: */
   Insertar(&ArbolInt, 10);
   Insertar(&ArbolInt, 5);
   Insertar(&ArbolInt, 12);
   Insertar(&ArbolInt, 4);
   Insertar(&ArbolInt, 7);
   Insertar(&ArbolInt, 3);
   Insertar(&ArbolInt, 6);
   Insertar(&ArbolInt, 9);
   Insertar(&ArbolInt, 8);
   Insertar(&ArbolInt, 11);
   Insertar(&ArbolInt, 14);
   Insertar(&ArbolInt, 13);
   Insertar(&ArbolInt, 2);
   Insertar(&ArbolInt, 1);
   Insertar(&ArbolInt, 15);
   Insertar(&ArbolInt, 10);
   Insertar(&ArbolInt, 17);
   Insertar(&ArbolInt, 18);
   Insertar(&ArbolInt, 16);

   /* Mostrar el árbol en tres ordenes distintos: */
   printf("InOrden: ");
   InOrden(ArbolInt, Mostrar);
   printf("\n");
   printf("PreOrden: ");
   PreOrden(ArbolInt, Mostrar);
   printf("\n");
   printf("PostOrden: ");
   PostOrden(ArbolInt, Mostrar);
   printf("\n\n");

   /* Veamos algunos parámetros */
   printf("N nodos: %d\n\n", NumeroNodos(ArbolInt, &nnodos));
   printf("La Altura de arbol es %d\n\n", AlturaArbol(ArbolInt, &altura));
   
   /* Liberar memoria asociada al árbol: */
   eliminar(&ArbolInt);
   system("PAUSE");{}
   return 0;
}



/* Poda: borrar todos los nodos a partir de uno, incluido */
void eliminar(Arbol *a)
{
   /* Algoritmo recursivo, recorrido en postorden */
   if(*a) {
      eliminar(&(*a)->izquierdo); /* Podar izquierdo */
      eliminar(&(*a)->derecho);   /* Podar derecho */
      free(*a);                /* Eliminar nodo */
      *a = NULL;
   }
}

/* Insertar un dato en el árbol ABB */
void Insertar(Arbol *a, int dat)
{
   pNodo padre = NULL;
   pNodo actual = *a;

   /* Buscar el dato en el árbol, manteniendo un puntero al nodo padre */
   while(!Vacio(actual) && dat != actual->dato) {
      padre = actual;
      if(dat < actual->dato) actual = actual->izquierdo;
      else if(dat > actual->dato) actual = actual->derecho;
   }

   /* Si se ha encontrado el elemento, regresar sin insertar */
   if(!Vacio(actual)) return;
   /* Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será
      el nodo raiz */
   if(Vacio(padre)) {
      *a = (Arbol)malloc(sizeof(tipoNodo));
      (*a)->dato = dat;
      (*a)->izquierdo = (*a)->derecho = NULL;
   }
   /* Si el dato es menor que el que contiene el nodo padre, lo insertamos
      en la rama izquierda */
   else if(dat < padre->dato) {
      actual = (Arbol)malloc(sizeof(tipoNodo));
      padre->izquierdo = actual;
      actual->dato = dat;
      actual->izquierdo = actual->derecho = NULL;
   }
   /* Si el dato es mayor que el que contiene el nodo padre, lo insertamos
      en la rama derecha */
   else if(dat > padre->dato) {
      actual = (Arbol)malloc(sizeof(tipoNodo));
      padre->derecho = actual;
      actual->dato = dat;
      actual->izquierdo = actual->derecho = NULL;
  }
}

/* Recorridos */
void InOrden(Arbol a, void (*func)(int*))
{
   if(a->izquierdo) InOrden(a->izquierdo, func);
   func(&(a->dato));
   if(a->derecho) InOrden(a->derecho, func);
}

void PreOrden(Arbol a, void (*func)(int*))
{
   func(&a->dato);
   if(a->izquierdo) PreOrden(a->izquierdo, func);
   if(a->derecho) PreOrden(a->derecho, func);
}

void PostOrden(Arbol a, void (*func)(int*))
{
   if(a->izquierdo) PostOrden(a->izquierdo, func);
   if(a->derecho) PostOrden(a->derecho, func);
   func(&a->dato);
}



/* Buscar un valor en el árbol */
int Buscar(Arbol a, int dat)
{
   pNodo actual = a;

   /* Todavía puede aparecer, ya que quedan nodos por mirar */
   while(!Vacio(actual)) {
      if(dat == actual->dato) return TRUE; /* dato encontrado */
      else if(dat < actual->dato) actual = actual->izquierdo; /* Seguir */
      else if(dat > actual->dato) actual = actual->derecho;
   }
   return FALSE; /* No está en árbol */
}

/* Calcular la altura del nodo que contiene el dato dat */
int Altura(Arbol a, int dat)
{
   int altura = 0;
   pNodo actual = a;

   /* Todavía puede aparecer, ya que quedan nodos por mirar */
   while(!Vacio(actual)) {
      if(dat == actual->dato) return altura; /* encontrado: devolver altura */
      else {
         altura++; /* Incrementamos la altura, seguimos buscando */
         if(dat < actual->dato) actual = actual->izquierdo;
         else if(dat > actual->dato) actual = actual->derecho;
      }
   }
   return -1; /* No está en árbol, devolver -1 */
}

/* Contar el número de nodos */
int NumeroNodos(Arbol a, int *contador)
{
   *contador = 0;

   auxContador(a, contador); /* Función auxiliar */
   return *contador;
}

/* Función auxiliar para contar nodos*/
void auxContador(Arbol nodo, int *c)
{
   (*c)++; /* Otro nodo */
   /* Continuar recorrido */
   if(nodo->izquierdo) auxContador(nodo->izquierdo, c);
   if(nodo->derecho)   auxContador(nodo->derecho, c);
}

/* Calcular la altura del árbol, que es la altura del nodo de mayor altura. */
int AlturaArbol(Arbol a, int *altura)
{
   *altura = 0;

   auxAltura(a, 0, altura); /* Función auxiliar */
   return *altura;
}

/* Función auxiliar para calcular altura*/
void auxAltura(pNodo nodo, int a, int *altura)
{
   /* Recorrido postorden */
   if(nodo->izquierdo) auxAltura(nodo->izquierdo, a+1, altura);
   if(nodo->derecho)   auxAltura(nodo->derecho, a+1, altura);
   /* Proceso, si es un nodo hoja, y su altura es mayor que la actual del árbol, actualizamos la altura actual del árbol */
   if(EsHoja(nodo) && a > *altura) *altura = a;
}

/* Comprobar si un árbol es vacío */
int Vacio(Arbol r)
{
   return r==NULL;
}

/* Comprobar si un nodo es hoja */
int EsHoja(pNodo r)
{
   return !r->derecho && !r->izquierdo;
}

/* Función de prueba para recorridos del árbol */
void Mostrar(int *d)
{
   printf("%d, ", *d);
}

