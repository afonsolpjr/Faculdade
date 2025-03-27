# ! bin/sh


#Checar se o arquivo de entrada existe, se não, criar um 
dict_file="$(pwd)/.dict_afonso"
if [ ! -e $dict_file ] || [ ! -f $dict_file ]
then
    rm -f -r $dict_file
    touch $dict_file
fi

search() {
    # Se não passarem opcoes pro search, mostra todas as entradas
    if [ $# -eq 0 ]
    then
        entradas_exibidas=""
        grep  ''  $dict_file | while read -r linha;
        do
            #Pegar termo
            termo="$(echo $linha | cut -d: -f 1)"
            if [ -z "$(echo $entradas_exibidas | grep -i $termo)" ]
            then
                #Entrada nao foi exibida ainda
                search "$termo";
                entradas_exibidas+="$termo ";
            else
                #Entrada ja foi exibida
                nada=True
            fi
        done

    fi 

    for arg in "$@"
    do 
        
        num_entradas=$(grep -c -i ^$arg $dict_file)
        if [ $num_entradas -eq 0 ]
        then
            echo -e "[ Sem entradas para '$arg' ]\n";
        else #Exibir entradas
            echo -e "[ '$arg' ]";
            i=1
            grep -i "^$arg" "$dict_file" | while read -r linha; 
            do
                echo -e "\t[$i]
                    \t $(echo $linha | cut -d: -f 2-)\n"
                i=$((i + 1))
            done
        fi
    done    
}

remove()
{

    for arg in "$@"
    do 
        
        num_entradas=$(grep -c -i ^$arg $dict_file)
        if [ $num_entradas -eq 0 ]
        then
            echo -e "[ Sem entradas para '$arg' ]\n";
        else #Exibir entradas
            echo "[ Removendo entradas para '$arg' ]"
        fi
    done

    #Criando regex pra todas linhas que comecem com os argumentos dados
    regex="^($(echo $@ | tr " " "|" ))"
    #Pega todas linhas que não dão match com o regex
    novo_dic=$(grep -v -Ei $regex $dict_file)
    echo "$novo_dic" > $dict_file
    
    exit 0
}

insert(){
    if [ -z "$(grep -i ^$1 $dict_file)" ]
    then
        nada=true
    else
        echo -e "\t[ Entrada já existente. Outra entrada será criada. ]"
    fi

    echo "$1:${@:2}" >> $dict_file
}
case "$1" in
    "-s"|"-search") search ${@:2} && exit 0;;
    "-i" | "-insert") insert ${@:2} && exit 0;;
    "-r" | "-remove") remove ${@:2};;
    "-d") echo "pasta atual: $pwd";;
    *) echo "$1: opção não reconhecida." && exit 1;;
esac
     
exit 0

# COmando pra criar um dicionario

   ./dicionario.sh -i Batata A Solanum tuberosum, comumente conhecida como batata[1], é uma planta perene da família das solanáceas e pertencente ao tipo fisionómico dos terófitos.[2] A planta adulta, conhecida como batateira, tem geralmente entre sessenta a cem centímetros de altura, possui flores e frutos e produz um tubérculo comestível rico em amido.[2];
  ./dicionario.sh -i batatinha Uma batata, só que bem pequena;