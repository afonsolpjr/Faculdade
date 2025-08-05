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
 * @brief Lê do descrito de arquivo f_ptr, e carrega a matriz mat,e o vetor vec
 * @param f_ptr Descritor de arquivo já aberto
 * @param mat ponteiro para o vetor a ser populado como a matriz
 * @param n numero de linhas da matriz
 * @param m numero de colunas da matriz
 * @return retorna o vetor vec
 */
float *matvec_bin_reader(FILE *f_ptr,float **mat, int n,int m){
    float *vec;

    *mat = (float*) malloc(sizeof(float)*n*m);
    alloc_check((void*)*mat);

    vec = (float*)malloc(sizeof(float)*m);
    alloc_check((void*)vec);

    fread_check(fread(*mat,sizeof(float),n*m,f_ptr));
    fread_check(fread(vec,sizeof(float),m,f_ptr));
    fclose(f_ptr);

    // mat_print(*mat,n,m);
    // vec_print(vec,m);
    return vec;
}


/**
 * @brief Multiplicação sequencial de Matrizes por vetores.  
 * @param n nº de linhas da matriz
 * @param m nº de colunas da matriz
 * @param a matriz de dimensoes (n x m)
 * @param b vetor de tamanho n
 * @return Resultado de "ab"
 */
float *matvet_seq(int n,int m,float *a,float *b){
    float *c;

    int i;

    c = (float*)malloc(sizeof(float)*n);
    alloc_check((void*)c);

    for ( i = 0; i < n; i++)
    {
            c[i] = dotprod_seq(&a[i*m],b,m);
    }
    return c;
}

/**
 * @brief Estrutura para thr_matvet
 */
typedef struct{
    int n;
    int m;
    float *linha_inicial;
    int carga;
    float *b;
    float *linhas_c;
}thr_args;

/**
 * @brief Tarefa a ser executada pela matvet_conc
 * @param t_arg 
 * @return 
 */
void *thr_matvet(void *t_arg){
    thr_args *args;
    float *aux;
    int i;

    args = (thr_args*) t_arg;
    for ( i = 0; i < args->carga; i++){

        aux = &args->linha_inicial[ i*args->m];
        // printf("\n\t linha que vou trabalhar:");
        // vec_print(aux,args->n);

        args->linhas_c[i] = dotprod_seq(aux,args->b,args->n);
    }
    free(args);
    pthread_exit(NULL);
}


/**
 * @brief Cria threads para execucao de multiplicacao matriz x vetor
 * Divide o numero de elementos a serem calculadis entre as threads
 * 
 * @param n numero de linhas da matriz
 * @param m numero de colunas da matriz / linhas do vetor
 * @param n_threads numero de threads
 * @param a matriz a 
 * @param b matriz b
 * @return matriz c, resultante de a*b, como vetor contínuo
 */
float * matvec_conc(int n,int m,int n_threads,float *a,float *b){
    int i,pos_inicial,carga;
    pthread_t *thr_ids;
    thr_args *t_args;
    float *c;
    /* o que cada thread precisa?
        - numero de elementos do vetor a ser calculado
        - linha inicial de "a" a ser operada
        - numero m de elementos do vetor (linhas de a / colunas de b)
        - matriz a
        - vetor b
        - vetor resultante
        */
    thr_ids = (pthread_t*) malloc(sizeof(pthread_t)*n_threads);
    alloc_check((void*)thr_ids);

    c = (float*) malloc(sizeof(float)*n);

    carga = n/n_threads;
    pos_inicial = 0;
    for ( i = 0; i < n_threads; i++)
    {
        t_args = (thr_args*) malloc(sizeof(thr_args));
        alloc_check((void*)t_args);

        t_args->linha_inicial = &a[pos_inicial*m];
        t_args->n = n;
        t_args->m = m;
        t_args->b = b;
        t_args->carga = (i < (n%n_threads)? carga+1 : carga);
        t_args->linhas_c = &c[pos_inicial];
        pos_inicial += t_args->carga;

        // printf("\n\tthread %d criada",i);

        if(pthread_create(&thr_ids[i],NULL,thr_matvet,(void*)t_args)){
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
    printf("%%tipo,%%flag,%d,%d,%f,%f,%f",
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

/* primeiro argumento: nome do binario
    segundo argumento: tipo de execucao (1 sequencial, 2 concorrente)
    terceiro argumento: numero de threads */

int main(int argc, char const *argv[])
{
    float *a,*b,*c;
    int n,m,n_threads;
    double inicio;
    FILE *f_ptr;
    exec_data data;
    
    //Inicializacao 
    c=NULL;
    inicio = actual_time();  

    f_ptr = fopen(argv[1],"r");
    fread_check(fread(&n,sizeof(int),1,f_ptr));
    fread_check(fread(&m,sizeof(int),1,f_ptr));
    b = matvec_bin_reader(f_ptr,&a,n,m);
    // mat_print(a,n,m);
    // vec_print(b,n);
    // puts("\ndados lidos sao os acima\n");
    data.dim = n;
    n_threads = valida_intarg(3,argc,(char**)argv);
    data.n_thr = n_threads;
    data.init = actual_time() - inicio;

    //execucao do algoritmo
    inicio = actual_time();
    // switch(execucao){
    // case 1:
    //     data.n_thr=1;
    //     c = matvet_seq(n,m,a,b);
    //     break;
    // case 2:
        c = matvec_conc(n,m,n_threads,a,b);
        // break;
    // }
    data.exec = actual_time() - inicio;
    
    inicio = actual_time();
    free(a);
    free(b);
    if(c)
        free(c);
    data.term = actual_time() - inicio;
    print_exec_data(&data);
    return 0;
}

/* Dados a serem guardados:
    - Tempo de processamento para:
        - Inicialização
        - Processamento
            - Sequencial
        - Finalização (um monte de free)

*/