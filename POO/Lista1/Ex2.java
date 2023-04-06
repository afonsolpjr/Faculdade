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

    int i,falta,total;
    for(i=0;i<3;i++)
        disponiveis[i] = input.nextInt();

    for(i=0;i<3;i++)
        pedidos[i] = input.nextInt();

    for(i=0,total=0;i<3;i++)
    {
      if(pedidos[i]>disponiveis[i])
        total += pedidos[i]-disponiveis[i];
    }

    System.out.println(total);
    


    

    

}

    
}
