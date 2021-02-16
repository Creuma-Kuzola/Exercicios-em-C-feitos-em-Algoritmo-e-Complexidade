#include <stdio.h>
#include <stdlib.h>
#define OK           0
#define QUEUE_FULL   1
#define QUEUE_EMPTY  2
#define NO_MEMORY    3
#define TAM          100

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
    TAtomo *frente;
    TAtomo *fundo;
}TFDinamica;


void criarFila(TFDinamica *fila)
{
    fila->frente = fila->fundo = NULL;
}

int vaziaFila(TFDinamica *fila)
{
    return (fila->frente == NULL && fila->fundo == NULL);
}

int inserir(TFDinamica *fila, TInfo info)
{
    TAtomo *paux = (TAtomo*) malloc(sizeof(TAtomo));
    if(paux == NULL) return NO_MEMORY;
    paux->info = info;
    paux->prox = NULL;
    if(vaziaFila(fila))
        fila->frente = fila->fundo = paux;
    fila->fundo->prox = paux;
    fila->fundo = paux;
}

int remover(TFDinamica *fila, TInfo *info)
{
    TAtomo *pdel = fila->frente;
    if(vaziaFila) return QUEUE_EMPTY;
    if(fila->frente == fila->fundo) fila->frente = fila->fundo = NULL;
    fila->frente = pdel;
    *info = pdel->info;
    free(pdel);
    return OK;
}

int main()
{

}