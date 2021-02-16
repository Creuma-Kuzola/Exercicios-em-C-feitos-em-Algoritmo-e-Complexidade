#include <stdio.h>
#include <stdlib.h>
#define TAM 30
#define NOT_FOUND -1
#define OK 0
#define LIST_ISFULL 1
#define INVALID_INDEX 3

typedef struct
{
    int chave;
    char valor;
}TItem;

typedef struct 
{
    TItem item[TAM];
    int ulPos;

}TLSeq;

typedef enum { FALSE=0, TRUE = 1} Boolean;

typedef struct
{
    Titem pilha[TAM];
    int Topo;
}TPilha;

int desempilhar ( TPilha *pilha, int *x )
{
    if ( VaziaPilha (pilha) )
    return STACK_EMPTY;
    *x = pilha->item[pilha->topo];
    pilha->topo--;
    return OK;
}

int empilhar ( int x, TPilha *pilha )
{
    if ( CheiaPilha (pilha) )
    return STACK_FULL;
    pilha->topo ++;
    pilha->item[pilha->topo] = x;
    return OK;
}
Boolean cheiaPilha ( TPilha pilha )
{
    return ( pilha.topo == TAMANHO-1 );
}

Boolean vaziaPilha ( TPilha pilha )
{
    return ( pilha.topo == -1 );
}

void inicializarPilha ( TPilha *pilha )
{
    pilha->topo = -1;
}

int tamanhoPilha(TPilha pilha)
{
    return ( pilha.topo + 1 );
}

boolean ehCapicua(TLSeq )
{

}

int main ()
{
    
}