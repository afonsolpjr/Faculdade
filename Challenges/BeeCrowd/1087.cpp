#include <iostream>
using namespace std;

int main()
{
    int x1,y1,x2,y2,resposta[200000]={0},n_resposta=0,i;

    while((cin >> x1) && x1)
    {
        cin >> y1 >> x2 >> y2;

        if(x1==x2 && y1==y2)
        {
            resposta[n_resposta++] = 0;
            continue;
        }
        else if( x1==x2 || y1==y2 || x2-y2==x1-y1 || x2+y2==x1+y1)
        {
            resposta[n_resposta++] = 1;
            continue;
        }
        else 
        {
            resposta[n_resposta++] = 2;
            continue;
        }
    }  

    for(i=0;i<n_resposta;i++)
    {
        cout << resposta[i] << '\n';
    }

    return 0;
}