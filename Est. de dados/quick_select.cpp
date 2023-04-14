#include <iostream>
#include <cstdlib>
using namespace std;

int particiona(int *v, int inicio, int fim)
{
    int lo=inicio,hi=fim-1,temp,pivot;


    pivot = v[inicio]; //posicao do pivot = inicio
    v[inicio]=v[hi];
    v[hi]=pivot;
    hi--;

    while(hi>=lo)
    {
        while(v[lo]<pivot && lo<=hi)
            lo++;
        
        while(v[hi]>pivot && hi>=lo)
            hi--;
        
        if(hi>lo)
        {
            temp=v[hi];
            v[hi]=v[lo];
            v[lo]=temp;
            lo++;
            hi--;
        }
    }
    temp=v[lo];
    v[lo]=pivot;
    v[fim-1]=temp;
    
    return lo; //retorna posicao do pivot

}

int quick_select(int *v,int posicao,int inicio,int fim)
{
    int pos_pivot=-1;

    while(pos_pivot!=posicao)
    {
        pos_pivot = particiona(v,inicio,fim);

        if(pos_pivot > posicao) //pivot é limite superior
            fim = pos_pivot;
        else if(pos_pivot < posicao) //pivot é limite inferior
            inicio = pos_pivot+1;
    }
    return v[pos_pivot];

}
int st_toi(char *str)
{
    int num,i=0; //   i = nº de algarismos
    num = 0;
    while(str[i]>= '0' && str[i]<='9')
    {
        num = (num * 10 ) + (str[i] - '0');
        i++;
    }
    return num;
}
int main(int argc,char *argv[])
{
    int i,*v,posicao, tam,n_lido;

    tam = posicao = st_toi(argv[1]);

    v = (int*)calloc(posicao,sizeof(int));
    
    if(v==NULL)
    {
        cout << "\nProblema de memória.";
        return 1;
    }
    i=-1;
    while(cin >> n_lido) //le os numeros
    {
        i++;
        if(i==tam)
        {
            tam*=2;
            v = (int*)realloc(v,tam*sizeof(int));
        }
        v[i]=n_lido;
    }

    cout << quick_select(v,posicao-1,0,i+1);

}




/* bash para testar
n=0
for((i=0;i<100;i++))
do
    n=$i%3
    echo "{$n} "
done
    
    */