#include <iostream>
 
using namespace std;
 
int main()
{
    int valores[200000],i,j,n50,n10,n5,n1;

    i=0;
    while((cin>>valores[i]) && valores[i]!=0)
        i++;
    
    for(j=0;j<i;j++)
    {
        n50=n10=n5=n1=0;

        while(valores[j]>=50)
        {
            valores[j]-=50;
            n50++;
        }
        while(valores[j]>=10)
        {
            valores[j]-=10;
            n10++;
        }
        while(valores[j]>=5)
        {
            valores[j]-=5;
            n5++;
        }
        while(valores[j]>=1)
        {
            valores[j]--;
            n1++;
        }


        cout << "Teste " << j+1 << '\n'
        << n50 << " " << n10 << " " << n5 << " " << n1 << "\n\n";
    }
    return 0;
}