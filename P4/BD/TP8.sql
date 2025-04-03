--1
SELECT Titre
FROM Film
WHERE annee=2003 AND genre='Comédie';


--2
SELECT p.nom,p.prenom
FROM Jouer j JOIN Personne p
ON j.num_acteur=p.num_personne
JOIN Film f
ON j.num_film=f.num_film
WHERE titre='La folie des grandeurs';

--3
SELECT p.nom,p.prenom
FROM Jouer j JOIN Personne p
ON j.num_acteur=p.num_personne
JOIN Film f
ON j.num_film=f.num_film
WHERE f.num_realisateur IN (
    SELECT num_personne
    FROM Personne
    WHERE nom='Blier' AND prenom='Bertrand'
) AND f.genre='Comédie';


--4
SELECT COUNT(num_film)
FROM JOUER
WHERE num_acteur = (
    SELECT num_personne
    FROM Personne
    WHERE nom='Depardieu' and prenom='Gérard'
);


--5
SELECT j.cnt,f.num_film,f.titre
FROM Film f
JOIN(
    SELECT COUNT(num_acteur) cnt,num_film
    FROM Jouer
    GROUP BY num_film
) j
ON f.num_film=p.num_film;

--6
SELECT DISTINCT p2.nom,p2.prenom
FROM Jouer j JOIN (
    SELECT num_film
    FROM Personne p JOIN Jouer j
    ON p.num_personne=j.num_acteur
    WHERE p.nom='Depardieu' and p.prenom='Gérard'
) j_d
ON j.num_film=j_d.num_film
JOIN Personne p2
ON j.num_acteur=p2.num_personne;

--7
--NAZE
SELECT DISTINCT p.nom,p.prenom
FROM Film f JOIN Personne p
ON f.num_realisateur=p.num_acteur
WHERE f.genre='Comédie';

SELECT nom,prenom
from Personne p
join film f
on p.num_personne = f.num_personne
where genre = 'Comédie'
except
(
    select nom,prenom
    From  Personne p join film f on p.num_personne=f.num_realisateur
    where genre !='Comédie'
);

--8
SELECT num_realisateur
FROM Film
GROUP BY num_realisateur
HAVING COUNT(num_film)>=5;

--9
SELECT p.nom,p.prenom
FROM Personne p JOIN(
    SELECT num_realisateur
    FROM Film
    GROUP BY num_realisateur
    HAVING COUNT(num_film)>=5
) f
ON p.num_personne=f.num_realisateur;

SELECT p.nom,p.prenom
FROM Personne p
WHERE p.num_personne IN (
    SELECT num_realisateur
    FROM Film
    GROUP BY num_realisateur
    HAVING COUNT(num_film)>=5
);

--10 MARCHE PAS !!!!
SELECT SUM(salaire)
FROM film f JOIN jouer j
ON f.num_film=j.num_film
GROUP BY j.num_film
HAVING SUM(salaire) = MAX(
    SELECT SUM(salaire)
    FROM film f JOIN jouer j
    ON f.num_film=j.num_film
    GROUP BY j.num_film
);


--11
SELECT DISTINCT j1.num_acteur,j2.num_acteur
FROM Jouer j1 JOIN Jouer j2
ON j1.num_film = j2.num_film
WHERE j1.num_acteur!=j2.num_acteur; --evite (a,b) (b,a)


--12
SELECT DISTINCT j1.nom,j1.prenom,j2.nom,j2.prenom
FROM (
    SELECT j.num_acteur, j.num_film, p.nom,p.prenom
    FROM Jouer j JOIN Personne p
    ON j.num_acteur=p.num_personne) j1
JOIN (
    SELECT j.num_acteur, j.num_film,p.nom,p.prenom
    FROM Jouer j JOIN Personne p
    ON j.num_acteur=p.num_personne) j2
ON j1.num_film = j2.num_film;

--on peut faire plusierus jointures a la fois

--13
SELECT num_film FROM film
WHERE num_film IN ALL(
    SELECT num_film
    FROM Film f JOIN Personne p
    ON f.num_realisateur=p.num_personne
    WHERE p.nom='Tarantino' AND p.prenom='Quentin'
);

--avec not exist
