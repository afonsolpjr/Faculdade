/*AFONSO LUSTOSA PIRES JUNIOR - DRE: 122079084

Olá, os programas seguem na mesma organização que fiz na lista 7.


-Todos os Exercicios estão como funções.
-Há um menu para escolha do exerćicio.
-Comentários contendo saídas dos exercicios estão abaixo das declarações de seus protótipos.
-Funçoes que determinados exercicios usam estão abaixo do comentário nos protótipos.

-Estruturas usadas estão declaradas antes dos protótipos! 


Grato!
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct _PONTO
  {
    float x,y;
  } PONTO;

typedef struct _CIRCUNFERENCIA
  {
    float raio;
    PONTO centro;
  } CIRCUNFERENCIA;

typedef struct _TEMPO
  {
    int hora,minuto,segundo;
  } TEMPO;

typedef struct _JOGADOR{
  int pontos;
  char nome[42];
} JOGADOR;

typedef struct _FRACAO{
  int numerador,denominador;
} FRACAO;

int valida_int(void)
{
	int valido,lixo,valor;
	valido=scanf("%d",&valor);
        while(valido==0)
        {
            while((lixo=getchar()) != EOF && lixo!= '\n');
            puts("\nInsira um valor válido: ");
            valido=scanf("%d",&valor);
        }
	return valor;
}


void exercicio_1(void);
/*                  Exercicio 1


Entre com as coordenadas do ponto p

1 3
DADOS LIDOS:
X = 1.000000 , Y = 3.000000
*/
float valida_float(void)
{
	int valido,lixo;
	float valor;
	valido=scanf("%f",&valor);
        while(valido==0)
        {
            while((lixo=getchar()) != EOF && lixo!= '\n');
            puts("\nInsira um valor válido: ");
            valido=scanf("%f",&valor);
        }
	return valor;
}

void exercicio_2(void);
/*                 Exercicio 2



Entre com o raio da circunferencia c1:
1

 Entre com as coordenadas do centro do c├¡rculo c1:

0
0


DADOS LIDOS:
Circulo c1: raio = 1.000000, x = 0.000000, y = 0.000000 */

void exercicio_3(void);
/*                   Exercicio 3


COORDENADAS DO PONTO 1:
Insira X:
0

 Insira Y:
0


COORDENADAS DO PONTO 2:
Insira X:
3

 Insira Y:
5

A distancia do ponto p1 ao ponto p2 equivale a 5.8309  */
double raiz(float n) /*Retorna raiz de "float n" com 4 digitos decimais de precisão*/
{
  double teste=0;

  if(n>=1)
  {
    while((teste*teste)<n)
    {
      teste++;
    }
    teste--;
  }
  while((teste*teste)<n)
  {
    teste+=0.00001;
  }

  return teste-0.00001;
}
/*Uso de double para maior precisão, já que são incrementos de 0.00001  .
Solução que pensei já que a priori não podemos usar math.h*/

void exercicio_4(void);
/*                  Exercicio 4





[POSICAO RELATIVA ENTRE PONTO E CIRCUNFERENCIA]

Insira o raio da circunferencia:
1

 [COORDENADAS (x,y) DO CENTRO DA CIRCUFERENCIA]
Insira x:
0

Insira y:
0
[COORDENADAS DO PONTO]
Insira x:
0.7

Insira y:
0.7
O ponto esta contido na circunferencia.
*/

void exercicio_5(void);
/*                   Exercicio 5


TEMPO 1:

Insira as horas:
0
Insira os minutos:
43
Insira os segundos:
33

TEMPO 2:

Insira as horas:
0
Insira os minutos:
42
Insira os segundos:
55

O maior tempo e o Tempo 1:
0:43:33
*/
void le_tempo(TEMPO* tempo)
{
  puts("Insira as horas:"); 
  tempo->hora=valida_int();
  puts("Insira os minutos:"); 
  tempo->minuto=valida_int();
  puts("Insira os segundos:"); 
  tempo->segundo=valida_int();
}

void exercicio_6(void);
/*                   Exercicio 6


TEMPO 1:

Insira as horas:
1
Insira os minutos:
22
Insira os segundos:
35

TEMPO 2:

Insira as horas:
1
Insira os minutos:
20
Insira os segundos:
30

Soma dos tempos e igual a:
 2 : 43 : 05
 */
void exercicio_7(void);
/*                 Exercicio 7


TEMPO 1:

Insira as horas:
1
Insira os minutos:
22
Insira os segundos:
31

TEMPO 2:

Insira as horas:
1
Insira os minutos:
22
Insira os segundos:
43

O maior tempo e o Tempo 2
*/
int comparaTempo(TEMPO *t1, TEMPO *t2)
{
  float minutos_t1,minutos_t2;
  
  minutos_t1=(t1->hora*60)+t1->minuto+(t1->segundo/60.0);
  minutos_t2=(t2->hora*60)+t2->minuto+(t2->segundo/60.0);

  if(minutos_t1>minutos_t2) return 1;
  else if(minutos_t1<minutos_t2) return -1;
  else return 0;
}

void exercicio_8(void);
/*                   Exercicio 8



TEMPO 1
Insira as horas:
1
Insira os minutos:
01
Insira os segundos:
02

TEMPO 2
Insira as horas:
1
Insira os minutos:
1
Insira os segundos:
3

TEMPO 3
Insira as horas:
1
Insira os minutos:
2
Insira os segundos:
0

TEMPO 4
Insira as horas:
0
Insira os minutos:
30
Insira os segundos:
23

TEMPO 5
Insira as horas:
0
Insira os minutos:
20
Insira os segundos:
22

Tempos em ordem crescente

0:20:22
0:30:23
1:01:02
1:01:03
1:02:00
*/

void exercicio_9(void);
/*                   Exercicio 9



Insira o raio da circunferencia 1:
1

 [COORDENADAS (x,y) DO CENTRO DA CIRCUFERENCIA 1]
Insira x:
0

Insira y:
0

[Circunferencia 2]

Insira o raio da circunferencia:
1

 [COORDENADAS (x,y) DO CENTRO DA CIRCUFERENCIA 2]
Insira x:
2

Insira y:
0
As duas circunferencias sao tangentes externamente*/

void exercicio_10(void);
/*                   Exercicio 10


[INICIALIZANDO JOGADOR 1]
Insira o nome:
afonso
Insira os pontos: 
1917

[INICIALIZANDO JOGADOR 2]
Insira o nome:
pedro
Insira os pontos: 
1

[INICIALIZANDO JOGADOR 3]
Insira o nome:
mateus
Insira os pontos: 
10

[INICIALIZANDO JOGADOR 4]
Insira o nome:
lucas
Insira os pontos: 
5

[INICIALIZANDO JOGADOR 5]
Insira o nome:
gabriel
Insira os pontos: 
7

        JOGADORES:

afonso
1917 pontos

pedro
1 pontos

mateus
10 pontos

lucas
5 pontos

gabriel
7 pontos   */
void le_jogador(JOGADOR* jogador)
{
  puts("Insira o nome: ");
  scanf("%s", jogador->nome);
  puts("Insira os pontos: ");
  jogador->pontos= valida_int();
}

void exercicio_11(void);
/*                   Exercicio 11



[INICIALIZANDO JOGADOR 1]
Insira o nome:
afonso
Insira os pontos: 
999

[INICIALIZANDO JOGADOR 2]
Insira o nome:
lucas 
Insira os pontos: 
10

[INICIALIZANDO JOGADOR 3]
Insira o nome:
olga
Insira os pontos: 
100

[INICIALIZANDO JOGADOR 4]
Insira o nome:
pedro
Insira os pontos: 
0

[INICIALIZANDO JOGADOR 5]
Insira o nome:
mateus
Insira os pontos: 
30

        RANKING:

afonso
999 pontos

olga
100 pontos

mateus
30 pontos

lucas
10 pontos

pedro
0 pontos */
void ordena_jogadores(JOGADOR* jogadores, int tam)
{ 
  int i,j;
  JOGADOR auxiliar;
   for(i=0;i<tam-1;i++) /*ordenando jogadores*/
  {
    for(j=0;j<tam-1-i;j++)
    {
      if(jogadores[j].pontos > jogadores[j+1].pontos)
      {
        auxiliar = jogadores[j+1];
        jogadores[j+1] = jogadores[j];
        jogadores[j]= auxiliar;
      }
    }
  }
}

void exercicio_12(void);
/*                   Exercicio 12



[INICIALIZANDO JOGADOR 1]
Insira o nome:
pedro 
Insira os pontos: 
10

[INICIALIZANDO JOGADOR 2]
Insira o nome:
afonso
Insira os pontos: 
999

[INICIALIZANDO JOGADOR 3]
Insira o nome:
lucas
Insira os pontos: 
2

[INICIALIZANDO JOGADOR 4]
Insira o nome:
mateus
Insira os pontos: 
1

[INICIALIZANDO JOGADOR 5]
Insira o nome:
olga
Insira os pontos: 
19

        RANKING:

afonso
999 pontos

olga
19 pontos

pedro
10 pontos

lucas
2 pontos

mateus
1 pontos

        [NOVO RECORDISTA!]

Insira o nome:
jefferson
Insira os pontos: 
7

        RANKING:

afonso
999 pontos

olga
19 pontos

pedro
10 pontos

jefferson
7 pontos

lucas
2 pontos*/

void exercicio_13(void);
/*                   Exercicio 13



        [FRACAO 1]

Insira o numerador:
5
Insira o denominador: 
7

        [FRACAO 2]

Insira o numerador:
3
Insira o denominador: 
17

        [SELECIONE A OPERACAO DESEJADA]
[1] SOMAR
[2] SUBTRAIR
[3] MULTIPLICAR
[4] DIVIDIR
Ou [0] para sair do programa

1
A soma de 5/7 e 3/17 = 106/119 = 0.890756
*/
int le_fracao(FRACAO *pf)
{
  puts("Insira o numerador: ");
  pf->numerador = valida_int();
  puts("Insira o denominador: ");
  if((pf->denominador = valida_int())==0)
  {
    puts("[ERRO]\n"
    "Denominador=0 !\n");
    return -1;
  }

  return 0;
}

void exercicio_14(void);
/*        Exercicio 14



        [FRACAO 1]

Insira o numerador:
7
Insira o denominador: 
10

        [FRACAO 2]

Insira o numerador:
3
Insira o denominador: 
5

        [SELECIONE A OPERACAO DESEJADA]
[1] SOMAR
[2] SUBTRAIR
[3] MULTIPLICAR
[4] DIVIDIR
         Ou [0] para sair do programa

3
O produto de 7/10 por 3/5 = 21/50 = 0.420000   */
FRACAO soma(FRACAO a,FRACAO b)
{
  FRACAO f3;
  
  f3.numerador=(a.numerador*b.denominador)+(b.numerador*a.denominador);
  f3.denominador = a.denominador*b.denominador;
  return f3;
}
FRACAO subtracao(FRACAO a,FRACAO b)
{
  FRACAO f3;
  
  f3.numerador=(a.numerador*b.denominador)-(b.numerador*a.denominador);
  f3.denominador = a.denominador*b.denominador;
  return f3;
}
FRACAO multiplicacao(FRACAO a,FRACAO b)
{
  FRACAO f3;
  
  f3.numerador=(a.numerador*b.numerador);
  f3.denominador = a.denominador*b.denominador;
  return f3;
}
FRACAO divisao(FRACAO a,FRACAO b)
{
  FRACAO f3;
  
  f3.numerador=(a.numerador*b.denominador);
  f3.denominador = a.denominador*b.numerador;
  return f3;
}


int main(int argc, char *argv[])
{
  int opcao=-1;
  while(opcao!=0)
  {
    puts("\n\n[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*]\n"
    "Lista 8 - AFONSO LUSTOSA PIRES JUNIOR - DRE:122079084\n\n"
    "SELECIONE O Exercicio QUE VOCÊ DESEJA:\n"
    "[1] Exercicio 1\t\t[8] Exercicio 8\n"
    "[2] Exercicio 2\t\t[9] Exercicio 9(desafio)\n"
    "[3] Exercicio 3\t\t[10] Exercicio 10\n"
    "[4] Exercicio 4\t\t[11] Exercicio 11\n"
    "[5] Exercicio 5\t\t[12] Exercicio 12\n"
    "[6] Exercicio 6\t\t[13] Exercicio 13\n"
    "[7] Exercicio 7\t\t[14] Exercicio 14\n"
    "Ou [0] para sair do programa.");
    opcao=valida_int();

    switch (opcao)
    {
      case 1:
        puts("\n\n[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*]\n\n"
        "                   Exercicio 1\n\n");
        exercicio_1();
        break;

      case 2:
        puts("\n\n[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*]\n\n"
        "                   Exercicio 2\n\n");
        exercicio_2();
        break;

      case 3:
        puts("\n\n[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*]\n\n"
        "                   Exercicio 3\n\n");
        exercicio_3();
        break;

      case 4:
        puts("\n\n[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*]\n\n"
        "                   Exercicio 4\n\n");
        exercicio_4();
        break;

      case 5:
        puts("\n\n[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*]\n\n"
        "                   Exercicio 5\n\n");
        exercicio_5();
        break;

      case 6:
        puts("\n\n[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*]\n\n"
        "                   Exercicio 6\n\n");
        exercicio_6();
        break;

      case 7:
        puts("\n\n[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*]\n\n"
        "                   Exercicio 7\n\n");
        exercicio_7();
        break;

      case 8:
        puts("\n\n[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*]\n\n"
        "                   Exercicio 8\n\n");
        exercicio_8();
        break;

      case 9:
        puts("\n\n[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*]\n\n"
        "                   Exercicio 9\n\n");
        exercicio_9();
        break;

      case 10:
        puts("\n\n[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*]\n\n"
        "                   Exercicio 10\n\n");
        exercicio_10();
        break;

      case 11:
        puts("\n\n[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*]\n\n"
        "                   Exercicio 11\n\n");
        exercicio_11();
        break;

      case 12:
        puts("\n\n[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*]\n\n"
        "                   Exercicio 12\n\n");
        exercicio_12();
        break;

      case 13:
        puts("\n\n[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*]\n\n"
        "                   Exercicio 13\n\n");
        exercicio_13();
        break;
      
      case 14:
        puts("\n\n[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*]\n\n"
        "                   Exercicio 14\n\n");
        exercicio_14();
        break;
      default:
        break;
    }
  }

  return 0;
  }

void exercicio_1(void)
{
  

  PONTO p;
  puts("Entre com as coordenadas do ponto p\n");
  scanf("%f %f", &p.x, &p.y);


  printf("DADOS LIDOS:\n"
  "X = %f , Y = %f\n", p.x,p.y);

}

void exercicio_2(void)
{
  



  CIRCUNFERENCIA c1;
  puts("\nEntre com o raio da circunferencia c1:");
  scanf("%f", &c1.raio);

  puts("\n Entre com as coordenadas do centro do circulo c1:\n");
  scanf("%f %f", &c1.centro.x, &c1.centro.y);

  printf("\n\nDADOS LIDOS:\n"
  "Circulo c1: raio = %f, x = %f, y = %f", c1.raio,c1.centro.x,c1.centro.y);

}

void exercicio_3(void)
{
  
  PONTO p1;
  PONTO p2;
  double distancia;


  puts("COORDENADAS DO PONTO 1:\n"
  "Insira X: ");
  p1.x=valida_float();

  puts("\n Insira Y:");
  p1.y=valida_float();

  puts("\n\nCOORDENADAS DO PONTO 2:\n"
  "Insira X: ");
  p2.x=valida_float();

  puts("\n Insira Y:");
  p2.y=valida_float();

  distancia=raiz((p1.x-p2.x)*(p1.x-p2.x) + (p1.y - p2.y)*(p1.y - p2.y));

  printf("\nA distancia do ponto p1 ao ponto p2 equivale a %.4f\n\n",distancia);

}

void exercicio_4(void)
{
  CIRCUNFERENCIA c;
  PONTO p1;
  float distancia;

  puts("\n\n\n[POSICAO RELATIVA ENTRE PONTO E CIRCUNFERENCIA]");
  puts("\nInsira o raio da circunferencia:");
  c.raio = valida_float();

  puts("\n [COORDENADAS (x,y) DO CENTRO DA CIRCUFERENCIA]\n"
  "Insira x: ");
  c.centro.x = valida_float();

  puts("\nInsira y: ");
  c.centro.y = valida_float();

  puts("[COORDENADAS DO PONTO]\n"
  "Insira x:");
  p1.x=valida_float();
  puts("\nInsira y:");
  p1.y=valida_float();

  distancia = raiz((c.centro.x - p1.x)*(c.centro.x - p1.x) + (c.centro.y - p1.y)*(c.centro.y - p1.y));

  if(distancia<=c.raio)
  {
		puts("O ponto esta contido na circunferencia.\n");
  }
	else
	{
		puts("O ponto nao esta contido na circunferencia.\n");
	}

}

void exercicio_5(void)
{
  TEMPO t1,t2;
  float minutos_t1,minutos_t2;
  
  puts("TEMPO 1:\n");
  le_tempo(&t1);

  puts("\nTEMPO 2:\n");
  le_tempo(&t2);

  minutos_t1=(t1.hora*60)+t1.minuto+(t1.segundo/60.0);
  minutos_t2=(t2.hora*60)+t2.minuto+(t2.segundo/60.0);
  

  if(minutos_t1>minutos_t2)
  {
    printf("\nO maior tempo e o Tempo 1:\n"
    "%d:%02d:%02d",t1.hora,t1.minuto,t1.segundo);
  }
  else if(minutos_t2>minutos_t1)
  {
    printf("\nO maior tempo e o Tempo 2:\n"
    "%d:%02d:%02d\n",t2.hora,t2.minuto,t2.segundo);
  }
  else
  {
    puts("\nOs tempos sao iguais.\n");
  }
}

void exercicio_6(void)
{
  TEMPO t1,t2,t3;

  puts("TEMPO 1:\n");
  le_tempo(&t1);

  puts("\nTEMPO 2:\n");
  le_tempo(&t2);

  t3.segundo=(t1.segundo+t2.segundo)%60;
  t3.minuto=(((t1.segundo+t2.segundo)/60) + (t2.minuto+t1.minuto))%60;
  t3.hora=(((t1.segundo+t2.segundo)/60) + (t2.minuto+t1.minuto))/60 + t1.hora + t2.hora;

puts("\nSoma dos tempos e igual a: ");
printf(" %d : %02d : %02d",t3.hora,t3.minuto,t3.segundo);
}

void exercicio_7(void)
{
  TEMPO t1,t2;
  
  puts("TEMPO 1:\n");
  le_tempo(&t1);

  puts("\nTEMPO 2:\n");
  le_tempo(&t2);

  switch (comparaTempo(&t1,&t2))
  {
    case -1:
      puts("\nO maior tempo e o Tempo 2\n");
      break;
    
    case 0:
      puts("\nOs tempos sao iguais\n");
      break;

    case 1:
      puts("\nO maior tempo e o Tempo 1\n");
      break;

    default:
      break;
  }
}

void exercicio_8(void)
{
  TEMPO tempo[5],aux;
  int i,j;
  for ( i = 0; i < 5; i++)
  {
    printf("\nTEMPO %d\n",i+1);
    le_tempo(tempo+i);
  }

  for(i=0;i<5-1;i++) /*ordenando tempos*/
  {
    for(j=0;j<5-1-i;j++)
    {
      if(comparaTempo(tempo+j,tempo+j+1)>0)
      {
        aux = tempo[j+1];
        tempo[j+1] = tempo[j];
        tempo[j]= aux;
      }
    }
  }
  puts("\nTempos em ordem crescente\n");
  for(i=0;i<5;i++)
  {
    printf("%d:%02d:%02d\n",tempo[i].hora,tempo[i].minuto,tempo[i].segundo);
  }
  
}

void exercicio_9(void)
{
  CIRCUNFERENCIA c1,c2;
  int tangente=-1;
  double distancia_centro,diferenca_raio;
  puts("\nInsira o raio da circunferencia 1:");
  c1.raio = valida_float();

  puts("\n [COORDENADAS (x,y) DO CENTRO DA CIRCUFERENCIA 1]\n"
  "Insira x: ");
  c1.centro.x = valida_float();

  puts("\nInsira y: ");
  c1.centro.y = valida_float();

  puts("\n[Circunferencia 2]");
  puts("\nInsira o raio da circunferencia:");
  c2.raio = valida_float();

  puts("\n [COORDENADAS (x,y) DO CENTRO DA CIRCUFERENCIA 2]\n"
  "Insira x: ");
  c2.centro.x = valida_float();

  puts("\nInsira y: ");
  c2.centro.y = valida_float();
  distancia_centro=(c1.centro.x-c2.centro.x)*(c1.centro.x-c2.centro.x) + (c1.centro.y-c2.centro.y)*(c1.centro.y-c2.centro.y);
  if(distancia_centro==(c1.raio+c2.raio)*(c1.raio+c2.raio)) tangente=1;

  distancia_centro = raiz(distancia_centro);
  diferenca_raio=c1.raio-c2.raio;
  diferenca_raio<0? diferenca_raio=-diferenca_raio : 0;
  if(distancia_centro<diferenca_raio )
  {
    puts("Uma circunferencia esta interna a outra.");
  }
  else if(distancia_centro>c1.raio+c2.raio)
  {
    printf("\nAs circunferencias sao externas uma a outra.\n");
  }
  else if(tangente==1)
  {
    printf("As duas circunferencias sao tangentes externamente");
  }
  else if(distancia_centro<c1.raio+c2.raio)
  {
    printf("As duas circunferencias sao secantes");
  }
  
}

void exercicio_10(void)
{
  JOGADOR jogadores[5];
  int i;
  for (i = 0; i < 5; i++)
  {
    printf("[INICIALIZANDO JOGADOR %d]\n",i+1);
    le_jogador(jogadores+i);
  }

  puts("\n\tJOGADORES:");
  for (i = 0; i < 5; i++)
  {
    printf("\n%s\n"
    "%d pontos\n",jogadores[i].nome,jogadores[i].pontos);
  }
  
}

void exercicio_11(void)
{
  JOGADOR jogadores[5];
  int i;
  for (i = 0; i < 5; i++)
  {
    printf("\n[INICIALIZANDO JOGADOR %d]\n",i+1);
    le_jogador(jogadores+i);
  }

  ordena_jogadores(jogadores,5);

  puts("\n\tRANKING:");
  for (i = 4; i >= 0; i--)
  {
    printf("\n%s\n"
    "%d pontos\n",jogadores[i].nome,jogadores[i].pontos);
  }
  
}

void exercicio_12(void)
{
  JOGADOR jogadores[5],auxiliar;
  int i;
  for (i = 0; i < 5; i++)
  {
    printf("\n[INICIALIZANDO JOGADOR %d]\n",i+1);
    le_jogador(jogadores+i);
  }

  ordena_jogadores(jogadores,5);

  puts("\n\tRANKING:");
  for (i = 4; i >=0; i--)
  {
    printf("\n%s\n"
    "%d pontos\n",jogadores[i].nome,jogadores[i].pontos);
  }
  
  puts("\n\t[NOVO RECORDISTA!]\n");
  le_jogador(&auxiliar);

  if(auxiliar.pontos>jogadores[0].pontos) jogadores[0]=auxiliar;

  ordena_jogadores(jogadores,5);

  puts("\n\tRANKING:");
  for (i = 4; i >=0; i--)
  {
    printf("\n%s\n"
    "%d pontos\n",jogadores[i].nome,jogadores[i].pontos);
  }

  
}

void exercicio_13(void)
{
  FRACAO f1,f2,f3;
  float valor;
  int opcao=-1;

  puts("\n\t[FRACAO 1]\n");
  if(le_fracao(&f1)<0) return;
  
  puts("\n\t[FRACAO 2]\n");
  if(le_fracao(&f2)<0) return;
  while(opcao<0 || opcao>4)
  {
    puts("\n\t[SELECIONE A OPERACAO DESEJADA]\n"
    "[1] SOMAR\n"
    "[2] SUBTRAIR\n"
    "[3] MULTIPLICAR\n"
    "[4] DIVIDIR\n"
    "Ou [0] para sair do programa\n");
    opcao = valida_int();
  }
  switch(opcao)
  {
    case 0:
      return;
    case 1:
      f3.numerador=(f1.numerador*f2.denominador)+(f2.numerador*f1.denominador);
      f3.denominador = f1.denominador*f2.denominador;
      valor=f3.numerador/(f3.denominador*1.0);
      printf("\nA soma de %d/%d e %d/%d = %d/%d = %f\n",
      f1.numerador,f1.denominador,f2.numerador,f2.denominador,
      f3.numerador,f3.denominador,valor);
      break;

    case 2:
      f3.numerador=(f1.numerador*f2.denominador)-(f2.numerador*f1.denominador);
      f3.denominador = f1.denominador*f2.denominador;
      valor=f3.numerador/(f3.denominador*1.0);
      printf("\nA diferenca de %d/%d e %d/%d = %d/%d = %f\n",
      f1.numerador,f1.denominador,f2.numerador,f2.denominador,
      f3.numerador,f3.denominador,valor);
      break;

    case 3:
      f3.numerador = f1.numerador*f2.numerador;
      f3.denominador = f1.denominador*f2.denominador;
      valor=f3.numerador/(f3.denominador*1.0);
      printf("\nO produto de %d/%d por %d/%d = %d/%d = %f\n",
      f1.numerador,f1.denominador,f2.numerador,f2.denominador,
      f3.numerador,f3.denominador,valor);
      break;
    
    case 4:
      f3.numerador = f1.numerador*f2.denominador;
      f3.denominador = f1.denominador*f2.numerador;
      valor=f3.numerador/(f3.denominador*1.0);
      printf("\nA divisao de %d/%d por %d/%d = %d/%d = %f\n",
      f1.numerador,f1.denominador,f2.numerador,f2.denominador,
      f3.numerador,f3.denominador,valor);
      
      break;
  }
}

void exercicio_14(void)
{
  FRACAO f1,f2,f3;
  float valor;
  int opcao=-1;

  puts("\n\t[FRACAO 1]\n");
  if(le_fracao(&f1)<0) return;
  
  puts("\n\t[FRACAO 2]\n");
  if(le_fracao(&f2)<0) return;
  while(opcao<0 || opcao>4)
  {
    puts("\n\t[SELECIONE A OPERACAO DESEJADA]\n"
    "[1] SOMAR\n"
    "[2] SUBTRAIR\n"
    "[3] MULTIPLICAR\n"
    "[4] DIVIDIR\n"
    "\t Ou [0] para sair do programa\n");
    opcao = valida_int();
  }
  switch(opcao)
  {
    case 0:
      return;
    case 1:
      f3=soma(f1,f2);
      valor=f3.numerador/(f3.denominador*1.0);
      printf("A soma de %d/%d e %d/%d = %d/%d = %f\n",
      f1.numerador,f1.denominador,f2.numerador,f2.denominador,
      f3.numerador,f3.denominador,valor);
      break;

    case 2:
      f3=subtracao(f1,f2);
      valor=f3.numerador/(f3.denominador*1.0);
      printf("A diferenca de %d/%d e %d/%d = %d/%d = %f\n",
      f1.numerador,f1.denominador,f2.numerador,f2.denominador,
      f3.numerador,f3.denominador,valor);
      break;

    case 3:
      f3=multiplicacao(f1,f2);
      valor=f3.numerador/(f3.denominador*1.0);
      printf("O produto de %d/%d por %d/%d = %d/%d = %f\n",
      f1.numerador,f1.denominador,f2.numerador,f2.denominador,
      f3.numerador,f3.denominador,valor);
      break;
    
    case 4:
      f3=divisao(f1,f2);
      valor=f3.numerador/(f3.denominador*1.0);
      printf("A divisao de %d/%d por %d/%d = %d/%d = %f\n",
      f1.numerador,f1.denominador,f2.numerador,f2.denominador,
      f3.numerador,f3.denominador,valor);
      
      break;
  }
}