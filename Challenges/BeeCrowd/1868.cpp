#include <iostream>
#include <iomanip>
using namespace std;

typedef struct _ESPIRAL
{
    int **v, n;


}ESPIRAL;

int** povoaespiral(int n)
{
    int i,lin,col,fim,**espiral;

    espiral = (int**) calloc(n,sizeof(int*));

    for(i=0;i<n;i++) espiral[i] = (int*) calloc(n,sizeof(int));
    
    i=1;
    fim=0;
    lin = n/2;
    col = n/2;
    espiral[lin][col] = i;

    while(!fim)
    {
        if(n==1) fim =1;
        while(!fim) //vai pdireita ate 0 na vertical
        {
            col++;
            espiral[lin][col] = ++i;
            // printespiral(espiral,n);
            if(  lin &&
                 !(espiral[lin-1][col]) && 
                 !(espiral[lin+1][col])  ) 
                 break;
            else if(col==n-1) fim=1;
            //precisa subir
        }

        while(!fim) //sobe ate 0 na horizontal
        {
            lin--;
            espiral[lin][col] = ++i;
            if( !(espiral[lin][col-1]) ) break;   
        }

        while(!fim) // vai pra esquerda ate ver zero em baixo
        {
            col--;
            espiral[lin][col] = ++i;
            if(!espiral[lin+1][col]) break;
        }

        while (!fim) //desce ate 0 na direita
        {
            lin++;
            espiral[lin][col] = ++i;
            if(!espiral[lin][col+1]) break;
        }
    }

  
    return espiral;
}
void printa_espiral(int** espiral,int n);
int main()
{
    ESPIRAL *espirais;
    
    int i=0,n;

    espirais = (ESPIRAL*) calloc(1,sizeof(ESPIRAL));

    while((cin >> n) && n!=0)
    {
        i++;

        espirais = (ESPIRAL*) realloc(espirais,i*sizeof(ESPIRAL));

        espirais[i-1].n = n;
        espirais[i-1].v = povoaespiral(n);

    }
    n=i;
    for(i=0;i<n;i++)
    {
        printa_espiral(espirais[i].v,espirais[i].n);
    }

    return 0;
}

void printa_espiral(int** espiral, int n) //falta td
{
    int i,j,k,xis,control;
    xis=1;
    for(k=0;k<n*n;k++)
    {
        control = 0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(espiral[i][j] == xis && !control)
                {
                    cout << "X";
                    xis++;
                    control++;
                }
                else cout << "O";

            }
            cout << "\n";
        }
        cout << "@\n";
    }



}

