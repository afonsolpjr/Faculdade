#include <iostream>
using namespace std;


long long int reg_kcomplete(long long int n)    //regioes de um grafo n completo
{
    long long int i,r,virtual_n,j,new_regions;

    if(n<3) return 0;
    r=2;
    virtual_n = 4;
    for(i=0;i<n-3;i++,virtual_n++)
    {
        // cout << "\n\nDebug\n" << "r anterior = " << r
        //      << "\n virtual_n = " << virtual_n << "\n";

        for(new_regions = 0,j=1;j<=virtual_n-3;j++)
        {
            new_regions += j * (virtual_n -2 - j) + 1;   //numero de interseccoes da diagonal atual + 1;
        }

        r = r + new_regions + 1;
    }



    return r;
}
long long int reg_inside_circle(long long int n)
{
    switch(n)
    {
        case 1: return 1;

        case 2: return 2;

        default: return reg_kcomplete(n) - 1 + n;
    }
}
 int main()
{


    long long int a;

    cin >> a;

    cout << reg_inside_circle(a) <<"\n";
    return 0;

}