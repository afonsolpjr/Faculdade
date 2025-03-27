import matplotlib.pyplot as plt
import math
import numpy
#interpolacao de lagrange
def lagrange_interpolation(valor_x,lista_x,lista_y):
    num_termos = len(lista_x)
    resultado = 0
    for i in range(num_termos): #somatorio
        termo = 1
        for j in range(num_termos):  #produtorio 
            if(j!=i):
                termo *= ((valor_x - lista_x[j])/(lista_x[i] - lista_x[j]))            
        termo *= lista_y[i] #multiplicando por y_i

        resultado+=termo

    return resultado

#calculo de diferencas divididas
def diferencas_divididas(lista_x,lista_y):
    if len(lista_x)!=len(lista_y):
        print("Coloque duas listas com mesmo tamanho.")
        return false
    
    n = len(lista_x)
    difdiv = []  #guardará tabela de diferenças divididas

    #Começando tabela de diferenças divididas de ordem 0
    difdiv.append([i for i in lista_y])

    for i in range(1,n):
        dif_ordem_n = [] #guardará diferenças divididas de ordem i para i<n
        for j in range(n-i):    #calcula os (n-i) termos de ordem i
            termo = (difdiv[i-1][j+1] - difdiv[i-1][j]) / (lista_x[j+i] - lista_x[j])  #calcula termo f[x_j, ... , x_j+i]
            dif_ordem_n.append(termo)
        difdiv.append(dif_ordem_n)
    
    return difdiv

#interpolacao de newton
def newton_interpolation(valor_x,lista_x,lista_y):
    num_termos = len(lista_x)
    dif_div = diferencas_divididas(lista_x,lista_y)
    
    if(type(valor_x)==type([])):  #caso seja lista a interpolar
        t = []
        for x in valor_x:
            t.append(0)
            for i in range(num_termos-1,0,-1):
                t[-1] += dif_div[i][0]
                t[-1] *= (x - lista_x[i-1])
            t[-1] += dif_div[0][0]
    else:  #caso seja só um valor a interpolar
        t = 0
        for i in range(num_termos-1,0,-1):
            t += dif_div[i][0]
            t *= (valor_x - lista_x[i-1])
        t += dif_div[0][0]
    return t


#funcao que calcula erro maximo dado a lista de valores referencia e valores teste
def calc_max_error(y_correct,y_test):
    error = []
    for i in range(len(y_test)):
        temp_error_list = [ math.fabs(y_correct[j] - y_test[i][j]) for j in range(len(y_correct))  ]
        error.append(max(temp_error_list))
    return error



# ITEM A)

n_list = [5,10,15,20]
x_list = []
y_list = []

i=0
#criar lista com 4 listas, cada uma com os pontos a serem utilizados:
for n in n_list:
    x_list.append( [(-1 + (2*j)/n) for j in range (n)] )
    #obtendo y para a lista de pontos criados:
    y_list.append( [ 1/(1 + (25*(x**2)) ) for x in x_list[i]] )
    i+=1


#obtendo lista de pontos de teste:
x_test = [ (-1 + (2*i + 1)/100) for i in range(100)]
#obtendo listas de f(x) para x nos pontos teste
y_control = [ 1/(1 + (25*(x**2)) ) for x in x_test ]

y_newton = []  #guardará 4 listas para interpolacoes com polinomios de diferentes graus
y_lagrange = []
for i in range(4):
    y_newton.append( newton_interpolation(x_test,x_list[i],y_list[i]) )
    y_lagrange.append ([lagrange_interpolation(val,x_list[i],y_list[i]) for val in x_test ])


#calculanr erro maximo para cada ponto, dada as 4 listas

max_error_newton = calc_max_error(y_control,y_newton)
max_error_lagrange = calc_max_error(y_control,y_lagrange)
print("ITEM A) \n")

#plotando grafico para metodo de newton
plt.plot(x_test,y_control,"k",label="Valor de referencia",lw=2)

plt.plot(x_test,y_newton[0],"r",label="n=5",linestyle='dotted')
plt.plot(x_test,y_newton[1],"g",label="n=10",linestyle='dotted')
plt.plot(x_test,y_newton[2],"magenta",label="n=15",linestyle='dotted')
plt.plot(x_test,y_newton[3],"b",label="n=20",linestyle='dotted')
plt.xlabel('eixo x')
plt.ylabel('eixo y')
plt.ylim([min(y_control)-0.1,max(y_control)+0.1])
plt.grid()
plt.title(u"Valores e interpolações para y = 1/(1+25x²). \nMétodo de Newton",fontsize=14)
plt.legend(fontsize=10)
plt.show()
print('\n')



#plotando grafico para metodo de lagrange 
plt.plot(x_test,y_control,"k",label="Valor de referencia",lw=2)

plt.plot(x_test,y_lagrange[0],"r",label="n=5",linestyle='dotted')
plt.plot(x_test,y_lagrange[1],"g",label="n=10",linestyle='dotted')
plt.plot(x_test,y_lagrange[2],"magenta",label="n=15",linestyle='dotted')
plt.plot(x_test,y_lagrange[3],"b",label="n=20",linestyle='dotted')
plt.xlabel('eixo x')
plt.ylabel('eixo y')
plt.ylim([min(y_control)-0.1,max(y_control)+0.1])
plt.grid()
plt.title(u"Valores e interpolações para y = 1/(1+25x²). \n Método de Lagrange",fontsize=14)
plt.legend(fontsize=10)
plt.show()
print('\n')


#plotando grafico de erro
plt.title(u"Erros máximos por nº de pontos e método",fontsize=14)

plt.plot(n_list,max_error_newton,"-ro",label="por Newton",markersize=2.5)
plt.plot(n_list,max_error_lagrange,"ko",label="por Lagrange",markersize=2.5)

plt.xlabel('Número de pontos')
plt.ylabel('Erro')
plt.grid()
# plt.ylim([-1,200])
plt.legend(fontsize=10)
plt.show()
print('\n')

#ITEM B:


print("Item b) \nRefazendo as interpolações usando nós de Chebyshev:\n\n")
n_list = [5,10,15,20]
cheb_points = []
y_list = []

i=0
for n in n_list:    
    #determinando pontos de chebyshev 
    cheb_points.append( [math.cos( (j*math.pi)/ n) for j in range (n)] )

    #obtendo y para a lista de pontos criados:
    y_list.append( [ 1/(1 + (25*(x**2)) ) for x in cheb_points[i]] )
    i+=1

#obtendo lista de pontos de teste:
x_test = [ math.cos((i*math.pi + 1)/100) for i in range(100)]
y_control = [ 1/(1 + (25*(x**2)) ) for x in x_test ]

#cada lista guardará 4 listas com interpolacoes com polinomios de diferentes graus
y_newton = [] 
y_lagrange = []
for i in range(4):
    y_newton.append( newton_interpolation(x_test,cheb_points[i],y_list[i]))
    y_lagrange.append( [lagrange_interpolation(val,cheb_points[i],y_list[i]) for val in x_test ])


#plotando para metodo de newton

plt.plot(x_test,y_control,"k",label="Valor de referencia",lw=2)

plt.plot(x_test,y_newton[0],"r",label="n=5",linestyle='dotted')
plt.plot(x_test,y_newton[1],"g",label="n=10",linestyle='dotted')
plt.plot(x_test,y_newton[2],"magenta",label="n=15",linestyle='dotted')
plt.plot(x_test,y_newton[3],"b",label="n=20",linestyle='dotted')
plt.xlabel('eixo x')
plt.ylabel('eixo y')
plt.ylim([min(y_control)-0.1,max(y_control)+0.1])
plt.grid()
plt.title(u"Valores e interpolações para y = 1/(1+25x²).\nPelo método de Newton e usando nós de Chebyshev",fontsize=14)
plt.legend(fontsize=10)
plt.show()
print('\n')

#plotando para método de lagrange

plt.plot(x_test,y_control,"k",label="Valor de referencia",lw=2)

plt.plot(x_test,y_lagrange[0],"r",label="n=5",linestyle='dotted')
plt.plot(x_test,y_lagrange[1],"g",label="n=10",linestyle='dotted')
plt.plot(x_test,y_lagrange[2],"magenta",label="n=15",linestyle='dotted')
plt.plot(x_test,y_lagrange[3],"b",label="n=20",linestyle='dotted')
plt.xlabel('eixo x')
plt.ylabel('eixo y')
plt.ylim([min(y_control)-0.1,max(y_control)+0.1])
plt.grid()
plt.title(u"Valores e interpolações para y = 1/(1+25x²).\nPelo método de Lagrange e usando nós de Chebyshev",fontsize=14)
plt.legend(fontsize=10)
plt.show()
print('\n')

#calculando e plotando erros

max_error_newton = calc_max_error(y_control,y_newton)
max_error_lagrange = calc_max_error(y_control,y_lagrange)

#plotando grafico de erro
plt.title(u"Erros máximos por nº de pontos e método (nós de Chebyshev)",fontsize=14)

plt.plot(n_list,max_error_newton,"-ro",label="por Newton",markersize=2.5)
plt.plot(n_list,max_error_lagrange,"ko",label="por Lagrange",markersize=2.5)

plt.xlabel('Número de pontos')
plt.ylabel('Erro')
plt.grid()
plt.legend(fontsize=10)
plt.show()
print('\n')

print("Vemos que o limite do erro com nós de Chebyshev é proximo de 1!")