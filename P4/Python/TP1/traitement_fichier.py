#=========IMPORT=================
import string

#==========SOUS PROGRAMME===========

def lire_fichier(file_name : str)->str : 
        try :
            with open(file_name,'r',encoding='utf-8') as fichier:
                texte = fichier.read() #stock l'entierté du contenue de {file_name}
                
        except FileNotFoundError:
            print("fichier non existant")
            
        return texte
                

#==========PROGRAMME PRINCIPAL===============
def main():
    file_name='text.txt'
    lire_fichier(file_name)
    fichier =lire_fichier(file_name) 
    print(f'{fichier}')
    
    lignes = fichier.split('\n')
    print(f'{lignes}')
    
    lignes_sans_espaces =[chaines.strip(' ') for chaines in lignes]
    print(f'{lignes_sans_espaces}')
    
    print(f'======AFFFICHAGE INFORMATIF=========')
    for i in range(0, len(lignes_sans_espaces)):
        #sinon enumerate a la place de range mais renvoi un tuple, le 'i+1:03d' fonctionne donc pas :(
        print(f'Ligne {i+1:03d} : {len(lignes_sans_espaces[i])} {lignes_sans_espaces[i]}')


    lignes_sans_ponctuation=["".join(char for char in lign if char not in string.punctuation) for lign in lignes_sans_espaces]
    
    print(f'{lignes_sans_ponctuation}')

    """
    for i in range(len(lignes_sans_ponctuation)):
        lignes_sans_ponctuation[i]=''.join(
             char.lower() if char.isupper() else char.upper() for char in lignes_sans_ponctuation[i]
        )
    
    print(f'{lignes_sans_ponctuation}')
    """

    
    dico={}
    for ligne in lignes_sans_ponctuation:
        mots = ligne.split()
        for mot in mots:
            mot = mot.lower()

            if mot in dico:
                dico[mot] +=1
            else:
                dico[mot]=1

    print(dico)

    list_occ_dico=dico.values()
    set_occ_dico = set(list_occ_dico)
    list_occ_dico=list(set_occ_dico)
    list_occ_dico.sort(reverse=True)
    print(list_occ_dico)

    for occ in list_occ_dico :
        for mot in dico:
            if dico[mot]==occ:
                print(f'{mot.ljust(20)} {occ}')



    



       
#==========APPEL DU MAIN====================
if __name__ == '__main__':
    main()