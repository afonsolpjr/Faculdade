#include <stdio.h>
#include <stdlib.h>

/* FUNÇÕES DA HEAP MINIMA */

int check_node(int *heap, int node) // Alterações a fazer caso queira heap max ou min.
{
    if(node==0)
    {
        return check_node(heap,1);
    }
    else if(node > 0)
    {
        // <= para heap max
        // >= para heap min
        if(heap[node] >= heap[(node/2)])
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

void subir(int *heap,int alvo)
{
    int temp,alvo_troca;

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

void descer(int *heap,int n, int alvo) // Alterações a fazer caso queira heap max ou min
{
    int alvo_troca,temp;
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
                heap[alvo_troca] < heap[alvo_troca+1] ? (alvo_troca) : (alvo_troca++);
            }

            temp = heap[alvo_troca];
            heap[alvo_troca] = heap[alvo];
            heap[alvo] = temp;
            alvo = alvo_troca;
        }
    }
    return;
}

void altera_prioridade(int *heap,int n, int alvo, int p_alvo)
{
    int aumento=0;

    if(p_alvo > heap[alvo])
        aumento=1;
    if(p_alvo < heap[alvo])
        aumento = 0;
    else
        return; //eh igual neahh

    heap[alvo] = p_alvo;

    while((alvo>0) && (alvo<n) && !check_node(heap,alvo)) //enqnt n satisfazer a propriedade das heaps
    {
        if(aumento) 
            subir(heap,alvo);
        else
            descer(heap,n,alvo);
    }
}

void insere(int *heap, int *n, int novo_p)
{
    heap[(*n)] = novo_p;
    subir(heap,(*n));
    (*n)++;
}

void print_heap(int *heap, int n)
{
    int i;
    puts("\n Heap:");

    for(i=0;i<n;i++)
        printf("[%d] ",heap[i]);

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

/* OUTRAS FUNÇÕES */ 


typedef struct _node
{
    int chave;
    int custo;
    struct _node *prox;

}NODE;

int main()
{
    /*
    Encontrar a árvore geradora minima de um grafo 
    Usando heap binária mínima, e Union find
    
    Entrada:
    N número de vértices, m arestas

    Seguidos de m linhas, dizendo qual os vértices q a aresta liga e o peso 
    */

    int i,n,m, link[2],custo;
    NODE *lista_adj;

    scanf("%d %d", &n,&m);

    //printf("\nn = %d    m = %d\n",n,m);
    lista_adj = (NODE*) calloc(n,sizeof(NODE));
    
    if(lista_adj == NULL)
        return 1;

    i=0;
    while(i<m)
    {
        scanf("%d %d %d",link,&(link[1]),&custo);
        // printf("\n\t%d %d %d\n", link[0],link[1],custo);
        i++;
        
        //criar lista de adjacencias
    }

}