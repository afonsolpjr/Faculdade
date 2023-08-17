<?php

$arrai = array();

for($i=0;$i<10;$i++)
{
  $arrai[$i]=$i+1;
}




//fazendo 2^n
foreach ($arrai as $indice => $expoente) {

    echo "</br> O indice desse expoente é ". $indice ;
    echo "</br> 2^" . $expoente . " = " . (2**$expoente)."</br> </br>";
}

//printando o array
print_r($arrai);


//testando array de chaves, ou dicionario sei la ein

$pessoas = array();

array_push($pessoas, array(
    'nome'=>'Jessica',
    'idade'=> 26
));

array_push($pessoas, array(
    'nome'=>'Afonso',
    'idade'=> 26
));
//testando pessoas e json

$json = json_encode($pessoas);

$pessoas_json = json_decode($json, true);

echo "<br><br>" . $pessoas_json[0]['nome'];




?>
