/*
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names,
 begin by sorting it into alphabetical order. Then working out the alphabetical value for each name,
  multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, 
is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


char** orgnomes();
void lenomes();
void calcula_scores(int *scores,char **nomes);

int main(void)
{
    char **nomes;
    int i,scores[5163];

    long long int resultado=0;


    for(i=0;i<5163;i++) scores[i]=0;

    lenomes();
    nomes = orgnomes();

    calcula_scores(scores,nomes);

    
    for(i=0;i<5163;i++) resultado+=scores[i];

    printf("\n\n             O resultado final foi      %lld",resultado);

    return 0;
}

void lenomes()
{
    FILE *pa, *ordem;
    char c;
    int i=0,k=0,max=0;
   

    pa = fopen("Euler22names.txt","r");
    if(pa==NULL)
    {
        puts("\nErro abrindo arquivo\n");
        return;
    }

    ordem = fopen("nomeslista.txt","w");
    if(ordem==NULL)
    {
        puts("\nErro abrindo arquivo\n");
        return;
    }

    while(!feof(pa))
    {
        k=0;
        if(i)
        {
            fputc('\n',ordem);
            i=0;
        }
        while((c = fgetc(pa))!=34 && c!=44 && c!=EOF) //dentro do while começa a pegar um nome
        {
            fputc(c,ordem);
            i=1;
            k++;
        }
        k>max? max= k : 0;
     
    }
    fclose(pa);
    fclose(ordem);
}

char** orgnomes()
{
    FILE *pa;
    char c,nome[12],temp[12];
    int i=0,k,count=0;
    char **nomes;
   
    if((nomes = (char**) calloc(5163,sizeof(char*)))==NULL)
    {
        puts("\nProblema ao alocar memoria.\n");
        return NULL;
    }
    
    for(i=0;i<5163;i++)
    {
        if((nomes[i] = (char*) calloc(12,sizeof(char)))==NULL)
        {
            puts("\nProblema ao alocar memoria 2.\n");
            return NULL;
        }
    }

    pa = fopen("nomeslista.txt","r");
    if(pa==NULL)
    {
        puts("\nErro abrindo arquivo\n");
        return NULL;
    }

    
  
    while(!feof(pa))
    { 
        k=0;
        while((c = fgetc(pa))!=10 && c!=EOF) //dentro do while começa a pegar um nome
        {
            nome[k]=c;
            k++;
        }
        if(k)
        {
            nome[k]='\0';
            strcpy(nomes[count++],nome);
        }
        
    }
    

    fclose(pa);
    remove("nomeslista.txt");

    for(i=0;i<5163;i++)
    {
        for(k=0;k<(5163-i-1);k++)
        {
            if( strcmp(nomes[k],nomes[k+1]) > 0 )
            {
                strcpy(temp,nomes[k+1]);

                strcpy(nomes[k+1],nomes[k]);

                strcpy(nomes[k],temp);
            }
        }
    }

    return nomes;
}

void calcula_scores(int *scores, char **nomes)
{
    int i,k;


    for(i=0;i<5163;i++)
    {
        for(k=0;nomes[i][k]!='\0';k++)
        {
            scores[i] += (nomes[i][k] - 64);
        }
        scores[i]*=(i+1);
    }

}




