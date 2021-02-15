#include <stdio.h>
#include <stdlib.h>

int invertElementosDoVector(int vet [], int nElem,int i);

int invertElementosDoVector(int vet [], int nElem,int i)
{
  int aux;
  if( i == nElem/2)
			return 1;

		aux=vet[i];
  vet[i] = vet[nElem-i];
  vet[nElem-i] = aux;
  return invertElementosDoVector(vet,nElem,i+1);

}

int main()
{

  int vet [] = {1,2,4,5},i;
  invertElementosDoVector(vet, 3,0);	
  for(i=0;i<4;i++)
      printf("%d Mostrando : \n",vet[i]);	
  
 return 0;

}
