
#include <stdio.h>
#include <string.h>

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

unsigned long int fatorial_rec(unsigned long int num)
{
    if(num==0) return 1;
    else
    return num *fatorial_rec(num-1);
}



void le_vetor(int *vetor, int tam)
{
    int i;
    for ( i = 0; i < tam; i++)
    {
        *(vetor+i)= valida_int();
    }
    
}


int pot(int a,int b);
/*int main(void)
{
    int a,b;
    puts("Insira a:");
    scanf("%d",&a);


    puts("\nInsira b:");
    scanf("%d",&b);

    printf("\n%d elevado a %d é=%d",a,b,pot(a,b));

    return 0;
    
} */

int pot(int a, int b)
{       
    int i,result=a;
    for(i=0;i<b-1;i++)
    {
	    result=a*result;
    }
    return (result);
}


void trocar(int *a,int *b)
{
    int temp;
    temp =*a;
    *a = *b;
    *b= temp;
}
/*
int main(void)
{
    int a,b;

    puts("\nInsira a:");
    a=valida_int();
    puts("\nInsira b:");
    b=valida_int();

    trocar(&a,&b);
    printf("\n\na=%d\nb=%d",a,b);


    return 0;
}
*/

/* FATORIAL RECURSIVO ***


int main(void)
{
    unsigned long int fat=1,num,i;
    puts("\nInsira num:");
    num=valida_int();

    for(i=num;i>1;i--)
    {
        fat=fat*i;
    }
    puts("[1]Normal\n ou [2]Recursivo?");
    i=valida_int();
    switch (i)
    {
    case 1:
        printf("Fatorial= %2lu",fat);
        break;
    
    case 2:
        fat = fatorial_rec(num);
        printf("Fatorial= %2lu",fat);
        break;
    }

    return 0;


} */

/* TESTANDO PARAMETROS DA MAIN E PONTEIROS */
/*
int main(int argc, char *argv[])
{   
    int i=10,vetor[2]={1,2},*pi;

    pi=&i;


    printf("\ni=%d, pi=%X, i=%d",i,pi,*pi);
    puts("\nInsira 2 valores:");
    le_vetor(vetor,2);

    printf("\nvetor[1]=%d e vetor[2]=%d\n"
    "frase=%s,argc=%d",vetor[0],vetor[1],argv[1],argc);



    

    return 0; 
} */

/* SOBRE ESCOPO DE VARIAVEIS: ****




int i;
void p1(int x);
void p2(int*x);

int main(void)
{
    int a[2];
    a[0]=10;
    a[1]=20;
    printf("a[0]=%d a[1]=%d\n",a[0],a[1]);

    i=0;
    p1(a[i]);
    printf("a[0]=%d a[1]=%d\n",a[0],a[1]);

    i=0;
    p2(&a[i]);
    printf("a[0]=%d a[1]=%d  i=%d\n",a[0],a[1],i);



    return 0;
}

void p1(int x)
{
    i=i+1;
    x=x+2;
    printf("x=%d  i=%d\n",x,i);
}

void p2(int *x)
{
    i=i+1;
    *x=*x+2;
    printf("x=%di=%d\n",*x,i);
} */