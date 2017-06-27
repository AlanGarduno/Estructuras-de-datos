 #include "lenguajes.h"
#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void introducir_Lenguaje(Lista *l)
{
    int res;
    char *cad = NULL;
    do
    {
        printf("Intoduce la cadena perteneciente al lenguaje\n");
        scanf("%s",cad);
        listaAgregar(l,cad);
        printf("Deseas introudicr otra cadena\n1.Si\n2.No\n");
        scanf("%d",&res);
    }while(res != 2);
    system("CLS");

}

int existe(char*a,char*b)
{
    if(strcmp(a,b) == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

Lista * unir(Lista* l, Lista*l2)
{
    Nodo *a,*b,*c;
    Lista *aux = crearLsita();
    a = l->inico;
    b = l2->inico;
    while(a != NULL)
    {
        listaAgregar(aux,a->cad);
        a = a->siguiente;
    }
    c = aux->inico;
    while(b != NULL && c != NULL)
    {
        if(existe(c->cad,b->cad) == 0)
        {
            b = b->siguiente;
            c = c->siguiente;
            break;
        }
        else
        {
            listaAgregar(aux,b->cad);
            b = b->siguiente;
            c = c->siguiente;

        }
    }

    return aux;
}

Lista *concatenar(Lista *l1, Lista* l2)
{
    Nodo *a,*b;
    char *cad =(char*)malloc(sizeof(char));
    char *cas = (char*)malloc(sizeof(char));
    Lista *aux;
    a=l1->inico;
    aux = crearLsita();
    while(a != NULL)
    {
        b=l2->inico;
        while(b != NULL)
        {

            cas = strcpy(cad,strcat(a->cad,b->cad));
            listaAgregar(aux,cas);
            b=b->siguiente;
            free(cad);
        }
        a=a->siguiente;
    }
    return aux;
}
