import java.util.Scanner;

class Main
{
    public static void main(String[] args) {

        Scanner read = new Scanner(System.in);

        System.out.println("Mostrar primos até que numero?");
        int fator,x,limite = read.nextInt();

        for(x=2;x<limite+1;x++)
        {
            for(fator=2;fator<x;fator++)
            {
                if((x%fator)==0)
                {
                    fator = -1;
                    break;
                }
            }
            if(fator<0)
                continue;
            else
                System.out.println( x + " é primo.");
        }

    }
}