<?php


class Produto {

    public $nome;

    public $descricao;

    public $preço;

    private $custo;

    public function getCusto()
    {
        return $this->custo;
    }

    public function setCusto($a)
    {
        $this->custo = $a;
    }

    public function descrever()
    {
        echo "<br><br>Descrição do Produto \"". $this->nome .  "\" :<br> " . $this->descricao;
        echo "<br>";
    }

    public static function lucro($preco=NULL, $custo=NULL)
    {
        $lucro = $preco/$custo;

        $lucro -= 1;
        $lucro *= 100;

        return "<br> O lucro deste produto é de ". $lucro . "% <br><br>";

    }
}
    


$bone = new Produto();

$bone->nome = "Boné maneiro";

$bone->descricao = "Bone da america latina";

$bone->descrever();

if($bone->getCusto())
{
    echo "<br> O produto \"" . $bone->nome . "\" tem o preço de custo cadastrado.<br>";
}
else
{
    echo "<br> O produto \"" . $bone->nome . "\" NÃO tem o preço de custo cadastrado.<br>";
}
$bone->preço = 120;
$bone->setCusto(20);


if($bone->getCusto())
{
    echo "<br> O produto \"" . $bone->nome . "\" tem o preço de custo cadastrado ( R$". $bone->getCusto() ." )<br>";
}
else
{
    echo "<br> O produto \"" . $bone->nome . "\" NÃO tem o preço de custo cadastrado.<br>";
}


// static methods


//permite que vc acesse atributos e metodos mesmo sem instanciar objetos


echo $bone->lucro($bone->preço,$bone->getCusto());

echo Produto::lucro(20,13);

// sobre proteção de atributos?? 


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

?>