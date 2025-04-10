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

#  objetivo:
    # executar o programa 10 (ou n vezes) com as configurações abaixo:
    # - execuções sequenciais:
        # - dimensoes 500,1000 e 2000
        # - flags de compilacao −O0, −O1, −O2 e −O3.
    # - execucoes concorrentes:
        # - dimensoes 500 1000 e 2000 (usarei 4 threads em todas)
gcc -o bin_gen -Wall bin_gen.c

#Criando csv e colunas
COLUNAS="\"tipo_execucao\",\"flags\",\"n_threads\",\"dimensao\",\"t_inicializacao\",\"t_processamento\",\"t_finalizacao\""
if [ ! -f execucoes.csv ]; then
    echo $COLUNAS >> execucoes.csv
fi

DIMENSOES=(500 1000 2000 5000 10000 20000)
# Gerar dados caso não haja
if [ ! -f "matvet500.bin" ]; then
    for dim in "${DIMENSOES[@]}";do
        ./bin_gen $dim $dim "matvet$dim.bin";
    done
    echo -e "\n\tDados gerados!";
fi

TIPOS_EXECUCAO=(2)
FLAGS=("-O0" "-O1" "-O2"  "-O3")



atividade1(){
    tipo_execucao=2
    for flag in "${FLAGS[@]}";do

                COMANDO="gcc $flag -o matvet -Wall matvet.c";
                echo -e "\nCompilando com flag $flag";
                $COMANDO;
                echo -e "\tcalculando para dimensoes "

                for dim in "${DIMENSOES[@]}";do
                    echo -n " $dim...";
                    # programa <nome binario> <tipo execucao> <n threads>
                    NOME_BIN="matvet$dim.bin"
                    COMANDO="./matvet $NOME_BIN $tipo_execucao 1 "
                    for ((i=1;i<=10;i++));do
                        OUTPUT=$($COMANDO)
                        S1="s/%tipo/$tipo_execucao/"         #substituicoes
                        S2="s/%flag/$flag/"
                        echo $OUTPUT | sed -e $S1 -e $S2 >> execucoes.csv
                    done
                done
            done

}
atividade2(){
    for tipo_execucao in "${TIPOS_EXECUCAO[@]}";do
        if [ $tipo_execucao -eq 1 ];then      # errei mano, sequencial é com uma thread.
            for flag in "${FLAGS[@]}";do

                COMANDO="gcc $flag -o matvet -Wall matvet.c";
                $COMANDO;

                for dim in "${DIMENSOES[@]}";do
                    # programa <nome binario> <tipo execucao> <n threads>
                    NOME_BIN="matvet$dim.bin"
                    COMANDO="./matvet $NOME_BIN $tipo_execucao"

                    for ((i=1;i<=10;i++));do
                        OUTPUT=$($COMANDO)
                        S1="s/%tipo/$tipo_execucao/"         #substituicoes
                        S2="s/%flag/$flag/"
                        echo $OUTPUT | sed -e $S1 -e $S2 >> execucoes.csv
                    done
                done
            done


        else
            gcc -o matvet -Wall matvet.c

            for dim in "${DIMENSOES[@]}";do

                for NUM_THR in $(seq 1 $MAX_T);do
                    # programa <nome binario> <tipo execucao> <n threads>
                    NOME_BIN="matvet$dim.bin"
                    COMANDO="./matvet $NOME_BIN $tipo_execucao $NUM_THR"

                    for ((i=1;i<=10;i++));do
                        OUTPUT=$($COMANDO)
                        S1="s/%tipo/$tipo_execucao/"         #substituicoes
                        S2="s/%flag/$flag/"
                        echo $OUTPUT | sed -e $S1 -e $S2 >> execucoes.csv
                    done

                done

            done
        fi
    done
}



echo -e "\nQual atividade executar? (1,2,3,4)\n"
read -p "Insira o numero: " ATIVIDADE

case $ATIVIDADE in
    1)
        atividade1
    ;;

    2)
    ;;

    3)
    ;;

    4)
    ;;
esac
exit 0
# gcc -o matvet -Wall matvet.c
# ./matvet matvet500.bin 2 1

# execucoes sequenciais

# execucoes concorrentes

