package aula_03;

public class Carro
{
	private class Porta{
	
		private boolean aberta;

		private void fechaPorta()
		{
			aberta=false;
		}

		private void abrePorta()
		{
			aberta=true;
		}

		private boolean isAberta()
		{
			return this.aberta;
		}	
	}
	private Porta[] lista_portas; 
	private String marca;
	private String modelo;

	public Carro(int qtd_portas) // metodo construtor recebendo a qtd de portas
	{
		int i;
		this.lista_portas = new Porta[qtd_portas]; // criar o array nao cria os objetos!
		
		for(i=0;i<qtd_portas;i++)    //criando cada um dos objetos
			lista_portas[i] = new Porta();
	}
	
	public void abrePortas()
	{
		int i;
		for(i=0;i<this.lista_portas.length;i++)
			this.lista_portas[i].abrePorta();
	}

	public void abrePorta(int n)
	{
		if(n>=this.lista_portas.length) //validacao
			return;

		this.lista_portas[n].abrePorta();
	}

	public void fechaPortas()
	{
		int i;
		for(i=0;i<this.lista_portas.length;i++)
			this.lista_portas[i].fechaPorta();
	}

	public void fechaPorta(int n)
	{
		if(n>=this.lista_portas.length) //validacao
			return;

		this.lista_portas[n].fechaPorta();
	}

	public int contaPortasAbertas()
	{
		int i,c=0;
		for(i=0;i<this.lista_portas.length;i++)
		{
			if(this.lista_portas[i].isAberta())
				c++;
		}
		return c;
	}
	public int getQtdPortas()
	{
		return this.lista_portas.length;
	}	
}