#include <stdlib.h>
#include <stdio.h>


/* 
 @brief Calcula produto interno entre 2 vetores (de forma sequencial)
 @param v1: primeiro vetor
 @param v2: segundo vetor
 @param n: tamanho dos vetores
 @return (float) produto interno de v1 e v2
*/
float produto_interno_seq(float *v1,float *v2,int n){
    int i;
    float resultado=0;
    for(i=0;i<n;i++)
        resultado+=(v1[i]*v2[i]);
    return resultado;
}


/**
 * @brief Checa por erros de alocação de arrays. Encerra o programa caso a alocação não tenha funcionado.
 * @param ptr ponteiro/endereço a ser verificado uma alocação
 */
void alloc_check(void *ptr)
{
    if(ptr==NULL)
    {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }
}


/*
    @brief Popula, por referência, um vetor de tamanho @tam_vetor com valores quase-aleatórios (range de 0.01 a 500) em float.
    @param vetor: ponteiro para o vetor de floats
    @param tam_vetor: tamanho do vetor
*/
void vetor_float_aleatorio(float *vetor,int tam_vetor){
    float num_aleatorio;
    int i;
    for(i=0;i<tam_vetor;i++){
        num_aleatorio = 5.0/(rand()%500+1)*100;
        if(rand()%2)
            num_aleatorio*=-1;
        vetor[i]=num_aleatorio;
        // printf(" %f ",num_aleatorio);
    }
}

/**
* @brief Gera uma matriz quadrada de tamanho n, com floats quase aleatórios.
* @param m ponteiro para a matriz
* @param n dimensão da matriz
* @return ponteiro para a matriz alocada 
 */
float ** matriz_float_aleatoria(int n)
{
    int i;
    float **m;

    // alocando ponteiros pra linhas
    m = (float**) malloc(sizeof(float*)*n);
    alloc_check((void*) m);

    for ( i = 0; i < n; i++) //alocando linhas
    {
        m[i]= (float*) malloc(sizeof(float)*n);
        alloc_check((void*) m[i]);

        vetor_float_aleatorio(m[i],n);
    }

    /* for ( i = 0; i < tamanho; i++)
    {
        for ( j = 0; j < tamanho; j++)
        {
            printf(" %f ",a[i][j]);
        }
        puts("\n");
    }
     */
    return m;
        
}


/**
 * @brief Printa matriz 'm' de dimensão n
 * @param m matriz
 * @param n dimensao de m
 */
void printa_matriz(float **m, int n)
{
    int i,j;
    for ( i = 0; i < n; i++)
    {
        for ( int j = 0; j < n; j++)
        {
            printf(" %f ",m[i][j]);
        }
        putchar('\n');
    }
    putchar('\n'); 
}


/**
 * @brief Retorna a matriz m invertida
 * @param m matriz a ser invertida
 * @param n dimensão de m
 * @return matriz m invertida
 */
float **inverter_matriz(float **m, int n){
    float **resultado;
    int i,j;

    resultado = (float**)malloc(sizeof(float*)*n);
    alloc_check(resultado);

    for ( i = 0; i < n; i++)
    {
        resultado[i]= (float*) malloc(sizeof(float)*n);
        alloc_check(resultado[i]);
    }

    // fazendo com que as colunas do resultado sejam as linhas de m
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
            resultado[j][i]=m[i][j];     
    }
    // printf("\n\tinvertida:\n");
    // printa_matriz(resultado,n);    
    return resultado;
}


/**
 * @brief Multiplica de forma sequencial a matriz quadrada 'a' pela matriz 'b'
 * @param a matriz a
 * @param b matriz b
 * @param n dimensão das matrizes
 */
float **matmul(float **a,float **b,int n){
    float **c,soma;
    int i,j,k;
    c = (float**) malloc(sizeof(float*)*n);
    alloc_check(c);

    for ( i = 0; i < n; i++)
    {
        c[i] = (float*) malloc(sizeof(float)*n);
        alloc_check(c[i]);
    }

    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            soma = 0;
            for ( k = 0; k < n; k++)
                soma += a[i][k] * b[k][j];
            c[i][j]=soma;
        }    
    }

    return c;
}



// float **create_identity(int n) {
//     float **mat = (float**)malloc(n * sizeof(float*));
//     alloc_check(mat);
    
//     for (int i = 0; i < n; i++) {
//         mat[i] = (float*)calloc(n, sizeof(float));
//         alloc_check(mat[i]);
//         mat[i][i] = 1.0f;
//     }

//     mat[1][2]=3;
//     return mat;
// }

// float **create_sequential(int n) {
//     float **mat = (float**)malloc(n * sizeof(float*));
//     alloc_check(mat);
    
//     for (int i = 0; i < n; i++) {
//         mat[i] = (float*)malloc(n * sizeof(float));
//         alloc_check(mat[i]);
//         for (int j = 0; j < n; j++) {
//             mat[i][j] = i*n + j + 1;
//         }
//     }
//     return mat;
// }

/**
 * @brief Compara e retorna 1 caso as duas matrizes quadradas a e b sejam iguais
 * @param a matriz a
 * @param b matriz b
 * @param n dimensão das matrizes
 */
float matdiff(float** a,float** b,int n){
    int i,j;
    float diff;
    diff=0;
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            diff+=(a[i][j]-b[i][j]);
        }
    }
    return diff;
}

/**
 * @brief Multiplica de forma sequencial a matriz quadrada 'a' pela matriz 'b'. Utiliza o produto interno sequencial
 * @param a matriz a
 * @param b matriz b
 * @param n dimensão das matrizes
 */
float **matmul_prodint_seq(float **a,float **b,int n){
    float **c;
    int i,j;
    float **b_t;
    
    c = (float**) malloc(sizeof(float*)*n);
    alloc_check(c);

    b_t = inverter_matriz(b,n);

    for ( i = 0; i < n; i++)
    {
        c[i] = (float*) malloc(sizeof(float)*n);
        alloc_check(c[i]);

        for ( j = 0; j < n; j++)
            c[i][j]=produto_interno_seq(a[i],b_t[j],n);
    }
    free(b_t);
    return c;
}


/**
 * @brief Verifica se duas matrizes são exatamente iguais
 * @param a matriz a
 * @param b matriz b
 * @param n dimensao das matrizes
 * @return 1 caso sejam iguais, 0 caso diferente
 */
int mat_equal(float **a,float **b,int n){
    int i,j;
    
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            if(a[i][j]!=b[i][j])
                return 0;
        }
    }
    return 1;
}


int main(int argc, char *argv[])
{
    

    return 0;
}


