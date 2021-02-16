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
    TAtomo *ultimo;
}TLEnc;

typedef enum {FALSE = 0, TRUE= 1} Boolean; 

void criarListaEncadeada(TLEnc *lista)
{
    lista->cabeca = NULL;
    lista->ultimo = NULL;
}

Boolean vaziaLista(TLEnc *lista)
{
    return lista->cabeca == NULL;
}



void imprimirListaEncandeada(TLEnc *lista){

    for(TAtomo *paux = lista->cabeca->prox; paux != NULL ; paux = paux->prox)
        printf("%d -> ",paux->info.chave);
     printf(" \n");   
}


int inserirAtomo(TLEnc *lista, TInfo info)
{
    TAtomo *pnovo = (TAtomo *) malloc(sizeof(TAtomo));
    if(pnovo == NULL) return NO_SPACE;
    pnovo->info;
    pnovo->prox = NULL;
    if(vaziaLista(lista)) 
        lista->cabeca->prox = lista->ultimo = pnovo;

     else 
         lista->ultimo->prox = pnovo;

     lista->ultimo = pnovo;    
     return OK;  
}

int main()
{

    TLEnc lista;
    TInfo a = {2,3},b = {3,4}, c = {4,5},d = {5,6}, e = {6,7},f = {7,8},g = {8,9}, h = {9,10};
    criarListaEncadeada(&lista);
    inserirAtomo(&lista,a);
    inserirAtomo(&lista,b);
    inserirAtomo(&lista,c);
    inserirAtomo(&lista,d);
    imprimirListaEncandeada(&lista);
}
