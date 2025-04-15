import csv
import matplotlib.pyplot as plt
import argparse

parser = argparse.ArgumentParser("analise_prog_conc")
parser.add_argument("analise", help="1 para analise de niveis de otimizacao | 2 para analise do tempo de execucao", type=int)
parser.add_argument("max_threads", help="numero maximo de threads desejada nas analises",type=int)
args = parser.parse_args()
# print("programa escolhido: {} \n".format(args.analise))

# Keys:
# "tipo_execucao","flags","n_threads","dimensao",
# "t_inicializacao","t_processamento","t_finalizacao"

flags = ["-O0","-O1", "-O2",  "-O3"]
dimensoes = [500,1000,2000,5000,10000,20000]
n_threads = list(range(1,args.max_threads + 1))
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
def analise_otimizacao(fazer_grafico):
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
        
        if(fazer_grafico):
            plt.scatter(list(data[flag].keys()),list(data[flag].values()),
                        marker='.')
            plt.plot(list(data[flag].keys()),list(data[flag].values()),
                        label=flag,
                        linestyle='dotted')
            
            plt.xlabel("Dimensão da matriz")
            plt.ylabel("Tempo médio de execução em segundos")
            plt.title("Tempo de execução por dimensão da matriz e nível de otimização")
            plt.legend()

    if(fazer_grafico):
        plt.savefig('graficos_matvet/tempos_nivel_otimizacao.png')
        plt.close()

    media_geral={}
    for flag in flags:
        media_geral[flag] = sum(list(data[flag].values()))/len(list(data[flag].values()))

    # print(media_geral)
    return min(media_geral, key = media_geral.get )

def analise_exec(execs):
    # calcular média do tempo para cada execucao com cada numero
    dados = {}
    for n_dim in dimensoes:
        for n_t in n_threads:    
            exs = [ex for ex in execs if (ex['dimensao']==n_dim and ex['n_threads']==n_t)]
            chave = (n_t,n_dim)
            # print(chave)
            media_init = sum([item['t_inicializacao'] for item in exs])/len(exs)
            media_exec = sum([item['t_processamento'] for item in exs])/len(exs)
            media_fin = sum([item['t_finalizacao'] for item in exs])/len(exs)
            dados.update({
                chave:{
                    "media_init":media_init,
                    "media_exec":media_exec,
                    "media_fin":media_fin,
                    "n":len(exs)
                }
            })
    
        # Criar subplots com mais espaço
    fig, axs = plt.subplots(3, 2, figsize=(16, 14), constrained_layout=True)
    axs = axs.flatten()

    for i, n_dim in enumerate(dimensoes):
        cria_grafico_dim(dados, n_dim, axs[i])
        cria_grafico_ind_dim(dados,n_dim)

    fig.suptitle('Tempos de Execução por Número de Threads (por dimensão)', fontsize=18)
    # fig.subplots_adjust(top=0.93, hspace=0.4)  # espaço vertical extra
    plt.savefig('graficos_matvet/todos_tempos_execucao.png', dpi=300)
    plt.close(fig)

    graf_aceleracao(dados)
    graf_eficiencia(dados)
    return

def cria_grafico_dim(dados, n_dim, ax):
    time_counts = {
        'T. Inicialização': [dados[(i, n_dim)]['media_init'] for i in n_threads],
        'T. Execução': [dados[(i, n_dim)]['media_exec'] for i in n_threads],
        'T. Finalização': [dados[(i, n_dim)]['media_fin'] for i in n_threads]
    }

    bottom = [0 for _ in n_threads]
    width = 0.3

    for tempo_nome, tempo_valores in time_counts.items():
        p = ax.bar(n_threads, tempo_valores, width, label=tempo_nome, bottom=bottom)
        bottom = [bottom[i] + tempo_valores[i] for i in range(len(bottom))]
        ax.bar_label(p, label_type='center', fontsize=7)

    ax.set_title(f'Dimensão = {n_dim}')
    ax.set_xticks(n_threads)
    ax.set_xlabel('Threads')
    ax.set_ylabel('Tempo (s)')
    # print(f"Salvo em: {caminho_arquivo}")

    # plt.close(fig)  # importante pra não mostrar agora (se quiser, pode deixar plt.show() opcional)


def cria_grafico_ind_dim(dados,n_dim):
    
    time_counts = {
        'T. Inicialização':[dados[(i,n_dim)]['media_init'] for i in n_threads],
        'T. Execução':[dados[(i,n_dim)]['media_exec'] for i in n_threads],
        'T. Finalização':[dados[(i,n_dim)]['media_fin'] for i in n_threads]
    }
    width = 0.5
    
    # species = ('Adelie', 'Chinstrap', 'Gentoo')
    # sex_counts = {
    #     'Male': np.array([73, 34, 61]),
    #     'Female': np.array([73, 34, 58]),
    # }
    width = 0.6  # the width of the bars: can also be len(x) sequence

    # print(time_counts)
    fig, ax = plt.subplots()    
    bottom = [0 for i in n_threads]

    for time, time_count in time_counts.items():
        # print("Printando",
        #     "\n\tn_threads = {}".format(n_threads),
        #     "\n\ttime_count=  {}".format(time_count),
        #     "\n\t tempo= {}".format(time),
        #     "\n\t bottom = {}".format(bottom))
        p = ax.bar(n_threads, time_count, width, label=time, bottom=bottom)
        
        bottom = [bottom[i]+time_count[i] for i in range(len(bottom))]

        ax.bar_label(p, label_type='center')

    ax.set_title('Tempos de execuções por número de threads para dimensão = {}'.format(n_dim))
    ax.legend()

    plt.savefig("graficos_matvet/{}.png".format(n_dim))
    plt.close(fig)
    return


def graf_aceleracao(dados):
    
#     Eixo x: número de threads pp

# Eixo y: aceleração A(n,p)

# Uma linha para cada dimensão nn (tamanho do problema)

    for n_dim in dimensoes:
        aceleracao = [] # guardará 3 valores de aceleracao, para p = 2,3,4
        # print(dados[(1,n_dim)])
        tempo_seq = sum([dados[(1,n_dim)][k] for k,v in dados[(1,n_dim)].items() if k !='n'])
        # print(tempo_seq)

        for n_t in n_threads:
            tempo_conc = sum([dados[(n_t,n_dim)][k] for k,v in dados[(n_t,n_dim)].items() if k !='n'])
            aceleracao.append(tempo_seq/tempo_conc)

        # print("Printando:",
        #     "\n\t Eixo x:{}".format(list(range(2,5))),
        #     "\n\t Eixo y = {}".format(aceleracao))
        plt.scatter(n_threads,aceleracao,
                    marker='.')
        plt.plot(n_threads,aceleracao,
                    label="n={}".format(n_dim),
                    linestyle='dotted')
        
        plt.xlabel("p (Nº de threads)")
        plt.ylabel("A(n,p)")
        plt.title("Aceleração A(n,p), por número de threads")
        plt.legend()

    plt.savefig('graficos_matvet/aceleracao.png')
    plt.close()
    return

def graf_eficiencia(dados):

    for n_dim in dimensoes:
        eficiencia = []

        tempo_seq = sum([dados[(1,n_dim)][k] for k,v in dados[(1,n_dim)].items() if k !='n'])
        # print(tempo_seq)

        for n_t in n_threads:
            tempo_conc = sum([dados[(n_t,n_dim)][k] for k,v in dados[(n_t,n_dim)].items() if k !='n'])
            acc = (tempo_seq/tempo_conc)
            eficiencia.append(acc/n_t)


        # print("Printando:",
        #     "\n\t Eixo x:{}".format(list(range(2,5))),
        #     "\n\t Eixo y = {}".format(aceleracao))

        plt.scatter(n_threads,eficiencia,
                    marker='.')
        plt.plot(n_threads,eficiencia,
                    label="n={}".format(n_dim),
                    linestyle='dotted')
        
        plt.xlabel("p (Nº de threads)")
        plt.ylabel("E(n,p)")
        plt.title("Eficiencia E(n,p), por número de threads")
        plt.legend()

    plt.savefig('graficos_matvet/eficiencia.png')
    plt.close()

    return


match args.analise:
    case 1:
        flag = analise_otimizacao(True)
        print(flag)
    case 2:
        flag = analise_otimizacao(False)
        analise_exec([item for item in execucoes if item['flags']==flag ])
