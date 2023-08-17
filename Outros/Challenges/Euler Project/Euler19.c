#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int ano=1901,bissexto=0,dia,cont;

    cont=0;

    dia=1; //começando em 1 jan 1901 que foi terça. terça =1 logo dom=6
    while(ano<2001)
    { 
        if(ano%400==0) bissexto=1;
        else if( (ano%4==0) && (ano%100!=0)) bissexto=1;
        else bissexto =0;

        /*Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.*/

        if(dia==6) cont++; //checando 1 de jan

        dia = (dia+31)%7;
        if(dia==6) cont++;    //checando 1 de fev

        if(bissexto)
        {
            dia = (dia+29)%7;
            if(dia==6) cont++;    //checando 1 de março
        }
        else
        {
            dia = (dia+28)%7;
            if(dia==6) cont++;    //checando 1 de março
        }
        
        dia = (dia+31)%7;
        if(dia==6) cont++;    //checando 1 de abril

        dia = (dia+30)%7;
        if(dia==6) cont++;    //checando 1 de maio

        dia = (dia+31)%7;
        if(dia==6) cont++;    //checando 1 de junho

        dia = (dia+30)%7;
        if(dia==6) cont++;    //checando 1 de julho

        dia = (dia+31)%7;
        if(dia==6) cont++;    //checando 1 de agosto

        dia = (dia+31)%7;
        if(dia==6) cont++;    //checando 1 de setembro

        dia = (dia+30)%7;
        if(dia==6) cont++;    //checando 1 de outubro

        dia = (dia+31)%7;
        if(dia==6) cont++;    //checando 1 de novembro

        dia = (dia+30)%7;
        if(dia==6) cont++;    //checando 1 de dezembro

        dia = (dia+31)%7;



        ano++;
    }

    printf("\nNumero de dias 1 e domingo de 1901 ate 2000 é: %d\n", cont);
    return 0;
}