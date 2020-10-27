import pandas as pd
import csv
import matplotlib.pyplot as plt
import numpy as np
headers = ['N','100','300','1000','2000','10000','50000']

df = pd.read_csv('/Users/chenningli/Desktop/Projects/algorithms/CSE_830/hw4/hw4_2.csv',names=headers)
# print (df)

x = df['N']
x=x[1:-1].astype(int)
y=(df.values[1:-1,1:7].astype(float))
print(y.shape)
# plot
y_low=y.min()
y_high=y.max()
for ii in range(len(headers)-1):
    plt.plot(x,y[:,ii],label='k='+headers[ii+1])
plt.legend(loc="upper left")
plt.xticks(np.arange(min(x), max(x)+1, (max(x)-min(x))/5))
plt.yticks(np.arange(y_low, y_high, step=(y_high-y_low)/5))
plt.xlabel('Sorted Numbers')
plt.ylabel('Time')
# beautify the x-labels
plt.gcf().autofmt_xdate()

# plt.show()
plt.savefig('hw4_2.png')