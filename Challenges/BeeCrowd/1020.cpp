#include <iostream>
using namespace std;
 
int main()
{
 
    int q,anos,meses;
    
    cin >> q;
    
    anos = q/365;
    q = q%365;
    
    meses = q/30;
    q = q%30;
    
    
    cout << anos << " ano(s)\n"
    << meses << " mes(es)\n"
    << q << " dia(s)\n";
    
    return 0;
}