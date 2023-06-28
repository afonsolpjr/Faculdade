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


#Definindo a função interior à integral de Fresnel:

def interior_fresnel(t):
    return math.cos((t**2)*(math.pi/2))

# Definindo  a integral de fresnel, que recebe, além de x, o numero n.

def fresnel(x):
    #determinar maior valor da 4ª derivada no intervalo [0,x]
    if(x<0):
        x_test = numpy.linspace(x,0,1001)
    else:
        x_test = numpy.linspace(0,x,1001)
    
    y_test = [ math.fabs(f4_dx(i)) for i in x_test ]
    max_val = max(y_test)
    
    # Determinar o melhor valor de n para erro < 10⁻⁸
    n = math.fabs((max_val*(x**5)*(10**7))/18)**(1/4)
    n = (int)(n//1)

    return int_simpson_v2(interior_fresnel,0,x,n**2)



#Definindo a 4a derivada da função, para o calculo de M4.
def f4_dx(x):
    resultado = 0
    resultado += -3*((math.pi)**2)*(math.cos((1/2)*math.pi*(x**2)))
    resultado += 6*(math.pi**3)*(x**2)*(math.sin((1/2)*math.pi*(x**2))) 
    resultado += (math.pi**4)*(x**4)*(math.cos((1/2)*math.pi*(x**2)))
    return resultado




x_values = [-2,0.5,1,5]
f_values = [fresnel(i) for i in x_values]
error = []
error.append( math.fabs( -0.48825340607534075450 - f_values[0]) )
error.append( math.fabs( 0.49234422587144639288 - f_values[1]) )
error.append( math.fabs( 0.77989340037682282947 - f_values[2]) )
error.append( math.fabs( 0.56363118870401223110 - f_values[3]) )
val_string  = [ str(i) for i in x_values]

plt.title("Erro absoluto para C(x) para x = [-2,0.5,1,5]")
plt.xlabel("Valor de x")
plt.ylabel("Erro para C(x)")
plt.plot(x_values,error, "k.",linestyle='dotted')
plt.show()