#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    double m[3],a,b,c,s,result[200000]={0};
    int i=0,j,n_case=0;

    while(cin >> m[0])
    {
        cin >> m[1] >> m[2];

        for(i=0;i<3;i++) // checar se existe triangulo com lados m1,m2,m3    (ordernar de tal forma q m1>=m2>=m3)
        {
            for(j=i;j<3-i-1;i++)
            {
                if(m[i]>m[i+1])
                {
                    s = m[i+1];
                    m[i+1] = m[i];
                    m[i] = s;
                }
            }
        }

        // puts("\n\tOrdenados:");
        // for(i=0;i<3;i++)
        // {
        //     printf("  %.3f  ",m[i] );
        // }

        if((m[0]+m[1])<=m[2])
        {
            result[n_case]= -1;
            n_case++;
            continue;
        }

        a = 2*m[0]/3;
        b = 2*m[1]/3;
        c = 2*m[2]/3;
        s = (a + b + c)/2;
        // printf("\n\tsemiperimetro   = %f",s);
        s = s*(s-a)*(s-b)*(s-c);
        // printf("\n\t arg da raiz   = %f",s);

        s = sqrt(s); 
        s*=3;
        result[n_case]=s;


        n_case++;
    }

    for(i=0;i<n_case;i++)
    {
        printf("%.3f\n",result[i]);
    }
    return 0;
}