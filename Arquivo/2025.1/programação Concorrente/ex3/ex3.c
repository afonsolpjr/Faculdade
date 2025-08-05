#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <math.h>

// #define DEBUG 1
#ifdef DEBUG
#define DBG(fmt, ...) printf(fmt "\n", __VA_ARGS__)
#else
#define DBG(fmt, ...)
#endif

#define N_PRODUTORES 1
#define N 5

/*
Objetivo: Projetar e implementar um programa concorrente em C que usa o padr˜ao
produtor/consumidor.
Descric¸ ˜ao: Vamos retomar com o problema da primalidade :-)
Implemente um programa concorrente onde UMA thread PRODUTORA gera
uma sequˆencia de N n ´umeros inteiros e os deposita no canal de inteiros de tamanho
M (M pequeno) — um de cada vez — que ser´a compartilhado com C threads CONSUM-
IDORAS. Os valores e N, M e C devem ser lidos da entrada do programa.
As threads CONSUMIDORAS retiram os n´umeros — um de cada vez — e avaliam
sua primalidade
*/

// Variaveis globais
sem_t full_slot, empty_slot; // semaforos para sincronizacao por condicao
pthread_mutex_t mutex;       // semaforo geral de sincronizacao por exclusao mutua
long long *buffer;
int buffer_size, n_threads;

int ehPrimo(long long int n)
{
    int i;
    if (n <= 1)
        return 0;
    if (n == 2)
        return 1;
    if (n % 2 == 0)
        return 0;
    for (i = 3; i < sqrt(n) + 1; i += 2)
        if (n % i == 0)
            return 0;
    return 1;
}

void insert(int value)
{
    static int in = 0;

    sem_wait(&empty_slot);
    pthread_mutex_lock(&mutex);

    buffer[in] = value;
    in = (in + 1) % buffer_size;

    pthread_mutex_unlock(&mutex);
    sem_post(&full_slot);
    return;
}

long long buffer_remove()
{
    static int out = 0;
    long long return_value;
    sem_wait(&full_slot);
    pthread_mutex_lock(&mutex);

    return_value = buffer[out];
    buffer[out] = 0;
    out = (out + 1) % buffer_size;

    pthread_mutex_unlock(&mutex);
    sem_post(&empty_slot);
    return return_value;
}

void *producer_routine(void *arg)
{
    int n = *((long long *)arg);
    int i;

    for (i = 0; i < n; i++)
        insert(i);

    // poison pill
    for (i = 0; i < n_threads; i++)
        insert(-1);

    return NULL;
}

void *consumer_routine(void *arg)
{
    long long item, score = 0;

    while ((item = buffer_remove()) >= 0)
    {
        if (ehPrimo(item))
            score++;
    }

    return (void *)score;
}

/* Funções de utilidade */

/**
 * @brief Valida se o argumento enviado à main na posição 'pos' é um inteiro.
 * @param pos posicao do argumento
 * @param argc arg counter da main
 * @param argv args da main
 * @return inteiro validado, caso contrario acusa erro e sai do programa
 */
int valida_intarg(int pos, int argc, char *argv[])
{
    int val;

    if (pos >= argc)
    {
        printf("Não foram inseridos argumentos suficientes.\n\tEsperado %d\n\tInseridos: %d\n", pos, argc);
        exit(1);
    }

    val = atoi(argv[pos]);

    if (!val)
    {
        printf("Valor inválido para o %dº argumento.", pos);
        exit(1);
    }
    return val;
}

/**
 * @brief Checa por erros de alocação de arrays. Encerra o programa caso a alocação não tenha funcionado.
 * @param ptr ponteiro/endereço a ser verificado uma alocação
 */
void alloc_check(void *ptr)
{
    if (ptr == NULL)
    {
        printf("Erro na alocação de memória.\n");
        exit(1);
    }
}

/// @brief
/// @param argc 3
/// @param argv N (teto da sequência de numeros), M (tamanho do buffer), C (número de threads)
/// @return
int main(int argc, char *argv[])
{
    int i, winner_thr, n_primes;
    long long thr_return, winner_score, n;
    pthread_t *t_ids;

    n = (long long)valida_intarg(1, argc, argv);
    buffer_size = valida_intarg(2, argc, argv);
    n_threads = valida_intarg(3, argc, argv);

    t_ids = malloc(sizeof(pthread_t) * (n_threads + 1));
    alloc_check((void *)t_ids);

    // inicializar buffer
    buffer = malloc(buffer_size * sizeof(int));
    alloc_check(buffer);

    // incializar controles
    sem_init(&full_slot, 0, 0);
    sem_init(&empty_slot, 0, buffer_size);
    pthread_mutex_init(&mutex, NULL);

    // inicializar thread produtora, com id na ultima posicao do array de ids
    if (pthread_create(&t_ids[n_threads], NULL, producer_routine, (void *)&n))
    {
        printf("Erro na criação da thread consumidora.\n");
        exit(1);
    }

    // consumidoras
    for (i = 0; i < n_threads; i++)
    {
        // criar threads
        if (pthread_create(&t_ids[i], NULL, consumer_routine, NULL))
        {
            printf("Erro na criação da thread %d\n", i);
            exit(1);
        }
    }

    // esperar threads
    winner_score = 0;
    n_primes = 0;
    for (i = 0; i < n_threads; i++)
    {
        if (pthread_join(t_ids[i], (void **)&thr_return))
        {
            printf("Erro no retorno da thread %d", i);
            exit(1);
        }

        DBG("\n\t Thread %d retornando valor %lld", i, thr_return);
        n_primes += thr_return;
        if (thr_return > winner_score)
        {
            winner_thr = i;
            winner_score = thr_return;
        }
    }

    printf("\tThread 'vencedora': %d, com %lld primos encontrados.\nTotal de primos: %d\n",
           winner_thr, winner_score, n_primes);

    return 0;
}