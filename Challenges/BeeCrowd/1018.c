#include <stdio.h>


int main(void)
{
    int n,i;

    scanf("%d",&n);

    printf("%d\n",n);
    while(n>0)
    {
        i=0;
        while(n>=100)
        {
            i++;
            n-=100;
        }
        printf("%d nota(s) de R$ 100,00\n",i);
        i=0;
        while(n>=50)
        {
            i++;
            n-=50;
        }
        printf("%d nota(s) de R$ 50,00\n",i);
        i=0;
        while(n>=20)
        {
            i++;
            n-=20;
        }
        printf("%d nota(s) de R$ 20,00\n",i);
        i=0;
        while(n>=10)
        {
            i++;
            n-=10;
        }
        printf("%d nota(s) de R$ 10,00\n",i);
        i=0;
        while(n>=5)
        {
            i++;
            n-=5;
        }
        printf("%d nota(s) de R$ 5,00\n",i);
        i=0;
        while(n>=2)
        {
            i++;
            n-=2;
        }
        printf("%d nota(s) de R$ 2,00\n",i);
        i=0;
        while(n>=1)
        {
            i++;
            n--;
        }
        printf("%d nota(s) de R$ 1,00\n",i);
    }



    return 0;
}