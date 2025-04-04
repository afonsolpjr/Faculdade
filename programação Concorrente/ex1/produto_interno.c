#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>

typedef struct{
    float *v1,*v2;
    int n,id;
} prod_int_parcial_targs;

/**
 * @brief Printa os dados lidos (só para fins de debug)
 * @param tam_vetor 
 * @param vetores 
 * @param prod_int 
 */
void printa_dados_lidos(int tam_vetor,float **vetores,float prod_int){
    int i,j;
    printf("\nDados lidos:"
        "\n\ttamanho de vetor:%d"
        "\n\tproduto_interno=%f\n",tam_vetor,prod_int);

    for(i=0;i<2;i++){
        printf("Vetor %d\n[",i);
        for ( j = 0; j < tam_vetor; j++)
        {
            printf(" %f ",vetores[i][j]);
        }
        puts(" ]");
    }
}

/**
 * @brief Calcula o produto interno parcial (de n elementos) dos dois vetores dados
 * @param arg 'struct contendo vetores, e numero de elementos a serem processados
 * @return struct contendo
 */
void *prod_int_parcial(void *arg)
{
    prod_int_parcial_targs *argumentos;
    double *retorno;
    int i;

    retorno = (double*) malloc(sizeof(double));
    argumentos = (prod_int_parcial_targs*) arg;
    *retorno = 0;
    
    // printf("\t\tThread %d começando\n",argumentos->id);
    for(i=0;i<argumentos->n;i++)
        *retorno += (argumentos->v1[i] * argumentos->v2[i]);

    // printf("\t\t\tresultado parcial dentro da thread %d: %f\n",argumentos->id,*retorno);
    free(arg);
    pthread_exit((void*) retorno);
    
}

int main(int argc, char const *argv[])
{
    FILE * ptr_arqv;
    int i,tam_vetor,n_threads,posicao_comeco,erro;
    float *vetores[2];
    double prod_int_seq,*retorno,prod_int_concorrente,diff;
    prod_int_parcial_targs *args;
    pthread_t *t_ids;
    
    /* Validar argumentos*/
    if(argc!=3){
        printf("Por favor, passe o numero de threads e o nome do arquivo binário como (únicos) argumentos."
            "\n\t./<programa> <numero de threads> <nome do arquivo binario>\n");
        return 1;
    }
    n_threads=atoi(argv[1]);
    if(!n_threads){
        printf("\n Insira um numero de threads válido. [o numero inserido foi %d]",n_threads);
        return 2;
    }
        /*le tamanho do vetor*/
    ptr_arqv = fopen(argv[2],"r");
    fread(&tam_vetor,sizeof(int),1,ptr_arqv);
    
    if(n_threads>tam_vetor){
        printf("O numero de threads indicado (%d) é maior que o tamanho do vetor (%d)."
            " O programa será encerrado\n",n_threads,tam_vetor);
    }
    
    /* Ler arquivo binario, inicializando vetores:
        conteúdo:tam,vetor1,vetor2,produto_interno */
    for(i=0;i<2;i++)
        vetores[i] = (float*) malloc(sizeof(float)*tam_vetor);
    if(!vetores[0] || !vetores[1]){
        puts("Houve um erro na alocação dos vetores");
        return 3;
    }
        
    fread(vetores[0],sizeof(float),tam_vetor,ptr_arqv);
    fread(vetores[1],sizeof(float),tam_vetor,ptr_arqv);
    fread(&prod_int_seq,sizeof(double),1,ptr_arqv);

    // printa_dados_lidos(tam_vetor,vetores,prod_int_seq);
        
    /* Estratégia para divisão da carga:
        - Cada thread receberá aproximadamente n=tam_vetor/n_threads elementos a processar o produto */

    /* argumento para cada thread: 
        - Endereço da posição que ela deve começar a processar, pros dois vetores
        - Número de elementos que ela deve processar
    */

    /*O LOOP: Criando threads*/

    t_ids = (pthread_t*) malloc(sizeof(pthread_t)*n_threads);
    if(!t_ids){
        puts("Problema na alocação de vetores para IDs de threads");
        return 3;
    }
    posicao_comeco=0;
    for(i=0;i<n_threads;i++){
        /*Criando argumento*/
        args = (prod_int_parcial_targs*) malloc(sizeof(prod_int_parcial_targs));
        if(!args){
            printf("Problemas na alocação dos argumentos\n");
            return 3;
        }
        args->id = i; 
        // printf("criando thread %d\n",i);
        args->n = tam_vetor/n_threads;
        if(i<(tam_vetor%n_threads))
            args->n++;
        args->v1 = &vetores[0][posicao_comeco];
        args->v2 = &vetores[1][posicao_comeco];
        posicao_comeco += args->n;
        /*criando threads*/
        erro = pthread_create(&t_ids[i],NULL,prod_int_parcial,(void*) args);      
        if(erro){
            printf("\nErro [%d] na criação de threads",erro);
            return 4;
        }  
    }


    /*
    Retornando threads
    */
    prod_int_concorrente=0;
    for(i=0;i<n_threads;i++){
        if(pthread_join(t_ids[i],(void**) &retorno)){
            printf("Erro no retorno da thread %d\n",i);
        }
        // printf("RETORNO da thread %d: %f \n",i,*retorno);
        prod_int_concorrente += (*retorno);
        free(retorno);
    }

    diff = fabs( (prod_int_seq-prod_int_concorrente)/prod_int_seq );
    printf("\nResultado Concorrente: %f\n"
        "Resultado Sequencial: %f\n"
        "DIferença relativa: %.15f\n",
        prod_int_concorrente,prod_int_seq,diff);
    return 0;
}
