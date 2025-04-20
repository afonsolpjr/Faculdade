#!/bin/bash
nome_gabarito="gabarito.txt"

cria_gabarito(){
    # echo -e "Criando gabarito com primos até $1....\n"
    truncate -s 0 $nome_gabarito
    seq 1 $(($1-1)) | factor | awk 'NF==2 {print $1}' | sed 's/://' >> $nome_gabarito
    # echo "Gabarito criado"; cat $nome_gabarito; echo -e "\n"
}

# Espera a saída do programa como argumento
checa_gabarito(){

    # Gera a saída do programa e compara com o gabarito
    if diff <(./teste 1 $1) $nome_gabarito >/dev/null; then
        echo "Gabarito OK: A saída do programa está correta."
    else
        echo "Gabarito NÃO está OK: A saída do programa não corresponde ao gabarito."
        exit 1
    fi
}

gcc ex2.c -o teste -Wall -lm 
cria_gabarito $1
checa_gabarito $1


# ./teste 1 50 | while read -r number;do 
#     if grep -q $number gabarito.txt
#         then echo "oi"
#     else 
#         echo "asdiufasf $number"
#     fi
# done