import csv
import pandas as pd
import numpy as np
#import seaborn as sns
#import scipy
#import statistics as s

import matplotlib.pyplot as plt
import plotly.plotly as py
import plotly.graph_objs as go
#from plotly.tools import FigureFactory as FF
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm

##
## Calculating mean and variance from experiments
##

##exp = pd.read_csv("exp2.out")
##with open('plot_data_2.csv', 'w') as csvfile:
##    filewriter = csv.writer(csvfile, delimiter=',')
##    filewriter.writerow(['q0','q1','q2','mean_cost','std'])
##    row = 0
##    pas1 = 0
##    pas2 = 0
##    while pas1 < 49:
##        while pas2 < 49: 
##            D = exp[row:row+100]
##            filewriter.writerow([round(np.mean(D['q0']),2),round(np.mean(D['q1']),2),round(np.mean(D['q2']),2),round(np.mean(D['cost']),2),round(np.std(D['cost']),2)])
##            row += 100
##            pas2 += 1
##        pas2 = 0
##        pas1 += 1
        
##exp = pd.read_csv("exp5.out")
##with open('plot_data_5.csv', 'w') as csvfile:
##    filewriter = csv.writer(csvfile, delimiter=',')
##    filewriter.writerow(['q0','q1','q2', 'mean_cost', 'std'])
##    row = 0
##    pas = 0
##    while pas < 49:
##        D = exp[row:row+100]
##        filewriter.writerow([round(np.mean(D['q0']),2),round(np.mean(D['q1']),2),round(np.mean(D['q2']),2),round(np.mean(D['cost']),2),round(np.std(D['cost']),2)])
##        row += 100
##        pas += 1

##exp = pd.read_csv("exp6.out")
##with open('plot_data_6.csv', 'w') as csvfile:
##    filewriter = csv.writer(csvfile, delimiter=',')
##    filewriter.writerow(['q0','mean_cost', 'std'])
##    row = 0
##    pas = 0
##    while pas < 99:
##        D = exp[row:row+500]
##        filewriter.writerow([round(np.mean(D['q0']),2),round(np.mean(D['cost']),2),round(np.std(D['cost']),2)])
##        row += 500
##        pas += 1

##exp = pd.read_csv("exp7.out")
##with open('plot_data_7.csv', 'w') as csvfile:
##    filewriter = csv.writer(csvfile, delimiter=',')
##    filewriter.writerow(['n','q0','q1','q2','mean_cost','std'])
##    row = 0
##    pas = 0
##    while pas < 1125: 
##        D = exp[row:row+100]
##        filewriter.writerow([np.mean(D['n']),round(np.mean(D['q0']),2),round(np.mean(D['q1']),2),round(np.mean(D['q2']),2),round(np.mean(D['cost']),2),round(np.std(D['cost']),2)])
##        row += 100
##        pas += 1

##exp = pd.read_csv("exp8.out")
##with open('plot_data_8.csv', 'w') as csvfile:
##    filewriter = csv.writer(csvfile, delimiter=',')
##    filewriter.writerow(['n','q0','mean_cost', 'std'])
##    row = 0
##    pas = 0
##    while pas < 45:
##        D = exp[row:row+100]
##        filewriter.writerow([np.mean(D['n']),round(np.mean(D['q0']),2),round(np.mean(D['cost']),2),round(np.std(D['cost']),2)])
##        row += 100
##        pas += 1

##
## Plotting
##

##
## K=2,s=1, alfa = 0.561552812809, beta = 1.5950990958, nu = 2.7325699914
##
## K=6,s=3, alfa = 0.561552812809, beta = 0.869033936, nu = 4.36905602
## 

##data1 = pd.read_csv('plot_data_3.csv')
##data2 = pd.read_csv('plot_data_4.csv')
##data3 = pd.read_csv('plot_data_5.csv')
##x = data1['q2']
##y1 = data1['mean_cost']
##y2 = data2['mean_cost']
##y3 = data3['mean_cost']
##t1 = (4.3690)*(50000**0.5615)*(.9*.1*.9*.1*x*(1-x))**(0.5615/2)
##t2 = (4.3690)*(50000**0.5615)*(.9*.1*.5*.5*x*(1-x))**(0.5615/2)
##t3 = (4.3690)*(50000**0.5615)*(.5*.5*.5*.5*x*(1-x))**(0.5615/2)
##f1 = (.9*.1*.9*.1*x*(1-x))**(0.5615/2)
##f2 = (.9*.1*.5*.5*x*(1-x))**(0.5615/2)
##f3 = (.5*.5*.5*.5*x*(1-x))**(0.5615/2)
##
##plt.plot(x,y1,'r--',x,y2,'b--',x,y3, 'g--',x,t1,'r',x,t2,'b',x,t3, 'g')
##plt.xlabel('$q_2$')
##plt.ylabel('$P_{n,q}$')
##plt.title('$K=6$, $s=3$, $q=(q_0,q_1,q_2)$, $n=50000$')
##plt.legend(['$q_0 = 0.1, q_1 = 0.1$','$q_0 = 0.1, q_1 = 0.5$','$q_0 = 0.5, q_1 = 0.5$'])
##plt.show()
##
##
##plt.plot(x,y1/((4.3690)*(50000**0.5615)),'r--',x,y2/((4.3690)*(50000**0.5615)),'b--',x,y3/((4.3690)*(50000**0.5615)), 'g--',x,f1,'r',x,f2,'b',x,f3, 'g')
##plt.xlabel('$q_2$')
##plt.ylabel('$f(q)$')
##plt.title('$K=6$, $s=3$, $q=(q_0,q_1,q_2)$, $n=50000$')
##plt.legend(['$q_0 = 0.1, q_1 = 0.1$','$q_0 = 0.1, q_1 = 0.5$','$q_0 = 0.5, q_1 = 0.5$'])
##plt.show()

#
# 3D Plot
#
fig = plt.figure()
ax = fig.gca(projection='3d')

data1 = pd.read_csv('plot_data_2.csv')
x = data1['q2']
y = data1['q1']
z = data1['mean_cost']
f = (4.36905602)*(50000**0.5615)*(x*(1-x)*y*(1-y)*0.5*0.5)**(0.5615/2)
#surf = ax.plot_trisurf(x, y, z,cmap=cm.coolwarm, linewidth=0,antialiased=False)
surf1 = ax.plot_trisurf(x, y, f, cmap=cm.Greys, linewidth=0,antialiased=False)
fig.colorbar(surf1)
fig.tight_layout()
ax.set_xlabel('$q_2$')
ax.set_ylabel('$q_1$')
ax.set_zlabel('$P_{n,q}$')
plt.title('$K=6$, $s=3$, $q=(q_0,q_1,q_2)$, $q_0 = 0.5$, $n=50000$')
#plt.show()# or:
fig.savefig('3D_4.png')
#
##
##data1 = pd.read_csv('plot_data_6.csv')
##x = data1['q0']
##y = data1['mean_cost']
##t = (2.7325699914)*(50000**0.5615)*(x*(1-x))**(0.5615/2)
##f = (x*(1-x))**(0.5615/2)
####
####plt.plot(x,y,'r--', x,t,'r')
####plt.xlabel('$q_0$')
####plt.ylabel('$P_{n,q}$')
####plt.title('$K=2$, $s=1$, $q=(q_0)$, $n=50000$')
####plt.show()
####
##plt.plot(x,y/((2.7325699914)*(50000**0.5615)),'r--',x,f,'r')
##plt.xlabel('$q_0$')
##plt.ylabel('$f(q)$')
##plt.title('$K=2$, $s=1$, $q=(q_0)$, $n=50000$')
##plt.show()

##data1 = pd.read_csv('plot_data_8.csv')
##d1 = data1.loc[data1['q0'] == 0.1]
##x1 = d1['n']
##y1 = d1['mean_cost']
##d2 = data1.loc[data1['q0'] == 0.2]
##x2 = d2['n']
##y2 = d2['mean_cost']
##d3 = data1.loc[data1['q0'] == 0.3]
##x3 = d3['n']
##y3 = d3['mean_cost']
##d4 = data1.loc[data1['q0'] == 0.4]
##x4 = d4['n']
##y4 = d4['mean_cost']
##d5 = data1.loc[data1['q0'] == 0.5]
##x5 = d5['n']
##y5 = d5['mean_cost']
####
##plt.plot(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5)
##plt.xlabel('$n$')
##plt.ylabel('$P_{n,q}$')
##plt.title('$K=2$, $s=1$, $q=(q_0)$, $n=50000$')
##plt.legend(['$q_0 = 0.1,$','$q_0 = 0.2$','$q_0 = 0.3$', '$q_0 = 0.4$','$q_0 = 0.5$'])
##plt.show()
