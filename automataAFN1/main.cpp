#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void recorrido(char *cad);

int main( )
{
    char *cad = (char*)malloc(sizeof(char)*50);
    printf("Ingresa una cadena\n");
    scanf("%s",cad);
    recorrido(cad);
    return 0;
}

void recorrido(char *cad)
{
    char *aux = (char*)malloc(sizeof(char)*50);
    bool q0=true,q1=false,q2=false;
    int i=0;
    int len = strlen(cad);
    while(i<len+1)
    {
        if(cad[i] == '0')
        {
            q0 = false;
            q1 = true;
            q2 = false;
            i++;
            strcat(aux,"q0");
            //aux[j] = "q0";
            //j++;
        }
        else if(q0 == true && cad[i] == '1')
        {
            q0 = true;
            q1 = false;
            q2 = false;
            i++;
            strcat(aux,"q0");
            //aux[j] = "q0";
            //j++;
        }
        else if(q1 == true && cad[i] == '0')
        {
            printf("Cadena no valida\n");
            break;
        }
        else if(q1 == true && cad[i] == '1')
        {
            q0 = false;
            q2 = true;
            i++;
            strcat(aux,"q1");
            //aux[j] = "q1";
            //j++;
        }
        else if(q2 == true)
        {
           // aux[j] = "q2";
            //j++;
            strcat(aux,"q2");
            printf("Cadena valida\n");
            puts(aux);
            break;

        }
        else
        {
            printf("Cadena no valida\n");
            break;
        }

    }

}
