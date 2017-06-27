#include <stdlib.h>
#include<stdio.h>
using namespace std;
struct lista{
       int dato;
       int busqueda=0;
       struct lista *apunt;
};


typedef struct lista *Tlista;
void lista_opciones();
void insertarFinal(Tlista &lista, int datoa);
int insertarAntesDespues(int a);
void insertarInicio(Tlista &lista, int datoa);
void insertarElemento(Tlista &lista, int datoa, int pos,int a);
void buscarElemento(Tlista lista, int datoa); //Busqueda secuencial
void reportarLista(Tlista lista);
void eliminarElemento(Tlista &lista, int datoa);
void eliminaRepetidos(Tlista &lista, int datoa);
int av;
 Tlista lista = NULL;
void insertarda(Tlista &lista, int datoa, int pos)
{
    Tlista q, t;
    int i;
    q = new(struct lista);
    q->dato = datoa;

    if(pos==1)
    {
        q->apunt = lista;
        lista = q;
    }
    else
    {
        int x = insertarAntesDespues(1);
        t = lista;

        for(i=1; t!=NULL; i++)
        {
            if(i==pos+x)
            {
                q->apunt = t->apunt;
                t->apunt = q;
                return;
            }
            t = t->apunt;
        }
    }
}



void eliminarElementoda(Tlista &lista, int datoa, int pos)
{
    Tlista p, ant;
    p = lista;

    if(lista!=NULL)
    {
        while(p!=NULL)
        {
            if(p->dato==datoa)
            {
                if(p==lista)
                    lista = lista->apunt;
                else
                    ant->apunt = p->apunt;

                delete(p);
                return;
            }
            ant = p;
            p = p->apunt;
        }
    }
    insertarda(lista, datoa,  pos-1);


}
int main()
{

    int op;
    int _dato;
    int pos;
    do
    {
        lista_opciones();
        scanf("%d",& op);
        switch(op)
        {
            case 1:
                 printf( "\n NUMERO A INSERTAR: "); scanf("%d",& _dato);
                 insertarInicio(lista, _dato);
            break;
            case 2:
                 printf( "\n NUMERO A INSERTAR: ");
                 scanf("%d",& _dato);
                 insertarFinal(lista, _dato );
            break;
            case 3:

                 printf( "\n NUMERO A INSERTAR: ");
                 scanf("%d",& _dato);
                 printf( " Posicion : ");
                 scanf("%d",& pos);
                 insertarElemento(lista, _dato, pos,0);
            break;
            case 4:

                 printf("\n\n MOSTRANDO LISTA\n\n");
                 reportarLista(lista);
            break;
            case 5:

                 printf("\n DATO A BUSCAR: ");
                 scanf("%d",& _dato);
                 buscarElemento(lista, _dato);
            break;
            case 6:
                printf("\n DATO A ELIMINAR: ");
                scanf("%d",& _dato);
                eliminarElemento(lista, _dato);
            break;
            case 7:

                printf("\n DATOS REPETIDOS A ELIMINAR ");
                 scanf("%d",& _dato);
                eliminaRepetidos(lista, _dato);
            break;
            default:
                printf("\noOPCION NO VALIDA\n");
                    }
        printf("\n\n");
        system("pause");
        system("cls");

    }while(op!=8);
   return 0;
}

void insertarInicio(Tlista &lista, int datoa)
{
    Tlista q;
    q = new(struct lista);
    q->dato = datoa;
    q->apunt = lista;
    lista  = q;
}
void insertarFinal(Tlista &lista, int datoa)
{
    Tlista t, q = new(struct lista);

    q->dato  = datoa;
    q->apunt = NULL;

    if(lista==NULL)
    {
        lista = q;
    }
    else
    {
        t = lista;
        while(t->apunt!=NULL)
        {
            t = t->apunt;
        }
        t->apunt = q;
    }

}

int insertarAntesDespues(int a)
{
    int _op, da;
    if(a=1)
    {
        da = -1;
    }
    else
    {
    printf("\n");
    printf("\t 1. ANTES DE LA POSICION ");
    printf("\t 2. DESPUES DE LA POSICION ");

    "\n\t OPCION : ";
    scanf("%d",&_op);

    if(_op==1)
        da = -1;
    else
        da = 0;
 }
    return da;
}

void insertarElemento(Tlista &lista, int datoa, int pos, int a)
{
    Tlista q, t;
    int i;
    q = new(struct lista);
    q->dato = datoa;

    if(pos==1)
    {
        q->apunt = lista;
        lista = q;
    }
    else
    {
        int x = insertarAntesDespues(a);
        t = lista;

        for(i=1; t!=NULL; i++)
        {
            if(i==pos+x)
            {
                q->apunt = t->apunt;
                t->apunt = q;
                return;
            }
            t = t->apunt;
        }
    }
    printf(" \nPOSICION ENCONTRADA\n");
}

void buscarElemento(Tlista lista, int datoa) //Busqueda secuencial
{
    Tlista q = lista;
       Tlista aux;
       Tlista abc=lista;
    int i = 1, repeticion = 0,f=0;

    while(q!=NULL)
    {
        if(q->dato==datoa)
        {
            printf(" ENCONTRADA EN POSICION %d \n", i );
            repeticion=1;
            q->busqueda=q->busqueda+1;
            if(q->busqueda>3)
            {
                f=q->busqueda;
            eliminarElemento(lista, datoa);
            insertarElemento(lista,datoa,i-1,1);
            }
        }
        q = q->apunt;
        i++;


    }
    reportarLista(lista);
    if(repeticion==0)
        printf("\n\n NUMERO NO ENCONTRADO\n");
}

void reportarLista(Tlista lista)
{
     int i = 0;

     while(lista != NULL)
     {
          printf("%d) %d\n",i+1,lista->dato);
          lista = lista->apunt;
          i++;
     }
}


void eliminarElemento(Tlista &lista, int datoa)
{
    Tlista p, ant;
    p = lista;

    if(lista!=NULL)
    {
        while(p!=NULL)
        {
            if(p->dato==datoa)
            {
                if(p==lista)
                    lista = lista->apunt;
                else
                    ant->apunt = p->apunt;

                delete(p);
                return;
            }
            ant = p;
            p = p->apunt;
        }
    }
    else
        printf(" LISTA VACIA\n");
}

void eliminaRepetidos(Tlista &lista, int datoa)
{
    Tlista q, ant;

    q = lista;
    ant = lista;

    while(q!=NULL)
    {
        if(q->dato==datoa)
        {
            if(q==lista)
            {
                lista = lista->apunt;
                delete(q);
                q = lista;
            }
            else
            {
                ant->apunt = q->apunt;
                delete(q);
                q = ant->apunt;
            }
        }
        else
        {
            ant = q;
            q = q->apunt;
        }

    }

    printf("\n\n DATOS ELIMINADOS\n");
}

void lista_opciones()
{

    printf(" 1. INSERTAR AL INICIO\n");
    printf(" 2. INSERTAR AL FINAL\n");
    printf(" 3. INSERTAR EN UNA POSICION\n");
    printf(" 4. MOSTRAR LISTA \n");
    printf(" 5. BUSCAR ELEMENTO\n");
    printf(" 6. ELIMINAR ELEMENTO\n");
    printf(" 7. ELIMINAR ELEMENTOS REPETIDOS CON DATO ESPECIFICO \n");
    printf(" 8. SALIR \n");
    printf("\n ESCOJA UNA OPCION: ");
}
