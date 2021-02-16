#include <stdio.h>
#include <stdlib.h>
#define NOT_FOUND       -1
#define OK               0
#define LIST_EMPTY       2
#define NO_SPACE         3
#define IMPOSSIBLE_REMOTION  4
#define IMPOSSIBLE_INVERTION 5

typedef struct Info {

    int chave;
    int valor;

}TInfo;

typedef struct Atomo{

    TInfo info;
    struct Atomo * prox;

}TAtomo;

typedef struct{

    TAtomo *cabeca;

}TLCirc;

typedef enum {FALSE = 0, TRUE= 1} Boolean; 

void criarListaCircularCabeca(TLCirc *lista)
{
    lista->cabeca = (TAtomo *) malloc(sizeof(TAtomo));
    if(lista->cabeca != NULL) lista->cabeca->prox = lista->cabeca;
}

Boolean vaziaLista(TLCirc *lista)
{
    return lista->cabeca == lista->cabeca->prox;
}

Boolean inserirAtomoDireita(TLCirc *lista, TInfo info)
{
    TAtomo *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
    if(pnovo == NULL) return NO_SPACE;
    pnovo->info = info;
    if(vaziaLista(lista))
    {
        lista->cabeca->prox = pnovo;
        pnovo->prox = lista->cabeca;
    }
    else
    {
        pnovo->prox = lista->cabeca->prox;
        lista->cabeca->prox = pnovo;
    }
    
    return OK;
}


void imprimirListaCabeca(TLCirc *lista)
{
    if(!vaziaLista(lista))
    {
        TAtomo *paux = lista->cabeca->prox;
        do{
            printf("%d ->", paux->info.chave);
            paux = paux->prox;
        }while(paux != lista->cabeca);
        printf("\n");
    
    }   
}


int removerDireita(TLCirc *lista,TInfo *info)
 {
     if(vaziaLista(lista)) return LIST_EMPTY;
     TAtomo *paux =lista->cabeca->prox ,*pdel = lista->cabeca->prox->prox;
     *info = pdel->info;

    if (pdel == lista->cabeca) 
        lista->cabeca->prox = lista->cabeca;    
    else if(paux->prox == pdel && pdel->prox == lista->cabeca)       
              lista->cabeca->prox->prox = lista->cabeca;
          else  lista->cabeca->prox->prox = pdel->prox;

    
     free(pdel);
     return OK;
 }

TAtomo *busca(TLCirc *lista, int chave)
{
    if(vaziaLista(lista)) return NULL;

    TAtomo *paux = lista->cabeca->prox;
    do{
        
         if(paux->info.chave == chave) return paux;
         paux = paux->prox;

    }while(paux != lista->cabeca);
    return NULL;


}   


int main()
{

    TLCirc lista;
    TInfo a = {2,3},b = {3,4}, c = {4,5},d = {5,6}, e = {6,7},f = {7,8},g = {8,9}, h = {9,10};
    TAtomo *paux;
    criarListaCircularCabeca(&lista);
    inserirAtomoDireita(&lista,a);
    inserirAtomoDireita(&lista,b);
    inserirAtomoDireita(&lista,c);
    inserirAtomoDireita(&lista,d);
    imprimirListaCabeca(&lista);

    paux = busca(&lista,d.chave);
    printf("paux:%d && paux->prox:%d\n",paux->info.chave, paux->prox->info.chave);
    
    

}
