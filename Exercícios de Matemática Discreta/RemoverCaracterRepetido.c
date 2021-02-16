#include <stdio.h>
#include <stdlib.h>

void removerCaracRepet(char vet[])
{
		int i=1,vez=0;
		char aux = vet[0];
		
		while (aux != '\0')
		{
				if(aux!= vet[i])
								i++;
				else
				{			
						while ( vet[i] != '\0')
								{
										vet[i] = vet[i+1];
											i++;
								}
								
						vez++;
						aux=vet[vez];
						i=vez+1;
				}
			
			
		} 

	

}



int main ()
{
	char vet [] = "isaiasa";
	removerCaracRepet(vet);
	puts(vet);


	return 0;
}
