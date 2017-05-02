# plotPopulation.py --- 
# 
# Filename: plotPopulation.py
# Description: 
# 
# Author:    Yu Lu
# Email:     yulu@utexas.edu
# Github:    https://github.com/SuperYuLu 
# 
# Created: Tue May  2 13:06:41 2017 (-0500)
# Version: 
# Last-Updated: Tue May  2 13:29:48 2017 (-0500)
#           By: yulu
#     Update #: 14
# 

import numpy as np
import matplotlib.pyplot as plt
import os

path = '../dat/'
fileG1 = 'groundState_F1_population.csv'
fileG2 = 'groundState_F2_population.csv'
fileE = 'excitedState_population.csv'


plt.figure()

plt.subplot(111)
data = np.genfromtxt(path + fileG1, delimiter = ' ')
#data = np.loadtxt(path + fileG1, delimiter = ' ')
plt.plot(data[:,0], label = 'F=1, mf = -1')
plt.plot(data[:,1], label = 'F=1, mf = 0')
plt.plot(data[:,2], label = 'F=1, mf = 1')
plt.xlabel('Time [ns]')
plt.ylabel('Population')
plt.legend
plt.title(fileG1[:-4])

'''

plt.subplot(312)
data = np.loadtxt(fileG2, dilimeter = ' ');
plt.plot(data[:,0], label = 'F=2, mf = -2')
plt.plot(data[:,1], label = 'F=1, mf = 0')
plt.plot(data[:,1], label = 'F=1, mf = 1')
plt.xlabel('Time [ns]')
plt.ylabel('Population')
plt.legend
plt.title(f[:-4])
plt.subplot(313)

'''
plt.show()



