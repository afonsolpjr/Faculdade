#include <stdio.h>
#include <stdlib.h>

/*  HEAPS BINOMIAIS
Formadas por árvores binomiais de ordem distintas.

    Revisando arvore binomial: 
        * Uma arvore binomial B_h tem uma ordem de h. 
        * A ordem de uma árvore binomial é o numero de filhos de sua raiz.
        * Uma àrvore de ordem B_h tem 2^h nós.
        * Cada nível tem ( h / j-1 ) nós. (combinação de h escolhe j-1)
        * Altura = log(n)
    
Uma heap  binomial H pode ser representada por um número binário. 
Possuindo log(n) árvores binomiais.
*/

/* 
Implementando árvores binomiais. 
A prioridade de um nó é sempre maior que a de seus filhos, e menor que a de seu pai.
*/
typedef struct __no
{
    int chave,n_filhos, tam_ptr;
    struct __no **ptr;
}NO;

void subordina(NO *arv1, NO *arv2)
{
    NO *dom, *sub;       // kkkk
    // Ver qual raiz tem prioridade maior, pra ser a dominante.
    if(arv1->chave > arv2->chave)
    {
        dom = arv1;
        sub = arv2;
    }
    else
    {
        dom = arv2;
        sub = arv1;
    }

    //Realocar ponteiros de filhos de dom, caso n haja espaço.
    dom->n_filhos++;
    if(dom->tam_ptr == dom->n_filhos)
    {
        dom->tam_ptr = 2*dom->tam_ptr;
        dom->ptr = (NO**) realloc(dom->ptr,dom->tam_ptr*sizeof(NO*));
    }
    //subordinar
    dom->ptr[dom->n_filhos-1] = sub;

}

/*
    Implementando Heaps
*/

typedef struct __heap
{
    int n_nos,tam_ptr;
    NO ** arvores; 
}HEAP;

HEAP* init_heap(int n)
{
    HEAP *ptr;
    //Inicializando heap
    ptr = (HEAP*) malloc(sizeof(HEAP));
    ptr->n_nos = 1;
    ptr->tam_ptr = 2;
    //inicializando arvore B_0
    ptr->arvores = (NO**) calloc(ptr->tam_ptr,sizeof(NO*));
    ptr->arvores[0] = (NO*) malloc(sizeof(NO));
    ptr->arvores[0]->chave = n;
    ptr->arvores[0]->n_filhos=0;
    ptr->arvores[0]->tam_ptr=2;
    ptr->arvores[0]->ptr = calloc(2,sizeof(NO*));

    return ptr;
}

void fusao(HEAP* h1, HEAP* h2) //ih rapaz complicou vou largar de base esse codigo (01/7/23)
{
    int c = 0, menor, i;
    
    if(h1->n_nos > h2->n_nos)
        menor = h2->n_nos;
    else
        menor = h1->n_nos;

    for(i=0;i<menor;i++)
    {
        if((h1->n_nos) & (1<<i)) ((menor) & (1<<i))
    }
    
    

    return;
}

int main()
{
    int numero, i,n;
    HEAP* h1,h2;

    printf("Digite um valor de prioridade:\n");
    scanf("%d",&n);

    h1 = init_heap(n);


    return 0;
}