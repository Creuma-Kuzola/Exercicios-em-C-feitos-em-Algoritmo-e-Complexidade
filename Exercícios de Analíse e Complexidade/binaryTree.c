#include <stdio.h>
#include <stdlib.h>
#define NOT_FOUND     -1
#define OK             0
#define TREE_EMPTY     2
#define NOT_TERMINAL   4
#define NO_SPACE       5
#define DESCENDING_FOUND 6
#define FATHER_WITHOUT_CHILD 7
#define NOT_LEAF 8
#define DESCENDING_NOT_FOUND 9
#define TAM 50

typedef enum {FALSE = 0, TRUE = 1 }boolean;

// Fila Sequencial
typedef struct
{
    int valor;
}TItem;

typedef struct
{
    TItem item[TAM];
    int frente;
    int fundo;
}TFila;

//  Árvore Binária
typedef struct 
{
    int chave;
    float valor;

}TInfo;

typedef struct Atomo
{
    struct Atomo *fesq;
    TInfo info;
    struct Atomo *fdir;
}TAtomo;

typedef struct 
{

    TAtomo *raiz;
}TAB;

// Fila Sequencial

void criarFila(TFila *fila)
{
    fila->frente = fila->fundo = -1;
}

boolean vaziaFila(TFila *fila)
{
    return(fila->frente == -1 && fila->fundo == -1);
}

boolean cheiaFila(TFila *fila)
{
    return (fila->fundo == TAM-1);
}


// Arvore Binaria
void criaArvoreBinaria(TAB *arvore)
{
    arvore->raiz = NULL;
}

int criarAtomoRaiz(TAB *arvore, TInfo info)
{
    arvore->raiz = (TAtomo*) malloc(sizeof(TAtomo*));
    if(arvore->raiz == NULL) return NO_SPACE;
    arvore->raiz->info = info;
    arvore->raiz->fdir = arvore->raiz->fesq = NULL;
    return OK;
}

TAtomo *localizar(TAtomo *raiz, int chaveBusca)
{
    TAtomo *res1, *res2;
    if(raiz == NULL) return NULL;
    if(raiz->info.chave == chaveBusca) return raiz;
    res1 = localizar(raiz->fesq, chaveBusca);
    res2 = localizar(raiz->fdir, chaveBusca);
    if(res1 != NULL) return res1;
    if(res2 != NULL) return res2;
    return NULL;
}
/*
TAtomo *preOrdemIterativo (TAtomo *raiz, int chavePai)
{
    if (raiz == NULL) return NULL;
    TAtomo *paux = raiz;
    TPilhaDinamic *pilha;
    iniciaPilhaDinamica(&pilha);
    do{
        
        while (paux != NULL)
        {
            if(paux->info.chave == chavePai)return raiz;
            int codret = empilhar(pilha,paux->info);
            if (codret == NO_SPACE)
            {
                destruirPilha (&pilha);
                return NULL;
            }
                paux = paux->fesq;

       }
       desempilhar (&pilha,paux->info);
        paux = paux->fdir;
    }
    while(pilha->topo != NULL || paux != NULL)
    return NULL;

}
*/

TAtomo *localizar1 ( TAtomo *raiz, int chavePai)
{
    TAtomo *res1 = raiz;
    if(raiz == NULL) return NULL;
    if(raiz->info.chave == chavePai) return raiz;
    while(raiz->fesq != NULL)
    {
        if(raiz->fesq->info.chave == chavePai) return raiz;
        raiz = raiz->fesq;
    }
    raiz = res1;
     while(raiz->fdir!= NULL)
    {
        if(raiz->fdir->info.chave == chavePai) return raiz;
        raiz = raiz->fdir;
    }
    return NULL;

}

int numDescendentes(TAtomo *paux, int pvez)
 { 
    if(pvez == 1) 
      return numDescendentes(paux->fesq, 0) + numDescendentes(paux->fdir,0); 
   if(paux == NULL) return 0;
   return 1 + numDescendentes(paux->fesq,0) + numDescendentes(paux->fdir,0);     
 }


void visitaAtomo (int x)
{
    printf(" %d \n" , x);
}

void preOrdemRecursivo (TAtomo *raiz)
{
    if ( raiz != NULL)
    {
        visitaAtomo (raiz->info.chave);
        preOrdemRecursivo (raiz->fesq);
        preOrdemRecursivo (raiz->fdir);
    }
}

boolean vaziaArvoreBinaria(TAB *arvore)
{
    return arvore->raiz == NULL;
}

int inserirFilhoEsquerdo(TAB * arvore, TInfo info , int chavePai)
{
    if(vaziaArvoreBinaria(arvore))
        criarAtomoRaiz(arvore,info);
    TAtomo  *pai = localizar(arvore->raiz, chavePai);
    if(pai == NULL) return NOT_FOUND;
    if(pai->fesq != NULL) return DESCENDING_FOUND;
    TAtomo *pfilho = (TAtomo*) malloc(sizeof(TAtomo));
    if(pfilho == NULL) return NO_SPACE;
    pfilho->info = info;
    pfilho->fesq = pfilho->fdir = NULL;
    pai->fesq = pfilho;
    return OK;

}

int inserirFilhoDireito(TAB * arvore, TInfo info , int chavePai)
{
    if(vaziaArvoreBinaria(arvore))
        criarAtomoRaiz(arvore,info);
    TAtomo  *pai = localizar(arvore->raiz, chavePai);
    if(pai == NULL) return NOT_FOUND;
    if(pai->fdir != NULL) return DESCENDING_FOUND;
    TAtomo *pfilho = (TAtomo*) malloc(sizeof(TAtomo));
    if(pfilho == NULL) return NO_SPACE;
    pfilho->info = info;
    pfilho->fesq = pfilho->fdir = NULL;
    pai->fdir = pfilho;
    return OK;

}

int removerE(TAtomo *pai, TInfo *info)
{
    TAtomo *pdel = pai->fesq;
    if(pdel->fesq == NULL && pdel->fdir == NULL)
    {
        *info = pdel->info;
        pdel->fesq = NULL;
        free(pdel);
        return OK;
    }
    return NOT_LEAF;
}

int removerD(TAtomo *pai, TInfo *info)
{
    TAtomo *pdel = pai->fdir;
    if(pdel->fesq == NULL && pdel->fdir == NULL)
    {
        *info = pdel->info;
        pdel->fdir = NULL;
        free(pdel);
        return OK;
    }
    return NOT_LEAF;
}


int removerFolha(TAB *arvore, int chavePai, int chaveFilho,TInfo *info)
{
    if(vaziaArvoreBinaria(arvore)) return TREE_EMPTY;
    TAtomo *pai = localizar(arvore->raiz,chavePai);
    if(pai == NULL) return NOT_FOUND;
    if(pai->fesq == NULL && pai->fdir == NULL) return FATHER_WITHOUT_CHILD;
    if(pai->fesq != NULL && pai->fesq->info.chave == chavePai )
    {
        TAtomo *pdel = pai->fesq;
        if(pdel->fesq == NULL && pdel->fdir == NULL)
        {
            *info = pdel->info;
            pai->fesq = NULL;
            free(pdel);
            return OK;
        }
        return NOT_LEAF;
    }
    
    if(pai->fdir != NULL && pai->fdir->info.chave == chavePai)
    {
        TAtomo *pdel = pai->fdir;
        if(pdel->fesq != NULL && pdel->fdir != NULL)
        {
            *info = pdel->info;
            pai->fdir = NULL;
            return OK;
        }
        return NOT_LEAF;
    }

    return NOT_FOUND; 
}

int numFolhas(TAtomo *raiz)
{
    if(raiz == NULL) return 0;
    if(raiz->fesq == NULL && raiz->fdir == NULL)
        return 1 + numFolhas(raiz->fesq) + numFolhas(raiz->fdir);
    return numFolhas(raiz->fesq) + numFolhas(raiz->fdir);    
}

int numFolhasEsquerdas(TAtomo *raiz)
{
    if(raiz == NULL) return 0;
    if(raiz->fesq == NULL && raiz->fdir == NULL)
        return 1 + numFolhas(raiz->fesq) + numFolhas(raiz->fdir->fesq);
    return numFolhas(raiz->fesq) + numFolhas(raiz->fdir->fesq);    
}

int compara(int num1, int num2)
{
    if(num1 <= num2) return num1;
    return num2;
}

int valorMinimo(TAtomo *raiz)
{
   int rData = raiz->info.chave;
   if(raiz == NULL) return 0;
   if(raiz->fesq == NULL && raiz->fdir == NULL) return raiz->info.chave;
   int maxe = compara(raiz->info.chave,valorMinimo(raiz->fesq));
   int maxd = compara(raiz->info.chave, valorMinimo(raiz->fdir));
   return compara(compara(maxe, maxd),rData) ;
}

boolean folha(TAtomo *raiz)
{
    if(raiz == NULL) return FALSE;
    if(raiz->fesq == NULL && raiz->fdir == NULL) return TRUE;
    return FALSE;
    
}

TAtomo *folhaEsq(TAtomo *raiz)
{
    TAtomo *leafEsq, *leafDir;
    if(raiz == NULL) return NULL;
    if(folha(raiz->fesq))  
        return raiz->fesq;
    leafEsq = folhaEsq(raiz->fesq);
    leafDir = folhaEsq(raiz->fdir);
    if(leafEsq != NULL) return leafEsq;
    if(leafDir != NULL) return leafDir;
    return NULL;
}

TAtomo *pointFolha(TAtomo *raiz)
{

    TAtomo *leafEsq, *leafDir;
    if(raiz == NULL) return NULL;
    if(raiz->fesq == NULL && raiz->fdir == NULL) return raiz;

    leafEsq = pointFolha(raiz->fesq);
    leafDir = pointFolha(raiz->fdir);

    if(leafEsq != NULL) return leafEsq;
    if(leafDir != NULL) return leafDir;
    return NULL;
}

int inserirFilhoEsqSemChavePai(TAB *arvore, TInfo info)
{
    if(vaziaArvoreBinaria(arvore))
        return criarAtomoRaiz(arvore,info);
    TAtomo *pFolhaEsq = folhaEsq(arvore->raiz);
    if(pFolhaEsq == NULL) return NOT_LEAF;

    TAtomo *pfilho = (TAtomo *) malloc(sizeof(TAtomo));

    if(pfilho == NULL) return NO_SPACE;

    pfilho->info = info;
    pfilho->fdir = pfilho->fesq = NULL;
    pFolhaEsq->fesq = pfilho;
    return OK;
}

/*
int inserirFilhoEsquerdo(TAB * arvore, TInfo info , int chavePai)
{
    if(vaziaArvoreBinaria(arvore))
        criarAtomoRaiz(arvore,info);
    TAtomo  *pai = localizar(arvore->raiz, chavePai);
    if(pai == NULL) return NOT_FOUND;
    if(pai->fesq != NULL) return DESCENDING_FOUND;
    TAtomo *pfilho = (TAtomo*) malloc(sizeof(TAtomo));
    if(pfilho == NULL) return NO_SPACE;
    pfilho->info = info;
    pfilho->fesq = pfilho->fdir = NULL;
    pai->fesq = pfilho;
    return OK;

}
*/
int numNaoFolhas(TAtomo *raiz)
{
    if(raiz == NULL) return 0;
    if(raiz->fesq != NULL || raiz->fdir != NULL)
        return 1+ numNaoFolhas(raiz->fesq) + numNaoFolhas(raiz->fdir);
    return numNaoFolhas(raiz->fesq) + numNaoFolhas(raiz->fdir);    
}

boolean opostasArvore(TAtomo *raiz1, TAtomo *raiz2 )
{
   if(raiz1 == NULL && raiz2 == NULL) return TRUE;
   if(raiz1 != NULL && raiz2!= NULL)
   {      if(raiz1->info.chave == raiz2->info.chave) 
            return opostasArvore(raiz1->fesq,raiz2->fdir) && opostasArvore(raiz1->fdir,raiz2->fesq);
         return FALSE;   
   }
   return FALSE;
}

boolean iguaisArvore(TAtomo *raiz1, TAtomo *raiz2 )
{
   if(raiz1 == NULL && raiz2 == NULL) return TRUE;
   if(raiz1 != NULL && raiz2!= NULL)
   {     if(raiz1->info.chave == raiz2->info.chave)  
            return iguaisArvore(raiz1->fesq,raiz2->fesq) && iguaisArvore(raiz1->fdir,raiz2->fdir);
         return FALSE;   
   }
   return FALSE;
}

/*
TAtomo *localizar(TAtomo *raiz, int chaveBusca)
{
    TAtomo *res1, *res2;
    if(raiz == NULL) return NULL;
    if(raiz->info.chave == chaveBusca) return raiz;
    res1 = localizar(raiz->fesq, chaveBusca);
    res2 = localizar(raiz->fdir, chaveBusca);
    if(res1 != NULL) return res1;
    if(res2 != NULL) return res2;
    return NULL;
}
*/

/*int profundidade(TAtomo *raiz)
{
    int alte, altd;
    if(raiz == NULL) return 0;
   alte = profundidade(raiz->fesq);
   altd = profundidade(raiz->fdir);

   if(alte > alte) return alte+1;
   return altd+1;

   
}


int nivelArvore(TAtomo *raiz,int chaveBusca,int nivel)
{
    if(raiz == NULL) return -1;
    if(raiz->info.chave == chaveBusca) return nivel;

    return nivelArvore(raiz,chaveBusca,nivel+1) + nivelArvore(raiz,chaveBusca,nivel+1);
}
*/
boolean ehBinaria(TAtomo *raiz)
{
    if(raiz == NULL) return TRUE;
    if(raiz->info.chave > raiz->fesq->info.chave && raiz->info.chave < raiz->fdir->info.chave) 
        return ehBinaria(raiz->fesq) && ehBinaria(raiz->fdir);
    return FALSE;    
}

int main()
{
    TAB arvore;
    TAtomo *raiz1, *raiz2;
    TAtomo *paux; 
    TInfo info,a,b,c,d,e,f,g,h,i,j;
    info.chave = 15;
    a.chave = 17;
    b.chave = 3;
    c.chave = 4;
    d.chave = 5;
    e.chave = 6;
    f.chave = 7;
    g.chave = 8;
    h.chave = 9;
    i.chave = 10;
    j.chave = 11;
    criaArvoreBinaria(&arvore);
    criarAtomoRaiz(&arvore,info);
   /* inserirFilhoEsquerdo(&arvore,a,info.chave);
    inserirFilhoDireito(&arvore,b,info.chave);
    inserirFilhoEsquerdo(&arvore,c,a.chave);
    inserirFilhoDireito(&arvore,d,a.chave);
    inserirFilhoEsquerdo(&arvore,f,c.chave);
    inserirFilhoEsquerdo(&arvore,g,c.chave);*/

    raiz1 = arvore.raiz;
    //printf("A profundidade é: %d\n",profundidade(raiz1));


    preOrdemRecursivo(arvore.raiz);

     
    
  
    
    
}
