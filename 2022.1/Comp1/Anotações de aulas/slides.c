#include <stdio.h>




/*                           SOBRE FUNÇÃO SCANF 
int main (void){
    int mes,dia,ano;
    int lidos;
    puts("Insira uma data no formato dd/mm/aaaa\n");
    lidos = scanf("%d/%d/%d",&dia,&mes,&ano);
    
    printf("\nForam lidos %d dados\n",lidos);
    printf("A data inserida foi: %d -- %d -- %d", dia,mes,ano);
    return 0;
} */

/* SOBRE TPOS DE CARACTERES 
int main(void){

    char c;
    puts("\nInsira um caractere qualquer");
    c=getchar();
    printf("\n O Valor ASCII do caractere '%c' vale %d\n",c,c);
    putchar(c); */

        /*int i;
    int v[10]={0};
    int j;
    
    for(i=0;i<10;i++)
    {
        v[i]=0;
    }



    espaco = 10*sizeof(int);




    
    

    for(i=0;i<10;i++)
    {
        printf("\nv[%d]=%d\n",i,v[i]);
    }
    
    printf("\nespaço de v=%d",espaco);
    
    */

    /* 
    
    int vetor[5], i, num;

    puts("ENtre com o n inicial do conjunto:");
    scanf("%d",&num);

    for (i=0;i < 5;i++)
    {
        vetor[i]=num++;
    }


    for(i=0;i<5;i++)
    {
        printf("ELemento %d = %d\n", i, vetor[i]);
    }
    */
   /*
   int vetor1[DIM],vetor2[DIM],i,prod=0;




   for(i=0;i < DIM;i++)
   {
       scanf("%d",&vetor1[i]);
   }

   for(i=0;i<DIM;i++)
   {
       scanf("%d",&vetor2[i]);
   }

   for(i=0;i<DIM;i++)
   {
       prod += vetor1[i] * vetor2[i];
   }

   printf("O produto vale %d",prod); */





   /*int vetor[5],i,j,temp;
   for(i=0;i<5;i++)
   {
       scanf("%d",&vetor[i]);
   }

   for(i=0;i < 5-1;i++)
   {
       for(j=0;j<5-1-i;j++)
       {
           if(vetor[j]>vetor[j+1])
           {
               temp=vetor[j];
               vetor[j]=vetor[j+1];
               vetor[j+1]=temp;
           }
       }
   }

    puts("\n");
    for(i=0;i<5;i++)
    {
        printf(" %d |",vetor[i]);
    } 

    char a[]="aeiou";
    char b[]= "abcd65634543545454e";
    char c[]="aiueo";
    int len = strlen(b);
    int j;
    j= strcmp(a,c);

    printf("strcmp=%d",j); */


    /*
    int y=1234;
    float x;


    x = (y*4)/1000000;


    printf("\n x= %f\n",x);
    */
    return 0;


} 