import math as m
import numpy as np
import matplotlib.pyplot as plt

#Tarefa 2, item a)

def funcao(x):
    return 1/x

def derivada_1a(f,x_0,delta_x):
    dif_avancada = f(x_0 + delta_x)/delta_x
    dif_atrasada = f(x_0 - delta_x)/delta_x

    return (dif_avancada - dif_atrasada)/2

def derivada_2a(f,x_0,delta_x):
    avanco = f(x_0 + delta_x)
    atraso = f(x_0 - delta_x)

    return (avanco + atraso - 2*f(x_0) )/delta_x**2

def derivada_3a(f,x_0,delta_x):
    numerador = f(x_0 + 2*delta_x) -2*f(x_0+delta_x) + 2*f(x_0-delta_x) - f(x_0 - 2*delta_x)

    return numerador / (2 * (delta_x**3))


delta_x = 0.001
print(
    "\n\t ITEM A) \n"
    "\n\tf(x) = 1/x\n" +
    "\nPrimeira derivada \ncalculando f'(1.2)  |  x0 = 1.2 | delta_x = 0.001\n" + 
    "Valor de referencia: -25/36 ou -0.6944444444\n" +
    "Resultado computado: [ {} ]\n".format(derivada_1a(funcao,1.2,delta_x)) )

print("\n Segunda derivada" +
    "\ncalculando f''(1.2)  |  x0 = 1.2 | delta_x = 0.001\n" + 
    "Valor de referencia: 125/108 ou 1.157407407\n" +
    "Resultado computado: [ {} ]\n".format(derivada_2a(funcao,1.2,delta_x)) )

print("\n Terceira derivada" +
    "\ncalculando f'''(1.2)  |  x0 = 1.2 | delta_x = 0.001\n" + 
    "Valor de referencia: -625/216 ou -2.893518519\n" +
    "Resultado computado: [ {} ]\n".format(derivada_3a(funcao,1.2,delta_x)) )



#Tarefa 2 item b)


def derivada_1a(f,x_0,delta_x):
    f_i = { i:f(x_0 + (i*delta_x)) for i in range(-10,10)}

    return (f_i[1] - f_i[-1]) / (2*delta_x)


def derivada_2a(f,x_0,delta_x):
    f_i = { i:f(x_0 + (i*delta_x)) for i in range(-10,10)}

    return (f_i[1] + f_i[-1] -2*f_i[0]) / (delta_x**2)

def derivada_3a(f,x_0,delta_x):
    f_i = { i:f(x_0 + (i*delta_x)) for i in range(-10,10)}

    numerador = f(x_0 + 2*delta_x) -2*f(x_0+delta_x) + 2*f(x_0-delta_x) - f(x_0 - 2*delta_x)

    return (f_i[2] - f_i[-2] - 2*f_i[1] + 2*f_i[-1]) / 2*(delta_x**3)


print(
    "\n\t ITEM B)\n"
    "\n\tf(x) = 1/x\n" +
    "\nPrimeira derivada \ncalculando f'(1.2)  |  x0 = 1.2 | delta_x = 0.001\n" + 
    "Valor de referencia: -25/36 ou -0.6944444444\n" +
    "Resultado computado: [ {} ]\n".format(derivada_1a(funcao,1.2,delta_x)) )

print("\n Segunda derivada" +
    "\ncalculando f''(1.2)  |  x0 = 1.2 | delta_x = 0.001\n" + 
    "Valor de referencia: 125/108 ou 1.157407407\n" +
    "Resultado computado: [ {} ]\n".format(derivada_2a(funcao,1.2,delta_x)) )

print("\n Terceira derivada" +
    "\ncalculando f'''(1.2)  |  x0 = 1.2 | delta_x = 0.001\n" + 
    "Valor de referencia: -625/216 ou -2.893518519\n" +
    "Resultado computado: [ {} ]\n".format(derivada_3a(funcao,1.2,delta_x)) )


# TAREFA 2 ITEM C

def funcao(x):
    return m.sin(m.sqrt(x)) / m.sqrt(x)

def deriva(f,x_0,delta_x,ordem):
    f_i = { i:f(x_0 + (i*delta_x)) for i in range(-3,4)}

    match ordem:
        case 1:
            return (f_i[1] - f_i[-1]) / (2*delta_x)

        case 2:
            return (f_i[1] + f_i[-1] -2*f_i[0]) / (delta_x**2)

        case 3:
            return (f_i[2] - f_i[-2] - 2*f_i[1] + 2*f_i[-1]) / (2*(delta_x**3))

def funcao_referencia(x,ordem):       #criando referencia manual das derivadas, para comparacao
    match ordem:
        case 1:
            num = x**(1/2) * m.cos(x**(1/2))
            num += -(m.sin(x**(1/2)))
            return num / (2*(x**(3/2)))
        case 2:       #vai demorar um pouco pra escrever tudo
            num = 3*x*m.sin(x**(1/2))
            num +=  -2*m.cos(x**(1/2))*x*(x**(1/2))
            num += (x**(1/2)) * -x * m.cos((x**(1/2)))
            num += -x*x * m.sin((x**(1/2)))
            return num/(4*(x**(7/2)))
        case 3:
            num = -15*x*m.sin(x**(1/2))
            num += 15 * m.cos(x**(1/2)) * (x**(3/2))
            num += -x*x * (x**(1/2)) * m.cos((x**(1/2)))
            num += 6 * x * x * m.sin((x**(1/2)))
            return num / ( 8 * (x**(9/2)))

val_delta = [0.1,0.01,0.001,0.0001]      #definindo valores de delta
x = np.linspace(0.31,1,3)         #definindo valores a serem calculados
for ordem in range(1,4):
    caso_delta=[]
    erros = []    #guardará erros
    ref = [funcao_referencia(val,ordem) for val in x]    #referencia da ordem

    for delta in val_delta :     #cria lista do tipo derivada[ordem da derivada][valor de val_delta (1,2,3,4) ]
        caso_delta.append([deriva(funcao,val,delta,ordem) for val in x])
        erros.append( [m.fabs(ref[i] - caso_delta[val_delta.index(delta)][i]) for i in range(3)] ) #valor absoluto da referencia - o calculado
    #plotando graficos
    plt.figure(figsize=(10,5)) 
    plt.plot(x, caso_delta[0], '-ro', label="Δx={}".format(val_delta[0]) )
    plt.plot(x, caso_delta[1], 'go', label="Δx={}".format(val_delta[1]) )
    plt.plot(x, caso_delta[2], 'bo', label="Δx={}".format(val_delta[2]) )
    plt.plot(x, caso_delta[0], 'co', label="Δx={}".format(val_delta[3]) )
    plt.plot(x, ref, "k", label="Valor de referencia")
    plt.xlabel("Eixo x")
    string_derivada = ""
    for i in range(ordem):
        string_derivada += '\''
    plt.ylabel("F" + string_derivada + "(x)")
    plt.legend(fontsize=10)
    plt.title(u"{}º Derivada".format(ordem))
    plt.grid()
    plt.show()
    #plotando erros
    plt.plot(x, erros[0], '-ro', label="Erro para Δx={}".format(val_delta[0]) )
    plt.plot(x, erros[1], 'go', label="Erro para Δx={}".format(val_delta[1]) )
    plt.plot(x, erros[2], 'bo', label="Erro para Δx={}".format(val_delta[2]) )
    plt.plot(x, erros[0], 'co', label="Erro para Δx={}".format(val_delta[3]) )
    plt.plot(x,[0*i for i in range(3)],"k")
    plt.legend(fontsize=10)
    plt.xlabel("Eixo x")
    plt.grid()
    plt.title(u"Erro absoluto para {}ª derivada".format(ordem))
    plt.show()
    