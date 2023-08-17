<?php


// caso exista informações na url, como em URL?a=123, este metodo pegaria um numero inteiro e atribuiria a valor

$valor = (int) $_GET["a"];

// pode haver mais de dois valores, como em ?a=123&b=27, e o codigo abaixo atribuiria a valor2

$valor2 = (int) $_GET["b"];


echo "<br>";

var_dump($valor);
echo "<br>";

var_dump($valor2);

echo $valor + $valor2;


/* existem outras variaveis de ambiente/pre definidas/super globais, como 

$_COOKIE
$_ENV
$_GET
$_POST
$_REQUEST
$_SESSION

*/

// ver a porta de acesso do usuario acessando, seria por exemplo:

$porta = $_SERVER["REMOTE_PORT"];






?>