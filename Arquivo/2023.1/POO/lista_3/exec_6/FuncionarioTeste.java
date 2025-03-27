package lista_3.exec_6;

public class FuncionarioTeste
{
    private static Funcionario func;
public static void main(String args[])
{
    String nome = new String(nome_random());
    double salario;

                                            //testando criacao só com nome
    System.out.println("\n\tTestando criacao de funcionario com nome \'" + nome + "\'\n");

    func = new Funcionario(nome);

                                            //testando criacao com nome e salario
    nome = new String(nome_random());
    salario = System.currentTimeMillis()%10000;

    System.out.println("\n\tTestando criacao de funcionario com nome \'" + nome + "\'"
    + "\n\te salario = " + salario + "\n");

    func = new Funcionario(nome,salario);

                                            //testando getnome

    if(func.getNome()==nome)
        System.out.println("\n nome do funcionario checado, valor = " + func.getNome());
    else
    {
        System.out.println("erro no metodo getNome\n");
        return;
    }
                                                         //testando getsalario

    if(func.getSalariohora()==salario)
        System.out.println("\ngetSalario checado! valor = " + salario);
    else
    {
        System.out.println("\nErro no metodo getSalario.\n");
        return;
    }
                                                      //testando id

    if(func.getIdFuncionario()==2)
        System.out.println("\nId atribuida corretamente! valor esperado = 2, retornado = " + func.getIdFuncionario());
    else
    {
        System.out.println("\nId atribuida errada. esperado valor = 2, retorno = " + func.getIdFuncionario());
        return;
    }
                                                // testando proxId

    if(Funcionario.getProxId()==3)
        System.out.println("\nproxId atribuida corretamente! valor esperado = 3, retornado = " + Funcionario.getProxId());
    else
    {
        System.out.println("\nproxId atribuida errada. esperado valor = 3, retorno = " + Funcionario.getProxId());
        return;
    }
                                                 // testando atualizacao de nome

    nome = new String(nome_random() + ' ' + nome_random());
    System.out.println("\n\ttestando nome sem sobrenome... espera-se aviso de inserçao de sobrenome. retorno :");

    func.atualizaNome(nome_random());

    System.out.println("\n\tTestando nome com sobrenome = \'" + nome + "\' \n");

    func.atualizaNome(nome);

    System.out.println("Novo nome = \'" + func.getNome() + "\' \n");

                                                         //testando abaixar o salario

    System.out.println("\n\tTestando abaixar o salario.");

    func.atualizaSalarioHora(salario-1);

    if(func.getSalariohora()==salario-1)
    {
        System.out.println("Erro na atualizacao de salario");
        return;
    }
    else
    {
        System.out.println("\nSalario impedido de ser abaixado." +
        "\n\n\tTestando aumento de salario..");
    }

    func.atualizaSalarioHora(salario+1);

    if(func.getSalariohora()==salario+1)
        System.out.println("Salario atualizado para " + (salario+1) + "\n");
    else
    {
        System.out.println("erro no aumento de salario.");
        return;
    }
    salario=func.getSalariohora();

                                                                     // testando adicao de horas

    System.out.println("\n\tTestando adicao de 3 horas de trabalho...");

    func.adicionaDiaDeTrabalho(3);
    if(func.getHoras()==3)
    {
        System.out.println("Erro na atualizacao de horas.");
        return;
    }
    else
        System.out.println("Impedido.");

    System.out.println("\n\tTestando adicao de 5 horas de trabalho..");

    double horas = 5;
    func.adicionaDiaDeTrabalho(horas);

    if(func.getHoras()==5)
        System.out.println("horas adicionadas com sucesso = " + func.getHoras() +
        "\n\n\t Testando calculo de salario...");

                                                            //testando calculo de salario

    if(func.calcularSalarioMes()==salario*horas)
    {
        System.out.println("Salario de " + func.calcularSalarioMes() + " calculado corretamente.");
    }
    else
    {
        System.out.println("salario calculado errado.");
        return;
    }


                                                //testando reiniciar mes de trabalho
    System.out.println("\n\tTestando zerar horas de trabalho..");
    func.reiniciaMesTrabalho();
    if(func.getHoras()==0)
        System.out.println("Mes zerado com sucesso");
    else
    {
        System.out.println("erro ao reinicar mes");
        return;
    }



}

private static String nome_random()
{
    char[] str = new char[6];
    String nome;
    int i;

    for(i=0;i<6;i++)
    {             //criar char de valor entre 97 e 123
        str[i] = (char) (97 + System.currentTimeMillis()%26);
    }
    nome = new String(str);
    return nome;
}
}