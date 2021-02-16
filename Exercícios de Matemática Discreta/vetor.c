#include <stdlib.h>
#define TAM 4
/*int main ()
{
int nvet[TAM]={1,2},i;
for(i=0;i<4;i++)
	printf(" %d Posição: %d \n " ,i, nvet[i]);

return 0;
}

/* Programa de votação estudantil */
#include <stdio.h>
#define TAMANHO_RESPOSTAS 10
#define TAMANHO_FREQUENCIA 11
int main()
{
int opiniao, nivel;
int respostas[TAMANHO_RESPOSTAS] =
{1,2,6,4,8,5,9,7,8,10};
int frequencia[TAMANHO_FREQUENCIA] = {0};
for (opiniao = 0; opiniao <= TAMANHO_RESPOSTAS - 1;
opiniao++)
++frequencia[respostas[opiniao]];

printf("%s%17s\n", "Nivel", "Frequencia");
for (nivel = 1; nivel <= TAMANHO_FREQUENCIA - 1; nivel++)
printf("%5d%17d\n", nivel, frequencia[nivel]);
return 0;
}
