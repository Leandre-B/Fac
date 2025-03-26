def tri(t):
	if len(t)<=1:
		return t
	else:
		pivot = t[len(t)//2]
		tinf=[]
		tegal=[]
		tsup=[]
		for i in range(len(t)):
			if t[i]>pivot:
				tsup.append(t[i])
			elif t[i]<pivot:
				tinf.append(t[i])
			else:
				tegal.append(t[i])
		return tri(tinf)+tegal+tri(tsup)
