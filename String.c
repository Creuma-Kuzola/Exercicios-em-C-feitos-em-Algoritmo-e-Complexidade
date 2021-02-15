#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int main ()
{
	
	int aux,f;
	char d;
	printf("%d",isdigit('g'));
	printf("Entre com a letra");
	scanf("%c",&d);
	
	aux = d -'c';
	f = aux+ 'c';
	printf("%d\n",aux);
	printf("%c",f);

	return 0;

}
