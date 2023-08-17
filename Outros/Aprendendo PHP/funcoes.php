<?php


//rotina

function ola($texto,$texto2="ao site"){   //$texto2 por default é "ao site"


    echo "<br><br>Ola $texto!<br>Seja bem vindo $texto2!<br>"; //posso usar $texto sem formatacao dentro de aspas duplas
}

function parametros(int ...$valores){  // parametros infinitos
    foreach($valores as $item)
    {
        echo "<br>". $item ."<br>";
    }
}

ola("Caralho!!!","porra!!!!");
ola("Desculpa por xingar antes.");


parametros(1,2,3,4,5,6,7,8,17);
//funcoes anonimas



$anon = function ($a){

    echo "<br><br>O resto de $a por 3 é ". $a%3 . "<br><br>";

};

echo $anon(3);

$anon(25);
var_dump($anon);











?>