#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20
#define troca2(x,y) {int aux=x;x=y;y=aux;}

typedef struct
{
    int chave,valor;
}TItem;

typedef struct
{
    TItem item[MAX];
    int nElem;
}TVet;

typedef enum {FALSE = 0, TRUE = 1}Boolean;

typedef struct
{
    int dia, mes, ano;
}TNascimento;

typedef struct 
{
    TNascimento dataNasc;
    char nome[50];
    char sexo;
}TPessoa;

void inicializarVetor(TVet *vet)
{
     vet->nElem = 0;
}

Boolean estaVazio(TVet vet)
{
    return vet.nElem == 0;
}

Boolean estaCheio(TVet vet)
{
    return vet.nElem == MAX;
}

Boolean estaContido(int ini,int fim,int pos)
{
    return pos>=ini && pos<=fim;
}

TItem acederElemento(TVet vet, int pos)
{
    if(estaContido(0,vet.nElem-1,pos))
        return vet.item[pos];
    else
        printf("\nErro: Impossível aceder elemento, posição inválida");    
}

/*int estaNoVetor(TVet vet,TItem x)
{
    int i;
    for(i=vet.nElem-1;i>=0 && vet.item[i].chave == x.chave;i--);
    return i;
}*/

void inserirDadoChave(TVet *vet,TItem x)
{
    vet->item[vet->nElem] = x;
    vet->nElem++;
}
void imprimirVetor(TVet vet)
{
    for(int i=0;i<vet.nElem;i++)
        printf("Chave:%d  Valor:%d\n",vet.item[i].chave,vet.item[i].valor);
}

void inserirDadaPosicao(TVet *vet,TItem x,int pos)
{
    if(!estaCheio(*vet))
    {    if(estaContido(0,vet->nElem-1,pos))
        {   for(int i=vet->nElem;i>=pos;i--)
                vet->item[i] = vet->item[i-1];
            vet->item[pos] = x;
            vet->nElem++;  
        }
        else
            printf("Erro: posição inválida");
    }
    else
        printf("Erro: O Vetor está cheio");
}

void removerDadaPosicao(TVet *vet,int pos)
{
    if(estaVazio(*vet))
        printf("Erro:Vetor vazio");
    else if(estaContido(0,vet->nElem-1,pos))
         {
             for(int i=pos;i<vet->nElem-1;i++)
                vet->item[i] = vet->item[i+1];
             vet->nElem--;   
         }
         else
            printf("Erro:Posição inválida");    
}

void inserirDadaChave(TVet *vet,TItem x)
{
    int i,j;
    if(estaCheio(*vet))
        printf("Erro: Vetor cheio");
    else
    {  
        for(i=0;i<vet->nElem && vet->item[i].chave < x.chave;i++);
        if(vet->item[i].chave == x.chave)
            printf("Erro: Chave já existente no vetor");
        else
        {
            for(j=vet->nElem;j>=i;j--)
                vet->item[j] = vet->item[j-1];
            vet->item[i] = x;  
            vet->nElem++;  
        }
    }    
        
}

void removerDadaChave(TVet *vet,TItem x)
{
    int i,j;
    if(estaVazio(*vet))
        printf("\nErro: Vetor vazio");
    else 
    {
        for(i=0;i<vet->nElem-1 && vet->item[i].chave < x.chave;i++);
        if(vet->item[i].chave == x.chave)
        {
            for(j=i;j<vet->nElem-1;j++)
                vet->item[j] = vet->item[j+1];
            vet->nElem--;   
            printf("\nChave:%d, removida com sucesso\n",x.chave); 
        }
        else
            printf("A chave:%d, não se encontra no vetor\n",x.chave);
    }    

}

TItem acederElemento1(TVet vet,int pos)
{
    TItem t;
    t.chave = -1; t.valor = 0;
    if(estaVazio(vet))
        printf("Erro: Vetor Vazio");
    else if(!estaContido(0,vet.nElem-1,pos))
            printf("Erro:Posição inválida\n");
         else
            t = vet.item[pos];

    return t;               
}

int ehDecrescente(TVet vet)
{
    int i;
    for(i=1;i<vet.nElem && vet.item[i-1].chave>vet.item[i].chave;i++);
    if(i == vet.nElem) return 1;
    return 0;
}

int ehDecrescenteRec1(TVet vet,int i)
{
    if(i==vet.nElem) return 1;
    if(vet.item[i-1].chave<vet.item[i].chave) return 0;
    return ehDecrescenteRec1(vet,i+1);
}

Boolean ehDecrescenteRec2(TVet vet,int i,int f)
{
    if(i==f)
        return (vet.item[i].chave>vet.item[i+1].chave);
    return ehDecrescenteRec2(vet,i,(i+f)/2)&&ehDecrescenteRec2(vet,((i+f)/2)+1,f);    
}

int estaNoVetor(TVet vet,TItem x)
{
    int i;
    for(i=0;i<vet.nElem && vet.item[i].chave != x.chave;i++);
    if(i == vet.nElem) return -1;
    return i;  
}

int estaNoVetorDecrescente(TVet vet, TItem x)
{
    int i;
    for(i=0;i<vet.nElem && vet.item[i].chave > x.chave;i++);
    if(i == vet.nElem)return -1;
    return i;
}

void inserirDadaChave1(TVet *vet,TItem x)
{
    if(estaCheio(*vet))
        printf("Erro: Vetor cheio\n");
    else if(estaNoVetor(*vet,x)!= -1)
            printf("Erro:Chave já inserida no vetor\n");
         else
        {
            vet->item[vet->nElem] = x;
            vet->nElem++;
        }   
}

void inserirDepoisDaChave(TVet *vet, TItem r1,TItem r2)
{
    if(estaVazio(*vet))
        printf("Erro:Vetor vazio");
    else if(estaNoVetor(*vet,r1) ==-1)
            printf("Erro:Registro R1, não está no vetor");  
         else
         {
             int aux = estaNoVetor(*vet,r1);
             for(int i=vet->nElem;i>aux;i--)
                  vet->item[i] = vet->item[i-1];
             vet->item[aux+1] = r2;
             vet->nElem++;     
         }      

}

void removerDadaChave1(TVet *vet,TItem x)
{
    if(estaVazio(*vet))
        printf("Erro:Vetor vazio");
    else if(estaNoVetorDecrescente(*vet,x) == -1)
            printf("Erro: A chave não está contida no vetor");
         else
         {
             int aux = estaNoVetorDecrescente(*vet,x),i;
             for(i=aux;i<vet->nElem-1;i++)
                    vet->item[i] = vet->item[i+1];
              vet->nElem--;      
         }     
}


int buscaSequencial(TVet vet, int x)
{
    int i;
    for(i=vet.nElem-1;i>=0 && vet.item[i].chave != x;i--);
    return i;
}

int buscaSequencialRec(TVet vet,int x,int i)
{
    if(i == vet.nElem) return -1;
    if(vet.item[i].chave == x) return i;
    return buscaSequencialRec(vet,x,i+1);
}

void adicionar(TVet a,TVet *b,int i)
{
    if(i<a.nElem) 
       b->item[b->nElem++] = a.item[i];
}

/*int estaNoVetor(TVet vet,TItem x)
{
    int i;
    for(i=0;i<vet.nElem && vet.item[i].chave != x.chave;i++);
    if(i == vet.nElem) return -1;
    return i;  
}
*/

void intercalar(TVet a,TVet b,TVet *c)
{
    int i;
    for(i=0;i<a.nElem;i++)
    {
        if(estaNoVetor(*c,b.item[i]) == -1)
            adicionar(b,c,i);
        if(estaNoVetor(*c, a.item[i]) == -1) 
                adicionar(a,c,i);    
    }
}


int buscaSequencialSentinela(TVet vet,int x)
{
    if(estaCheio(vet))printf("Não é possível fazer a busca com sentinela");
    else
    {
        int i; vet.item[vet.nElem].chave=x;
        for(i=0;i<vet.nElem && vet.item[i].chave != x;i++);
        if(i== vet.nElem) return -1;
        return i;
    }
}

int buscaSequencialSentinelaRec(TVet vet,TItem x,int i)
{
    if(i==vet.nElem) return -1;
    if(vet.item[i].chave == x.chave) return i;
    return buscaSequencialSentinelaRec(vet,x,i+1);
}

int buscaTabelasOrdenas(TVet vet,int x)
{
    int i;
    for(i=0;i<vet.nElem;i++)
    {
        if(vet.item[i].chave == x) return i;
        if(vet.item[i].chave>x) return -1;
    }
    return -1;
}

int pesquisaBinaria(TVet vet,int x)
{
    int ini = 0, fim = vet.nElem-1, meio;
    while(ini<=fim)
    {
        meio = (ini+fim)/2;
        if(vet.item[meio].chave == x) return meio;
        if(x > vet.item[meio].chave) ini = meio +1;
        else fim = meio -1;
    }
    return -1;
}

int pesquisaBinariaRec(TVet vet,int x,int ini,int fim)
{
    int meio;
    if(ini == fim) return -1;
    meio = (ini+fim)/2;
    if(vet.item[meio].chave==x) return meio;
    if(vet.item[meio].chave <x) return pesquisaBinariaRec(vet,x,meio+1,fim);
    return pesquisaBinariaRec(vet,x,ini,meio-1);
}

int pesquisaBinariaRec1(TVet vet,int x,int ini,int fim)
{
    int meio;
    if(ini>fim)return -1;
    meio = (ini+fim)/2;
    if(vet.item[meio].chave == x) return meio;
    if(vet.item[meio].chave<x)return pesquisaBinariaRec1(vet,x,meio+1,fim);
    return pesquisaBinariaRec1(vet,x,ini,meio-1);

}

int pesquisaVetOrdenado(TVet vet,int x,int i,int f)
{
    int l1,l2;
    if(i==f)    
    {    if(vet.item[i].chave==x) return i;
         if(vet.item[i].chave < x) return -1;
         return -1;
    }
   
    l1= pesquisaVetOrdenado(vet,x,i,(i+f)/2);
    l2 = pesquisaVetOrdenado(vet,x,((i+f)/2)+1,f);

    if(l1!=-1)return l1;
    if(l2!=-1)return l2;
}

int busca(TVet v , int x)
{
    int inicio= 0, fim = v.nElem-1 , meio;
    while (inicio < fim)
    {
      meio = (inicio+fim)/2;
      if (v.item[meio].chave < x) inicio = meio +1;
      else fim = meio -1 ;
    }

    if (v.item[inicio].chave == x) return inicio;
    else return -1;
}

void actualizarRegistro(TVet *vet,int chave,TItem r)
{
    int i;
    for(i=0;i<vet->nElem && vet->item[i].chave!=chave;i++);
    if(i==vet->nElem) printf("Erro:O registro não está no vetor;Impossível actualizar");
    else 
        vet->item[i] = r;
    
}

void actualizarReg(TVet *vet,int chave,TItem r,int i)
{
    if(i<vet->nElem)
    {
        if(vet->item[i].chave == chave) 
            vet->item[i] = r;
        else   
            actualizarReg(&(*vet),chave,r,i+1);
    }
    else
      printf("\nErro:O registro não está no vetor;Impossível actualizar\n");  
}

int primeiraOcorrenciaRec(TVet vet,int i,int f,int x)
{
   int oc1,oc2;
   if(i==f) 
   {    if(vet.item[i].chave == x) return i;
        return -1;
   }     
   oc1 = primeiraOcorrenciaRec(vet,i,(i+f)/2,x);
   oc2 = primeiraOcorrenciaRec(vet,((i+f)/2)+1,f,x);
   if(oc1 != -1 ) return oc1;
   if(oc2 != -1) return oc2;
}


void actualizarReg1(TVet *vet,int chave,TItem r,int i,int f)
{
   int aux = primeiraOcorrenciaRec(*vet,0,vet->nElem-1,chave);
   if(aux != -1)
        vet->item[aux] = r;
   else
    printf("A chave não se encontra no vetor \n");     

}

int busca1(TVet v , int x)
{
    int med, len;
    med = (v.nElem-1)/2;
    len = (v.nElem-2)/2;
    while (x != v.item[med].chave)
    {
        if (x < v.item[med].chave) med -= len/2;
        else med += len/2;
        len /= 2;
    }
    return med;
}

void troca(int *x, int *y)
{
    int aux = *x;
    *x = *y;
    *y = aux;
}

void troca3(TItem *x,TItem *y)
{
    TItem aux = *x;
    *x=*y;
    *y = aux;
}

void troca1(int *x[],int k1,int k2)
{
    int aux=*x[k1];
    *x[k1] = *x[k2];
    *x[k2] = aux;
}

void sequentialSort(TVet *vet)
{
    int i,j;
    for(i=0;i<vet->nElem-1;i++)
        for(j=i+1;j<vet->nElem;j++)
            if(vet->item[i].chave>vet->item[i].chave)troca3(&vet->item[i],&vet->item[j]);
}


void selectionSort (TVet *vet )
{
    int i , j , idMim;
    for ( i = 0 ; i < vet->nElem-1 ; i++)
    {
        idMim = i;
        for ( j = i+1 ; j < vet->nElem ; j++ )
            if ( vet->item[idMim].chave > vet->item[j].chave) idMim = j;
                if (idMim != i) troca3(&vet->item[i] , &vet->item[idMim]);
    }
}



void bubbleSort (TVet *vet )
{
    int i, j;
    for (i = 1 ; i < vet->nElem ; i++)
        for ( j = i ; j > 0 && vet->item[j].chave < vet->item[j-1].chave ; j--)
            troca3( &vet->item[j],&vet->item[j-1]);
}
void bubleSortRec(TVet *vet, int i,int j)
{
    if(i<vet->nElem)
    {
        if(j>0 )
        {  if(vet->item[j].chave < vet->item[j-1].chave)
                troca3( &vet->item[j],&vet->item[j-1]);
            bubleSortRec(&(*vet),i,j-1);   
        }
        else
             bubleSortRec(&(*vet),i+1,j);       
    }
}

void insertionSort (TVet *vet )
{
    int j , i ;
    TItem x;
    for ( j = 1 ; j < vet->nElem ; j++)
    {
        x = vet->item[j];
        for ( i = j-1 ; i >= 0 && vet->item[i].chave > x.chave ; j--)
            vet->item[i+1] = vet->item[i];
        vet->item[i+1] = x;
    }
}

void insertionSortRec(TVet *vet,int i,int j)
{
    TItem x;
    if(j<vet->nElem)
     {
        i=j-1;
        x=vet->item[j];
        if(i>=0 )
        {    if(vet->item[i].chave > x.chave) 
                vet->item[i+1] = vet->item[i];
            insertionSortRec(&(*vet),i,j-1);
        }
        else    
        {
            vet->item[i+1] = x;
            insertionSortRec(&(*vet),i,j+1);
        }
    }
 }

void inverterR(TVet a,TVet *b,int i)
{
    if(i<a.nElem)
    {
        inverterR(a,b,i+1);
        b->item[b->nElem++] = a.item[i];
    }
}

int buscaTernaria(TVet v,int x,int max,int min)
{
    int pivo1,pivo2;
    if(min>=max)return -1;
    if(v.nElem%3 == 0)
    {
        pivo1 = min + v.nElem/3-1;
        pivo2 = min + 2*v.nElem/3-1;
    }
    else
    {
        pivo1 = min + v.nElem/3;
        pivo2 = min + 2*v.nElem/3;
    }
    if(v.item[pivo1].chave == x) return pivo1;
    if(v.item[pivo1].chave>x) return buscaTernaria(v,x,pivo1-1,min);
    if(v.item[pivo2].chave == x) return pivo2;
    if(v.item[pivo2].chave>x) return buscaTernaria(v,x,pivo2-1,pivo1+1);
    return buscaTernaria(v,x,max,pivo2+1);
}

int main()
{
    TVet vetA,vetB,vetC;
    TItem b1,c1,d1,e1,f1,g1;
    TItem b2,c2,d2,e2,f2,g2;

    TItem a = {2,3},b = {3,4}, c = {4,5},d = {5,6}, e = {6,7},f = {7,8},g = {8,9}, h = {9,10};
    b1.chave = 2;b1.valor = 0;
    c1.chave = -1;c1.valor = 0;
    d1.chave = 5;d1.valor = 0;
    e1.chave = 3;e1.valor = 0;
    f1.chave = 15;f1.valor = 0;
    inicializarVetor(&vetA);
    inicializarVetor(&vetB);
    inicializarVetor(&vetC);
    inserirDadoChave(&vetA,b1);
    inserirDadoChave(&vetA,c1);
    inserirDadoChave(&vetA,d1);
    inserirDadoChave(&vetA,e1);
   inserirDadoChave(&vetA,f1);


     inserirDadoChave(&vetB,a);
    inserirDadoChave(&vetB,b);
    inserirDadoChave(&vetB,c);
    inserirDadoChave(&vetB,d);
    inserirDadoChave(&vetB,e);

    printf("Vetor A\n");
    imprimirVetor(vetA);
    
    printf("\nVetor B\n\n");
    imprimirVetor(vetB);
   
     intercalar(vetA,vetB,&vetC);
      printf("\nVetor c \n");
     imprimirVetor(vetC);
   

    return 0;
}   



 