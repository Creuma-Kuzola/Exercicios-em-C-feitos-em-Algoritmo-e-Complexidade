#include <stdio.h>
#include <stdlib.h>
#define OK           0
#define QUEUE_FULL   1
#define QUEUE_EMPTY  2
#define NO_MEMORY    3
#define TAM          100

typedef struct
{
    int valor;
}TItem;

typedef struct
{
    TItem item[TAM];
    int frente;
    int fundo;
    int tamanho;
}TFilaCircular;

void criarFila(TFilaCircular *fila)
{
    fila->frente = fila->fundo = TAM/2;
    fila->tamanho = 0;
}

int vaziaFila(TFilaCircular *fila)
{
    return(fila->tamanho == 0);
}

int cheiaFila(TFilaCircular *fila)
{
    return (fila->tamanho == TAM);
}

int inserirElemento(TFilaCircular *fila,int x)
{
    if(cheiaFila(fila)) return QUEUE_FULL;
    fila->fundo = (fila->fundo +1)% TAM;
    fila->tamanho++;
    fila->item[fila->fundo].valor = x; 
    return OK;
}

int removerElemento(TFilaCircular *fila, int *x)
{
    if(vaziaFila(fila)) return QUEUE_EMPTY;
    fila->frente = (fila->frente+1)%TAM;
    *x = fila->item[fila->frente].valor;
    fila->tamanho--;
    
    
}

int imprimirFila(TFilaCircular *fila)
{
    int j=0, aux;
    if(vaziaFila(fila)) return QUEUE_EMPTY;
    if(fila->frente < fila->fundo)   
        for(int i = fila->frente; i<= fila->fundo;i++)
            printf("%d \n", fila->item[i].valor);    
    else if(fila->frente > fila->fundo)
    {
        aux = TAM - fila->frente+1;
        for(int i = fila->frente; i< TAM ;i++)
            printf("%d \n", fila->item[i].valor);  
        aux = fila->tamanho - aux;
        while(aux !=0)
        {
            printf("%d \n", fila->item[j].valor);
            aux--;
            j++;
        }

    } 

    return OK;   
}

int main()
{

    TFilaCircular fila;
    int x,y,z,l;
    x = 1; y = 2; z = 3;
    criarFila(&fila);
    inserirElemento(&fila,x);
    inserirElemento(&fila,y);
    inserirElemento(&fila,z);
    imprimirFila(&fila);
    removerElemento(&fila,&l);
    printf("\n");
    imprimirFila(&fila);
}