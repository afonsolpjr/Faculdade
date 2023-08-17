#include <stdio.h>
#include <stdlib.h>


int** criaespiral(int n);
void povoa_espiral(int** espiral, int n);


void printespiral(int** espiral, int n)
{
    int i,j;
      for(i=0;i<n;i++)          //imprime a espiral
    {
        for(j=0;j<n;j++)
        {
            printf("  %d  ",espiral[i][j]);
        }
        puts("\n");
    }
    puts("\n\n");
}

int soma_diagonais(int** espiral, int n);

int main(void)
{
    int n,i,j,**espiral;

    puts("Selecione o tamanho da espiral,impar pfv: ");
    scanf("%d",&n);

    espiral = criaespiral(n);
     

    povoa_espiral(espiral,n);
  

    for(i=0;i<n && n<10 ;i++)          //imprime a espiral
    {
        for(j=0;j<n;j++)
        {
            printf("  %d  ",espiral[i][j]);
        }
        puts("\n\n");
    }

    printf("\n\t A soma das diagonais eh de : %d",soma_diagonais(espiral,n));

    return 0;
}


int** criaespiral(int n)
{
    int **espiral,i;

    espiral = (int**) calloc(n,sizeof(int*));

    for(i=0;i<n;i++)
    {
        espiral[i] = (int*) calloc(n,sizeof(int));
    }

    return espiral;
}


void povoa_espiral(int** espiral, int n)
{
    int i,col,lin,fim=0;

    //determinando coluna e linha inicial
    col = n/2;
    lin = n/2;
    i=1;
    espiral[lin][col] = i;

    

    while(!fim)
    {
        
        //vai pra direita ate zeros na vertical
        while(!fim)
        {
            col++;
            espiral[lin][col] = ++i;
            // printespiral(espiral,n);
            if(  lin &&
                 !(espiral[lin-1][col]) && 
                 !(espiral[lin+1][col])  ) 
                 break;
            else if(col==n-1) fim=1;
            //precisa descer
        }

        // pbaixo 
        while(!fim)
        {
            lin++;
            espiral[lin][col] = ++i;
            // printespiral(espiral,n);
            if( col!=n-1 &&
                !espiral[lin][col-1] &&
                !espiral[lin][col+1] ) 
                break;
            else if(lin==n-1) break;
        }

        //p esquerda

        while(!fim)
        {
            col--;
            espiral[lin][col] = ++i;
            // printespiral(espiral,n);    
            if( lin!=n-1 &&
                !espiral[lin-1][col] &&
                !espiral[lin+1][col] ) 
                break;
            else if(!col) break;
        }
        //p cima
        while(!fim)
        {
            lin--;
            espiral[lin][col] = ++i;
            // printespiral(espiral,n);
            if( col &&
                !espiral[lin][col-1] &&
                !espiral[lin][col+1]) break;
            else if(!lin) break;
        }
    }
    // puts("final:");
    // printespiral(espiral,n);

}


int soma_diagonais(int** espiral, int n)
{
    int diag1=0, diag2 = 0,i,j;


    for(i=0,j=0;i<n;j++,i++)
    {
        diag1 += espiral[i][j];
    }

    for(i=0,j=n-1;i<n;i++,j--)
    {
        diag2 += espiral[i][j];
    }

    return diag1+diag2-1;



}