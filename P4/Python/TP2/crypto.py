import string


def cesar(chn :str,n:int)->str :
    chn=chn.upper()
    code=''
    for char in chn:
        if 'A'<= char<= 'Z' :
            new_char = chr(((ord(char)-ord('A') +n)%26) +ord('A'))
        else : 
            new_char=char
        code+=new_char
    return code

def vigener(chn:str, cle:str,reverse:bool)->str:
    code=''
    chn=chn.upper()
    n=0
    for char in chn :
        if 'A'<= char<= 'Z' :
            if reverse :
                new_char = chr(((ord(char)-ord('A')-((ord(cle[n]))-ord('A')))%26) +ord('A'))
            else :
                new_char = chr(((ord(char)-ord('A')+((ord(cle[n]))-ord('A')))%26) +ord('A'))
            n+=1
        else : 
            new_char=char
        code+=new_char

        if(n==len(cle)):
            n=0
    
    return code

def lire_fichier(file_name:str) -> str:
    texte=''
    try:
        with open(file_name,'r',encoding='utf-8') as file :
            texte=file.read()
    except FileNotFoundError:
        print(f'Fichier {file_name} non trouve')
    
    return texte



def main():
    #cesar
    #'KXWWN JWWNN' - > BONNE ANNEE'

    #vigener
    #'KZ RMEKH HGI HCVL YPS CXXKHR YMNZR TTRSYXI DCHVPG R\'BK' key = 'CONTE'
    #   ->'IL ETAIT UNE FOIS UNE PETITE FILLE APPELEE BOUCLE D'OR'

    chn='KZ RMEKH HGI HCVL YPS CXXKHR YMNZR TTRSYXI DCHVPG R\'BK'
    reverse=True
    for i in [ "PYRAMYDE", "GNOU", "LINUX", "CONTE", "CRYPTO", "ZIDANE"] :
        print(f'cle {i} : {vigener(chn,i,reverse)}')


    texte=lire_fichier('a_encoder_file.txt')
    print(f'\nTexte non chiffre : \n {texte} \n')
 

    print(f'Texte chiffre : \n {vigener(texte,'VILLAGE',False)}')

#==========APPEL DU MAIN====================
if __name__ == '__main__':
    main()   
