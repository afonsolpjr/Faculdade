#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    long long **piramide,col;
    long long tam=0,i,j,n;


    puts("*****Quantas linhas da piramide de pascal vc quer?? \n");
    scanf("%lld",&n);


    //criando 5 linhas
    piramide = (long long**)calloc(n,sizeof(long long*));
    puts("\n\n*********\n\n\n");
    //criando piramide
    for(tam=0;tam<n;tam++)
    {
        piramide[tam]= (long long*)calloc(tam+1,sizeof(long long));
        for(col=0;col<tam+1;col++)
        {
            if(col==0 || col==tam)
            {
                piramide[tam][col]=1;
            }
            else
            {
                piramide[tam][col] = (piramide[tam-1][col-1]) + piramide[tam-1][col];
            }
        }
    }
    while(1)
    {
        printf("\n__________\n Combinacao de :");
        scanf("%lld",&i);
        printf("\nescolhendo :");
        scanf("%lld",&j);
        printf("\n\nA combinacao de %lld escolhendo %lld:         %lld",i,j,piramide[i][j]);
    }
    return 0;
}

printpir(long long **piramide,int n)
{
    int i,j;
       for(i=0;i<n;i++)
    {
        for(j=0;j<=i;j++)
        {
            printf("%lld | ",piramide[i][j]);
        }
        puts("\n");
    }
}