#include <stdio.h>
#include <string.h>

int largo(char a[]);

int main()
{
    char a[20]="Hola";
    int l,r;
    l=largo(a);
    printf("El largo de la cadena es %d \n",l);
    r=strlen(a);
    printf("El largo de la cadena es %d \n",r);
    strcat(a,"Alan");
    printf("%s\n",a);

}

int largo(char a[])
{
    int cout=0,i=0;
    while(a[i] != '\0')
    {
        cout = cout+1;
        i++;
    }

    return cout;
}
