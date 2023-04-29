import  math


def fat_limitada(a,b):      #calcula a!/b!   
    if(a==b):
        return 1
    result = 1;
    for i in range(b+1,a+1):
       result *= i;

    return result;


def serie_pi(tam_serie):
    result = 0

    for i in range(tam_serie):
        result+= 2 * (2**i * math.factorial(i) ) / fat_limitada(2*i +1, i) 
    
    return result


def serie_euler(tam_serie):
    resultado=0;

    for i in range(tam_serie):
        resultado += 1 / (math.factorial(i))

    return resultado

lista_k = [5,10,50,100,500,1000,5000]

for x in lista_k:
    aprox = serie_pi(x)
    erro = math.fabs(math.pi - aprox)
    print("PI com uma série de {} termos: {:.60f}\nErro absoluto de {:.50f}\n".format(x,aprox,erro))

print()

lista_k
for x in lista_k:
    aprox = serie_euler(x)
    erro = math.fabs(math.e - aprox)
    print(" 'e' com série de {} termos : {:.50f}\nErro absoluto de {:.50f}\n".format(x,serie_euler(x),erro))








   


