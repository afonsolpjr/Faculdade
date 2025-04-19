#!/bin/bash
nome_gabarito="gabarito.txt"

cria_gabarito(){
    # echo -e "Criando gabarito....\n"
    truncate -s 0 $nome_gabarito
    seq 1 $1 | factor | awk 'NF==2 {print $1}' | sed 's/:/''/' >> $nome_gabarito
    # echo -e "Gabarito criado\n"
}

# Espera a saída do programa como argumento
checa_gabarito(){

# Run the C program and process its output line by line
./teste 1 $1 | while read -r number; do
    # Check if the number exists in the prime file
    if grep -Fxq "$number" "$PRIME_FILE"; then
        echo "$number is in the prime list."
    else
        echo "$number is NOT in the prime list."
        exit 1
    fi
done

}

gcc ex2.c -o teste -Wall -lm 
cria_gabarito $1

checa_gabarito