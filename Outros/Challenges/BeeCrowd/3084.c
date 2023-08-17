#include <stdio.h>


int main()
{   
    int i,h[10000],m[10000],k;
    k=0;

    while(scanf("%d %d",&h[k],&m[k])!=EOF)
    {
        h[k] = h[k]/30;
        m[k] = m[k]/6;
        k++;
    }

    for(i=0;i<k;i++)
    {
        printf("%02d:%02d\n",h[i],m[i]);
    }



    return 0;
}