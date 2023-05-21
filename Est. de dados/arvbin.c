#include <stdio.h>
#include <stdlib.h>

typedef struct __no
{
    int chave,altura,regulagem;
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

void calc_regulagem(NO* raiz)
{
    int *regulagem = &(raiz->regulagem);

    if(raiz->dir==NULL && raiz->esq==NULL)
        *regulagem=0;
    else if(raiz->dir==NULL)
        *regulagem = raiz->esq->altura;
    else if (raiz->esq==NULL)
        *regulagem = - (raiz->dir->altura);
    else
        *regulagem = raiz->esq->altura - raiz->dir->altura;


}

int altura(NO* raiz)
{
    int e,d;
    if(raiz==NULL)
        return 0;
    e = altura(raiz->esq);
    d = altura(raiz->dir);
    if(e>d)
    {
        raiz->altura = e+1;
        return e+1;
    }
    else
    {
        raiz->altura = d+1;
        return d+1;
    }
    
}
void rot_right(NO** p_raiz)
{
    NO *a,*b,*raiz = *p_raiz;
    a=raiz;
    b=a->esq;

    *p_raiz = b;
    a->esq = b->dir;
    b->dir = a;

    altura(b);
    calc_regulagem(b);
    calc_regulagem(a);
}

void rot_left(NO** p_raiz)
{
    NO *a, *b, *raiz = *p_raiz;
    a = raiz;
    b = a->dir;

    *p_raiz = b;

    a->dir = b->esq;
    b->esq = a;
    
    altura(b);
    calc_regulagem(b);
    calc_regulagem(a);
}

void rot_lr(NO** p_raiz)
{
    NO *raiz = *p_raiz;

    rot_left(&(raiz->esq));
    rot_right(p_raiz);
}

void rot_rl(NO** p_raiz)
{
    NO *raiz = *p_raiz;

    rot_right(&(raiz->dir));
    rot_left(p_raiz);
}

void regula_no(NO** p_raiz)
{
    NO *raiz = *p_raiz;
     /* processos de regulagem*/
    if(raiz->regulagem > 1)      //pendeu p esquerda
    {
        if(raiz->esq->regulagem > 0)     // esquerda dnv
            rot_right(p_raiz);
        else
            rot_lr(p_raiz);
    }
    else if (raiz->regulagem < -1)
    {
        if(raiz->dir->regulagem < 0)
            rot_left(p_raiz);
        else
            rot_rl(p_raiz);
    }
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
        calc_regulagem(raiz);

        return;
    }
    if( busca(raiz,n) !=NULL) //sem dupliocatas
        return;
    

    
    if(n > raiz->chave)
    {
        insere_no(&(raiz->dir),n);
    }
    else
    {
        insere_no(&(raiz->esq),n);
    }
    
    altura(raiz);
    calc_regulagem(raiz);
    regula_no(ptr_raiz);
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
    
    for(i=0;i<p_raiz->chave;i++)
    {
        printf("\nbuscando valor [%d]",i);
        if(busca(p_raiz,i)!=NULL)
        {    
            printf("\n\tValor [%d] esta na arvore!",i);
        }
    }
    return 0;
}