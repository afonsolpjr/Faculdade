<?php

// diferença das aspas

$nome = "Afonso";

$nome2 = 'Pires';

// no echo ela dá normalmente as duas

var_dump($nome);
echo "<br>";

echo "<br>";
var_dump($nome2);
echo "<br>";


echo $nome . ' '  . $nome2;

//mesma coisa:

echo "<br>";
echo "$nome $nome2";

// não é a mesma coisa que

echo "<br><br>cagando tdo:";
echo "<br>";

echo '$nome $nome2';

echo "<br>";

// funcoes
echo "<br>testando strtoupper: ";

echo strtoupper("João");
echo "<br>testando strtolower:";
echo strtolower("João");

$musica = "O SAPO NAO LAVA O PE";

$musica = str_replace("A","i",$musica);

$musica = str_replace("O","i",$musica);

$musica = str_replace("E","i",$musica);

echo "<br>" . $musica;















?>



