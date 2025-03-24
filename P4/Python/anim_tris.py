import numpy as np
import matplotlib.pyplot as plt
import matplotlib.animation as animation


fig, ax = plt.subplots()
n=20
#data = np.random.uniform(0,100,n)
data=np.linspace(n,1,n)
x = np.linspace(1, n, n)

#1er argument -> num de la frame
def bubble_sort_step(frame) :

  for j in range(n-1-frame) :
    if data[j]>data[j+1] :
      aux = data[j]
      data[j]=data[j+1]
      data[j+1]=aux
      
      bars[j].set_height(data[j])
      bars[j+1].set_height(data[j+1])
  
plt.bar(x,data,color='black')
bars=plt.bar(x,data,color='black')
ani = animation.FuncAnimation(fig,bubble_sort_step, frames=n,repeat=False)
plt.show()
