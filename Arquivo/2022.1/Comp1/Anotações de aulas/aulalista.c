#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DATA{
  int dia,mes,ano;
};

typedef struct _ALUNO
{
  char nome[40];
  char curso[40];
  struct DATA data_entrada;
  struct _ALUNO *p_aluno;
} ALUNO;

void teste_1(ALUNO **p_head);

void teste_2(ALUNO *p_head,ALUNO **ultimo_no);

void teste_3(ALUNO **ultimo_no);

void printa_lista(ALUNO *p_head);

void pergunta_aluno(ALUNO *aluno);

int valida_int(void)
{
	int valido,lixo,valor;
	valido=scanf("%d",&valor);
        while(valido==0)
        {
            while((lixo=getchar()) != EOF && lixo!= '\n');
            puts("\nInsira um valor válido: ");
            valido=scanf("%d",&valor);
        }
	return valor;
}

int main(void)
{
  int opcao=-1;
  while(opcao!=0)
  {
    ALUNO *p_head,*ultimo_no;

    puts("\nTestes: \n"
    "[1]Criar a lista (cabeca)\n"
    "[2]Criar segundo elemento\n"
    "[3]Criar mais um elemento\n"
    "[4]PRintar lista inteira\n");

    opcao = valida_int();

    switch(opcao)
    {
      case 1:
      teste_1(&p_head);

      break;

      case 2:
      teste_2(p_head,&ultimo_no);
      break;

      case 3:
      teste_3(&ultimo_no);
      break;

      case 4:
      printa_lista(p_head);
      break;
    }
  }



  return 0;
}

void teste_1(ALUNO **p_head)
{

  if( ( *p_head = (ALUNO*)malloc( sizeof(ALUNO) ) ) == NULL)
  {
    puts("Sem memoria para criar aluno");
    exit (1);
  }

  (*p_head)->p_aluno = NULL;
  pergunta_aluno(*p_head);


}

void teste_2(ALUNO *p_head, ALUNO **ultimo_no)
{
  ALUNO *p_novo;
  /* criamos o proximo aluno sem liga-lo a head, de começo*/
  if( (p_novo= (ALUNO*) malloc( sizeof(ALUNO) )) == NULL)
  {
    puts("Sem memoria para criar aluno");
    exit (1);
  }

  p_novo->p_aluno = NULL;
  p_head->p_aluno = p_novo;
  *ultimo_no = p_novo;
  pergunta_aluno(*ultimo_no);

}

void teste_3(ALUNO **ultimo_no)
{
  ALUNO *p_novo;

  if( (p_novo= (ALUNO*) malloc( sizeof(ALUNO) )) == NULL)
  {
    puts("Sem memoria para criar aluno");
    exit(1);
  }

  p_novo->p_aluno = NULL;
  (*ultimo_no)->p_aluno = p_novo;
  *ultimo_no=p_novo;

  pergunta_aluno(*ultimo_no);
}

void printa_lista(ALUNO *aluno)
{
  int i;
  for(i=1;;i++)
  {
    printf("\nAluno %d: %s \n"
    "Curso: %s\n"
    "Data Entrada: %02d/%02d/%d \n\n"
    ,i,aluno->nome,aluno->curso,aluno->data_entrada.dia,
    aluno->data_entrada.mes,aluno->data_entrada.ano);

    if( aluno->p_aluno == NULL)
    {
      break;
    }
    else
    {
      aluno = aluno->p_aluno;
    }
  }


}

void pergunta_aluno(ALUNO *aluno)
{
    char string[40];
    int data;

    puts("\n Insira o nome do aluno:");
    scanf("%s",string);
    strcpy(aluno->nome,string);

    puts("\n Insira o curso do aluno:");
    scanf("%s",string);
    strcpy(aluno->curso,string);

    puts("\n Insira dia de entrada:");
    data =valida_int();
    aluno->data_entrada.dia = data;


    puts("\n Insira mes de entrada:");
    data =valida_int();
    aluno->data_entrada.mes = data;


    puts("\n Insira ano de entrada:");
    data =valida_int();
    aluno->data_entrada.ano = data;



}
