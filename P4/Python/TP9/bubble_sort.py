def tri (t):
   for i in range(len(t)-1):
      for j in range(0,len(t)-1-i) :
         if t[j]>t[j+1] :
            aux=t[j]
            t[j]=t[j+1]
            t[j+1]=aux
   return t


def tri_chelou (t):
   for i in range(len(t)-1):
      for j in range(i+1,len(t)-1):
         if t[i]>t[j] :
            aux=t[j]
            t[j]=t[i]
            t[i]=aux
   return t
