import numpy
import math
import matplotlib.pyplot as pyplot
# edo: EDO conhecida
# a: valor inicial
# b:valor desejado
# y0: valor inicial
# n: numero de pontos a ser utilizado 
def metodo_euler(edo,a,b,y0,n):
    delta_t = (b-a)/n
    t_n = [ (a + delta_t*i) for i in range(n)  ]
    #Começa a lista com o valor inicial
    y_n = [y0]
    for i in t_n:
        #usando aprox. linear de 2a ordem
        d = edo(i,y_n[-1])
        y_n.append( y_n[-1] + delta_t*d)

    return y_n


def metodo_heun(edo,a,b,y0,n):
    delta_t = (b-a)/n
    #note que uso range (n+1) pois precisamos sempre de um t avançado
    t_n = [ ( a + delta_t*i ) for i in range(n+1) ] 
    y_n = [y0]

    for i in range(n):
        t = t_n[i]
        t_1 = t_n[i+1]

        k1 = edo(t,y_n[-1])*delta_t
        k2 = edo(t_1,y_n[-1] + k1)*delta_t
        y_n.append( y_n[-1] + 0.5*(k1 + k2) )

    return y_n


def metodo_rk4(edo,a,b,y0,n):
    delta = (b-a)/n
    t_n = [ a + delta*i for i in range(n)]
    y_n = [y0]
    for t in t_n:
        yn=y_n[-1]
        k1 = delta*edo(t,yn)
        k2 = delta*edo(t + 0.5*delta,yn + 0.5*k1)
        k3 = delta*edo(t + 0.5*delta,yn + 0.5*k2)
        k4 = delta*edo(t + delta,yn + k3)
        y_n.append( yn + (1/6)*(k1 + 2*k2 + 2*k3 + k4))
    
    return y_n
        



# def edo1(x,y):
#     return 0.04*y

# def edo2(x,y):
#     return (y/x) + 2*(math.e**(-y/x))


# result = metodo_rk4(edo2,1,3,0,10)

# print("resultado = {:.30f}".format(result[-1]))


# ##############################               TAREFA 2            ##################################

# Função dada para calcular o valor de referência.
def velocidade(g,m,c,t):
    result = 0
    result += g*m/c
    result *= (1 - math.e**(-(c/m)*t))
    return result 

def edo_paraquedista(x,y):
    g = 9.81
    m = 75
    c = 12.5
    return g - (c/m)*y    

g = 9.81
m = 75
c = 12.5
t = 25

valor_ref = velocidade(g,m,c,t)
metodos = [metodo_euler,metodo_heun,metodo_rk4]
#listas que guardarão dados para euler,heun e rk
num_passos = []
valores_finais = []
erros = []
for metodo in metodos:
    i=1
    valores = metodo(edo_paraquedista,0,t,0,i)
    erro =  math.fabs(valor_ref - valores[-1] )
    erros.append( [ ])
    while( 0.01 <= erro ):
        # print("Teste realizado para  {}  passos. Erro =  {} \n".format(i,erro))
        i+=1
        valores = metodo(edo_paraquedista,0,t,0,i)
        erro =  math.fabs(valor_ref - valores[-1] )
        erros[-1].append(erro)
        
    num_passos.append(i)
    valores_finais.append(valores)
# for lista,passos,erro in zip(valores_finais,num_passos,erros):
#     print("Valores finais = {}\nNum passos = {}     Erro = {}".format(lista[-1],passos,erro))

print("\nVelocidade aos 25 segundos:" 
      "\nValor de referência: {:.30f}"
      "\nMétodo de Euler: {:.30f}"
      "\nMétodo de Heun : {:.30f}"
      "\nMétodo de Runge Kutta 4ª ordem: : {:.30f}\n\n"
      .format(valor_ref,valores_finais[0][-1],valores_finais[1][-1],valores_finais[2][-1]))
#plotando graficos]

pyplot.title("Erro absoluto por numero de passos e método")
pyplot.xlabel("Nº de passos")
pyplot.ylabel("Erro absoluto")
pyplot.plot(range(1,num_passos[0]),erros[0],"ko",label="métod. Euler",markersize=3,linestyle='dashed')
pyplot.plot(range(1,num_passos[1]),erros[1],"ro",label="métod. Heun",markersize=3,linestyle='dashed')
pyplot.plot(range(1,num_passos[2]),erros[2],"bo",label="métod. RK4",markersize=3,linestyle='dashed')
pyplot.legend(fontsize=9)
pyplot.axis([0, 35, 0, 10])
pyplot.text(20,6,'Nº de passos por método:\n Euler = 791\n Heun = 35\n Runge-Kutta = 7')
pyplot.show()

######## TAREFA 2 item b #############

def resistencia_paraquedas(v,v_max,c,alfa,beta):
    result = c * (1 + alfa * ((v/v_max)**(beta)) )
    return result

def edo2_paraquedista(x,y):
    g = 9.81
    m = 75
    r = resistencia_paraquedas(y,46,12.5,0.2,1.1)
    return  g - (r/m)*y

valores_itemb = []
for metodo,n_passo in zip(metodos,num_passos):
    valores_itemb.append(metodo(edo2_paraquedista,0,25,0,n_passo))

pyplot.title("Velocidade por tempo e método de aproximação")
pyplot.xlabel("Tempo")
pyplot.ylabel("Velocidade")
pyplot.plot(numpy.linspace(0,25,num_passos[0]+1),valores_itemb[0],"k.",label="métod. Euler",markersize=3,linestyle='dashed')
pyplot.plot(numpy.linspace(0,25,num_passos[1]+1),valores_itemb[1],"r.",label="métod. Heun",markersize=3,linestyle='dashed')
pyplot.plot(numpy.linspace(0,25,num_passos[2]+1),valores_itemb[2],"b.",label="métod. RK4",markersize=3,linestyle='dashed')
pyplot.legend(fontsize=9)
pyplot.text(7,20,"\nVelocidade aos 25s :"
      "\nmétodo de Euler: {}"
      "\nmétodo de Heun: {}"
      "\nmétodo de Runge-Kutta 4: {}"
      .format(valores_itemb[0][-1],valores_itemb[1][-1],valores_itemb[2][-1]))
pyplot.show()



##############   TAREFA 3 ###################

# testando funções de vetores do numpy
# vetor = numpy.array([1,2])
# vetor *= 2
# vetor += numpy.array([2,3])
# print(vetor)

def dsdt_vetorial(x,y_n):
    s = y_n[0]
    i = y_n[1]
    ds =  (-0.0003*s*i + 0.15*i)
    vetor = numpy.array([ds,-ds])
    return vetor

#começando com 21 passos e aumentando até os incrementos não mudarem mais que 0.05
y0 = numpy.array([10000,1])    
i=t=21
valores_antigo = metodo_rk4(dsdt_vetorial,0,t,y0,i)
i+=1
valores = metodo_rk4(dsdt_vetorial,0,21,y0,i)
variacao = math.fabs(valores[-1][0] - valores_antigo[-1][0])
    
while( variacao >=0.05 ):
    i+=1
    valores_antigo = valores
    valores = metodo_rk4(dsdt_vetorial,0,t,y0,i)
    variacao = math.fabs(valores[-1][0] - valores_antigo[-1][0])


suscetiveis = [ par[0] for par in valores]
infectados = [ par[1] for par in valores]


pyplot.title("Suscetiveis e infectados por dia")
pyplot.xlabel("Dia")
pyplot.ylabel("Quantidade de pessoas")
pyplot.plot(numpy.linspace(0,21,i+1),suscetiveis,"k",label="Suscetíveis",markersize=3)
pyplot.plot(numpy.linspace(0,21,i+1),infectados,"r",label="Infectados",markersize=3)
pyplot.legend(fontsize=9)
pyplot.text(15,8150,"Infectados no dia 21:\n{}".format(valores[-1][1]))
pyplot.text(15,1600,"Suscetiveis no dia 21:\n{}".format(valores[-1][0]))
pyplot.text(6,5200,"Numero de passos: {}".format(i))
pyplot.show()