#include <stdio.h>
#include <stdlib.h>
#define TAM 12

int main ()
{
 int i,tot = 0,n,aux,vet[TAM]={0};

for(i=0;i<TAM;i++)
	scanf("%7d",&vet[i]);

n = vet[0];
aux=1;

for(i=1;i<TAM;i++)
{   if(n==vet[i])
      aux++;
    else
    {
      n = vet[i];
      if(aux>tot)
      {
         tot = aux;
         aux=0;
      }		
    }
}
printf("Tot: %d", tot);

return 0;
}
