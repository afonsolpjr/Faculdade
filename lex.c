/* AFONSO LUSTOSA PIRES JUNIOR */
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 500

typedef struct _token
{
    char token[MAX_LENGTH];
    /* numero, nome, simbolos, espaços, comentarios ou palavras reservadas*/
    char type[19];
} token;



char buffer[MAX_LENGTH];
int ind=0;
int buffer_length=0;

void bufferize_input()
{
    int i=0;
    char c;

    while( ((c=getchar())!= EOF) && (i<MAX_LENGTH))
    {
        buffer[i++]=c;
    }
    buffer[i]='\0';
    buffer_length=i;
}

char peek(int i)
{
    if(ind!=buffer_length)
        return buffer[ind+i];
    return '\0';
}

/* return a string of size i starting from current ind */
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

int issymbol(char c)
{
    switch(c)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '=':
    case ';':
    case '%':
    case '(':
    case ')':
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
        strcpy(new_token.type,"ESPACO");
        consume(1);
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
        strcpy(new_token.type,"NUMERO");
        new_token.token[i]='\0';
        // printf("i=%d\n",i);
        consume(i);
        return new_token;
    }

    /*checando se é nome ou palavra reservada*/
    if(isalpha(peek(0))){

        /*checking reserved words*/
        
        if(peek_str(str,2))
        {
            if(strcmp(str,"if")==0)
            {
                strcpy(new_token.token,"if");
                strcpy(new_token.type,"PALAVRA RESERVADA");
                consume(2);
                return new_token;
            }
        }
        if(peek_str(str,4))
        {

            if(strcmp(str,"else")==0)
            {
                strcpy(new_token.token,"else");
                strcpy(new_token.type,"PALAVRA RESERVADA");
                consume(4);
                return new_token;
            }

        }
        if(peek_str(str,5))
        {
            if(strcmp(str,"while")==0)
            {
                strcpy(new_token.token,"while");
                strcpy(new_token.type,"PALAVRA RESERVADA");
                consume(5);
                return new_token;
            }
        }
    
        /*not a reserved word*/
        i=0;
        while(isalnum(peek(i)))
        {
            new_token.token[i]=peek(i);
            i++;
        }
        new_token.token[i]='\0';
        strcpy(new_token.type,"NOME");
        consume(i);
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
                    strcpy(new_token.type,"COMENTARIO");
                    consume(2);
                    return new_token;
                }
                consume(1);

            }

        }
    }

    /*se simbolo*/
    if(issymbol(peek(0)))
    {
        new_token.token[0]=peek(0);
        new_token.token[1]='\0';
        strcpy(new_token.type,"SIMBOLO");
        consume(1);
        return new_token;
    }
    
    new_token.token[0]=peek(0);
    new_token.token[1]='\0';
    strcpy(new_token.type,"CHAR INVALIDO");
    consume(1);
    return new_token;
}



int main()
{
    int i,n_tokens = 0;
    token tokens[MAX_LENGTH];
    char test[MAX_LENGTH];

    bufferize_input();
    printf("%s \n<fim do buffer>\n",buffer);


    while(peek(0)!='\0'){
        tokens[n_tokens++]=next_token();
    }

    for(i=0;i<n_tokens;i++)
    {
        printf("%s\t%s\n",tokens[i].type,tokens[i].token);
    }
    return 0;
}