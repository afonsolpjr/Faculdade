/* AFONSO LUSTOSA PIRES JUNIOR */
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>



char c;


/* todo:
    -consertar erro dos allocs */
typedef struct _token
{
    char *token;

    int token_length;

    /* numero, nome, simbolos, espaços, comentarios ou palavras reservadas*/
    char name_type[19];
    int type;
} token;



token* init_token()
{
    token *new_token;

    if((new_token = malloc(sizeof(token)))==NULL)
    {
        puts("erro na alocação de memória");
    }
    new_token->token_length=16;
    
    if((new_token->token = calloc(new_token->token_length,sizeof(char))) ==NULL)
    {
        puts("erro na alocação de memória");
    }
    return new_token;
}


/* aumenta tamanho da string token*/
void expand_string(token* token)
{
    char *new_str;
    int i;
    token->token_length = token->token_length*2;
    if(( new_str = realloc(token->token,token->token_length))==NULL)
    {
        puts("erro na alocação de memória");
    }

    if(new_str!=token->token)
        free(token->token);
    
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
    while( (i < token->token_length) && token->token[i]!='\0')
        i++;

    
    /* aumentar array se necessario*/
    if(i==token->token_length)
        expand_string(token);

    token->token[i]=c;
    c = getchar();
}

/* 
# Símbolos
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


token* next_token()
{
    token *new_token;
    new_token = init_token();

    if (isspace(c))
    {
        strcpy(new_token->token," ");
        strcpy(new_token->name_type,"ESPACO");
        new_token->type=0;
        consume(new_token);
        return new_token;
    }

    // /* caso seja numero */
    if(isdigit(c))
    {
        while(isdigit(c))
            consume(new_token);
        
        strcpy(new_token->name_type,"NUMERO");
        new_token->type=1;
        return new_token;
    }

    // /*checando se é nome e então se é palavra reservada*/
    // if(isalpha(peek(0))){

    //     /*not a reserved word*/
    //     i=0;
    //     while(isalnum(peek(i)))
    //     {
    //         new_token.token[i]=peek(i);
    //         i++;
    //     }
    //     new_token.token[i]='\0';
    //     /* checar se é palavra reservada*/
        
    //     strcpy(new_token.name_type,"NOME");
    //     consume(i);

    //     /*checking reserved words*/

    //     if(strcmp(new_token.token,"if")==0)
    //     {
    //         strcpy(new_token.name_type,"PALAVRA RESERVADA");
    //     }
    //     else if(strcmp(new_token.token,"else")==0)
    //     {
    //         strcpy(new_token.name_type,"PALAVRA RESERVADA");
    //     }
    //     else if(strcmp(new_token.token,"while")==0)
    //     {
    //         strcpy(new_token.name_type,"PALAVRA RESERVADA");
    //     }
    //     else
    //         strcpy(new_token.name_type,"NOME");
    
    //     new_token.type=1;
    //     return new_token;
    // }
    
    // /*checando se é comentario*/
    // if(peek_str(str,2))
    // {   
    //     if(strcmp(str,"/*")==0)
    //     {

    //         consume(2);
    //         i=0;
    //         while(ind<(buffer_length-1))
    //         {
    //             peek_str(str,2);
    //             if(strcmp(str,"*/")==0)
    //             {
    //                 strcpy(new_token.token," ");
    //                 strcpy(new_token.name_type,"COMENTARIO");
    //                 consume(2);
    //                 new_token.type=0;
    //                 return new_token;
    //             }
    //             consume(1);
    //         }
    //         /* Caso o comentário não feche até o final do arquivo */
    //         new_token.type=-1;
    //         return new_token;
    //     }
    // }

    // /*se simbolo*/
    // if(issymbol(peek(0)))
    // {
    //     new_token.token[0]=peek(0);
    //     new_token.token[1]='\0';
    //     strcpy(new_token.name_type,"SIMBOLO");
    //     consume(1);
    //     new_token.type=1;
    //     return new_token;
    // }
    
    // new_token.token[0]=peek(0);
    // new_token.token[1]='\0';
    // strcpy(new_token.name_type,"CHAR INVALIDO");
    // consume(1);
    // new_token.type = -2;
}


void print_token(token *token)
{
    printf("%s\t%s\n",token->name_type,token->token);
}

int main()
{
    int i,max_tokens = 8;
    token **tokens;


    tokens = calloc(max_tokens,sizeof(token*));

    c=getchar();
    i=0;
    while(c!=EOF){

        // printf("\n\tvalor de c=%d\n",c);
        
        tokens[i++]=next_token();
        if(tokens[i-1]->type==-1)
        {
            puts("\tERRO: Faltou fechar um comentário");
            return 0;
        }
        else if(tokens[i-1]->type==-2)
        {
            printf("\tERRO: Caractere inválido '%s'\n",tokens[i-1]->token);
            return 0;
        }
    }

    for(i=0;i<max_tokens;i++)
    {
        print_token(tokens[i]);
    }


    return 0;
}