#include <stdio.h>
#include <gmp.h>
#include <stdlib.h>

int valida_int(void);
void teste1(void);
int teste_fermat(mpz_t numero, int base_i);

void teste2(void);
int teste_car(mpz_t numero);
void exibir_pseudoprimos(void);
void teste3();
int miller_rabin(mpz_t numero,int base_i);

int main (void)
{
    int opcao=-12;
    
    while(opcao!=0)
    {
        puts("\n\nQual operacao kkkkkkkkkkkkkk deseja?\n\n"
        "[1] Teste de fermat, inserindo o numero e base a ser testada.\n"
        "[2] Testa se numero dado é primo ou carmichael.\n"
        "[3] TEste de Miller-Rabin para o numero dado.\n"
        "[4] EXibe pseudoprimos para o numero dado.\n");
        opcao=valida_int();
        switch(opcao)
        {
            case 1:
            teste1();
            break;

            case 2:
            teste2();
            break;

            case 3:
            teste3();
            break;

            case 4:
            exibir_pseudoprimos();
            break;
        }
    }
        return 0;
        

}

void teste1(void)
{
    int opcao=-1, base;
    mpz_t numero;
    mpz_init(numero);
    puts("\n\nInsira o numero que deseja checar se é composto:");
    gmp_scanf("%Zd",numero);

    puts("\n\nInsira a base que deseja testar:");

    base = valida_int();

    while(opcao!=0)
    {
        if(teste_fermat(numero,base))
        {
            gmp_printf("\n\t\t\t\t\t\t\t\tO numero %Zd é pseudoprimo para a base %d\n\n"
            "Deseja testar outra base? Insira-a, ou 0 para cancelar.\n",numero,base);
            base=valida_int();
            opcao=base;
            
            
        }
        else
        {
            gmp_printf("\n\t\t\t\t\t\t\t\tO numero %Zd é composto\n\n",numero);
            opcao=0;
   
        }
    }

}

int teste_fermat(mpz_t numero, int base_i)
{
    mpz_t modulo,base,exp;
    mpz_init(modulo);
    mpz_init(exp);
    mpz_init_set_ui(base,base_i);
    mpz_sub_ui(exp,numero,1);
    mpz_powm(modulo,base,exp,numero);

    if(!mpz_cmp_ui(modulo,1)) // caso seja pseudoprimo a base
    {
        return 1;
    }
    return 0;
}
int valida_int(void)        //VALIDA INTEIROS
{
	int valido,lixo,valor;
	valido=scanf("%d",&valor);
        while(valido==0)
        {
            while((lixo=getchar()) != EOF && lixo!= '\n');
            puts("\nInsira um valor válido: ");
            valido=scanf("%d",&valor);
        }
	while((lixo=getchar()) != EOF && lixo!= '\n');
	return valor;
}
void teste2()
{
    mpz_t numero;
    mpz_init(numero);
    puts("\nInsira o numero a testar primalidade/carmichael:");

    gmp_scanf("%Zd",numero);

    if(teste_car(numero))
    {
        puts("\n\t\t\t\t\t\t\t\tO numero é composto e não-carmichael.\n");
    }
    else
    {
        puts("\t\t\t\t\t\t\t\t O numero é primo ou carmichael!");
    }

}
int teste_car(mpz_t numero)
{
    mpz_t iterador,modulo,limite;

    mpz_init_set_ui(iterador,2);
    mpz_init(modulo);
    mpz_init(limite);
    mpz_sub_ui(limite,numero,1);

    while(mpz_cmp(iterador,limite)<0)
    {
        gmp_printf("Testando com a base %Zd....\n",iterador);
        mpz_powm(modulo,iterador,numero,numero);

        if(mpz_cmp(modulo,iterador)) // se o modulo e diferente da base(iterador)
        {
            return 1;
        }
        mpz_add_ui(iterador,iterador,1);
    }
    return 0;
}

void teste3()
{
    int base,opcao=-1;
    mpz_t numero;
    mpz_init(numero);

    puts("\n\nQual numero deseja testar?");
    gmp_scanf("%Zd",numero);

    puts("\n\nCom qual base?");
    base = valida_int();
    while(opcao!=0)
    {
        if(miller_rabin(numero,base))
        {
            gmp_printf("\t\t\t\t\t\t\t\t\t"
            "O Numero %Zd é composto.\n",numero);
            break;
        }
        else
        {
            gmp_printf("\t\t\t\t\t\t\t\t\t"
            "O numero %Zd é pseudoprimo forte para a base %d \n"
            "Deseja testar outra base? Insira-a ou 0 para cancelar.\n",numero,base);
            base=valida_int();
            opcao = base;
        }
    }
}

int miller_rabin(mpz_t numero,int base_i)
{
    mpz_t limite,k,modulo,par,q,i,base;
    mpz_init_set_ui(i,0);
    mpz_init(modulo);
    mpz_init(k);
    mpz_set_ui(k,0);
    mpz_init(q);

    mpz_init(limite);
    mpz_sub_ui(limite,numero,1);
    mpz_init_set(par,limite);

    mpz_init_set_ui(base,base_i);

    while(1)
    {
        if(mpz_even_p(par))
        {
            mpz_add_ui(k,k,1);
            mpz_fdiv_q_ui(par,par,2);
        }
        else break;
    } // pegar q e k
    mpz_set(q,par);
    mpz_powm(modulo,base,q,numero);

    // gmp_printf("TEmos q=%Zd e k=%Zd\n"
    // "i=%Zd e modulo=%Zd\n",q,k,i,modulo);

    while(mpz_cmp(i,k))
    {
        if( (!mpz_cmp_ui(i,0) && !mpz_cmp_si(modulo,1)) || ( mpz_cmp_si(i,0) && !mpz_cmp(modulo,limite) ))
        {
            return 0; // se pseudoprimo forte a base
        }
        mpz_add_ui(i,i,1);
        mpz_pow_ui(q,modulo,2);
        mpz_mod(modulo,q,numero);


    }
    return 1; // se composto


}
void exibir_pseudoprimos()
{
    int base,n,i;
    mpz_t candidato;
    mpz_init(candidato);

    puts("\n\n Deseja pseudoprimos para qual base?");
    base = valida_int();

    mpz_set_ui(candidato,base+2);
    puts("QUantos pseudoprimos?");
    n = valida_int();

    for(i=0;i<n;i++)
    {
        while(!teste_fermat(candidato,base) || mpz_probab_prime_p(candidato,30))
        {
            mpz_add_ui(candidato,candidato,1);
        }
        gmp_printf("\t\t\t\t\t\t\t\t O numero %Zd é pseudoprimo para %d\n",candidato,base);
        if(!miller_rabin(candidato,base))
        {
            puts("\t\t\t\t\t\t\t\t\tE é forte também.");
        }

        mpz_add_ui(candidato,candidato,1);
    }

    
}

