#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[])
{
    int a,i=0,j,adj_lido,n_vertices, **adj_matrix;
    char c;
    //tentar fazer ler até encontrar newline, e aí incrementar

    //considerar que n e a não virão como argumentos

 
    scanf("%d",&n_vertices);

    scanf("%d",&a);

    //alocar matriz

    adj_matrix = (int**) calloc(n_vertices,sizeof(int*));
    if(adj_matrix==NULL)
    {
        puts("Erro em alocação dinamica.\n");
        return 1;
    }

    for(i=0;i<n_vertices;i++)
    {
        adj_matrix[i] = (int*) calloc(n_vertices,sizeof(int));
        if(adj_matrix[i]==NULL)
        {
            puts("Erro em alocação dinamica.\n");
            return 1;
        }
    }

    i=0;
    while(i<n_vertices)
    {
        if(scanf("%d",&adj_lido)!=1)
        {
            puts("\nnao li nd kk\n");
        }
        adj_matrix[i][adj_lido]=1;

        //printf("Vertice %d adjacente a %d\n",i,adj_lido);
        
    }
    while(getchar()!=EOF);

    

    for ( i = 0; i < n_vertices; i++)
    {
        for ( j = 0; j < n_vertices; j++)
        {
            printf("[ %d ] ",adj_matrix[i][j]);
        }
        puts("\n");
    }
    
    
    return 0;
}