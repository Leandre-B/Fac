import sympy as sp
import sys
import re
# Permet l'affichage stylisé avec Unicode
sp.init_printing(use_unicode=True)
 
def trouver_les_solutions(expression,intervalles):
	x,y,z = sp.symbols('x y z')
	
	f = expression
	solutions=[]
	sol=0
	
	for i in range(0,int(int(intervalles[0])*'9')+1):
		for j in range(0,int(int(intervalles[2])*'9')+1):
			for k in range(0,int(int(intervalles[4])*'9')+1):
				if f.subs([(x, i), (y, j), (z, k)])==0 : 
					solutions.append([i,j,k])
					sol+=1
	#print(f'Il y\'a : {sol} solutions')
	return solutions
	

expression=str(sys.argv[1])
intervalles=str(sys.argv[2])
filtres=str(sys.argv[3])

expression = sp.sympify(expression.replace("=", "-(") + ")")
filtres = filtres.split('|')

print(f'Expression : {expression}')
print(f'Intervalles {intervalles}')
print(f'Filtres {filtres}\n')

solutions = trouver_les_solutions(expression,intervalles)
solution_filtre=[]

#====== Filtrage ========
for sol in solutions :
	is_match = True
	for i in range(len(filtres)) :
		is_match=re.search(filtres[i],str(sol[i])) and is_match
	if is_match :
		solution_filtre.append(sol)
		
print(f'Après filtrage : {len(solution_filtre)} solutions :\n')
for sol in solution_filtre : 
	print(f'x={sol[0]}, y={sol[1]}, z={sol[2]}') 
