#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct expressao{
    int n[2],d[2],resultado[2],simplificado[2];
    char c;
}EXPRESSAO;
void calcula_exp(EXPRESSAO *caso);
void simplifica(int *f, int *s);
int main()
{
    EXPRESSAO caso[10000];
    int i,n_casos;

    cin >> n_casos;

    for(i=0;i<n_casos;i++)
    {
        scanf("%d / %d %c %d / %d",&caso[i].n[0],&caso[i].d[0],
        &caso[i].c,&caso[i].n[1], &caso[i].d[1]);
        // printf("\nDebug: n1=%d   d1=%d  n2=%d d2=%d   c=%c e vale = %d\n",
        // caso[i].n[0],caso[i].d[0],
        // caso[i].n[1], caso[i].d[1],caso[i].c,caso[i].c);
        calcula_exp(&caso[i]);
    }

    for(i=0;i<n_casos;i++)
    {
        printf("%d/%d = %d/%d\n",caso[i].resultado[0],caso[i].resultado[1],
        caso[i].simplificado[0],caso[i].simplificado[1]);
    }
}


void calcula_exp(EXPRESSAO *caso)
{
    switch(caso->c)
    {
        case 43:       //soma
            caso->resultado[0] = (caso->n[0]*caso->d[1]) + (caso->n[1]*caso->d[0]);
            caso->resultado[1] = caso->d[0] * caso->d[1];
            simplifica(caso->resultado,caso->simplificado);
            break;
        
        case 45:        //subt
            caso->resultado[0] = (caso->n[0]*caso->d[1]) - (caso->n[1]*caso->d[0]);
            caso->resultado[1] = caso->d[0] * caso->d[1];
            simplifica(caso->resultado,caso->simplificado);

            break;
        
        case 42:        //mult
            caso->resultado[0] = caso->n[0]*caso->n[1] ;
            caso->resultado[1] = caso->d[0] * caso->d[1] ;
            simplifica(caso->resultado,caso->simplificado);
            break;
        
        case 47:        //div
            caso->resultado[0] = caso->n[0]*caso->d[1] ;
            caso->resultado[1] = caso->d[0] * caso->n[1] ;
            simplifica(caso->resultado,caso->simplificado);
            break;
    }
}
void simplifica(int *f, int *s)
{
    int i,neg[2] = {0};
    
    if(!f[0] || !f[1])
    {
        s[0] = 0;
        s[1] = 1;
        return;
    }

    s[0] = f[0];
    s[1] = f[1];

    if(s[0]<0) 
    {    
        neg[0] = 1;
        s[0]*=-1;
    }
    if(s[1]<0) 
    {
        neg[1] = 1;
        s[1]*=-1;
    }

    // printf("debug simplificacao: n=%d d=%d   fim\n\n",s[0],s[1]);

    for(i=2;(i<=s[0])&&(i<=s[1]);i++)
    {
        while( !(s[0]%i) && !(s[1]%i) )
        {
            s[0] = s[0]/i;
            s[1] = s[1]/i;
        }
    }

    if(neg[0]) s[0]*=-1;
    if(neg[1]) s[1]*=-1;
}