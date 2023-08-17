#include <stdio.h>


int main(void)
{
    int i;
    float media,notas[4],exame;

    scanf("%f %f %f %f",&notas[0],&notas[1],&notas[2],&notas[3]);

    if(!feof(stdin))
    {
        scanf("%f",&exame);
    }
    

    media = 2*notas[0] + 3*notas[1] + 4*notas[2] + notas[3];
    media = media/10;

    printf("Media: %.1f\n",media);
    if(media>=7)
    {
        printf("Aluno aprovado.\n");
        return 0;
    }
    else if(media<5)
    {
        printf("Aluno reprovado.\n");
        return 0;
    }
    else
    {
        printf("Aluno em exame.\n");
        printf("Nota do exame: %.1f\n",exame);
        media = (media + exame)/2;
        if(media>=5)
        {
            printf("Aluno aprovado.\n");
            printf("Media final: %.1f\n",media);
            return 0;
        }
        else
        {
            printf("Aluno reprovado.\n");
            printf("Media final: %.1f\n",media);
            return 0;
        }
    }



    return 0;
}