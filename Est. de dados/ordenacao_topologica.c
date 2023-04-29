#include <stdio.h>
#include <stdlib.h>
#define MAX_INPUT 4096
#define NAO_LIDO -1
#define CABECA -1


typedef struct _VERTICE
{
    int chave;

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
    int n_vertices,arestas,i,adj_lido,vertice_atual;
    VERTICE **lista_adj, *ptr_lista;
    char string[MAX_INPUT];

    scanf("%d",&n_vertices);

    scanf("%d",&arestas);
    getchar();

    /*alocar lista de adjacencias*/

    lista_adj = (VERTICE**) calloc(n_vertices,sizeof(VERTICE*));
    if(lista_adj==NULL)
    {
        puts("Erro alocando memoria.\n");
        return 1;
    }

    printf("li %d vertices e %d arestas\n",n_vertices,arestas);

    for(i=0;i<n_vertices;i++) /* alocando cabeças de lista */
    {
        lista_adj[i] = (VERTICE*) calloc(1,sizeof(VERTICE));
        
        lista_adj[i]->chave = CABECA;
        
        lista_adj[i]->anterior = NULL;
        lista_adj[i]->prox = NULL; 
        /*  printf("\n\tcabeça alocada chave=%d\n",lista_adj[i]->chave); */
    }

    vertice_atual = 0;

    while(vertice_atual<n_vertices) /*  ler inteiros em cada linha */
    {
        /* printf("\n vertice atual = %d\n",vertice_atual);
         */
        ptr_lista = lista_adj[vertice_atual];

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
                insere_lista(ptr_lista,adj_lido);
            }
        }

        vertice_atual++;
    }    

    printf(" \n[ TESTANDO LISTAS ] i=%d nv=%d\n",i,n_vertices);

    for(i=0;i<n_vertices;i++)
    {

        ptr_lista = lista_adj[i];

        printf("\nVertice %d adjacente a: ",i);
        while(ptr_lista!=NULL)
        {
            if(ptr_lista->chave != CABECA)
            {
                printf(" [%d] ",ptr_lista->chave);
            }
            ptr_lista = ptr_lista->prox;
        }
        puts("\n");

    }
    
    return 0;
}