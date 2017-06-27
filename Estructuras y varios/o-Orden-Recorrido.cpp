#include <stdlib.h>
#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct _nodo {
   int dato;
   struct _nodo *derecho;
   struct _nodo *izquierdo;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Arbol;

void Insertar(Arbol *a, int dat);
int Vacio(Arbol r);
void InOrden(Arbol, void (*func)(int*));
void PreOrden(Arbol, void (*func)(int*));
void PostOrden(Arbol, void (*func)(int*));
void eliminar(Arbol *a);
void Mostrar(int *d);

int main()
{
   Arbol ArbolInt=NULL;    
   int opc1, opc2;
   do
   {
	system("cls");
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
   
   printf("Los Datos ordenados son: \n"); 
   InOrden(ArbolInt, Mostrar);
   printf("\n");
   printf("\nMENU DE OPCIONES:");
   printf("\n1. Preorden\n2. inorder \n3. postorden\n\n");
   printf("Seleccione una opcion: ");
   scanf("%d", &opc1);
   
   switch(opc1)
   {
   		case 1: 
		    printf("\nInOrden: ");
   			InOrden(ArbolInt, Mostrar);
   			printf("\n");
   			break;
   		case 2:
   			printf("\nPreOrden: ");
			PreOrden(ArbolInt, Mostrar);
			printf("\n");
			break;
		case 3:
			printf("\nPostOrden: ");
   			PostOrden(ArbolInt, Mostrar);
   			printf("\n");
   			break;
   		default:
   			printf("\nOpcion mal ingresada...");
   			break;
	}
	
   /* Liberar memoria */
   eliminar(&ArbolInt);
   system("PAUSE");
   system("cls");
   printf("Desea finalizar la ejecucion: 1.No 2.Si\n");
   scanf("%d", &opc2);
	}while(opc2==1);

   return 0;
}

void eliminar(Arbol *a)
{
   /* Algoritmo recursivo, recorrido en postorden */
   if(*a) {
      eliminar(&(*a)->izquierdo); 
      eliminar(&(*a)->derecho);   
      free(*a);                
      *a = NULL;
   }
}

/* Insertar un dato en el árbol */
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
   /* Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será el nodo raiz */
   if(Vacio(padre)) {
      *a = (Arbol)malloc(sizeof(tipoNodo));
      (*a)->dato = dat;
      (*a)->izquierdo = (*a)->derecho = NULL;
   }
   /* Si el dato es menor que el que contiene el nodo padre, lo insertamos en la rama izquierda */
   else if(dat < padre->dato) {
      actual = (Arbol)malloc(sizeof(tipoNodo));
      padre->izquierdo = actual;
      actual->dato = dat;
      actual->izquierdo = actual->derecho = NULL;
   }
   /* Si el dato es mayor que el que contiene el nodo padre, lo insertamos en la rama derecha */
   else if(dat > padre->dato) {
      actual = (Arbol)malloc(sizeof(tipoNodo));
      padre->derecho = actual;
      actual->dato = dat;
      actual->izquierdo = actual->derecho = NULL;
  }
}
//RECORRIDOS
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

/* Comprobar si un árbol es vacío */
int Vacio(Arbol r)
{
   return r==NULL;
}

/* Función de prueba para recorridos del árbol */
void Mostrar(int *d)
{
   printf("%d, ", *d);
}
