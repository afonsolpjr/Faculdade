import math as m
import numpy as np
import matplotlib.pyplot as plt



m = [ 0, 0.002, 0.006, 0.012, 0.018, 0.024 ]
v = [ 0, 0.287, 0.899, 1.915, 3.048, 4.299 ]
mi = 0.000018

# Queremos a derivada da velocidade (v) em função da posição (m)
# Como não temos valores de posicao m<0, não podemos fazer uma aproximação centrada.
# Logo usaremos somente a diferença avançada.

dvdm= (v[1] - v[0]) / m[1]

tensao = mi * dvdm

print("Tensao de cisalhamento para y = 0 metros:    {:.10f}".format(tensao))




#TAREFA 3 ITEM B)

time = [i*2 for i in range(9)]
pos = [0, 0.7, 1.8, 3.4, 5.1, 6.3, 7.3, 8, 8.4]

time_pos = { time[i]:pos[i] for i in range(1,8)}
          
#calculando velocidade por diferença centrada para pontos entre 1 e 7, onde se pode fazer centrado
vel = []
for i in range(0,7):
    vel.append( (pos[i+2] - pos[i])  / 4 )

# calculando aceleração analogamente
accel = []
for i in range(0,7):
    accel.append( (pos[i+2] -2*pos[i+1] + pos[i])  / 4 )

plt.plot(time,pos , "-ko")
plt.plot([time[i] for i in range(1,8)], vel, '-go' , label='Velocidade')
plt.plot([time[i] for i in range(1,8)], accel, '-ro', label='Aceleração')
plt.legend(fontsize=8)
plt.xlabel("Posição")
plt.ylabel("Tempo")
plt.grid()
plt.annotate("v={}".format(vel[4]),(10,1))
plt.annotate("accel = {:.4f}".format(accel[4]),(8,-0.5))
plt.title(u'Posição x Tempo, Velocidade e aceleração')
plt.show()