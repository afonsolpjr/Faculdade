#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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
* @brief Gera uma matriz  de tamanho , com floats quase aleatórios.
* @param n numero de linhas
* @param m numero de colunas
* @return ponteiro para a matriz alocada 
 */
float ** random_float_matrix(int n,int m)
{
    int i;
    float **mat;

    // alocando ponteiros pra linhas
    mat = (float**) malloc(sizeof(float*)*n);
    alloc_check((void*) mat);

    for ( i = 0; i < n; i++) //alocando linhas
        mat[i]= random_float_array(m);

    /* for ( i = 0; i < tamanho; i++)
    {
        for ( j = 0; j < tamanho; j++)
        {
            printf(" %f ",a[i][j]);
        }
        puts("\n");
    }
     */
    return m;
        
}


/**
 * @brief Printa matriz 'm' de dimensão n
 * @param m matriz
 * @param n dimensao de m
 */
void mat_print(float **m, int n)
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


void mat_const_print(float (*matriz)[], int n)
{
    int i,j;
    float (*m)[n] = (float(*)[n])matriz;
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
 * @brief Retorna a matriz m invertida
 * @param m matriz a ser invertida
 * @param n dimensão de m
 * @return matriz m invertida
 */
float **transp_mat(float **m, int n){
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
    // mat_print(resultado,n);    
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



// float **create_identity(int n) {
//     float **mat = (float**)malloc(n * sizeof(float*));
//     alloc_check(mat);
    
//     for (int i = 0; i < n; i++) {
//         mat[i] = (float*)calloc(n, sizeof(float));
//         alloc_check(mat[i]);
//         mat[i][i] = 1.0f;
//     }

//     mat[1][2]=3;
//     return mat;
// }

// float **create_sequential(int n) {
//     float **mat = (float**)malloc(n * sizeof(float*));
//     alloc_check(mat);
    
//     for (int i = 0; i < n; i++) {
//         mat[i] = (float*)malloc(n * sizeof(float));
//         alloc_check(mat[i]);
//         for (int j = 0; j < n; j++) {
//             mat[i][j] = i*n + j + 1;
//         }
//     }
//     return mat;
// }

/**
 * @brief Compara e retorna 1 caso as duas matrizes quadradas a e b sejam iguais
 * @param a matriz a
 * @param b matriz b
 * @param n dimensão das matrizes
 */
float matdiff(float** a,float** b,int n){
    int i,j;
    float diff;
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
float **matmul_dotprod_seq(float **a,float **b,int n){
    float **c;
    int i,j;
    float **b_t;
    
    c = (float**) malloc(sizeof(float*)*n);
    alloc_check(c);

    b_t = transp_mat(b,n);

    for ( i = 0; i < n; i++)
    {
        c[i] = (float*) malloc(sizeof(float)*n);
        alloc_check(c[i]);

        for ( j = 0; j < n; j++)
            c[i][j]=dotprod_seq(a[i],b_t[j],n);
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
 * @brief 
 * @param n 
 */
void matmul_bin_generator(int n, char filename[]){

    float **a,**b, **c;
    int i;
    FILE *ptr_arquivo;
    
    a = random_float_matrix(n);
    b = random_float_matrix(n);
    
  
    c = matmul(a,b,n);

    // mat_print(a,n);
    // mat_print(b,n);
    // mat_print(c,n);

    ptr_arquivo = fopen(filename,"w");
    if(!ptr_arquivo){
        printf("Erro na criação de arquivo.\n");
        exit(1);
    }

    fwrite(&n,sizeof(int),1,ptr_arquivo);
    
    for ( i = 0; i < n; i++)
        fwrite(a[i],sizeof(float),n,ptr_arquivo);

    for ( i = 0; i < n; i++)
        fwrite(b[i],sizeof(float),n,ptr_arquivo);

    for ( i = 0; i < n; i++)
        fwrite(c[i],sizeof(float),n,ptr_arquivo);

 
    
    free(a);
    free(b);
    free(c);
    return;
}

void matmul_bin_reader(char filename[]){
    FILE *file_ptr;
    int n,i;
    float **a,**b,**c;

    file_ptr = fopen(filename,"r");

    fread(&n,sizeof(int),1,file_ptr);
    
    /* Se for alocar blocos contiguos */

    // a = (float(*)[]) malloc(sizeof(float)*n*n);
    // b = (float*) malloc(sizeof(float)*n*n);
    // c = (float*) malloc(sizeof(float)*n*n);


    a = (float**) malloc(sizeof(float*)*n);
    alloc_check(a);
    for(i=0;i<n;i++){
        a[i] = (float*) malloc(sizeof(float)*n);
        fread(a[i],sizeof(float),n,file_ptr);
    }

    b = (float**) malloc(sizeof(float*)*n);
    alloc_check(b);
    for(i=0;i<n;i++){
        b[i] = (float*) malloc(sizeof(float)*n);
        fread(b[i],sizeof(float),n,file_ptr);
    }
     
    c = (float**) malloc(sizeof(float*)*n);
    alloc_check(c);
    for(i=0;i<n;i++){
        c[i] = (float*) malloc(sizeof(float)*n);
        fread(c[i],sizeof(float),n,file_ptr);
    }
    
    mat_print(a,n);
    mat_print(b,n);
    mat_print(c,n);

}

<<<<<<< Updated upstream
/**
 * @brief Retorna o instante de tempo atual em segundos
 * @return 
 */
double actual_time() {
    struct timespec tempo;
    clock_gettime(CLOCK_MONOTONIC_RAW, &tempo);
    return tempo.tv_sec + tempo.tv_nsec/1000000000.0;
=======
void matvec_bin_generator(int n, int m, char filename[]){
    float **a,*b;
    int i,j;
    FILE *f_ptr;

    a = random_float_matrix(n,m);
    b = random_float_array(m);

    f_ptr = fopen(filename,"w");

    fwrite(&n,sizeof(int),1,f_ptr);
    fwrite(&m,sizeof(int),1,f_ptr);

    //escrever matriz
    for ( i = 0; i < n; i++)
        fwrite(a[i],sizeof(float),m,f_ptr);

    fwrite(b,sizeof(float),m,f_ptr);

    fclose(f_ptr);
    //escrever vetor

    
>>>>>>> Stashed changes
}

int main(int argc, char *argv[])
{
<<<<<<< Updated upstream
    double start,exec_time;
    srand(time(NULL));
    start = actual_time();
    matmul_bin_generator(atoi(argv[1]),"matmul.bin");
    exec_time =  actual_time() - start;

    printf("Tempo que se passou = %f\n",exec_time);
    // matmul_bin_reader("matmul.bin");
=======
    int n,m;
    srand(time(NULL));
    // matmul_bin_generator(atoi(argv[1]),"matmul.bin");
    
    matvec_bin_generator
>>>>>>> Stashed changes

    // printf("Tamanho de ptr = %ld\n",sizeof(ptr));
    return 0;
}


