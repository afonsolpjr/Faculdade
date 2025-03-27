/* LISTA 5 - VETORES
 * AFONSO LUSTOSA PIRES JUNIOR

EXERCÍCIO 1 -
[ENTRADAS]
Insira a primeira string: Afonso
Insira a segunda string: Lustosa
[INsira o número da operação desejada]
2
[SAIDA]: Afonso Lustosa




#include <stdio.h>

int tam_str(char str[500]);
int valida_int(void);
int inverte_str(char str1[500], char str2[500]);
int junta_str(char str1[500], char str[500]);
int checa_tam(char str1[500],char str2[500]);
int comp_str(char str1[500],char str2[500]);
int checa_char(char str[500],char c,int qual_string);




int main(void)
{
    int menu=1,opcao=0;
    char str1[500],str2[500],lixo,c;

    puts("\nInsira a primeira string:");
    scanf("%[^\n]s",str1);
    while((lixo=getchar()) != EOF && lixo!= '\n');
    puts("\nInsira a segunda string:");
    scanf("%[^\n]s",str2);

    while(menu)
    {
        puts("\n\n\n \t [Insira o número da operação desejada]\n\n"
        "[1] Mostrar as duas strings invertidas\n"
        "[2] Concatenar as duas strings em outra e imprimir\n"
        "[3] Comparar e saber qual é a maior\n"
        "[4] Informar a string de maior tamanho\n"
        "[5] Checar ocorrencia de caractere na string e informar posicao\n"
        "[6] Sair do programa\n");

        opcao=valida_int();

        while((lixo=getchar()) != EOF && lixo!= '\n');

        switch(opcao)
        {
            case 1:
                inverte_str(str1,str2);
                break;

            case 2:
                junta_str(str1,str2);
                break;

            case 3:
                comp_str(str1,str2);
                break;

            case 4:
                checa_tam(str1,str2);
                break;

            case 5:
                puts("\nInsira o caractere a ser checado nas strings:");
                scanf("%c",&c);
                checa_char(str1,c,1);
                checa_char(str2,c,2);
                break;

            case 6:
                return 0;
        }
    }
    return 0;

}



int inverte_str(char str1[500],char str2[500])
{

    int i;

    puts("\n [INVERTENDO STRINGS...]\n\n"
    "Primeira string invertida:");
    for(i=tam_str(str1)-1;i>=0;i--)
    {
        putchar(str1[i]);
    }

    puts("\n\nSegunda string invertida:");
    for(i=tam_str(str2)-1;i>=0;i--)
    {
        putchar(str2[i]);
    }

    return 0;
}

int valida_int(void)
{
    int valido,lixo,valor;
    valido=scanf("%d",&valor);
        while(valido==0 || (valor<1 || valor>6))
        {
            while((lixo=getchar()) != EOF && lixo!= '\n');
            puts("\nInsira um valor válido: ");
            valido=scanf("%d",&valor);
        }
    return valor;
}

int junta_str(char str1[500], char str2[500])
{
    int i,j=0;
    char str3[1000];
    for (i = 0; i < 500; i++)
    {
        if(str1[i]!='\0')
        {
            str3[j]=str1[i];
            j++;
        }
        else { break; }
    }
    str3[j]=' ';
    j++;
    for (i = 0; i < 500; i++)
    {
        if(str2[i]!='\0')
        {
            str3[j]=str2[i];
            j++;
        }
        else {break;}
    }
    str3[j]='\0';
    puts("\n\n[JUNTANDO STRINGS...]\n"
    "Resultado: ");
    for(i=0;i<500;i++)
    {
        if(str3[i]!='\0')
        {
            putchar(str3[i]);
        }
        else {break;}
    }





    return 0;
}

int tam_str(char str[500])
{
    int i,tamanho=0;
    for(i=0;i<500;i++)
    {
        if(str[i]!='\0')
        {
            tamanho++;
        }
        else
        {
            tamanho++;
            break;
        }
    }

    return tamanho;
}

int checa_tam(char str1[500],char str2[500])
{
    puts("\n\n[CHECANDO TAMANHO DAS STRINGS...]\n");
    if(tam_str(str1)>tam_str(str2)) {
        puts("A string de maior tamanho é a PRIMEIRA.");
        }
    else if(tam_str(str1)<tam_str(str2)) {
        puts("A string de maior tamanho é a SEGUNDA.");
        }
    else if(tam_str(str1)==tam_str(str2)) {
        puts("As duas strings possuem tamanhos IGUAIS.");
        }
    return 0;
}


int comp_str(char str1[500],char str2[500])
{
    int i,max;
    tam_str(str1) >= tam_str(str2) ? (max=tam_str(str2)) : (max=tam_str(str1));
    puts("\n[COMPARANDO STRINGS...]\n\n");
    for ( i = 0; i < max; i++)
    {
        if(str1[i]>str2[i])
        {
            puts("A primeira string é lexogramaticalmente maior que a segunda.\n");
            return 0;
        }
        else if(str1[i]<str2[i])
        {
            puts("A segunda string é lexogramaticalmente maior que a primeira.\n");
            return 0;
        }
    }
    puts("As duas strings são iguais.\n");

    return 0;
}

int checa_char(char str[500],char c, int qual_string)
{
    int i,freq=0;
    printf("\n\n[CHECANDO OCORRENCIAS DO CARACTERE '%c' NA STRING %d... ]\n\n",c,qual_string);
    for ( i = 0; i < tam_str(str); i++)
    {
        str[i]==c ? (freq++) : 0;
    }

    if(freq>0)
    {
        printf("O caractere '%c' ocorre %d vezes na %da string,nas seguintes posicoes:\n"
        ,c,freq,qual_string);
        for ( i = 0; i < tam_str(str); i++)
        {
            str[i]==c ? (printf(" [%d]",i)): 5;
        }
    }
    else
    {
        printf("O caractere '%c' não aparece na %da string.",c,qual_string);
    }



    return 0;
}


************************************************************



                EXERCICIO 2:

    [ENTRADAS]: Insira os valores para a primeira matriz 2x3:
    1
    2
    3
    4
    5
    6

    Insira os valores para a segunda matriz 2x3:
    1
    2
    3
    4
    5
    6

    [SAÍDA]:
    Soma das matrizes:

   2   4   6

   8  10  12



#include <stdio.h>

int valida_int(void);

int main(void)
{
    int matriz1[2][3], matriz2[2][3],soma[2][3],i,j;

    puts("Insira os valores para a primeira matriz 2x3");
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            matriz1[i][j]=valida_int();
        }
    }
    puts("\nMATRIZ 1:\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%4d",matriz1[i][j]);
        }
        puts("\n");
    }
    puts("Insira os valores para a segunda matriz 2x3");
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            matriz2[i][j]=valida_int();
        }
    }
    puts("\nMATRIZ 2:\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%4d",matriz2[i][j]);
        }
        puts("\n");
    }


    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            soma[i][j]=matriz1[i][j]+matriz2[i][j];
        }
    }

    puts("\nSoma das matrizes:\n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%4d",soma[i][j]);
        }
        puts("\n");
    }
    return 0;
}
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






*****************************************************************

        EXERCICIO 3:

Insira 10 valores:[ENTRADAS]
0
1
9
2
8
3
4
5
6
7
[SAÍDA]:
O maior valor da lista = [9]
O menor valor da lista =[0]
A lista possui 5 numeros pares.
A soma de todos os valores = 45
Insira um numero para checagem no vetor:
[ENTRADA]: 9
[SAÍDA]:
O numero 9 esta presente no vetor.






#include <stdio.h>

int valida_int(void);

int main(void)
{
    int vetor[10],i,j,temp,pares=0,soma=0,checa;

    puts("\nInsira 10 valores:");
    for(i=0;i<10;i++)
    {
        vetor[i]=valida_int();
        soma+=vetor[i];
        vetor[i]%2==0 ? pares++ : 0;
    }

    for(i=0;i<10;i++)
    {
        for(j=0;j<10-i-1;j++)
        {
            if(vetor[j]>vetor[j+1])
            {
                temp=vetor[j+1];
                vetor[j+1]=vetor[j];
                vetor[j]=temp;
            }
        }
    }



    printf("\nO maior valor da lista = [%d]\n"
    "O menor valor da lista =[%d]\n"
    "A lista possui %d numeros pares.\n"
    "A soma de todos os valores = %d\n",vetor[9],vetor[0],pares,soma);

    puts("Insira um numero para checagem no vetor:");
    checa = valida_int();
    for(i=0;i<10;i++)
    {
        if(vetor[i]==checa)
        {
            printf("\nO numero %d esta presente no vetor.",checa);
            break;
        }
    }
    if(i==10)
    {
        printf("\nO numero %d NAO esta presente no vetor.",checa);
    }


    return 0;
}
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






*****************************************************



        EXERCICIO 4



Insira os 25 valores para a primeira matriz 5x5
[ENTRADAS]:
1
2
3
4
5
1
2
3
4
5
1
2
3
4
5
1
2
3
4
5
1
2
3
4
5

MATRIZ 1:

   1   2   3   4   5

   1   2   3   4   5

   1   2   3   4   5

   1   2   3   4   5

   1   2   3   4   5

Insira os 25 valores para a segunda matriz 5x5
[ENTRADAS]:
1
2
3
4
5
1
2
3
4
5
1
2
3
4
5
1
2
3
4
5
1
2
3
4
5

MATRIZ 2:

   1   2   3   4   5

   1   2   3   4   5

   1   2   3   4   5

   1   2   3   4   5

   1   2   3   4   5

[SAÍDA]:
RESULTADO:

  15  30  45  60  75

  15  30  45  60  75

  15  30  45  60  75

  15  30  45  60  75

  15  30  45  60  75





  #include <stdio.h>
int valida_int(void);
int main(void)
{
    int matriz1[5][5],matriz2[5][5],produto[5][5],i,j,k,somaprod;

    puts("Insira os 25 valores para a primeira matriz 5x5");
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            matriz1[i][j]=valida_int();
        }
    }
    puts("\nMATRIZ 1:\n");
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%4d",matriz1[i][j]);
        }
        puts("\n");
    }
    puts("Insira os 25 valores para a segunda matriz 5x5");
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            matriz2[i][j]=valida_int();
        }
    }
    puts("\nMATRIZ 2:\n");
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%4d",matriz2[i][j]);
        }
        puts("\n");
    }

    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            somaprod=0;
            for(k=0;k<5;k++)
            {
                somaprod+=matriz1[i][k]*matriz2[k][j];
                produto[i][j]=somaprod;
            }
        }
    }

    puts("\nRESULTADO:\n");
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            printf("%4d",produto[i][j]);
        }
        puts("\n");
    }







    return 0;
}

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






  *******************************************************

                EXERCICIO 5

[ENTRADAS]
Insira 5 valores para o VETOR 1:
1
2
3
4
6

Vetor 1:
  [1]    [2]    [3]    [4]    [6]


Insira 5 valores para o VETOR 2:
1
2
3
4
5

Vetor 2:
  [1]    [2]    [3]    [4]    [5]


[SAÍDAS]


Vetor com a soma de elementos de mesma posição:
  [2]    [4]    [6]    [8]    [11]


Vetor com o produto de elementos de mesma posição:
  [1]    [4]    [9]    [16]    [30]


Diferença de Vetor 1 - Vetor 2:
  [6]


Vetor Intersecção:
  [1]    [2]    [3]    [4]


 Vetor união:
  [1]    [2]    [3]    [4]    [5]    [6]





#include <stdio.h>

int valida_int(void);
int print_vetor(int vetor[5]);
int soma_xy(int x,int y);
int printa_inter(int vetor1[5],int vetor2[5]);
int print_dif(int vetor1[5],int vetor2[5]);

int print_uniao(int vetor1[5],int vetor2[5]);

int main(void)
{
    int vetor1[5],vetor2[5],v3[5],i;


    puts("\nInsira 5 valores para o VETOR 1:");
    for(i = 0; i <5; i++)
    {
        vetor1[i]=valida_int();
    }
    puts("\nVetor 1:");
    print_vetor(vetor1);

    puts("\nInsira 5 valores para o VETOR 2:");
    for(i = 0; i <5; i++)
    {
        vetor2[i]=valida_int();
    }
    puts("\nVetor 2:");
    print_vetor(vetor2);

    puts("\n\n\nVetor com a soma de elementos de mesma posição:");
    for(i=0;i<5;i++)
    {
        v3[i]=vetor1[i]+vetor2[i];
        printf("  [%d]  ",v3[i]);
    }


    puts("\n\n\nVetor com o produto de elementos de mesma posição:");
    for(i=0;i<5;i++)
    {
        v3[i]=vetor1[i]*vetor2[i];
        printf("  [%d]  ",v3[i]);
    }

    puts("\n\n\nDiferença de Vetor 1 - Vetor 2:");
    print_dif(vetor1,vetor2);

    puts("\n\n\nVetor Intersecção:");
    printa_inter(vetor1,vetor2);

    puts("\n\n\n Vetor união:");
    print_uniao(vetor1,vetor2);


    return 0;
}

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

int print_vetor(int vetor[5])
{
    int i;
    for(i=0;i<5;i++)
    {
        printf("  [%d]  ",vetor[i]);

    }
    puts("\n");
    return 0;
}

int print_dif(int vetor1[5],int vetor2[5])
{
    int i,j,printa=1;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(vetor1[i]==vetor2[j])
            {
                printa=0;
            }

        }

        if(printa)
        {
            printf("  [%d]  ",vetor1[i]);
        }
        printa=1;
    }

    return 0;
}


int printa_inter(int vetor1[5],int vetor2[5])
{
    int i,j,printa=0;
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            if(vetor1[i]==vetor2[j])
            {
                printa=1;
            }

        }

        if(printa)
        {
            printf("  [%d]  ",vetor1[i]);
        }
        printa=0;
    }

    return 0;
}

int print_uniao(int vetor1[5],int vetor2[5])
{
    int i;

    for(i=0;i<5;i++)
    {
        printf("  [%d]  ",vetor2[i]);
    }

    print_dif(vetor1,vetor2);
    return 0;
}



****************************************
        EXERCÍCIO 6

NOVO ALUNO:

Insira a matricula do aluno:
1
Insira a media das provas:
2
Insira a media dos trabalhos:
3

NOVO ALUNO:

Insira a matricula do aluno:
2
Insira a media das provas:
2
Insira a media dos trabalhos:
3

NOVO ALUNO:

Insira a matricula do aluno:
3
Insira a media das provas:
3
Insira a media dos trabalhos:
4

NOVO ALUNO:

Insira a matricula do aluno:
4
Insira a media das provas:
4
Insira a media dos trabalhos:
5

NOVO ALUNO:

Insira a matricula do aluno:
5
Insira a media das provas:
3
Insira a media dos trabalhos:
5


[CALCULANDO NOTAS FINAIS...]

 O aluno com a maior nota final foi o
de matricula=[4], com nota final = 9.

[CALCULANDO MEDIA DAS NOTAS FINAIS...]
A média das notas finais foi = 6.80




***código:



#include <stdio.h>

int valida_int(void);

int main(void)
{
    int notas[5][4],i,j,maior_nota[2]={0,0};
    float media;


    for(i=0;i<5;i++)
    {
        puts("\nNOVO ALUNO:");
        for(j=0;j<3;j++)
        {
            switch (j)
            {
            case 0:
                puts("\nInsira a matricula do aluno:");
                notas[i][j]=valida_int();
                break;

            case 1:
                puts("Insira a media das provas:");
                notas[i][j]=valida_int();
                break;

            case 2:
                puts("Insira a media dos trabalhos:");
                notas[i][j]=valida_int();
                break;

            }

        }
    }
    puts("\n\n[CALCULANDO NOTAS FINAIS...]");
    for (i = 0; i < 5; i++)
    {
        notas[i][3]= notas[i][1]+notas[i][2];
    }

    for ( i = 0; i < 5; i++)
    {
        if(notas[i][3]>maior_nota[1])
        {
            maior_nota[1]=notas[i][3];
            maior_nota[0]=notas[i][0];
        }
    }

    for(i=0; i<5;i++)
    {
        media+=notas[i][3];
    }
    media=(1.0*media)/i;

    puts("\n O aluno com a maior nota final foi o");
    printf("de matricula=[%d], com nota final = %d.\n\n"
    "[CALCULANDO MEDIA DAS NOTAS FINAIS...]\n"
    "A média das notas finais foi = %.2f\n"
    ,maior_nota[0],maior_nota[1],media);

    return 0;
}

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

*/
