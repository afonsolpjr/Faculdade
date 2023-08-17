#include <stdlib.h>
#include <stdio.h>


int tam_dizima(int a);
int main(void)
{   int a;
    
    printf("Checar tamanho maximo de dizimas de 1/n ate qual n?\n");
    scanf("%d",&a);
    printf(", com %d digitos em sua dizima.\n\n",
    tam_dizima(a) );
    return 0;
}

int tam_dizima(int a)
{
    int k,resto,n,tam,*restos,i,max,nMax;
    max = 0;
    for(k=2;k<a;k++)
    {
        n=k;
        restos = calloc(1,sizeof(int));

        tam = 0;
   
        resto=1;

        printf("\n [1/%d] = 0.",n);
        while(!(resto/n))
        {

            resto*=10;
            printf("%d",resto/n);
            resto = resto%n;
            tam++;
            if(!resto) 
            {
                tam = 0;
                break;
            }
            
            for(i=0;i<tam-1;i++)   //vendo se o resto eh repetido
            {
                if (resto==restos[i])
                {
                    printf("%d",(resto*10)/n);
                    tam--;
                    tam = tam-i;
                    i=-1; 
                    break;
                }
            }
            if(i==-1) break;
            if(resto==1)
            {
            break;
            }

            restos = realloc(restos,(tam)*sizeof(int));

            restos[tam-1] = resto;
        }
        printf (" e sua dizima tem %d digitos",tam);
        tam>max? (max=tam) && (nMax = n): 0;
    }
    printf("\n\n\t\tO numero com maior dizima periodica foi %d",nMax);
    return max;
}