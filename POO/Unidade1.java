import java.util.Scanner;


public class Unidade1
{
public static void main(String[] args)
{
    double raio;
    Scanner read = new Scanner(System.in);
    System.out.println("Olá mundo!");
    
    // System.out.print("Me diga seu nome: ");
    // nome = read.nextLine();
    // System.out.print("Sua idade: ");
    // idade = read.nextInt();

    // System.out.println("Olá " + nome + ", você tem " + idade + " anos.");

    while(true) //calculo da area do circulo
    {
        System.out.print("\nInsira o raio do círculo para calculo da área, ou 0 para sair: ");
        raio = read.nextDouble();
        if(raio==0)
            break;
        System.out.println(
            "O círculo de raio " + raio + "cm tem área de " +
            (3.14159 * raio * raio));
    }
    read.nextLine();
    
    //leitura de dados

    int idade;
    double altura;
    String nome;
    System.out.println("Insira seu nome: ");
    nome = read.nextLine();
    System.out.println("Insira sua altura: ");
    altura = read.nextDouble();
    System.out.println("Insira sua idade");
    idade = read.nextInt();

    System.out.println(
        "Olá " + nome + "!\n" +
        "Você tem " + idade + " anos e " + altura + " de altura.\n");

    double p1,p2;
    System.out.println("Insira as notas das P1 e P2 separado por espaço (nota negativa para pular):");
    p1 = read.nextDouble();
    if(p1>=0)
    {
        p2 = read.nextDouble();
        double media = (p1+p2)/2;
        if(media>=7)
        {
            System.out.println("\nParabéns!\nVocê foi aprovado com média " + media);
        }
        else if (media >=3)
        {
            System.out.println(
                "\nMedia = " + media +
                "\nVocê está de prova final." );
        }
        else
        {
            System.out.println(
                "\nMedia = " + media +
                "Você foi reprovado diretamente.");
        }
    }

    //fatorial
    int n,i,fat;
    System.out.println("\n Insira o numero para cálculo do fatorial: ");
    n = read.nextInt();
    i=n;
    for(fat=1;n>0;n--)
        fat *= n;
    
    System.out.println(
        i + "! = " + fat);


    read.close();
}    
}
