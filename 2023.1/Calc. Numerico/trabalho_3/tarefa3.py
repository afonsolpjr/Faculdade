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
        return False
    
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


#TAREFA 3 ITEM A)

#criando lista de entrada (valores da tabela)
x_4 = [80,53.5,38.43,30.39,30]
y = [0,2,4,6,8]
## interpolação linear usando pontos y = [2,4]
intpol_lagrange = []
intpol_newton = []
intpol_lagrange.append(lagrange_interpolation(3.2,y[1:3],x_4[1:3]))
intpol_newton.append(newton_interpolation(3.2,y[1:3],x_4[1:3]))

##interpolacao quadratica usando y=[2,4,6]
intpol_lagrange.append(lagrange_interpolation(3.2,y[1:4],x_4[1:4]))
intpol_newton.append(newton_interpolation(3.2,y[1:4],x_4[1:4]))

##interpolacao cubica usando y=[0,2,4,6]

intpol_lagrange.append(lagrange_interpolation(3.2,y[0:4],x_4[0:4]))
intpol_newton.append(newton_interpolation(3.2,y[0:4],x_4[0:4]))

for i in range(3):
    match i:
        case 0:
            print("\tAproximação Linear usando pontos y = [2,4]:\n" +
            "Método de Lagrange : {:.10f}\nMétodo de Newton: {:.10f}"
            .format(intpol_lagrange[i],intpol_newton[i]))
        case 1:
            print("\tAproximação Quadrática usando pontos y = [2,4,6]:\n" +
            "Método de Lagrange : {:.10f}\nMétodo de Newton: {:.10f}"
            .format(intpol_lagrange[i],intpol_newton[i]))
        case 2:
            print("\tAproximação Cúbica usando pontos y = [0,2,4,6]:\n" +
            "Método de Lagrange : {:.10f}\nMétodo de Newton: {:.10f}"
            .format(intpol_lagrange[i],intpol_newton[i]))
        
#plotando grafico
plt.title(u"Temperatura em y=3.2 por grau de interpolação.\nMétodos de Lagrange e Newton")
plt.plot([2,3,4],intpol_newton,"ro",label="métod. Newton")
plt.plot([2,3,4],intpol_lagrange,"ko",markersize=2.5,label="métod. Lagrange")
plt.xlabel("Numero " + u'n ' + " de pontos" )
plt.ylabel("Temperatura para y=3.2")
plt.grid()
plt.annotate("Linear",[1.93,intpol_lagrange[0]-0.05])
plt.annotate("Quadrática",[2.91,intpol_lagrange[1]+0.05])
plt.annotate("Cúbica",[3.88,intpol_lagrange[2]+0.05])

print("\nOs pontos a serem usados foram pensados de forma que o ponto y=3.2 a ser interpolado fosse o mais próximo possível do centro do intervalo,\n"+
        "evitando assim as oscilações que ocorrem nas extremidades do polinômio interpolador. ")
plt.legend(fontsize=8)
plt.show()


# def fx(x):
#     return x*x

# x = numpy.linspace(-2,2,10)
# y = [fx(i) for i in x]
# x_test = [ i+0.23 for i in x]

# pol_acima = [ newton_interpolation(i,x[1:],y[1:]) for i in x_test]
# pol_abaixo =  [ newton_interpolation(i,x[:-1],y[:-1]) for i in x_test]
# pol_meio = []
# correto = [fx(i) for i in x_test]

# for i in range(len(pol_abaixo)):
#     pol_meio.append((pol_acima[i] + pol_abaixo[i])/2)

# erro_acima = [ math.fabs(correto[i] - pol_acima[i]) for i in range(len(correto))]
# erro_abaixo = [ math.fabs(correto[i] - pol_abaixo[i]) for i in range(len(correto))]
# erro_meio = [ math.fabs(correto[i] - pol_meio[i]) for i in range(len(correto))]

# plt.plot(x_test,erro_acima,"bo",label="Acima")
# plt.plot(x_test,erro_abaixo,"ro",label="abaixo")
# plt.plot(x_test,erro_meio,"g",label="meio",linestyle="dotted")
# plt.legend(fontsize=8)
# plt.grid()
# plt.show()