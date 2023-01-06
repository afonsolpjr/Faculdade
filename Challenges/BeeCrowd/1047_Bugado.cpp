#include <iostream>
using namespace std;
/*beecrowd | 1047
Tempo de Jogo com Minutos
Adaptado por Neilor Tonin, URI  Brasil

Timelimit: 1
Leia a hora inicial, minuto inicial, hora final e minuto final de um jogo. A seguir calcule a duração do jogo.

Obs: O jogo tem duração mínima de um (1) minuto e duração máxima de 24 horas.

Entrada
Quatro números inteiros representando a hora de início e fim do jogo.

Saída
Mostre a seguinte mensagem: “O JOGO DUROU XXX HORA(S) E YYY MINUTO(S)” 

.*/

//problema ta bugado fds
int main()
{
    int h_f,m_f,h_i,m_i, min_decorrido,dias;

    cin >> h_i >> m_i >> h_f >> m_f;

    if(m_i==60)
    {
        h_i++;
        m_i=0;
    }
    if(m_f==60)
    {
        m_f=0;
        h_f++;
    }

    h_i%=24;
    if(!(h_f%=24)) m_f+=1440;
   

    m_i+=h_i*60;
    m_f+=h_f*60;

    min_decorrido = 0;
    if(m_i<=m_f) min_decorrido = m_f - m_i;
    else if(m_i>m_f)
    {
        while(m_i++%1440 != m_f) min_decorrido++; 
    }
    
    if(!min_decorrido) min_decorrido = 24*60;
    


    cout << "O JOGO DUROU " << min_decorrido/60 << " HORAS(S) E "
        << min_decorrido%60 << " MINUTO(S)\n";
    return 0;
}