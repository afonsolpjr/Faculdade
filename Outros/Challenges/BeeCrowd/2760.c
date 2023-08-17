#include <stdio.h>

int main(void)
{
    char str[3][101];
    int i,j;

    for(i=0;i<3;i++) 
    {
        j=0;

        while((str[i][j++]=getchar())!='\n');
        str[i][j-1] = '\0';
    }

    for(i=0;i<3;i++) printf("%s",str[i]);
    printf("\n");

    printf("%s",str[1]);
    printf("%s",str[2]);
    printf("%s\n",str[0]);
  

    printf("%s",str[2]);
    printf("%s",str[0]);
    printf("%s\n",str[1]);
    

    for(i=0;i<3;i++)
    {
        for(j=0;j<10;j++)
        {
            if(str[i][j] != '\0') putchar(str[i][j]);
            else break;
        }
    }
    printf("\n");





    return 0;
}