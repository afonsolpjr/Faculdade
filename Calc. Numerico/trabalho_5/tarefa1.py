import numpy
import math

# edo: EDO conhecida
# a: valor inicial
# b:valor desejado
# y0: valor inicial
# n: numero de pontos a ser utilizado 
def metodo_euler(edo, a, b,y0, n):
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
        



def edo1(x,y):
    return 0.04*y

def edo2(x,y):
    return (y/x) + 2*(math.e**(-y/x))


result = metodo_rk4(edo2,1,3,0,10)

print("resultado = {:.30f}".format(result[-1]))
