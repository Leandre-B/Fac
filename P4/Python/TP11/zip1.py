id = [0,1,2,3,4]
nom = ['Michel','Marie','André','Ange','ANGELOOO']
salaire = [10,1,0,500000,-10,42]
z_pers = zip(id,nom,salaire)
l_z_pers= list(zip(id,nom,salaire))
somme=0
for i,n,s in z_pers : 
	print(f'{n} (id={i}) gagne {s}€ de l\'heure')
	somme+=s
print(f'La moyenne de leur salaire est : {somme/len(salaire)}€ omgggg\n') 

print(f'sorted(zip(id,nom,salaire) :\n {sorted(zip(id,nom,salaire))}\n')
print(f'sorted(zip(nom,id,salaire) :\n {sorted(zip(nom,id,salaire))}\n')
print(f'sorted(zip(id,nom,salaire) key[2] :\n {sorted(zip(id,nom,salaire),key=lambda x: x[2])}\n')

print(f'Filtre salaire>0: {list(filter(lambda x: x[2]>0,l_z_pers))}\n')

#print(f'Augmentation des salaire : {list(map(lambda x: type(x)==int * 1.2,zip(id,nom,salaire)))}\n')
"""
print(z_pers) #fonctionne pas, normal
print(list(z_pers)) #fontionne pas ????
print(list(zip(id,nom,salaire))) #fontionne ?!?!?
#c'est quoi ce bazar ????


#meme chose........ (._.,)
print(sorted(z_pers))
print(sorted(zip(id,nom,salaire)))
print(sorted(list(z_pers)))
"""
