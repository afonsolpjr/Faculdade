#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <pthread.h>

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


void * checa_n(void *arg){
    long long int *n = (long long int*) arg;
    long long int atual;

    // printf("[debug thread]\n"
    //     "\tn=%lld\n"
    //     "\tnumero=%lld\n",*n,numero);
    
    while(numero<*n){
        pthread_mutex_lock(&mutex);
        atual = numero++;
        pthread_mutex_unlock(&mutex);
        if(ehPrimo(atual))
            printf("%lld\n",atual);
    }

    return (void*) n;
}

/* argumentos: <numero de threads> <numero de elementos> <nome-arquivo-gabarito> */

int main(int argc, char const *argv[])
{
    int n_thr;
    long long int n,i;
    pthread_t *t_ids;

    n_thr = valida_intarg(1,argc,(char**)argv);

    
    if(argc<2 || !(n = atoll(argv[2]))){
        printf("Insira o tamanho da série como o segundo argumento.\n");
        exit(1);
    }

    // for ( i = 0; i < n; i++)
    //     if(ehPrimo(i)){
    //         printf("%lld ",i);}
    // puts("\n");


    t_ids = (pthread_t*) malloc(sizeof(pthread_t)*n_thr);
    alloc_check(t_ids);
    numero = 0;
    pthread_mutex_init(&mutex,NULL);

    for ( i = 0; i < n_thr; i++)
    {
        // printf("%lld,%lld\n",n,numero);
        if(pthread_create(&t_ids[i],NULL,checa_n,(void *)&n)){
            printf("erro na criação da thread [%lld]\n",i);
            exit(1);
        }
    }
    
    
    for ( i = 0; i < n_thr; i++)
    {
        if(pthread_join(t_ids[i],NULL)){
            printf("erro no retorno da thread %lld",i);
            exit(1);
        }
    }
    
    
    return 0;
}