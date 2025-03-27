import numpy;
import math;

# para n = 5 em um intervalo igualmente espaçado em [0,1] usariamos linspace(0,1,6)

# Tarefa 1:
# Item A)
def int_trapez_v1(h,f_values):  #Versão que utiliza uma lista de favores de f(x) e a variação h.
    n = len(f_values)
    result = h/2
    sum = 0
    for i in range(1,n-1):
        sum += f_values[i]
    result*=(f_values[0] + f_values[-1] + 2*sum)
    return result

def int_trapez_v2(func,a,b,n): #Versão que utiliza a definição da função, os limites de integração e o numero de nós.
    x_values = numpy.linspace(a,b,n+1)
    h = x_values[1] - x_values[0]
    result = h/2

    f_values = [ func(i) for i in x_values]
    
    sum = 0
    for i in range(1,n):
        sum += f_values[i]
    result*=(f_values[0] + f_values[-1] + 2*sum)
    return result

def int_simpson_v1(h,f_val):   #Versão que utiliza uma lista de favores de f(x) e a variação h.
    n = len(f_val)
    resultado = h/3

    sum = f_val[0] + f_val[-1]
    i=1
    if(n%2==0):
        for i in range(1,n//2):
            sum+=(2*f_val[2*i-1] + 4*f_val[2*i-2])
        sum+= 4*f_val[2*i]
    else:
        for i in range(1,n//2):
            sum+=(2*f_val[2*i] + 4*f_val[2*i-1])
        i=n//2
        sum+= 4*f_val[2*i-1]

    resultado*=sum
    return resultado

def int_simpson_v2(func,a,b,n): #Versão que utiliza a definição da função, os limites de integração e o numero de nós.
    if(n%2==1):  #n precisa ser par
        n+=1
    
    x_list = numpy.linspace(a,b,n+1)
    f_val = [ func(i) for i in x_list]
    h = x_list[1] - x_list[0]

    sum = f_val[0] + f_val[-1]
    i=1
    for i in range(1,n//2):
        sum+=(2*f_val[2*i] + 4*f_val[2*i-1])
    i=n//2
    sum+= 4*f_val[2*i-1]

    resultado = sum * (h/3)
    return resultado    


def funcao(x):
    return -(x*x)/4
    
xl = numpy.linspace(0,7,66)
print(xl)
h = xl[1]-xl[0]
lista_xx = [ -(x*x)/4 for x in xl ]
print("Valor de h: {:.6f}\nValor da integral: {:.15f}".format(h,int_trapez_v1(h,lista_xx)))

print("\nusando a segunda funcao: {:.15f}".format(int_trapez_v2(funcao,0,7,100)))
    
print("Regra de simpson: {:.15f}".format(int_simpson_v1(h,lista_xx)))

print("Regra de simpson 2  par: {:.15f}".format(int_simpson_v2(funcao,0,7,66)))
print("Regra de simpson 2  impar: {:.15f}".format(int_simpson_v2(funcao,0,7,67)))



    
