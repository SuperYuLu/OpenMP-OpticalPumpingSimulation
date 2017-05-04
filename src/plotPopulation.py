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
# Last-Updated: Thu May  4 09:39:59 2017 (-0500)
#           By: yulu
#     Update #: 46
# 

import numpy as np
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import re

path = '../dat/'
configFile = 'setValues.h'
fileG1 = 'groundState_F1_population.csv'
fileG2 = 'groundState_F2_population.csv'
fileE = 'excitedState_population.csv'

content = open(configFile, 'r').read()
tStep = float(re.findall('\d.+', re.findall('tStep = \d.+\d', content)[0])[0])



plt.figure(1)

plt.subplot(111)
#tStep = 1e-9
data = np.genfromtxt(path + fileG1, delimiter = ' ')
length = len(data[:,0])
t = np.linspace(0, (length - 1) * tStep, length) * 1e6 #[us]
plt.plot(t,data[:,0], label = 'F=1, mf = -1')
plt.plot(t,data[:,1], label = 'F=1, mf = 0')
plt.plot(t,data[:,2], label = 'F=1, mf = 1')
plt.xlabel('Time [us]')
plt.ylabel('Population')
plt.legend()
plt.title(fileG1[:-4])
plt.savefig('../dat/groundStateF1Population.png')

plt.figure()
plt.subplot(111)
data = np.genfromtxt(path + fileG2, delimiter = ' ')
plt.plot(t,data[:,0], label = 'F=2, mf = -2')
plt.plot(t,data[:,1], label = 'F=2, mf = -1')
plt.plot(t,data[:,2], label = 'F=2, mf = 0')
plt.plot(t,data[:,3], label = 'F=2, mf = 1')
plt.plot(t,data[:,4], label = 'F=2, mf = 2')
plt.xlabel('Time [us]')
plt.ylabel('Population')
plt.legend()
plt.title(fileG2[:-4])
plt.savefig('../dat/groundStateF2Population.png')


plt.figure()
plt.subplot(111)

data = np.genfromtxt(path + fileE, delimiter = ' ')

if data.shape[1] == 5:
    plt.plot(t,data[:,0], label = 'F=2, mf = -2')
    plt.plot(t,data[:,1], label = 'F=2, mf = -1')
    plt.plot(t,data[:,2], label = 'F=2, mf = 0')
    plt.plot(t,data[:,3], label = 'F=2, mf = 1')
    plt.plot(t,data[:,4], label = 'F=2, mf = 2')
elif data.shape[1] == 3:
    plt.plot(t,data[:,0], label = 'F=1, mf = -1')
    plt.plot(t,data[:,1], label = 'F=1, mf = 0')
    plt.plot(t,data[:,2], label = 'F=1, mf = 1')

plt.xlabel('Time [us]')
plt.ylabel('Population')
plt.legend()
plt.title(fileE[:-4])
plt.savefig('../dat/excitedStatePopulation.png')
#plt.show()




