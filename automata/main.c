#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verificar(char *cad);
void recorrido(char *cad);

int main( )
{
    char *cad = (char*)malloc(sizeof(char)*50);
    printf("Ingresa una cadena\n");
    scanf("%s",cad);
    if(verificar(cad) == 0)
    {
        printf("Cadena invalida\n");
        return 0;
    }
    recorrido(cad);
    return 0;
}

int verificar(char *cad)
{
    int i = 0;
    while(cad[i] != '\0')
    {
        if(cad[i] != '1' && cad[i] != '0' )
        {
            return 0;
        }
        i++;
    }
    return 1;
}

void recorrido(char *cad)
{
    bool q0=false,q1=false,q2=false,q3=false,q4=false;
    int i=0;
    while(cad[i] != '\0')
    {
        if(cad[i] == '0')
        {
            q1=true;
            i++;
        }
        else if(cad == '1')
        {
            q2 = true;
            i++;
        }
        else if(q2 = true && cad[i] = '0')
        {
            q1 = true;
            i++;
        }
        else if(q2 = true && cad[i] = '1')
        {
            q2 = true;
            i++;
        }
        else if(q1 =true && cad[i] == '0')
        {
            q1 = true;
            i++;
        }
        else if(q1 =true && cad[i] == '1')
        {
            q3 = true;
            i++;
        }
        else if(q3 = true && cad[i] == '0')
        {
            q1= true;
            i++;
        }
        else if(q3 = true && cad[i] == '1')
        {
            q4 = true;
            i++;
        }
        else if(q4 = true && cad[i] == '0')
        {
            q1 = true;
            i++;
        }
        else if(q4 = true && cad[i] == '1')
        {
            q2 = true;
            i++;
        }
        else if (q4 = true)
        {
            printf("Cadena valida\n");

        }
        else
        {
            printf("Cadena no valida\n");
        }
    }

}
