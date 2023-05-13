#include <stdio.h>
#include <stdlib.h>
#define MAX_INPUT 4096
#define NAO_LIDO -1
#define CABECA -1


typedef struct _VERTICE
{
    int chave;
    int contador;
    struct _VERTICE *prox;
    struct _VERTICE *anterior;

}VERTICE;

void insere_lista(VERTICE *ptr_lista,int chave)
{

    while(ptr_lista->prox != NULL)
    {
        ptr_lista = ptr_lista->prox;
    }

    ptr_lista->prox = (VERTICE*) malloc(sizeof(VERTICE));

    ptr_lista->prox->chave = chave;
    ptr_lista->prox->prox = NULL;
    ptr_lista->prox->anterior = ptr_lista;
}

int main(int argc, char *argv[])
{
    int n_vertices,arestas,i,adj_lido,indice_atual,*ordem_topologica;
    VERTICE **lista_adj, *ptr_lista,*p_free;
    char string[MAX_INPUT];
    /* ler vertice e aresta*/
    scanf("%d",&n_vertices);

    scanf("%d",&arestas);
    getchar();
    /* printf("\nli %d vertices e %d arestas\n",n_vertices,arestas); */

    /*alocar lista de adjacencias*/

    lista_adj = (VERTICE**) calloc(n_vertices,sizeof(VERTICE*));
    if(lista_adj==NULL)
    {
        puts("Erro alocando memoria.\n");
        return 1;
    }
    /* alocar lista da ordem*/

    ordem_topologica = (int*) calloc(n_vertices,sizeof(int));

    /* alocar cabeça das listas*/
    for(i=0;i<n_vertices;i++) 
    {
        lista_adj[i] = (VERTICE*) calloc(1,sizeof(VERTICE));
        if(lista_adj[i]==NULL)
            return 1;

        lista_adj[i]->chave = CABECA;
        lista_adj[i]->contador=0;
        lista_adj[i]->anterior = NULL;
        lista_adj[i]->prox = NULL; 
        /*  printf("\n\tcabeça alocada chave=%d\n",lista_adj[i]->chave); */
    }

    indice_atual = 0;

    /*  ler inteiros em cada linha */
    while(indice_atual<n_vertices) 
    {
        // printf("\n vertice atual = %d\n",vertice_atual);
         
        ptr_lista = lista_adj[indice_atual];

        if(fgets(string,MAX_INPUT,stdin)==NULL) /*le ate EOF*/
            break;

        i=0;

        while(string[i]!='\n' ) /* le ate o fim da linha*/
        {
            if(string[i]< '0' || string[i]>'9') /*avisa se tem char nao-digito, passa pro prox*/
            {
                adj_lido = NAO_LIDO;
                i++;
            }
            
            if(string[i]>= '0' && string[i]<='9') /* se tenho char que é digito*/
                adj_lido = 0;                            /*depois de um nao-digito, começo novo num*/

            while(string[i]>= '0' && string[i]<='9') /* basicamente um atoi */
            {
                adj_lido = (adj_lido * 10 ) + (string[i] - '0');
                i++;
            }


            if(adj_lido!=NAO_LIDO) /*se leu o num:*/
            {
                adj_lido--;                   /*    PRESSUPONDO QUE AS ENTRADAS NAO COMEÇARAO DE 0*/
                insere_lista(ptr_lista,adj_lido);
                lista_adj[adj_lido]->contador++;
                // printf("\n\tvertice %d adj a [%d]",vertice_atual,adj_lido);
            }
        }

        indice_atual++;
    }    

    /* printf(" \n\t[ TESTANDO LISTAS ]");          //tudo funcionando normal */

    // for(i=0;i<n_vertices;i++)
    // {
    //     ptr_lista = lista_adj[i];
    //     printf("\nVertice %d tem %d antecedentes " 
    //             "e eh adjacente a: ",
    //              i+1,ptr_lista->contador);           /*    PRESSUPONDO QUE AS ENTRADAS NAO COMEÇARAO DE 0*/
    //     while(ptr_lista!=NULL)
    //     {
    //         if(ptr_lista->chave != CABECA)
    //         {
    //             printf(" [%d] ",ptr_lista->chave +1);
    //         }
    //         ptr_lista = ptr_lista->prox;
    //     }
    //     puts("\n");
    // } 
    
    
    indice_atual=0; i=0;
    while(indice_atual<n_vertices)   //cria o array da ordenação
    {
         /*procurar por quem tem contador = 0 e adicionar na ordem*/
            if(lista_adj[i]->contador==0)
            {
                // printf("\n zerando vertice %d",i);
                ordem_topologica[indice_atual] = i;
                indice_atual++;

                //retirando vertice
                lista_adj[i]->contador = -1;
                ptr_lista = lista_adj[i]->prox;
                lista_adj[i]->prox = NULL;

                while(ptr_lista!=NULL) //apaga lista de adj
                {
                    p_free = ptr_lista;
                    // printf("\n\t vertice %d orfao, diminuindo antecendente...",ptr_lista->chave);
                    lista_adj[ptr_lista->chave]->contador--;
                    if(lista_adj[ptr_lista->chave]->contador == 0)  
                        {
                            /* se zerou algum, reinicia o iterador pro começo da lista de adjacencias,
                            menos eficiente pq necessita mais comparações... */
                            i=0;
                            // printf("\n\t\torfao %d zerado ",ptr_lista->chave);
                        }
                    ptr_lista = ptr_lista->prox;

                    free(p_free);
                }
            }
            else
                i++;
    }
    
    //printf("\n\t ORDEM TOPOLOGICA: \n [");
    for(i=0;i<n_vertices;i++)
    {
        printf("%d ",ordem_topologica[i]+1 );
    }
    puts("\n");
    return 0;
}

/* alguns grafos 

echo "8 9
>> 2 3
>> 6
>> 4
>> 
>> 2 8
>> 7
>> 3
>> 6
>> " | ./teste
    ORDEM TOPOLOGICA:
 [  0    4    1    7    5    6    2    3  ]



echo "7 9
>> 2 3
>> 3 6
>> 4
>> 
>>
>> 5 4
>> 2 6
>> " | ./teste
ordem:

 [  0    6    1    2    5    3    4  ]




echo "6 8
>> 2 3
>> 4 5
>> 4 6
>> 5 6
>> 
>>
>> " | ./teste

    ORDEM TOPOLOGICA:
 [  0    1    2    3    4    5  ]

*/