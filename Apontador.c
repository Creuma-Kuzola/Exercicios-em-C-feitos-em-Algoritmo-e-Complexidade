#include <stdio.h>
#include <stdlib.h>

 int s,p;
 void somaprod(int a, int b)
 {
     s = a+b;
     p = a*b;
 }

int main ()
{
   int x,y;
   printf("Entre com os números: ");
   scanf("%d %d",&x,&y);
   somaprod(x,y);
   printf("Soma:%d \nProduto:%d\n",s,p);

}
