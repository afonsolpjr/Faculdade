#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int tam[1024],i, n, j, k, help,width;

    n=0;
    while( (cin >> tam[n]) && tam[n]!=0 ) n++;

    for (i = 0; i < n; i++) //imprimir n matrizes
    {

        // cout << "width = " << width << '\n';
        width=1;
            help = (1<<(2*(tam[i]-1)));
            
            while( help != help%10)
            {
                help/=10;
                width++;
            }
            // cout << "width =" << width << endl;

        for(j=0;j<tam[i];j++)   //imprimir matriz tam[i] x tam[i];
        {
            

            for(k=0;k<tam[i];k++)
            {
                cout << std::setw(width) <<
                     std::right << (1<<j+k) ;
                if(k!=tam[i]-1) cout << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    

    
    
    
    return 0;
}