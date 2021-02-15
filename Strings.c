#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define TAM 30

int ehMaiuscula(char c)
{
    if(c>='A' && c<='Z') return 1;
    return 0;
}

int ehVogal(char c)
{
    if(c == 'a')  return 1;  
    if(c == 'e')  return 1;
    if(c == 'i')  return 1;
    if(c == 'o')  return 1;
    if(c == 'u')  return 1;
    return 0;
}
int ehMinuscula(char c)
{
    if(c>='a' && c<='z') return 1;
    return 0;
}

int converteEmMinuscula(char c)
{
    if(ehMaiuscula(c))
        c+='a' -'A';
    return c;
}

int converteEmMaiuscula(char c)
{
    if(ehMinuscula(c))
        c-='a' -'A';
    return c;    
}

int converteEmMaiuscula1(char c)
{
        c-='a' -'A';
    return c;    
}

void converter(char st[],int i)
{
    if(st[i]!='\0')
    {
        if(ehVogal(st[i]) == 1) st[i] = converteEmMaiuscula1(st[i]);
        else st[i] = converteEmMinuscula(st[i]);
        converter(st,i+1);
    }
}

void converter1(char st[],int i,int f)
{
    if(i==f)
    {   if(ehVogal(st[i])== 1) st[i] = converteEmMaiuscula1(st[i]);
        else st[i] = converteEmMinuscula(st[i]);
    }
    else 
    {
        converter1(st,i,(i+f)/2);
        converter1(st,((i+f)/2)+1,f);
    }   
}

void imprimir(char st[])
{
    for(int i=0;st[i]!='\0';i++)
        printf("%c",st[i]);
    printf("\n");    
}

void imprimir1(char st[])
{
    printf("%s",st);
    printf("\n");
}

void imprimir2(char st[])
{
    puts(st);
    printf("\n");
}

int comprimentoString(char st[])
{
    int i;
    for(i = 0;st[i]!= '\0';i++);
    return i;
}

int comprimentoStringRec(char st[],int i)
{
    if(st[i]=='\0') return 0;
    return  1 + comprimentoStringRec(st,i+1);
    
}

void copiarCadeia(char origem[],char destino[])
{
    int i;
    for(i=0;origem[i]!='\0';i++) destino[i] = origem[i];
    destino[i] = '\0';
    
}

void copiarCadeiaRec(char origem[],char destino[],int i)
{
    destino[i] = origem[i];
    if(origem[i]!='\0') copiarCadeiaRec(origem,destino,i+1);
     
}

void copiar(char st1[],char st2[])
{
    int i=0;
    while((st2[i]=st1[i])!='\0')i++;
}

void mesPorExtenso(int mes, char st[])
{
    switch(mes)
    {
        case 1: 
            copiarCadeia("Janeiro",st);
            break;
        case 2: 
            copiarCadeia("Fevereiro",st);
            break;
        case 3:
            copiarCadeia("Março",st);
            break;
        case 4:
            copiarCadeia("Abril",st);
            break;
        case 5:
            copiarCadeia("Maio",st);
            break;
        case 6:
            copiarCadeia("Junho",st);
            break;
        case 7:
            copiarCadeia("Julho",st);
            break;
        case 8:
            copiarCadeia("Agosto",st);
            break;
        case 9:
            copiarCadeia("Setembro",st);
            break;
        case 10:
            copiarCadeia("Outubro",st);
            break;
        case 11:
            copiarCadeia("Novembro",st);
            break;
        case 12:
            copiarCadeia("Dezembro",st);
            break;                                                 
    }
}
int estaVazia(char st[])
{
    if(st[0]=='\0')return 1;
    return 0;
}

int estaCheia(char st[])
{
    if(comprimentoString(st) == TAM)return 1;
    return 0;
}

void concatCadeia(char origem[],char destino[])
{
    if(estaVazia(origem))
        printf("Impossível concatenar as cadeias, a origem está vazia");
    else if(estaCheia(destino)) 
            printf("Impossível concatenar as strings. A string de destino está cheia");
         else
        {
            int i;
            for(i=0;destino[i]!=0;i++);
            for(int j=0;origem[j]!=0;j++)
            {    destino[i]=origem[j];
                 i++;
            }
        }    
}

int temMesmoTamanho(char st1[],char st2[])
{
    if(comprimentoString(st1) == comprimentoString(st2)) return 1;
    return 0;
}
int compararCadeia1(char st1[],char st2[])
{
    if(temMesmoTamanho(st1,st2))   
    {    for(int i=0;st1[i]!='\0';i++)
        {
            if(st1[i]<st2[i]) return -1;
            if(st1[i]>st2[i]) return 1;
        }  
        return 0;
    }
    else 
        return 2;
}

int compararCadeia2(char st1[],char st2[])
{
    int i;
    for(i=0;st1[i]==st2[i];i++);
    if(st1[i-1] == '\0') return 0;
    return st1[i] - st2[i];
}

int compararCadeiaRec(char st1[],char st2[],int i)
{
    if((st1[i-1] == '\0') || (st1[i]!=st2[i]))return st1[i]-st2[i];
    return compararCadeiaRec(st1,st2,i+1);
}

void imprimirRec(char st[],int i)
{
    if(st[i]!=0)
    {
        printf("%c",st[i]);
        imprimirRec(st,i+1);
    }
    else
        printf("\n");
}

int ehVogal1(char c)
{
    switch(c)
    {
        case 'a':
            return 1;
            break;
        case 'e':
            return 1;
            break;
        case 'i':
            return 1;
            break;
        case 'o':
            return 1;
            break;
        case 'u':
            return 1;
            break;
        default:
            return 0;
            break;                     
    }
}

/*************************** Exercícios ***************** */
int quantVogais(char st[])
{
    int n=0;
    for(int i=0;st[i]!='\0';i++)
        if(ehVogal(tolower(st[i])))
            n++;
    return n;        
}

int quantVogaisRec(char st[],int i)
{
    if(st[i]== '\0') return 0;
    if(ehVogal(tolower(st[i]))) return 1 + quantVogaisRec(st,i+1);
    return quantVogaisRec(st,i+1);    
}

void converteEmMaiuscula2(char st[])
{
    for(int i=0;st[i]!='\0';i++)
        if(ehMinuscula(st[i]))
            st[i] =converteEmMaiuscula1(st[i]);

}

void converteEmMaiusculaRec(char st[],int i)
{
    if(st[i] != '\0')
    {
       if(ehMinuscula(st[i]))
            st[i] =converteEmMaiuscula1(st[i]);
       converteEmMaiusculaRec(st,i+1);     
    }
}

int primeiraOcorrenciaCaracter(char st[],char c)
{
    int i;
    for(i=0;st[i]!=c;i++);
    if(st[i] == c)return i;
    return -1;        
}

int primeiraOcorrenciaCaracterRec(char st[],char c,int i)
{
    if(st[i] == '\0') return -1;
    if(st[i] == c) return i;
    return primeiraOcorrenciaCaracterRec(st,c,i+1);
}
int posValida(int pos,char st[])
{
    if(pos>=0 && pos<=comprimentoString(st)-1) return 1;
    return 0;
}
void removerLetra(char st[],int pos)
{
    int i;
    for(pos;st[pos]!='\0';pos++)
        st[pos] = st[pos+1]; 

}

void removerCadeia(char st[])
{
  for(int i=0;st[i]!=0;i++)
  {
      if(ehMinuscula(st[i]))
      {
          //st[i] = "0";
          removerLetra(st,i);
      }
  }
}

int opostaMinuscula(char c)
{
    c = 219 - c;
    return c;
}

int opostaMaiuscula(char c)
{
    c = 155 - c;
    return c;
}

void cadeiaOposta(char st[])
{
    for(int i=0;st[i]!=0;i++)
    {    if(ehMaiuscula(st[i]))
            st[i] = opostaMaiuscula(st[i]);
        else
            st[i] = opostaMinuscula(st[i]);    
    }        
}

void cadeiaOpostaRec(char st[],int i)
{
    if(st[i] != '\0')
    {    if(ehMaiuscula(st[i]))
            st[i] = opostaMaiuscula(st[i]);
        else
            st[i] = opostaMinuscula(st[i]);
        cadeiaOpostaRec(st,i+1); 
    }           
}

void cadeiaOpostaRec1(char st[],int i,int f)
{
    if(i==f)
    {   if(ehMaiuscula(st[i])) st[i]=opostaMaiuscula(st[i]);
        else st[i] = opostaMinuscula(st[i]);
    }
    else
    {
        cadeiaOpostaRec1(st,i,(i+f)/2);
        cadeiaOpostaRec1(st,((i+f)/2)+1,f);
    }    
}

void deslocarMaisADireita(char st[])
{
    int tam = comprimentoString(st);
    if(!estaCheia(st))
    {
        for(int i=tam;i>=0;i--)
            st[i+1] = st[i];
        st[0] = st[tam];
        st[tam] = st[tam+1];   
        st[tam+1] = ' ';
    }        
    else
        printf("Erro: Vetor cheio");              
}

void deslocarMaisADireitaRec(char st[],int i , int tam)
{
    if(i>=0)
    {
        st[i+1] = st[i];
        deslocarMaisADireitaRec(st,i-1,tam);
    }
    else
    {
        st[0] = st[tam];
        st[tam] = st[tam+1];
        st[tam+1] =' ';
    }
}

int ehPossivelAdiconar(char st[], int quantElem)
{
    if(comprimentoString(st)+quantElem <= TAM) return 1;
    return 0;
}

void concatenarDetermElems(char origem[], char destino[], int nOrigem)
{
    int i,j;
    if(!estaCheia(destino))
    {    
        if(ehPossivelAdiconar(destino,nOrigem))
        {   
            for(i=0;destino[i]!='\0';i++);
            for(j=0;origem[j]!='\0' && nOrigem>0;j++,nOrigem--)
            {  
                destino[i]=origem[j];
                i++;
            }    
            destino[i] = '\0';    
        }
        else
            printf("Erro: Não é possível adicionar essa quantidade de elementos");    
    }
    else 
        printf("Erro: o vetor destino está cheio");
    
}


void concatenarDetermElemsRec(char origem[],char destino[],int nOrigem,int i,int j)
{
        if(destino[i]!='\0')
            concatenarDetermElemsRec(origem,destino,nOrigem,i+1,j);
        else if(origem[j]!='\0' && nOrigem>0)
        {
            destino[i] = origem[j];
            concatenarDetermElemsRec(origem,destino,nOrigem-1,i+1,j+1);
        }
        else
            destino[i] = '\0';
            
}

int somaAlgoritmos(int n)
{
    if(n == 0) return 0;
    return n%10 + somaAlgoritmos(n/10);
}

int somaAlgoritmos1(int n[],int i,int f)
{
    if(i==f)
        return n[i];
    return somaAlgoritmos1(n,i,(i+f)/2)+somaAlgoritmos1(n,((i+f)/2)+1,f);    
}

void normaliza(char s[])
{
    
    for(int i=0;s[i]!='\0';i++)
    {    if(i==0 && ehMinuscula(s[i]))s[i] = converteEmMaiuscula(s[i]);
        else if(s[i] == ' ' && ehMinuscula(s[i+1])) s[i+1] = converteEmMaiuscula(s[i+1]);

    }    
}

int procuraSubs(char st[],char st1[])
{
    int j=0,k,i,val = 0;
    for(i=0;st[i]!='\0';i++)
    {
        k=i;  
        while(st1[j]!='\0')
        {
            if(st[k]==st1[j])
                val++;
            k++;j++;    
        }
        if(comprimentoString(st1) == val) return 1;
        else
        {    val = 0;
             j = 0;
        }       
    }
    return 0;
}

void substr(char st[],char st1[],int pos,int n,int i)
{
    if(st[pos]!='\0' && n!=0)
    {
        st1[i]=st[pos];
        substr(st,st1,pos+1,n-1,i+1);
    }
}

int main()
{
    char st[TAM],str[TAM] ="Anabela",tam = comprimentoString(str);
    int n[TAM] = {2,3,9};
    substr(str,st,3,4,0);
    imprimirRec(st,0);
}