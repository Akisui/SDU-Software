import numpy as np
import matplotlib.pyplot as plt  
x1=[10,20,30,40,50,60,70,80,90,100]
y1=[0.007573,0.028676,0.052855,0.097378,0.180813,0.31133,0.484649,0.718244,1.01026,1.37485]

l1=plt.plot(x1,y1,'r--',label='Rrogram 2-22')

plt.xticks([x for x in range(max(x1) + 1) if x % 10 == 0])
plt.plot(x1,y1,'ro-')
plt.title('Runtime Test')
plt.xlabel('rows')
plt.ylabel('time/ms')
plt.legend()
plt.savefig('./figure.png', dpi = 300)
plt.show()

