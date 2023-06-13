#include <stdio.h>
#include <stdlib.h>
/* ESTRUTURAS */
typedef struct _aresta
{
    int v1;
    int v2;
    int custo;
}ARESTA;

typedef struct _node
{
    int chave;
    int custo;
    struct _node *prox;

}NODE;
/* FUNÇÕES DA HEAP MINIMA */

int check_node(ARESTA *heap, int node) // Alterações a fazer caso queira heap max ou min.
{
    if(node==0)
    {
        return check_node(heap,1);
    }
    else if(node > 0)
    {
        // <= para heap max
        // >= para heap min
        if(heap[node].custo >= heap[(node/2)].custo)
            return 1;
        else 
            return 0;
    }
    else
    {
        puts("Tinha nem que chegar aqui mano");
        return -1;
    }
}

void subir(ARESTA *heap, int alvo)
{
    int alvo_troca;
    ARESTA temp;

    while( alvo>0 && !check_node(heap,alvo))
    {
        alvo_troca = alvo/2;

        temp = heap[alvo_troca];
        heap[alvo_troca] = heap[alvo];
        heap[alvo] = temp;

        alvo = alvo_troca;
    }

    return;
}

void descer(ARESTA *heap,int n, int alvo) // Alterações a fazer caso queira heap max ou min
{
    int alvo_troca;
    ARESTA temp;
    if(alvo==0)
    {
    
    }
    while( (alvo_troca = 2*alvo)<=n && !check_node(heap,alvo_troca) )
    {
        if(alvo_troca<=n)
        {
            if(alvo_troca<n)
            {
            //caso heap-max = perguntar se é maior
            //caso heap-min = perguntar se é o menor
                heap[alvo_troca].custo < heap[alvo_troca+1].custo ? (alvo_troca) : (alvo_troca++);
            }

            temp = heap[alvo_troca];
            heap[alvo_troca] = heap[alvo];
            heap[alvo] = temp;
            alvo = alvo_troca;
        }
    }
    return;
}

void altera_prioridade(ARESTA *heap,int n, int alvo, int p_alvo)
{
    int aumento=0;

    if(p_alvo > heap[alvo].custo)
        aumento=1;
    if(p_alvo < heap[alvo].custo)
        aumento = 0;
    else
        return; //eh igual neahh

    heap[alvo].custo = p_alvo;

    while((alvo>0) && (alvo<n) && !check_node(heap,alvo)) //enqnt n satisfazer a propriedade das heaps
    {
        if(aumento) 
            subir(heap,alvo);
        else
            descer(heap,n,alvo);
    }
}

void insere(ARESTA *heap, int m /*n de arestas*/, ARESTA novo_p)
{
    heap[m-1] = novo_p;
    subir(heap,m-1);
}

void print_heap(ARESTA *heap, int n)
{
    int i;
    puts("\n Heap:");

    for(i=0;i<n;i++)
        printf("[%d] ",heap[i].custo);

    puts("\n Checaguem da propriedade: ");
    for(i=0;i<n;i++)
    {
        if(check_node(heap,i))
            putchar('Y');
        else
            putchar('N');
    }
    puts("\n");
    
}

void remover(ARESTA *heap,int alvo,int *n)
{
    heap[0] = heap[(*n)-1];
    descer(heap,0)

}
/* OUTRAS FUNÇÕES */ 


int main()
{
    /*
    Encontrar a árvore geradora minima de um grafo 
    Usando heap binária mínima, e Union find
    
    Entrada:
    N número de vértices, m arestas

    Seguidos de m linhas, dizendo qual os vértices q a aresta liga e o peso 
    */

    int i,n,m,v1,v2,custo;
    ARESTA *arestas,input;
    NODE *lista_adj;

    scanf("%d %d", &n,&m);

    //printf("\nn = %d    m = %d\n",n,m);
    //lista_adj = (NODE*) calloc(n,sizeof(NODE));

    arestas = (ARESTA*) calloc(m,sizeof(ARESTA));


    i=0;
    while(i<m)
    {
        scanf("%d %d %d",&v1,&v2,&custo);
        // printf("\n\t%d %d %d\n", link[0],link[1],custo);
        input.v1=v1;
        input.v2=v2;
        input.custo = custo;
        i++;
        insere(arestas,i,input);
    }

    print_heap(arestas,m);
    // for(i=0;i<m;i++)
    //     printf("Aresta %d = %d %d %d\n",i,arestas[i].v1, arestas[i].v2,arestas[i].custo);
}


/*
5 4
0 1 5
0 2 3
2 3 1
4 3 2
*/
