import matplotlib.pyplot as plt

def lagrange_interpolation(valor_x,lista_x,lista_y):
    num_termos = len(lista_x)
    print(lista_x,lista_y)
    resultado = 0
    for i in range(num_termos): #somatorio
        termo = 1
        for j in range(num_termos):  #produtorio 
            if(j!=i):
                termo *= ((valor_x - lista_x[j])/(lista_x[i] - lista_x[j]))            
        termo *= lista_y[i] #multiplicando por y_i

        resultado+=termo

    return resultado

def newton_interpolation(valor_x,lista_x,lista_y):

    num_termos = len(lista_x)
    resultado = 0

    for i in range(num_termos):
        termo = lista_y[i]
        for j in range(num_termos-i,0,-1):
            termo *= (valor_x - lista_x[j])
        resultado += termo
    
    return resultado


x = [i for i in range(100)]
y = [ i**2 for i in x]

print("Valor estimado pela minha funcao = {:.12f}".format(
    lagrange_interpolation(50.5,x,y)))
plt.plot(x,y,"ko",label ="x²")
plt.grid()
plt.show()

