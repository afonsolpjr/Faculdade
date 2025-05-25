#!/bin/bash
if [ ! -f "programa" ];then
    gcc ex3.c -o programa -lm -Wall
    if [ $? -ne 0 ];then
        echo "Erro ao compilar o programa"
        exit 1
    fi
fi

saida=$(./programa $1 $2 $3)

echo -e $saida

primos_encontrados=$(echo $saida |grep -oP '\d+$')
gabarito=$(seq 1 $1 | factor | grep -cP "^(\d+): \1")

if [ "$primos_encontrados" -ne "$gabarito" ];then
    echo "Gabarito NÃO está OK: O número de primos não corresponde ao esperado."
    exit 1
else
    echo "O número de primos corresponde ao esperado."
fi
echo -e 