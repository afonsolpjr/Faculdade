#include <iostream>
using namespace std;

int main()
{
    int n,m,in,i,j,passo,regioes[100],k,r,controle,resultado[100];

    in=0;
    while((cin >> n) && n!=0)
    {
        in++;
        for(m=1;;m++) // testa m 
        {  
            for(j=0;j<100;j++) regioes[j] = 0;
            j=0;
            k=0;
            regioes[0] = 1;
            while(!regioes[n-1]) //enquanto n preencher ultima casa
            {
                passo=0;
                while(passo!=m)
                {
                    controle=0;
                    j = (j+1)%n;
                    for(r=0;r<n;r++)
                    {
                        if(regioes[r]==j+1)
                        {
                            controle=1;
                        }
                    }
                    if(!controle) passo++;

                }
                if(j+1==13 && k+1!=n-1) break;
                else regioes[++k]=j+1;
            }    
            if(k==n-1)
            {
                resultado[in-1] = m;
                break;
            }
            
        }
    }

    for(i=0;i<in;i++)
    {
        cout << resultado[i] << "\n";
    }
        

      
    return 0;
}