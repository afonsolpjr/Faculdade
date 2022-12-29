#include <stdlib.h>
#include <stdio.h>



int caso_2()
{
    int num[601],limite,c,i,p;
    limite=100;
    p=1;

    for(i=0;i<601;i++) num[i]=0;



    for(i=2;i<=100;i++) num[i]=1;

    for(i=4;i<=200;i+=2) num[i]=1;

    for(i=6;i<=300;i+=3) num[i]=1;

    for(i=8;i<=400;i+=4) num[i]=1;

    for(i=10;i<=500;i+=5) num[i]=1;

    for(i=12;i<=600;i+=6) num[i]=1;

    c=0;
    for(i=0;i<601;i++)
    {
        if(num[i]) c++;
    }

    return c;
}

int caso_3()
{
    int num[401],limite,c,i,p;
    limite=100;
    p=1;

    for(i=0;i<401;i++) num[i]=0;

    for(i=2;i<=100;i++) num[i]=1;

    for(i=4;i<=200;i+=2) num[i]=1;

    for(i=6;i<=300;i+=3) num[i]=1;

    for(i=8;i<=400;i+=4) num[i]=1;




    c=0;
    for(i=0;i<401;i++)
    {
        if(num[i]) c++;
    }
    return c;
}

int caso_5()
{
    int num[201],limite,c,i,p;
    limite=100;
    p=1;

    for(i=0;i<201;i++) num[i]=0;

    for(i=2;i<=100;i++) num[i]=1;

    for(i=4;i<=200;i+=2) num[i]=1;

    c=0;
    for(i=0;i<201;i++)
    {
        if(num[i]) c++;
    }
    return c;
}

int main(void)
{
    int i,c;


    printf("Caso 2: %d\n"
            "Caso 3: %d\n"
            "Caso 5: %d\n"
            "Caso 6: %d\n"
            "Caso 7: %d\n"
            "Caso 10: %d\n",
            caso_2(),caso_3(),caso_5(),caso_5(),caso_5(),caso_5());
}
