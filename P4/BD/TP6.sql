--1)
SELECT nom,prenom
FROM musicien
WHERE datnaiss<1930;

--2)
SELECT nom,prenom
FROM album JOIN joue
ON album.refAlbum=joue.refAlbum
WHERE titre='Electric Ladyland';

--3)
SELECT DISTINCT label.ville
FROM album JOIN joue
    ON album.refAlbum=joue.refAlbum
JOIN label
    ON album.nomLabel = label.nomLabel
WHERE joue.nom='Coltrane' AND joue.prenom='John';

--4)
SELECT album.titre
FROM album
WHERE annee=
(
    SELECT annee
    FROM album
    WHERE titre='Are You Experienced'
);

--5)
SELECT MAX(duree)
FROM album;

--6)
SELECT ville,COUNT(nomLabel)
FROM label
GROUP BY ville;

--7)
SELECT COUNT(album.refAlbum)
FROM album JOIN joue
    ON album.refAlbum=joue.refAlbum
WHERE joue.nom='Coltrane' AND joue.prenom='John'
GROUP BY nom,prenom;

--8)
SELECT nom,prenom
FROM joue
GROUP BY nom,prenom
HAVING COUNT(refAlbum)>
(
    SELECT COUNT(refAlbum)
    FROM joue
    WHERE nom='Coltrane' AND prenom='John'
);

--9)
SELECT album.titre
FROM album
JOIN joue ON album.refAlbum=joue.refAlbum
WHERE nom='Hendrix'
AND prenom='Jimi'
AND duree=
(
    SELECT MIN(duree) FROM album
    JOIN joue ON album.refAlbum=joue.refAlbum
    WHERE nom='Hendrix' AND prenom='Jimi'
);

--10)
SELECT j1.nom,j1.prenom,j2.nom,j2.prenom
FROM joue j1 JOIN joue j2
ON j1.refAlbum=j2.refAlbum;

--11)
SELECT nom, prenom
FROM
(
    (
        SELECT refAlbum
        FROM joue WHERE nom='Monk' AND prenom='Thelonious'
    )
UNION
    (
        SELECT refAlbum
        FROM joue
        WHERE nom='Davis' AND prenom='Miles'
    )
) t
JOIN joue
ON t.refAlbum=joue.refAlbum;

--12)
SELECT j.nom,j.prenom
FROM joue j JOIN
(
    SELECT refAlbum
    FROM joue
    WHERE nom='Hendrix' AND prenom='Jimi'
) jm
ON j.refAlbum=jm.refAlbum;

