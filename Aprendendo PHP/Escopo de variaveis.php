<?php

$data = 1917;


function var_global(){

    global $data;
    
    echo "<br> Uso de var global: ";
    echo $data;
}

function var_local(){

    $data = 1945;
    
    echo "<br> Uso de var local: ";
    echo $data;
}

// testando uso de var global:

var_global();

var_local();








?>