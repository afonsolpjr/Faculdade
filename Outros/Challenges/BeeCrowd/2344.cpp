#include <iostream>
 
using namespace std;
 
int main() 
{
    int a;

    cin >> a;

    if(!a) cout << 'E';
    else if(a>=1 && a<=35) cout << 'D';
    else if(a>35 && a<61) cout << 'C';
    else if(a>60 && a<86) cout << 'B';
    else if(a>85 && a<101) cout << 'A';
    
 
    return 0;
}