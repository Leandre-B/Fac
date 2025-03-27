import numpy as np


def resoudre(plaques,cible):
	for plaque in plaques :
		if plaque==cible:
			print('solution')
			return
			
	if True :#len(plaques)> :
		for i in range(0,len(plaques)-1):
			for j in range(i+1, len(plaques)):
				
				print(plaques)
				print(len(plaques))
				print(f'i={i} j={j}')
				
				a = plaques[i]
				b = plaques[j]
				
				plaques.remove(a)
				plaques.remove(b)

				if (a+b)<1000 :
					resoudre(plaques+[(a+b)],cible)
					#plaques.remove(a+b)

				if (a-b)>0 :
					resoudre(plaques+[(a-b)],cible)
					#plaques.remove(a-b)

				if (a*b)<1000 :
					resoudre(plaques+[(a*b)],cible)
					#plaques.remove(a*b)

				if b>1 and (a%b)==0 :
					resoudre(plaques+[(a/b)],cible)
					#plaques.remove(a/b)
				
				"""
				plaques.append(a)
				plaques.append(b)
				"""
	

def main():
	plaques = [1,2,3,4,5,6,7,8,9,10,25,50,75,100]
	
	cible = 355
	selection_de_plaques = [1,4,5,7,7,9]
	"""
	cible = 899
	selection_de_plaques = [3,5,8,9,9,25]
	
	cible = 897
	selection_de_plaques = [3,5,8,9,9,25],
	"""

	resoudre(selection_de_plaques,cible)


if __name__=='__main__':
	main()
