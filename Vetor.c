#include<stdio.h>
#include<stdlib.h>
#define TAM 20

void imprimir(int vet [], int nElem);
int estaCheio(int nElem);
int posValida(int pos,int nElem);
int estaVazio(int nElem);
void inserirNaPosicao(int pos,int nElem, int a[],int elem);
int removerElementoDeDeterminadaPosicao(int a[],int pos,int nElem);
int maximoDoVetor(int a[],int nElem);
void imprimirRecDecrescente(int a[],int nElem);
void imprimirRecCrescente(int a[], int nElem, int i);
int somaElementosDoVetorRec(int a[],int nElem);
int produtoElementos(int a[], int nELem);


void imprimir(int vet [], int nElem)
{
    for(int i=0;i<nElem;i++)
        printf("%d\n", vet[i]);
}

int estaCheio(int nElem)
{
    return nElem == TAM;
}

int posValida(int pos,int nElem)
{
    if(pos>= 0 && pos<=nElem)
        return 1;
    return 0;    
}

int estaVazio(int nElem)
{
    return nElem == 0;
}

void inserirNaPosicao(int pos,int nElem, int a[],int elem){
    int i;
    for(i=nElem-1;i>=pos;i--) 
        a[i+1] = a[i];
    printf("i:%d\n",i);    
   // a[i+1]= elem;
    a[pos] = elem;
    nElem++;      
}

int removerElementoDeDeterminadaPosicao(int a[],int pos,int nElem)
{
    int rm=0;
    if(estaVazio(nElem))
        printf("Erro: Impossível remover, o vector está vazio");
    else if(!posValida(pos,nElem))
            printf("Erro: Impossível remover, posição de remoção inválida");
         else       
        {   
            rm = a[pos];
            for(int i=pos;i<nElem;i++)
                a[i]=a[i+1];
            nElem--;       
        }
    return rm;    
}

int maximoDoVetor(int a[],int nElem)
{   
    if(estaVazio(nElem))
        printf("Erro: Impossível achar o máximo, vetor vazio");
    else    
    {  int maior=a[0];
        for(int i=1;i<nElem;i++)
            if(maior<a[i])
                 maior = a[i];
        return maior;    
    }        
}

int maxVet(int a[],int nElem)
{
    int max;
    if(nElem == 1) return a[0];
    max = maxVet(a,nElem-1);
    if(max>a[nElem-1])return max;
    printf("Max :%d e a[nElem-1]: %d",max,a[nElem-1]);
    return a[nElem-1];
}

void imprimirRecCrescente(int a[], int nElem, int i)
{
    if(i<nElem)
    {
        printf("%d\n",a[i]);
        imprimirRecCrescente(a,nElem,i+1);
    }
}

void imprimirRecDecrescente(int a[],int nElem)
{
    if(nElem>=1)
    {
        printf("%d\n",a[nElem-1]);
        imprimirRecDecrescente(a,nElem-1);
    }
}

int somaElementosDoVetorRec(int a[],int nElem)
{
    if(nElem==0)return 0; 
    return a[nElem-1]+somaElementosDoVetorRec(a,nElem-1);  
}

void imprimir1 ( int vet[ ] , int nElem )
{
    if ( nElem >= 1 )
    {
        printf ("%d \n", vet[nElem-1] );
        imprimir ( vet , nElem-1);
    }
}


void imprimir2 ( int vet[ ], int nElem )
{
    if ( nElem >= 1 )
    {
        imprimir ( vet , nElem-1 );
        printf ("%d \n", vet[nElem-1] );
    }

}

int totalElementos(int a[],int nElem,int i)
{
    if(i == nElem)return 0;
    return 1+totalElementos(a,nElem,i+1);
}

int totalElementos1(int a[],int nElem)
{
    if(nElem == 0) return 0;
    return 1+ totalElementos1(a,nElem-1);
}

int totalElementos2(int a[],int i,int f)
{
    if(i==f)
        return 1;
    return totalElementos2(a,i,(i+f)/2)+totalElementos2(a,((i+f)/2)+1,f);    
}

/********************************Exercícios*****************************************************/
int produtoElementos(int a[], int nELem)
{
    if(nELem == 0) return 1;
    if(a[nELem-1]> 0)
        return a[nELem-1]*produtoElementos(a,nELem-1);
    return produtoElementos(a,nELem-1);    
}

int produtoElem1(int a[],int i,int f)
{
    if(i==f) return a[i];
    return produtoElem1(a,i,(i+f)/2)*produtoElem1(a,((i+f)/2)+1,f);
}

void troca1(int a[],int nElem)
{
    int aux;
    nElem--;
    for(int i=0;i<=nElem/2;i++)
    {
        aux=a[i];
        a[i] = a[nElem-i];
        a[nElem-i] = aux;
    }
}

void troca(int a[],int nElem, int i)
{
    int aux;
    if(i<=nElem/2)
    {    
      aux = a[i];
      a[i] = a[nElem-i];
      a[nElem-i] = aux;
      troca(a,nElem,i+1);   
    }      
}

int troca2 (int a[],int nElem, int i,int f)
{
    if(i==f)
    {
        int aux = a[i];
        a[i] = a[nElem -i];
        a[nElem-i] = aux;
    }
    if(i<nElem/2)
        return troca2(a,nElem,i,(i+f)/2)&&troca2(a,nElem,((i+f)/2)+1,f);
}

int verifParImpar(int a[],int nElem,int i)
{
    if(i==nElem) return 1;
    if(i%2 == 0)
    {    if(a[i]%2 ==1)
            return verifParImpar(a,nElem,i+1);
        return 0;    
    }    
    if(a[i]%2 == 0)
        return verifParImpar(a,nElem,i+1);
    return 0;    
}

int verifParImpar1(int a[],int i, int f)
{
    if(i==f)
    {  
        if(i%2==0)
          return(a[i]%2 == 1);
        return(a[i]%2 == 0); 
    }    
    return verifParImpar1(a,i,(i+f)/2)&&verifParImpar1(a,((i+f)/2)+1,f);      
}

int maxFunc(int a[],int nElem)
{
    int max=a[0];
    for(int i=1;i<nElem;i++)
        if(max<a[i])
            max=a[i];
    return max;        
}

int minFunc(int a[],int nElem)
{
    int min = a[0];
    for(int i=1;i<nElem;i++)
        if(min>a[i])
            min=a[i];
    return min;        
}

void maxMinFunc(int a[],int nElem,int *max, int *min)
{
    for(int i=1;i<nElem;i++)
    {
        if(*max<a[i])
            *max = a[i];
        if(*min>a[i]);
            *min = a[i];     
   
    }
    
}
/*int maxRec(int a[],int i,int f,int *max,int *min)
{
    int max1,max2,min1,min2;
    if(i==f) return a[i];
    min1=max1=maxRec(a,i,(i+f)/2,&(*max),&(*min));
    min2=max2=maxRec(a,((i+f)/2)+1,f,&(*max),&(*min));
    if(max1>max2) *max=max1;
    else *max = max2;
    if(min1>min2) *min = min2;
    else *min = min1;
 
}
*/

void maxMinRec(int a[], int nElem, int *max, int *min)
{
    if(nElem>0)
    {
        if(*max < a[nElem]) *max = a[nElem];
        if(*min > a[nElem]) *min = a[nElem];
        maxMinRec(a,nElem-1,&(*max),&(*min));
    }

}

void maxRec(int a[],int i,int f,int *max,int *min)
{
    if(i==f){
        if(a[i]>*max) *max=a[i];
        if(a[i]<*min) *min=a[i];
   }
    else
     {   if(a[i]>*max) *max=a[i];
         if(a[i]<*min) *min=a[i];
         maxRec(a,i,(i+f)/2,&(*max),&(*min));
         maxRec(a,((i+f)/2)+1,f,&(*max),&(*min));
     }          

}

int minRec(int a[],int i,int f)
{
    int min1,min2;
    if(i==f) return a[i];
    min1=minRec(a,i,(i+f)/2);
    min2=minRec(a,((i+f)/2)+1,f);
    if(min1<min2) return min1;
    return min2;

}


int removerPosRec(int a[],int *nElem,int k)
{
    if(k == *nElem) 
        *nElem = *nElem -1;
    if(k<*nElem)
    {  a[k]=a[k+1];
       removerPosRec(a,&(*nElem),k+1);
    }   
}


void inseriRec(int a[],int *nElem,int k,int x,int i)
{
    if(i<k)
    {   a[k]=x;
        *nElem = *nElem+1;
    }
    if(i>=k)
    {    a[i+1] = a[i];
        inseriRec(a,&(*nElem),k,x,i-1);
    }    

}

int seIguais(int a[],int b[],int nElem)
{
    if(nElem==0)return 1;
    if(a[nElem-1]!=b[nElem-1])
        return 0;
    return seIguais(a,b,nElem-1);    
}

int quantVezesRepetNum(int a[],int nElem,int x)
{
    if(nElem == 0)return 0;
    if(a[nElem -1] == x)
        return 1+quantVezesRepetNum(a,nElem-1,x);
    return quantVezesRepetNum(a,nElem-1,x);    
}

int estaNoVetor1(int a[],int nElem,int i, int x)
{
    if(i == nElem ) return -1;
    if(a[i] == x)return i;
    return estaNoVetor1(a,nElem,i+1,x);
}

int saoInverso(int a[],int b[],int nElem,int i)
{
    if(i==nElem) return 1;
    if(a[i]!=b[nElem-i]) return 0;
    return saoInverso(a,b,nElem,i+1);
}

int saoInverso1(int a[], int b[],int i, int f, int nELem)
{
    if(i==f) return a[i] == b[nELem-i];
    return saoInverso1(a,b,i,(i+f)/2,nELem)&&saoInverso1(a,b,((i+f)/2)+1,f,nELem);
}

void inverterParImpar(int a[],int nElem)
{
    int i=0,j,aux;
    for(j=0;j<nElem;j++)
    {
        if(a[j]%2 == 0 )
        {
            aux = a[i];
            a[i] = a[j];
            a[j] = aux;
            i+=1;   
        }      
    }
}

void inverterParImparRec(int a[],int nElem, int j,int i)
{
    int aux;
    if(j<nElem)
    {
        if(a[j]%2==0)
        {
            aux = a[i];
            a[i] = a[j];
            a[j] = aux;
            inverterParImparRec(a,nElem,j+1,i+1);
        }
        inverterParImparRec(a,nElem,j+1,i);
    }
}


void converteEmBinario(int n)
{
    while(n>0)
    {
        n=n/2;  
        printf("%d",n%2); 
    }
     printf("\n");
}

void convertEmBinarioRec(int n)
{
    if(n>0)
    {
        convertEmBinarioRec(n/2);
        printf("%d",n%2);    
    }
}

void total(int a[],int nElem,int b[])
{
    for(int i=0;i<nElem;i++)
        b[i] = a[i]/5;
}

/*******************************MAIN************************************************************/
int main()
{
  int a[TAM]={0,10,20,50,60,70,80,90,100}, b[TAM]={4,3,2,1},c[TAM];
  total(a,9,c);
  imprimir(c,9);
  return 0;
}