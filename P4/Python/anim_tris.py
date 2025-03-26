import tkinter as tk
import numpy as np
import time

#créé la fenetre
root = tk.Tk()
root.geometry('800x600')
root.title('Canvas Demo')

#on defini un canva
w=1000
h=700
canvas = tk.Canvas(root, width=w, height=h, bg='white')

#place canva sur la fenetre
canvas.pack(anchor=tk.CENTER, expand=True)

#fill du coin (x,y) au coin opposé (x',y')
#rect=canvas.create_rectangle((0,0), (10, 100), fill='black')
n=int(w/10)
max = int(h-50)
data=np.random.randint(0,max,n)
print(data)


def bubble_sort() :
      for i in range(len(data)-1):
            for j in range(0,len(data)-1-i) :
                  if data[j]>data[j+1] :
                        aux=data[j]
                        data[j]=data[j+1]
                        data[j+1]=aux

                        #efface les deux rect
                        canvas.create_rectangle((j*10,0),(j*10+10,max), fill='white', width=0)
                        canvas.create_rectangle(((j+1)*10,0),((j+1)*10+10,max), fill='white',width=0)

                        #on recréé les bons
                        canvas.create_rectangle((j*10,0),(j*10+10,data[j]), fill='black')
                        canvas.create_rectangle(((j+1)*10,0),((j+1)*10+10,data[j+1]), fill='black')
                        
                        canvas.update()
                        time.sleep(0.001)

def selection_sort():
      for i in range(len(data)-1,-1,-1) :
            maxim=i
            for j in range(i,-1,-1) :
                  if data[maxim]<data[j]:
                        maxim=j
            aux=data[maxim]
            data[maxim]=data[i]
            data[i]=aux

            #efface les deux rect
            canvas.create_rectangle((maxim*10,0),(maxim*10+10,max), fill='white', width=0)
            canvas.create_rectangle((i*10,0),(i*10+10,max), fill='white',width=0)

            #on recréé les bons
            canvas.create_rectangle((maxim*10,0),(maxim*10+10,data[i]), fill='black', width=0)
            canvas.create_rectangle((i*10,0),(i*10+10,data[i]), fill='black', width=0)
            
            canvas.update()
            time.sleep(0.05)

def insertion_sort() :
      for i in range(1,len(data)) :
            v=data[i]
            j=i
            while data[j-1]>v and j>0:
                  data[j]=data[j-1]
                  canvas.create_rectangle((j*10,0),(j*10+10,max), fill='white',width=0)
                  canvas.create_rectangle((j*10,0),(j*10+10,data[j-1]), fill='black', width=0)
                  time.sleep(0.01)
                  canvas.update()
                  j-=1
            data[j]=v
            canvas.create_rectangle((j*10,0),(j*10+10,max), fill='white',width=0)
            canvas.create_rectangle((j*10,0),(j*10+10,v), fill='black', width=0)
            canvas.update()
            time.sleep(0.001)
    


#TODO : quick sort
#       quick sort + insertion
#       shell sort ?
#       bongo sort mdr

def init_canva() :
      for i in range(len(data)) :
            canvas.create_rectangle((i*10,0),(i*10+10,data[i]), fill='black', width=0)

def move_rect():
    canvas.move(rect, 10, 0)  # Déplace le cercle vers la droite
    canvas.after(10, move_rect)  # Appelle à nouveau cette fonction après 50 millisecondes

#move_rect()
init_canva()

#bubble_sort()
selection_sort()
#insertion_sort()

print(data)
root.mainloop()
