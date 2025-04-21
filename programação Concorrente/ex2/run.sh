#!/bin/bash
nome_gabarito="gabarito.txt"
DATA_FILE="dados.csv"
FLAGS=("-O0" "-O1" "-O2" "-O3")
DIMENSOES=(100 1000 10000 100000 1000000 10000000)
MELHOR_FLAG=""
GABARITO=""
cria_gabarito(){
    # Calcula o número de primos até $1 e armazena em uma variável
    GABARITO=$(seq 1 $(($1-1)) | factor | awk 'NF==2 {print $1}' | wc -l)
    # echo "Número de primos até $1: $num_linhas_gabarito"
}
# Recebe o número de primos como argumento (saída do programa)
checa_gabarito(){

    num_linhas_saida=$1
    # echo "Número de primos na saída do programa: $num_linhas_saida"
    if [ "$num_linhas_saida" -ne "$GABARITO" ]; then
        echo "\nGabarito NÃO está OK: O número de primos não corresponde ao esperado."
        exit 1
    fi
}

checa_flag(){
    echo -e "\nGerando dados para analisar melhor flag...\n"
    for flag in "${FLAGS[@]}";do

        COMANDO="gcc ex2.c -o primetest -Wall -lm $flag";
        $COMANDO;

        for dim in "${DIMENSOES[@]}";do
            printf "\rGerando gabarito para n=%d" "$dim"
            cria_gabarito $dim
            printf "\rTestando para [Flag: %s  |  N= %d]" "$flag" "$dim"
            # programa <nome binario> <tipo execucao> <n threads>
            COMANDO="./primetest 1 $dim $DATA_FILE"
            # echo "$COMANDO"
            for ((i=1;i<=10;i++));do
                checa_gabarito $($COMANDO)
            done
        done
        S1="s/%flag/$flag/"
        sed -e $S1 -i $DATA_FILE
    done
    mkdir -p graficos_nprimos
    MELHOR_FLAG=$(python3 analise.py 1 $MAX_T)
}

gera_dados(){

    COMANDO="gcc ex2.c -o primetest -Wall -lm $MELHOR_FLAG";
    $COMANDO;
    echo -e "\nGerando dados para....\n"
    for dim in "${DIMENSOES[@]}";do
        printf "\rGerando gabarito para n=%d" "$dim"
        cria_gabarito $dim
        for n_threads in $(seq 2 $MAX_T);do
            # programa <nome binario> <tipo execucao> <n threads>
            COMANDO="./primetest $n_threads $dim $DATA_FILE"
            printf "\rDimensao: %d | Numero de Threads: %d  " "$dim" "$n_threads"

            for ((i=1;i<=10;i++));do
                checa_gabarito $($COMANDO)
            done
        done
    done
    S1="s/%flag/$MELHOR_FLAG/"
    sed -e $S1 -i $DATA_FILE
}

analisa_dados(){
    mkdir -p graficos_nprimos
    # echo -e "\n\t maximo threads = $MAX_T"
    python3 analise.py 2 $MAX_T
    echo -e "\n\tgraficos gerados!"
}



if [ $# -ne 1 ];then
    MAX_T=4
    echo "vc pode passar o numero maximo de threads como o primeiro argumento para este script."
    echo "por padrao, o maximo é 4"
else
    MAX_T=$1
fi
echo -e "\n\tNumero máximo de threads selecionado = $MAX_T\n"

if [ ! -f $DATA_FILE ]; then
    touch $DATA_FILE
    echo "\"flag\",\"n_threads\",\"dimensao\",\"t_init\",\"t_exec\",\"t_fin\"" >> $DATA_FILE
fi

awk -F',' 'NR > 1 {count[$1]++} END {if (NR == 1) {print "Nenhuma linha de dados encontrada"; exit 1} for (flag in count) {if (count[flag] < 10) {print flag, count[flag]; found=1}} if (!found) print "Foram encontrados dados suficientes para encontrar a melhor flag"}' $DATA_FILE
if [ ! $? -eq 0 ];then
    checa_flag
else    
    MELHOR_FLAG=$(python3 analise.py 1 $MAX_T)
    echo -e "\n\tMelhor flag encontrada: $MELHOR_FLAG\n"
fi
gera_dados
analisa_dados