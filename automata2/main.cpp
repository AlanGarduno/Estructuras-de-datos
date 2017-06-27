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
    bool q0=true,q1=false,q2=false,q3=false,q4=false;
    int i=0;
    int x = strlen(cad);
    while(i < x+1 )
    {
        if(q0 == true && cad[i] == '0')
        {
            q2=false,q3=false,q4=false;
            q1=true;
            q0 = false;
            i++;
        }
        else if(q0 == true && cad[i] == '1')
        {
            q1=false,q3=false,q4=false;
            q2 = true;
            q0 = false;
            i++;
        }
        else if(q2 == true && cad[i] == '0')
        {
            q3=false,q4=false,q2=false;
            q1 = true;
            i++;
        }
        else if(q2 == true && cad[i] == '1')
        {
            q3=false,q4=false,q1=false;
            q2 = true;
            i++;
        }
        else if(q1 == true && cad[i] == '0')
        {
            q2 = false,q3=false,q4=false;
            q1 = true;
            i++;
        }
        else if(q1 == true && cad[i] == '1')
        {
            q2 = false,q4=false,q1=false;
            q3 = true;
            i++;
        }
        else if(q3 == true && cad[i] == '0')
        {
            q2 = false,q4=false,q3=false;
            q1= true;
            i++;
        }
        else if(q3 == true && cad[i] == '1')
        {
            q2 = false,q1=false,q3=false;
            q4 = true;
            i++;
        }
        else if(q4 == true && cad[i] == '0')
        {
            q2 = false,q3=false,q1=false;
            q1 = true;
            i++;
        }
        else if(q4 == true && cad[i] == '1')
        {
            q1 = false,q3=false,q3=false;
            q2 = true;
            i++;
        }
        else if (q4 == true)
        {
            printf("Cadena valida\n");
            return;

        }
        else
        {
            printf("Cadena no valida\n");
            return;
        }
    }
}




