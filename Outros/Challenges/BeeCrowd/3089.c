#include <stdio.h>

// https://github.com/rilpires/competitive_programming


int main(void)
{
    int n,i,caro[10000],barato[10000],par[20000],somas[10000],k;
    k=0,n=1;

    while(n)
    {
        scanf("%d",&n);
        if(!n) break;
        else k++;
        // par = calloc(2*n,sizeof(int));

        for(i=0;i<2*n;i++)
        { 
            scanf("%d",&par[i]);
            
        }

        for(i=0;i<n;i++)
        {
            somas[i] = par[0+i] + par[(2*n)-1-i ];
        }
        barato[k-1]=200000000;
        caro[k-1]=0;
        for(i=0;i<n;i++)
        {
            if(somas[i]>caro[k-1]) caro[k-1] = somas[i];
            if(somas[i]<barato[k-1]) barato[k-1] = somas[i];
        }

        for(i=0;i<2*n;i++) par[i]=0;
    }
    
    for(i=0;i<k;i++)
    {
        printf("%d %d\n",caro[i],barato[i]);
    }

    return 0;
}