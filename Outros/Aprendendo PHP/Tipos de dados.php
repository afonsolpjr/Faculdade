<?php
// Dando um olá mundo com uma string:

$string = "Afonso";

$inteiro = 1;

$float = 3.2;

$boolean = True;

$array = array("nome",2,3.2,False);

$objeto = new DateTime();

$resource = fopen("Tipos de dados.php", "r");

$nulo = NULL;

echo "<br>";
var_dump($string);


echo "<br>";
var_dump($inteiro);

echo "<br>";
var_dump($float);


echo "<br>";
var_dump($boolean);


echo "<br>E o array?<br>";
var_dump($array);


echo "<br> O array pode ter varios tipos misturados!<br>";



echo "<br>";
var_dump($objeto);


echo "<br>";
var_dump($resource);


echo "<br>";
var_dump($nulo);






// Deletando a variavel $ola

// unset($ola);




?>