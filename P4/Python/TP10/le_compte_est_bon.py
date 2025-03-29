import numpy as np
import string
import random

solutions=0
interval = 0

def resoudre(plaques,cible,operation):
	global solutions
	global interval
	
	for plaque in plaques :
		if cible-interval<=plaque<=cible+interval:
			print('Solutions')
			print(operation)
			print('\n')
			solutions+=1
			return
			
	if True :#len(plaques)> :
		for i in range(0,len(plaques)-1):
			for j in range(i+1, len(plaques)):

				aux_plaques=[]
				for plaque in plaques :
					aux_plaques.append(plaque)

				aux_operation=[]
				for ope in operation :
					aux_operation.append(ope)
				
				'''
				print(aux_plaques)
				print(len(aux_plaques))
				print(f'i={i} j={j}')
				'''
				a = aux_plaques[i]
				b = aux_plaques[j]
				
				aux_plaques.remove(a)
				aux_plaques.remove(b)

				if (a+b)<1000 :
					aux_operation.append([str(a) + '+' + str(b) + '=' + str(a+b)])
					resoudre(aux_plaques+[(a+b)],cible,aux_operation)
					aux_operation.pop(-1)

				if (a-b)>0 :
					aux_operation.append([str(a) + '-' + str(b) + '=' + str(a-b)])
					resoudre(aux_plaques+[(a-b)],cible,aux_operation)
					aux_operation.pop(-1)

				if (a*b)<1000 :
					aux_operation.append([str(a) + '*' + str(b) + '=' + str(a*b)])
					resoudre(aux_plaques+[(a*b)],cible,aux_operation)
					aux_operation.pop(-1)

				if b>1 and (a%b)==0 :
					aux_operation.append([str(a) + '/' + str(b) + '=' + str(a/b)])
					resoudre(aux_plaques+[(a/b)],cible,aux_operation)
					aux_operation.pop(-1)
				
				"""
				plaques.append(a)
				plaques.append(b)
				"""
	

def main():
	global interval
	
	cible = random.randint(101,999)
	plaques = [1,2,3,4,5,6,7,8,9,10,25,50,75,100]
	selection_de_plaques = []
	
	for i in range(0,6) :
		rdm = random.randint(0,len(plaques)-1)
		selection_de_plaques.append(plaques[rdm])
		plaques.remove(plaques[rdm])

	print(selection_de_plaques)
	operation=[]

	resoudre(selection_de_plaques,cible,operation)
	while solutions ==0 :
		resoudre(selection_de_plaques,cible,operation)
		interval+=1
		
	print(f'Il y a {solutions} solutions')
	print(f'Pour {cible} +- {interval}')
	print(f'Avec {selection_de_plaques}')
	
	"""
	cible = 355
	selection_de_plaques = [1,4,5,7,7,9]
	
	cible = 899
	selection_de_plaques = [3,5,8,9,9,25]
	
	cible = 897
	selection_de_plaques = [3,5,8,9,9,25],
	"""

if __name__=='__main__':
	main()
