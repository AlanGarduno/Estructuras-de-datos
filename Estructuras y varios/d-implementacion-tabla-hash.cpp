#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <Math.h>
#include<stdio.h>

typedef struct no no_hash;
struct no
{
    int data; 
    int state; /* 0 para VACIO, 1 para REMOVIDO e 2 para OCUPADO */
};

// Esta función se encarga de la distribución de la tabla hash
int funcion(int k, int m, int i)
{ 
    return ((k+i)%m);
}
/* Crea la tabla hash basando en un determinado tamaño de tabla asignada por el usuario*/
no_hash *Crea_Hash(int m)
{
    no_hash *temp;
    int i; 
   if((temp = (no_hash*)malloc(m*sizeof(no_hash))) != NULL)
   {
        for(i = 0; i < m; i++)
           temp[i].state = 0;
        return temp;
   }
   else
        exit(0);
}
// Inserta un elemento k en la tabla llamada T de tamaño m
void Inserta_Hash(no_hash *T, int m, int k)
{
    int j, i = 0;
    do
    {
        j = funcion(k, m, i);
        if(T[j].state == 0 || T[j].state == 1)
        {
            T[j].data = k;
            T[j].state = 2;
            printf("\nElemento insertado con éxito!\n");
            return;
        }
        else
            i++;
    }while(i < m);
    printf("\nTabla llena!\n");
}

//Esta funcion hace una busqueda de elementos dentro de la tabla hash
/*Busca un elemento de la tabla hash, regresa -1 si no se encontro el elemento, 
y si se encuentra regresa el subindice donde se encuentra el dato*/
int Busca_Hash(no_hash *T, int m, int k, int i)
{
    int j;
    if(i < m)
    {
        j = funcion(k, m, i);
        if(T[j].state == 0)
            return -1;
        else
            if(T[j].state == 1)
                return Busca_Hash(T, m, k, i+1);
            else
                if(T[j].data == k)
                    return j;
                else
                    return Busca_Hash(T, m, k, i+1);
    }
    return -1;
}
/*Esta funcion hace la eliminacion de elementos dentro de la tabla hash,*/
//Reemplaza con 0 el numero que se desea eliminar y cambia el dato state de la estructura a 1 (Removido)
int Remove_Hash(no_hash *T, int m, int k)
{
    int i;
    i = Busca_Hash(T, m, k, 0);
    if(i == -1)
        return -1;
    else
    {
        T[i].state = 1;
         T[i].data=0;
        return 1;
    }
}
//imprime el comportamiento de la tabla hash
void imprimir(no_hash *T,int m)
{
	int i;
	for(i=0;i<m;i++)
	printf("%d\t",T[i].data);
	
}
//Reemplaza todos los datos de la tabla por 0
void inicieo(no_hash *T,int m)
{
	int i=0;
	do
    {
            T[i].data = 0;
            i++;
    }while(i < m);
	
}

int main() 
{
    int m, i, k; 
    int op;
    no_hash *T; 
    printf("\nEntre con el tamano de la tabla: \n");
    scanf("%d", &m);
    
    T = Crea_Hash(m);
    inicieo(T, m);
    while(1) 
    {
    	system("cls");
        printf("\n Insertar (1)\n Buscar (2)\n Remover (3) \n Salir (4)\n");
        scanf("%d",&op);
        switch(op)
        { 
            case 1:
              	printf("\nIngrese el numero a ser insertado en la tabla: ");
                scanf("%d", &k);
                Inserta_Hash(T, m, k);
                imprimir(T, m);
                printf("\n");
                system("pause");
                break;
            case 2: 
               	printf("\nIngrese el numero a ser buscado en la tabla: ");
                scanf("%d", &k);
                i = Busca_Hash(T, m, k, 0);
                if(i == -1) 
                    printf("\nNumero no encontrado!\n");
                else 
                    printf("\nNumero encontrado!\n");
                system("pause");
                break; 
            case 3:
                printf("\nIngrese el numero a ser eliminado de la tabla: ");
                scanf("%d", &k);
                i = Remove_Hash(T, m, k); 
                if(i == -1)
                    printf("\nNumero no encontrado!\n");
                else
                    printf("\nNumero eliminado con éxito!\n");
                 printf("\n");   
                    imprimir(T, m);
                printf("\n");
              system("pause");
                break;
                
            case 4: 
                exit(0);
                break; 
                
                default:
					printf("opcion no valida");
					system("pause");
      }
   } 
}

