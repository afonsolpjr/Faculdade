#include <iostream>
using namespace std;

int main()
{
    int i,b,n,reservas[20],total,tem_negativo=0,d,c,v,caso[200000],n_casos=0;


    while(cin >> b >> n)
    {
        if(!b)
            break;
        
        for(i=0,total=0;i<b;i++)
        {
            cin >> reservas[i];
            total+=reservas[i];
        }

        for(i=0;i<n;i++)
        {
            cin >> d >> c >> v;
            d--; c--;

            reservas[d]-=v;
            reservas[c]+=v;
        }
        tem_negativo=0;
        for(i=0;i<b;i++)
            if(reservas[i]<0)
            {
                tem_negativo=1;
                caso[n_casos]=0;
            }
        
        if(!tem_negativo)
            caso[n_casos]=1;
        
        

        n_casos++;

    }

    for(i=0;i<n_casos;i++)
    {
        switch(caso[i])
        {
        case 1:
            printf("S\n");
            break;
        case 0:
            printf("N\n");
            break;
        }
    }


    return 0;
}