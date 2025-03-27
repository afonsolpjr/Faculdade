#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>


/* 
Objetivo: Implementar o seu primeiro programa concorrente! Escreva um programa
concorrente que execute com 4 threads para incrementar de 1 cada elemento de um
vetor de 4*N elementos do tipo inteiro. Para cada elemento a_i do vetor, calcular o novo
valor (ai + 1) e escrever o resultado na mesma posic ̧ao do elemento.  ̃
A tarefa completa devera ser dividida entre as threads de forma balanceada (as  ́
threads devem receber a mesma carga de trabalho). O valor de N deve ser informado
na chamada do programa.
Roteiro:
1. Comece pensando em como dividir a tarefa completa entre as 4 threads. Todas
as threads deverao executar a mesma func ̧  ̃ ao ̃ . Depois pense como verificar a
corretude do programa.
2. Lembre-se de executar o programa varias vezes e verificar se ele est  ́ a funcionando  ́
corretamente.
*/

typedef struct{
    int *vetor;
    int carga;
    int id;
} t_args;

void* acumulador(void *arg){
    t_args *argv;
    argv = (t_args*) arg;

    int i;
    for(i=0;i<argv->carga;i++)
        argv->vetor[i]++;

    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    int i;

    /* Checar argumento do programa */

    if(argc!=2)
        puts("\n\t Por favor passe o tamanho do vetor como o único argumento.");
    
    int tam_vetor = atoi(argv[1]);
    
    /* Alocar vetor de n inteiros com 0 a n-1*/
    int vetor[tam_vetor];
    for(i = 0; i<=tam_vetor;i++)
        vetor[i]=i;

    /* Distribuir carga para cada thread */
    t_args cargas[4];
    int posicao_comeco = 0;
    for(i=0;i<4;i++)
    {
        cargas[i].id=i;
        cargas[i].carga = tam_vetor/4;
        if(i<(tam_vetor%4))
            cargas[i].carga++;
        cargas[i].vetor = &vetor[posicao_comeco];
        posicao_comeco += cargas[i].carga;
        /* printf("\nCarga da thread %d = %d",i+1,carga_thread[i]); */
    }

    /* Criar threads*/
    pthread_t t_ids[4];

    for(i=0;i<4;i++)
    {
        int ret = pthread_create(&t_ids[i],NULL,acumulador,&cargas[i]);
        if(ret)
        {
            printf("\nErro [%d] na criação da thread %d\n",ret,i);
        }
    }

    /* Esperar threads acabarem */

    for(i=0;i<4;i++)
    {
        int ret = pthread_join(t_ids[i],NULL);
        if(ret)
        {
            printf("\nErro [%d] na finalização da thread %d\n",ret,i);
        }
    }

    /* verificar corretude: vetores possuem valores de 1 a n */
    
    for(i=0;i<tam_vetor;i++)
    {
        if(vetor[i] != i+1)
        {
            printf("Valor na posição %d está errado: [%d]",i,vetor[i]);
            return 1;
        }
    }
    
    return 0;
}
