#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>
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
    return;
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
 * @brief Checa se um fread deu sucesso
 * @param n retorno da fread em questão
 */
void fread_check(size_t n){
    if(!n){
        printf("\n\t Erro em leitura de arquivo.\n");
        exit(1);
    }
    return;
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
 * @brief Retorna o instante de tempo atual em segundos
 * @return 
 */
double actual_time() {
    struct timespec tempo;
    clock_gettime(CLOCK_MONOTONIC_RAW, &tempo);
    return tempo.tv_sec + tempo.tv_nsec/1000000000.0;
}

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

/**
 * @brief Gera uma matriz (nxm) float e um vetor de tamanho n, 
 * gravando-os em um arquivo binário contendo (n,m,matriz,vetor)
 * @param n numero de linhas da matriz
 * @param m numero de colunas da matriz
 * @param filename nome do arquivo a ser escrito
 */
void matvec_bin_generator(int n, int m, char filename[]){
    float *a,*b;
    FILE *f_ptr;

    a = random_float_matrix(n,m);
    b = random_float_array(m);

    mat_print(a,n,m);
    vec_print(b,m);
    
    f_ptr = fopen(filename,"w");

    fwrite(&n,sizeof(int),1,f_ptr);
    fwrite(&m,sizeof(int),1,f_ptr);

    //escrever matriz
    fwrite(a,sizeof(float),m*n,f_ptr);
    fwrite(b,sizeof(float),m,f_ptr);

    fclose(f_ptr);
    //escrever vetor

    return;
}

/**
 * @brief Lê do descrito de arquivo f_ptr, e carrega a matriz mat,e o vetor vec
 * @param f_ptr Descritor de arquivo já aberto
 * @param mat ponteiro para o vetor a ser populado como a matriz
 * @param n numero de linhas da matriz
 * @param m numero de colunas da matriz
 * @return retorna o vetor vec
 */
float *matvec_bin_reader(FILE *f_ptr,float **mat, int n,int m)
{
    float *vec;

    *mat = (float*) malloc(sizeof(float)*n*m);
    alloc_check((void*)*mat);

    vec = (float*)malloc(sizeof(float)*m);
    alloc_check((void*)vec);

    fread(*mat,sizeof(float),n*m,f_ptr);
    fread(vec,sizeof(float),m,f_ptr);

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
 * @brief Estrutura de argumentos para thr_matvet
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


int main(int argc, char *argv[])
{
    int n,m;
    srand(time(NULL));

    n = valida_intarg(1,argc,argv);
    m = valida_intarg(2,argc,argv);

    matvec_bin_generator(n,m,argv[3]);
    
    
    return 0;
}


