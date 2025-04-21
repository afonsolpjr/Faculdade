#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>
#include <time.h>

long long int numero;
pthread_mutex_t mutex;

int ehPrimo(long long int n) 
{
    int i;
    if (n<=1) return 0;
    if (n==2) return 1;
    if (n%2==0) return 0;
    for (i=3; i<sqrt(n)+1; i+=2)
        if(n%i==0) return 0;

    return 1;
}

/**
 * @brief Valida se o argumento enviado à main na posição 'pos' é um inteiro.
 * @param pos posicao do argumento
 * @param argc arg counter da main
 * @param argv args da main
 * @return inteiro validado, caso contrario acusa erro e sai do programa
 */
long long int valida_intarg(int pos, int argc, char *argv[])
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


void * conc_factor(void *arg){
    long long int *n = (long long int*) arg;
    long long int atual;
    long int n_primos;

    // printf("[debug thread]\n"
    //     "\tn=%lld\n"
    //     "\tnumero=%lld\n",*n,numero);
    
    n_primos=0;

    while(1){
        pthread_mutex_lock(&mutex);
        atual = numero++;
        pthread_mutex_unlock(&mutex);

        if(atual>=*n)
            break;
        else if(ehPrimo(atual)){
            // printf("%lld\n",atual);
            n_primos++;
        }
    }
    // printf("%lld primos encontrados.\n",n_primos);
    pthread_exit((void*) n_primos);
    return NULL;
}

int conc_main(int n_thr,long long int n,pthread_t **pt_ids){

    long long int i;
    long int retorno,resultado;
    pthread_t *t_ids;


    t_ids = *pt_ids;
    t_ids = (pthread_t*) malloc(sizeof(pthread_t)*n_thr);
    alloc_check(t_ids);
    numero = 0;
    pthread_mutex_init(&mutex,NULL);

    for ( i = 0; i < n_thr; i++)
    {
        // printf("%lld,%lld\n",n,numero);
        if(pthread_create(&t_ids[i],NULL,conc_factor,(void *)&n)){
            printf("erro na criação da thread [%lld]\n",i);
            exit(1);
        }
    }
    
    resultado = 0;
    for ( i = 0; i < n_thr; i++)
    {
        if(pthread_join(t_ids[i],(void**)&retorno)){
            printf("erro no retorno da thread %lld",i);
            exit(1);
        }
        resultado += retorno;
    }
    
    return resultado;
}
typedef struct{
    double init, exec, term;
    int dim,n_thr;
}exec_data;


/**
 * @brief Printa dados da execucao
 * @param data 
 */
void store_exec_data(exec_data *data, char* filename){
    FILE *data_file;
    data_file = fopen(filename,"a");
    if(data_file==NULL){
        printf("Erro ao abrir o arquivo de dados.\n");
        exit(1);
    }
    fprintf(data_file,"%%flag,%d,%d,%f,%f,%f\n",
        data->n_thr,
        data->dim,
        data->init,
        data->exec,
        data->term);
    fclose(data_file);
    return;
}       
 
double actual_time() {
    struct timespec tempo;
    clock_gettime(CLOCK_MONOTONIC_RAW, &tempo);
    return tempo.tv_sec + tempo.tv_nsec/1000000000.0;
}

/* argumentos: <numero de threads> <numero de elementos> <nome-arquivo-dados> */

int main(int argc, char const *argv[])
{
    int n_thr;
    double tempo;
    long long int n;
    long int resultado;
    pthread_t *t_ids = NULL;
    exec_data data;

    tempo = actual_time();

    n_thr = valida_intarg(1,argc,(char**)argv);
    if(argc<2 || !(n = atoll(argv[2]))){
        printf("Insira o tamanho da série como o segundo argumento.\n");
        exit(1);
    }
    if(argc<3){
        printf("Insira o nome do arquivo de dados como o terceiro argumento.\n");
        exit(1);
    }

    data.n_thr=n_thr;
    data.dim=n;
    data.init = actual_time() - tempo;
    tempo = actual_time();
    resultado = conc_main(n_thr,n,&t_ids);
    data.exec = actual_time() - tempo;
    tempo = actual_time();
    // for ( i = 0; i < n; i++)
    //     if(ehPrimo(i)){
    //         printf("%lld ",i);}
    // puts("\n");

    if(t_ids!=NULL)
        free(t_ids);
    printf("%ld\n",resultado);
    pthread_mutex_destroy(&mutex);
    data.term = actual_time() - tempo;
    store_exec_data(&data,(char*)argv[3]);
    return 0;
}