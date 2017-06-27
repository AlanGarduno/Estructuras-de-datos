#ifndef ArbolAVL_H

#define ArbolAVL_H

#include <stdlib.h>
typedef struct AVL
{
	int dato,FB;
	struct AVL *izq, *der;
	bool borrado;
}AVL;

void rotarLL(AVL* &A);
void rotarRR(AVL* &A);
void rotarLRalter(AVL* &A);
void rotarRLalter(AVL* &A);
AVL* crear();
void insert(int n, bool &aumento, AVL* &A);
void insertar(AVL* &A, int n);
bool vacio(AVL *A);
bool pertenece(AVL *A, int n);
void borrar(AVL* &A, int n);

#endif