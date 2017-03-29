import numpy as np
import os
import matplotlib.pyplot as plt

folder = '../dat/'

if os.path.exists(folder):
    files = os.listdir(folder)
    files.sort()
    for f in files:
        data2D = np.genfromtxt(folder + f, delimiter = ',')
        p = plt.figure()
        plt.plot(data2D[:,0], abs(data2D[:,1]))
        plt.title('Magnetic field distribution at time' + f[:-4])
        plt.xlabel('Position [mm]')
        plt.ylabel('Magnetic field [T]')
        plt.ylim([0, 1.2])
        p.savefig(folder + f[:-4] + '.png', dpi=150)
        #print("--- Plot saved in :  " + folder + f[:-4] +'.png ---')
        plt.close(p)
        
