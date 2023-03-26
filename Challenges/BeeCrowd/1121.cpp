#include <iostream>
using namespace std;

int main()
{
    int n,m,s,caso[200000],n_casos=0,i,j,pi,pj,facing,fig,andou=0;

    char mapa[100][100],instr[50000];


    while(cin >> n >> m >> s)
    {
        if(!n)
            break;
        
        facing=80000;
        pi=pj=-1;
        fig = 0;
        for(i=0;i<n;i++)     //cria mapa e le posicao inicial
        {
            for(j=0;j<m;j++)
            {
                cin >> mapa[i][j];
                switch(mapa[i][j])
                {

                case 'N':
                    pi=i; pj=j;
                    mapa[i][j] = '.';
                    break;
                case 'L':
                    facing++;
                    pi=i; pj=j;
                    break;
                case 'S':
                    facing+=2;
                    pi=i; pj=j;
                    break;
                case 'O':
                    facing+=3;
                    pi=i; pj=j;
                    break;
                }
                if(pi==i && pj==j) //limpa letrinha que indica posicao inicial
                    mapa[i][j] = '.';

            }
        }

        cin >> instr;

        for(i=0;i<s;i++) //executa instrucoes
        {
            andou = 0;

            switch(instr[i])
            {
            case 'E':
                facing--;
                continue;
            case 'D':
                facing++;
                continue;
            }
            // printf("\n\tcaso = %d      instrucao = %d   vou tentar andar! \n\t"
            //         "direcao=%d     pi=%d    pj=%d\n",n_casos,i,facing%4,pi,pj);
            switch(facing%4)
            {
                case 0:
                    if(pi-1<0 || mapa[pi-1][pj]=='#')
                        continue;
                    else
                    {
                        andou = 1;
                        pi--; 
                    }
                    break;
                
                case 1:
                    if(pj+1>=m || mapa[pi][pj+1]=='#')
                        continue;
                    else
                    {
                        andou = 1;
                        pj++; 
                    }
                    break;

                case 2:
                    if(pi+1>=n || mapa[pi+1][pj]=='#')
                        continue;
                    else
                    {
                        andou = 1;
                        pi++; 
                    }
                    break;
                
                case 3:
                    if(pj-1<0 || mapa[pi][pj-1]=='#')
                        continue;
                    else
                    {
                        andou = 1;
                        pj--; 
                    }
                    break;
            }
            if(andou && mapa[pi][pj]=='*')
            {
                fig++;
                mapa[pi][pj] = '.';
            }
        }

        caso[n_casos] = fig;
        n_casos++;
    }

    for(i=0;i<n_casos;i++)
    {
        printf("%d\n",caso[i]);
    }



    return 0;
}