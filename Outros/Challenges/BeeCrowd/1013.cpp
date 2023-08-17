#include <iostream>
 
using namespace std;
 
int main() {
 
    int a,b,c,maior,i=0;
    
    cin >> a >> b>> c;
    while((i++<2))
    {
        if( (a-b)>=0 )
        {
            maior = ( a+b+(a-b) ) / 2;
        }
        else
        {
            maior = ( a+b+ ((a-b)*-1) ) / 2;
        }
        a = maior;
        b = c;
    }

    cout << maior << " eh o maior\n";
    return 0;
}