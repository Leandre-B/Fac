def tri(t):
	for i in range(1,len(t)) :
		v=t[i]
		j=i
		while t[j-1]>v and j>0:
			t[j]=t[j-1]
			j-=1
		t[j]=v
	return t
