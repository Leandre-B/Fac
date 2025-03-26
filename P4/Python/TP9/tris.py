import numpy as np
import time
import matplotlib.pyplot as plt

#import sorting algo
import bubble_sort
import insertion_sort
import quick_sort

def verif_tris(t) ->bool:
   for i in range(len(t)-1) :
      if t[i]>t[i+1] :
         #sort du programme entierement
         raise Exception("tableau non trié")
   return True;

def evaluation_bubble_sort(t) :
   debut=time.time()
   bubble_sort.tri_chelou(t)
   fin=time.time()
   return(fin-debut)

def evaluation_insertion_sort(t) :
   debut=time.time()
   insertion_sort.tri(t)
   fin=time.time()
   return(fin-debut)

def evaluation_quick_sort(t) :
   debut=time.time()
   quick_sort.tri(t)
   fin=time.time()
   return(fin-debut)

def main() :
   tailles = [100, 1000, 10000, 20000]
   t1=[]
   t2=[]
   t3=[]
   for taille in tailles:
      rdm_tab=np.random.randint(0,taille,taille)
      t1.append(evaluation_bubble_sort(rdm_tab))
      t2.append(evaluation_insertion_sort(rdm_tab))
      t3.append(evaluation_quick_sort(rdm_tab))
      
   # taille de la figure
   plt.figure(figsize=(8, 5))  
   
   plt.plot(tailles, t1, label='à bulles', marker='o')  
   plt.plot(tailles, t2, label='insertion', marker='s')  
   plt.plot(tailles, t3, label='rapide', marker='x')  
   
   # Label the axes
   plt.xlabel('Tailles')
   plt.ylabel('Temps d\'exécution (s)')
   
   
   plt.title('Efficacité des tris en fonction de la taille des tableaux')
   plt.legend()
   
   
   plt.grid(True)
   plt.show()


if __name__=='__main__':
   main()
