#include <iostream>
#include <stdlib.h>
using namespace std;

int* cria_vetor_random(int n)
{
    srand(time(0));
    int i,*v,*ja_foi;

    v = (int*) calloc(n,sizeof(int));
    ja_foi = (int*) calloc(n,sizeof(int));
    if (v==NULL)
    {
        cout << "\nDeu merda! Sem memoria\n";
        return NULL;
    }

    for(i=0;i<n;i++)
    {
        while(true)
        {
            v[i] = ( rand()% n );
            if(ja_foi[v[i]]==0)
            {
                ja_foi[v[i]]=1;
                break;
            }
        }
    }
    cout << "\n";
    free(ja_foi);
    return v;

}
void printa_vetor(int *v,int i,int n)
{
    for(;i<n;i++)
    {
        cout << " ["<< v[i] << "] ";
    }
    cout << "\n";
}
void selection_sort(int *v,int n)
{
    int i,menor,j,temp;

    for(i=0;i<100;i++)
    {
        menor=i;
        for(j=i;j<100;j++)
        {
            if(v[menor]>v[j])
                menor=j;
        }
        temp=v[i];
        v[i]=v[menor];
        v[menor]=temp;
    }
    cout << "\nordernados:\n";
    for(i=0;i<100;i++)
        cout << v[i] << " ";

}
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

void quick_sort(int *v,int inicio, int fim)
{
    int pos_pivot;
    if(inicio<fim)
    {
        pos_pivot =  particiona(v,inicio,fim); //tenho posicao certa do pivot
        quick_sort(v,inicio,pos_pivot);
        quick_sort(v,pos_pivot+1,fim);
    }
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
    return pos_pivot;

}
int main()
{   
    int *v,n,i;
    cout << "Selecione o tamanho do vetor. Ele será randomizado com numeros de 1 a n." 
    << "\nTamanho: ";
    cin >> n;

    v = cria_vetor_random(n);

    // quick_sort(v,0,n);
    // cout <<"\n\npronto\n\n";

    printa_vetor(v,0,n);

    cout << "\nselecione a posicao que quer do vetor: ";
    cin >> i;

    printf(" \n O item na posicao %d é [%d]",i,quick_select(v,i,0,n));
}