--Q1 Nom des auteurs Italiens
SELECT nom
FROM auteur
WHERE pays='ITA';


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
SELECT COUNT(reflivre)
FROM livre
GROUP BY type;

--6. Nombre de récits par pays.
SELECT COUNT(reflivre)
FROM livre JOIN auteur
ON auteur.nom = livre.nomauteur
WHERE livre.type='roman'
GROUP BY auteur.pays;


--7. Pays et nombre de romans, pour chaque pays, écrits par des auteurs du 19ème siècle.
SELECT auteur.pays, COUNT(livre.reflivre)
FROM livre JOIN auteur
ON auteur.nom = livre.nomauteur
WHERE auteur.siecle=19 AND livre.type='roman'
GROUP BY auteur.pays;

--8. Noms des auteurs qui ont écrit des récits et des romans.
SELECT DISTINCT auteur.nom
FROM livre JOIN auteur
ON auteur.nom = livre.nomauteur
WHERE livre.type='récit' and auteur.nom IN (
    SELECT auteur.nom
    FROM livre JOIN auteur
    ON auteur.nom = livre.nomauteur
    WHERE livre.type='roman'
);

--9. Noms des auteurs ayant écrit au moins trois livres.
SELECT DISTINCT auteur.nom
FROM livre JOIN auteur
ON auteur.nom = livre.nomauteur
GROUP BY (auteur.nom)
HAVING COUNT (livre.reflivre) >=3;


--10. Noms des auteurs ayant écrit le plus de romans.
SELECT DISTINCT auteur.nom 
FROM livre JOIN auteur
ON auteur.nom = livre.nomauteur
GROUP BY (auteur.nom)
HAVING COUNT (livre.reflivre) >= ALL(
    SELECT COUNT (livre.reflivre)
    FROM livre JOIN auteur
    ON auteur.nom = livre.nomauteur
    GROUP BY (auteur.nom)
);

--11. Titres des livres ayant le plus de personnages cités.
SELECT livre.titre
FROM livre JOIN participe
ON participe.idlivre = livre.reflivre
GROUP BY (livre.reflivre)
HAVING COUNT(participe.idpers) >= ALL(
    SELECT COUNT(participe.idpers)
    FROM livre JOIN participe
    ON participe.idlivre = livre.reflivre
    GROUP BY (livre.reflivre)
);


-- 12. Noms des auteurs qui ont écrit dans tous les types.
SELECT a.nom
FROM auteur a
JOIN livre l ON l.nomauteur = a.nom
GROUP BY a.nom
HAVING COUNT(DISTINCT l.type) = (
    SELECT COUNT(DISTINCT type)
    FROM livre
);


-- 13. Noms des auteurs avec les titres de leurs livres (même s'ils n'ont pas écrit de livres).
SELECT nom, titre
FROM auteur LEFT OUTER JOIN livre
ON auteur.nom = livre.nomauteur;

-- 14. Couples des titres de livres écrits par le même auteur.
SELECT l1.titre, l2.titre
FROM livre l1
JOIN livre l2 ON l1.nomauteur = l2.nomauteur
WHERE l1.reflivre < l2.reflivre; --evite les couples A-A, A-B B-A

-- 15. Couples des titres de livres dans lesquels intervient le même personnage.
SELECT l1.titre, l2.titre
FROM participe p1
JOIN participe p2 ON p1.idpers = p2.idpers
JOIN livre l1 ON l1.reflivre = p1.idlivre
JOIN livre l2 ON l2.reflivre = p2.idlivre
WHERE p1.idlivre < p2.idlivre;