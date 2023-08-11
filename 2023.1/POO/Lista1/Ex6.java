import java.util.Scanner;
public class Ex6 {
    
public static void main(String[] args) 
{
    Scanner input = new Scanner(System.in);
    int c,testes=0;
    long n;
    int[] testados = new int[101];

    System.out.println("\tPense em um numero entre 0 e 100!" +
    "\nPensou? Insira 1 para continuar");

    c = input.nextInt();

    if(c != 1) 
    {
        input.close();
        return;
    }

    while(c != 1 || c != 3) // enquanto nao acertar ou nao pedir pra sair
    {
        while(true)         //gerando um numero aleatorio que ainda nao foi tentado
        {
            n = System.currentTimeMillis() % 101;
            if(testados[(int)n]==1) // se ja foi o numero, espaço 'n' do vetor está igual a 1
                continue;
            else
            {
                testados[(int)n]=1;
                break;
            }
        }
    testes++;
    System.out.println(
    "Deixe-me adivinhar. Você pensou em " + n + "?\n" +
    "[1] Acertou!\n" +
    "[2] Errou! Tente outra vez.\n" +
    "[3] Cansei, me tire daqui.");
    c = input.nextInt();

    if(c==1)
    {
        System.out.println("Oba! Acertei em " + testes + " tentativas!\n");
        break;
    }
    else if (c==2)
        continue;
    else if(c==3)
        break;
    }
    input.close();

}
}
