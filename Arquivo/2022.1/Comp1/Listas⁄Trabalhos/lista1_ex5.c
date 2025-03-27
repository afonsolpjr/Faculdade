#include <stdio.h>

int main(void){

  float n1,n2,m;
  puts("\nInsira a primeira nota:");
  scanf("%f", &n1);

  puts("\n Insira a segunda nota:");
  scanf("%f", &n2);

  m=(n1+n2)/2;
  printf("\nMédia final do aluno=%.1f",m);

  if (m>=5) {
    puts("\nAprovado!");
  }
  else{
    puts("\nReprovado!");
  }
  return 0;
} 
/*   SAÍDA DO PROGRAMA:


Insira a primeira nota: 6

Insira a segunda nota: 4

Média final do aluno=5.0
Aprovado!



*/

