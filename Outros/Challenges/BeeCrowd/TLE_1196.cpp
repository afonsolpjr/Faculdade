#include <iostream>
using namespace std;

char substitui(char letra)
{
    switch(letra) //MANO Eu fiz um código pra gerar essas linhas de codigo, n deu trabalho.. Mas caramba, mesmo assim ainda ta dando TLE
    {
    case '1':
            return '`';
    case '2':
            return '1';
    case '3':
            return '2';
    case '4':
            return '3';
    case '5':
            return '4';
    case '6':
            return '5';
    case '7':
            return '6';
    case '8':
            return '7';
    case '9':
            return '8';
    case '0':
            return '9';
    case '-':
            return '0';
    case '=':
            return '-';
    case 'W':
            return 'Q';
    case 'E':
            return 'W';
    case 'R':
            return 'E';
    case 'T':
            return 'R';
    case 'Y':
            return 'T';
    case 'U':
            return 'Y';
    case 'I':
            return 'U';
    case 'O':
            return 'I';
    case 'P':
            return 'O';
    case '[':
            return 'P';
    case ']':
            return '[';
    case '\\':
            return ']';
    case 'S':
            return 'A';
    case 'D':
            return 'S';
    case 'F':
            return 'D';
    case 'G':
            return 'F';
    case 'H':
            return 'G';
    case 'J':
            return 'H';
    case 'K':
            return 'J';
    case 'L':
            return 'K';
    case ';':
            return 'L';
    case '\'':
            return ';';
    case 'X':
            return 'Z';
    case 'C':
            return 'X';
    case 'V':
            return 'C';
    case 'B':
            return 'V';
    case 'N':
            return 'B';
    case 'M':
            return 'N';
    case ',':
            return 'M';
    case '.':
            return ',';
    case '/':
            return '.';
    
    default:
        return letra;
    }
    return 1;
}
int main()
{
    char lido[10000], casos[10000][100];

    int n_casos, j,i;

  
    n_casos=0;
    while(1)
    {
        i=0;
        while( (lido[i]=getchar())!= '\n' && lido[i]!=EOF   )
        {
            casos[n_casos][i]= substitui(lido[i]);
            i++;
        }
        if(lido[i]==EOF)
            break;

        lido[i]='\0';
        n_casos++;
    }

    for(i=0;i<n_casos;i++)
        printf("%s\n",casos[i]);
}
