#include <stdlib.h>
#include <stdio.h>


typedef struct ArbolBinario
{
    int dato;
    struct ArbolBinario *izq;
    struct  ArbolBinario *der;
}arbol;

arbol *insert(arbol *a,int valor);
arbol *swap(arbol *a);
arbol *serch(arbol*a, int llave);
arbol *serchMin(arbol *a);
arbol *serchMax(arbol *a);
void destruir(arbol *a);
int count(arbol *a);
void print_preorder(arbol *a);
void print_postorder(arbol *a);
void print_inorder(arbol *a);

int main()
{

}

arbol *insert(arbol *a, int valor)
{
    arbol *tmp_one=NULL;
    arbol *tmp_two=NULL;
    if(a == NULL)
    {
        a =(arbol*)malloc(sizeof(arbol)*1);
        a->dato=valor;
        a->izq = NULL;
        a->der = NULL;
    }
    else
    {
        tmp_one = a;
        while (tmp_one != NULL)
        {
            tmp_two = tmp_one;
            if(tmp_one->dato > valor)
                tmp_one = tmp_one->izq;
            else
                tmp_one = tmp_one->der;
        }

        if(tmp_two->dato > valor)
        {
            tmp_two->izq = (arbol*)malloc(sizeof(arbol)*1);
            tmp_two = tmp_two->izq;
            tmp_two->dato=valor;
            tmp_two->izq = tmp_two->der = NULL;
        }
        else
        {
            tmp_two->der=(arbol*)malloc(sizeof(arbol)*1);
            tmp_two = tmp_two->der;
            tmp_two->dato=valor;
            tmp_two->izq = tmp_two->der = NULL;
        }
        return  (a);
    }
}

void print_inorder(arbol *a)
{
    if(a!=NULL)
    {
        print_inorder(a->izq);
        printf("%d",a->dato);
        print_inorder(a->der);

    }
}

void print_preorder(arbol *a)
{
    if(a != NULL)
    {
        printf("%d",a->dato);
        print_preorder(a->izq);
        print_preorder(a->der);
    }
}

void print_postorder(arbol *a)
{
    if(a != NULL)
    {
        print_postorder(a->izq);
        print_postorder(a->der);
        printf("%d",a->dato);
    }
}

int count(arbol *a)
{
    if(a == NULL)
    {
        return  0;
    }
    else
    {
        if(a->der == NULL && a->izq == NULL)
            return  1;
        else
            return  (1+count(a->izq) + count(a->der));
    }
}

void destruir(arbol *a)
{
    if(a != NULL)
    {
        destruir(a->izq);
        destruir(a->der);
        free(a);
    }
}

arbol *swap(arbol * a)
{
    arbol *tmp_one = NULL;
    arbol *tmp_two = NULL;

    if(a!= NULL)
    {
        tmp_one = swap(a->izq);
        tmp_two = swap(a->der);
        a->der = tmp_one;
        a->izq = tmp_two;
    }
    return(a);
}

arbol *serch(arbol *a, int llave)
{
    arbol *tmp = NULL;
    tmp = a;

    while(tmp != NULL)
    {
        if(tmp->dato == llave)
            return  tmp;
        else if(tmp->dato > llave)
            tmp = tmp->izq;
        else
            tmp = tmp->der;
    }
    return  NULL;
}

arbol *serchMin(arbol *a)
{
    if(a == NULL)
        return  NULL;
    else
        if(a->izq == NULL)
            return a;
    else
            return  serchMin(a->izq);
}

arbol *serchMax(arbol *a)
{
    if(a != NULL)
        while(a != NULL)
        {
            a=a->der;
        }

    return a;
}





