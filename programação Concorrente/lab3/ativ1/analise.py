import csv


# Keys:
# "tipo_execucao","flags","n_threads","dimensao",
# "t_inicializacao","t_processamento","t_finalizacao"

flags = ["-O0","-O1", "-O2",  "-O3"]
dimensoes = [500,1000,2000,5000,10000,20000]
n_threads = list(range(0,5))
execucoes = []
with open('execucoes.csv', newline='') as csvfile:
    reader = csv.DictReader(csvfile)
    for row in reader:
        row['tipo_execucao'] = int(row['tipo_execucao'])
        row['n_threads'] = int(row['n_threads'])
        row['dimensao'] = int(row['dimensao'])
        row['t_inicializacao'] = float(row['t_inicializacao'])
        row['t_processamento'] = float(row['t_processamento'])
        row['t_finalizacao'] = float(row['t_finalizacao'])
        row['t_total'] = row['t_finalizacao'] + row['t_processamento'] + row['t_inicializacao']
        execucoes.append(row)
        # print(row)

# print(n_threads)
#gerar grafico de tempo médio de execução por flag e dimensao
# 4 arrays entao, um para cada flag, com valores medios de execucao pra cada dimensao

data = {}
for flag in flags:
    #calcular media para valores que tenham determinada flag
        #pegando só dados com a determinada flag
    data[flag]= {}
    for dim in dimensoes:
        #colocar media dos valores 
        flag_execs = [item for item in execucoes if item['flags']==flag and item['dimensao']==dim ]
        valores = [item['t_total'] for item in flag_execs]
        # print("Valores para flag {} e dimensao {}:{}".format(flag,dim,len(valores)))
        data[flag][dim] = sum(valores)/len(valores)

print(data)
