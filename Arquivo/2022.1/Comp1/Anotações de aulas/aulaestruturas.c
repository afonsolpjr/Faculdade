#include <stdio.h>
#include <string.h>
#include <stdlib.h>

  struct DATA{
    int dia,mes,ano;
  };

  typedef struct _ALUNO
  {
    char nome[40];
    int registro;
    int ano_entrada;
    char curso[20];
    struct DATA data_nascimento;
  } ALUNO;

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
	return valor;
}

void print_aluno(ALUNO *aluno);
void print_alunos(ALUNO *alunos,int qtd_alunos);
int main(void)
{
  int qtd_alunos,i;

  ALUNO *alunos;

  // afonso.ano_entrada = 2022;
  // strcpy(afonso.nome,"Afonso Lustosa");
  // afonso.data_nascimento.mes=8;
  // afonso.data_nascimento.dia=19;
  // afonso.data_nascimento.ano=1996;
  // afonso.registro=122079084;
  // strcpy(afonso.curso, "C. da Computacao");

  // afonso_2=afonso;
  //
  // print_aluno(&afonso);
  //
  // print_aluno(&afonso_2);
  //
  // fulano = &fulani;
  //
  //
  // strcpy(fulano->nome,"Fulano da Silva");
  // fulano->ano_entrada=2010;
  // fulano->data_nascimento.mes=1;
  // fulano->data_nascimento.dia=1;
  // fulano->data_nascimento.ano=1990;
  // fulano->registro=111222333;
  // strcpy(fulano->curso, "Necas de pitibiribas");
  //
  // print_aluno(fulano);


  // TESTANDO CRIAÇAO DE ESTRUTURAS POR VETORES
  puts("Insira a quantidade de alunos:");
  qtd_alunos=valida_int();

  alunos = (ALUNO*)malloc(qtd_alunos*sizeof(ALUNO));

  for(i=0;i<qtd_alunos;i++)
  {
    puts("[*~*~*~*~NOVO ALUNO*~*~*~*~*~]\n");
    puts("\nInsira o nome do aluno:");
    scanf("%s",alunos[i].nome);

    puts("\nInsira o curso do aluno:");
    scanf("%s",alunos[i].curso);

    puts("\nInsira o registro do aluno:");
    alunos[i].registro=valida_int();

    puts("\nInsira o ano de entrada do aluno:");
    alunos[i].ano_entrada=valida_int();

    puts("\nInsira o dia de nascimento do aluno:");
    alunos[i].data_nascimento.dia=valida_int();

    puts("\nInsira o mes de nascimento do aluno:");
    alunos[i].data_nascimento.mes=valida_int();

    puts("\nInsira o ano de nascimento do aluno:");
    alunos[i].data_nascimento.ano=valida_int();
  }

  print_alunos(alunos,qtd_alunos);
  return 0;

}

void print_aluno(ALUNO *aluno)
{
  printf("\n Nome: %s\n"
  "Registro: %d\n"
  "Ano de entrada: %d\n"
  "Curso: %s\n"
  "Nascimento: %d/%d/%d\n",
  aluno->nome,aluno->registro,aluno->ano_entrada,aluno->curso,
  aluno->data_nascimento.dia,aluno->data_nascimento.mes,aluno->data_nascimento.ano);
}


void print_alunos(ALUNO *alunos,int qtd_alunos)
{
  int i;
  ALUNO *aluno;
  for(i=0;i<qtd_alunos;i++)
  {
    aluno=(alunos+i);
    printf("\n Nome: %s\n"
    "Registro: %d\n"
    "Ano de entrada: %d\n"
    "Curso: %s\n"
    "Nascimento: %d/%d/%d\n",
    aluno->nome,aluno->registro,aluno->ano_entrada,aluno->curso,
    aluno->data_nascimento.dia,aluno->data_nascimento.mes,aluno->data_nascimento.ano);
  }

}
