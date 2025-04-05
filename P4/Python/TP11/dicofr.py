import unicodedata
import string
from itertools import permutations
 
def calculer_permutations(mot):
    # Génère toutes les permutations sous forme de tuples
    toutes_les_permutations = permutations(mot)
   
    # Transforme les tuples en chaînes
    permutations_en_chaines = [''.join(p) for p in toutes_les_permutations]
   
    return permutations_en_chaines
    
def lire_fichier(file_name : str)->str : 
        try :
            with open(file_name,'r',encoding='utf-8') as fichier:
                texte = fichier.read() #stock l'entierté du contenue de {file_name}
        except FileNotFoundError:
            print("fichier non existant")
            
        return (texte)
        
def sans_accent(mot):
    return ''.join(char for char in unicodedata.normalize('NFD', mot) if unicodedata.category(char) != 'Mn')
   

mots_avec_accent = lire_fichier('french.txt')
mots_avec_accent= mots_avec_accent.split('\n')
 
mots_sans_accent = [sans_accent(mot.strip('\n').replace("-","").replace('.','')) for mot in mots_avec_accent]
#print(mots_sans_accent)

mot_3_to_9 = list(filter(lambda x: 3<=len(x)<=9, mots_sans_accent))
#print (mot_3_to_9)

dico = {i : [] for i in range(3,10)}

'''
for mot in mot_3_to_9 :
  dico[len(mot)]+=1

for cle in dico :
  print(f'{cle} => {dico[cle]}')
'''

for mot in mot_3_to_9 :
  dico[len(mot)].append(mot)

mot = input("Entrer un mot entre 3 et 9 lettres : ")
perm_mot = calculer_permutations(mot)

print(perm_mot)

print('=============================================')
print('Mots dans le dico : ')
print('=============================================')
print('\n')

for perm in perm_mot : 
  if perm in dico[len(perm)]:
    print(perm)
