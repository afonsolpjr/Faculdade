#!/bin/bash

# O exercício inteiro pode ser executado a partir deste script. Ele realiza as seguintes tarefas:
# - Baixa os arquivos do exercicio meu repositório, se nao existirem na pasta atual
# - Compila os arquivos, se não estiverem compilados
# - Executa em sequencia o gerador do arquivo binário e o progarma concorrente, conforme os parametros passados para o script no seguinte formato:
# ./script <tamanho-vetor> <nome_binario> <numero-de-threads>
# O script oculta a saída do gerador, que mostra os vetores gerados.

# Funções pra colorir texto
RED="\033[31m"
GREEN="\033[0;32m"
YELLOW="\033[0;33m"
NC="\033[0m"
colortext(){
    echo -e "$1$2${NC}\n"
}

#Baixa os arquivos se não existirem na pasta atual
wget -q -nc https://raw.githubusercontent.com/afonsolpjr/Faculdade/refs/heads/main/programa%C3%A7%C3%A3o%20Concorrente/ex1/gerador.c
wget -q -nc https://raw.githubusercontent.com/afonsolpjr/Faculdade/refs/heads/main/programa%C3%A7%C3%A3o%20Concorrente/ex1/produto_interno.c



#Compilando se arquivos não existirem
if [ ! -f gerador ] || [ ! -f prod_interno ]; then
    colortext $YELLOW "Programas necessários não encontrados. Compilação será feita"

    if [ ! -f gerador ]; then
        gcc -o gerador -Wall gerador.c
        colortext $GREEN "Compilação do gerador concluída"
    fi

    if [ ! -f prod_interno ]; then
        gcc -o prod_interno -Wall produto_interno.c
        colortext $GREEN "Compilação do prog. concorrente concluída"
    fi
    colortext $GREEN "Compilações feitas."
fi

if [ $# -lt 3 ]; then
    colortext $YELLOW "Você pode, adicionalmente, fornecer o tamanho do vetor, nome do binario, e número de threads como argumentos para este script."
    echo -e "\tExemplo: ./script <tamanho-vetor> <nome_binario> <numero-de-threads>\n";
fi

TAM_VETOR=${1:?"Tamanho do vetor não fornecido."}
NOME_BIN=${2:?"Nome do binário não fornecido"}
NUM_THR=${3:?"Número de threads não fornecido"''}

./gerador $TAM_VETOR $NOME_BIN > /dev/null && ./prod_interno $NUM_THR $NOME_BIN
