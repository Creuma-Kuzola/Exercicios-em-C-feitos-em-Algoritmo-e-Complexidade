#include <stdio.h>
#include <stdlib.h>

int verificaCapicua(int vet [], int nElem, int i);

int verificaCapicua(int vet [], int nElem, int i)
{
			if (i>nElem) return 1;
			if (vet[i] != vet[nElem-1]) return 0;
			return verificaCapicua(vet,nElem-1,i+1);
}

int main ()
{
	
int vet [] = {1,2,3,2,1};

printf("%d",verificaCapicua(vet,5,0));

return 0;
}
