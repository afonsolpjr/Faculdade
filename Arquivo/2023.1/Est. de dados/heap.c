#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    int *heap,n,opcao,tam,novo_p;


    tam = 10;
    heap = calloc(tam,sizeof(int));

    n = 0;

    opcao=-1;
    while(opcao!=0)
    {
        puts("\n Seleciona a operaçâo que deseja realizar:"
            "\n\t[1] Inserir nó na heap"
            "\n\t[2] Ver nó prioritário"
            "\n\t[3] Remover nó prioritário"
            "\n\t[4] Alteração de prioridades"
            "\n\t[5] Printar heap e checar prioridade"
            "\n\n Selecione a opcao desejada: ");

        scanf("%d",&opcao);

        switch(opcao)
        {
        case 0:
            return 0;

        case 1:
            if(n==tam) //aumentar tam
            {
                tam*=2;
                heap = realloc(heap,tam*sizeof(int));
            }
            puts("\n\t[INSERÇÃO DE NOVO NÓ]"
                "\nSelecione a prioridade do novo nó: ");
            scanf("%d",&novo_p);
            insere(heap,&n,novo_p);
            break; 

        case 2:
            printf("\n\t[SELEÇÃO DE NÓ PRIORITÁRIO]"
            "\n\t Maior prioridade = %d\n",heap[0]);
            break; 

        case 3:
            printf("\n\t[REMOÇÃO DE NÓ PRIORITÁRIO]\n");
            n--;
            heap[0] = heap[n];
            descer(heap,n,0);
            break;

        case 4:
            break;

        case 5:
            print_heap(heap,n);
            break;

        }
    }

}