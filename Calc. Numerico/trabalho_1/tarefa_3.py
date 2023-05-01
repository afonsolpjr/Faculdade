import  math
import sys

sys.setrecursionlimit(10000)
# ITEM 2B

def euler_kahan(n_termo):
    erro_a_compensar = 0
    termo = 1
    soma = 1      #computando termo 0
    for i in range(1,n_termo):

        soma_antes = soma
        termo = termo/i
        termo_compensado = termo + erro_a_compensar        
        soma += termo_compensado  #compensa erro anterior
        erro_a_compensar = (soma_antes - soma) + termo_compensado       #calcula do termo efetivamente somado(erro). 
        #depois diminui do termo que foi somado, dando o erro a ser compensado        


    return (soma - erro_a_compensar)

def pi_kahan(n_termo):
    termo = 1
    erro_a_compensar = 0
    soma = termo* 2            #computando termo 0, daonde se derivará os outros
    for i in range(1,n_termo):
        soma_antes = soma
        termo = termo * (i/((2*i) + 1))
        termo_compensado = termo + erro_a_compensar/2           #precisa dividir o erro porque como a soma é += 2* o termo, ele seria compensado 2x
        soma += termo_compensado*2
        erro_a_compensar = (soma_antes - soma) + termo_compensado*2

    return soma


print("\n\t[CALCULANDO COM SOMA COMPENSADA DE KAHAN....]\n")

lista_k = [5,10,50,100,500,1000,5000]

for x in lista_k:
    aprox=pi_kahan(x)
    
    erro = math.fabs(math.pi - aprox)
    print("PI compensado com {} termos : {:.50f}\nErro absoluto de {:.50f}\n".format(x,aprox,erro))

for x in lista_k:
    aprox = euler_kahan(x)
    
    erro = math.fabs(math.e - aprox)
    print(" 'e' compensado com {} termos : {:.50f}\nErro absoluto de {:.50f}\n".format(x,aprox,erro))