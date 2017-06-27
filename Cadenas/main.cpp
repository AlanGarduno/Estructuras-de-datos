#include <stdio.h>
#include <stdlib.h>

void invertir(char cadena[]);
void potencia(char s[], int n);
char * prefijo(char a[], int n);
char * subfijo(char a[], int n);
void subsec(char a[]);
void subcad(char a[], int n, int m);
int longi(char a[]);

int main(void)
{
    int res,loop;
    char cad1[100],cad2[100], *ca1,*ca2;
    printf("Ingresa 2 cadenas\n");
    printf("Primer cadena: \n");
    scanf("%s",cad1);
    printf("Segunda cadena: \n");
    scanf("%s",cad2);
    do
    {
        fflush(stdin);
        printf("Cadenas\n\n");
        printf("Elige una opcion\n1.Concatenar\n2.Invertir\n3.Prefijo\n4.Potencia\n5.Subfijo\n6.Subsecuencia\n7.Subcadena\n");
        scanf("%d", &res);
        switch (res)
        {
            case 1:
                printf("Primeea-Segunda\n");
                printf("%s%s\n",cad1,cad2);
                printf("Segunda-primera\n");
                printf("%s%s\n",cad2,cad1);
                break;
            case 2:
                printf("Primera cadena inversa\n");
                invertir(cad1);
                printf("Segunda cadena inversa\n");
                invertir(cad2);
                break;
            case 3:
                int let;
                printf("Ingresa el numero de  carcteres a remover\n");
                scanf("%d",&let);
                printf("Prefijo primer cadena\n");
                ca1 = prefijo(cad1,let);
                printf("%s\n",ca1);
                printf("Prefijo segunda cadena\n");
                ca2 = prefijo(cad2,let);
                printf("%s\n",ca2);
                break;
            case 4:
                int n;
                printf("Ingresa la potemcia\n");
                scanf("%d",&n);
                printf("Potencia primera cadena\n");
                potencia(cad1,n);
                printf("Potencia segunda cadena\n");
                potencia(cad2,n);
                break;
            case 5:
                int les;
                printf("Ingresa el numero de letras a remover\n");
                scanf("%d",&les);
                printf("Subfijo primer cadena\n");
                ca1 = subfijo(cad1,les);
                printf("%s\n",ca1);
                printf("Subfijo segunda cadena\n");
                ca2 = subfijo(cad2,les);
                printf("%s\n",ca2);
                break;
            case 6:
                printf("Subsecuencia Primer cadena\n");
                subsec(cad1);
                printf("Subsecuencia segunda cadena\n");
                subsec(cad2);
                break;
            case 7:
                int a,m;
                printf("Subcadena\n");
                printf("Ingresa el largo del prefijo a remover\n");
                scanf("%d",&a);
                printf("Ingresa el largo del subfijo a remover\n");
                scanf("%d",&m);
                printf("Subcadena primer cadena\n");
                subcad(cad1,a,m);
                printf("Subcadena segunda cadena\n");
                subcad(cad2,a,m);
                break;

            default:
                printf("ERROR");
        }
        printf("1.Volver al menu\n2.Salir\n");
        scanf("%d",&loop);
        system("CLS");
        system("PAUSE");
    }while(loop == 1);

    system(EXIT_SUCCESS);
}


void invertir(char cadena[]) //INVERIR
{
    char aux[100] ={0};
    int largo = longi(cadena) - 1;
    for (int i = largo, x=0;i >=0; i--,x++)
    {
        aux[x] = cadena[i]; //EL ARREGLO DE LA CADENA SE VACIA DE MANERA INVERSA EN EL AUXILIAR
    }
    printf("Cadena inicial %s  Resultado %s\n ",cadena, aux);

}

void potencia(char s[], int n) //POTENCIA
{
    if(n<0)
    {
        n=n*(-1);

        for (int i = 0; i <= n - 1; i++) {
            invertir(s);
            puts(s); //SE IMPRIME N VECES LA CADENA
        }

    }
    else {


        for (int i = 0; i <= n - 1; i++) {
            puts(s); //SE IMPRIME N VECES LA CADENA
        }
    }

}

char * prefijo(char a[], int n) //PREFIJO
{
    char aux[100];
    int largo = longi(a);
    if(largo < n)
    {
        printf("ERROR");
        return NULL; //SE COMPRUEBA QUE ESTE DENTRO DEL RANGO
    }
    else if(largo == n ) //SE COMPRUEBA CUADO QUEDA UNA CADEAN VACIA
    {
       return NULL;
    }
    else
    {
        int k = largo - n;
        for (int i = 0; i < k ; i++) // SE RESTA EL NUMERO DE CARACTERES A EL LARGO TOTAL PARA IMPRIMIRLO HASTA AHI
        {
            aux[i] = a[i];
        }
        return aux;
    }
}

char * subfijo(char a[], int n) //SUBFIJO
{
    char aux[100];
    int largo =  longi(a);
    if(largo < n)
    {
        printf("ERROR");
        return NULL;
    }
    else if(largo == n)
    {
        return NULL;
    }
    else
    {
        for (int i=n ,x = 0;i < largo ;i++,x++) // SE PONE COMO INICO DEL FOR DESDE N PARA QUITAR LO DEL PRINCIOPI
        {
            aux[x] = a[i]; //SE GUARDA EN EL AUXILIAR
        }
        aux[x]='\0';
          return  aux;
    }
}

void subsec(char a[]) //SUBSECUENCIA
{
    char aux[50];
    char elem[50];
    int i=0,j=0,k=0,len,lon;
    lon = longi(a);
    len = longi(elem);
    printf("Ingresa los carateres que quieres quitar %s \n",a);
    scanf("%s",elem);
    if(len > lon)
        printf("ERROR\n");
    while(a[i] != '\0')
    {
        if(len == 1)
        {
            if(elem[0] != a[i])
            {
                aux[k]=a[i];
                k++;
            }
            i++;

        }
        else
        {
            if(elem[j] != a[i])
            {
                aux[k]=a[i];
                k++;
            }
            else if(elem[j] == a[i])
            {
                j++;
            }
            i++;
        }

    }
    aux[k]='\0';
    printf("La subsecuencia de la cadena %s, es %s \n",a,aux);
}

void subcad(char a[], int n, int m) //SUBCADENAS
{
    char *aux,*aux2;
    int largo = longi(a);
    if((n + m) > largo) //SE COMPREUBA QUE NO PASE EL LARGO
        printf("ERROR");
    else if((n + m) == largo)  //cADENA VACIA
        NULL;
    else
    {
        aux = prefijo(a, n); //SE OBTIENE  LAS SUBCADENAS A PARTIR DE LAS FUNCIONES DE PREFIJO Y SUBFIJO
        aux2 = subfijo(aux, m);
        fflush(stdout);
        printf("%s\n",aux2);
    }
}

int longi(char a[])
{
    int cout=0,i=0;
    while(a[i] != '\0')
    {
        cout = cout+1;
        i++;
    }

    return cout;
}