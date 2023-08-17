
#include <stdio.h>
#include <stdlib.h>


int main()
{
    
    int digito[4],n[500000],entradas,i;

    digito[0] = 1;
    digito[1] = 7;
    digito[2] = 9;
    digito[3] = 3;
    scanf("%d",&entradas);

    

    for(i=0;i<entradas;i++)
    {
        scanf("%d",&n[i]);
    }

    
    for(i=0;i<entradas;i++)
    {
        printf("%d\n",digito[n[i]%4]);    
    }
    


    return 0;
}