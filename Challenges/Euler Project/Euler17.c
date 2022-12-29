#include <stdlib.h>
#include <stdio.h>


int main(void)
{
    int n,i,mod,num[3],diff,total;

    total = 0;
    diff=0;

    for(n=1;n<1001;n++)
    {
        for(i=0;i<3;i++) // fazendo o vetor do num
        {
            switch(i)
            {
                case 0: mod = 10; break;

                case 1: mod = 100; break;

                case 2: mod = 1000; break;
            }

            num[i] = (n%mod) / (mod/10);
        }
        //printf(" O vetor no num= %d ficou assim:  %d %d %d\n",n,num[2],num[1],num[0]);

        
            //calculando numero de letras 

        if( (n%100>9) && (n%100<20)  )
        {   // ten eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen 
            diff=1;
           // puts("diferente");
            switch(n%100)
            {
                case 10:
                total+=3;
                break;

                case 11: case 12:
                total+=6;
                break;

                case 13: case 14: case 19: case 18:
                total+=8;
                break;

                case 15: case 16:
                total+=7;
                break;

                case 17:
                total+=9;
                break;
            }

        }
        for(i=0;i<3;i++)
        {
            if( i==0 && !diff )  //se for casa da unidade  e n ser caso diferente
            {
                switch(num[i])
                {   // one two three four five six seven eight nine
                    case 1: case 2: case 6:
                    total+=3;
                    break;

                    case 4: case 5: case 9:
                    total+=4;
                    break;

                    case 3: case 7: case 8:
                    total+=5;
                    break;
                }
            }
            else if( i==1 && !diff ) // casa dzena  e n ser caso diferente
            {
                switch(num[i])
                {   //twenty thirty forty fifty sixty seventy eighty ninety

                    case 2: case 3: case 8: case 9:
                    total+=6;
                    break;

                    case 5: case 6: case 4:
                    total+=5; 
                    break;

                    case 7:
                    total+=7;
                    break;
                }
            }
            else if(i==2)
            {
                switch(num[i])
                {   // one two three four five six seven eight nine
                    // + hundred 
                    case 1: case 2: case 6:
                    total+=(3+7);
                    break;

                    case 4: case 5: case 9:
                    total+=(4+7);
                    break;

                    case 3: case 7: case 8:
                    total+=(5+7);
                    break;
                }
            }
            
        }
        
        if( (num[0]!=0 || num[1]!=0) && num[2]!=0 ) //colocar o and
        {
            total+=3;
        }

        diff=0;
        if(n==1000)
        {   //one thousand
            total+=11;
        }
       // printf("total ate agr:%d\n",total);
    }
    printf("\nMano o resultado deu: %d\n",total);
    return 0;
}