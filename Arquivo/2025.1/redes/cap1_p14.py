import numpy as np
import matplotlib.pyplot as plt

# Parâmetros
a = 100  # taxa de chegada (pacotes por segundo)
R = 1e6  # taxa de transmissão do link (bps)

# Valores de L/R
# Possiveis valores de L

L_R_vals = np.linspace(0, 0.0099, 500)  # até 9 ms de transmissão

# Valores de a para análise
a_vals = np.linspace(90,100,3)  # diferentes taxas de chegada (pacotes por segundo)

# Plot
plt.figure(figsize=(8, 5))
for a in a_vals:
    I_vals = a * L_R_vals
    total_delay = L_R_vals / (1 - I_vals)
    plt.plot(L_R_vals, total_delay, label=f"a = {a} pacotes/s")

plt.xlabel("L / R (ms)")
plt.ylabel("Atraso total (ms)")
plt.title("Atraso total vs L / R para diferentes valores de a")
plt.grid(True)
plt.ylim(0, 1.1 * max(total_delay))
plt.xlim(0, max(L_R_vals))
plt.legend()
plt.show()
