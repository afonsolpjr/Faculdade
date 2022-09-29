
<a href="teste.php"> <button> Ir para teste.php </button> </a>
<?php

//abrindo e testando a sessão


session_start();




var_dump($_SESSION);






?>


// no teste.php

<form> 
    Nome da sessão: <input type="text" name="nome"> <br>
</form> 
<a href="index.php"> <button> Ir para index.php </button> </a>

<form method="post">
<br><input type="submit"  value="Unset Session" name="unset"> </form>


<?php


//criando sessoes

session_start();

if(isset($_GET['nome']))
{
    $_SESSION['nome'] = $_GET['nome'];
}

if(isset($_POST['unset']))
{
    echo "<br> Sessão Limpa. <br>";

    session_unset();
    
}



if(isset($_SESSION['nome']))
{
    echo "<br> Nome da sessão já existe:". $_SESSION['nome'] . "<br>";
}
else
{
    echo "<br> Sessão não tem nome!<br>";
}
?>
