/* FUncoes uteis*/
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

float valida_float(void)
{
	int valido,lixo;
	float valor;
	valido=scanf("%f",&valor);
        while(valido==0)
        {
            while((lixo=getchar()) != EOF && lixo!= '\n');
            puts("\nInsira um valor válido: ");
            valido=scanf("%f",&valor);
        }
	while((lixo=getchar()) != EOF && lixo!= '\n');
	return valor;
}


void print_vetor(int vetor[TAMANHO]) //PRINTA VETORES
{
    int i;
    for(i=0;i<TAMANHO;i++)
    {
        printf("  [%d]  ",vetor[i]);
    }
}


int tam_str(char str[500])    //RETORNA TAMANHO DE STRING
{
	int i,tamanho=0;
	for(i=0;i<500;i++)
	{
		if(str[i]!='\0')
		{
			tamanho++;
		}
		else
		{
			tamanho++;
			break;
		}
	}

	return tamanho;
}




	for(i=0;i<5;i++)   // MULTIPLICANDO VETORES 5X5
	{
		for(j=0;j<5;j++)
		{
            somaprod=0;
			for(k=0;k<5;k++)
            {
                somaprod+=matriz1[i][k]*matriz2[k][j];
                produto[i][j]=somaprod;
            }
		}
	}




void le_vetor(int *vetor, int tam)       //le vetores
{
    int i;
    for ( i = 0; i < tam; i++)
    {
        *(vetor+i)= valida_int();
    }

}


potencia(int base,int exp)
{
	int i,n=base;
	for(i=0;i<exp-1;i++)
	{
		n*=base;
	}

	return n;
}

float qse_raiz(long int n)  //quase a raiz kk
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


void insere_lista( /*tipo da struct  **ultimo_no */ )
{
		TIPO *p_novo;

		if( ( p_novo = (TIPO*)malloc( sizeof(TIPO) ) ) == NULL)
		{
			puts("Sem memoria.\n");
			exit (1);
		}

		p_novo->p_prox = NULL;
		(*ultimo_no)->p_prox = p_novo;
		*ultimo_no = p_novo;

}

STRUCT_TIPO* cria_lista( /*tipo da struct  **p_head */ )
{
		TIPO *ultimo_no;

		if( ( *p_head = (TIPO*)malloc( sizeof(TIPO) ) ) == NULL)
		{
			puts("Sem memoria.\n");
			exit (1);
		}

		p_head->p_prox = NULL;
		ultimo_no = *p_head;

		return ultimo_no;
}


void le_string(char *string,int tam)
{
  int i;
  char c;

  for(i=0;i<tam-1;i++)
  {
    if((c=getchar())!= EOF && c!='\n')
    {
      string[i]=c;
    }
    else break;
  }
  string[i]='\0';
}


while(opcao!=0)                  //prototipo menu
  {
    puts("\nSelecione a operacao desejada:\n"
    "[1] \n"
    "[2] \n"
    "[3] \n"
    "[4] \n"
    "[5] \n"
    "[6] \n"
    "Ou [0] para sair.\n");

    opcao=valida_int();
    switch (opcao)
    {
      case 1:
        
        break;

      case 2:
        

      case 3:
        
        break;

      case 4:
        
        break;

      case 5:

        
        break;

      case 6:
       

        break;

      default: break;
    }
  }