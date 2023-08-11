package lista_3.exec_6;

public class Funcionario
{
	// fazer a atualizarNome e algumas exceções
	private String nome;
	private double salario_hora;
	private final int id_func;
	private static int proxId = 1;
	public static final double salario_hora_min=12.5;
	private double hrs_trabalhadas_mes;

	public Funcionario(String nome)
	{
		this.nome = nome;
		this.id_func = proxId++;
		this.salario_hora = Funcionario.salario_hora_min;
		System.out.println("Funcionario " + this.nome + " criado com código: #" + id_func);
	}

	public Funcionario(String nome, double salario)
	{
		this.nome = nome;
		this.id_func = proxId++;
		this.salario_hora = salario;

		System.out.println(
			"Funcionario " + this.nome + " criado com código: #" + id_func +
			"\n Salario registrado de R$" + salario_hora + " por hora.");
	}

	public String getNome()
	{
		return this.nome;
	}

	public int getIdFuncionario()
	{
		return this.id_func;
	}

	public double getSalariohora()
	{
		return this.salario_hora;
	}

	public double calcularSalarioMes()
	{
		return this.salario_hora * this.hrs_trabalhadas_mes;
	}

	public double getHoras()
	{
		return this.hrs_trabalhadas_mes;
	}

	public void reiniciaMesTrabalho()
	{
		this.hrs_trabalhadas_mes = 0;
	}

	public void atualizaNome(String novo_nome)
	{
		int i=0; 
		
		//checar se tem espaco
		i = novo_nome.indexOf(' ');

		if( i !=-1 && i+1 < novo_nome.length() && novo_nome.charAt(i+1)!=' ') //se tem espaço, e se o espaço n for o ultimo
		{																	 // e se tem algum char dps do espaço q n seja espaço
			this.nome = novo_nome;
		}
		else
		{
			System.out.println("Insira um sobrenome.");
		}
	}

	public void atualizaSalarioHora(double novo_salario)
	{
		if(novo_salario < this.salario_hora)
		{
			return;
		}
		this.salario_hora = novo_salario;
	}

	public static int getProxId()
	{
		return Funcionario.proxId;
	}
	
	public void adicionaDiaDeTrabalho(double horas)
	{
		if(horas<4)
		{
			return;
		}
		this.hrs_trabalhadas_mes += horas;
	}
}
