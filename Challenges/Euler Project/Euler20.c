#include <stdlib.h>
#include <stdio.h>
#define MAX_DIGITS 200

typedef struct _numero
{
    int n_digit;
    int d[MAX_DIGITS];
}NUMERO;

NUMERO* transform(int n);
int checazero(NUMERO* num);
NUMERO* fatorial(int limite);
NUMERO* soma(NUMERO* num1, NUMERO* num2);
void initn(NUMERO** num);
void split(NUMERO* original,NUMERO* high, NUMERO* low, int tam);
NUMERO* karatsuba(NUMERO* num1, NUMERO* num2, int n);
void printnum(NUMERO num);
NUMERO* subt(NUMERO* num1, NUMERO* num2);

int main(void)
{
    int a,b,resultado;
    NUMERO *fat;
    resultado = 0;
    // puts("Insira 2 num pra multiplicar: ");
    // scanf("%d",&a);
    // scanf("%d",&b);

    // printnum(*karatsuba(transform(a),transform(b),0));

    puts("Insira o numero que vc quer o fatorial: ");
    scanf("%d",&a);
    
    fat = fatorial(a);

    printf("A soma dos digitos de ' %d! ' eh:  ",a);
    for(b=0;b<fat->n_digit;b++)
    {
        resultado+=fat->d[b];
    }
    printf("    %d",resultado);
}

NUMERO* transform(int n)
{
    int i,m=10,div;
    NUMERO* num;
    initn(&num);
    div = n;
    //calculando tamanho de int n
    for(i=0;i<10;i++)
    {
        num->d[i]= div%10;
        div = div/10;
        if(n%m==n)
        {
            num->n_digit = i+1;
            break;
        }
        m*=10;
    }
/*  printf("n digitos: %d\n",num.n_digit);
    for(i=num.n_digit-1;i>=0;i--)
    {
        printf(" %d ",num.d[i]);
    }
*/
   
    return num;
}

NUMERO* karatsuba(NUMERO* num1, NUMERO* num2, int n)
{
    int tam,i,j,k;
    NUMERO* high1, *high2, *low1, *low2, *result,*helper,*highs,*lows,*soma1,*soma2,*middle,*real_middle,*m;

    initn(&high1);
    initn(&low1);
    initn(&high2);
    initn(&low2);

    if(checazero(num1) || checazero(num2))
    {
        free(num1);
        free(num2);
        free(high1);
        free(low1);
        free(high2);
        free(low2);
        return transform(0);
    }
    
    if( (num1->n_digit==1) && (num2->n_digit==1) )   //caso seja um algarismo só
    {
        result = transform((num1->d[0] * num2->d[0]));
        free(num1);
        free(num2);
        free(high1);
        free(low1);
        free(high2);
        free(low2);
        return result;
    }
    

    // printf("            KARATSUBA:\n");
    // printnum(*num1);
    // printnum(*num2);

    //determinando tamanho das separações
    num1->n_digit>num2->n_digit? (tam = num1->n_digit) : (tam = num2->n_digit); 
    !(tam%2)? (tam = tam/2) : (tam = (tam/2) +1 );

    //separando numeros
    split(num1,high1,low1,tam);
    split(num2,high2,low2,tam);
    free(num1);
    free(num2);

    // //testes
    // printf("Membros     ");
    // printnum(*high1);
    // printnum(*low1);
    // printnum(*high2);
    // printnum(*low2);


    //somando membros
    soma1 = soma(high1, low1);
    soma2 = soma(high2, low2);
    

    //multiplicando membros
    m = karatsuba(soma1,soma2,0);

    // puts("produto da soma dos membros: ");
    // printnum(*middle);
 

    //subtraindo primeiros termos
    // if(n==60)
    // {
    //     printf("\n\nhigh1:");
    //     printnum(*high1);
    //     printf("\n\nhigh2:");
    //     printnum(*high2);
    //     puts("\n");
    // }
    highs = karatsuba(high1,high2,0);
    // puts("high member:");
    // printnum(*highs);
    // puts("chamando lows com low1 e low2=");
    // printnum(*low1);
    // printnum(*low2);
    lows = karatsuba(low1,low2,0);
    // puts("lows feito!\n");
    // printnum(*lows);


    helper = soma(highs,lows);
    // puts("subtrairemos:");
    // printnum(*helper);
    middle = subt(m,helper);
    // puts("meio:");
    // printnum(*middle);
    free(helper);
    free(m);

    // if(n==60)
    // {
    // printf("Produtos finais:\n"
    // "Tam: %d \n",tam);
    // printnum(*lows);
    // printf("^ low n digit: %d\n ",lows->n_digit);
    // printnum(*middle);
    
    // printf("^ mid n digit: %d\n ",middle->n_digit);
    // printnum(*highs);

    // printf("^ high n digit: %d \n",highs->n_digit);
    // }

    //alocar TAMs do lows no menos significativo,
    // criar um num = o que restou alem dos alocados, caso !=0
    initn(&result);
    initn(&helper);

    for(i=0;i<tam;i++)
    {
        result->d[i] = lows->d[i];
    }

    for(j=tam,k=0;j<lows->n_digit;j++,k++) //construindo a parte superior 1
    {
        helper->d[k] = lows->d[j];
    }

    for(j=tam+1;j>=0;j--) //determinando n de digitos do split superior 
    {
        if(helper->d[j]) break;
    }
    helper->n_digit=j+1;

    free(lows);

    // somar no middle, alocar TAMs igualmente, criar um num
    real_middle = soma(middle,helper);
    free(middle);
    free(helper);

    // puts("real mid:");
    // printnum(*real_middle);
    initn(&lows);
    for(j=0;j<tam;j++,i++)
    {
        result->d[i] = real_middle->d[j];
    }

    //construindo parte superior 2
    for(j=tam,k=0;j<real_middle->n_digit;j++,k++)
    {   
       // if(n==60) puts("\n              entrouu\n");
        lows->d[k]=real_middle->d[j];
    }

  

    
    for(j=tam+1;j>0;j--) //determinando n de digitos do split superior 
    {
        if(lows->d[j]) break;
    }
    lows->n_digit=j+1;

    // if(n==60)
    // {
    //     printf("\nparte superior 2 tem %d digitos e = ",lows->n_digit);
    //     printnum(*lows);
    //     puts("\n\n");
    // }

    free(real_middle);
    initn(&real_middle);
    // somar no high e alocar nos mais significativos
    real_middle = soma(lows,highs);
    //     if(n==60)
    // {
    //     printf("\nreal high tem %d digitos e = ",real_middle->n_digit);
    //     printnum(*real_middle);
    //     puts("\n\n");
    // }
    // puts("num final high:");
    // printnum(*real_middle);

    for(j=0;j<real_middle->n_digit;j++,i++)
    {
        result->d[i] = real_middle->d[j];
        // if(n==60) puts("botoukk");
    }

    for(i=(MAX_DIGITS-1);i>=0;i--)
    {
        if(result->d[i]) break;
    }
    result->n_digit=i+1;
    free(lows);
    free(real_middle);
    free(highs);
    return result;
}

void printnum(NUMERO num)
{
    int i;
    for(i=num.n_digit-1;i>=0;i--)
    {
        if(((i+1)%3)==1)
        {
            printf("%d ",num.d[i]);
        }
        else
        {
            printf("%d",num.d[i]);
        }
    }
}

void split(NUMERO* original,NUMERO* high, NUMERO* low, int tam)
{
    int i;

    high->n_digit = tam;
    low->n_digit = tam;

    for(i=0;i<tam;i++)
    {
        low->d[i]=original->d[i];
        high->d[i]=original->d[tam+i];
    }
}

void initn(NUMERO** num)
{
    int i;
    *num = malloc(sizeof(NUMERO));

    for(i=0;i<MAX_DIGITS;i++)
    {
        (*num)->d[i]=0;
    }
}

NUMERO* soma(NUMERO* num1, NUMERO* num2)
{
    NUMERO* resultado;
    int max,i,soma,carry;
    initn(&resultado);

    num1->n_digit > num2->n_digit? (max=num1->n_digit) : (max=num2->n_digit);

    carry=0;
    
    for(i=0;i<max;i++)
    {
        soma = num1->d[i] + num2->d[i] + carry;
        // if(carry)
        // {
        //     puts("carry!");
        // }
        resultado->d[i] = soma%10;

        if( (soma%10)<soma )   // se tiver carry
        {
            carry=1;
        }
        else carry=0;
    }

    if(carry)
    {
        resultado->d[i++]=1;
    }

    resultado->n_digit = i;
    return resultado;
}

NUMERO* subt(NUMERO* num1, NUMERO* num2)
{
    NUMERO* resultado;
    int max,i,soma,teste;
    initn(&resultado);

    num1->n_digit > num2->n_digit? (max=num1->n_digit) : (max=num2->n_digit);
    
    for(i=0;i<max;i++)
    {
        soma = num1->d[i] + (-1 * num2->d[i]);
        resultado->d[i] = soma;
    }

    teste = 0;

    for(i=max-1;i>=0;i--)
    {
        if(teste==0)
        {
            if(resultado->d[i]<0) teste = 1; //subtraiu menor - maior
            else if (resultado->d[i]>0) teste = 2 ;
        }
        if(teste==2) break;
        
        if(teste==1)
        {
            resultado->d[i]*=-1;
        }
    }
    // puts("\n inversos 2:\n");
    // for(i=max-1;i>=0;i--)
    // {
    //     printf(" %d ",resultado->d[i]);
    // }
    // puts("\n");
    for(i=max-1;i>0;i--)
    {
        if(resultado->d[i-1]<0)
        {
            resultado->d[i]--;

            resultado->d[i-1]+=10;
            i+=2;
        }
    }
    for(i=max-1;i>=0;i--)
    {
        if(resultado->d[i]!=0) break;
    }
    resultado->n_digit = i+1;
   
    return resultado;
}

NUMERO* fatorial(int limite)
{
    NUMERO *resultado, *transformado;
    int i;
    resultado = transform(1);
    for(i=2;i<=limite;i++)
    {
        printf("fatorial de %d = ",i);
        
        transformado = transform(i);
        resultado = karatsuba(resultado,transformado,i);
        
       
        printnum(*resultado); puts("\n");
    }
    puts("\n\n");
    return resultado;
}

int checazero(NUMERO* num)
{
    int i,check;

    check=0;

    for(i=0;i<MAX_DIGITS;i++)
    {
        if(num->d[i]) check = 1;
        if(check) return 0;
    }
    return 1;
}

