import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D


def heart_function(t):
    x = 16 * np.sin(t)**3
    y = 13 * np.cos(t) - 5 * np.cos(2*t) - 2 * np.cos(3*t) - np.cos(4*t)
    z = 0
    return x, y, z


t = np.linspace(0, 2*np.pi, 1000)


x, y, z = heart_function(t)


fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')


ax.plot(x, y, z, label='Corazón', color='yellow')


ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
ax.set_title('Mi amor <3')


ax.legend()

ax.set_facecolor('darkorange')  

plt.show()

# <3