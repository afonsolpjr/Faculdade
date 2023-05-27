import matplotlib.pyplot as plt
import math
import numpy

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


def newton_interpolation(valor_x,lista_x,lista_y):
    num_termos = len(lista_x)
    resultado = 0
    dif_div = diferencas_divididas(lista_x,lista_y)
    t = 0

    for i in range(num_termos-1,0,-1):
        t += dif_div[i][0]
        t *= (valor_x - lista_x[i-1])
    t += dif_div[0][0]
    
    return t


#criar lista com 4 listas com os pontos a serem utilizados:
n = [5,10,15,20]
x_list = []
y_list = []

i=0
for n in n:
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
    y_newton.append ([newton_interpolation(val,x_list[i],y_list[i]) for val in x_test ])
    y_lagrange.append ([lagrange_interpolation(val,x_list[i],y_list[i]) for val in x_test ])


#calculanr erro maximo para cada ponto, dada as 4 listas

max_error_newton = []
max_error_lagrange = []

for i in range(len(x_test)):    
    ref_value = 1/(1 + 25*(x_test[i]**2) ) #valor de referencia

    error_newton = [ math.fabs( ref_value - y_newton[j][i]) for j in range(4)] #calculando erro para os 4 valores de p_n(x), 0<n<4
    max_error_newton.append( max(error_newton) )

    error_lagrange = [ math.fabs( ref_value - y_lagrange[j][i]) for j in range(4)]
    max_error_lagrange.append( max(error_lagrange) )

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
print("\n Erros por método. Se observarmos bem, o método de Lagrange apresenta erros ligeiramente maiores.")
plt.title(u"Erros máximos por método",fontsize=14)

plt.plot(x_test,max_error_newton,"r",label="por Newton",markersize=2.5)
plt.plot(x_test,max_error_lagrange,"ko",label="por Lagrange",markersize=2.5)

plt.xlabel('eixo x')
plt.ylabel('Erro')
plt.grid()
# plt.ylim([-1,200])
plt.legend(fontsize=10)
plt.show()
print('\n')


#ITEM B:



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

y_newton = []  #guardará 4 listas para interpolacoes com polinomios de diferentes graus
y_lagrange = []
for i in range(4):
    y_newton.append( [newton_interpolation(val,cheb_points[i],y_list[i]) for val in x_test ])
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

max_error_newton = []
max_error_lagrange = []

for i in range(len(x_test)):    
    ref_value = 1/(1 + 25*(x_test[i]**2) ) #valor de referencia

    error_newton = [ math.fabs( ref_value - y_newton[j][i]) for j in range(4)] #calculando erro para os 4 valores de p_n(x), 0<n<4
    max_error_newton.append( max(error_newton) )

    error_lagrange = [ math.fabs( ref_value - y_lagrange[j][i]) for j in range(4)]
    max_error_lagrange.append( max(error_lagrange) )


    #plotando grafico de erro
plt.title(u"Erros máximos por método.\nUsando pontos de Chebyshev",fontsize=14)

plt.plot(x_test,max_error_newton,"r",label="por Newton",markersize=2.5)
plt.plot(x_test,max_error_lagrange,"ko",label="por Lagrange",markersize=2.5)

plt.xlabel('eixo x')
plt.ylabel('Erro')
plt.grid()
plt.legend(fontsize=10)
plt.show()
print('\n')

print("Vemos que o limite do erro é proximo de 1!")