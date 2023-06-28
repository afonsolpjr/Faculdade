import math
import numpy
import matplotlib.pyplot as plt


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


# Definição de f = cos(x)² 
def funcao(x):
    return (math.cos(x)**2)

n_list = [10,50,100,200]

f_int_trapez = []
f_int_simpson = []
for n in n_list:   #Obtendo os valores.
    f_int_trapez.append(int_trapez_v2(funcao,0,10,n))
    f_int_simpson.append(int_simpson_v2(funcao,0,10,n))
print("Valores para o método de Simpson, para n = 10,50,100,200\n",f_int_simpson)
print("\nValores para o método dos Trapézios, para n = 10,50,100,200\n",f_int_trapez)


#Item c) calculando erro absoluto


ref_value = 1/4*(math.sin(20)) + 5

error_trap = [ math.fabs(ref_value - value) for value in f_int_trapez]
error_simp = [ math.fabs( ref_value - value) for value in f_int_simpson]

plt.title(u"Erro absoluto de $\int_{0}^{\pi} cos²(x) \,dx$ por nº de nós utilizados e método")
plt.plot(n_list,error_trap,"bo",label="métod. Trap",linestyle='dotted') 
plt.plot(n_list,error_simp,"rv",label="métod. Simpson",linestyle='dotted')
plt.xlabel("Nº de nós utilizados")
plt.ylabel("Erro absoluto")
plt.legend(fontsize=9)
plt.grid()
plt.show()

