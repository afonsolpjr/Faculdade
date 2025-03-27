/* AFONSO LUSTOSA PIRES JUNIOR */
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

char c;

typedef struct _token
{
    char *token;

    int token_length;

    /* numero, nome, simbolos, espaços, comentarios ou palavras reservadas*/
    char name_type[19];
    int type; // 1 = nome ou num, 2,3= simbolo ou palavra reservada
} token;

/* inicializa uma estrutura de token */
token* init_token()
{
    token *new_token;

    if((new_token = malloc(sizeof(token)))==NULL)
    {
        puts("erro na alocação de memória");
        return NULL;
    }
    new_token->token_length=16;
    
    if((new_token->token = calloc(new_token->token_length,sizeof(char))) ==NULL)
    {
        puts("erro na alocação de memória");
        return NULL;
    }
    return new_token;
}

/* aumenta tamanho da string do token enviado como parâmetro */
void expand_string(token* token)
{
    char *new_str;
    int i;
    token->token_length = token->token_length*2;
    if(( new_str = realloc(token->token,token->token_length))==NULL)
    {
        puts("Erro na alocação de memória");
    }
    
    token->token = new_str;

    /* inicializando com \0s */
    for(i=token->token_length/2;i<token->token_length;i++)
    {
        token->token[i]='\0';
    }
}

void consume(token *token)
{
    int i=0;
    /*procurar posicao pra inserir c */
    while( (i < token->token_length-1) && token->token[i]!='\0')
        i++;

    
    /* aumentar array se necessario*/
    if(i == token->token_length-1)
        expand_string(token);

    token->token[i]=c;
    c = getchar();
}

/*Símbolos
Categoria:  + - * / % ( ) [ ] { } , ; =
Valor:      Não há */
int issymbol(char ch)
{
    switch(ch)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case '(':
    case ')':
    case '[':
    case ']':
    case '{':
    case '}':
    case ',':
    case ';':
    case '=':
        return 1;
    default:
        return 0;
    }
}

/* regras de tokenização */
token* next_token()
{
    token *new_token;
    new_token = init_token();

    /* cespaço */
    if (isspace(c))
    {
        strcpy(new_token->token," ");
        strcpy(new_token->name_type,"ESPACO");
        new_token->type=0;
        consume(new_token);
        return new_token;
    }

    /* numero */
    if(isdigit(c))
    {
        while(isdigit(c))
            consume(new_token);
        
        strcpy(new_token->name_type,"NUM");
        new_token->type=1;
        return new_token;
    }

    /*checando se é nome e então se é palavra reservada*/
    if(isalpha(c)){

        while(isalnum(c))
            consume(new_token);
        
        /* checar se é palavra reservada*/
        switch(strcmp(new_token->token,"if")==0
            || strcmp(new_token->token,"while")==0
            || strcmp(new_token->token,"else")==0)
        {
        case 1:
            strcpy(new_token->name_type,"PALAVRA RESERVADA");
            new_token->type=3;
            break;
        default:
            strcpy(new_token->name_type,"NOME");
            new_token->type=1;
        }
        return new_token;
    }
    

    /*se simbolo*/
    if(issymbol(c))
    {
        consume(new_token);
        
        //se for comentario:
        if(new_token->token[0]=='/' && c=='*')
        {
            consume(new_token);
            while(c!=EOF)
            {
                if(c=='*')
                {
                    consume(new_token);
                    if(c=='/') //fim do comentario
                    {
                        consume(new_token);
                        strcpy(new_token->name_type,"COMENTARIO");
                        new_token->type=0;
                        return new_token;
                    }
                }
                else
                    consume(new_token);
            }
            //chegou ao fim e nao fechou o comentario
            new_token->type=-1;
            return new_token;
        }
        strcpy(new_token->name_type,"SIMBOLO");
        new_token->type=2;
        return new_token;
    }

    /* demais opções inválidas*/
    consume(new_token);
    strcpy(new_token->name_type,"CHAR INVALIDO");
    new_token->type = -2;
    return new_token;
}

/* print simples para um token */
void print_token(token *token)
{
    switch(token->type)
    {
    case 1:
        printf("%s\t%s\n",token->name_type,token->token);    
        return;
    case 2:
    case 3:
        printf("%s\n",token->token);
        return;
    }
}

/* aumenta a memoria para alocação de tokens */
token** expand_tokens(token **tokens, int *max_tokens)
{
    token **new_tokens;
    *max_tokens = 2 * *max_tokens;

    if( (new_tokens=realloc(tokens,(*max_tokens)*sizeof(*tokens))) == NULL)
    {
        puts("\nErro na alocação de memória");
        return NULL;
    }

    return new_tokens;
}


int main()
{
    int i,n_tokens,max_tokens = 8,j;
    token **tokens;


    tokens = calloc(max_tokens,sizeof(token*));

    c=getchar();
    i=0;
    while(c!=EOF){

        if(i==max_tokens)
            tokens = expand_tokens(tokens,&max_tokens);

        tokens[i]=next_token();

        switch(tokens[i]->type)
        {
        case -1:
            puts("\tERRO: Faltou fechar um comentário");
            return 1;
        case -2:
            printf("\tERRO: Caractere inválido '%s'\n",tokens[i]->token);
            return 1;
        case 3:
            //colocando palavras reservadas em maiusculo
            for(j=0;tokens[i]->token[j]!='\0';j++)
                tokens[i]->token[j]-=32;
        }

        i++;
    }
    n_tokens=i;
    for(i=0;i<n_tokens;i++)
    {
        if(tokens[i]->type>0)
            print_token(tokens[i]);
    }


    return 0;
}