#include <stdio.h>
#include <stdlib.h>
/* Eu ja tinha todas essas funççoes prontas de outro trabalho. 21/12/2022 */

long int soma_divisores(long int a);
long int* fatoracao_com_repeticao(long int a);
long int* fatoracao_sem_repeticao(long int a);
float raiz(long int n);
long int potencia(long int base,int exp);
long int* calcula_abundantes(long int *tam);

int main(void)
{

    //pegar todos numeros abundantes ate 28123 +/-

    // fazer uma combinação de todos, e ver quais numeros não aparecem


    long int *abundante, tam, i, *inexp, k, j,tam_inexp,resultado;
    
    tam_inexp = 23;
    inexp = calloc(tam_inexp,sizeof(long int));         //numeros inexpressiveis como soma de 2 abundantes, todos até 23, pelo menos.

    for(i=1;i<24;i++) inexp[i]=i;

    abundante = calcula_abundantes(&tam);
    

    //for(i=0;i<tam;i++) printf("Abundante %ld:  %ld\n",i,abundante[i]);

    for(i=23;i<=28123;i++)
    { 
        for(k=0;k<tam;k++)
        {
            if(abundante[k]>i)
            {
                if((inexp = realloc(inexp,(++tam_inexp)*sizeof(long)))==NULL)
                {
                    puts("problema alocando memoria");
                    return -1;
                }
                inexp[tam_inexp-1]=i;    
               
                //printf("\t\t\t\tO numero %ld nao pode ser expresso como a soma de dois abundantes!!\n",i);
                
                break;
            }

            j=0;
            while( (abundante[k] + abundante[j+k]) < i )
            {

                // printf( "Testando para [i=%ld] -> %ld + %ld \n"
                // ,i,abundante[k],abundante[j+k]);
                
                j++;
            }

            if(i == abundante[k] + abundante[j+k])
            {
                // printf("O num %ld pode ser expresso como a soma de dois abundantes: %ld + %ld\n"
                // ,i,abundante[k],abundante[j]);
                break;
            }
           


        }
        
       
        

    }
    resultado=0;
    for(i=0;i<tam_inexp;i++)
    {
        resultado+=inexp[i];
    }

    printf("Resultado = %ld",resultado);
    


    return 0;
}


long int* calcula_abundantes(long int *tam)
{
    long int i,*abundante;
    *tam = 1;
    if((abundante = (long int*) calloc((*tam),sizeof(long int)))==NULL)
            {
                puts("\n\nproblema ao alocar memoria.\n\n");
                return 0;
            }

    for(i=1;i<=28123;i++)
    {   
        
        if(i<soma_divisores(i)) //se abundante
        {
            if((abundante = (long int*) realloc(abundante,((*tam)++)*sizeof(long int)))==NULL)
            {
                puts("\n\nproblema ao alocar memoria.\n\n");
                return 0;
            }

            abundante[*tam-2] = i;
        }
    }


    return abundante;
}




long int soma_divisores(long int a)
{
	long int *distintos,*repetidos,*expoentes,conta=0;
	long int i,j,k,*soma_pg;

	distintos = fatoracao_sem_repeticao(a);
	repetidos = fatoracao_com_repeticao(a);

	expoentes = calloc(distintos[0]-1,sizeof(int));
	soma_pg = calloc(distintos[0]-1,sizeof(int));

	for(k=0,i=1;i<distintos[0];i++,k++)
	{
		conta=0;
		for(j=1;j<repetidos[0];j++)
		{
			distintos[i]==repetidos[j]? conta++ : 0;
		}
		expoentes[k]=conta+1;
	}


	//armazenando a soma da pg onde (razao=fator primo, termos = n_expoentes, 1o termo=1) para cada fator primo EM soma_pg
	
	// print_vetor(distintos,distintos[0]);
	// for(i=0;i<distintos[0]-1;i++)
	// {
	// 	printf("\no expoente de %d é = %d",distintos[i+1],expoentes[i]-1);
	// }

	for ( i=1,j=0; i < distintos[0]; i++,j++)
	{
		soma_pg[j]= ( potencia(distintos[i],expoentes[j]) - 1 ) / ( distintos[i] - 1);
	}
	j=1;
	for(i=0;i<distintos[0]-1;i++)
	{
		j=j*soma_pg[i];
	}

	return (j-a);
}
/* a funçao a seguir retorna um ponteiro para uma array dinamico com todos os fatores primos REPETIDOS de "a".
	ESSENCIAL: o indice 0 armazena um inteiro com o tamanho do array.
	Ou seja, o numero de fatores distintos será p[0]-1
	e a partir de p[1] temos os fatores. */
long int* fatoracao_com_repeticao(long int a)
{
	long int i,n,*lista,tam=1;
	n=a;
	float rz=raiz(a);

	lista = calloc(1,sizeof(long int));
	lista[0]=1;

	for(i=2;i<=rz;i++)
	{
		while(n%i==0)
		{
			tam++;
			lista = realloc(lista,tam*(sizeof(long int)));
			lista[0]=tam;
			lista[tam-1]=i;
			n=n/i;
			rz=raiz(n);
		}
	}
	if(n!=1)
	{
	tam++;
	lista = realloc(lista,tam*(sizeof(long int)));
	lista[0]=tam;
	lista[tam-1]=n;
	}


	return lista;


}
/* a funçao a seguir retorna um ponteiro para uma array dinamico com todos os fatores primos DISTINTOS de "a".
	ESSENCIAL: o indice 0 armazena um inteiro com o tamanho do array.
	Ou seja, o numero de fatores distintos será p[0]-1
	e a partir de p[1] temos os fatores. */
long int* fatoracao_sem_repeticao(long int a)
{
	long int i,n,*lista,tam=1;
	n=a;
	float rz=raiz(a);

	lista = calloc(1,sizeof(long int));
	lista[0]=1;

	for(i=2;i<=rz;i++)
	{
		if(n%i==0)
		{
			tam++;
			lista = realloc(lista,tam*(sizeof(long int)));
			lista[0]=tam;
			lista[tam-1]=i;
			while(n%i==0) n=n/i;
			rz=raiz(n);
		}
	}
	if(n!=1)
	{
	tam++;
	lista = realloc(lista,tam*(sizeof(long int)));
	lista[0]=tam;
	lista[tam-1]=n;
	}


	return lista;


}

float raiz(long int n)
{
	long int sup,inf,usa;
	float qse_raiz;
	for(sup=0;;sup++)
	{
		if(sup*sup>n) break;
	}
	inf=sup-1;
	(sup*sup)-n>n-(inf*inf)?(usa=inf):(usa=sup);
	qse_raiz=(((n+(usa*usa))*1.0)/(2*usa));
	return qse_raiz;
}

long int potencia(long int base,int exp)
{
	int i,n=base;
	for(i=0;i<exp-1;i++)
	{
		n*=base;
	}

	return n;
}
