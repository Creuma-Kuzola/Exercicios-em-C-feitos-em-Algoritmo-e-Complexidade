#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
}TFila;

typedef enum { FALSE=0, TRUE = 1}boolean;

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

int inserirElemento(TFila *fila, TItem item)
{
    if(cheiaFila(fila)) return QUEUE_FULL;
    fila->fundo++;
    fila->item[fila->fundo] = item;
    return OK;
}

int inserirElemento1(TFila *fila, int x)
{
    if(cheiaFila(fila)) return QUEUE_FULL;
    fila->fundo++;
    fila->item[fila->fundo].valor = x;
    return OK;
}

int removerElemento(TFila *fila, TItem *x)
{
    if(vaziaFila(fila)) return QUEUE_EMPTY;
    fila->frente++;
    *x = fila->item[fila->frente];
    if(fila->frente == fila->fundo) criarFila(fila);
    return OK;
}

int copiar(TFila filaOrigem, TFila *filaDestino)
{
    TItem x;
    if(vaziaFila(&filaOrigem)) return QUEUE_EMPTY;
    criarFila(filaDestino);
    while(!vaziaFila(&filaOrigem))
    {
        removerElemento(&filaOrigem,&x);
        inserirElemento(filaDestino,x);
    }
}

int imprimirFila(TFila *fila)
{
    vaziaFila(fila);
    for(int i=0; i<=fila->fundo;i++)
        printf("%d \n", fila->item[i].valor);
     return OK;   
}

int totalElem(TFila *fila)
{
    return(fila->fundo - fila->frente);
}


int removerFilaComoPilha(TFila *fila)
{
    int tot = totalElem(fila), i=0;
    TItem v[tot],x;
    if(vaziaFila(fila)) return QUEUE_EMPTY;
    while(!vaziaFila(fila))
    {
        removerElemento(fila,&x);
        v[i] = x;   
        i++;    
    }
    criarFila(fila);
    for(int i=0;i<tot-1;i++)
         inserirElemento(fila,v[i]);
    return OK;     

}

int main()
{
    TFila fila, f1;
    TItem x,y,z;
    x.valor = 1; y.valor = 2; z.valor = 3;
    criarFila(&fila);
    criarFila(&f1);
    inserirElemento(&fila,x);
    inserirElemento(&fila,y);
    inserirElemento(&fila,z);

    copiar(fila,&f1);   
    imprimirFila(&fila);

    printf("Cópia\n");
    imprimirFila(&f1);

    

}