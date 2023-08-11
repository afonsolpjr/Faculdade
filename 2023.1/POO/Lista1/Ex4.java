import java.util.Scanner;

public class Ex4 {

public static void main(String[] args) {

    Scanner input = new Scanner(System.in);

    double a,b,c=0;
    char opcao;

    while(true)
    {
        System.out.println(
            "\n\t[ Escolha o numero da operação ou 's'\\'S' para sair. ]\n" +
            "[1] Adição - a+b \n[2] Subtração - a-b\n" +
            "[3] Multiplicação - a*b\n[4] Divisão - a/b \n"
        );
        opcao = input.nextLine().charAt(0); //pegando só o 1º char
        opcao -= '0'; //conversao pela tabela ascii
        
        if (opcao > 4 || opcao < 1)
            break;
        
        System.out.println("\n\t[Digite os 2 valores a e b separados por espaço ]");
        a = input.nextDouble();
        b = input.nextDouble();


        switch(opcao)
        {
        case 1:
            c=a+b;
            break;
        
        case 2:
            c = a-b;
            break;

        case 3:
            c = a*b;
            break;
        
        case 4:
            c = a/b;
            break;
        }

        System.out.println("Resultado = " + c);
        input.nextLine();
    }
    input.close();
}

}
