#!/bin/bash



MAX_VETOR=${1:?"Tamanho máximo do vetor não fornecido."}

#{START..END..INCREMENT}
echo "[" >> dados.json
for (( tam_vetor=1;tam_vetor<MAX_VETOR;tam_vetor++ ))
do
    ./gerador $tam_vetor bin > /dev/null
    echo "começando para vetores de tamanho $tam_vetor..."
    for (( num_thr=1;num_thr<tam_vetor;num_thr++))
    do
        ./prod_interno $num_thr bin >> dados.json
    done
done
echo "]" >> dados.json