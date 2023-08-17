#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    char keyword[46], **message,cifra[26][26];
    int n,i,j,keylen,check,k;
    
    scanf("%s",keyword);
    scanf("%d\n",&n);
    
    message = (char**) calloc(n,sizeof(char*));

  
    
    for(i=0;i<n;i++) //lendo msgs
    {
        message[i] = (char*) calloc(100000,sizeof(char));
        j=0;
        while((message[i][j++]=getchar())!='\n');
        message[i][j-1] = '\0';
    }

    for(i=0;;i++) //vendo tamanho da keyweord
    {
        if(keyword[i]=='\0')
        {
            keylen = i;
            break;
        }
    }
    
      //fazendo cifra
    for(i=0;i<26;i++)
    {
        for(j=0;j<26;j++)
        {
            if(97+j+i<122) cifra[i][j] = 97 + j + i;
            else cifra[i][j] = 97 + ((j+i)%26);
        }
    }
    
    //criptografando

    for(i=0;i<n;i++)
    {
        check=1;
        k=0;
        for(j=0;;j++)
        {   
            if(message[i][j]=='\0') break;
            // printf("checando o char [%c]\n",message[i][j]);
            switch(message[i][j])
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                    while(1)
                    {
                        if(message[i][j] == 32 || !message[i][j]) break;
                        else j++;
                    }
                    break;
                
                default:
                    while(message[i][j]!= 32 && message[i][j])
                    {
                        // printf("ihaa j=%d [j]=%c \t (j-space %% keylen) = %d\n ",j,message[i][j],(j-spaces)%keylen);
                        message[i][j] = cifra[keyword[k%keylen]-97][message[i][j]-97];
                        j++;
                        k++;
                    }
                    break;

            }
            if(check<0) break;
            
        }
    }
    
    
    
    
    for(i=0;i<n;i++) printf("%s\n",message[i]);



    return 0;
}