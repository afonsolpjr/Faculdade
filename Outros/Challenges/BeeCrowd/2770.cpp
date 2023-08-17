#include <iostream>
using namespace std;

int main()
{
    int resultado[1000000]={0}, m, x ,y, a , b,i,j,h;
;
    i=0;
    while(cin >> x >> y >> m)
    {
        if(x<y)
        {
            h=y;
            y=x;
            x=h;
        }         // quero ter ctz q o x é o maior

         for(j=0;j<m;j++)
        {
           
            cin >> a >> b;
            if(a<b)      //ter ctz q o a é o maior
            {
                h=b;
                b=a;
                a=h;
            }
            // cout << a << b;
            if( (a>x) || (b>y) ) 
            {
                resultado[i++]=0;
            }
            else resultado[i++] = 1;
        }

    }

    for(j=0;j<i;j++)
    {
        if(resultado[j]) cout << "Sim\n";
        else cout << "Nao\n";
    }


    return 0;
}