#include <iostream>
 
using namespace std;
/*beecrowd | 2986
Nem Tudo é Greve Versão Hard


Falta lidar com big int */

int recorrencialinear3grau(int n);
int main()
{
    int n;

    cin >> n;

    cout << recorrencialinear3grau(n);
    return 0;
}


int recorrencialinear3grau(int n)
{
    int result,n_1,n_2,n_3,i;

    n_1 = 4, n_2 = 2, n_3=1;
    result = 0;
    switch(n)
    {
        case 1: return n_3;
        case 2: return n_2;
        case 3: return n_3;

        default:
            for(i=0;i<n-3;i++)
            {
                result = n_1 + n_2 + n_3;
                n_3 = n_2;
                n_2 = n_1;
                n_1 = result;
            }
            return result;
    }
}