#include <iostream>
 
void hanoi(int num,char A,char C,char B)
{
    if(num==1)
    {
            printf("Mueva el bloque %d desde %c hasta %c\n", num, A, C);
             
    }
    else
    {
        hanoi(num-1,A,B,C);
        printf("Mueva el bloque %d desde %c hasta %c\n", num, A, C);
        hanoi(num-1,B,C,A);
    }
}
 
int main()
{
        int n, opc;
        char A,B,C;
 		do
 		{
 		system("cls");
        printf("Las torres de hanoi son A B C\n");
        printf("Inserte el numero de discos: ");
        scanf("%d", &n);
        if(n>=1)
        	{
        		hanoi(n,'A','C','B');
    		} else printf("\n Debe ingresar un dato entero positivo arriba de 0.");
		system("pause");
        system("cls");
        printf("\nDesea Realizar Nuevamente La Ejecucion: \n\nsi=1 \nno=2\n\n");
        scanf("%d", &opc);
    	}while(opc==1);
		return 0;	
}

