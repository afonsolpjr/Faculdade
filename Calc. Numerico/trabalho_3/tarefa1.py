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
        for j in range(n-i):    #calcula n-i termos de ordem i
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


#plotando graficos:

x = numpy.linspace(-50,50,50)
alt_x = numpy.linspace(-50,50,100)  
y = [ i**2 for i in x]
alt_y = [i**2 for i in alt_x]    #conjunto alternativo com maior precisao, só para melhor plotagem no gráfico
x_to_interpolate = [ i+0.53 for i in x]  #criando valores x para serem calculados

lagrange_values = [ lagrange_interpolation(i,x,y) for i in x_to_interpolate]
newton_values = [ newton_interpolation(i,x,y) for i in x_to_interpolate]

plt.plot(alt_x,alt_y, "k", label="Valor de referência")
plt.plot(x_to_interpolate,lagrange_values, "ro", label="interp. por lagrange",markersize=3.5)
plt.plot(x_to_interpolate,newton_values, "co", label="interp. por newton",markersize=2.5)
plt.xlabel('eixo x')
plt.ylabel('eixo y')
plt.xlim([-50,50])
plt.ylim([-2,3000])
plt.grid()
plt.title(u"Valores e interpolações para y=x² por método",fontsize=14)
plt.legend(fontsize=10)


plt.show()






# anotacoes de estudo

# x = [ 0, 0.35, 0.65, 1]
# y = [ (math.e)**(i) for i in x]


# print(newton_interpolation(0.6,x,y))

# #plotando erro              visualização nao ficou boa
# lagrange_error = []
# newton_error = []
# for i in range(len(x_to_interpolate)):
#     lagrange_error.append( math.fabs(x_to_interpolate[i]**2 - lagrange_values[i]))
#     newton_error.append( math.fabs(x_to_interpolate[i]**2 - newton_values[i]))


# plt.bar(x_to_interpolate,lagrange_error,  label=" Métd. Lagrange")
# plt.bar(x_to_interpolate,newton_error, label=" Métd. Newton")
# plt.xlabel('eixo x')
# plt.ylabel('Erro absoluto')
# #definindo valor maximo para melhor resolucao do grafico
# plt.grid()
# plt.title(u"Erro absoluto para métodos de interpolação",fontsize=14)
# plt.legend(fontsize=10)
# plt.show()


