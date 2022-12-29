#include <stdio.h>
#include <stdlib.h>

int potencia(int n,int e);

int main(void)
{
    int i,d[6],j,soma,resultado;
    

    resultado = 0;
    for(i=0;i<700000;i++)
    {
        // printf("\nNum: %d \t digitos:",i);
        soma = 0;
        for(j=0;j<6;j++)
        {
            d[j] = (i%(potencia(10,1+j)) - i%(potencia(10,j)) ) / potencia(10,j);

            soma+=potencia(d[j],5);
            // printf(" %d ",d[j]);
        }

        if(soma==i)
        {
            printf("\n Achei um porraaa = %d\n",i);
            resultado+=i;
        }
         
    }   
    printf("Resultado = %d", resultado);
}

int potencia(int n,int e)
{
    int i,resultado;
    if(!e) return 1;
    resultado = n;
    for(i=1;i<e;i++)
    {
        resultado*=n;
    }

    return resultado;

}