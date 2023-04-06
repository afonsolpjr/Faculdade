import java.util.Scanner;

public class Ex3 {

public static void main(String[] args)
{
    Scanner input = new Scanner(System.in);

    double raio,volume;
    
    raio = input.nextDouble();
    input.close();
    
    volume = (4/3.0) * raio * raio * raio * (3.14159);
    System.out.printf("VOLUME = %.3f\n",volume);
}
    
}
