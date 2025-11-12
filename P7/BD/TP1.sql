--Q1 Nom des auteurs Italiens
--SELECT nom
--FROM auteur
--WHERE pays='ITA';


--Q2 
SELECT DISTINCT personnage.nom, livre.nomauteur
FROM livre JOIN participe
ON livre.reflivre = participe.idlivre
JOIN personnage ON personnage.refpers = participe.idpers
ORDER BY personnage.nom, livre.nomauteur;

--Q3
SELECT auteur.pays
FROM livre JOIN participe
ON livre.reflivre = participe.idlivre
JOIN personnage ON personnage.refpers = participe.idpers
JOIN auteur ON auteur.nom = livre.nomauteur
WHERE personnage.metier='voyageur';

--Q4
SELECT nom
FROM auteur
WHERE nom_complet IS NOT NULL;

--Q5
