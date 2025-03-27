/*AFONSO LUSTOSA PIRES JUNIOR - DRE: 122079084

Olá, os programas seguem na mesma organização que fiz em algumas listas anteriores.


-Todos os Exercicios estão como funções.
-Há um menu para escolha do exerćicio.
-Comentários contendo saídas dos exercicios estão abaixo das declarações de seus protótipos.

-Estruturas usadas estão declaradas antes dos protótipos!


        IMPORTANTE!!!!!

O Exercicio 1 não roda direito no Windows.
Eu o fiz e testei no LINUX (manjaro), e está rodando perfeitamente.
Não sei o porquê disto, mas desconfio que seja algum problema
na definicao de EOF no windows. para os outros programas, usei outra maneira
de determinar o fim do arquivo.
Grato!
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _ANIVERSARIO{
  int dia,mes;
}ANIVERSARIO;

typedef struct _CONTATO
{
  char nome[40];
  char telefone[20];
  ANIVERSARIO data_aniversario;
  struct _CONTATO* p_contato;
}CONTATO;


typedef struct _VENDA{
  int cod_vendedor;
  char nome_vendedor[50];
  int valor_da_venda,mes;
}VENDA;





int valida_int(void);
void le_string(char *string,int tam);


/*
[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*]

                   Exercicio 1 - Agenda


Arquivo de agenda criado!


Selecione a operacao desejada:
[1] Inserir Contato
[2] Remover Contato
[3] Pesquisar contato pelo nome
[4] Listar todos os contatos
[5] Listar todos os contatos que começam com uma letra especifica
[6] Mostrar aniversariantes do mes
Ou [0] para sair e SALVAR agenda.

1


[*~*~*~*~*] Inserir Contato [*~*~*~*~*]



Insira o nome do contato:
Afonso

Insira o telefone:
21 981377240

Insira o dia do aniversario:
19

Insira o mes do aniversario:
8


[*~*~*~*~*] Contato Inserido [*~*~*~*~*]



Selecione a operacao desejada:
[1] Inserir Contato
[2] Remover Contato
[3] Pesquisar contato pelo nome
[4] Listar todos os contatos
[5] Listar todos os contatos que começam com uma letra especifica
[6] Mostrar aniversariantes do mes
Ou [0] para sair e SALVAR agenda.

1


[*~*~*~*~*] Inserir Contato [*~*~*~*~*]



Insira o nome do contato:
Fulano

Insira o telefone:
21 999999999

Insira o dia do aniversario:
1

Insira o mes do aniversario:
1


[*~*~*~*~*] Contato Inserido [*~*~*~*~*]



Selecione a operacao desejada:
[1] Inserir Contato
[2] Remover Contato
[3] Pesquisar contato pelo nome
[4] Listar todos os contatos
[5] Listar todos os contatos que começam com uma letra especifica
[6] Mostrar aniversariantes do mes
Ou [0] para sair e SALVAR agenda.

3


[*~*~*~*~*] Busca por nome [*~*~*~*~*]


Insira o nome a ser buscado:
Afonso


Nome: Afonso
Telefone: 21 981377240
Aniversario: 19/8



[*~*~*~*~*] Fim da busca [*~*~*~*~*]



Selecione a operacao desejada:
[1] Inserir Contato
[2] Remover Contato
[3] Pesquisar contato pelo nome
[4] Listar todos os contatos
[5] Listar todos os contatos que começam com uma letra especifica
[6] Mostrar aniversariantes do mes
Ou [0] para sair e SALVAR agenda.

4


[*~*~*~*~*] Contatos [*~*~*~*~*]


Nome: Afonso
Telefone: 21 981377240
Aniversario: 19/8

Nome: Fulano
Telefone: 21 999999999
Aniversario: 1/1



[*~*~*~*~*] Fim da lista [*~*~*~*~*]



Selecione a operacao desejada:
[1] Inserir Contato
[2] Remover Contato
[3] Pesquisar contato pelo nome
[4] Listar todos os contatos
[5] Listar todos os contatos que começam com uma letra especifica
[6] Mostrar aniversariantes do mes
Ou [0] para sair e SALVAR agenda.

2


[*~*~*~*~*] Remover contato [*~*~*~*~*]


[1]: Afonso (21 981377240)
[2]: Fulano (21 999999999)

Escolha o contato a ser removido (ou 0 para sair):
0


[*~*~*~*~*] Fim da remocao [*~*~*~*~*]



Selecione a operacao desejada:
[1] Inserir Contato
[2] Remover Contato
[3] Pesquisar contato pelo nome
[4] Listar todos os contatos
[5] Listar todos os contatos que começam com uma letra especifica
[6] Mostrar aniversariantes do mes
Ou [0] para sair e SALVAR agenda.

1


[*~*~*~*~*] Inserir Contato [*~*~*~*~*]



Insira o nome do contato:
Adriano

Insira o telefone:
21 99999999

Insira o dia do aniversario:
1

Insira o mes do aniversario:
1


[*~*~*~*~*] Contato Inserido [*~*~*~*~*]



Selecione a operacao desejada:
[1] Inserir Contato
[2] Remover Contato
[3] Pesquisar contato pelo nome
[4] Listar todos os contatos
[5] Listar todos os contatos que começam com uma letra especifica
[6] Mostrar aniversariantes do mes
Ou [0] para sair e SALVAR agenda.

4


[*~*~*~*~*] Contatos [*~*~*~*~*]


Nome: Adriano
Telefone: 21 99999999
Aniversario: 1/1

Nome: Afonso
Telefone: 21 981377240
Aniversario: 19/8

Nome: Fulano
Telefone: 21 999999999
Aniversario: 1/1



[*~*~*~*~*] Fim da lista [*~*~*~*~*]



Selecione a operacao desejada:
[1] Inserir Contato
[2] Remover Contato
[3] Pesquisar contato pelo nome
[4] Listar todos os contatos
[5] Listar todos os contatos que começam com uma letra especifica
[6] Mostrar aniversariantes do mes
Ou [0] para sair e SALVAR agenda.

5


[*~*~*~*~*] Busca por letra [*~*~*~*~*]


Insira a letra inicial do contato:
a


Nome: Adriano
Telefone: 21 99999999
Aniversario: 1/1



Nome: Afonso
Telefone: 21 981377240
Aniversario: 19/8



[*~*~*~*~*] Fim da busca [*~*~*~*~*]



Selecione a operacao desejada:
[1] Inserir Contato
[2] Remover Contato
[3] Pesquisar contato pelo nome
[4] Listar todos os contatos
[5] Listar todos os contatos que começam com uma letra especifica
[6] Mostrar aniversariantes do mes
Ou [0] para sair e SALVAR agenda.

6


[*~*~*~*~*] Aniversariantes do mes [*~*~*~*~*]

Selecione o mes desejado:
[1]Janeiro              [7]Julho
[2]Fevereiro            [8]Agosto
[3]Marco                [9]Setembro
[4]Abril                [10]Outubro
[5]Maio                 [11]Novembro
[6]Junho                [12]Dezembro


1


Nome: Adriano
Telefone: 21 99999999
Aniversario: 1/1



Nome: Fulano
Telefone: 21 999999999
Aniversario: 1/1



[*~*~*~*~*] Fim da exibicao [*~*~*~*~*]



Selecione a operacao desejada:
[1] Inserir Contato
[2] Remover Contato
[3] Pesquisar contato pelo nome
[4] Listar todos os contatos
[5] Listar todos os contatos que começam com uma letra especifica
[6] Mostrar aniversariantes do mes
Ou [0] para sair e SALVAR agenda.

2


[*~*~*~*~*] Remover contato [*~*~*~*~*]


[1]: Adriano (21 99999999)
[2]: Afonso (21 981377240)
[3]: Fulano (21 999999999)

Escolha o contato a ser removido (ou 0 para sair):
2


[*~*~*~*~*] Fim da remocao [*~*~*~*~*]



Selecione a operacao desejada:
[1] Inserir Contato
[2] Remover Contato
[3] Pesquisar contato pelo nome
[4] Listar todos os contatos
[5] Listar todos os contatos que começam com uma letra especifica
[6] Mostrar aniversariantes do mes
Ou [0] para sair e SALVAR agenda.

4


[*~*~*~*~*] Contatos [*~*~*~*~*]


Nome: Adriano
Telefone: 21 99999999
Aniversario: 1/1

Nome: Fulano
Telefone: 21 999999999
Aniversario: 1/1



[*~*~*~*~*] Fim da lista [*~*~*~*~*]



Selecione a operacao desejada:
[1] Inserir Contato
[2] Remover Contato
[3] Pesquisar contato pelo nome
[4] Listar todos os contatos
[5] Listar todos os contatos que começam com uma letra especifica
[6] Mostrar aniversariantes do mes
Ou [0] para sair e SALVAR agenda.
 */
void exercicio_1(void);
void carregar_agenda(FILE **agenda,CONTATO **head);
void salvar_agenda(FILE *agenda,CONTATO *head);
void inserir_contato(CONTATO **p_head);
void listar_contatos(CONTATO *head);
void remover_contatos(CONTATO **head);
void busca_contato(char *c,CONTATO* head);
void busca_letra(char c,CONTATO* head);
void aniversariantes(int mes,CONTATO* head);


/*[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*]

                   Exercicio 2



Arquivo de saida gerado.
*/
void exercicio_2(char *entrada,char *saida);
char** carrega_entrada(char* entrada,int *n);
void salva_saida(char** linha,int n_linhas,char* saida);


/*
        [*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*]

                       LISTA 8
        AFONSO LUSTOSA PIRES JUNIOR - DRE:122079084

SELECIONE O EXERCICIO QUE VOCE DESEJA:
[1] Exercicio 1
[2] Exercicio 2
[3] Exercicio 3
[4] Exercicio 4
Ou [0] para sair do programa.
3


[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*]

                   Exercicio 3


Arquivo de vendas ainda nao existe. Por favor crie um.


      [MENU]

Selecione a operacao desejada:
[1] Criar arquivo de dados
[2] Incluir registro de venda/vendedor
[3] Deletar vendedor
[4] Alterar valor de uma venda
[5] Mostrar todos vendedores e vendas
[6] Excluir dados
Ou [0] para sair.

2

Por favor, crie o arquivo de dados.

Arquivo de vendas ainda nao existe. Por favor crie um.


      [MENU]

Selecione a operacao desejada:
[1] Criar arquivo de dados
[2] Incluir registro de venda/vendedor
[3] Deletar vendedor
[4] Alterar valor de uma venda
[5] Mostrar todos vendedores e vendas
[6] Excluir dados
Ou [0] para sair.

1
[*~*~*~*~*~*~*~*] Criar arquivo[*~*~*~*~*~*~*~*]

Arquivo vendas.bin criado!

[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~]


      [MENU]

Selecione a operacao desejada:
[1] Criar arquivo de dados
[2] Incluir registro de venda/vendedor
[3] Deletar vendedor
[4] Alterar valor de uma venda
[5] Mostrar todos vendedores e vendas
[6] Excluir dados
Ou [0] para sair.

2
[*~*~*~*~*~*~*] Inserir registro [*~*~*~*~*~*~*]

Primeiro registro!
O codigo de vendedor deve ser diferente de 0.


Codigo do vendedor:
1
Nome do vendedor:
Afonso
Mes de referencia:
[1]Janeiro              [7]Julho
[2]Fevereiro            [8]Agosto
[3]Marco                [9]Setembro
[4]Abril                [10]Outubro
[5]Maio                 [11]Novembro
[6]Junho                [12]Dezembro


1
Valor das vendas:
123
[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~]


      [MENU]

Selecione a operacao desejada:
[1] Criar arquivo de dados
[2] Incluir registro de venda/vendedor
[3] Deletar vendedor
[4] Alterar valor de uma venda
[5] Mostrar todos vendedores e vendas
[6] Excluir dados
Ou [0] para sair.

5
[*~*~*~*~*~*~*] Registros [*~*~*~*~*~*~*]


Codigo do vendedor:1
Mes:1
Nome:Afonso
Valor das vendas:R$ 123

[*~*~*~*~*~*~*~*~*~*~*~*~*~**~*~*~*~*~*~]


      [MENU]

Selecione a operacao desejada:
[1] Criar arquivo de dados
[2] Incluir registro de venda/vendedor
[3] Deletar vendedor
[4] Alterar valor de uma venda
[5] Mostrar todos vendedores e vendas
[6] Excluir dados
Ou [0] para sair.

2
[*~*~*~*~*~*~*] Inserir registro [*~*~*~*~*~*~*]

Digite o codigo do vendedor ou [0] para criar um novo.

0

Codigo do vendedor:
1
Codigo ja existente. Insira valor valido:

Codigo do vendedor:
2
Nome do vendedor:
Fulano
Mes de referencia:
[1]Janeiro              [7]Julho
[2]Fevereiro            [8]Agosto
[3]Marco                [9]Setembro
[4]Abril                [10]Outubro
[5]Maio                 [11]Novembro
[6]Junho                [12]Dezembro


1
Valor das vendas:
1230
[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~]


      [MENU]

Selecione a operacao desejada:
[1] Criar arquivo de dados
[2] Incluir registro de venda/vendedor
[3] Deletar vendedor
[4] Alterar valor de uma venda
[5] Mostrar todos vendedores e vendas
[6] Excluir dados
Ou [0] para sair.

5
[*~*~*~*~*~*~*] Registros [*~*~*~*~*~*~*]


Codigo do vendedor:1
Mes:1
Nome:Afonso
Valor das vendas:R$ 123

Codigo do vendedor:2
Mes:1
Nome:Fulano
Valor das vendas:R$ 1230

[*~*~*~*~*~*~*~*~*~*~*~*~*~**~*~*~*~*~*~]


      [MENU]

Selecione a operacao desejada:
[1] Criar arquivo de dados
[2] Incluir registro de venda/vendedor
[3] Deletar vendedor
[4] Alterar valor de uma venda
[5] Mostrar todos vendedores e vendas
[6] Excluir dados
Ou [0] para sair.

3
[*~*~*~*~*~*~*] Deletar vendedor [*~*~*~*~*~*~*]

Digite o codigo do vendedor ou [0] para sair.

2
[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~]


      [MENU]

Selecione a operacao desejada:
[1] Criar arquivo de dados
[2] Incluir registro de venda/vendedor
[3] Deletar vendedor
[4] Alterar valor de uma venda
[5] Mostrar todos vendedores e vendas
[6] Excluir dados
Ou [0] para sair.

5
[*~*~*~*~*~*~*] Registros [*~*~*~*~*~*~*]


Codigo do vendedor:1
Mes:1
Nome:Afonso
Valor das vendas:R$ 123

[*~*~*~*~*~*~*~*~*~*~*~*~*~**~*~*~*~*~*~]


      [MENU]

Selecione a operacao desejada:
[1] Criar arquivo de dados
[2] Incluir registro de venda/vendedor
[3] Deletar vendedor
[4] Alterar valor de uma venda
[5] Mostrar todos vendedores e vendas
[6] Excluir dados
Ou [0] para sair.

4
[*~*~*~*~*] Alterar valor de venda [*~*~*~*~*]

Digite o codigo do vendedor ou [0] para sair.

1
Meses registrados:

[1] Janeiro

Selecione o mes do registro a ser alterado:
1
        Registro selecionada:
Nome:Afonso
Codigo do vendedor: 1
Mes: 1
Valor: R$123
Insira o novo valor a ser registrado:
1000
[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~]


      [MENU]

Selecione a operacao desejada:
[1] Criar arquivo de dados
[2] Incluir registro de venda/vendedor
[3] Deletar vendedor
[4] Alterar valor de uma venda
[5] Mostrar todos vendedores e vendas
[6] Excluir dados
Ou [0] para sair.

5
[*~*~*~*~*~*~*] Registros [*~*~*~*~*~*~*]

Codigo do vendedor:1
Mes:1
Nome:Afonso
Valor das vendas:R$ 1000

[*~*~*~*~*~*~*~*~*~*~*~*~*~**~*~*~*~*~*~]


      [MENU]

Selecione a operacao desejada:
[1] Criar arquivo de dados
[2] Incluir registro de venda/vendedor
[3] Deletar vendedor
[4] Alterar valor de uma venda
[5] Mostrar todos vendedores e vendas
[6] Excluir dados
Ou [0] para sair.

6
[*~*~*~*~*~*~*] Exclus├úo de dados [*~*~*~*~*~*]

Arquivo deletado com sucesso.

[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~]
*/
void exercicio_3(void);
void cria_arq(FILE **dados);
void registra_venda(FILE *dados);
VENDA* carrega_dados(FILE *dados,int *n);
void del_vendedor(FILE *dados);
void alterar_venda(FILE *dados);
void print_vendas(FILE *dados);
void apaga_dados(FILE *dados);
int checa_cod(VENDA* vendas,int cod,int n);

/*
[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*]

                   Exercicio 4


Sugestao:
Deseja criar,para a busca, um arquivo com +300 nomes de desaparecidos politicos da ditadura empresarial-militar?
Isto ira sobrescrever o arquivo de nome "nomes.txt" indicado como argumento.
Fonte: https://www.gov.br/participamaisbrasil/lista-de-pessoas-desaparecidas-politicas

[1] Sim         [2]Nao
1

Lendo arquivo..

Arquivo lido! O texto tem 324 linhas.
Resultados para "Maria":
Linha 7: Alceri Maria Gomes da Silva
Linha 18: Ana Maria Nacinovic Corr├¬a
Linha 50: Aurora Maria Nascimento Furtado
Linha 77: Darcy Jos├® dos Santos Mariante
Linha 130: Gilberto Ol├¡mpio Maria
Linha 203: Jos├® Maria Ferreira de Ara├║jo
Linha 224: L├¡gia Maria Salgado N├│brega
Linha 228: Lourdes Maria Wanderley Pontes
Linha 231: L├║cia Maria de Souza
Linha 267: Maria Augusta Thomaz
Linha 268: Maria Auxiliadora Lara Barcellos
Linha 269: Maria Celia Corr├¬a / Maria Cec├¡lia
Linha 269: Maria Celia Corr├¬a / Maria Cec├¡lia
Linha 270: Maria L├║cia Petit da Silva
Linha 271: Maria Regina Lobo Leite de Figueiredo
Linha 272: Mariano Joaquim da Silva
Encerrando busca, 16 resultados encontrados.

        [*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*]
*/
void exercicio_4(char *termo_busca, char* arquivo);

int main(int argc,char* argv[])
{
  int opcao=-1;

  if(argc<5)
  {
    puts("\nPor favor, insira como argumentos do programa os nomes\n"
    "dos arquivos de entrada e saida para o exercicio 2 \n"
    "assim como o termo de busca e o arquivo do exercicio 4.\n"
    "A ordem dos argumentos precisa ser:\n"
    "[entrada.txt][saida.txt][nome a buscar][arquivo.txt]\n");
    return 1;
  }
  while(opcao!=0)
  {
    puts("\n\n\t[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*]\n\n"
    "\t               LISTA 8\n "
    "\tAFONSO LUSTOSA PIRES JUNIOR - DRE:122079084\n\n"
    "SELECIONE O EXERCICIO QUE VOCE DESEJA:\n"
    "[1] Exercicio 1\n"
    "[2] Exercicio 2\n"
    "[3] Exercicio 3\n"
    "[4] Exercicio 4\n"
    "Ou [0] para sair do programa.");
    opcao=valida_int();

    switch (opcao)
    {
      case 1:
        puts("\n\n[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*]\n\n"
        "                   Exercicio 1 - Agenda \n\n");
        exercicio_1();
        break;

       case 2:
        puts("\n\n[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*]\n\n"
        "                   Exercicio 2\n\n");
        exercicio_2(argv[1],argv[2]);
        break;

      case 3:
        puts("\n\n[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*]\n\n"
        "                   Exercicio 3\n\n");
        exercicio_3();
        break;

      case 4:
        puts("\n\n[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*]\n\n"
        "                   Exercicio 4\n\n");
        exercicio_4(argv[3],argv[4]);
        break;

      default: break;
    }
  }

  return 0;
}

void exercicio_1(void)
{
  int opcao=-1,lixo;
  char nome[40],c;
  FILE *agenda;

  CONTATO *p_head=NULL;
  carregar_agenda(&agenda,&p_head);

  while(opcao!=0)
  {
    puts("\nSelecione a operacao desejada:\n"
    "[1] Inserir Contato\n"
    "[2] Remover Contato\n"
    "[3] Pesquisar contato pelo nome\n"
    "[4] Listar todos os contatos\n"
    "[5] Listar todos os contatos que começam com uma letra especifica\n"
    "[6] Mostrar aniversariantes do mes\n"
    "Ou [0] para sair e SALVAR agenda.\n");

    opcao=valida_int();
    switch (opcao)
    {
      case 1:
        puts("\n\n[*~*~*~*~*] Inserir Contato [*~*~*~*~*]\n\n");
        inserir_contato(&p_head);
        puts("\n\n[*~*~*~*~*] Contato Inserido [*~*~*~*~*]\n\n");
        break;

      case 2:
        puts("\n\n[*~*~*~*~*] Remover contato [*~*~*~*~*]\n\n");
        remover_contatos(&p_head);
        puts("\n\n[*~*~*~*~*] Fim da remocao [*~*~*~*~*]\n\n");
        break;

      case 3:
        puts("\n\n[*~*~*~*~*] Busca por nome [*~*~*~*~*]\n\n");
        puts("Insira o nome a ser buscado:");
        le_string(nome,40);
        busca_contato(nome,p_head);
        puts("\n\n[*~*~*~*~*] Fim da busca [*~*~*~*~*]\n\n");
        break;

      case 4:
        puts("\n\n[*~*~*~*~*] Contatos [*~*~*~*~*]\n\n");
        listar_contatos(p_head);
        puts("\n\n[*~*~*~*~*] Fim da lista [*~*~*~*~*]\n\n");
        break;

      case 5:

        puts("\n\n[*~*~*~*~*] Busca por letra [*~*~*~*~*]\n\n");
        puts("Insira a letra inicial do contato:");
        while ( ((c=getchar())<65) || (c>91 && c<97) || c>122)
        {
          while( (lixo=getchar()) != EOF && lixo!='\n');
          puts("Insira uma letra valida.\n");
        }
        busca_letra(c,p_head);
        puts("\n\n[*~*~*~*~*] Fim da busca [*~*~*~*~*]\n\n");
        break;

      case 6:
        puts("\n\n[*~*~*~*~*] Aniversariantes do mes [*~*~*~*~*]\n\n"
        "Selecione o mes desejado:\n"
        "[1]Janeiro\t\t[7]Julho\n"
        "[2]Fevereiro\t\t[8]Agosto\n"
        "[3]Marco\t\t[9]Setembro\n"
        "[4]Abril\t\t[10]Outubro\n"
        "[5]Maio\t\t\t[11]Novembro\n"
        "[6]Junho\t\t[12]Dezembro\n\n");

        opcao=valida_int();
        aniversariantes(opcao,p_head);
        puts("\n\n[*~*~*~*~*] Fim da exibicao [*~*~*~*~*]\n\n");

        break;

      default: break;
    }
  }
  salvar_agenda(agenda,p_head);
  return;
}
void carregar_agenda(FILE **agenda,CONTATO **head)
{
    int i=0;
    char c;
    CONTATO *novo_contato,*anterior;
    if((*agenda = fopen("agenda.txt","r+"))==NULL)
    {
      if((*agenda = fopen("agenda.txt","w+"))==NULL)
      {
        puts("Arquivo nao pode ser criado.\n");
      }
      else{
      puts("Arquivo de agenda criado!\n");
      return;
      }
    }
    while(1)
    {
      if(!(novo_contato = (CONTATO*)malloc(sizeof(CONTATO)))) return;
      i=0;
      while(((c=fgetc(*agenda))!= EOF) && c!='\n')
      {
        novo_contato->nome[i]=c;
        i++;
      }
      novo_contato->nome[i]='\0';
      i=0;
      while(((c=fgetc(*agenda))!= EOF) && c!='\n')
      {
        novo_contato->telefone[i]=c;
        i++;
      }
      novo_contato->telefone[i]='\0';
      fscanf(*agenda,"%d/%d\n",&(novo_contato->data_aniversario.dia),&(novo_contato->data_aniversario.mes));
      if(c==EOF) break;

      if(*head==NULL)
      {
        *head=novo_contato;
        novo_contato->p_contato = NULL;
        anterior=novo_contato;
      }
      else
      {
        anterior->p_contato = novo_contato;
        anterior = novo_contato;
      }
    }
    anterior->p_contato=NULL;
    fclose(*agenda);
    puts("Agenda carregada!\n");

}
void salvar_agenda(FILE *agenda,CONTATO *head)
{
  CONTATO *checando = head;
  puts("Salvando agenda..\n");

  if((agenda=fopen("agenda.txt","w+"))==NULL)
  {
    puts("Erro abrindo arquivo\n");
  }

  while(1)
  {
    if(head==NULL)
    {
      puts("Nao ha contatos a salvar na agenda.\nEncerrando..\n");
      break;
    }


    fputs(checando->nome,agenda);
    fputc('\n',agenda);
    fputs(checando->telefone,agenda);
    fputc('\n',agenda);
    fprintf(agenda,"%d/%d\n",checando->data_aniversario.dia,checando->data_aniversario.mes);


    if(checando->p_contato == NULL) break;
    else
    {
      checando = checando->p_contato;
    }
  }
  fclose(agenda);
}
void inserir_contato(CONTATO **p_head)
{
  int valor;
  CONTATO *checando = *p_head;
  CONTATO *novo_contato,*anterior;;

  novo_contato = (CONTATO*)malloc(sizeof(CONTATO));

  puts("\nInsira o nome do contato:");
  le_string(novo_contato->nome,40);

  puts("\nInsira o telefone:");
  le_string(novo_contato->telefone,20);

  puts("\nInsira o dia do aniversario:");
  valor=valida_int();
  novo_contato->data_aniversario.dia = valor;

  puts("\nInsira o mes do aniversario:");
  valor=valida_int();
  novo_contato->data_aniversario.mes = valor;

  if(*p_head==NULL)
  {
    *p_head = novo_contato;
  }
  else
  {
    while( (checando != NULL) && (strcmp(novo_contato->nome,checando->nome) > 0)  )
    { /*condicao da strcmp = novo_contato->nome é lexicograficamente maior que esta sendo checado*/
      anterior = checando;
      checando = checando->p_contato;
    }
    if(checando == NULL)
    {
      anterior->p_contato = novo_contato;
      novo_contato->p_contato = NULL;
    }
    else
    {
      if(checando == *p_head)
      {
        novo_contato->p_contato = *p_head;
        *p_head = novo_contato;
      }
      else
      {
        anterior->p_contato = novo_contato;
        novo_contato->p_contato = checando;
      }
    }
  }
}
void listar_contatos(CONTATO *head)
{
  CONTATO *listando=head;

  while(1)
  {
    if(head==NULL)
    {
      puts("Nao ha contatos na agenda.\n");
      break;
    }

    printf("Nome: %s\n"
    "Telefone: %s\n"
    "Aniversario: %d/%d\n\n",listando->nome,listando->telefone,listando->data_aniversario.dia,
    listando->data_aniversario.mes);

    if(listando->p_contato == NULL)
    {
       break;
    }
    else
    {
      listando = listando->p_contato;
    }
  }
}
void remover_contatos(CONTATO **head)
{
  CONTATO *listando = *head;
  int i=0,opcao;
  CONTATO **opcoes;

  opcoes = (CONTATO**) malloc(sizeof(CONTATO));
  while(1)
  {
    if(listando==NULL)
    {
      puts("Nao ha contatos na agenda.\n");
      return;
    }
    opcoes[i] = listando;

    printf("[%d]: %s (%s)\n",i+1,listando->nome,listando->telefone);


    if(listando->p_contato == NULL) break;
    else
    {
      i++;
      opcoes = (CONTATO**) realloc(opcoes,(i+1)*sizeof(CONTATO));
      listando = listando->p_contato;
    }
  }

  puts("\nEscolha o contato a ser removido (ou 0 para sair):");
  while( ((opcao= valida_int()) > i+1) || (opcao<0) )
  {
    puts("Digite um número valido.\n");
  }
  if(opcao==0)
  {
    return;
  }
  opcao--;
  if(opcoes[opcao]->p_contato == NULL) /*caso ultimo da lista*/
  {
    if(opcoes[opcao] == *head)  /*deletar lista toda */
    {
      free(opcoes[opcao]);
      *head = NULL;
    }
    else
    {
    opcoes[opcao-1]->p_contato = NULL;
    free(opcoes[opcao]);
    }
  }
  else if(opcoes[opcao] == *head) /*caso seja o primeiro*/
  {
    *head=opcoes[opcao+1];
    free(opcoes[opcao]);
  }
  else   /*deletar qlqer um no meio*/
  {
    opcoes[opcao-1]->p_contato = opcoes[opcao]->p_contato;
    free(opcoes[opcao]);
  }

}
void busca_contato(char *c,CONTATO* head)
{
  int teste=0;
  CONTATO *checando;
  checando = head;

  while(1)
  {
    if(head==NULL)
    {
      puts("Nao ha contatos na agenda.\n");
      break;
    }

    if(!(strcmp(c,checando->nome)))
    {
      printf("\n\nNome: %s\n"
      "Telefone: %s\n"
      "Aniversario: %d/%d\n\n",checando->nome,checando->telefone,checando->data_aniversario.dia,
      checando->data_aniversario.mes);
      teste=1;

    }

    if(checando->p_contato == NULL) break;
    else
    {
      checando = checando->p_contato;
    }
  }
  if(!teste)
  {
    puts("\nA busca nao retornou resultados.\n");
  }
}
void busca_letra(char c,CONTATO* head)
{
  int teste=0;
  CONTATO *checando;
  checando = head;

  while(1)
  {
    if(head==NULL)
    {
      puts("Nao ha contatos na agenda.\n");
      break;
    }

    if( (c-32==checando->nome[0]) || (c+32==checando->nome[0]) || (c==checando->nome[0]))
    { /*checa maiusculas e minusculas */
      printf("\n\nNome: %s\n"
      "Telefone: %s\n"
      "Aniversario: %d/%d\n\n",checando->nome,checando->telefone,checando->data_aniversario.dia,
      checando->data_aniversario.mes);
      teste=1;

    }

    if(checando->p_contato == NULL) break;
    else
    {
      checando = checando->p_contato;
    }
  }
  if(!teste)
  {
    puts("\nA busca nao retornou resultados.\n");
  }
}
void aniversariantes(int mes,CONTATO* head)
{
  int teste=0;
  CONTATO *checando;
  checando = head;

  while(1)
  {
    if(head==NULL)
    {
      puts("Nao ha contatos na agenda.\n");
      break;
    }
    if(mes ==checando->data_aniversario.mes)
    {
      printf("\n\nNome: %s\n"
      "Telefone: %s\n"
      "Aniversario: %d/%d\n\n",checando->nome,checando->telefone,checando->data_aniversario.dia,
      checando->data_aniversario.mes);
      teste=1;
    }

    if(checando->p_contato == NULL) break;
    else
    {
      checando = checando->p_contato;
    }
  }
  if(!teste)
  {
    puts("\nA busca nao retornou resultados.\n");
  }
}

void exercicio_2(char *entrada,char *saida)
{
  int n_linhas,i;
  char **linha;

  if((linha=carrega_entrada(entrada,&n_linhas))==NULL)
  {
   puts("Escreva algo na entrada antes de continuar!");
  }

  salva_saida(linha,n_linhas,saida);
  for(i=0;i<n_linhas;i++)
  {
    free(linha[i]);
  }
  free(linha);

}
char** carrega_entrada(char* entrada,int *n)
{
  FILE *p_entrada=NULL;
  long int fim,tam;
  char **linha;
  int n_linhas=0;
  if((p_entrada = fopen(entrada,"r")) ==NULL)
  {
    if((p_entrada = fopen(entrada,"w+"))==NULL)
    {
      puts("Arquivo nao pode ser criado.\n");
    }
    else
    {
    puts("Arquivo de entrada criado!\n");
    fclose(p_entrada);
    return NULL;
    }
  }

  fseek(p_entrada,0,SEEK_END);     /*feof nao funciona nem a pau no windows. sempre acusa o fim, to usando isso entao*/
  fim = ftell(p_entrada);
  rewind(p_entrada);
  if(fim==ftell(p_entrada))
  {
    fclose(p_entrada);
    return NULL;
  }


  if((linha=(char**)malloc(sizeof(char*)))==NULL)
  {
    puts("problema na memoria\n");
    return NULL;
  };

  while(ftell(p_entrada)!=fim)
  {
    n_linhas++;
    if((linha=(char**)realloc(linha,n_linhas*sizeof(char*)))==NULL)
    {
    puts("problema na memoria\n");
    return NULL;
    }

    if((linha[n_linhas-1] = malloc(50*sizeof(char)))==NULL)
    {
    puts("problema na memoria\n");
    return NULL;
    }

    fgets(linha[n_linhas-1],50,p_entrada);

    tam = strlen(linha[n_linhas-1]);   /*retirando \n */
    if(tam>0 && linha[n_linhas-1][tam-1]=='\n')
    {
      linha[n_linhas-1][tam-1]='\0';
    }
  }

  *n=n_linhas;
  return linha;
}
void salva_saida(char** linha,int n_linhas,char* saida)
{
  FILE *p_saida;
  int i,k,tam;
  char **nova_linha;

  if((p_saida = fopen(saida,"w"))==NULL)
    {
      puts("Arquivo nao pode ser criado.\n");
      return;
    }

  if((nova_linha = (char**)malloc(n_linhas*sizeof(char*)))==NULL)
    {
      puts("Problema na memoria.\n");
      return;
    }

  for(i=0;i<n_linhas;i++)
  {
    if((nova_linha[i] = (char*)malloc(50*sizeof(char)))==NULL)
    {
      puts("Problema na memoria.\n");
      return;
    }
    strcpy(nova_linha[i],linha[n_linhas-i-1]);
    tam=strlen(nova_linha[i]);

    for(k=0;k<strlen(nova_linha[i]);k++)
    {
      nova_linha[i][k]=linha[n_linhas-i-1][tam-1-k];
    }
  }
  for(i=0;i<n_linhas;i++)
  {
    fputs(nova_linha[i],p_saida);
    fputc('\n',p_saida);
  }
  fclose(p_saida);
  puts("\nArquivo de saida gerado.\n");


}

void exercicio_3(void)
{
  int opcao=-1;
  FILE *dados=NULL;


  while(opcao!=0)
  {
      if((dados = fopen("vendas.bin","r+b"))==NULL)
    {
      puts("Arquivo de vendas ainda nao existe. Por favor crie um.\n");
    }
    else
    {
      fclose(dados);
    }

    puts("\n      [MENU]\n\n"
    "Selecione a operacao desejada:\n"
    "[1] Criar arquivo de dados\n"
    "[2] Incluir registro de venda/vendedor\n"
    "[3] Deletar vendedor \n"
    "[4] Alterar valor de uma venda\n"
    "[5] Mostrar todos vendedores e vendas\n"
    "[6] Excluir dados\n"
    "Ou [0] para sair.\n");

    opcao=valida_int();
    if( (dados==NULL) && (opcao!=1 && opcao!=0) )
    { puts("\nPor favor, crie o arquivo de dados.\n");
      opcao=-1;
    }
    switch (opcao)
    {

      case 1:
        puts("[*~*~*~*~*~*~*~*] Criar arquivo[*~*~*~*~*~*~*~*]\n");
        cria_arq(&dados);
        puts("[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~]\n");
        break;

      case 2:
        puts("[*~*~*~*~*~*~*] Inserir registro [*~*~*~*~*~*~*]\n");
        registra_venda(dados);
        puts("[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~]\n");
        break;

      case 3:
      puts("[*~*~*~*~*~*~*] Deletar vendedor [*~*~*~*~*~*~*]\n");
      del_vendedor(dados);
      puts("[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~]\n");

        break;

      case 4:
      puts("[*~*~*~*~*] Alterar valor de venda [*~*~*~*~*]\n");
      alterar_venda(dados);
      puts("[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~]\n");

        break;

      case 5:
        puts("[*~*~*~*~*~*~*] Registros [*~*~*~*~*~*~*]\n");
        print_vendas(dados);
        puts("[*~*~*~*~*~*~*~*~*~*~*~*~*~**~*~*~*~*~*~]\n");
        break;

      case 6:
        puts("[*~*~*~*~*~*~*] Exclusão de dados [*~*~*~*~*~*]\n");
        apaga_dados(dados);
        puts("[*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~]\n");


        break;

      default: break;
    }
  }
}
void cria_arq(FILE **dados)
{
  int n=0;

  if(*dados!=NULL)
  {
    puts("Arquivo .bin ja existe!");
    return;
  }
  if((*dados = fopen("vendas.bin","w+b"))==NULL)
  {
    puts("Arquivo de vendas nao pode ser criado.\n");
    return;
  }
  else
  {
    puts("Arquivo vendas.bin criado!\n");
    fwrite(&n,sizeof(int),1,*dados);
  }
  fclose(*dados);
}
void registra_venda(FILE *dados)
{
  VENDA nova_venda, temp, *vendas;
  int n_registros=0,opcao,i,k;

  vendas=carrega_dados(dados,&n_registros);

  if(n_registros>0) while(1)
  {
    puts("Digite o codigo do vendedor ou [0] para criar um novo.\n");
    opcao=valida_int();
    if(opcao==0) break;
    /*checar se codigo existe mesmo*/
    if((i=checa_cod(vendas,opcao,n_registros))>=0)
    {
      nova_venda.cod_vendedor=opcao;
      strcpy(nova_venda.nome_vendedor,vendas[i].nome_vendedor);
      break;
    }
    else puts("Vendedor nao encontrado.\n");
  }
  if(opcao==0 || n_registros==0)
  {
    if(n_registros==0) puts("Primeiro registro!\nO codigo de vendedor deve ser diferente de 0.\n");
    while(1)
    {
      puts("\nCodigo do vendedor:");
      nova_venda.cod_vendedor=valida_int();
      if(nova_venda.cod_vendedor==0)
      {
        puts("Digite um valor valido.\n");
        continue;
      }
    /*checar se cod ja existe caso nao seja primeiro registro*/
      if(n_registros!=0)
      {
        if((checa_cod(vendas,nova_venda.cod_vendedor,n_registros)>=0))
        {
          puts("Codigo ja existente. Insira valor valido:");
          continue;
        }
        else break;
      }
      else break;
    }
    puts("Nome do vendedor: ");
    le_string(nova_venda.nome_vendedor,50);
  }
  while(1)
  {
    puts("Mes de referencia:\n"
        "[1]Janeiro\t\t[7]Julho\n"
        "[2]Fevereiro\t\t[8]Agosto\n"
        "[3]Marco\t\t[9]Setembro\n"
        "[4]Abril\t\t[10]Outubro\n"
        "[5]Maio\t\t\t[11]Novembro\n"
        "[6]Junho\t\t[12]Dezembro\n\n");

    if( (nova_venda.mes=valida_int())<=0 || nova_venda.mes>12 )
    {
      puts("Insira um valor valido.\n");
    }
    else if(n_registros>0)     /*checar se ja existe registro pra esse mes e esse vendedor, caso ñ seja primeiro registro*/
    {
      for(i=0;i<n_registros;i++)
      {
        if(vendas[i].cod_vendedor==nova_venda.cod_vendedor)
        {
          if(vendas[i].mes==nova_venda.mes)
          {
            puts("\n\tERRO!\n\nVendas referentes a este mes ja foram registrado para este vendedor.\n"
                "Insira outro mes.\n");
            i=n_registros+1;
          }
        }
      }
      if(i==n_registros)
      {
        break;
      }
    }
    else break;
  }
  puts("Valor das vendas: ");
  nova_venda.valor_da_venda=valida_int();

  /*gravar dados,primeiramente no vetor alocado*/
  n_registros++;
  vendas = (VENDA*)realloc(vendas,n_registros*sizeof(VENDA));
  if(vendas==NULL)
  {
    puts("erro de memoria.\n");
    return;
  }
  vendas[n_registros-1]=nova_venda;
  /*ORDERNAR o vetor por cod_vendedor e mes*/

  for(i=0;i<n_registros;i++)
  {
    for(k=0;k<n_registros-1;k++)
    {
      if(vendas[k].cod_vendedor>vendas[k+1].cod_vendedor)
      {
        temp=vendas[k+1];
        vendas[k+1]=vendas[k];
        vendas[k]=temp;
      }
    }
  }
  /*ordernar por mes*/
  for(i=0;i<n_registros;i++)
  {
    for(k=0;k<n_registros-1;k++)
    {
      if(vendas[k].cod_vendedor==vendas[k+1].cod_vendedor)
      {
        if(vendas[k].mes>vendas[k+1].mes)
        {
          temp=vendas[k+1];
          vendas[k+1]=vendas[k];
          vendas[k]=temp;
        }
      }
    }
  }


  /*gravar vetor no bin*/
  if((dados = fopen("vendas.bin","r+b"))==NULL )
  {
    puts("Problema abrindo arquivo\n");
    return;
  }

  fwrite(&n_registros,sizeof(int),1,dados);
  fwrite(vendas,sizeof(VENDA),n_registros,dados);
  fclose(dados);
  free(vendas);

}
VENDA* carrega_dados(FILE *dados, int* n)
{
  int n_registros;
  VENDA *vendas;
  if((dados = fopen("vendas.bin","rb"))==NULL ) return NULL;
  else
  {

    fread(&n_registros,sizeof(int),1,dados);
    *n=n_registros;
    if(n_registros==0)
    {
      if((vendas = (VENDA*)malloc(sizeof(VENDA)))==NULL)
      {
        puts("Erro de memoria.\n");
        return NULL;
      }
      return vendas;
    }
    if((vendas = (VENDA*)malloc(n_registros*sizeof(VENDA)))==NULL)
    {
      puts("Erro de memoria.\n");
      return NULL;
    }
    fread(vendas,sizeof(VENDA),n_registros,dados);
    fclose(dados);
    return vendas;
  }
}
void del_vendedor(FILE *dados)
{
  VENDA *vendas,*nova_vendas;
  int opcao,n_registros,i,*indices,n_del,k=0;

  vendas=carrega_dados(dados,&n_registros);
  if(n_registros==0)
  {
    puts("Nao ha registros.\n\n");
    return;
  }

  while(1)
  {
    puts("Digite o codigo do vendedor ou [0] para sair.\n");
    opcao=valida_int();
    if(opcao==0)
    {
      free(vendas);
       return;
    }
    /*checar se codigo existe mesmo*/
    if((i=checa_cod(vendas,opcao,n_registros))>=0)
    {
      break;
    }
    else puts("Vendedor nao encontrado.\n");
  }
  /*guardar 0 numero "n_del" de indices de valores a deletar num vetor*/
  if((indices = (int*)malloc(sizeof(int)))==NULL)
  {
    puts("erro na memoria.\n");
    return;
  }
  for(i=0,n_del=0;i<n_registros;i++)
  {
    if(vendas[i].cod_vendedor==opcao)
    {
      n_del++;
      if((indices =(int*)realloc(indices,n_del*sizeof(int)))==NULL)
      {
        puts("erro na memoria.\n");
        return;
      }
      indices[n_del-1]=i;
    }
  }
  if(n_del==n_registros) /*caso tenha que deletar tudo, cria outro arquivo logo*/
  {
    if((dados = fopen("vendas.bin","w+b"))==NULL)
    {
      puts("Arquivo de vendas nao pode ser aberto.\n");
      return;
    }
    else
    {
      puts("Todos registros foram deletados!\n");
      fwrite(&k,sizeof(int),1,dados);
    }
    fclose(dados);
    free(vendas);
    return;
  }
  nova_vendas=(VENDA*)malloc((n_registros-n_del)*sizeof(VENDA));
  if(nova_vendas==NULL)
  {
    free(vendas);
    return;
  };
  for(i=0,k=0;i<n_registros;i++)
  {
    if(vendas[i].cod_vendedor!=opcao)
    {
      nova_vendas[k]=vendas[i];
      k++;
    }
  }
  free(vendas);
  vendas=nova_vendas;
  n_registros-=n_del;
  /*gravacao*/
  if((dados = fopen("vendas.bin","r+b"))==NULL )
  {
    puts("Problema abrindo arquivo\n");
    return;
  }

  fwrite(&n_registros,sizeof(int),1,dados);
  fwrite(vendas,sizeof(VENDA),n_registros,dados);
  fclose(dados);
  free(vendas);



}
void alterar_venda(FILE *dados)
{
  int n_registros,i,opcao,ind,valido=0;
  VENDA *vendas;
  char **mes;

  vendas = carrega_dados(dados,&n_registros);
  if((mes = (char**)malloc(12*sizeof(char*)))==NULL) return;
  for(i=0;i<12;i++)
  {
    if((mes[i] = (char*)malloc(10*sizeof(char)))==NULL) return;
  }
  {  /*um bloco so pra eu poder fechar*/
    strcpy(mes[0],"Janeiro");
    strcpy(mes[1],"Fevereiro");
    strcpy(mes[2],"Marco");
    strcpy(mes[3],"Abril");
    strcpy(mes[4],"Maio");
    strcpy(mes[5],"Junho");
    strcpy(mes[6],"Julho");
    strcpy(mes[7],"Agosto");
    strcpy(mes[8],"Setembro");
    strcpy(mes[9],"Outubro");
    strcpy(mes[10],"Novembro");
    strcpy(mes[11],"Dezembro");
  }

  if(!n_registros)
  {
    puts("Nao ha registros.\n");
    return;
  }
  while(1)      /*Selecionar vendedor ja existente*/
  {
    puts("Digite o codigo do vendedor ou [0] para sair.\n");
    opcao=valida_int();
    if(opcao==0)
    {
      free(vendas);
        return;
    }
    /*checar se codigo existe mesmo*/
    if((ind=checa_cod(vendas,opcao,n_registros))>=0) break;
    else puts("Vendedor nao encontrado.\n");
  }
  while(1) /*Selecionar mes disponivel*/
  {
    puts("Meses registrados:\n");
    for(i=0;i<n_registros;i++)
    {
      if(vendas[i].cod_vendedor==vendas[ind].cod_vendedor)
      {
        printf("[%d] %s\n",vendas[i].mes,mes[vendas[i].mes-1]);
      }
    }
    putchar('\n');
    puts("Selecione o mes do registro a ser alterado:");
    opcao=valida_int();
     for(i=0;i<n_registros;i++)
    {
      if(vendas[i].cod_vendedor==vendas[ind].cod_vendedor)
      {
        if(opcao==vendas[i].mes)
        {
          valido=1;
          break;
        }
      }
    }
    if(valido)
    {
      printf("\tRegistro selecionada:\n"
      "Nome:%s\n"
      "Codigo do vendedor: %d\n"
      "Mes: %d\n"
      "Valor: R$%d\n"
      "Insira o novo valor a ser registrado:\n"
      ,vendas[i].nome_vendedor,vendas[i].cod_vendedor,vendas[i].mes,vendas[i].valor_da_venda);
      opcao=valida_int();
      vendas[i].valor_da_venda=opcao;
      break;
    }
    else
    {
      puts("\n\tSelecione um mes valido!\n");
    }
  }

  if((dados = fopen("vendas.bin","r+b"))==NULL )
  {
    puts("Problema abrindo arquivo\n");
    return;
  }

  fwrite(&n_registros,sizeof(int),1,dados);
  fwrite(vendas,sizeof(VENDA),n_registros,dados);
  fclose(dados);
  free(vendas);
}
void print_vendas(FILE *dados)
{
  int n_registros,i;
  VENDA *vendas;

  vendas = carrega_dados(dados,&n_registros);
  if(n_registros==0)
  {
    puts("Nao ha registros.\n");
    return;
  }
  for(i=0;i<n_registros;i++)
  {
    printf("\nCodigo do vendedor:%d\n"
    "Mes:%d\n"
    "Nome:%s\n"
    "Valor das vendas:R$ %d\n",vendas[i].cod_vendedor,vendas[i].mes,vendas[i].nome_vendedor,vendas[i].valor_da_venda);
  }
  putchar('\n');
  free(vendas);
  fclose(dados);


}
void apaga_dados(FILE *dados)
{
  if(remove("vendas.bin"))
  {
    puts("Arquivo nao pode ser deletado.\n");
  }
  else {
    puts("Arquivo deletado com sucesso.\n");
  }
}
int checa_cod(VENDA* vendas,int cod,int n)
{
  int i;

  for(i=0;i<n;i++)
      {
        if(cod==vendas[i].cod_vendedor)
        {
          return i; /*caso exista codigo, i sempre >=0*/
        }
      }
  return -1; /*caso nao exista o codigo*/
}

void exercicio_4(char *termo_busca, char* arquivo)
{
  FILE *pa=NULL;
  int opcao=-1,fim, n_linhas=0,i,tam,k,j,cont=0;
  char **linha,*str_cortada;

  printf("Sugestao: \n"
    "Deseja criar,para a busca, um arquivo com +300 nomes de desaparecidos politicos da ditadura empresarial-militar?\n"
    "Isto ira sobrescrever o arquivo de nome \"%s\" indicado como argumento.\n"
    "Fonte: https://www.gov.br/participamaisbrasil/lista-de-pessoas-desaparecidas-politicas \n\n"
    "[1] Sim\t\t[2]Nao\n",arquivo);
    opcao=valida_int();
    if(opcao==1)
    {
      if((pa = fopen(arquivo, "w"))==NULL)
      {
        puts("erro criando arquivo.\n");
      }  /*eu fiz outro programa só pra criar esse monte de linha ok kkkkkkkkkk
      e parece que ele para em um nome especifico,324, sei la pq*/
      else
      {
        fputs("Abelardo Rausch de Alcântara\n",pa);
        fputs("Abílio Clemente Filho\n",pa);
        fputs("Adauto Freire da Cruz\n",pa);
        fputs("Aderval Alves Coqueiro\n",pa);
        fputs("Adriano Fonseca Filho\n",pa);
        fputs("Alberto Aleixo\n",pa);
        fputs("Alceri Maria Gomes da Silva\n",pa);
        fputs("Aldo de Sá Brito Souza Neto\n",pa);
        fputs("Alex de Paula Xavier Pereira\n",pa);
        fputs("Alexander José Ibsen Voerões\n",pa);
        fputs("Alexandre Vannucchi Leme\n",pa);
        fputs("Alfeu de Alcântara Monteiro\n",pa);
        fputs("Almir Custódio de Lima\n",pa);
        fputs("Aluízio Palhano Pedreira Ferreira\n",pa);
        fputs("Alvino Ferreira Felipe\n",pa);
        fputs("Amaro Felix Pereira\n",pa);
        fputs("Amaro Luiz de Carvalho\n",pa);
        fputs("Ana Maria Nacinovic Corrêa\n",pa);
        fputs("Ana Rosa Kucinski Silva\n",pa);
        fputs("Anatália de Souza Melo Alves\n",pa);
        fputs("André Grabois\n",pa);
        fputs("Ângelo Arroyo\n",pa);
        fputs("Ângelo Cardoso da Silva\n",pa);
        fputs("Antogildo Pascoal Viana\n",pa);
        fputs("Antônio Alfredo de Lima\n",pa);
        fputs("Antônio Araujo Veloso\n",pa);
        fputs("Antônio Bem Cardoso\n",pa);
        fputs("Antônio Benetazzo\n",pa);
        fputs("Antônio Carlos Bicalho Lana\n",pa);
        fputs("Antônio Carlos Monteiro Teixeira\n",pa);
        fputs("Antônio Carlos Nogueira Cabral\n",pa);
        fputs("Antônio de Pádua Costa\n",pa);
        fputs("Antônio dos Três Reis de Oliveira\n",pa);
        fputs("Antônio Ferreira Pinto\n",pa);
        fputs("Antônio Guilherme Ribeiro Ribas\n",pa);
        fputs("Antônio Henrique Pereira Neto, Padre\n",pa);
        fputs("Antônio Joaquim de Souza Machado\n",pa);
        fputs("Antônio José dos Reis\n",pa);
        fputs("Antônio Marcos Pinto de Oliveira\n",pa);
        fputs("Antônio Raymundo de Lucena\n",pa);
        fputs("Antônio Sérgio de Mattos\n",pa);
        fputs("Antônio Teodoro de Castro / Theodoro\n",pa);
        fputs("Arildo Airton Valadão\n",pa);
        fputs("Armando Teixeira Fructuoso\n",pa);
        fputs("Arnaldo Cardoso Rocha\n",pa);
        fputs("Arno Preis\n",pa);
        fputs("Ary Abreu Lima da Rosa\n",pa);
        fputs("Augusto Soares da Cunha\n",pa);
        fputs("Aurea Eliza Pereira / Áurea\n",pa);
        fputs("Aurora Maria Nascimento Furtado\n",pa);
        fputs("Avelmar Moreira de Barros\n",pa);
        fputs("Aylton Adalberto Mortati\n",pa);
        fputs("Benedito Gonçalves\n",pa);
        fputs("Benedito Pereira Serra\n",pa);
        fputs("Bergson Gurjão Farias\n",pa);
        fputs("Boanerges de Souza Massa\n",pa);
        fputs("Caiupy Alves de Castro\n",pa);
        fputs("Carlos Alberto Soares de Freitas\n",pa);
        fputs("Carlos Antunes da Silva\n",pa);
        fputs("Carlos Eduardo Pires Fleury\n",pa);
        fputs("Carlos Lamarca\n",pa);
        fputs("Carlos Marighella\n",pa);
        fputs("Carlos Nicolau Danielli\n",pa);
        fputs("Carlos Roberto Zanirato\n",pa);
        fputs("Carlos Schirmer\n",pa);
        fputs("Cassimiro Luiz de Freitas\n",pa);
        fputs("Catarina Helena Abi-Eçab\n",pa);
        fputs("Célio Augusto Guedes\n",pa);
        fputs("Celso Gilberto de Oliveira\n",pa);
        fputs("Chael Charles Schreier\n",pa);
        fputs("Cilon Cunha Brum / Cilon da Cunha\n",pa);
        fputs("Ciro Flávio Salazar de Oliveira\n",pa);
        fputs("Cloves Dias Amorim\n",pa);
        fputs("Custódio Saraiva Neto\n",pa);
        fputs("Daniel José de Carvalho\n",pa);
        fputs("Daniel Ribeiro Callado\n",pa);
        fputs("Darcy José dos Santos Mariante\n",pa);
        fputs("David Capistrano da Costa\n",pa);
        fputs("David de Souza Meira\n",pa);
        fputs("Dênis Casemiro\n",pa);
        fputs("Dermeval da Silva Pereira\n",pa);
        fputs("Devanir José de Carvalho\n",pa);
        fputs("Dilermano Mello do Nascimento\n",pa);
        fputs("Dimas Antônio Casemiro\n",pa);
        fputs("Dinaelza Santana Coqueiro\n",pa);
        fputs("Dinalva Oliveira Teixeira\n",pa);
        fputs("Divino Ferreira de Souza\n",pa);
        fputs("Divo Fernandes de Oliveira\n",pa);
        fputs("Dorival Ferreira\n",pa);
        fputs("Durvalino Porfírio de Souza\n",pa);
        fputs("Edgar de Aquino Duarte / Edgard\n",pa);
        fputs("Edmur Péricles Camargo\n",pa);
        fputs("Edson Luiz Lima Souto\n",pa);
        fputs("Edson Neves Quaresma\n",pa);
        fputs("Edu Barreto Leite\n",pa);
        fputs("Eduardo Antônio da Fonseca\n",pa);
        fputs("Eduardo Collen Leite\n",pa);
        fputs("Eduardo Collier Filho\n",pa);
        fputs("Eiraldo de Palha Freire\n",pa);
        fputs("Elmo Corrêa\n",pa);
        fputs("Élson Costa ou Elson\n",pa);
        fputs("Emmanuel Bezerra dos Santos\n",pa);
        fputs("Enrique Ernesto Ruggia\n",pa);
        fputs("Epaminondas Gomes de Oliveira\n",pa);
        fputs("Eremias Delizoicov\n",pa);
        fputs("Esmeraldina Carvalho Cunha\n",pa);
        fputs("Eudaldo Gomes da Silva\n",pa);
        fputs("Evaldo Luiz Ferreira de Souza\n",pa);
        fputs("Evaristo Alves da Silva\n",pa);
        fputs("Ezequias Bezerra da Rocha\n",pa);
        fputs("Felix Escobar\n",pa);
        fputs("Fernando Augusto da Fonseca\n",pa);
        fputs("Fernando Augusto de Santa Cruz Oliveira\n",pa);
        fputs("Fernando da Silva Lembo\n",pa);
        fputs("Flávio Carvalho Molina\n",pa);
        fputs("Flávio Ferreira da Silva\n",pa);
        fputs("Francisco das Chagas Pereira\n",pa);
        fputs("Francisco Emanuel Penteado ou Francisco Emmanuel\n",pa);
        fputs("Francisco José de Oliveira\n",pa);
        fputs("Francisco Manoel Chaves\n",pa);
        fputs("Francisco Seiko Okama\n",pa);
        fputs("Francisco Tenório Cerqueira Júnior\n",pa);
        fputs("Frederico Eduardo Mayr\n",pa);
        fputs("Gastrone Lúcia de Carvalho Beltrão\n",pa);
        fputs("Gelson Reicher\n",pa);
        fputs("Geraldo Bernardo da Silva\n",pa);
        fputs("Geraldo da Rocha Gualberto\n",pa);
        fputs("Gerson Theodoro de Oliveira\n",pa);
        fputs("Getulio de Oliveira Cabral\n",pa);
        fputs("Gilberto Olímpio Maria\n",pa);
        fputs("Gildo Macedo Lacerda\n",pa);
        fputs("Grenaldo de Jesus da Silva\n",pa);
        fputs("Guilherme Gomes Lund\n",pa);
        fputs("Gustavo Buarque Schiller\n",pa);
        fputs("Hamilton Fernando Cunha\n",pa);
        fputs("Hamilton Pereira Damasceno\n",pa);
        fputs("Helber José Gomes Goulart\n",pa);
        fputs("Hélcio Pereira Fortes\n",pa);
        fputs("Helenira Resende de Souza Nazareth\n",pa);
        fputs("Heleny Ferreira Telles Guariba\n",pa);
        fputs("Hélio Luiz Navarro de Magalhães\n",pa);
        fputs("Henrique Cintra Ferreira de Ornellas\n",pa);
        fputs("Higino João Pio\n",pa);
        fputs("Hiran de Lima Pereira\n",pa);
        fputs("Hiroaki Torigoe\n",pa);
        fputs("Honestino Monteiro Guimarães\n",pa);
        fputs("Horacio Domingo Campiglia\n",pa);
        fputs("Iara Iavelberg\n",pa);
        fputs("Idalísio Soares Aranha Filho\n",pa);
        fputs("Ieda Santos Delgado\n",pa);
        fputs("Inocêncio Pereira Alves\n",pa);
        fputs("Ísis Dias de Oliveira\n",pa);
        fputs("Ismael Silva de Jesus\n",pa);
        fputs("Israel Tavares Roque\n",pa);
        fputs("Issami Nakamura Okano\n",pa);
        fputs("Itair José Veloso\n",pa);
        fputs("Iuri Xavier Pereira\n",pa);
        fputs("Ivan Mota Dias\n",pa);
        fputs("Ivan Rocha Aguiar\n",pa);
        fputs("Jaime Petit da Silva\n",pa);
        fputs("Jana Moroni Barroso\n",pa);
        fputs("Jarbas Pereira Marques\n",pa);
        fputs("Jayme Amorim de Miranda\n",pa);
        fputs("Jeová Assis Gomes\n",pa);
        fputs("João Alfredo Dias\n",pa);
        fputs("João Antônio Santos Abi-Eçab\n",pa);
        fputs("João Batista Franco Drumond\n",pa);
        fputs("João Batista Rita\n",pa);
        fputs("João Bosco Penido Burnier\n",pa);
        fputs("João Carlos Cavalcanti Reis\n",pa);
        fputs("João Carlos Haas Sobrinho\n",pa);
        fputs("João Domingos da Silva ou João Domingues da Silva\n",pa);
        fputs("João Gualberto Calatrone\n",pa);
        fputs("João Leonardo da Silva Rocha\n",pa);
        fputs("João Lucas Alves\n",pa);
        fputs("João Massena Melo\n",pa);
        fputs("João Roberto Borges de Souza ou Souza\n",pa);
        fputs("Joaquim Alencar de Seixas\n",pa);
        fputs("Joaquim Câmara Ferreira\n",pa);
        fputs("Joaquim Pires Cerveira\n",pa);
        fputs("Joel José de Carvalho\n",pa);
        fputs("Joel Vasconcelos Santos\n",pa);
        fputs("Joelson Crispim\n",pa);
        fputs("Jonas José de Albuquerque Barros\n",pa);
        fputs("Jorge Aprígio de Paula\n",pa);
        fputs("Jorge Leal Gonçalves Pereira\n",pa);
        fputs("Jorge Oscar Adur\n",pa);
        fputs("José Bartolomeu Rodrigues de Souza\n",pa);
        fputs("José Campos Barreto\n",pa);
        fputs("José Carlos Novaes da Mata Machado\n",pa);
        fputs("José Dalmo Guimarães Lins\n",pa);
        fputs("José de Souza\n",pa);
        fputs("José Gomes Teixeira\n",pa);
        fputs("José Guimarães\n",pa);
        fputs("José Huberto Bronca ou Humberto\n",pa);
        fputs("José Idésio Brianezi\n",pa);
        fputs("José Inocêncio Barreto\n",pa);
        fputs("José Isabel do Nascimento\n",pa);
        fputs("José Julio de Araújo\n",pa);
        fputs("José Lavecchia\n",pa);
        fputs("José Lima Piauhy Dourado\n",pa);
        fputs("José Manoel da Silva\n",pa);
        fputs("José Maria Ferreira de Araújo\n",pa);
        fputs("José Maurílio Patrício\n",pa);
        fputs("José Maximino de Andrade Netto\n",pa);
        fputs("José Mendes de Sá Roriz\n",pa);
        fputs("José Milton Barbosa\n",pa);
        fputs("José Montenegro de Lima\n",pa);
        fputs("José Porfírio de Souza\n",pa);
        fputs("José Raimundo da Costa\n",pa);
        fputs("José Roberto Arantes de Almeida\n",pa);
        fputs("José Roberto Spiegner\n",pa);
        fputs("José Roman\n",pa);
        fputs("José Silton Pinheiro\n",pa);
        fputs("José Toledo de Oliveira\n",pa);
        fputs("José Wilson Lessa Sabbag\n",pa);
        fputs("Juan Antônio Carrasco Forrastal\n",pa);
        fputs("Juarez Guimarães de Brito\n",pa);
        fputs("Kleber Lemos da Silva\n",pa);
        fputs("Labibe Elias Abduch\n",pa);
        fputs("Lauriberto José Reyes\n",pa);
        fputs("Leopoldo Chiapetti\n",pa);
        fputs("Libero Giancarlo Castiglia / Líbero\n",pa);
        fputs("Lígia Maria Salgado Nóbrega\n",pa);
        fputs("Lincoln Bicalho Roque\n",pa);
        fputs("Lincoln Cordeiro Oest\n",pa);
        fputs("Lorenzo Ismael Viñas\n",pa);
        fputs("Lourdes Maria Wanderley Pontes\n",pa);
        fputs("Lourenço Camelo de Mesquita\n",pa);
        fputs("Lourival Moura Paulino\n",pa);
        fputs("Lúcia Maria de Souza\n",pa);
        fputs("Lucimar Brandão Guimarães\n",pa);
        fputs("Lucindo Costa\n",pa);
        fputs("Lúcio Petit da Silva\n",pa);
        fputs("Luiz Almeida Araújo\n",pa);
        fputs("Luiz Antônio Santa Barbara\n",pa);
        fputs("Luiz Carlos Augusto\n",pa);
        fputs("Luiz Eduardo da Rocha Merlino\n",pa);
        fputs("Luiz Eurico Tejera Lisbôa\n",pa);
        fputs("Luiz Fogaça Balboni\n",pa);
        fputs("Luiz Ghilardini\n",pa);
        fputs("Luiz Gonzaga dos Santos\n",pa);
        fputs("Luiz Hirata\n",pa);
        fputs("Luiz Ignácio Maranhão Filho\n",pa);
        fputs("Luiz José da Cunha\n",pa);
        fputs("Luiz Paulo da Cruz Nunes\n",pa);
        fputs("Luiz René Silveira e Silva\n",pa);
        fputs("Luiz Vieira\n",pa);
        fputs("Luiza Augusta Garlippe / Luisa\n",pa);
        fputs("Lyda Monteiro da Silva\n",pa);
        fputs("Manoel Aleixo da Silva\n",pa);
        fputs("Manoel Alexandrino\n",pa);
        fputs("Manoel Custódio Martins\n",pa);
        fputs("Manoel Fiel Filho\n",pa);
        fputs("Manoel José Mendes Nunes Abreu / Manuel\n",pa);
        fputs("Manoel José Nurchis\n",pa);
        fputs("Manoel Lisbôa de Moura\n",pa);
        fputs("Manoel Raimundo Soares\n",pa);
        fputs("Manoel Rodrigues Ferreira\n",pa);
        fputs("Manuel Alves de Oliveira / Manoel\n",pa);
        fputs("Márcio Beck Machado\n",pa);
        fputs("Marco Antônio Dias Baptista\n",pa);
        fputs("Marcos Antônio Bráz de Carvalho\n",pa);
        fputs("Marcos Antônio da Silva Lima\n",pa);
        fputs("Marcos José de Lima\n",pa);
        fputs("Marcos Nonato da Fonseca\n",pa);
        fputs("Maria Augusta Thomaz\n",pa);
        fputs("Maria Auxiliadora Lara Barcellos\n",pa);
        fputs("Maria Celia Corrêa / Maria Cecília\n",pa);
        fputs("Maria Lúcia Petit da Silva\n",pa);
        fputs("Maria Regina Lobo Leite de Figueiredo\n",pa);
        fputs("Mariano Joaquim da Silva\n",pa);
        fputs("Marilena Villas Boas Pinto\n",pa);
        fputs("Mário Alves de Souza Vieira\n",pa);
        fputs("Mário de Souza Prata\n",pa);
        fputs("Massafumi Yoshinaga\n",pa);
        fputs("Maurício Grabois\n",pa);
        fputs("Mauricio Guilherme da Silveira\n",pa);
        fputs("Merival Araújo\n",pa);
        fputs("Miguel Pereira dos Santos\n",pa);
        fputs("Miguel Sabat Nuet\n",pa);
        fputs("Milton Soares de Castro\n",pa);
        fputs("Monica Suzana Pinus de Binstock\n",pa);
        fputs("Nativo Natividade de Oliveira\n",pa);
        fputs("Neide Alves dos Santos\n",pa);
        fputs("Nelson José de Almeida\n",pa);
        fputs("Nelson Lima Piauhy Dourado\n",pa);
        fputs("Nestor Vera\n",pa);
        fputs("Newton Eduardo de Oliveira\n",pa);
        fputs("Nilda Carvalho Cunha\n",pa);
        fputs("Noberto Nehring\n",pa);
        fputs("Norberto Armando Habegger\n",pa);
        fputs("Odijas Carvalho de Souza\n",pa);
        fputs("Olavo Hanssen ou Hansen\n",pa);
        fputs("Onofre Pinto\n",pa);
        fputs("Orlando da Silva Rosa Bomfim Júnior\n",pa);
        fputs("Orlando Momente ou Orlando Moura Momente\n",pa);
        fputs("Ornalino Cândido da Silva\n",pa);
        fputs("Orocilio Martins Gonçalves\n",pa);
        fputs("Oswaldo Orlando da Costa / Osvaldo\n",pa);
        fputs("Otávio Soares Ferreira da Cunha\n",pa);
        fputs("Otoniel Campos Barreto\n",pa);
        fputs("Pauline Philipe Reichstul\n",pa);
        fputs("Paulo César Botelho Massa\n",pa);
        fputs("Paulo Costa Ribeiro Bastos\n",pa);
        fputs("Paulo de Tarso Celestino da Silva\n",pa);
        fputs("Paulo Guerra Tavares\n",pa);
        fputs("Paulo Mendes Rodrigues\n",pa);
        fputs("Paulo Roberto Pereira Marques\n",pa);
        fputs("Paulo Stuart Wright\n",pa);
        fputs("Paulo Torres Gonçalves\n",pa);
        fputs("Pedro Alexandrino de Oliveira Filho    \n",pa);
        fputs("Pedro Domiense de Oliveira\n",pa);
        fputs("Pedro Inácio de Araújo\n",pa);
        fputs("Pedro Jerônimo de Souza\n",pa);
        fputs("Pedro Ventura Felipe de Araújo Pomar\n",pa);
        fputs("Péricles Gusmão Régis\n",pa);
        fputs("Raimundo Eduardo da Silva\n",pa);
        fputs("Raimundo Gonçalves de Figueiredo\n",pa);
        fputs("Raimundo Nonato Paz\n",pa);
        fputs("Ramires Maranhão do Valle\n",pa);
        fputs("Ranúsia Alves Rodrigues\n",pa);
        fputs("Raul Amaro Nin Ferreira\n",pa);
        fputs("Reinaldo Silveira Pimenta\n",pa);
        fputs("Roberto Cietto\n",pa);
        fputs("Roberto Macarini\n",pa);
        fputs("Rodolfo de Carvalho Troiano\n",pa);
        fputs("Ronaldo Mouth Queiroz\n",pa);
        fputs("Rosalindo Sousa ou Souza\n",pa);
        fputs("Rubens Beyrodt Paiva ou Rubens Beirodt\n",pa);
        fputs("Rui Osvaldo Aguiar Pfutzenreuter\n",pa);
        fputs("Ruy Carlos Vieira Berbert\n",pa);
        fputs("Ruy Frasão Soares\n",pa);
        fputs("Santo Dias da Silva\n",pa);
        fputs("Sebastião Tomé da Silva\n",pa);
        fputs("Sergio Landulfo Furtado\n",pa);
        fputs("Severino Elias de Mello\n",pa);
        fputs("Severino Viana Colou ou Collôr\n",pa);
        fputs("Solange Lourenço Gomes\n",pa);
        fputs("Soledad Barret Viedma\n",pa);
        fputs("Sônia Maria de Moraes Angel Jones\n",pa);
        fputs("Stuart Edgar Angel Jones\n",pa);
        fputs("Suely Yumiko Kanayama\n",pa);
        fputs("Telma Regina Cordeiro Corrêa\n",pa);
        fputs("Therezinha Viana de Assis\n",pa);
        fputs("Thomaz Antônio da Silva Meirelles Netto\n",pa);
        fputs("Tito de Alencar Lima\n",pa);
        fputs("Tobias Pereira Júnior\n",pa);
        fputs("Uirassú de Assis Batista / Uirassu\n",pa);
        fputs("Umberto de Albuquerque Câmara Neto\n",pa);
        fputs("Valdir Sales Saboia\n",pa);
        fputs("Vandick Reidner Pereira Coqueiro\n",pa);
        fputs("Virgílio Gomes da Silva\n",pa);
        fputs("Vitor Carlos Ramos\n",pa);
        fputs("Vitorino Alves Moitinho\n",pa);
        fputs("Vladimir Herzog\n",pa);
        fputs("Walkíria Afonso Costa / Walquíria\n",pa);
        fputs("Walter de Souza Ribeiro ou Walter de Souza\n",pa);
        fputs("Walter Ribeiro Novaes\n",pa);
        fputs("Wilson Silva\n",pa);
        fputs("Wlademiro Jorge Filho\n",pa);
        fputs("Yoshitane Fujimori\n",pa);
        fputs("Zelmo Bosa\n",pa);
        fputs("Zuleika Angel Jones\n",pa);
      }
    }

  if((pa = fopen(arquivo, "r"))==NULL)
  {
    puts("\nOk. Mas ou arquivo indicado no argumento nao existe ou deu erro!\n");
  }
  else
  {
    puts("\nLendo arquivo..\n");
    fseek(pa,0,SEEK_END);     /*feof nao funciona nem a pau no windows. sempre acusa o fim, to usando isso entao*/
    fim = ftell(pa);
    rewind(pa);
    if(fim==ftell(pa)) /*caso arquivo esteja vazio*/
    {
      fclose(pa);
      puts("Escreva algo no arquivo! Ou aceite minha sugestao :)\n");
      return;
    }

    if((linha=(char**)malloc(sizeof(char*)))==NULL)
    {
      puts("problema na memoria\n");
      return;
    }

    while(ftell(pa)!=fim)   /*pega todas linhas*/
    {
      n_linhas++;
      if((linha=(char**)realloc(linha,n_linhas*sizeof(char*)))==NULL)
      {
        puts("problema na memoria\n");
        return;
      }
      if((linha[n_linhas-1] = malloc(60*sizeof(char)))==NULL)
      {
        puts("problema na memoria\n");
        return;
      }

      fgets(linha[n_linhas-1],60,pa);/*
      printf("linha %d:%s",n_linhas,linha[n_linhas-1]); */
    }
    printf("Arquivo lido! O texto tem %d linhas.\n",n_linhas);

    printf("Resultados para \"%s\":\n",termo_busca);
    tam=strlen(termo_busca)+1;
    str_cortada=(char*)malloc(tam*sizeof(char));
    for(i=0;i<n_linhas;i++)
    {
      if(tam-1<=strlen(linha[i]))
      {
        for(k=0;(k+tam)<strlen(linha[i])+1;k++)
        {
          for(j=0;j<tam-1;j++)/*recortando linha atual*/
          {
            str_cortada[j]=linha[i][k+j];
          }
          str_cortada[j]='\0';
          if(strcmp(str_cortada,termo_busca)==0)
          {
            cont++;
            opcao=3;
            printf("Linha %d: %s",i+1,linha[i]);
          }
        }
      }
    }
    if(opcao==3)
    {
      printf("Encerrando busca, %d resultados encontrados.",cont);
    }
    if(opcao!=3) puts("A busca nao retornou resultados.\n");


  }

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
	while((lixo=getchar()) != EOF && lixo!= '\n');
	return valor;
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
