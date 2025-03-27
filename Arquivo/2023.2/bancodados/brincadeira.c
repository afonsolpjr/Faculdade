#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Recebe nome de arquivo csv como argumento */

#define BASE_LINE_LENGTH 370
#define BASE_ATTRIBUTE_LENGTH 8
#define BASE_COLLUMN_LENGTH 80
#define LIMITE_LISTA 9000000

/*define estrutura de uma linha do csv pra ser um nó em uma lista*/
typedef struct _remuneracao
{
    char **nome_colunas;
    char **dados;
    struct _remuneracao *prox;

} REMUNERACAO;

/* Cria nó para a lista a partir de dados*/
REMUNERACAO* cria_entrada(char **nome_cols,char **dados)
{
    REMUNERACAO *no;
    no = (REMUNERACAO*) calloc(1,sizeof(REMUNERACAO));
    no->dados = dados;
    no->nome_colunas = nome_cols;
    no->prox = NULL;

    return no;
}

/* Insere NO INICIO da lista o nó */
void insere_lista(REMUNERACAO **lista, REMUNERACAO *no)
{
    if(lista == NULL)
    {
        *lista = no;
        return;
    }
    
    no->prox = *lista;
    *lista = no;
    return;
}


/* Retorna proxima linha ou NULL caso eof(prt_arquivo)*/
char* get_linha(FILE *ptr_arquivo)
{
    char *linha,c;
    int i,vezes_aloc,tam_aloc;


    tam_aloc = BASE_LINE_LENGTH;
    linha = (char*) calloc(tam_aloc,sizeof(char));

    i=0;
    while( (c=fgetc(ptr_arquivo))!='\n' && !feof(ptr_arquivo) )
    {
        if(i == tam_aloc)
        {
            tam_aloc*=2;
            linha = (char*) realloc(linha,tam_aloc*sizeof(char));
        }
        linha[i++]=c;
    }
    linha[i]='\0';
    if(feof(ptr_arquivo))
        return NULL;
    else
        return linha;
}

/*Le quantas colunas tem na linha recebida caso n==0 e atribui em n,
 retorna n strings em um char** */
char** get_colunas(char* linha, int *n)
{
    char **colunas;
    int i,i_coluna,num_coluna,col_char,tam_aloc,retira_espaco;
    retira_espaco = 0;
    num_coluna = *n;
    if(!num_coluna)
    {
        for(i=0,num_coluna=0;linha[i]!='\0';i++)
        {
            if(linha[i]==';')
                num_coluna++;
        }
        num_coluna++;
        *n = num_coluna;
        printf("li %d colunas\n ",num_coluna);
        retira_espaco = 1;
    }

    colunas = (char**) calloc(num_coluna,sizeof(char*));

    // alocando tamanho de atributos
    tam_aloc = BASE_ATTRIBUTE_LENGTH;
    for(i=0;i<num_coluna;i++)
    {
        colunas[i] = (char*) calloc(tam_aloc,sizeof(char));
    }

    i=0;
    i_coluna = 0;
    col_char = 0;
    while(linha[i]!='\0')
    {

        if(linha[i]!='\"' && linha[i]!=';')
        {
            // Dobra tamanho da alocação padrão para atributos, se precisar
            if(col_char==tam_aloc)
            {
                tam_aloc*=2;
                colunas[i_coluna] = (char*) realloc(colunas[i_coluna],tam_aloc*sizeof(char));
            }
            
            colunas[i_coluna][col_char] = linha[i];
            if( retira_espaco &&   
                (colunas[i_coluna][col_char]== ' ' || 
                colunas[i_coluna][col_char] == '(') ||
                colunas[i_coluna][col_char] == ')' ||
                colunas[i_coluna][col_char] == '-') 
                colunas[i_coluna][col_char]='_';
            col_char++;
        }
        else if(linha[i]==';')
        {
            i_coluna++;
            col_char = 0;
            tam_aloc = BASE_ATTRIBUTE_LENGTH;
        }
        i++;
    }

    return colunas; 
}

/* Lê o tamanho da proxima linha em ptr_arquivo,
 usei pra debug (ver o tamanho maximo da linha no arquivo pra definir a macro)*/
int tam_linha(FILE *ptr_arquivo)
{
    int i = 0;
    char c;
    while ( (c=fgetc(ptr_arquivo)!='\n' && !feof(ptr_arquivo) ) )
        i++;

    return i;
}


void create_query(REMUNERACAO *head,char *nome_db, char *nome_tabela,int tam_atr,int n_col)
{
    FILE *ptr_arquivo;
    int i,cnt;

    ptr_arquivo = fopen("query.txt","w");

    fputs("USE ",ptr_arquivo);
    fputs(nome_db,ptr_arquivo);
    fputs(";\n",ptr_arquivo);

    fputs("CREATE TABLE ",ptr_arquivo);
    fprintf(ptr_arquivo,"%s (",nome_tabela);
    for(i=0;i<n_col;i++)
    {
        if(i!=n_col-1)
            fprintf(ptr_arquivo,"\n%s VARCHAR(%d),",head->nome_colunas[i],tam_atr);
        else
            fprintf(ptr_arquivo,"\n%s VARCHAR(%d) );",head->nome_colunas[i],tam_atr);
    }

    fclose(ptr_arquivo);


    return;
}


int main(int argc, char *argv[]) 
{
    FILE *ptr_arquivo;
    char *linha,**nome_colunas,**dados;
    int i,j,n_colunas,contador_linha,max;
    REMUNERACAO *lista,*no;

    ptr_arquivo = fopen(argv[1],"r");
    n_colunas=0;
    linha = get_linha(ptr_arquivo);
    nome_colunas = get_colunas(linha,&n_colunas);
    
    for(i=0;i<n_colunas;i++)
    {
        printf("Coluna [%d]  - %s\n",i,nome_colunas[i]);
    }
    putchar('\n');



    lista = NULL;
    contador_linha=1;
    while((linha = get_linha(ptr_arquivo)) != NULL)
    {
        if(contador_linha>LIMITE_LISTA)
            break;
        dados = get_colunas(linha,&n_colunas);
        no = cria_entrada(nome_colunas,dados);
        insere_lista(&lista,no);
        contador_linha++;
    }
    fclose(ptr_arquivo);

    no = lista;
    max =0;
    for(i=0;;i++)
    {
        if(no!=NULL)
        {
            for(j=0;j<n_colunas;j++)
            {

                strlen(no->dados[j]) > max? max = strlen(no->dados[j]): 0;  
            }
            no=no->prox;
            continue;
        }
        else
            break;
    }
    printf("tamanho maximo de um atributo = %d",max);

    create_query(lista,argv[2],argv[3],max,n_colunas);
    return 0;
}