#include <stdio.h>
#include <stdlib.h>
#define NOT_FOUND -1 // O Item não existe
#define OK         0 // Operação realizada com sucesso
#define LIST_EMPTY 2 // Lista Vazia
#define NO_SPACE   3 // Não há espaço de memória


typedef enum {FALSE=0,TRUE = 1}boolean;

typedef struct 
{
    int chave;
    int valor;

}TInfo;

typedef struct Atomo
{
    TInfo info;
    struct Atomo *eprox;
    struct Atomo *dprox;
}TAtomo;

typedef struct 
{ 
    TAtomo *primeiro;
    TAtomo *ultimo;    
}TLDEnc;

void criarListaEncadeada(TLDEnc *lista)
{
    lista->primeiro = NULL;
    lista->ultimo = NULL;
}

boolean vaziaLista(TLDEnc *lista){

    return (lista->primeiro == NULL);
}

void imprimirLista(TLDEnc *lista)
{
    if(!vaziaLista(lista))
    {
        for(TAtomo *paux = lista->primeiro; paux != NULL; paux = paux->dprox)
            printf("%d ->", paux->info.chave);
        printf("\n");   
    }
}

boolean listaUnitaria(TLDEnc *lista)
{
    return lista->primeiro == lista->ultimo;
}
int inserirAtomo(TLDEnc *lista, TInfo info)
{
    TAtomo *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
    if(pnovo == NULL) return NO_SPACE;
    pnovo->info = info;
    pnovo->dprox = NULL;
    if(vaziaLista(lista)) lista->primeiro = pnovo;
    else if(listaUnitaria(lista))
    { 
        lista->primeiro->dprox = pnovo;
        pnovo->eprox = lista->primeiro;

    }
    else 
    {   
         lista->ultimo->dprox = pnovo;
         pnovo->eprox = lista->ultimo;
    }

    lista->ultimo = pnovo;
    return OK;
}

int inserirInicio(TLDEnc *lista, TInfo info)
{
    TAtomo *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
    if(pnovo == NULL) return NO_SPACE;
    pnovo->info = info;
    pnovo->eprox = NULL;
    if(vaziaLista(lista)) lista->ultimo = pnovo;
    else {
        lista->primeiro->eprox = pnovo;
        pnovo->dprox = lista->primeiro;
    }
    lista->primeiro = pnovo;
    return OK;
}

int removerAtomo(TLDEnc *lista, TInfo *info)
{
    if(vaziaLista(lista)) return LIST_EMPTY;
    else if(listaUnitaria(lista)) criarListaEncadeada(lista);
     TAtomo *pdel = lista->ultimo;
     lista->ultimo = pdel->eprox;
     lista->ultimo->dprox = NULL;
     free(pdel);
     return OK;
}



TAtomo *busca(TLDEnc *lista, int chave)
{
    TAtomo *paux = lista->primeiro;
    while(paux != NULL && paux->info.chave != chave)    
        paux = paux->dprox;
    if(paux == NULL) return NULL;
    return paux;
}

int dividirEmDuas(TLDEnc *lista, TLDEnc *novaLista, int chave)
{
    if(vaziaLista(lista)) return LIST_EMPTY;
    TAtomo *pchave = busca(lista,chave), *paux = pchave, *p1 = lista->primeiro;
    if(pchave == NULL) return NOT_FOUND;
    while(paux != NULL)
    {
        inserirAtomo(novaLista, paux->info);
        paux = paux->dprox;
    }
    criarListaEncadeada(lista);
    while(p1 != pchave)
    {
        inserirAtomo(lista,p1->info);
        p1 = p1->dprox;
    }
    return OK;

}


int main()
{
    TLDEnc lista, lista1;
    TInfo a = {2,3},b = {3,4}, c = {4,5},d = {5,6}, e = {6,7},f = {7,8},g = {8,9}, h = {9,10};
    criarListaEncadeada(&lista);
    criarListaEncadeada(&lista1);
    inserirInicio(&lista,a);
    inserirInicio(&lista,b);
    inserirInicio(&lista,c);
    inserirInicio(&lista,d);
    imprimirLista(&lista);

    dividirEmDuas(&lista,&lista1,2);
    imprimirLista(&lista);
     imprimirLista(&lista1);




}