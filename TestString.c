#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define TAM 30
int main ()
{
		char string [TAM];
		long unsigned int tam;
		
		puts("Entre com um nome: ");
		fflush(stdin); // Limpeza do buffer do teclado
	 scanf("%[^\n]",string);
		printf("\nA string digitada é : ");
		puts(string);
		tam = strlen(string);
		printf("\n O tamanho da string é %ld",sizeof(string)); // Tamanho da string em bytes.
		
	//	printf("De acordo com isdigit", isdigit('8') ? " 8 e um " : "8 nao e um ", "digito");

	return 0;
}
