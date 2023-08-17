#include <iostream>
using namespace std;


int main()
{
    int caso[100000],n_tiros,j, altura[50],resultado,i=0,n_casos;

    char acao[50]={0};

    cin >> n_casos;

    while(i<n_casos)
    {
        cin >> n_tiros;

        for(j=0; j<n_tiros;j++)
            cin >> altura[j];

        for(j=0;j<50;j++)
            acao[j] = 0;
        
        cin >> acao;
        resultado = 0;
        for(j=0;j<n_tiros;j++)
        {
            if( (altura[j]>2 && acao[j]=='J') || (altura[j]<3 && acao[j]=='S') )
                resultado++;
        }   
        caso[i] = resultado;
        i++;
    }
    for(i=0;i<n_casos;i++)
    {
        printf("%d\n",caso[i]);
    }


    return 0;
}