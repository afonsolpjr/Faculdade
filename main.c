/* Trabalho 2 - Análise Léxica
===========================


O objetivo deste trabalho é construir um algoritmo
para converter uma expressão regular em uma árvore
que representa a expressão.


Formato da entrega
------------------

Entregue um arquivo ZIP com o "main.c" e o "README.txt".
Coloque um comentário com o seu nome no topo do arquivo.
O readme deve explicar como compilar e rodar o programa.

*/


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

