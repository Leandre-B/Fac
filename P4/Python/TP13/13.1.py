
def est_un_pangramme(s:str) -> bool :
	alphabet = 'a,b,c,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z'
	alphabet = alphabet.split(',')	
	
	s=s.lower()
	
	for lettre in s : 
		if lettre in alphabet :
			alphabet.remove(lettre)

	if len(alphabet) == 0 :
		return True
	else: 
		return False
	




def main() : 
	s="Portez, ce vieux whisky, au juge blond qui fume."
	if est_un_pangramme(s) :
		print(f'{s} est un pangramme')
	else : 
		print(f'{s} n\'est pas un pangramme')


if __name__=='__main__' : 
	main()
