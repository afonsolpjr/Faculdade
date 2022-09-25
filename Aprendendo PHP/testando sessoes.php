<a href="/session/teste.php"> <button>Ir para criador de sessão</button></a>

<?php

//abrindo e testando a sessão


session_start();



echo "<br> O nome da sessão é : ". $_SESSION['nome'];




?>




// no teste.php



<form> 
    Nome da sessão: <input type="text" name="nome"> <br>
</form> 

<?php


//criando sessoes

session_start();
if($_GET)
{
    $_SESSION['nome'] = $_GET['nome'];
}
else{
    echo "<br> Dê um nome à sessão para voltar!";
}
if(isset($_SESSION['nome']))
{
    echo "<br> nome da sessão atualizada<br>";
    echo "<a href=\"../index.php\"> <button>Ir para index.php</button></a>";
}

?>
