#include <iostream>
#include <stdlib.h>

typedef struct node{
     int numero;
     struct node *izq, *der;
}*ABB;

int numNodos = 0; // nummero de nodos del arbol binario de busqueda

//Necesitamos la ocupacion de una cola, para el manejo de los valores del arbol
struct nodeCola{
    ABB ptr;
    struct nodeCola *siguiente;
};

struct cola{
    struct nodeCola *delante;
    struct nodeCola *atras;
};

void inicializaCola(struct cola &q)
{
    q.delante = NULL;
    q.atras = NULL;
}
//agrega un valor a la cola
void encola(struct cola &q, ABB n)
{
     struct nodeCola *p;
     p = new(struct nodeCola);
     p->ptr = n;
     p->siguiente = NULL;
     if(q.delante==NULL)
         q.delante = p;
     else
         (q.atras)->siguiente = p;
     q.atras = p;
}

//elimina un valor a la cola
ABB desencola(struct cola &q)
{
    struct nodeCola *p;
    p = q.delante;
    ABB n = p->ptr;
    q.delante = (q.delante)->siguiente;
    delete(p);
    return n;
}

//Crear un nuevo nodo
ABB crearNode(int x)
{
     ABB newNode = new(struct node);
     newNode->numero = x;
     newNode->izq = NULL;
     newNode->der = NULL;
     return newNode;
}

//Esta funcion ayudara a insertar los datos a nuestro arbol binario
void insertar(ABB &arbol, int x)
{
     if(arbol==NULL)
     {
           arbol = crearNode(x);
           printf("\n\t  Insertado..!\n\n");
     }
     else 
	 	if(x < arbol->numero)
          insertar(arbol->izq, x);
     else if(x > arbol->numero)
          insertar(arbol->der, x);
}

//Estas funciones nos dara el recorrido del arbol ya sea en preorden, inorden, postorden
void preOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          printf(" %d ", arbol->numero);
          preOrden(arbol->izq);
          preOrden(arbol->der);
     }
}

void inOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          inOrden(arbol->izq);
          printf(" %d ", arbol->numero);
          inOrden(arbol->der);
     }
}

void postOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          postOrden(arbol->izq);
          postOrden(arbol->der);
          printf(" %d ", arbol->numero);
     }
}

//Esta funcion permite ver como se esta formando el arbol binario
void verArbol(ABB arbol, int n)
{
     if(arbol==NULL)
          return;
     verArbol(arbol->der, n+1);

     for(int i=0; i<n; i++)
         printf("   ");

     numNodos++;
     printf("%d \n\n ", arbol->numero);

     verArbol(arbol->izq, n+1);
}

//Esta funcion permite realizar una busqueda dentro del arbol binario
bool busquedaRec(ABB arbol, int dato)
{
     int busq=0;   // 0 indica que lo encontre

     if(arbol==NULL)
        return busq;

     if(dato<arbol->numero)
         busq = busquedaRec(arbol->izq, dato);

     else if(dato> arbol->numero)
         busq = busquedaRec(arbol->der, dato);

     else
        busq = 1;   // son iguales, lo encontre

     return busq;
}

//Funcion auxiliar para unir nodos 
ABB unirABB(ABB izq, ABB der)
{
    if(izq==NULL) return der;
    if(der==NULL) return izq;

    ABB centro = unirABB(izq->der, der->izq);
    izq->der = centro;
    der->izq = izq;
    return der;
}

//Funcion para eliminar nodos y realizar un recorrido
void elimina(ABB &arbol, int x)
{
     if(arbol==NULL) return;

     if(x<arbol->numero)
         elimina(arbol->izq, x);
     else if(x>arbol->numero)
         elimina(arbol->der, x);

     else
     {
         ABB p = arbol;
         arbol = unirABB(arbol->izq, arbol->der);
         delete p;
     }
}

int main()
{
    ABB arbol = NULL;
    int x;
    int op, op2;
    system("color f9");
    do
    {
          system("cls");
		  printf("\n\t\t  .::TAD ARBOL BINARIO DE MANERA DINAMICA::.   \n\n");
		  printf("\t [1]  Insertar elemento                  \n");
		  printf("\t [2]  Mostrar arbol                      \n");
		  printf("\t [3]  Recorridos                         \n");
		  printf("\t [4]  Buscar elemento                    \n");
		  printf("\t [5]  Eliminar elemento                  \n");
		  printf("\t [12]  SALIR                              \n");
		  printf("\n\t Ingrese opcion : "); 
		  scanf("%d", &op);
          printf("\n");

          switch(op)
          {
               case 1:
                    printf(" Ingrese valor : ");
					scanf("%d", &x);
                    insertar( arbol, x);
                    break;

               case 2:
                    verArbol(arbol, 0);
                    break;

               case 3:
                    system("cls");   
     				printf("\n");
     				printf("\t [1] En Orden     \n");
     				printf("\t [2] Pre Orden    \n");
     				printf("\t [3] Post Orden   \n");
     				printf("\n\t     Opcion :  ");
					scanf("%d", &op2);

                    if(arbol!=NULL)
                    {
                         switch(op2)
                         {
                             case 1:
                                 inOrden(arbol); 
								 break;
                             case 2:
                                 preOrden(arbol); 
								 break;
                             case 3:
                                 postOrden(arbol); 
								 break;
                         }
                    }
                    else
                        printf("\n\t Arbol vacio..!");
                    break;

               case 4:
                    bool band;

                    printf(" Valor a buscar: ");
					scanf("%d", &x);
					band = busquedaRec(arbol,x);
                    if(band==1)
                       printf("\n\tEncontrado...");
                    else
                       printf("\n\tNo encontrado...");
                    break;

               case 5:
                    printf(" Valor a eliminar: "); 
					scanf("%d", &x);
                    elimina(arbol, x);
                    printf("\n\tEliminado..!");
                    break;

               case 12:
                    exit(0);
          }

          printf("\n\n\n");
          system("pause"); 
    }while(op!=11);
}

