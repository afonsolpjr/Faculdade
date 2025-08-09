#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char *mat;
    int size;
} adj_matrix;

int *cria_matriz(int n_vertices)
{
    int i, *matriz,j;


    matriz = (int*) malloc(sizeof(int)*n_vertices*n_vertices);
    for(i=0;i<(n_vertices-1);i++)
    {
        for(j=i+1;j<(n_vertices-1);j++)
        {
            matriz[i * n_vertices + j] = rand()%2;
            matriz[j * n_vertices + i] = matriz[i*n_vertices + j];
        }
        
    }

    return matriz;
}
void    pmat(int *matriz,int size)
{
    int i,j;
    for (int i = 0; i < size; i++)
    {
        for ( j = 0; j < size; j++)
        {
            printf( "%d ", matriz[i*size + j]);
        }
        putchar('\n');
        
    }
    
}
int main()
{
    srand(time(NULL));
    printf("Olá %d\n", rand());

    adj_matrix 
    pt = cria_matriz(size);
    pmat(pt, size);
}