#include <stdio.h>
#include <stdlib.h>
#define NOT_FOUND       -1
#define OK               1
#define TREE_EMPTY       2
#define NO_SPACE         5

typedef struct 
{
    int chave;
    int valor;
}TInfo;

typedef struct Atomo
{
    TInfo info;
    struct Atomo *fesq;
    struct Atomo *fdir;
    struct Atomo *pai;
} TAtomo;

typedef struct
{
    TAtomo *raiz;
}TABB;

typedef enum {FALSE= 0, TRUE= 1} Boolean;

void criarArvore(TABB *arvore)
{
    arvore->raiz = NULL;
}

int estaVaziaArvore(TABB *arvore)
{
    return arvore->raiz == NULL;
}

TAtomo *busca(TABB *arvore, int chaveBusca)
{ 
    TAtomo *pBusca = arvore->raiz;
    while(pBusca != NULL)
    {
        if(pBusca->info.chave == chaveBusca) return pBusca;
        if(pBusca->info.chave >chaveBusca ) pBusca = pBusca->fesq;
        else pBusca = pBusca->fdir;
    }
    return NULL;
}

TAtomo *buscaRec (TAtomo *pBusca, int chaveBusca)
{
    if(pBusca == NULL) return NULL;
    if(pBusca->info.chave == chaveBusca) return pBusca;
    if(pBusca->info.chave > pBusca->info.chave) return buscaRec(pBusca->fesq, chaveBusca);
    return buscaRec(pBusca->fdir,chaveBusca);
}

int inserirAtomo(TABB *arvore, TInfo info)
{
    TAtomo *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
    if(pnovo == NULL) return NO_SPACE;
    
    pnovo->fesq = pnovo->fdir = NULL;
    pnovo->info = info;
    if(estaVaziaArvore(arvore))
    { 
       pnovo->pai = NULL;
       arvore->raiz = pnovo;
    }
    else
    {
        TAtomo *pPai = NULL, *paux = arvore->raiz;
        while(paux != NULL)
        {
            pPai = paux;
            if(paux->info.chave > pnovo->info.chave) paux = paux->fesq;
            else paux = paux->fdir;
        }

        pnovo->pai = pPai;

        if(pPai->info.chave > pnovo->info.chave ) pPai->fesq = pnovo;
        else pPai->fdir = pnovo;
    }

    return OK;
}

void visitaAtomo (int x)
{
    printf(" %d \n" , x);
}


void imprimir (TAtomo *raiz)
{
    if ( raiz != NULL)
    {
        visitaAtomo (raiz->info.chave);
        imprimir (raiz->fesq);
        imprimir (raiz->fdir);
    }
}


int removerComPeloMenosUmFilho(TABB *arvore, TAtomo *pdel,TAtomo *paiPdel, TInfo *x)
{
    TAtomo *filho;

    if(estaVaziaArvore(arvore)) return TREE_EMPTY;
    if(pdel->fesq == NULL && pdel->fdir == NULL) filho = NULL;
    else if(pdel->fesq != NULL) filho = pdel->fesq;
    else filho = pdel->fdir;

    if(paiPdel != NULL)
    {
        if(pdel == paiPdel->fesq) paiPdel->fesq = filho;
        else paiPdel->fdir = filho;
    }
    else
        arvore->raiz = filho;

    *x = pdel->info;
    free(pdel);
    return OK;
}

int tipoRemover(TAtomo *pdel)
{
    if(pdel->fesq == NULL && pdel->fdir == NULL) return 1;
    if(pdel->fesq != NULL || pdel->fdir != NULL) return 2;
    return 3;
}

TAtomo *noMaisAEsquerda(TABB *arvore, TAtomo *pdel)
{
    if(pdel->fesq!= NULL)
    {
        pdel = pdel->fdir;
    }
    return pdel;
}

int removerArvore(TABB *arvore,TAtomo *pdel,TAtomo *paiPdel, TInfo *x )
{
    TAtomo *ptr = pdel->fesq,*paiPtr = pdel;
      printf("ptr: %d\n",ptr->info.chave);
    if(estaVaziaArvore(arvore)) return TREE_EMPTY;

    if(pdel->fesq != NULL && pdel->fdir != NULL)
    {   
        while(ptr->fdir!= NULL)
        {
            paiPtr = ptr;
            ptr = ptr->fdir; 
        }
         printf("ptr: %d\n",ptr->info.chave);
         printf("pdel:%d",pdel->info.chave);
          
        if(paiPdel != NULL)
        {
            if(pdel == paiPdel->fesq) paiPdel->fesq = ptr;
            else paiPdel->fdir = ptr;
            ptr->pai = paiPdel;
            ptr->fdir= NULL;
            ptr->fesq = pdel->fdir;
        }
         else 
         {
            TAtomo *pRaiz =  arvore->raiz;
            if(ptr == paiPtr->fdir)
            {
                ptr->fesq = pdel->fesq;
                ptr->fdir = pdel->fdir;
                ptr->pai = NULL;
                arvore->raiz = ptr;
                paiPtr->fdir = NULL;
                paiPtr->pai = ptr;

                printf("Creuma1");

            }else
              printf("Creuma");
         }
        free(pdel);
        return OK;
    }

    return removerComPeloMenosUmFilho(arvore,pdel,paiPdel,x);   
}

Boolean ehBinaria(TAtomo *raiz)
{
    if(raiz == NULL) return TRUE;
    if((raiz->info.chave > raiz->fesq->info.chave) && (raiz->info.chave < raiz->fdir->info.chave)) 
        return ehBinaria(raiz->fesq) && ehBinaria(raiz->fdir);
    return FALSE;    

}

int main()
{
    TABB arvore;
    TAtomo *pdel,*paiPDel,*raiz;
    TInfo a,b,c,d,e,f,g;
    a.chave = 10;
    b.chave = 1;
    c.chave = 5;
    d.chave = 2;
    e.chave = 15;
    f.chave = 11;
    g.chave = 14;
    criarArvore(&arvore);
    inserirAtomo(&arvore,a);
    inserirAtomo(&arvore,d);
    inserirAtomo(&arvore,b);
    inserirAtomo(&arvore,c);
    inserirAtomo(&arvore,e);
    inserirAtomo(&arvore,f);
    inserirAtomo(&arvore,g);
    raiz = arvore.raiz;
    imprimir(raiz);
    printf("\n%d\n: ",ehBinaria(raiz));

   /* printf("\n\n\n");
    imprimir(raiz);

    pdel = busca(&arvore,15);
    paiPDel = pdel->pai;
    
    removerArvore(&arvore,pdel,paiPDel,&d);
    printf("\n\n\n");
    imprimir(raiz);

     pdel = busca(&arvore,10);
    paiPDel = pdel->pai;
    
    removerArvore(&arvore,pdel,paiPDel,&d);
    printf("\n\n\n");
    imprimir(raiz);*/


}