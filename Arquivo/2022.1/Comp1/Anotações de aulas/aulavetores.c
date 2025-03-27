#define DIML 3
#define DIMC 5
#include <stdio.h>
#include <string.h>
/*
int main(void)
{
    int i;
    int vetor[5];

    for ( i = 0; i < 6; i++)
    {
        vetor[i]=0;
        
    }

    int j=10,a=10,c=10,d=10;


    for ( i = 0; i < 6; i++)
    {
        printf("\n%d",vetor[i]);
        
    }

    return 0;
    
}*/

/* COMO EQUIPARAR VETORES
int main(void) 
{
    int vetor[2]={1,2},i;
    int * vetor2=vetor;


    for ( i = 0; i < 2; i++)
    {
        printf("%4d",vetor[i]);
    }

    puts("\nvetor 2:\n");


    for ( i = 0; i < 2; i++)
    {
        printf("%4d",vetor2[i]);
    }

    return 0;
} */

/* INTRODUÇÃO A VETORES E PONTEIROS 
 
 
  ASTERISCO**, QUANDO ANTERIOR A UM PONTEIRO, SIGNIFICA "CONTEUDO DE"
  &&& SIGNIFICA "ENDEREÇO DE"

  
  NOte que quando se faz (v+i) para termos um endereço, o compilador automaticamente faz (v +(i * sizeof(int) 
  
int main(void)
{
	int v[5]={1,2,3,4,5},i,j;
	

	for(i=0;i<5;i++)
	{
			printf("Endereço do primeiro elemento: %x - Valor: %d\n",&v[i],v[i]);
			printf("Endereço do segundo elemento: %x - Valor: %d\n\n",(v+i),*(v+i));

					
	}




	return 0;
} */
