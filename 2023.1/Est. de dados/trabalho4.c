#include <stdio.h>
#include <stdlib.h>

#define STR_SIZE 100
/* ler um arquivo com o seguinte formato:

8
0.0.0.0/0 N/A
146.164.0.0/16 UFRJ
146.164.3.7/32 acd.ufrj.br
146.164.40.0/23 DCC-UFRJ
146.164.41.220/32 Maquina do Claudson
3.0.0.0/8 GE
18.72.0.3/32  name server: bitsy.mit.edu
18.62.0.0/24 eecs.mit

146.164.3.8
146.164.41.210
5.0.1.2

A primeira linha indica o numero de linhas com blocos que se seguem. Estas linhas tem 1 bloco cidr, espaco, e informacoes sobre o bloco.
Para cada um dos ips que se seguem, o programa deve imprimir a informacao mais especifica disponivel para aquele bloco. Deve ser implementado com uma arvore digital ou patricia.

A saida, para este exemplo, acho que seria:

146.164.3.8 UFRJ
146.164.41.210 DCC-UFR
5.0.1.2 N/A
*/

/* Definição de um endereço e função para ler a linha */
typedef struct _endereco
{
    long int ip;
    int mascara;
    char *info;
}ENDERECO;

/* funcao pra ler linha de entrada com endereço e informação */
ENDERECO* reader()
{
    long int temp,i,num,tam;
    int mascara;
    char *info,c;
    ENDERECO *ptr;

    /*alocando string pra info */
    info = malloc(sizeof(char)*STR_SIZE);
    /*Construir long int com o endereço inteiro*/
    num = 0;
    for(i=0;i<4;i++)
    {
        scanf("%ld",&temp);
        getchar();
        num += temp;
        // printb(num);
        if(i!=3)
            num = (num << 8);
    
    }
    
    
    scanf("%ld",&mascara); //lendo mascara

    /* Ler string no fim da linha.*/
    i=0;
    while( (c=getchar()) )
    {
        if((c!='\n'))
        {
            info[i++]=c;
        }
        else
        {
            info[i++]='\0';
            break;
        }
    }

    ptr = malloc(sizeof(ENDERECO));
    ptr->ip = num;
    ptr->info = info;
    ptr->mascara = mascara;

    return ptr;
}

/* funcao pra ler linha com endereco*/
long int ip_reader(char *cidr_str)
{
    long int temp,num,inicio,fim,tam,pos,pontos,j,temp2;
    int i;
    char c;
    /*Construir long int com o endereço inteiro em string*/
    num = inicio = pontos = temp = num = 0;
    i=0;
    
    while(1)
    {
        if(pontos==4)
            break;
        
        inicio=i;
        if(pontos!=3)
        {
            while(cidr_str[i]!='.')
                i++;
            fim=i;
        }
        else
        {
            while(cidr_str[i]!='\0')
                i++;
            fim=i;
        }
        pontos++;
        tam = fim-inicio-1;

        for(temp=0,pos=tam;inicio<fim;inicio++,pos--)
        {  
            temp2=0;
            temp2 += (cidr_str[inicio] - '0');
            for(j=0;j<pos;j++)
                temp2*=10;
            temp+=temp2;
        }

        num += temp;
        // printb(num);
        if(pontos<4)
            num = (num << 8);
        
        i++;
    }
    return num;
}

/* Definicao da árvore digital binaria e suas funcoes */
typedef struct _NO
{
    ENDERECO *endereco;
    struct _NO *esq;
    struct _NO *dir;
}NO;

NO* init_node()
{
    NO* ptr;
    ptr = malloc(sizeof(NO));
    ptr->dir = NULL;
    ptr->endereco = NULL;
    ptr->esq = NULL;
    return ptr;
}

int buscar(NO *arvore,long int n, NO** ultimo_com_info)
{
    int i;

    *ultimo_com_info = NULL;
    // /* obtendo tamanho da palavra */
    // for(i=31;i>=0;i--)
    // {
    //     if(n & (1<<i))
    //         break;
    // }

    //buscando 
    for(i=31;i>=0;i--)
    {
        if(arvore->endereco!=NULL)
            *ultimo_com_info = arvore;

        if( n & (1<<i)) //se bit =1
        {
            if(arvore->dir!=NULL)
                arvore=arvore->dir;
            else
                break;
        }
        else // se bit = 0
        {
            if(arvore->esq!=NULL)
                arvore=arvore->esq;
            else
                break;
        
        }
        // printf("tem o %d bit!\n",32-i);
    }
    
    if(arvore->endereco!=NULL && (arvore->endereco->ip == n)) // chegou, mas tem  endereço associado?
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/*
Adiciona a NO* 'arvore' o endereço 'endereco', com a mascara 'mascara'
*/
void adicionar(NO* arvore, ENDERECO *endereco, int mascara)
{
    int i,j;
    long int n = endereco->ip;
    // /* obtendo tamanho */
    // for(i=31;i>=0;i--)
    // {
    //     if(n & (1<<i))
    //         break;
    // }
    

    for(i=31,j=0;i>=0 && j<mascara;i--, j++)
    {
        if( n & (1<<i) )
        {
            if(arvore->dir!=NULL)
                arvore=arvore->dir;
            else
            {
                arvore->dir = init_node();
                arvore = arvore->dir;
            }
        }
        else
        {
            if(arvore->esq!=NULL)
                arvore=arvore->esq;
            else
            {
                arvore->esq = init_node();
                arvore = arvore->esq;
            }
        }
    }
    arvore->endereco=endereco;
}

/* (fins de debug) função pra imprimir numero em binario. */
// void printb(long int n)
// {
//     long int i,c;
//     for(i=31;i>=0;i--)
//     {
//         if(n & (1<<i))
//         {
//             c=i;
//             break;
//         }
//     }
//     putchar('\n');
//     for(i=c;i>=0;i--)
//     {
//         if(n & (1<<i))
//             putchar('1');
//         else
//             putchar('0');
//     }
//     putchar('\n');
// }

int main()
{
    int num_linhas,i,pos_busca,fim;
    ENDERECO *enderecos;
    NO *arvore,*no_busca,*ultimo_com_info= NULL;
    long int cidr,temp;
    char cidr_str[STR_SIZE];
    //inicializar arvore

    no_busca = arvore = init_node();

    /* ler n de linhas */
    scanf("%d",&num_linhas);

    /* alocar n enderecos */
    enderecos = malloc(num_linhas*sizeof(ENDERECO));

    /* ler endereços */
    for(i=0;i<num_linhas;i++)
    {
        enderecos[i]=*(reader());
        
        //adicionar endereco na arvore
        buscar(arvore,enderecos[i].ip,&ultimo_com_info);

        adicionar(no_busca,&enderecos[i],enderecos[i].mascara);
    }

    // /* debug da leitura */
    // for(i=0;i<num_linhas;i++)
    // {
    //     printf("\n\t Buscando endereço [%d]\n"
    //         "\n\t Numero = %ld\n\tInfo: %s\n",
    //         i,enderecos[i].ip,enderecos[i].info);

    //     if(buscar(arvore,&enderecos[i],&pos_busca,&no_busca,&ultimo_com_info))
    //         printf("\nEsta na arvore! num achado= %ld\n",no_busca->endereco->ip);
    //     else
    //         puts("\n ....nao ta na arovre..............\n");
        
    // }
    
    cidr = 0;
    while(scanf("%s",cidr_str) && !feof(stdin))
    {
        cidr=0;
        cidr = ip_reader(cidr_str);
        buscar(arvore,cidr,&ultimo_com_info);
        printf("%s %s\n",cidr_str,ultimo_com_info->endereco->info);
    }


    return 0;
}