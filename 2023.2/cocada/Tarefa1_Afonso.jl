#Testando valor max e minimo de variáveis 8bits

x = Int8(-127)
x - Int8(1)
x * Int8(-1) # Vemos então o intervalo de -128 a 127


x = BigInt(2^63)   
#Note que o resultado dá overflow, mesmo para o tipo BigInt, sendo negativo.
#Isto ocorre porque constantes em Julia são consideradas Inteiras de 64 bits.

#Observe o comportamento diferente em:
x = BigInt(2)^63

#Representação em ponto flutuante com perda de precisão
x = 10.0^16
y = 10.0^16 + 1
x == y # Teoricamente, deveria dar false.
# Representação de Infinito
x = 10.0^309
x/x      

x = 1.0
while x>0 # Loop teoricamente não deveria acabar. Porém alguma hora o resultado é truncado para 0.
    x = x/2
    println(x)
end

x = 5.0e-324
x = 5.0e-325


using Plots