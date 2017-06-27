#include <stdlib.h>
#include <stdio.h>
#include "ArbolAVL.h"

void rotarLL(AVL* &A)
{
	AVL* aux = A->izq->der;
	A->izq->der = A;
	A->izq->FB = 0;
	AVL* aux2 = A->izq;
	A->izq = aux;
	A->FB = 0;
	A = aux2; 
}

void rotarRR(AVL* &A)
{
	AVL* aux = A->der->izq;
	A->der->izq = A;
	A->der->FB=0;
	AVL* aux2 = A->der;
	A->der = aux;
	A->FB = 0;
	A = aux2;
}

void rotarLRalter(AVL* &A)
{
	rotarRR(A->izq);
	rotarLL(A);
}

void rotarRLalter(AVL* &A)
{
	rotarLL(A->der);
	rotarRR(A);
}

AVL* crear()
{
	return NULL;
}

void insert(int n, bool &aumento,AVL* &A)
{
	if(A == NULL)
	{
		A = new AVL;
		A->dato = n;
		A->FB = 0;
		A->izq = NULL;
		A->der = NULL;
		aumento = true;
		A->borrado = false;
	}
	else
	{
		if(n < A->dato)
		{
			insert(n,aumento,A->izq);
			if(aumento)
			{
				switch(A->FB)
				{
					case -1:{
						A->FB = 0;
						aumento = false;
						break;
					}
					case 0:{
						A->FB = 1;
						aumento = true;
						break;
					}
					case 1:{
						if(A->izq->FB == 1)
						{
							rotarLL(A);
						}
						else
						{
							rotarLRalter(A);
						}
						aumento = false;
						break;
					}

				}
			}
		}
	}
	else
	{
		insert(n,aumento,A->der);
		if (aumento)
		{
			switch(A->FB)
			{
				case -1:{
					if(A->der->FB == 1)
					{
						rotarRLalter(A);
					}
					else{
						rotarRR(A);
					}
					aumento = false;
					break;
				}
				case 0:{
					A->FB =-1;
					aumento = true;
					break;
				}
				case 1:{
					A->FB = 0;
					aumento = false;
					break;
				}
			}
		}
	}
}

void insertar(AVL* &A, int n)
{
	bool aumento;
	insert(n,aumento,A);
}

bool vacio(AVL* &A)
{
	return A == NULL;
}

bool pertenece(AVL* &A, int n)
{
	if(A == NULL)
	{
		return false;
	}
	else
	{
		if(A->dato == n)
		{
			if(A->borrado){
				return false;
			}
			else
			{
				return true;
			}
		}else if(n < A->dato)
		{
			return pertenece(A->izq,n);
		}else{
			return pertenece(A->der,n);
		}
	}
}

void borrar(AVL* &A, int n)
{
	if(A->dato == n)
	{
		A->borrado = true;
	}else if(n < A->dato){
		borrar(A->izq,n);
	}else
	{
		borrar(A->der,n);
	}
}