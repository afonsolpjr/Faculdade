#include <stdio.h>
#define MAX_INPUT 4096
#define NAO_LIDO -1

int main()
{
    char string[MAX_INPUT];
    int i,num;
    puts("insira entrada:\n");


    while(1) /*  ler inteiros em cada linha */
    {
        if(fgets(string,MAX_INPUT,stdin)==NULL) /*le ate EOF*/
            break;
        
        i=0;
        while(string[i]!='\n' ) /* le ate o fim da linha*/
        {
            if(string[i]< '0' || string[i]>'9') /*avisa se tem char nao-digito, passa pro prox*/
            {
                num = NAO_LIDO;
                i++;
            }
            
            if(string[i]>= '0' && string[i]<='9') /* se tenho char que é digito*/
                num = 0;                            /*depois de um nao-digito, começo novo num*/

            while(string[i]>= '0' && string[i]<='9') /* basicamente um atoi */
            {
                num = (num * 10 ) + (string[i] - '0');
                i++;
            }

            if(num!=NAO_LIDO) /*se leu o num:*/
                printf("\n\tli o num=%d",num);
        }
    }    
    puts("fim do programa");
    return 0;
}