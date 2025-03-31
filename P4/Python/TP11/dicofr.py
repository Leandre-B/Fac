import unicodedata
import string

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
print (mot_3_to_9)

