/* AFONSO LUSTOSA 
JOAO AMANCIO   


Definição do trabalho:

Trabalho 2 - Análise Léxica
===========================


O objetivo deste trabalho é construir um algoritmo
para converter uma expressão regular em uma árvore
que representa a expressão.


Formato da entrega
------------------

Entregue um arquivo ZIP com o "main.c" e o "README.txt".
Coloque um comentário com o seu nome no topo do arquivo.
O readme deve explicar como compilar e rodar o programa.


O que o programa deve fazer
---------------------------

Seu programa deve ler linhas da entrada padrão (stdin). Cada linha contém uma
expressão regular. Seu programa deve ler esta expressão regular, convertê-la
para uma árvore, e imprimí-la na saída padrão (stdout).

Caso a expressão regular seja inválida, seu programa deve imprimir em stderr
uma mensagem de erro informando a posição e causa do erro. Após o erro, você
pode abortar a execução do programa e não precisa imprimir as árvores das
pŕoximas linhas.

Exemplo de entrada
------------------

abc**
(ab||c)


Exemplo de saída
----------------

CONCAT
  CHAR a
  CONCAT
    CHAR b
    STAR
      STAR
        CHAR c
UNION
  CONCAT
    CHAR a
    CHAR b
  UNION
    EMPTY
    CHAR c

Exemplos de mensagens de erro
------------------------------

(a
Erro de sintaxe na posição 3: esperava ')', encontrei '\n'

(a))
Erro de sintaxe na posição 4: esperava '\n', encontrei ')'


Representação da árvore em C
----------------------------

Use a seguinte estrutura de dados para a sua árvore


    enum RegExpTag {
        TAG_EMPTY,
        TAG_CHAR,
        TAG_STAR,
        TAG_CONCAT,
        TAG_UNION,
    };

    struct RegExp {
        char tag;
        union {
            struct {
                char c;
            } ch;
            struct {
                struct RegExp *filho;
            } un;
            struct {
                struct RegExp *filho1;
                struct RegExp *filho2;
            } bin;
        } u;
    };

    typedef struct RegExp RegExp;


Implemente os seguintes construtores para nós de árvore:

    RegExp *new_empty();
    RegExp *new_char(char c);
    RegExp *new_star(RegExp *filho);
    RegExp *new_concat(RegExp *filho1, RegExp *filho2);
    RegExp *new_union(RegExp *filho1, RegExp *filho2);



Imprimindo uma árvore
---------------------

Implemente uma função recursiva que recebe uma árvore e a imprime em stdout.
Na primeira linha, imprima a tag do nó (e, no caso CHAR também imprima o char).
Nas linhas subsequentes, imprima recursivamente os nós filhos, indentados por
dois espaços. (Veja os exemplos de entradas e saídas)


Gramática das expressões regulares
----------------------------------

Os caracteres |*() e também '\n' e '\0' são considerados especiais.
Todos os outros caracteres são considerados "normais".

O operador de estrela tem precedência mais forte que concatenação, que por
sua vez tem preferência mais forte que união. A regex da string vazia é
representada por uma concatenação de 0 elementos. A gramática fica assim:

    Regexp -> Uniao
    Uniao -> lista de uma ou mais concatenações, separadas por '|'
    Concat -> lista potencialmente vazia de itens estrelados
    Estrela -> item básico, seguido de zero ou mais estrelas
    Basico -> um caractere não-especial, ou uma regexp entre parênteses.


Implementação do parser
-----------------------

Mantenha um conjunto de variáveis globais para armazenar o estado interno do
parser. Você precisa de alguma forma de saber o próximo caractere que ainda
não foi lido, e sua posição na linha.

Para parsear a gramática, crie um grupo de funções mutuamente recursivas,
uma por não-terminal. Cada função consome quantos caracteres da entrada for
necessário e retorna uma árvore.

    static RegExp *parse_regexp();
    static RegExp *parse_uniao();
    static RegExp *parse_concat();
    static RegExp *parse_estrela();
    static RegExp *parse_basico();

Pseudocódigo:

    parse_uniao()
        parse_concat()
        enquanto proc char é '|'
            parse_concat()

    parse_concat()
        enquanto prox char pode começar um item estrelado:
            parse_estrela()

    parse_estrela()
        parse_basico()
        enquanto prox char é estrela:
            adiciona uma 
            
_______________________________________

Comando para compilar e testar o programa com entradas em um arquivo 'input.txt':

no linux:
    gcc -o parser -Wall -Wextra main.c ; ./parser < input.txt


no windows:
    gcc -o parser -Wall -Wextra main.c ; Get-Content input.txt | ./parser.exe */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Definição dos Tipos */
enum RegExpTag {
    TAG_EMPTY,
    TAG_CHAR,
    TAG_STAR,
    TAG_CONCAT,
    TAG_UNION,
};
typedef struct {
    char c;
}Char;
typedef struct RegExp RegExp;
typedef struct Concat{
    RegExp *f1;
    RegExp *f2;
}Concat;
typedef struct Union{
    RegExp *f1;
    RegExp *f2;
}Union;
typedef struct Star{
    RegExp *exp;
}Star;
struct RegExp {
    char tag;
    union {
        Char charNode;
        Concat concatNode;
        Union unionNode;
        Star starNode;
    } u;
};

// Inicializadores
RegExp *newEmpty(){
    RegExp *exp;

    exp = malloc(sizeof(RegExp));
    exp->tag = TAG_EMPTY;
    return exp;
}
RegExp *newChar(char ch){
    RegExp *exp;

    exp = malloc(sizeof(RegExp));
    exp->tag = TAG_CHAR;
    exp->u.charNode.c = ch;
    return exp;
}
RegExp *newStar(RegExp *filho){
    RegExp *exp;

    exp = malloc(sizeof(RegExp));
    exp->tag = TAG_STAR;
    exp->u.starNode.exp = filho;
    return exp;
}
RegExp *newConcat(RegExp *filho1, RegExp *filho2){
    RegExp *exp;

    exp = malloc(sizeof(RegExp));
    exp->tag = TAG_CONCAT;
    exp->u.concatNode.f1 = filho1;
    exp->u.concatNode.f2 = filho2;
    return exp;
}
RegExp *newUnion(RegExp *filho1, RegExp *filho2){
    RegExp *exp;

    exp = malloc(sizeof(RegExp));
    exp->tag = TAG_UNION;
    exp->u.unionNode.f1 = filho1;
    exp->u.unionNode.f2 = filho2;
    return exp;
}

/*Variáveis globais */
char c;
int p,cp,line; /* Posição, contagem de parênteses e linha*/
const char *types[] = {"EMPTY", "CHAR","STAR","CONCAT", "UNION"}; 

/* Funções auxiliares */
void printIndent(int lvl)
{
    int i =0;

    putchar('\n');
    for(i=0;i<(lvl*2);i++)
            putchar(' ');
}
void printTree(RegExp *tree, int indent_lvl)
{
    printf("%s",types[(int)tree->tag]);

    switch(tree->tag)
    {
    case TAG_EMPTY:
        return;
    case TAG_CHAR:
        printf(" %c",tree->u.charNode.c);
        return;
    case TAG_STAR:
        printIndent(indent_lvl+1);
        printTree(tree->u.starNode.exp,indent_lvl+1);
        return;
    case TAG_UNION:
        printIndent(indent_lvl+1);
        printTree(tree->u.unionNode.f1,indent_lvl+1);
        printIndent(indent_lvl+1);
        printTree(tree->u.unionNode.f2,indent_lvl+1);
        return;
    case TAG_CONCAT:
        printIndent(indent_lvl+1);
        printTree(tree->u.concatNode.f1,indent_lvl+1);
        printIndent(indent_lvl+1);
        printTree(tree->u.concatNode.f2,indent_lvl+1);
        return;
    }
    return;
}
void consume()
{
    c=getchar();
    p++;
}
void printError()
{
    fprintf(stderr,"Erro na linha %d, caractere na posicao %d:",line+1,p);
}

/* Parseadores por tipos*/
static RegExp* parseRegexp();
static RegExp* parseBasic(){
    RegExp *e;
    
    if(c=='(')
    {
        consume();
        cp++;
        e = parseRegexp();
        if(c!=')')
        {
            printError();
            fprintf(stderr,"\n\tFim de linha inesperado. (Esperando fechamento de parênteses)");
            exit(1);
        }
        else
        {
            consume();
            cp--;
        }
    }
    else
    {
        e =  newChar(c);
        consume();
    }
    return e;
}
static RegExp* parseStar(){
    RegExp *e1;

    e1 = parseBasic();

    while(c=='*'){
        consume();
        e1 = newStar(e1);
    }
    return e1;
}
static RegExp* parseConcat(){
    RegExp *e1,*e2;
    
    switch(c){
    case ')':
        if(cp==0)
        {
            consume();
            printError();
            fprintf(stderr,"\n\tCaractere ')' não esperado.");
            exit(1);
        }
        [[fallthrough]];
    case '\n':
    case '\0':
    case '|':
    case EOF:
        return newEmpty();
    }
    
    e1 = parseStar();
    e2 = parseConcat();

    if(e2->tag!=TAG_EMPTY)
        return newConcat(e1,e2);
    else
        return e1;
}
static RegExp* parseUnion(){
    RegExp *e1,*e2;

    if(c=='*'){
        consume();
        printError();
        fprintf(stderr,"\n\tCaractere '*' não permitido em inicio de expressoes.");
        exit(1);
    }
    
    e1 = parseConcat();
    if(c=='|'){
        consume();
        e2 = parseUnion();
        return newUnion(e1,e2);
    }
    
    return e1;
}
static RegExp* parseRegexp(){
    return parseUnion();
}
static RegExp* parseLine(){
    RegExp *e;
    if(c=='\n'){
        consume();
        e = newEmpty();
        return e;
    }
    e = parseRegexp();
    if(c=='\n')
        consume();
    return e;
}

int main()
{
    RegExp **expressions;
    int max_exp,i;

    p=0;
    max_exp = 4;
    line = 0 ;

    expressions = malloc(max_exp*sizeof(RegExp*));

    consume();
    while(c!=EOF){
        if(line==max_exp){
            max_exp*=2;
            expressions = realloc(expressions,max_exp*sizeof(RegExp*));
        }

        cp=0;
        p=0;
        expressions[line] = parseLine();
        line++;
    }
    
    for(i=0;i<line;i++)
    {
        printTree(expressions[i],0);
        printf("\n");
    }

    return 0;
}

