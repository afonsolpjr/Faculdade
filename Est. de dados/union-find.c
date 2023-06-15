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

void remover(ARESTA *heap,int *n)  /*retira o primeiro nó*/
{
    *n -=1;
    heap[0] = heap[*n];
    descer(heap,*n,0);

}
/* OUTRAS FUNÇÕES */ 
int getChefe(int *chefe,int v)
{
    while(chefe[v]!=v)
        v = chefe[v];

    return v;
}

int main()
{
    /*
    Encontrar a árvore geradora minima de um grafo 
    Usando heap binária mínima, e Union find
    
    Entrada:
    N número de vértices, m arestas

    Seguidos de m linhas, dizendo qual os vértices q a aresta liga e o peso 
    */

    int i,n,m,*chefe,*altura,contador,chefe1,chefe2;
    ARESTA *arestas,input;

    scanf("%d %d", &n,&m);

    //printf("\nn = %d    m = %d\n",n,m);

    arestas = (ARESTA*) calloc(m,sizeof(ARESTA));
    chefe = (int*)calloc(n,sizeof(int));
    altura = (int*)calloc(n,sizeof(int));
    
    for(i=0;i<n;i++)
    {
        chefe[i]=i;
        altura[i]=0;
    }

    i=0;
    /* construindo heap min organizado pelo custo das arestas*/
    while(i<m)
    {
        scanf("%d %d %d",&(input.v1),&(input.v2),&(input.custo));
        // printf("\n\t%d %d %d\n", link[0],link[1],custo);
        i++;
        insere(arestas,i,input);
    }
    
    contador = 0;
    while(m>0) //enquanto existir arestas na heap
    {
        //checar se a aresta minima é externa 
        chefe1 = getChefe(chefe,arestas[0].v1);
        chefe2 = getChefe(chefe,arestas[0].v2);
        if(chefe1 != chefe2)
        {
            //fazer uniao dos conjuntos
            if(altura[chefe1]>altura[chefe2])
                chefe[chefe2]=chefe1;
            else
            {
                chefe[chefe1]=chefe2;
                if(altura[chefe1]==altura[chefe2])
                    altura[chefe2] = altura[chefe1] + 1;
            }
            // somar o peso da aresta analisada ao contador e descartar aresta
            contador += arestas[0].custo;
            remover(arestas,&m);
        }
        else // descartar aresta
            remover(arestas,&m);
    } 
    /*e se as arestas dadas nao gerarem uma arvore? */
    printf("%d",contador);
}


/*
5 6
0 1 4
0 2 3
1 3 1
2 3 3
2 4 4
4 3 2


*/
