import numpy;
import math;

# para n = 5 em um intervalo igualmente espaçado em [0,1] usariamos linspace(0,1,6)

# Tarefa 1:
# Item A)
def int_trapez_v1(h,f_values):
    n = len(f_values)
    result = h/2
    sum = 0
    for i in range(1,n-1):
        sum += f_values[i]
    result*=(f_values[0] + f_values[-1] + 2*sum)
    return result

def int_trapez_v2(func,a,b,n):
    x_values = numpy.linspace(a,b,n)
    h = x_values[1] - x_values[0]
    n = len(x_values)
    result = h/2

    f_values = [ func(i) for i in x_values]
    
    sum = 0
    for i in range(1,n-1):
        sum += f_values[i]
    result*=(f_values[0] + f_values[-1] + 2*sum)
    return result

def int_simpson_v1(h,f_val):
    n = len(f_val)
    resultado = h/3

    sum = 0 
    for i in range(1,n//2-1):
        print("i={}".format(i))
        sum+=(f_val[2*i -2] + 4*f_val[2*i-1] + f_val[2*i])
    resultado*=sum
    return resultado


def funcao(x):
    return -(x*x)/4
    
xl = numpy.linspace(0,7,100)
print(xl)
h = xl[1]-xl[0]
lista_xx = [ -(x*x)/4 for x in xl ]
print("Valor de h: {:.6f}\nValor da integral: {:.15f}".format(h,int_trapez_v1(h,lista_xx)))

print("\nusando a segunda funcao: {:.15f}".format(int_trapez_v2(funcao,0,7,100)))
    
print("Regra de simpson: {:.15f}".format(int_simpson_v1(h,lista_xx)))

    
