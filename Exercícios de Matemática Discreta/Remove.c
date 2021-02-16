#include <stdio.h>
#include <stdlib.h>

int main ()
{
   int vet [9] = {1,2,3,4,5,6,7,8,9};
   int nElem = 9,k,m,cont, quant;

   printf("Entre com o k e com o m \n");
   scanf("%d %d" ,&k , &m );
   
   if(nElem-1-m-k != 0)  /* Para saber se depois da posição da paragem de remoção, ainda tem mais elementos*/
   {   quant =nElem-1-m-k;
       cont = m+k+1;
       for(int i = 0; i<quant;i++)
          vet[k+i] = vet[cont+i];
	nElem-= m+1;
   }
   else
      nElem-= m+1;
	
return 0;

}
