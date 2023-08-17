#include <stdio.h>
#include <stdlib.h>

typedef struct _CASO
{
    int c,n;
    char cifra[2][24], frase[100][1024];
}CASO;
int substchar(char c1, char c2, char frase)
{
    if(frase<123 && frase>96 ) // se letra minuscula
    {
        if((frase-32)==c1)
        {
            
            if(c2>64 && c2<91) return c2+32;
            else if(c2>96 && c2<123) return c2;
            else return c2;
        }
        else if((frase-32)==c2)
        {   
            if(c1>64 && c1<91) return c1+32;
            else if(c1>96 && c1<123) return c1;
            else return c1;
        }
    }
    //checar correspondencia direta

    if(frase==c1)
    {
        if( ((c1<65 && c2>31) || (c1>90 && c1<97) || (c1>122 && c1<127) ) && c2>64 && c2<91) return c2+32;
        else return c2;
    }
    else if(frase==c2)
    {
        if( ((c2<65 && c2>32) || (c2>90 && c2<97) || (c2>122 && c2<127)) && c1>64 && c1<91) return c1+32;
        else return c1;
    }     
    // printf("\nChecando cifras [%c] e [%c] com [%c]\n",c1,c2,frase);
   

    
    return frase;    
}
int main()
{
    CASO *casos;
    char teste;
    int n_caso = 0, i, j, k;
    
    casos = (CASO*) calloc(1,sizeof(CASO));

    while(!feof(stdin))
    {
        n_caso++;

        casos = realloc(casos,n_caso*sizeof(CASO));

        scanf("%d %d\n",&casos[n_caso-1].c,&casos[n_caso-1].n);

        for(i=0;i<2;i++)
        {
            for(j=0;j<casos[n_caso-1].c + 1;j++)
            {
                casos[n_caso-1].cifra[i][j] = getchar();
                if(casos[n_caso-1].cifra[i][j]=='\n')
                {
                    casos[n_caso-1].cifra[i][j] = '\0';
                    break;
                }
            }
        }
        // getchar();

        // printf("\nDEBUG:\n"
        // "n_caso-1 = %d\n"
        // "cifra[0] = %s\n"
        // "cifra[1]= %s\n"
        // "c=%d     n=%d\n",n_caso-1,casos[n_caso-1].cifra[0],casos[n_caso-1].cifra[1],casos[n_caso-1].c,casos[n_caso-1].n);


        for(i=0;i<casos[n_caso-1].n;i++) //lendo frases
        {
            for(j=0;j<1024;j++)
            {
                casos[n_caso-1].frase[i][j] = getchar();

                teste = casos[n_caso-1].frase[i][j];
                if(casos[n_caso-1].frase[i][j]<32)
                {
                    casos[n_caso-1].frase[i][j] = '\0';
                    break;
                }
                else
                {
                    for(k=0;k<casos[n_caso-1].c;k++)
                    {   
                        // printf("\nQuase cifras [%c] e [%c] com [%c]\n",cifra[0][k],cifra[1][k],frase[n_caso-1][i][j]);

                         if(teste !=  
                            (casos[n_caso-1].frase[i][j] 
                            = 
                            substchar(casos[n_caso-1].cifra[0][k],casos[n_caso-1].cifra[1][k],casos[n_caso-1].frase[i][j])) )
                        continue;
                    }
                }
            }
            // printf("\n%d frase lida: %s",i,casos[n_caso-1].frase[i]);

        }
    }

    for(i=0;i<n_caso-1;i++)
    {
        for(j=0;j<casos[i].n;j++)
        {
            printf("%s\n",casos[i].frase[j]);
        }
       printf("\n"); 
    }
    
   

    return 0;
}