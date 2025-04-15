#!/bin/bash

#NUMERO MAXIMO DE THREADS DO PC:
if [ $# -ne 1 ];then
    MAX_T=4
    echo "vc pode passar o numero maximo de threads como o primeiro argumento para este script."
    echo "por padrao, o maximo é 4"
else
    MAX_T=$1
fi
echo -e "\n\tNumero máximo de threads selecionado = $MAX_T\n"


atividade1(){
    echo -e "\n Gerando dados para analisar melhor flag...\n"
    for flag in "${FLAGS[@]}";do

                COMANDO="gcc $flag -o matmul -Wall matmul.c";
                $COMANDO;

                for dim in "${DIMENSOES[@]}";do
                    printf "\rFlag: %s | Dimensão %d" "$flag" "$dim"
                    # programa <nome binario> <tipo execucao> <n threads>
                    NOME_BIN="binarios/matmul$dim.bin"
                    COMANDO="./matmul $NOME_BIN 1 "
                    for ((i=1;i<=10;i++));do
                        OUTPUT=$($COMANDO)
                        #substituicoes
                        S1="s/%flag/$flag/"
                        echo $OUTPUT | sed -e $S1 >> execucoes.csv
                    done
                done
            done
    mkdir -p graficos_matmul
    MELHOR_FLAG=$(python3 analise.py 1 $MAX_T)
    echo -e "\n\tFlag com o menor tempo médio geral: $MELHOR_FLAG"
}

atividade2(){
    COMANDO="gcc $MELHOR_FLAG -o matmul -Wall matmul.c";
    $COMANDO;
    echo -e "\n Gerando dados para....\n"
    for dim in "${DIMENSOES[@]}";do

        for n_threads in $(seq 2 $MAX_T);do
            # programa <nome binario> <tipo execucao> <n threads>
            NOME_BIN="binarios/matmul$dim.bin"
            COMANDO="./matmul $NOME_BIN $n_threads"
            printf "\rDimensao: %d | Numero de Threads: %d" "$dim" "$n_threads"

            for ((i=1;i<=10;i++));do
                OUTPUT=$($COMANDO)
                S1="s/%tipo/$tipo_execucao/"         #substituicoes
                S2="s/%flag/$MELHOR_FLAG/"
                echo $OUTPUT | sed -e $S1 -e $S2 >> execucoes.csv


            done
        done
    done
    mkdir -p graficos_matmul
    echo -e "\n\t maximo threads = $MAX_T"
    python3 analise.py 2 $MAX_T
}

#  objetivo:
    # executar o programa 10 (ou n vezes) com as configurações abaixo:
    # - execuções sequenciais:
        # - dimensoes 500,1000 e 2000
        # - flags de compilacao −O0, −O1, −O2 e −O3.
    # - execucoes concorrentes:
        # - dimensoes 500 1000 e 2000 (usarei 4 threads em todas)
gcc -o bin_gen -Wall bin_gen.c

DIMENSOES=( 50 100 250 500 1000 )
# Gerar dados caso não haja
mkdir -p binarios
if [ ! -f "binarios/matmul${DIMENSOES[0]}.bin" ]; then
    echo -e "\ngerando matrizes de dimensões..."
    for dim in "${DIMENSOES[@]}";do
        echo -n "$dim..."
        ./bin_gen $dim "binarios/matmul$dim.bin";
    done

    echo -e "\n\tDados gerados!";
fi

FLAGS=("-O0" "-O1" "-O2"  "-O3")

MELHOR_FLAG=''

#Criando csv e colunas
COLUNAS="\"flags\",\"n_threads\",\"dimensao\",\"t_inicializacao\",\"t_processamento\",\"t_finalizacao\""
if [ ! -f execucoes.csv ]; then
    echo $COLUNAS >> execucoes.csv
fi

echo -e "\nQual atividade executar? (1,2,3,4)\n"
read -p "Insira o numero: " ATIVIDADE

case $ATIVIDADE in
    1)
        atividade1
    ;;

    2)
        atividade2
    ;;

    3)
    ;;

    4)
    ;;
esac
exit 0