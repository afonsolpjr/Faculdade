#include <stdio.h>
#include <stdlib.h>

typedef struct __no
{
    int chave,altura;
    struct __no *esq;
    struct __no *dir;
}NO;

NO* busca(NO* raiz, int n)
{
    if(raiz==NULL)
        return NULL;


    if(n==raiz->chave)
        return raiz;
    else if(n>raiz->chave)
        return busca(raiz->dir,n);
    else
        return busca(raiz->esq,n);

}

void print_preordem(NO *raiz)
{
    if(raiz == NULL)
    {
        return;
    }
    printf(" [%d] ",raiz->chave);
    print_preordem(raiz->esq);
    print_preordem(raiz->dir);

}

void insere_no(NO **ptr_raiz,int n)
{
    NO *raiz = *ptr_raiz;
    if( raiz == NULL)
    {
        *ptr_raiz = raiz = (NO*) malloc(sizeof(NO));
        raiz->chave = n;
        raiz->dir = NULL;
        raiz->esq = NULL;
        raiz->altura = 1;
        return;
    }
    if( busca(raiz,n) !=NULL) //sem dupliocatas
        return;
    

    
    if(n > raiz->chave)
    {
        insere_no(&(raiz->dir),n);
        raiz->altura = raiz->dir->altura + 1;
    }
    else
    {
        insere_no(&(raiz->esq),n);
        raiz->altura = raiz->esq->altura +1;
    }
}

void print_pos_ordem(NO* raiz)
{
    if(raiz == NULL)
        return;

    printf(" [%d] ",raiz->chave);
    print_pos_ordem(raiz->dir);
    print_pos_ordem(raiz->esq);
}

void print_ordem(NO* raiz)
{
    if(raiz==NULL)
        return;

    if( raiz->esq != NULL )
    {
        print_ordem(raiz->esq);
        printf(" [%d] ",raiz->chave);
        print_ordem(raiz->dir);
    }
    else
    {
        printf(" [%d] ",raiz->chave);
        print_ordem(raiz->dir);
    }
    return;


}



int main()
{

    NO *p_raiz = NULL;
    int chave,i;
    puts("Insira numeros para insercao na arvore\n");
    while( (scanf("%d",&chave)) && (chave!= 0) )
    {
        insere_no(&p_raiz,chave);
    }

    printf("\nArvore em pre-ordem : ");
    print_preordem(p_raiz);

    printf("\nArvore em pos-ordem: ");
    print_pos_ordem(p_raiz);

    printf("\nArvore em ordem: ");
    print_ordem(p_raiz);
    
    for(i=0;i<5;i++)
    {
        printf("\nbuscando valor [%d]",i);
        if(busca(p_raiz,i)!=NULL)
        {    
            printf("\n\tValor [%d] esta na arvore!",i);
        }
    }
    return 0;
}