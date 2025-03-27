# AFONSO LUSTOSA PIRES JUNIOR  122079084

import numpy as np
import matplotlib.pyplot as plt
total_time = 10000
n = 100
arrival_rates  = [0.5, 0.8, 0.9, 0.99]

#random number generator
rng = np.random.default_rng()


class Queue_Run:
    def __init__(self,t,arrival_rate,service_rate,mod):
        self.t = t
        self.arrival_rate = arrival_rate
        self.service_rate = service_rate
        self.mod = mod
        self.compute_run()
        

    def compute_run(self):
        #arrival times:
        arrivals = [0]
        next_arrival = rng.exponential(1/self.arrival_rate)
        arrivals.append(next_arrival)
        while(arrivals[-1]+next_arrival<self.t):
            arrivals.append(arrivals[-1] + next_arrival)
            next_arrival = rng.exponential(1/self.arrival_rate)
        self.arrivals = arrivals


        #service times
        if(not self.mod):
            self.service_times = rng.exponential(1,len(self.arrivals))
        else:
            self.service_times = [1 for i in range(0,len(self.arrivals))]
        #compute end times
        ends = []
        ends.append(self.arrivals[0]+self.service_times[0])

        for i in range(1,len(arrivals)):
            if(ends[-1]>=arrivals[i]):
                ends.append(ends[-1]+self.service_times[i])
            else:
                ends.append(self.arrivals[i]+self.service_times[i])
        self.ends = ends
        self.time_in_system = [self.ends[i]-self.arrivals[i] for i in range(0,len(self.arrivals))]





#means and constant service time means
m = []
cm = []
for arrival_rate in arrival_rates:
    runs = []
    const_runs =[]
    for i in range(0,100):
        runs.append(Queue_Run(10000,arrival_rate,1,False))
        const_runs.append(Queue_Run(10000,arrival_rate,1,True))
    
    print("Average amount of time in system for arrival rate({})= {}\n".format(arrival_rate,np.mean([np.mean(run.time_in_system) for run in runs])))
    print("With constant service times:")

    print("\tAverage amount of time in system for arrival rate({})= {}\n".format(arrival_rate,np.mean([np.mean(run.time_in_system) for run in const_runs])))
    mean = np.mean([np.mean(run.time_in_system) for run in runs])
    const_mean = np.mean([np.mean(run.time_in_system) for run in const_runs])
    m.append(mean)
    cm.append(const_mean)
plt.yticks([i for i in range(0,61,2)])

plt.scatter(arrival_rates,m,color="black",label="Tempo de serviço exponencialmente distribuido com param. 1")
plt.scatter(arrival_rates,cm,color="red",label = "Tempo de serviço constante = 1")
plt.title("Médias de tempo de serviço por taxas de chegadas")
plt.legend()

plt.show()
