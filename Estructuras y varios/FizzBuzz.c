#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void fizzBuzz(int a[], int tam);

int main(int argc, char const *argv[])
{
  printf("Fizz_Buzz\n");
  int a[MAX] = {1,2,3,4,27,40,90,20,90};
  fizzBuzz(a,MAX);
  return 0;
}


void fizzBuzz(int a[], int tam)
{
  int i;
  for (i = 0; i <= tam; i++)
  {
    if((a[i]%3)==0)
    {
      printf("Buzz\n");
    }
    if((a[i]%5)==0)
    {
      printf("Fizz\n");
    }
  }
}
