<?php

setlocale(LC_ALL,'ptb'); // só funciona pra strftime parece...


echo date("H:i:s  l eT   d/m/Y U"); //tem varias formatações


echo "<br><br>O número de segundos que se passaram desde a era unix é ". time() . "<br><br>";
echo "Horas q se passaram: " . time()/3600;
echo "<br>dias q passaram: " . time()/(3600*24);
echo "<br> anos q passsaram: " . time()/(3600*24*365);

var_dump(time());

echo "<br>" . strftime("%A %B"). "<br><br><br>";

var_dump(strftime("%A %b %c %d"));


echo "<br><br>";
// mexendo  com classe DateTime




$dia = new DateTime();
$periodo = new DateInterval("P7D");           //criando classe intervalo de data que é de 7 dias
echo $dia->format("d/m/y H:i:s");
$dia->add($periodo);
echo "<br><br>". $dia->format("d/m/y H:i:s");


// exibir timestamp de uma semana a frente do atual:


$ts = strtotime("+1week");

echo "<br> Timestamp alterado:         " . date("H:i:s d/m/Y",$ts);



echo "<br><br> E pra finalizar, data com timestamp de quando esse codigo foi escrito! (só que o horário tá +5 em relacao ao brasil)";
echo "<br>". date("H:i:s  T   d/m/Y U",1664476748)





?>