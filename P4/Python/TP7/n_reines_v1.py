from itertools import permutations
import time
 
nbr_permutations = 0
 
# méthode de résolution
# basée sur les permutations
def resoudre(n):
  global nbr_permutations
  columns = range(n)
  #===== permutation(tab)======
  #return les permutations de tab
  #permutations(range(3)) → 012 021 102 120 201 210
  #->ensemble (set) pas de doublons
  
  #ici, toutes les combinaisons de dames possibles
  #-> 120 = 1 dames en [0][1],[1][2],[2][0]
  #-> pas de prise en lignes et colonnes
  #-> faut juste regarder les diagos
  #============================
  for board in permutations(columns):
    nbr_permutations = nbr_permutations + 1
    
    #on regarde dans quelle diago la reine appartient
    s1 = set(board[i] + i for i in columns) #haut-droite bas-gauche
    s2 = set(board[i] - i for i in columns) #haut-gauche bas-droite
    
    #si nombres d'elem dans s1 et s2 = nbr de reines -> c'est good
    #aka (4 diag uniq dans s1 et s2)
    if n == len(s1) == len(s2):
      yield board #yield -> genre un return mais c'est un compteur, stop pas la fonction
     
 
# nombre de reines
N = 7
t1 = time.time()
ns = len(list(resoudre(N)))
t2 = time.time()
print("reines=", N)
print("permutations=", nbr_permutations)
print("solutions=", ns)
print("temps de calcul=", t2-t1)

""" TEST POUR COMPRENDRE ALGO
columns=range(3)
permu=permutations(columns)
for board in permutations(columns):
    print(f'board : {board}')
    s1_list = list(board[i] + i for i in columns)
    s2_list=list(board[i] - i for i in columns)
    s1 = set(s1_list)
    s2=set(s2_list)
    print(f's1_list = {s1_list}\ns1 = {s1}')
    print(f's2_list = {s2_list}\ns2 = {s2}\n')
"""