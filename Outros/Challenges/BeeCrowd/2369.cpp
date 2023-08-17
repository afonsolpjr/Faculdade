#include <iostream>
 
using namespace std;
 
int main()
{
    int m3,preco=0;

    cin >> m3;


    if(m3>100)
    {
        preco += (m3 - 100) * 5;
        m3=100;
    }

    if(m3>30)
    {
        preco += (m3-30) * 2;
        m3=30;
    }

    if(m3>10)
    {
        preco += (m3-10);
    }

    preco+=7;

    cout << preco <<'\n';



    return 0;
}