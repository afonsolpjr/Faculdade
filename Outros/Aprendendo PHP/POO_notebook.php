<?php



class Endereco
{
  private $numero;
  private $logradouro;
  private $cep;
  private $cidade;
  private $estado;
  public $pais;

  public function __construct($num,$log,$cep,$cidade,$estado,$pais)
  {
    $this->numero = $num;
    $this->logradouro=$log;
    $this->cep = $cep;
    $this->cidade = $cidade;
    $this->estado = $estado;
    $this->pais = $pais;

  }

  public function __destruct()
  {
    echo "<br><br><br> DESTRUIDO O ENDEREÇO!! <br><br><br>";
  }

  public function __toString()
  {
    return "<br><br>" . $this->logradouro . " " . $this->numero . ", " . $this->cidade
    . ", " . $this->estado . "<br>" . $this->cep . ", ". $this->pais;

  }

}

 $bobo = new Endereco(0,"Rua dos Bobos","00000-000","Bobópolis","Bobolândia","Bostil");

 var_dump($bobo);

 echo $bobo;

 unset($bobo);


 // ENCAPSULAMENTO
 echo "<br>__________________parte sobre encapsulamento______________________<br>";
 class Pessoa
 {
   public $nome = "Rafael Ernesto Guevara de la Sierna";
   protected $idade = 32;
   private $senha = "123moscou";

   public function get_All()
   {
     echo "<br>" . $this->nome;
     echo "<br>" . $this->idade;
     echo "<br>" . $this->senha . "<br>";
   }
 }

 $p1  = new Pessoa();

 $p1->get_All();


 class Comunista extends Pessoa {

   public function get_All()
   {
     echo "<br><br>" . get_class($this) . "<br>";
     echo "<br>" . $this->nome;
     echo "<br>" . $this->idade;
     echo "<br>" . $this->senha . "<br>";
   }

 };

 $p2 = new Comunista();

 echo "<br><br> pessoa 2:<br>";
 $p2->get_All();
 get
 ?>
