#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>

/* 
1. No programa de multiplicação de matrizes mostramos uma forma de paralelizar

o algoritmo de multiplicação de matrizes criando um fluxo de execução indepen-
dente para calcular cada um dos elementos da matriz de saída. Proponha outra

solução onde a tarefa de cada fluxo de execução seja calcular uma linha inteira da
matriz de saída. */

typedef struct{
    int n;
    float *linha;
    float **matriz;
}thr_arg;


/**
 * @brief Checa por erros de alocação de arrays.
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
 * @brief Printa matriz 'm' de dimensão n
 * @param m matriz
 * @param n dimensao de m
 */
void printa_matriz(float **m, int n)
{
    int i,j;
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            printf(" %f ",m[i][j]);
        }
        putchar('\n');
    }
    putchar('\n'); 
}


/**
 * @brief Multiplica uma linha por uma matriz.
 * @param targs Estrutura contendo:
 * @param n dimensão do array/matriz quadrada
 * @param linha array/linha
 * @param matriz matriz 
 * @return 
 */
void * thr_calc_linha_matriz(void *targs)
{
    thr_arg *args;
    float *resultado;
    int i;

    args = (thr_arg*) targs;

    resultado = (float*) malloc(sizeof(float)*args->n);
    alloc_check((void*) resultado);

    for ( i = 0; i < args->n ; i++)
    {
        resultado[i]=produto_interno_seq(args->linha,args->matriz[i],args->n);
    }
    free(args);
    pthread_exit((void*)resultado);
}



int valida_intarg(int pos, int argc, char *argv[])
{
    int val;
    
    if(pos>=argc)
    {
        printf("Não foram inseridos argumentos suficientes.\n\tEsperado %d\n\tInseridos: %d\n",pos,argc);
        exit(1);
    }

    val = atoi(argv[pos]);
    
    if(!val)
    {
        printf("Valor inválido para o %dº argumento.",pos);
        exit(1);
    }
    return val;
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

    // printa_matriz(m,n);
    
    return m;
        
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


/**
 * @brief Compara e retorna diferença agregada entre cada elemento das matrizes
 * @param a matriz a
 * @param b matriz b
 * @param n dimensão das matrizes
 */
float matdiff(float **a,float **b,int n){
    int i,j;
    double diff;
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

/**
 * @brief Realiza uma multiplicação de matrizes a e b de forma concorrente.
 * Cada thread computa uma linha, 
 * utilizando a matriz bT (inversa de b) e o produto interno entre linhas de a e bT
 * @param a matriz a
 * @param b  matriz b
 * @param n dimensao das matrizes
 * @return 
 */
float **thr_matmul_prod_int(float **a, float **b, int n)
{
    int i;
    float **c,**bT;
    pthread_t *thr_ids;
    thr_arg *args;


    /* criar identificadores de threads. Serão n threads */
    thr_ids = (pthread_t*) malloc(sizeof(pthread_t)*n);
    alloc_check(thr_ids);

    // invertendo matriz pra facilitar o calculo dos elementos
    bT = inverter_matriz(b,n);

    for ( i = 0; i < n; i++)
    {
        //criando n fluxos de execucao, um para cada linha
        args = (thr_arg*) malloc(sizeof(thr_arg));
        alloc_check(args);

        args->linha = a[i];
        args->matriz = bT;
        args->n = n;

        if(pthread_create(&thr_ids[i],NULL,thr_calc_linha_matriz,(void*)args)){
            printf("\nErro na criação da thread n° %d",i);
            exit(1);
        }

    }
    
    //esperar por threads para popular matriz resultado
    c = (float**) malloc(sizeof(float*)*n);
    alloc_check(c);
    for ( i = 0; i < n; i++)
    {
        // c[i] = (float*) malloc(sizeof(float)*n);
        // alloc_check(c[i]);
        
        if(pthread_join(thr_ids[i],(void**)&c[i])){
            printf("Erro no retorno da thread n°%d",i);
        }
    }

    return c;
}

int main(int argc, char *argv[])
{
    int n;
    float **a,**b,**c_seq,**c_conc;
  
    srand(time(NULL));
    //receber tamanho de n como argumento
    n = valida_intarg(1,argc,argv);

    //criar matrizes
        // alocando ponteiros pra linhas
    a = matriz_float_aleatoria(n);
    b = matriz_float_aleatoria(n);

    
      // calculando resultado sequencial
      c_seq = matmul(a,b,n);
      printf("\n\tmultiplicacao sequencial feita\n");
  
      /* resultado concorrente */
      c_conc = thr_matmul_prod_int(a,b,n);
      printf("\tmultiplicação concorrente feita\n");
  
    
   
    // puts("matriz conc:\n");
    // printa_matriz(c_conc,n);

    printf("Diferença agregada das matrizes: %.16f\n",matdiff(c_seq,c_conc,n));
    printf("matrizes iguais? %d\n",mat_equal(c_conc,c_seq,n));
    printf("endereços iguais? %d\n",(c_conc==c_seq) );

    return 0;
}