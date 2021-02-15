#include<stdio.h>
#include<stdlib.h>
#define TAM 30


int fibo(int n)
{
    int f;
    printf("Entrar em fibo %d\n",n);
    if(n<=1)
        f=n;
    else
        f=fibo(n-1) + fibo(n-2);
    printf("Sair de fibo(%d),Retornar = %d \n",n,f);
    return f;        
}
void imprimirElementos(float vet[],int i, int f)
{
    int k;
    if(i==f)
        printf("%.2f\n",vet[i]);
    else 
    {
        k=(i+f)/2;
        imprimirElementos(vet,i,k);
        imprimirElementos(vet,k+1,f);
    }    
}

int quantElementos(int vet[],int ini, int fim)
{
    int total1,total2,meio;
    if(ini==fim)
        return 1;
    else
    {
       meio=(ini+fim)/2;
       return quantElementos(vet,ini,meio)+quantElementos(vet,meio+1,fim);
    }
        
}

int comparar(int a[],int b[],int i, int f)
{
    if(a[i]!=b[i]) return 0;
    if(i==f)return a[i] == b[i];
    return comparar(a,b,i,(i+f)/2)&&comparar(a,b,((i+f)/2)+1,f);  
}

int quantZero (int a[],int i, int f)
{
    if(i==f) return (a[i]==0);
    return quantZero(a,i,(i+f)/2)+quantZero(a,((i+f)/2)+1,f);
}

int estaOrdenado(int a[],int nElem,int i)
{
    if(i==nElem-2)return 1;
    if(a[i+1]>a[i])return estaOrdenado(a,nElem,i+1);
    return 0;
}

int estaOrdenado1(int a[],int nElem)
{
    if(nElem==0) return 1;
    if(a[nElem-1]<a[nElem])return estaOrdenado1(a,nElem-1); 
    return 0;
}

int estaOrdenado2(int a[],int i,int f)
{
    if(i==f)
        return(a[i]>a[i+1]);
    return estaOrdenado2(a,i,(i+f)/2)&&estaOrdenado2(a,((i+f)/2)+1,f);    
}

int ehCapicua(int a[],int nElem,int i)
{
    if(i>nElem/2) return 1;
    if(a[i]!= a[nElem-i]) return 0;
    return ehCapicua(a,nElem,i+1);
} 

int ehCapicua1(int a[],int i,int f,int nElem)
{
    if(i == f)
        return a[i] == a[nElem-i];
    return ehCapicua1(a,i,(i+f)/2,nElem)&&ehCapicua1(a,((i+f)/2)+1,f,nElem);    
}

int maisProximo(int a[],int x,int nElem)
{
    int num= 0;
    for(int i=0;i<nElem;i++)
    {
        if(x-a[i]>0 && x-a[i] <x)
            if(num<a[i])
                num = a[i];
    }
    return num;
}

int maisProximo1(int a[],int x,int nElem,int num)
{
    if(nElem == 0) return num;
    if(x-a[nElem]>0 && x-a[nElem]<x)
        if(num<a[nElem])
            num = a[nElem];
    maisProximo1(a,x,nElem-1,num);        
}

int nLucas(int n)
{
    int ant=2,act = 1,prox=0;
    if(n==0) return 2;
    if(n==1) return 1;
    for(int i=2;i<=n;i++)
    {
        prox = act + ant;
        ant = act;
        act = prox;
    }
    return prox;
}

int nLucasRec(int n)
{
    if(n==0)return 2;
    if(n==1) return 1;
    return nLucasRec(n-1)+nLucasRec(n-2);
}

int nLucasD(int n,int i,int vet[])
{
    vet[0] = 2;vet[1] = 1;
    if(n==0)return vet[n];
    if(n==1)return vet[n];
    if(i<=n)
    {
        vet[i] = vet[i-1]+vet[i-2];
        return nLucasD(n,i+1,vet);
    }
    return vet[n];
}

int potencia(int a,int n,int vet[],int i)
{
    vet[0] = 1;
    if(n==0)return vet[n];
    if(i<=n)
    {   
        vet[i] = vet[i-1] * a;
        return potencia(a,n,vet,i+1);
    }    
    return vet[n];
}

int numG(int n)
{
    if(n==0) return 2;
    if(n==1) return 1;
    if(n==2) return 3;
    return numG(n-1)+5*numG(n-2)+3*numG(n-3);
}

int numGRec(int n,int i,int vet[])
{
    vet[0] = 2;vet[1]=1;vet[2] = 3;
    if(n==0)return vet[n];
    if(n==1)return vet[n];
    if(n==2)return vet[n];
    if(i<=n)
    {
        vet[i] =vet[i-1]+5*vet[i-2]+3*vet[i-3];
        return numGRec(n,i+1,vet);
    }
    return vet[n];
}

int numTribo(int n,int i, int vet[])
{
    vet[0] = 0;vet[1]=1;vet[2] = 1;
    if(n==0)return vet[n];
    if(n==1)return vet[n];
    if(n==2)return vet[n];
    if(i<=n)
    {
        vet[i] = vet[i-1]+vet[i-2]+vet[i-3];
        return numTribo(n,i+1,vet);
    }
    return vet[n];
}

int main()
{
    float vet1[TAM] = {14.5,13.6,12.9,10.1,15.6};
    int a[TAM] = {7,2,4,8,6,9},b[TAM] = {1,2,0,0,0,6},n=3,vet[5] ={0};
    //printf("O mais proximo de 5 é:%d",maisProximo1(a,5,5,0));

   // n = (2*n)/2;
    printf("O numReg é: %d\n",potencia(2,4,vet,1));


}