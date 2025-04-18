#!/bin/bash
$nome_gabarito="gabarito.txt"
cria_gabarito(){
    # echo -e "Criando gabarito....\n"
    truncate -s 0 $nome_gabarito
    seq 1 $1 | factor | awk 'NF==2 {print $1}' | sed 's/:/''/' >> gabarito.txt
    # echo -e "Gabarito criado\n"
}

# Espera a saída do programa como argumento
checa_gabarito(){
    numeros=$($1)
}

cria_gabarito $1


grep '\b17\b' $nome_gabarito