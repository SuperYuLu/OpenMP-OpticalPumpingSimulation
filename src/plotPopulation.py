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
# Last-Updated: Wed May  3 09:36:06 2017 (-0500)
#           By: yulu
#     Update #: 34
# 

import numpy as np
import matplotlib.pyplot as plt
import re

path = '../dat/'
configFile = 'setValues.h'
fileG1 = 'groundState_F1_population.csv'
fileG2 = 'groundState_F2_population.csv'
fileE = 'excitedState_population.csv'

content = open(configFile, 'r').read()
tStep = float(re.findall('\d.+', re.findall('tStep = \d.+\d', content)[0])[0])



plt.figure()

plt.subplot(111)
#tStep = 1e-9
data = np.genfromtxt(path + fileG1, delimiter = ' ')
length = len(data[:,0])
t = np.linspace(0, (length - 1) * tStep, length) * 1e9 #[ns]
plt.plot(t,data[:,0], label = 'F=1, mf = -1')
plt.plot(t,data[:,1], label = 'F=1, mf = 0')
plt.plot(t,data[:,2], label = 'F=1, mf = 1')
plt.xlabel('Time [ns]')
plt.ylabel('Population')
plt.legend()
plt.title(fileG1[:-4])

plt.figure()
plt.subplot(111)
data = np.genfromtxt(path + fileG2, delimiter = ' ')
plt.plot(t,data[:,0], label = 'F=2, mf = -2')
plt.plot(t,data[:,1], label = 'F=2, mf = -1')
plt.plot(t,data[:,2], label = 'F=2, mf = 0')
plt.plot(t,data[:,3], label = 'F=2, mf = 1')
plt.plot(t,data[:,4], label = 'F=2, mf = 2')
plt.xlabel('Time [ns]')
plt.ylabel('Population')
plt.legend()
plt.title(fileG2[:-4])

plt.figure()
plt.subplot(111)
data = np.genfromtxt(path + fileE, delimiter = ' ')
plt.plot(t,data[:,0], label = 'F=2, mf = -2')
plt.plot(t,data[:,1], label = 'F=2, mf = -1')
plt.plot(t,data[:,2], label = 'F=2, mf = 0')
plt.plot(t,data[:,3], label = 'F=2, mf = 1')
plt.plot(t,data[:,4], label = 'F=2, mf = 2')
plt.xlabel('Time [ns]')
plt.ylabel('Population')
plt.legend()
plt.title(fileE[:-4])

plt.show()
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



