#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOT_FOUND  -1
#define OK          0
#define STACK_EMPTY 2
#define NO_SPACE    5

typedef struct
{
    int chave;
    int valor;

}TInfo;

typedef struct 
{
    TInfo info;
    TAtomo *prox;

}TAtomo;

typedef struct
{
    TAtomo *topo;

}TPDinamica;

typedef enum { FALSE=0, TRUE = 1}boolean;

void criarPilhaDinamica(TPDinamica *pilha)
{
    pilha->topo = NULL;
}

int empilhar(TPDinamica *pilha, TInfo info)
{
    TAtomo *pNovo = (TAtomo*) malloc(sizeof(TAtomo));
    if(pNovo == NULL) return NO_SPACE;
    pNovo->info = info;
    pNovo->prox = pilha->topo;
    pilha->topo = pNovo;
    return OK;
}

boolean estavazia(TPDinamica pilha)
{
    return (pilha.topo == NULL);
}

int desempilhar(TPDinamica *pilha, TInfo *x)
{
    if(estavazia(pilha)) return STACK_EMPTY;
    TAtomo *paux = pilha->topo;
    *x = pilha->topo->info;
    pilha->topo = paux->prox;
    free(paux);
    return OK;
    
}

int main ()
{

}