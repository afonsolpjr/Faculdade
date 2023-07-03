#include <stdio.h>
#include <stdlib.h>

#define STR_SIZE 100


typedef struct _endereco
{
    long int ip;
    char *info;
}ENDERECO;

void printb(long int n)
{
    long int i,c;
    for(i=31;i>=0;i--)
    {
        if(n & (1<<i))
        {
            c=i;
            break;
        }
    }
    putchar('\n');
    for(i=c;i>=0;i--)
    {
        if(n & (1<<i))
            putchar('1');
        else
            putchar('0');
    }
    putchar('\n');
}


ENDERECO* reader()
{
    long int temp,i,num;
    char *info,c;
    ENDERECO *ptr;

    /*alocando string pra info */
    info = malloc(sizeof(char)*STR_SIZE);
    /*Construir long int com o endereço inteiro*/
    num = 0;
    for(i=0;i<4;i++)
    {
        scanf("%ld",&temp);
        getchar();
        num += temp;
        // printb(num);
        if(i!=3)
            num = (num << 8);
    
    }
    // printb(num);

    /* Ler string no fim da linha.*/
    i=0;
    while( (c=getchar()) )
    {
        if((c!='\n'))
        {
            info[i++]=c;
        }
        else
        {
            info[i++]='\0';
            break;
        }
    }

    ptr = malloc(sizeof(ENDERECO));
    ptr->ip = num;
    ptr->info = info;

    return ptr;
}

int main()
{
    int num_linhas,i;
    ENDERECO *enderecos;

    /* ler n de linhas */
    scanf("%d",&num_linhas);

    /* alocar n enderecos */
    enderecos = malloc(num_linhas*sizeof(ENDERECO));

    /* ler endereços */
    for(i=0;i<num_linhas;i++)
    {
        enderecos[i]=*(reader());
    }

    // /* debug da leitura */
    // for(i=0;i<num_linhas;i++)
    // {
    //     printf("\n\nendereco %d:\n%s",i,enderecos[i].info);
    //     printb(enderecos[i].ip);
    // }

    return 0;
}