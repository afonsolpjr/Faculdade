#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    int num[302],i,j,k,print,carry=0,resultado=0;
    print=0;
    for(i=0;i<302;i++)
    {
        num[i]=0;
    }
    num[0]=1;
    //elevando a 1000
    for(i=0;i<1000;i++)
    {
        for(j=0;j<302;j++)
        {
            num[j]*=2;

            if(carry) num[j]++;

            if(num[j]>=10)
            {
                num[j]= num[j]%10;
                carry=1;
            }
            else carry=0;
            
        }
    }

    for(i=301;i>=0;i--)
    {
        resultado+=num[i];
    }
    printf("O resultado desse caralho foi: %d",resultado);

}