liste_1 = [4, 7, 9, 1]
liste_2 = ["rouge", "vert", "bleu", "jaune"]
 
# zip() donne un itérateur et n'est donc pas
# affichable, il faut le transformer en liste
# afin de l'afficher
combiner = (zip(liste_1, liste_2))
print(combiner)
print(list(combiner))

# parcours des deux listes
for x,y in zip(liste_1,liste_2):
    print(f"{x} -> {y}")
