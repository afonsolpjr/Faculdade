#include<stdlib.h>
#include<stdio.h>


int checa_primo(int n);
int main(void)
{
    int *primos,tam,i,a,n,max=0,pmax; 

    tam = 0;
    primos = calloc(1,sizeof(int));

    for(i=2;i<1000;i++)
    {
        if(checa_primo(i))
        {
            primos = realloc(primos,(++tam)*sizeof(int));
            primos[tam-1] = i;
        }
    }
    // montar uma equacao
    for(i=0;i<tam;i++)
    {
        for(a=-999;a<1000;a++)
        {
            //equacao sera  n*n + a*n - primos[i];

            for(n=0;n<100;n++)
            {
                if((!(checa_primo((n*n) + (a*n) + primos[i]))))
                {
                    if(n>max)
                    {
                        pmax = a*primos[i];
                        max=n;
                        printf("A equacao n^2 + %d*n + %d deu primos ate n=%d\n",a,primos[i],n-1);
                        
                    }
                    break;
                }
            }
        }
    }
    printf("E o produto dos coeficientes para a equacao maxima foi %d",pmax);
    return 0;
}


int checa_primo(int n)
{
    int i,limite;
    
    
    if(n<=0) return 0;
    if(n==1) return 0;
 
    limite=0;
 
    while(1)
    {
        limite++;
        if(limite*limite>n) break;
    }

    for(i=2;i<limite;i++)
    {
        if(!(n%i))
        {
            return 0;
        }
    }

    return 1;
}