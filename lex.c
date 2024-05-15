/* AFONSO LUSTOSA PIRES JUNIOR */
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 1000



/* To do

    checar tamanho do buffer
    */
typedef struct _token
{
    char token[MAX_LENGTH];
    
    /* numero, nome, simbolos, espaços, comentarios ou palavras reservadas*/
    char name_type[19];
    int type;
} token;



char buffer[MAX_LENGTH];
int ind=0;
int buffer_length=0;

int bufferize_input()
{
    int i=0;
    char c;

    while( ((c=getchar())!= EOF) && (i<MAX_LENGTH))
    {
        buffer[i++]=c;
    }
    if(c!=EOF && (i>= MAX_LENGTH))
        return 0;
    

    buffer[i]='\0';
    buffer_length=i;
    return 1;
}

char peek(int i)
{
    if(ind!=buffer_length)
        return buffer[ind+i];
    return '\0';
}

/* Retorna string de tamanho i a partir do */

int peek_str(char* str,int i)
{
    int k=0;
    if((i+ind)>buffer_length)
        return 0;

    for(k=0;k<i;k++)
    {
        str[k]=peek(k);
    }
    str[k]='\0';
    return 1;
}

void consume(int i)
{
    ind+=i;
}

/* 
# Símbolos
Categoria:  + - * / % ( ) [ ] { } , ; =
Valor:      Não há */
int issymbol(char c)
{
    switch(c)
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


token next_token(){
    token new_token;
    int i;
    char str[MAX_LENGTH];

    if (isspace(peek(0)))
    {
        strcpy(new_token.token," ");
        strcpy(new_token.name_type,"ESPACO");
        consume(1);
        new_token.type=0;
        return new_token;
    }

    /* caso seja numero */
    if(isdigit(peek(0)))
    {
        i=0;
        while(isdigit(peek(i)))
        {
            new_token.token[i]=peek(i);
            i++;
        }
        strcpy(new_token.name_type,"NUMERO");
        new_token.token[i]='\0';
        // printf("i=%d\n",i);
        consume(i);
        new_token.type=1;
        return new_token;
    }

    /*checando se é nome e então se é palavra reservada*/
    if(isalpha(peek(0))){

        /*not a reserved word*/
        i=0;
        while(isalnum(peek(i)))
        {
            new_token.token[i]=peek(i);
            i++;
        }
        new_token.token[i]='\0';
        /* checar se é palavra reservada*/
        
        strcpy(new_token.name_type,"NOME");
        consume(i);

        /*checking reserved words*/

        if(strcmp(new_token.token,"if")==0)
        {
            strcpy(new_token.name_type,"PALAVRA RESERVADA");
        }
        else if(strcmp(new_token.token,"else")==0)
        {
            strcpy(new_token.name_type,"PALAVRA RESERVADA");
        }
        else if(strcmp(new_token.token,"while")==0)
        {
            strcpy(new_token.name_type,"PALAVRA RESERVADA");
        }
        else
            strcpy(new_token.name_type,"NOME");
    
        new_token.type=1;
        return new_token;
    }
    
    /*checando se é comentario*/
    if(peek_str(str,2))
    {   
        if(strcmp(str,"/*")==0)
        {

            consume(2);
            i=0;
            while(ind<(buffer_length-1))
            {
                peek_str(str,2);
                if(strcmp(str,"*/")==0)
                {
                    strcpy(new_token.token," ");
                    strcpy(new_token.name_type,"COMENTARIO");
                    consume(2);
                    new_token.type=0;
                    return new_token;
                }
                consume(1);
            }
            /* Caso o comentário não feche até o final do arquivo */
            new_token.type=-1;
            return new_token;
        }
    }

    /*se simbolo*/
    if(issymbol(peek(0)))
    {
        new_token.token[0]=peek(0);
        new_token.token[1]='\0';
        strcpy(new_token.name_type,"SIMBOLO");
        consume(1);
        new_token.type=1;
        return new_token;
    }
    
    new_token.token[0]=peek(0);
    new_token.token[1]='\0';
    strcpy(new_token.name_type,"CHAR INVALIDO");
    consume(1);
    new_token.type = -2;
    return new_token;
}



int main()
{
    int i,n_tokens = 0;
    token tokens[MAX_LENGTH];

    if(!(bufferize_input()))
    {
        puts("Entrada é maior que o buffer permitido.\n Altere a macro MAX_LENGTH\n");
    }
    // printf("%s \n<fim do buffer>\n",buffer);


    while(peek(0)!='\0'){
        tokens[n_tokens++]=next_token();
        if(tokens[n_tokens-1].type==-1)
        {
            puts("\tERRO: Faltou fechar um comentário");
            return 0;
        }
        else if(tokens[n_tokens-1].type==-2)
        {
            printf("\tERRO: Caractere inválido '%s'\n",tokens[n_tokens-1].token);
            return 0;
        }
    }

    for(i=0;i<n_tokens;i++)
    {
        if(tokens[i].type==1)
            printf("%s\t%s\n",tokens[i].name_type,tokens[i].token);
    }
    return 0;
}