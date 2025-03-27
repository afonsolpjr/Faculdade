#include <stdio.h>
#include <stdlib.h>
#define CONST_D 2



typedef struct __no
{      /* no maximo 4 chaves, para d = 2. indice final guardado para ajudar no processo de cisao*/
    int chave[2*CONST_D + 1];
    int n_chaves;
    int folha;
    struct __no *filho[2*CONST_D + 1];
    struct __no *pai;

}NO;

typedef struct __busca
{
    NO *ptr;
    int indice,resultado;
}BUSCA;


NO* aloca_no()
{
    int i;
    NO *ptr;
    ptr = malloc(sizeof(NO));
    ptr->folha=1;
    ptr->n_chaves=0;
    ptr->pai = NULL;
    for(i=0;i<(CONST_D*2 + 1);i++)
        ptr->filho[i]=NULL;
    

    return ptr;
}

BUSCA* busca(NO *raiz, int valor)
{
    BUSCA *busca_ptr = NULL;
    NO *ptr = raiz;
    int i;
    
    i=0;

    while( i<(raiz->n_chaves) &&  valor>(raiz->chave[i]) )
        i++;
    if(valor == raiz->chave[i] && i<(raiz->n_chaves) ) /* se chave encontrada*/
    {
        busca_ptr = malloc(sizeof(BUSCA));
        busca_ptr->resultado = 1;
        return busca_ptr;
    }
    else if(raiz->folha)     /* se é folha e a chave n tá, retornar posicao que estaria.*/
    {
        busca_ptr = malloc(sizeof(BUSCA));
        busca_ptr->indice = i;
        busca_ptr->ptr = raiz;
        busca_ptr->resultado = 0;

        return busca_ptr;
    }
    else if(!(raiz->folha))     /* mudar de pagina*/
    {
        return busca(raiz->filho[i],valor);
    }
}

int insercao(int num, NO* ptr_no, int indice);

void insere_chave_lista(int *vetor, int indice, int n, int n_chaves)
{
    int i,temp;

    for(i = n_chaves;i>indice;i--)
    {
        vetor[i] = vetor[i-1];
    }
    vetor[i] = n;
}

int cisao(NO* ptr_no)         
{
    int num_meio,i,j,i_adc;
    NO* novo_pai, *no_adc,*pai;
    pai = ptr_no->pai;

    num_meio = ptr_no->chave[CONST_D];

    // Criando nó adicional
    no_adc = aloca_no();

    for(i=0;i<(CONST_D*2 + 1);i++) //limpando e transferindo filhos
    {
        if(i>CONST_D) //limpar em ptr no e botar no no_adc
        {
            i_adc = i-CONST_D-1;
            insercao(ptr_no->chave[i],no_adc,i_adc);
            no_adc->filho[i_adc] = ptr_no->filho[i];
            ptr_no->filho[i] = NULL;
            ptr_no->chave[i] = 0;
            ptr_no->n_chaves--;
        }
    }
    ptr_no->chave[CONST_D] = 0;
    ptr_no->n_chaves--;

    if(pai == NULL)      // !!!!!!!! RAIZ CINDINDO  !!!!!! 
    {
        novo_pai = aloca_no();
        insercao(num_meio,novo_pai,0);
        novo_pai->filho[0] = ptr_no;
        novo_pai->filho[1] = no_adc;
        novo_pai->folha = 0;
        ptr_no->pai = novo_pai;
        no_adc->pai = novo_pai;
        return 1;
    }
    else
    {
        //achar indice de insercao no pai
        i=0;
        while(i<pai->n_chaves && num_meio>pai->chave[i])
            i++;
        j=i;
        insercao(num_meio,pai,j);       
        for(i=(CONST_D*2 +1);i>j;i--)
        {
            pai->filho[i]=pai->filho[i-1];
        }
        pai->filho[j] = ptr_no;
        pai->filho[j+1] = no_adc;
        no_adc->pai = pai;
    }
}

int insercao(int num, NO* ptr_no, int indice)   /*Se cindiu a raiz, retorna 1*/
{
    if(ptr_no->n_chaves <= CONST_D*2)
    {
        //Inserção normal.
        insere_chave_lista(ptr_no->chave,indice,num,ptr_no->n_chaves);
        ptr_no->n_chaves++;
    }
    
    if(ptr_no->n_chaves > CONST_D*2 )
    {
        cisao(ptr_no);
    }

}

void print_arvore(NO* raiz)
{
    int i;


    if(raiz==NULL)
        return;
    
    for(i=0;i<raiz->n_chaves;i++)
    {
        print_arvore(raiz->filho[i]);
        printf("[%d] ",raiz->chave[i]);
    }
    print_arvore(raiz->filho[i]);
}
int main()
{
    int chave,i;
    NO* ptr_raiz;
    BUSCA *res_busca;

    /*definindo arvore inicial*/
    ptr_raiz = aloca_no();  

    puts("Insira numeros para insercao na arvore\n");

    while( (scanf("%d",&chave)) && (chave!= 0) && (chave > 0) )
    {
        res_busca = busca(ptr_raiz,chave);
        if(res_busca->resultado)
        {
            puts("\n\t Chave já inserida.\n");
        }
        else
        {
            (insercao(chave,res_busca->ptr,res_busca->indice));
            if(ptr_raiz->pai!=NULL) //raiz cindiu
                ptr_raiz = ptr_raiz->pai;
            
            print_arvore(ptr_raiz);
           
           

        }
        free(res_busca);
    }


}