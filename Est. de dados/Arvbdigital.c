#include <stdio.h>
#include <stdlib.h>


typedef struct _NO
{
    int chave;
    struct _NO *esq;
    struct _NO *dir;
}NO;


int buscar(NO *arvore,long int n)
{
    int i;

    /* obtendo tamanho */
    for(i=31;i>=0;i--)
    {
        if(n & (1<<i))
            break;
    }

    for(;i>=0;i--)
    {
        if( n & (1<<i)) //se bit =1
        {
            if(arvore->dir!=NULL)
                arvore=arvore->dir;
            else
                return 0;
        }
        else // se bit = 0
        {
            if(arvore->esq!=NULL)
                arvore=arvore->esq;
            else
                return 0;
        }
        // printf("tem o %d bit!\n",32-i);
    }
    
    if(arvore->chave==n) // chegou, mas tem a info?
        return 1;
    else
        return 0;
}

void adicionar(NO* arvore, int n)
{
    int i;
    /* obtendo tamanho */
    for(i=31;i>=0;i--)
    {
        if(n & (1<<i))
            break;
    }

    for(;i>=0;i--)
    {
        if( n & (1<<i) )
        {
            if(arvore->dir!=NULL)
                arvore=arvore->dir;
            else
            {
                arvore->dir = malloc(sizeof(NO));
                arvore = arvore->dir;
                arvore->dir=NULL;
                arvore->esq=NULL;
                arvore->chave=-1;
            }
        }
        else
        {
            if(arvore->esq!=NULL)
                arvore=arvore->esq;
            else
            {
                arvore->esq = malloc(sizeof(NO));
                arvore = arvore->esq;
                arvore->dir=NULL;
                arvore->esq=NULL;
                arvore->chave=-1;
            }
        }
    }
    arvore->chave=n;
}
int main()
{
    long int num;
    int opcao=-1;

    NO* arvore;


    /* alocando arvore */

    arvore = malloc(sizeof(NO));
    arvore->dir=NULL;
    arvore->esq=NULL;
    arvore->chave=-1;

   
    while(opcao!=0)
    {
         printf("\n\tEscolha:"
        "\n\t[0] Sair"
        "\n\t[1] Inserir num na arvore digital"
        "\n\t[2] Buscar num na arvore digital\n Selecao: ");

        scanf("%d",&opcao);

        switch(opcao)
        {
        case 0:
            return 0;

        
        case 1:
            puts("\n Inserir : ");
            scanf("%ld",&num);
            if(buscar(arvore,num))
                puts("\n\tNumero ja esta na arvore!!\n");
            else
                adicionar(arvore,num);
            break;
        
        case 2:
            puts("\n Buscar: ");
            scanf("%ld",&num);
            if(buscar(arvore,num))
                puts("\n\tNumero esta na arvore!!\n");
            else
                puts("\n\tNao esta na arvore!!");
            break;

        }
    }

    return 0;
}