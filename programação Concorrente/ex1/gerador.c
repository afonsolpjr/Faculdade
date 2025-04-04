#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* 
1. Comece gerando os casos de teste (vetores de entrada e resultado esperado). Es-
creva um programa sequencial em C que gere dois vetores de entrada (tipo: float)
de dimensao ̃ N, com valores randomicos (gere numeros fracion  ́ arios).
Escreva em um arquivo binario o valor de N (tipo: inteiro) e os dois vetores. Depois calcule
o produto interno desses dois vetores e escreva o resultado encontrado no mesmo
arquivo binario (tipo: double).  ́
*/


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
        printf(" %f ",num_aleatorio);
    }
}

/* 
 @brief Calcula produto interno entre 2 vetores
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

int main(int argc, char const *argv[])
{
    int tam_vetor,i;
    float *vetor[2];
    double produto_interno;
    FILE * ptr_arquivo;
    srand(time(NULL));

    /* checando argumentos do programa */
    if(argc!=3){
        printf("Por favor, passe o tamanho do vetor e o nome do arquivo binário como (únicos) argumentos."
            "\n\t./<programa> <tamanho do vetor> <nome do arquivo binario>\n");
        return 1;
    }
    tam_vetor = atoi(argv[1]);
    if(tam_vetor==0){
        printf("Tamanho do vetor = 0 ou não fornecido corretamente");
        return 1;
    }

    /*Alocando vetor*/
    for(i=0;i<2;i++)
        vetor[i] = (float*) malloc(sizeof(float)*tam_vetor);
    if(!vetor[0] || !vetor[1]){
        puts("Houve um erro na alocação dos vetores");
        return 2;
    }
        
        /* Populando e printando vetor */
    for(i=0;i<2;i++){
        printf("\tVETOR %d\n[",i+1);
        vetor_float_aleatorio(vetor[i],tam_vetor);
        printf("]~~~\n\n");
    }
    
    /* Calculando produto interno */
    produto_interno=produto_interno_seq(vetor[0],vetor[1],tam_vetor);
    printf("\n\tProduto interno = %f\n",produto_interno);

    /* Criando arquivo binário */
    ptr_arquivo = fopen(argv[2],"w");
    fwrite(&tam_vetor,sizeof(int),1,ptr_arquivo);
    fwrite(vetor[0],sizeof(float),tam_vetor,ptr_arquivo);
    fwrite(vetor[1],sizeof(float),tam_vetor,ptr_arquivo);
    fwrite(&produto_interno,sizeof(double),1,ptr_arquivo);
    
    
    fclose(ptr_arquivo);
    return 0;
}
