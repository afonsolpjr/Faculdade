package aula_03;
import java.util.Scanner;


public class CarroTeste
{
	
	public static void  main(String args[])
	{
		criaObjeto();
	}

	public static void criaObjeto()
	{
		int n;
		Carro carro;
		Scanner input = new Scanner(System.in);
		
		System.out.println("\nInsira o numero de portas: ");
		n = input.nextInt();
		input.close();
		carro = new Carro(n);

		if(carro.getQtdPortas()==n)
		{
			System.out.println("Carro com " + carro.getQtdPortas() +
             " portas criado!");
		}
		else
		{
			System.out.println("Metodo construtor errado.\n");
		}
	}







}