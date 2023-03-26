#include <iostream>
using namespace std;

int abs_diff(int a, int b)
{
    int x;

    x = a-b;

    if(x<0)
        return -1*x;
    else
        return x;
}
int main()
{
    int n,m,p_x,p_y,t_x,t_y,i,j,teste,resultado[100000],n_casos;

    n_casos = 0;

    while(cin >> n >> m)
    {

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin >> teste;
                // printf("testando o '%d' \n",teste);
                if(teste==1)
                {
                    t_x = i;
                    t_y = j;
                }
                else if(teste==2)
                {
                    p_x = i;
                    p_y = j;
                }
            }
        }
        // printf("tx = %d  ty =%d    px =%d   py =%d ",t_x,t_y,p_x,p_y);
        resultado[n_casos++] = abs_diff(t_x,p_x) + abs_diff(t_y,p_y);
    }

    for(n=0;n<n_casos;n++)
    {
        printf("%d\n",resultado[n]);
    }


    return 0;
}
