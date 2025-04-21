
A geração e análise dos dados, assim como a criação dos gráficos, são orquestradas pelo bash script run.sh. 
O programa está em C, como determinado, e a análise e criação dos gráficos é feita em python.
A execução do script por si só é suficiente para todas as etapas.

# Especificações da máquina
```  
Architecture:             x86_64
  CPU op-mode(s):         32-bit, 64-bit
  Address sizes:          36 bits physical, 48 bits virtual
  Byte Order:             Little Endian
CPU(s):                   4
  On-line CPU(s) list:    0-3
Vendor ID:                GenuineIntel
  Model name:             Intel(R) Core(TM) i5-3330 CPU @ 3.00GHz
    CPU family:           6
    Model:                58
    Thread(s) per core:   1
    Core(s) per socket:   4
    Socket(s):            1
    Stepping:             9
    CPU(s) scaling MHz:   70%
    CPU max MHz:          3200,0000
    CPU min MHz:          1600,0000
    BogoMIPS:             5986,49
Caches (sum of all):      
  L1d:                    128 KiB (4 instances)
  L1i:                    128 KiB (4 instances)
  L2:                     1 MiB (4 instances)
  L3:                     6 MiB (1 instance)
NUMA:                     
  NUMA node(s):           1
  NUMA node0 CPU(s):      0-3

```
# Dependências :
Em um ambiente Linux padrão na maioria das distribuições, acredito não haver necessidade de instalar nenhum programa, além da biblioteca Python *matplotlib*.

De qualquer forma segue lista de comandos utilizados:
-  **1. Comandos do sistema operacional:**
	- **`bash`**: Para executar o script Bash.
	- **`touch`**: Para criar o arquivo `dados.csv`.
	- **`echo`**: Para escrever mensagens no terminal e no arquivo `dados.csv`.
	- **`awk`**: Para processar e analisar o arquivo `dados.csv`.
	- **`sed`**: Para substituir valores no arquivo `dados.csv`.
	- **`mkdir`**: Para criar o diretório `graficos_nprimos`.
	- **`printf`**: Para formatar e exibir mensagens no terminal.
	- **`seq`**: Para gerar sequências numéricas.
	- **`gcc`**: Para compilar o programa principal `ex2.c`
	- **`python3`**: Para executar o script `analise.py`
- **2. Dependências Python**
	-  **Bibliotecas padrão:**
		- **[csv](vscode-file://vscode-app/usr/share/code/resources/app/out/vs/code/electron-sandbox/workbench/workbench.html)**: Para leitura e manipulação de arquivos CSV.
		- **[argparse](vscode-file://vscode-app/usr/share/code/resources/app/out/vs/code/electron-sandbox/workbench/workbench.html)**: Para lidar com argumentos da linha de comando.
	-  **Bibliotecas externas:**
		- **[matplotlib](vscode-file://vscode-app/usr/share/code/resources/app/out/vs/code/electron-sandbox/workbench/workbench.html)**: Para geração de gráficos.


# Observações sobre a implementação quanto ao roteiro:
 1. O programa principal, gerado pela compilação de ex2.c, recebe como argumentos:
	 1. O número de threads
	 2. O número N, (limite superior para checagem de primos).
	 3. O nome de um arquivo para gravação dos dados (em formato de texto).
 2. A checagem de corretude é feita através da comparação com o resultado de um pipeline de comandos:
	 1. GABARITO=$(seq 1 $(($1-1)) | factor | awk 'NF\==2 {print $1}' | wc -l)
	 2. O comando acima envia uma sequencia de elementos (1 até N-1) para serem fatorados pelo comando factor, enquanto o comando awk separa e imprime aqueles que só tem 2 campos (o primeiro indicando o numero, e o segundo indicando seu único fator). O comando 'wc -l' conta a quantidade de linhas.
 3. Valores de N: 10²,10³, ... até 10⁷
 4. Números de threads testadas: 1,2,3 e 4
 5. Número de execuções por valor de n & número de threads: 10

Observações e descrição das  tarefas do script:
1. O script pode receber como argumento, opcionalmente, o número máximo de threads a serem executadas (ele executará o programa com threads de 1 até o valor enviado). Por padrão o número máximo de threads é 4.
2. Determina os valores de N a serem testados, na lista "DIMENSOES".
3. Assegura criação do arquivo "dados.csv", que conterá dados de execução.
4. Determina necessidade ou não de gerar dados de execução com diferentes níveis de otimização, para que a execução seja feita com o nível que proporcione o menor tempo médio geral de execução
5. Determinado o melhor nível de otimização, gera os dados para diferentes valores de N e número de threads.
6. Com o arquivo python, plota gráficos sobre os diferentes níveis de otimização, tempos de execução, aceleração e eficiência.