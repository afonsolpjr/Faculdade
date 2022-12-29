/* BEECROWD 3232 
table of words: 
“be” “our” “rum” “will”
“dead” “hook” “ship” “blood”
“sable” “avenge” “parrot” “captain”
*/

#include <stdio.h>
#include <string.h>

void impossible()
{
    printf("Impossible\n");
}

int strtam(char *str)
{
    int i;

    for(i=0;;i++) if(str[i]=='\0') return i;
}

int diffwords(char *palavra) //retorna n de letras diferentes na string
{
    int i,alfabeto[26]={0},resultado;


    for(i=0;(palavra[i]!='\0');i++)
    {
        if(palavra[i]!=32)
        {
            alfabeto[122-palavra[i]]=1;
        }
    }
    for(resultado=0,i=0;i<26;i++) 
    {
        if(alfabeto[i]==1) resultado++;
    }
    return resultado;
}

int checa_palavra(char* palavra)
{
    if(strtam(palavra)<2 || strtam(palavra)>7) return -1;   //nao se compara com nenhuma das 12 palavras
    else
    {
        switch(strtam(palavra))
        {
            case 7:
                if( (diffwords(palavra)==6) && (palavra[1]==palavra[4])   )
                {
                    return 12; //captain
                }
                break;
            
            case 6:
                if((palavra[2]==palavra[3]) && diffwords(palavra)==5)
                {
                    return 11; //parrot
                }
                else if((palavra[2]==palavra[5]) && diffwords(palavra)==5)
                {
                    return 10; //avenge
                } break;
            case 5:
                if(diffwords(palavra)==4 && palavra[2]==palavra[3])
                {
                    return 8; //blood
                }
                else return 0;
                break;
            case 4:
                if(diffwords(palavra)==3 && palavra[1]==palavra[2])
                {
                    return 6; //hook
                }
                else if(diffwords(palavra)==3 && palavra[0]==palavra[3])
                {
                    return 5; //dead
                }
                else if(diffwords(palavra)==3 && palavra[2]==palavra[3])
                {
                    return 4; //will
                }
                break;

            default:
                return 0;
                break;
        }
    }
    return 0;
}
void substituir(char *string, char *cript, int n, char *final)
{
    int i,j;
    char word[8];


    switch(n)
    {
        case 12:

            strcpy(word,"captain");

            for(i=0;cript[i]!='\0';i++)
            {
                for(j=0;string[j]!='\0';j++)
                {
                    if(string[j]==cript[i])
                    {
                        final[j]=word[i];
                    }
                }
            }
            break;

        case 11:

            strcpy(word,"parrot");
            for(i=0;cript[i]!='\0';i++)
            {
                for(j=0;string[j]!='\0';j++)
                {
                    if(string[j]==cript[i])
                    {
                        // printf("\nstring[%d]=cript[%d] = %c, logo troco por %c\n",j,i,string[j],word[i]);
                        final[j]=word[i];
                    }
                }
            }
            break;

    }
}
int main(void)
{
    char string[201], palavras[100][200],final[201];
    int i=0,j,k,diff_cripto,diff_words,no_words=0;
    while( (string[i++]=getchar())>31);

    string[i-1] = '\0';

    //separando palavras
    
    for(i=0,k=0,j=0; i<201 ; i++ )
    {
        palavras[k][j] = string[i];

        if(palavras[k][j]==32)
        {
            palavras[k][j] = '\0';
            k++;
            j=0;
            continue;
        }
        else if(palavras[k][j]=='\0') break;
        j++;
    }
    k++; //num de palavras

    //vendo n de letras diferentes na mensagem criptografada

    
    for(j=0;string[j]!='\0';j++)
    {
        final[j]= ' ';    
    }
    final[j]='\0';

    for(i=0;i<k;i++)
    {
        substituir(string,palavras[i],checa_palavra(palavras[i]),final);
    }   
 
    printf("\n\n%s",final);

    


    //
    
    return 0;
}