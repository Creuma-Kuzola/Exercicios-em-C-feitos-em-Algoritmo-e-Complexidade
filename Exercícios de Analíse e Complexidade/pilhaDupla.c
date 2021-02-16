#include <stdio.h>
#include <stdlib.h>
#define NOT_FOUND  -1 // Não encontrado
#define OK          0 // Efectuado com sucesso
#define STACK_FULL  1 // Pilha Vazia
#define STACK_EMPTY 2 // Pilha Cheia
#define ST1_FULL    3
#define ST2_FULL    4
#define NUM_PILHA_INVALIDA 5
#define TAM         100 // Tamanho da Pilha

typedef struct
{
    int chave;
    float valor;
}TItem;

typedef struct pilhaDupla
{
    int topo1;
    int topo2;
    TItem item[TAM];
}TPDupla;

typedef enum { FALSE=0, TRUE = 1}boolean;

void criarPilhaDupla(TPDupla *pDupla )
{
    pDupla->topo1 = -1;
    pDupla->topo2 = TAM;
}

int tamanhoPilhaDupla(TPDupla *pDupla, int numPilha)
{
    if(numPilha == 1) return (pDupla->topo1+1);
    return (pDupla->topo2+1);
}

boolean estaVazia(TPDupla *pDupla, int numPilha)
{
    if(numPilha == 1) return (pDupla->topo1 == -1);
    return(pDupla->topo2 == (TAM) );
}

boolean estaCheia(TPDupla *pDupla)
{
    if(pDupla->topo1 == -1) 
    {   
        if(pDupla->topo2 == TAM) return TRUE;
        return ST1_FULL;
    }
    else
        return ST2_FULL;
}

int empilhar(TPDupla *pDupla, TItem x,int numPilha)
{
    if(estaCheia(pDupla)) return STACK_FULL;
    //if(numPilha == 1 && estaCheia(pDupla) == 3) return ST1_FULL;
    //if(numPilha == 2 && estaCheia(pDupla) == 4) return ST2_FULL;

    if(numPilha == 1) 
    {
        pDupla->topo1++;
        pDupla->item[pDupla->topo1] = x;
    }
    else if(numPilha == 2)
    {
        pDupla->topo2--;
        pDupla->item[pDupla->topo2]=x;
    }
    else
       return NUM_PILHA_INVALIDA;
    
    return OK;
}

int desempilhar (TPDupla *pDupla, TItem *x, int numPilha)
{
    if(estaVazia(pDupla, numPilha)) return STACK_EMPTY;
    if(numPilha == 1)
    {
        *x = pDupla->item[pDupla->topo1];
        pDupla->topo1--;
    }
    else if(numPilha == 2)
    {
        *x = pDupla->item[pDupla->topo2];
        pDupla->topo2++;
    }
    else 
        return NUM_PILHA_INVALIDA;

    return OK;    
}

int imprimirUmaPilha(TPDupla *pDupla, int numPilha)
{
    if(numPilha == 1)
    { 
        if(estaVazia(pDupla,numPilha)) return STACK_EMPTY;
        printf("Elementos da pilha 1\n");
        for(int i = pDupla->topo1;i>-1;i--)
            printf("Chave: %d \n", pDupla->item[i].chave);
    }
    else if(numPilha == 2)
    {
        if(estaVazia(pDupla,numPilha))return STACK_EMPTY;
        printf("Elementos da pilha 2\n");
        for(int i = pDupla->topo2; i<TAM; i++)
           printf("%d \n", pDupla->item[i].chave); 
    }
    else
        return NUM_PILHA_INVALIDA;
    
    return OK;

}

int main()
{

    TPDupla pilha;
    TItem x,y;
    x.chave = 1;
    x.valor = 12;
    y.chave = 2;

    criarPilhaDupla(&pilha);
    pilha.topo1++;
    //pilha.item[pilha.topo1] = x;
    empilhar(&pilha,x,1);
    //printf("%d",empilhar(&pilha,y,1));
    imprimirUmaPilha(&pilha,1);

}


