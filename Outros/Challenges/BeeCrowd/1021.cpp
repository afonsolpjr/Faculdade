#include <iostream>
using namespace std;

/*
BeeCrowd 1021
Notas e Moedas
Por Neilor Tonin, URI  Brasil

Timelimit: 1
Leia um valor de ponto flutuante com duas casas decimais. Este valor representa um valor monetário. A seguir, calcule o menor número de notas e moedas possíveis no qual o valor pode ser decomposto. As notas consideradas são de 100, 50, 20, 10, 5, 2. As moedas possíveis são de 1, 0.50, 0.25, 0.10, 0.05 e 0.01. A seguir mostre a relação de notas necessárias.

Entrada
O arquivo de entrada contém um valor de ponto flutuante N (0 ≤ N ≤ 1000000.00).

Saída
Imprima a quantidade mínima de notas e moedas necessárias para trocar o valor inicial, conforme exemplo fornecido.

Obs: Utilize ponto (.) para separar a parte decimal.
*/

void notas(int *nota,double *d)
{
    int cont;
    cont=0;

    while(*d>=100)
    {
        *d-=100;
        cont++;
    }
    nota[0] = cont;

    cont=0;
    while(*d>=50)
    {
        *d-=50;
        cont++;
    }
    nota[1] = cont;

    cont=0;
    while(*d>=20)
    {
        *d-=20;
        cont++;
    }
    nota[2] = cont;

    cont=0;
    while(*d>=10)
    {
        *d-=10;
        cont++;
    }
    nota[3] = cont;

    cont=0;
    while(*d>=5)
    {
        *d-=5;
        cont++;
    }
    nota[4] = cont;

    cont=0;
    while(*d>=2)
    {
        *d-=2;
        cont++;
    }
    nota[5] = cont;


}

void moedas(int *moeda,double *d)
{
    int cont;

    cont=0;

    while(*d>=1)
    {
        *d-=1;
        cont++;
    }
    moeda[0] = cont;
    
    cont=0;
    while(*d>=0.5)
    {
        *d-=0.5;
        cont++;
    }
    moeda[1] = cont;

    cont=0;
    while(*d>=0.25)
    {
        *d-=0.25;
        cont++;
    }
    moeda[2] = cont;

    cont=0;
    while(*d>=0.1)
    {

        *d-=0.1;
        cont++;
    }
    moeda[3] = cont;

    

    cont=0;
    while(*d>=0.05)
    {
        *d-=0.05;
        cont++;
    }
    moeda[4] = cont;

    

    cont=0;
    while(*d>0.001)
    {
        *d-=0.01;
        cont++;
    }
    moeda[5] = cont;
}

int main()
{
    double d;
    
    int nota[6],moeda[6];

    cin >> d;
   

    notas(nota,&d);

    moedas(moeda,&d);

    cout << "NOTAS:\n" <<
         nota[0] << " nota(s) de R$ 100.00\n" <<
         nota[1] << " nota(s) de R$ 50.00\n" <<
         nota[2] << " nota(s) de R$ 20.00\n" <<
         nota[3] << " nota(s) de R$ 10.00\n" <<
         nota[4] << " nota(s) de R$ 5.00\n" <<
         nota[5] << " nota(s) de R$ 2.00\n" <<
         "MOEDAS:\n" <<
         moeda[0] << " moeda(s) de R$ 1.00\n" <<
         moeda[1] << " moeda(s) de R$ 0.50\n" <<
         moeda[2] << " moeda(s) de R$ 0.25\n" <<
         moeda[3] << " moeda(s) de R$ 0.10\n" <<
         moeda[4] << " moeda(s) de R$ 0.05\n" <<
         moeda[5] << " moeda(s) de R$ 0.01\n";


    return 0;
}