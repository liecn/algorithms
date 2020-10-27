import pandas as pd
import csv
import matplotlib.pyplot as plt
import numpy as np
headers = ['N','Insertion','Merge','Hybrid']
df = pd.read_csv('/Users/chenningli/Desktop/Projects/algorithms/CSE_830/hw4/hw4_1_1.csv',names=headers)
print (df)

x = df['N']
x=x[1:-1].astype(int)
y_insertion = df['Insertion']
y_insertion=y_insertion[1:-1].astype(float)
y_merge = df['Merge']
y_merge=y_merge[1:-1].astype(float)
y_hybrid = df['Hybrid']
y_hybrid=y_hybrid[1:-1].astype(float)

# plot
y_low=(min(y_insertion))
y_high=(max(y_insertion))
plot_insertion = plt.plot(x,y_insertion,label='Insertion')
plot_merge = plt.plot(x,y_merge,label='Merge')
plot_hybrid= plt.plot(x,y_hybrid,label='Hybrid')
plt.legend(loc="upper left")
plt.xticks(np.arange(min(x), max(x)+1, (max(x)-min(x))/5))
plt.yticks(np.arange(y_low, y_high, step=(y_high-y_low)/5))
plt.xlabel('Sorted Numbers')
plt.ylabel('Time')
# beautify the x-labels
plt.gcf().autofmt_xdate()

# plt.show()
plt.savefig('hw4_1_1.png')