import  math
import sys

sys.setrecursionlimit(10000)
def fat_limitada(a,b):      #calcula a!/b!   
    if(a==b):
        return 1
    result = 1
    for i in range(b+1,a+1):
       result *= i

    return result

def serie_pi_inversa(tam_serie):
    result = 0

    for i in reversed(range(tam_serie)):
        result+= 2 * (2**i * math.factorial(i) ) / fat_limitada(2*i +1, i) 
    
    return result


def serie_euler_inversa(tam_serie):
    resultado=0

    for i in reversed(range(tam_serie)):
        resultado += 1 / (math.factorial(i))

    return resultado

lista_k = [5,10,50,100,500,1000,5000]

print("\n[COM SOMAS INVERSAS]\n")


for x in lista_k:
    aprox = serie_pi_inversa(x)
    erro = math.fabs(math.pi - aprox)
    print("PI com uma série de {} termos: {:.60f}\nErro absoluto de {:.50f}\n".format(x,aprox,erro))


for x in lista_k:
    aprox = serie_euler_inversa(x)
    erro = math.fabs(math.e - aprox)
    print(" 'e' com série de {} termos : {:.50f}\nErro absoluto de {:.50f}\n".format(x,aprox,erro))


# ITEM B

def euler_recursivo(n_termo):
    termo = 1
    resultado = 1      #computando termo 0
    for i in range(1,n_termo):
        termo = termo/i
        resultado += termo

    return resultado

def pi_recursivo(n_termo):
    termo = 1
    resultado = termo* 2            #computando termo 0, daonde se derivará os outros
    for i in range(1,n_termo):
        termo = termo * (i/((2*i) + 1))
        resultado += termo*2

    return resultado


print("\n\t[CALCULANDO RECURSIVAMENTE....]\n")

for x in lista_k:
    aprox=pi_recursivo(x)
    
    erro = math.fabs(math.pi - aprox)
    print("PI recursivo com {} termos : {:.50f}\nErro absoluto de {:.50f}\n".format(x,aprox,erro))

for x in lista_k:
    aprox = euler_recursivo(x)
    
    erro = math.fabs(math.e - aprox)
    print(" 'e' recursivo com {} termos : {:.50f}\nErro absoluto de {:.50f}\n".format(x,aprox,erro))