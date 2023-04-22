package lista3.exec_5;

public class ContaTeste
{
    private static Conta conta = new Conta();
public static void main(String[] args) 
{

    System.out.println("\nConta criada com saldo = " + conta.pegaSaldo() );

    testa_deposito();

    testa_pega();

    testa_saque();

}

    private static void testa_deposito()
    {
        double n;
        n = System.currentTimeMillis() % 100000;
        System.out.println(
            "\n\n\t[Testando deposito]\n" +
            "Saldo antes = " + conta.pegaSaldo() +
            "\nTentando depositar " + n + "...."
            );

        conta.deposita(n);

        System.out.println(
            "\nFeito!" +  "\nSaldo depois = " + conta.pegaSaldo() );
    }

    private static void testa_pega()
    {
        System.out.println("\n\t[testando pegar o saldo..]" +
        "\nSaldo = " + conta.pegaSaldo());
    }

    private static void testa_saque()
    {
        System.out.println("\n\t[testando o saque...]" +
            "\n Tentando sacar " + (conta.pegaSaldo()-1) + " [...]");

        if(conta.saca(conta.pegaSaldo()-1))
        {
            System.out.println("\n\tSaque bem sucedido!" +
            "\nSaldo apos saque = " + conta.pegaSaldo());
        }
        else
            System.out.println("\n\tSaque falhou!");

        System.out.println("\ntentando sacar 2 reais...");

        if(conta.saca(2))
        {
            System.out.println("Problemas no saque. Não havia 2 reais na conta.");
        }
        else
            System.out.println("Saque impedido.\nTestes de saque concluido.\n");
    }

}