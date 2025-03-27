#include <stdio.h>
#include <stdlib.h>

void strcop(void)
{
    /*ta incompleta, precisa ler 2 strings ainda
    puts("\n");
    strcop(destino,origem);
    printf("%s\n",origem);
    printf("%s\n",destino);

    while ((*d++ = *o++) != '\0')
    
    //essa expressão equivale a 
    {
        *d=*o;
        d++;
        o++;
    }
    */
}

void trocacao(void)
{
    int i;
    int *p1;

    char ce;
    
    char *pce=&ce;

    float f;
    float *pf=&f;

    p1=&i;
    i=127;
    *p1=*p1 +3;


    ce='P';

    f=10.25;


    printf("\npi=%p, i=%d"
    "\n pce=%p, ce=%c"
    "\n pf=%p, f=%.2f\n\n\n**********",(void *)p1,i,pce,ce,(void *)pf,f);
}

void mostrando_ponteiros(void)
{
    int i,vetor[5]={10,20,30,40,50};
    int *p1,*p2;
    i=100;
    p1=&vetor[2];
    printf("\n*p1=%d",*p1);
    p2=&i;
    printf("\n*p2=%d",*p2);
    p2=p1;
    printf("\n*p2=%d\n\n\n",*p2); 
}

void diferenca(void)
{
    /*         diferença entre ponteiros de um vetor e um de seus indices,apontando o indice  */
    float *pf1,*pf2;
    float vetor1[]={1.0,2.0,3.0,4.0,5.0,6.0,7.0};

   pf1=&vetor1[2];
   pf2=vetor1;
   printf("\nDiferença entre ponteiros = %ld\n\n\n", pf1-pf2);
   
}

void levetor(float *v,int tam)
{
    int i;
    puts("insira os valores dos ponteiros");
    for(i=0;i<tam;i++)
    {
        scanf("%f",v+i);
    }

}

void procuramaior(void)
{
    int i, tam=10,vezes=1;
    float maior,*v;
    vezes=1;
    puts("\n******\n\ntamanho do vetor?\n");
    scanf("%d",&tam);
    v=(float*)malloc(tam*sizeof(float));
    levetor(v,tam);
    maior=v[0];
    for(i=1;i<tam;i++)
    {
        if(v[i]>maior)
        {
            maior=v[i];
            vezes=1;
        }
        else
        {
            vezes++;
        }
    }
    printf("O maior elemento é %f\n",maior);
}

int matriz_p(void)
{
    int lin=3,col=4;

    int *matriz,i,j;


    matriz=malloc(lin*col*sizeof(int));

    if(!matriz)
    {
        printf("Erro.\n");
        return 1;
    }
    for(i=0; i<lin;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("Elemento %d %d =",i, j);
            scanf("%d",matriz+(i*lin*col+j));
        }
    }
    return 0;
}
int main(void)
{
    
    puts("Trocacao danada:\n");
    trocacao();

    mostrando_ponteiros();

    diferenca();

    procuramaior();

    matriz_p();

    


    

    /* formas diferentes de printar vetor
    for(i=0;i<7;i++)
    {
        printf("\nvetor1[%d]=%.1f",i,vetor1[i]);
    }
    puts("\n");
    for(i=0;i<7;i++)
    {
        printf("\nvetor1[vetor1+i]=%.1f",*(vetor1+i));
    }
    puts("\n");
    for(i=0,pf1=vetor1;i<7;i++,pf1++)
    {
        printf("\n *pf1=%.1f",*pf1);
    } */
  



    return 0;
}
/* programa q fiz pra testar calloc 
int altera()
{ 
    int i;
    int *p,*pt;

    p=(int*)malloc(10*4);
    pt=p;

    for(i=0;i<10;i++,pt++)
    {
        *pt=i;
    }
    return p;
}

int main(void)
{
    int i;
    int *p,*pt;
    p=altera();
    pt=p;

    for(i=0,pt=p;i<10;i++,pt++)
    {
        printf("\npt=%x, *pt=%d",pt,*pt);
    }


    return 0;
} */