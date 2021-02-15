#include <stdio.h>
#include <stdlib.h>
#define MAXCOL 3
#define MAXLIN 3
#define M 1
#define N 2
/*
int somaDaDiagonal(int matriz[][MAXCOL])
{
    int soma=0;
    for(int i=0;i<=MAXCOL-1;i++)
        soma+=matriz[i][i];
    return soma;
}

int somaDaDiagonal(int matriz[][MAXCOL],int i)
{
    if(i<N) return 0;
    return matriz[i][i]+somaDaDiagonal(matriz,i+1);
}


int acederUmElementoDaMatriz(int matriz[][MAXCOL],int linha,int coluna)
{
    return matriz[linha][coluna];
}

void percorrerMatrizPorColuna(int matriz[][MAXCOL])
{
    for(int i=0;i<MAXCOL;i++)
    {     for(int j=0;j<MAXLIN;j++)
        {     matriz[i][j]=0;
              printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }    

}

void percorrerMatrizPorColunaRec(int matriz[][MAXCOL],int i, int j)
{
    if(i<M)
    {    if(j<N)
        {    
            matriz[i][j]=0;
            percorrerMatrizPorColuna(matriz,i,j+1);
        }
        else
          percorrerMatrizPorColuna(matriz,i+1,0);  
    }
}


void percorrerMatrizPorLinha(int matriz[][MAXCOL])
{
    for(int i=0;i<MAXLIN;i++)
        for(int j=0;j<MAXCOL;j++)
            matriz[i][j]=0;
}

void imprimirMatriz(int matriz[][MAXCOL])
{
    for(int i=0;i<MAXLIN;i++)
    {   for(int j=0;j<MAXCOL;j++)
            printf("%d ",matriz[i][j]);
        printf("\n");    
    }
}

void copiarMatriz(int matrizA[][MAXCOL],int matrizB[][MAXCOL])
{
    for(int i=0;i<MAXLIN;i++)
        for(int j=0;j<MAXCOL;j++)
            matrizB[i][j] = matrizA[i][j];
}

void copiarMatrizRec(int matrizA[][MAXCOL],int matrizB[][MAXCOL],int i, int j)
{
    if(i<M)
    {    if(j<N)
        {    
            matrizB[i][j]=matrizA[i][j];
            copiarMatrizRec(matrizA,matrizB,i,j+1);
        }
        else
           copiarMatrizRec(matrizA,matrizB,i+1,0); 
    }       
}

int tamMatriz(int matriz[][MAXCOL])
{
    return MAXCOL*MAXLIN;
}

int somaMatrizes(int matrizA[][MAXCOL],int matrizB[][MAXCOL],int matrizC[][MAXCOL])
{
        for(int i=0;i<MAXLIN;i++)
            for(int j=0;j<MAXCOL;j++)
                matrizC[i][j]=(matrizA[i][j]+matrizB[i][j]);
}

void somaDeMatrizes(int matrizA[][MAXCOL],int matrizB[][MAXCOL],int matrizC[][MAXCOL],int i,int j)
{
    if(i<M)
    {    if(i<M)
        {
            matrizC[i][j] = matrizA[i][j]+matrizB[i][j];
            somaDeMatrizes(matrizA,matrizB,matrizC,i,j+1)
        } 
        else
            somaDeMatrizes(matrizA,matrizB,matrizC,i+1,0);   
    }         
}

int matrizTringularSuperior(int matriz[][MAXCOL])
{
    for(int i=0;i<MAXLIN;i++)
        for(int j=0;j<MAXCOL;j++) 
             if(i>j)
                if(matriz[i][j]!=0)
                    return 0;

    return 1;            
}

int matrizTriangularInferiorRec(int matriz[][MAXCOL],int i, int j)
{
    if(i<M)
    {    if(j<N)
        {   if(i>j)   
                if(matriz[i][j]!=0)
                    return 0;
            else      
                matrizTriangularInferiorRec(matriz,i,j+1);   
        }
        else
            matrizTriangularInferiorRec(matriz,i+1,0);  
    }  
    return 1;     
}

int matrizTriangularInferior(int matriz[][MAXCOL])
{
    for(int i=0;i<MAXLIN;i++)
        for(int j=0;j<MAXCOL;j++)
            if(i<j)
                if(matriz[i][j]!=0)
                    return 0;

    return 1;
}

int matrizTriangularInferiorRec(int matriz[][MAXCOL],int i, int j)
{
    if(i<M)
    {    if(j<N)
        {    if(i<j)   
                if(matriz[i][j]!=0)
                    return 0;
            else      
                matrizTriangularInferiorRec(matriz,i,j+1);   
        }
        else
            matrizTriangularInferiorRec(matriz,i+1,0);  
    }  
    return 1;     
}

void calcularMatrizTransposta(int matriz[][MAXCOL],int matrizT[][MAXCOL])
{
    for(int i=0;i<MAXCOL;i++)
        for(int j=0;j<MAXLIN;j++)
            matriz[j][i] = matriz[i][j];
}

void calcularMatrizTransposta(int matriz[][MAXCOL],int matrizT[][MAXCOL],int i,int j)
{
    if(i<M)
    {   if(j<N)
        {    matrizT[j][i]=matriz[i][j]
            calcularMatrizTransposta(matriz,matrizT,i,j+1);
        }
        else
            calcularMatrizTransposta(matriz,matrizT,i+1,0);    
    }        
}

int simetrica(int matriz[][MAXCOL])
{
    for(int i=0;i<MAXCOL;i+++)
        for(int j=0;j<MAXLIN;j++)
            if(matriz[i][j] != matriz[j][i])
                return 0;

     return 1;           
}

void multMatrizes(int matrizA[][MAXCOL1],int matrizB[][MAXCOL2]L,int matrizC[][MAXCOL3])
{
    int i,j,k;
    for(i=0;i<MAXCOL2;i++)
        for(j=0;j<MAXCOL3;j++)
        {
            matrizB[i][j]=0;
            for(k=0;k<MAXCOL1;k++)
                matrizC[i][j] += matrizA[i][k]*matrizB[k][j];
        }

}

void multMatrizes(int matrizA[][MAXCOL1],int matrizB[][MAXCOL2]L,int matrizC[][MAXCOL3],int i, int j , int k)
{
    if(i<MAXCOL2)
    {    if(j<MAXCOL3)
        {    matrizC[i][j]=0;
            if(k<MAXCOL1)
            {    matrizC[i][j]+=matrizA[i][k]*matrizB[k][j];
                multMatrizes(matrizA,matrizB,matrizC,i,j,k+1);
            }   
             else
                multMatrizes(matrizA,matrizB,matrizC,i,j+1,0); 
        }
        else
             multMatrizes(matrizA,matrizB,matrizC,i+1,0,0);

    }
}

void imprimirMatrizRec(int matriz[][MAXCOL],int i, int j))
{
    if(i<M)
    {    if(j<N)
        {   printf("%d ", matriz[i][j]);
            imprimirMatrizRec(matriz,i,j+1);
        }
        else
        {
            printf("\n");
            imprimirMatrizRec(matriz,i+1,0);
        }
    }    
}


int somaRec(int matriz[][MAXCOL],int i, int j)
{
    if(i<M)
    {  if(j<N)
            return matriz[i][j]+somaRec(matriz,i,j+1);
        else
            return somaRec(matriz,i+1,0);
    }
}

int simetricaRec(int matriz[][MAXCOL],int i, int j)
{
    if(i<M)
    {    if(i<N)
        {   if(matriz[i][j]!=matriz[j][i])
                return 0;
            else
                simetricaRec(matriz,i,j+1);
        }
        else
            simetricaRec(matriz,i+1,0);
    } 
    return 1;      
}
*/

int seIguais(int matrizA[][MAXCOL],int matrizB[][MAXCOL],int linha,int coluna)
{
    if(linha == MAXLIN) return 1;
    if(coluna<MAXCOL)
    {
        if(matrizA[linha][coluna]!= matrizB[linha][coluna])return 0;
        return seIguais(matrizA,matrizB,linha,coluna+1);
    }
    else
        return seIguais(matrizA,matrizB,linha+1,0);
}

int main()
{
    int matriz1[MAXLIN][MAXCOL]={{0,1,2},{2,3,4},{3,4,5}},soma,elemento,tam,
    matriz3[MAXLIN][MAXCOL]={{0,1,2},{2,3,4},{3,4,5}};

    printf("As matrizes são iguais:%d \n",seIguais(matriz1,matriz3,0,0));


return 0;
}