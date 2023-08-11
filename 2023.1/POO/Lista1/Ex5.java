import java.util.Scanner;

public class Ex5 {

public static void main(String[] args)
{
    Scanner input = new Scanner(System.in);

    int tempo, velocidade,km;
    double litros;

    tempo = input.nextInt();
    velocidade = input.nextInt();
    input.close();
    km = tempo*velocidade;

    litros = km/12.0;

    System.out.printf("%.3f\n",litros);
}
    
}
