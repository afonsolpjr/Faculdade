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


void matvec_bin_generator(int n, int m, char filename[]){
    float *a,*b;
    FILE *f_ptr;

    a = random_float_matrix(n,m);
    b = random_float_array(m);

    // mat_print(a,n,m);
    // vec_print(b,m);
    
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
float *matvec_bin_reader(FILE *f_ptr,float **mat, int n,int m){
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
    int n,m;
    srand(time(NULL));

    n = valida_intarg(1,argc,argv);
    m = valida_intarg(2,argc,argv);


    matvec_bin_generator(n,m,argv[3]);
    // puts("\nbinário gerado com dados acima\n");
    // matvec_bin_reader(argv[1],&mat);    
    return 0;
}