#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
		int idade;
		char nome [25];
		char sexo;
		char morada [10];

}pessoa;

struct horario
{
		int hora;
		int min;
		int seg;
}h1={10,12};

int main()
{

	/*	char vet[25];
		printf("Sexo: %c \n", p1.sexo);
		strcpy(p1.nome,"Creuma Kuzola");
		printf("Nome: ");
		puts(p1.nome);
		
		struct horario h2;
		h2 = h1;
		
		printf("H1: %d:%d:%d \n", h1.hora, h1.min,h1.seg);
	//	printf("H2: %d:%d:%d", h2.hora, h2.min,h2.seg);
	*/
	pessoa p[5];
	
	for(int i=0;i<3;i++)
	{
			//fflush(stdin);
			printf("Entre com o nome: ");
			scanf(" %[^\n]",p[i].nome);
			
	}
	return 0;	
}
