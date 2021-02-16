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

    TAtomo *primeiro;

}TLCirc;

typedef enum {FALSE = 0, TRUE= 1} Boolean; 

void criarListaCircular(TLCirc *lista)
{
    lista->primeiro = NULL;
    //lista->primeiro->prox = NULL;
}

int vaziaLista(TLCirc *lista)
{
    return lista->primeiro == NULL;
}


int inserirAtomoDireita(TLCirc *lista, TInfo info)
{
    TAtomo *pnovo = (TAtomo *) malloc(sizeof(TAtomo));

    if(pnovo == NULL) return NO_SPACE;
    pnovo->info = info;

    if(vaziaLista(lista))
    { 
        lista->primeiro = pnovo;
        pnovo->prox = lista->primeiro->prox = lista->primeiro;
    }
    else    
    {
        pnovo->prox = lista->primeiro->prox;
        lista->primeiro->prox = pnovo;
    }
    return OK;
}

void imprimirLista(TLCirc *lista)
{
    TAtomo *paux = lista->primeiro;
    if(!vaziaLista(lista))
    {
        do{

            printf("%d ->", paux->info.chave);
            paux = paux->prox;
        }
        while(paux != lista->primeiro);

        printf("\n");
    }    
}

int removerAtomoDireita(TLCirc *lista, TInfo info)
{
    if(vaziaLista(lista)) return LIST_EMPTY;

    TAtomo *pdel = lista->primeiro->prox;
    info = pdel->info;

    if(pdel->info.chave == lista->primeiro->info.chave) criarListaCircular(lista);
    else if(pdel->prox->info.chave == lista->primeiro->info.chave) lista->primeiro->prox = lista->primeiro;
    else lista->primeiro->prox = pdel->prox;
       
    free(pdel);
    return OK;
}



int vezesRepetidas(TLCirc *lista, int valor)
{
    TAtomo  *paux = lista->primeiro;
    int num = 0;
    do{
        if(paux->info.valor == valor) num++;
        paux = paux->prox;

    }while(paux != lista->primeiro);

    return num;
}

int removerDadoValor(TLCirc *lista, int valor)
{
    if(vaziaLista(lista)) return LIST_EMPTY;
    TAtomo *paux = lista->primeiro, *pdel, *pant = NULL;
    int numVezesRepet = vezesRepetidas(lista, valor);

    while(numVezesRepet > 0)
    {
        if(paux->info.valor == valor)  
        {    
            pdel = paux;
            if(pdel->info.chave == lista->primeiro->info.chave)
                lista->primeiro = lista->primeiro->prox;
            else pant->prox = pdel->prox;

            pant = NULL;
            paux = lista->primeiro;
            free(pdel);
            numVezesRepet--;
        }
        else
        {
            pant = paux;
            paux = paux->prox;
        }
    
    }

    return OK;
}




int main()
{
    TLCirc lista;
    TInfo a = {2,4},b = {3,3}, c = {4,5},d = {5,4}, e = {6,4},f = {7,8},g = {8,9}, h = {9,10};
    criarListaCircular(&lista);
    inserirAtomoDireita(&lista,a);
    inserirAtomoDireita(&lista,b);
    inserirAtomoDireita(&lista,c);
    inserirAtomoDireita(&lista,d);
    inserirAtomoDireita(&lista,e);
    inserirAtomoDireita(&lista,f);
    inserirAtomoDireita(&lista,g);
    inserirAtomoDireita(&lista,h);
    imprimirLista(&lista);

    removerDadoValor(&lista,4);
    imprimirLista(&lista);
}