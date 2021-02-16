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
    
}TLDCirc;


void criarListaCircular(TLDCirc *lista)
{
    lista->primeiro = NULL;
}

int vaziaLista(TLDCirc *lista)
{
    return lista->primeiro == NULL;
}

int listaUnitaria(TLDCirc *lista)
{
   return lista->primeiro->dprox == lista->primeiro;
}

int inserirAtomo(TLDCirc *lista, TInfo info)
{
    TAtomo *pnovo = (TAtomo*) malloc(sizeof(TAtomo));
    if(pnovo == NULL) return NO_SPACE;
    pnovo->info = info;
    if(vaziaLista(lista))
    {
        lista->primeiro = pnovo;
        lista->primeiro->dprox = lista->primeiro->eprox = pnovo;
    }
    else if(listaUnitaria(lista))
    {
        lista->primeiro->dprox = lista->primeiro->eprox = pnovo;
        pnovo->dprox = pnovo->eprox = lista->primeiro;
    }
    else
    {
        TAtomo *paux = lista->primeiro->dprox;
        lista->primeiro->dprox = pnovo;
        paux->eprox = pnovo;
        pnovo->dprox = paux;
        pnovo->eprox = lista->primeiro;
        
       
    }
    return OK;
    
}

int inserirAtomoFim(TLDCirc *lista, TInfo info)
{
    TAtomo *pnovo = (TAtomo*) malloc(sizeof(TAtomo));
    if(pnovo == NULL) return NO_SPACE;
    pnovo->info = info;
    if(vaziaLista(lista))
    {
        lista->primeiro = pnovo;
        lista->primeiro->dprox = lista->primeiro->eprox = pnovo;
    }
    else if(listaUnitaria(lista))
    {
        lista->primeiro->dprox = lista->primeiro->eprox = pnovo;
        pnovo->dprox = pnovo->eprox = lista->primeiro;
    }
    else
    {
        TAtomo *paux = lista->primeiro->eprox;
        paux->dprox = pnovo;
        pnovo->eprox = paux;
        pnovo->dprox = lista->primeiro;
        lista->primeiro->eprox = pnovo;
    }
    return OK;
    
}


void imprimir(TLDCirc *lista)
{
    TAtomo *paux = lista->primeiro;
    do{
        printf("%d ->", paux->info.chave);
        paux = paux->dprox;
    }while(paux != lista->primeiro);
    printf("\n");
}

int removerAtomo(TLDCirc *lista, TInfo *info)
{
    TAtomo *pdel = lista->primeiro->eprox, *paux = pdel->eprox;

    if(vaziaLista(lista)) return LIST_EMPTY;
    else if(listaUnitaria(lista))criarListaCircular(lista);
    else {
            lista->primeiro->eprox = paux;
            paux->dprox = lista->primeiro;
            *info = pdel->info;
            free(pdel);
    }
    
    return OK;

}

int juntarLista(TLDCirc *lista1, TLDCirc *lista2)
{
    if(vaziaLista(lista1) && vaziaLista(lista2)) return LIST_EMPTY;
    TAtomo *paux = lista2->primeiro;
    do{
            inserirAtomoFim(lista1,paux->info);
            paux = paux->dprox;
    }while(paux != lista2->primeiro);
}



int main()
{
    TLDCirc lista, lista1;
    TInfo a = {2,3},b = {3,4}, c = {4,5},d = {5,6}, e = {6,7},f = {7,8},g = {8,9}, h = {9,10};
    criarListaCircular(&lista);
    inserirAtomo(&lista,a);
    inserirAtomo(&lista,b);
    inserirAtomo(&lista,c);
    inserirAtomo(&lista,e);
    imprimir(&lista);

    criarListaCircular(&lista1);
    inserirAtomo(&lista1,d);
    inserirAtomo(&lista1,f);
    inserirAtomo(&lista1,g);
    inserirAtomo(&lista1,h);
    imprimir(&lista1);


    juntarLista(&lista,&lista1);
     imprimir(&lista);
}