#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    @brief Cria e popula, um vetor de tamanho @tam_vetor com valores quase-aleatórios (range de -500 a 500) de floats.
    @param vetor: ponteiro para o vetor de floats
    @param tam_vetor: tamanho do vetor
*/
float *random_float_array(int tam_vetor){
    float num_aleatorio,*array;
    int i;


    array = (float*) malloc(sizeof(float)*tam_vetor);
    alloc_check((void*) array);

    for(i=0;i<tam_vetor;i++){
        num_aleatorio = 5.0/(rand()%500+1)*100;
        if(rand()%2)
            num_aleatorio*=-1;
        array[i]=num_aleatorio;
        // printf(" %f ",num_aleatorio);
    }

    return array;
}

/**
* @brief Gera uma matriz de tamanho (n x m) , com floats quase aleatórios.
* @param n numero de linhas
* @param m numero de colunas
* @return ponteiro para a matriz alocada 
 */
float * random_float_matrix(int n,int m){
    float *mat;
    mat = random_float_array(n*m);
    return mat;
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
 * @brief Cria duas matrizes quadradas n por n, alocadas continuamente
 * @param n dimensao da matriz
 * @param filename nome do arquivo
 */
void matmul_bin_generator(int n, char filename[]){

    float *a,*b;
    FILE *ptr_arquivo;
    
    a = random_float_matrix(n,n);
    b = random_float_matrix(n,n);
  
    // c = matmul(a,b,n);

    // mat_print(a,n,n);
    // mat_print(b,n,n);
    // mat_print(c,n,n);

    ptr_arquivo = fopen(filename,"w");
    if(!ptr_arquivo){
        printf("Erro na criação de arquivo.\n");
        exit(1);
    }

    fwrite(&n,sizeof(int),1,ptr_arquivo);
    
    fwrite(a,sizeof(float),n*n,ptr_arquivo);

    fwrite(b,sizeof(float),n*n,ptr_arquivo);

    // for ( i = 0; i < n; i++)
    //     fwrite(c,sizeof(float),n*n,ptr_arquivo);

 
    
    free(a);
    free(b);
    // free(c);
    return;
}

/**
 * @brief Lê duas matrizes alocadas continuamente no arquivo de nome filename
 * @param filename nome do arquivo binario
 * @param a ponteiro para matriz a
 * @param b ponteiro para matriz b
 */
void matmul_bin_reader(char filename[],float **a, float**b){
    FILE *file_ptr;
    int n;

    file_ptr = fopen(filename,"r");

    fread(&n,sizeof(int),1,file_ptr);
    
    /* Se for alocar blocos contiguos */
    // a = (float(*)[]) malloc(sizeof(float)*n*n);
    // b = (float*) malloc(sizeof(float)*n*n);
    // c = (float*) malloc(sizeof(float)*n*n);


    *a = (float*) malloc(sizeof(float)*n*n);
    alloc_check(*a);
    fread(*a,sizeof(float),n*n,file_ptr);
    mat_print(*a,n,n);
    
    

    *b = (float*) malloc(sizeof(float)*n*n);
    alloc_check(*b);
    fread(*b,sizeof(float),n*n,file_ptr);
    
    // printf("\n\tdimensão = %d, a=b? %d\n",n,(*a==*b));

    mat_print(*b,n,n);
    
    // c = (float*) malloc(sizeof(float)*n*n);
    // fread(c,sizeof(float),n*n,file_ptr);
    
    // mat_print(a,n,n);
    // mat_print(b,n,n);

    // mat_print(c,n,n);
    return;
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

int main(int argc, char *argv[])
{
    int n;
    // float *a,*b;

    srand(time(NULL));
    /* Argumentos esperados */
    n = valida_intarg(1,argc,argv);


    matmul_bin_generator(n,argv[2]);

    // puts("\nbinário gerado com dados acima\n");

    // matmul_bin_reader(argv[2],&a,&b);
    // mat_print(a,n,n);
    // mat_print(b,n,n);

    return 0;
}