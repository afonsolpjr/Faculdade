#include <stdio.h>
#include <stdlib.h>


typedef struct _NO
{
    int chave;
    struct _NO *esq;
    struct _NO *dir;
}NO;


int buscar(NO *arvore,long int n, int *nivel_busca, NO **ultimo_no)
{
    int i;

    /* obtendo tamanho da palavra */
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
                break;
        }
        else // se bit = 0
        {
            if(arvore->esq!=NULL)
                arvore=arvore->esq;
            else
                break;
        
        }
        // printf("tem o %d bit!\n",32-i);
    }
    
    if(arvore->chave==n) // chegou, mas tem a info?
        return 1;
    else
    {
        *nivel_busca=i;
        *ultimo_no=arvore;    
        return 0;
    }
}

void adicionar(NO* arvore, int n,int pos_inicio)
{
    int i;
    // /* obtendo tamanho */
    // for(i=31;i>=0;i--)
    // {
    //     if(n & (1<<i))
    //         break;
    // }
    i=pos_inicio;
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
    int opcao=-1,nivel_busca;

    NO *arvore,*ultimo_no_busca;


    /* alocando arvore */

    arvore = malloc(sizeof(NO));
    arvore->dir=NULL;
    arvore->esq=NULL;
    arvore->chave=-1;
    ultimo_no_busca=arvore;

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
            if(buscar(arvore,num,&nivel_busca,&ultimo_no_busca))
                puts("\n\tNumero ja esta na arvore!!\n");
            else
                adicionar(ultimo_no_busca,num,nivel_busca);
            break;
        
        case 2:
            puts("\n Buscar: ");
            scanf("%ld",&num);
            if(buscar(arvore,num,&nivel_busca,&ultimo_no_busca))
                puts("\n\tNumero esta na arvore!!\n");
            else
                puts("\n\tNao esta na arvore!!");
            break;

        }
    }

    return 0;
}