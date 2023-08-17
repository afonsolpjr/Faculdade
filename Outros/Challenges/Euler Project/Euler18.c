/*

By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom of the triangle below:

75
95 64
17 47 82
18 35 87 10
20 04 82 47 65
19 01 23 75 03 34
88 02 77 73 07 63 67
99 65 04 28 06 16 70 92
41 41 26 56 83 40 80 70 33
41 48 72 33 47 32 37 16 94 29
53 71 44 65 25 43 91 52 97 51 14
70 11 33 28 77 73 17 78 39 68 17 57
91 71 52 38 17 14 91 43 58 50 27 29 48
63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
*/

#include <stdio.h>
#include <stdlib.h>

int** le_piramide(void);
int main(void)
{
    int **piramide,i,j,linha,coluna,current_total,max,exp;

    max=0, current_total=0;
    piramide = le_piramide();

    for (i=0;i<(1<<14);i++)             // sao 1<<14 (ou 2^14) caminhos
    {
        linha=0, coluna=0;
       // puts("\nSomando: ");
        for(j=0;j<15;j++)                // cada caminho soma 15 numeros
        {
            //printf("%d + ",piramide[linha][coluna]);
            current_total+=piramide[linha][coluna];
            linha++;
            if(i & (1<<j))   //   se o j-ésimo bit do numero do caminho atual for 1, ele decide ir pra casa mais a direita.
            {
                coluna+=1;
            }
        }

        current_total>max? (max=current_total) : 0;

        current_total=0;
    }
    printf("\nO maximo total foi %d\n",max);
    return 0;
}
int** le_piramide(void)
{
    FILE *fp;
    int **piramide,n_linhas,i,j;

    char c;
    n_linhas=0;

    if((fp = fopen("Euler18.txt","r"))==NULL)
    {
        puts("erro abrindo arquivo");
    }


    while(c=fgetc(fp)) //saber qnts linhas
    {
        if(c=='\n') n_linhas++;
        if(c==EOF) break;
    }
    n_linhas++;
    printf("\nn de linhas: %d\n",n_linhas);

    //criando piramide

    //criando n de linhas
    piramide = (int**) calloc(n_linhas,sizeof(int*));
    
    //criando n de colunas
    for(i=0;i<n_linhas;i++)
    {
        
        piramide[i] = (int*) calloc(i+1,sizeof(int));
    }
    rewind(fp);

    for(i=0;i<n_linhas;i++)
    {
        for(j=0;j<i+1;j++)
        {
            fscanf(fp,"%d",&piramide[i][j]);
            printf("%d ",piramide[i][j]);    
        }
        puts("\n");
    }
    puts("\nFim da piramide!\n");
    fclose(fp);
    return piramide;
}