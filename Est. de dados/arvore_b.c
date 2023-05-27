#include <stdio.h>
#include <stdlib.h>

typedef struct __no
{      /* no maximo 4 chaves, para d = 2*/
    int chave[4];
    int n_chaves;
    struct __no *filho[5];
    struct __no *pai;
}NO;

typedef struct __busca
{
    NO *ptr;
    int result;
    int indice;
}BUSCA;

BUSCA* busca(NO *raiz, int valor)
{
    BUSCA *busca_ptr = malloc(sizeof(BUSCA));
    NO *ptr = raiz;
    int i;
    
    busca_ptr->result=0; 
    while (ptr!=NULL)
    {
        i=0;
        while(i<4)
        {
            if(valor > ptr->chave[i]) /*se for maior, continua na msm pagina*/
                i++;
            else if(valor == ptr->chave[i])
            {
                busca_ptr->result = 1;
                return busca_ptr;
            }
            else /* se for menor, como é ordenado, precisa mudar de pagina*/
            {
                ptr = ptr->filho[i];
                break;
            }
        }
        if(i==4)  /* caso seja ultimo, mudar pag pro ultimo filho*/
            ptr = ptr->filho[i+1];
    }
    busca_ptr->indice = i;
    return busca_ptr;

}

void insercao(int num, NO* ptr_no, int indice)
{
    NO *no = ptr_no;
    int i;
    if(no->n_chaves == 4)     //é sempre d que sobe. mas caso indice != d, pode ser d-1 ou d+1
    {
        /* cisao */
    }
    else
    {
        for(i=3;i>indice;i++) /*joga geral pra frente*/
        {
            no->chave[i] = no->chave[i-1];
        }
        no->chave[indice] = num;
        no->n_chaves++;
    }                      
}

int main()
{
    int chave,i;
    NO* ptr_raiz = malloc(sizeof(NO));
    BUSCA *res_busca;

    /*definindo arvore inicial*/
    for(i=0;i<4;i++)
    {
        ptr_raiz->chave[i] = -1; 
        ptr_raiz->filho[i] = NULL;
    }
    ptr_raiz->filho[i]=NULL;
    ptr_raiz->pai = NULL;

    puts("Insira numeros para insercao na arvore\n");

    while( (scanf("%d",&chave)) && (chave!= 0) && (chave > 0) )
    {
        res_busca = busca(ptr_raiz,chave);
        if(res_busca->result)
        {
            puts("\n\t Chave já inserida.\n");
        }
        else
        {
           /* inserir */
        }
    }


}