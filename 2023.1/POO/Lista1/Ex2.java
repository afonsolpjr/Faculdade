import java.util.Scanner;

/* Vou considerar a entrada sendo a mesma do beecrowd.
  Que são duas linhas com três inteiros, uma de pratos disponiveis
  e outra do numero pedidos.
  */
class Ex2 
{
public static void main(String[] args)
{
  Scanner input = new Scanner(System.in);
  int[] pedidos = new int[3];
  int[] disponiveis = new int[3];

  int i,total;
  for(i=0;i<3;i++)    //lendo numero de pratos
    disponiveis[i] = input.nextInt();

  for(i=0;i<3;i++)     //lendo pedidos
    pedidos[i] = input.nextInt();
  input.close();

  for(i=0,total=0;i<3;i++) //vendo a diferença entre os 2 e somando-as
  {
    if(pedidos[i]>disponiveis[i])
      total += pedidos[i]-disponiveis[i];
  }

  System.out.println(total);

}

}
