import string


def longueur_mot(phrase) : 
	mots = phrase.split()
	return (list(map(lambda x: len(x),mots))) 


def filtre(l,min):
	mots = l.split()
	return (list(filter(lambda x: len(x)>min,mots)))

def remplace_par_lg (l):
	mots = l.split()
	return " ".join(map(lambda x: str(len(x)),mots))


def main() : 
	phrase = 'Il était une fois une petite fille de village, la plus jolie qu\'on eût su voir ; sa mère en était folle, et sa mère-grand plus folle encore. Cette bonne femme lui fit faire un petit chaperon rouge, qui lui seyait si bien que partout on l\'appelait le petit Chaperon rouge.'
	print (phrase)
	
	l_longueur_mot = longueur_mot(phrase)
	print(l_longueur_mot)

	l_min_longueur_mot = filtre(phrase,5)
	print(l_min_longueur_mot)

	print(remplace_par_lg(phrase))
	

if __name__=='__main__' : 
	main()
