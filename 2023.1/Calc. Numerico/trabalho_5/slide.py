import numpy
import math

# edo: EDO conhecida
# a: valor inicial
# b:valor desejado
# y0: valor inicial
# n: numero de pontos a ser utilizado
# Retorna lista com todos pontos 
def metodo_euler(edo, a, b,y0, n):
    delta_t = (b-a)/n
    t_n = [ (a + delta_t*i) for i in range(n)  ]
    #Começa a lista com o valor inicial
    y_n = [y0]
    for i in t_n:
        #usando aprox. linear de 2a ordem
        lbda = edo(i,y_n[-1]) / y_n[-1]
        y_n.append( y_n[-1] * (1 + lbda*delta_t + ((lbda*delta_t)**2)/2 ) )

    return y_n


def edo1(x,y):
    return 0.04*y

def edo2(x,y):
    return (y/x) + 2*(math.e**(-y/x))

result = metodo_euler(edo2,0,1,1000,10)

print("resultado = {:.30f}".format(result[-1]))
    





