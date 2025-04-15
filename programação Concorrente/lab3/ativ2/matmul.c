#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

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

void fread_check(size_t n){
    if(!n){
        printf("\n\t Erro em leitura de arquivo.\n");
        exit(1);
    }
    return;
}
    

/* 
 @brief Calcula produto interno entre 2 vetores (de forma sequencial)
 @param v1: primeiro vetor
 @param v2: segundo vetor
 @param n: tamanho dos vetores
 @return (float) produto interno de v1 e v2
*/
float dotprod_seq(float *v1,float *v2,int n){
    int i;
    float resultado=0;
    for(i=0;i<n;i++)
        resultado+=(v1[i]*v2[i]);
    return resultado;
}

void vec_print(float *vec,int n){
    int i;
    for ( i = 0; i < n; i++)
        printf(" %f ",vec[i]);
    return;
}

/**
 * @brief Printa matriz 'm' de dimensão (n x m)
 * @param m matriz
 * @param n dimensao de m
 */
void mat_print(float *mat, int n, int m)
{
    int i;
    for ( i = 0; i < n; i++)
    {
        vec_print(&mat[i*n],m);
        putchar('\n');
    }
    putchar('\n'); 
}

/**
 * @brief Lê duas matrizes alocadas continuamente no arquivo de nome filename
 * @param filename nome do arquivo binario
 * @param a ponteiro para matriz a
 * @param b ponteiro para matriz b
 * @return dimensao da matriz
 */
int matmul_bin_reader(char filename[],float **a, float**b)
{
    FILE *file_ptr;
    int n;

    file_ptr = fopen(filename,"r");

    fread_check(fread(&n,sizeof(int),1,file_ptr));
    
    /* Se for alocar blocos contiguos */
    // a = (float(*)[]) malloc(sizeof(float)*n*n);
    // b = (float*) malloc(sizeof(float)*n*n);
    // c = (float*) malloc(sizeof(float)*n*n);


    *a = (float*) malloc(sizeof(float)*n*n);
    alloc_check(*a);
    fread_check(fread(*a,sizeof(float),n*n,file_ptr));
    // mat_print(*a,n,n);
    
    

    *b = (float*) malloc(sizeof(float)*n*n);
    alloc_check(*b);
    fread_check(fread(*b,sizeof(float),n*n,file_ptr));
    
    // printf("\n\tdimensão = %d, a=b? %d\n",n,(*a==*b));

    // mat_print(*b,n,n);
    
    // c = (float*) malloc(sizeof(float)*n*n);
    // fread(c,sizeof(float),n*n,file_ptr);
    
    // mat_print(a,n,n);
    // mat_print(b,n,n);

    // mat_print(c,n,n);
    return n;
}

/**
 * @brief Estrutura para thr_matmul
 */
typedef struct{
    int n;
    float *linha_inicial_a;
    int carga;
    float *b;
    float *linha_inicial_c;
}thr_matmul_args;

/**
 * @brief Tarefa a ser executada pela matmul_conc
 * @param t_arg 
 * @return 
 */
void *thr_matmul(void *t_arg){
    thr_matmul_args *args;
    float *aux_a,*aux_b,*aux_c;
    int i,j;

    args = (thr_matmul_args*) t_arg;
    for ( i = 0; i < args->carga; i++){
        //calcular linha inteira
        aux_a = &args->linha_inicial_a[ i*args->n ];
        aux_c = &args->linha_inicial_c[ i*args->n ];

        // printf("\n\t linhas (a,b) que vou trabalhar:");
        // vec_print(aux_a,args->n);

        for ( j = 0; j < args->n; j++)
        {
            //calcular cada elemento
            aux_b = &args->b[ j*args->n ];
            aux_c[j] = dotprod_seq(aux_a,aux_b,args->n);
            // printf("\nLinha de b\n");
            // vec_print(aux_b,args->n);
            // printf("\nResultado: %f",aux_c[j]);
        }        
    }
    free(args);
    // puts("frim da thread");
    pthread_exit(NULL);
}


/**
 * @brief Cria threads para execucao de multiplicacao matriz x matriz
 * Divide o numero de linhas a serem calculadas entre as threads
 * 
 * @param n numero de linhas da matriz
 * @param m numero de colunas da matriz / linhas do vetor
 * @param n_threads numero de threads
 * @param a matriz a 
 * @param b matriz b
 * @return matriz c, resultante de a*b, como vetor contínuo
 */
float * matmul_conc(int n,int n_threads,float *a,float *b){
    int i,linha_inicial_c,carga;
    pthread_t *thr_ids;
    thr_matmul_args *t_args;
    float *c;

    /* o que cada thread precisa?
        - numero de linhas a serem calculadas
        - linha inicial de "a" a ser operada
        - dimensao da matriz
        - matriz b
        - linha inicial c para guardar resultados
        */
    thr_ids = (pthread_t*) malloc(sizeof(pthread_t)*n_threads);
    alloc_check((void*)thr_ids);

    c = (float*) malloc(sizeof(float)*n*n);

    carga = n/n_threads;
    linha_inicial_c = 0;
    for ( i = 0; i < n_threads; i++)
    {
        t_args = (thr_matmul_args*) malloc(sizeof(thr_matmul_args));
        alloc_check((void*)t_args);

        t_args->linha_inicial_a = &a[linha_inicial_c*n];
        t_args->n = n;
        t_args->b = b;
        t_args->carga = (i < (n%n_threads)? carga+1 : carga);
        t_args->linha_inicial_c = &c[linha_inicial_c*n];
        linha_inicial_c += t_args->carga;

        // printf("\n\tthread %d criada",i);

        if(pthread_create(&thr_ids[i],NULL,thr_matmul,(void*)t_args)){
            printf("Erro na criação da threads nº %d\n",i);
            exit(1);
        }
    }

    // esperar fim das threads

    for ( i = 0; i < n_threads; i++)
    {
        if(pthread_join(thr_ids[i],NULL)){
            printf("Erro no retorno da thread nº %d",i);
            exit(1);
        }
    }
    
    return c;
    
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


typedef struct{
    double init, exec, term;
    int dim,n_thr;
}exec_data;


/**
 * @brief Printa dados da execucao
 * @param data 
 */
void print_exec_data(exec_data *data){
    printf("%%flag,%d,%d,%f,%f,%f",
        data->n_thr,
        data->dim,
        data->init,
        data->exec,
        data->term);
    return;
}

double actual_time() {
    struct timespec tempo;
    clock_gettime(CLOCK_MONOTONIC_RAW, &tempo);
    return tempo.tv_sec + tempo.tv_nsec/1000000000.0;
}


/**
 * @brief Multiplica de forma sequencial a matriz quadrada 'a' pela matriz 'b'
 * @param a matriz a
 * @param b matriz b
 * @param n dimensão das matrizes
 */
float *matmul(float *a,float *b,int n){
    float *c,soma;
    int i,j,k;
    c = (float*) malloc(sizeof(float)*n*n);
    alloc_check(c);

    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
            soma = 0;
            for ( k = 0; k < n; k++)
                soma += a[i*n + k] * b[k*n+ j];
            c[i*n + j]=soma;
        }    
    }

    return c;
}

/**
 * @brief Retorna a matriz m transposta
 * @param m matriz a ser transposta
 * @param n dimensão de m
 * @return matriz m transposta
 */
float *transp_mat(float *a, int n,int m){
    float *resultado;
    int i,j;

    resultado = (float*)malloc(sizeof(float)*n*m);
    alloc_check(resultado);

    // fazendo com que as colunas do resultado sejam as linhas de m
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
            resultado[i*n +j] = a[j*n + i];     
    }
    // printf("\n\tinvertida:\n");
    // mat_print(resultado,n); 
    free(a);   
    return resultado;
}


/**
 * @brief calcula e gera dados sobre multiplicacao matricial concorrente/sequencial
 * @param argc esperado que seja 2, <nome_binario> <numero de threads>
 * @param argv ./programa <nome_binario> <numero de threads>
 * @return ojsadoijdfsaiofjsid
 */
int main(int argc, char const *argv[])
{
    float *a,*b,*c;
    int n,n_threads;
    double inicio;
    exec_data data;
    //Inicializacao 
    inicio = actual_time();  

    n = matmul_bin_reader((char*)argv[1],&a,&b);
    
    data.dim = n;
    n_threads = valida_intarg(2,argc,(char**)argv);
    data.n_thr = n_threads;
    // printf("valor de n = %d\n",n);
    if(n_threads>1){
        //inverter matriz... ajuda mto
        // mat_print(b,n,n);
        // puts("\ntranspondo b\n");
        b = transp_mat(b,n,n);
    }
    // mat_print(a,n,n);
    // mat_print(b,n,n);
    // puts("\nmatriz lidas acima\n");
    data.init = actual_time() - inicio;
    //execucao do algoritmo
    inicio = actual_time();
    switch(n_threads){
    case 1:
        c = matmul(a,b,n);
        break;
    default:
        c = matmul_conc(n,n_threads,a,b);
        break;
    }
    data.exec = actual_time() - inicio;
    
    inicio = actual_time();
    free(a);
    free(b);
    free(c);
    data.term = actual_time() - inicio;
    print_exec_data(&data);
    // puts("\n");
    // mat_print(c,n,n);
    return 0;
}

/* Dados a serem guardados:
    - Tempo de processamento para:
        - Inicialização
        - Processamento
            - Sequencial
        - Finalização (um monte de free)

*/