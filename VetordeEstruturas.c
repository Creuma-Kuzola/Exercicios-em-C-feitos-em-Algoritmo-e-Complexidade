#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 4

typedef struct
{
		int chave;
		float valor;
}TItem;

typedef struct 
{
		TItem item[MAX];
		int nElem;
}TVet;

typedef enum { FALSE= 0, TRUE=1 }Boolean;

void mostrarDados(TVet vet);
void inserirDadoChave(TVet *vet, TItem x);
void inicializarVector(TVet *vet);
TItem acederElemento (TVet vet, int pos);
Boolean estaVazio(TVet vet);
Boolean estaContido(int ini, int fim, int pos);

void inicializarVector(TVet *vet)
{
		vet->nElem = 0;
}

Boolean estaVazio(TVet vet)
{
			return vet.nElem == 0;
}

Boolean estaCheio(TVet vet)
{
			return vet.nElem == MAX;
}

TVet acederElemento (TVet vet, int pos)
{
		if(estaContido(0,vet.nElem,pos))
						return vet.item[pos];
		printf("Erro: Posição inválida");				
}

Boolean estaContido(int ini, int fim, int pos)
{
			return (pos>= ini && pos <=fim);
}

void inserirDadoChave(TVet *vet, TItem x)
{
		vet->item[vet->nElem] = x;
		vet->nElem++;

}

void mostrarDados(TVet vet)
{
		for(int i = 0; i<vet.nElem;i++)
						printf("chave: %d  valor: %f \n",vet.item[i].chave, vet.item[i].valor);
}

int main ()
{
	
}


