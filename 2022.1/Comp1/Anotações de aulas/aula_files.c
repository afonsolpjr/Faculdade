#include <stdio.h>
#include <stdlib.h>

FILE *pa;


void teste_eof(void)
{
  char c;

  c= getchar();
  while(c != EOF && c != '0')
  {
    putchar(c);
    c=getchar();
  }
}

void open_file(void)
{
  char c;
  char nome[50],modo[3];
  puts("Insira o nome do arquivo:");

  scanf("%s",nome);
  puts("Insira o modo de leitura/escrita\n");
  scanf("%s",modo);
  pa = fopen(nome,modo);


  if(pa==NULL)
  {
    puts("\nArquivo nao pode ser aberto.\n");
    exit(1);
  }


}

void teste_feof(void)
{
  char c;

  c=getchar();
  while(!feof(stdin) && c!='0')
  {
    putchar(c);
    c=getchar();
  }

}

void fecha_arquivo(void)
{
  fclose(pa);
  puts("Arquivo fechado.\n");
}

void edit_arquivo(void)
{
  char c=0;

  c=getchar();
  while(c!='\n')
  {
    fputc(c,pa);
    c = getchar();
  }
  fputc('\n',pa);

  puts("Terminando escrita.\n Lendo:\n");

  rewind(pa);

  while(c!=EOF)
  {
    putchar(c);
    c=fgetc(pa);
  }
  putchar('\n');
}

void ler_arquivo(void)
{
  char c;
  rewind(pa);

  while(!feof(pa))
  {
    c=fgetc(pa);
    putchar(c);
  }
  putchar('\n');
}

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
  while((lixo=getchar()) != EOF && lixo!= '\n'){}

	return valor;
}

int main(void)
{
  int opcao=-1;


  while(opcao!=0)
  {


    puts("\nTestes: \n"
    "[1]Teste EOF\n"
    "[2]Abrir arquivo p escrita\n"
    "[3] Teste FEOF\n"
    "[4]Fechar arquivo\n"
    "[5]Edita conteudo\n"
    "[6] Ler arquivo\n");

    opcao = valida_int();

    switch(opcao)
    {
      case 1:
      teste_eof();

      break;

      case 2:
      open_file();
      break;

      case 3:
      teste_feof();
      break;

      case 4:
      fecha_arquivo();
      break;

      case 5:
      edit_arquivo();
      break;

      case 6:
      ler_arquivo();
      break;
    }
  }

    return 0;
}
