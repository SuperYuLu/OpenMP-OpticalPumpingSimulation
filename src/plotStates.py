import numpy as np
import os
import matplotlib.pyplot as plt

folder = '../dat/'

if os.path.exists(folder):
    file1 = 'numInitState.csv'
    data2D = np.loadtxt(folder + file1,delimiter = ',')
    p1 = plt.figure()
    timeX = np.linspace(0, len(data2D[:,0]) , len(data2D[:,0]))
    plt.plot(timeX, data2D[:,0],'*', label = 'F=1,m=-1')
    plt.plot(timeX, data2D[:,1],'*', label = 'F=1,m=-0')
    plt.plot(timeX, data2D[:,2],'*', label = 'F=1,m=1')
    plt.title('Ground State F = 1 hyperfine states')
    plt.xlabel('number of emission cycles')
    plt.ylabel('Population')
    plt.legend()
    p1.savefig(folder + file1[:-4] + '.png', dpi=150)
    
        
    file2 = 'numTargetState.csv'
    data2 = np.loadtxt(folder + file2,delimiter = ',')
    p2 = plt.figure()
    timeX = np.linspace(0, len(data2[:,0]) , len(data2[:,0]))
    plt.plot(timeX, data2[:,0],'*', label = 'F=2,m=-2')
    plt.plot(timeX, data2[:,1],'*', label = 'F=2,m=-1')
    plt.plot(timeX, data2[:,2],'*', label = 'F=2,m=0')
    plt.plot(timeX, data2[:,3],'*', label = 'F=2,m=1')
    plt.plot(timeX, data2[:,4],'*', label = 'F=2,m=2')
    plt.title('Ground State F = 2 hyperfine states')
    plt.xlabel('number of emission cycles')
    plt.ylabel('Population')
    plt.legend()
    p2.savefig(folder + file2[:-4] + '.png', dpi=150)
    plt.show()
        
