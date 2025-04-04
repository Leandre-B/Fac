--1
SELECT premannee
FROM biathlete
WHERE nom='Fourcade' AND prenom='Martin';

--2
SELECT b.nom,b.prenom
FROM biathlete b JOIN resultat r
ON b.numlicence=r.numlicence
WHERE r.place=1;

--3

SELECT b.nom,b.prenom
FROM biathlete b JOIN resultat r
ON b.numlicence=r.numlicence
--WHERE r.place!=1;
WHERe numlicence NOT IN (SELECT numlicence from resultat where place=1)

--4
SELECT b.nom,b.prenom,e.saison
FROM biathlete b JOIN resultat r
ON b.numlicence=r.numlicence
JOIN epreuve e
ON r.numepreuve=r.numepreuve
WHERE b.pays='France' AND e.saison=2021 or e.saison=2022;

--5
SELECT e.nom
FROM biathlete b JOIN resultat r
ON b.numlicence=r.numlicence
JOIN epreuve e
ON r.numepreuve=e.numepreuve
WHERE r.place=1 AND b.nom='Fourcade' AND b.prenom='Martin';

--6
SELECT nom,prenom
FROM biathlete
WHERE premannee=(
SELECT premannee
FROM biathlete
WHERE nom='Fourcade' AND prenom='Martin');


--7 PAS DE RESULTAT
SELECT e.nom
FROM biathlete b JOIN resultat r
ON b.numlicence=r.numlicence
JOIN epreuve e
ON r.numepreuve=r.numepreuve
WHERE b.pays='Japan' AND r.place=1
EXCEPT
SELECT e.nom
FROM biathlete b JOIN resultat r
ON b.numlicence=r.numlicence
JOIN epreuve e
ON r.numepreuve=r.numepreuve
WHERE b.pays='France' AND r.place=1;

--8
SELECT b.nom,b.prenom
FROM biathlete b JOIN resultat r
ON b.numlicence=r.numlicence
JOIN epreuve e
ON r.numepreuve=e.numepreuve
WHERE e.numepreuve IN (
    SELECT e.numepreuve
    FROM biathlete b JOIN resultat r
    ON b.numlicence=r.numlicence
    JOIN epreuve e
    ON r.numepreuve=e.numepreuve
    WHERE b.nom='Fourcade' AND b.prenom='Martin'
);

--9
SELECT COUNT(b.numlicence),e.lieu
FROM biathlete b JOIN resultat r
ON b.numlicence=r.numlicence
JOIN epreuve e
ON r.numepreuve=e.numepreuve
WHERE b.nom='Fourcade' AND b.prenom='Martin' AND r.place=1
GROUP BY e.lieu;

--10
SELECT b.nom,b.prenom,min(r.place)
FROM biathlete b JOIN resultat r
ON b.numlicence=r.numlicence
JOIN epreuve e
ON r.numepreuve=r.numepreuve
WHERE b.pays='France'
GROUP BY b.nom,b.prenom;

--11
SELECT b.nom,b.prenom
FROM biathlete b JOIN resultat r
ON b.numlicence=r.numlicence
JOIN epreuve e
ON r.numepreuve=r.numepreuve
WHERE r.place=1
GROUP BY b.numlicence,b.nom,b.prenom
HAVING COUNT(r.place)>=2;


--12
SELECT e.saison
FROM epreuve e JOIN resultat r ON e.numepreuve=r.numepreuve
JOIN biathlete b ON r.numlicence=b.numlicence
WHERE b.nom='Fourcade' AND b.prenom='Martin' AND r.place='1'
GROUP BY e.saison
HAVING COUNT(e.numepreuve)>
(
    SELECT COUNT(e.numepreuve)
    FROM epreuve e JOIN resultat r ON e.numepreuve=r.numepreuve
    JOIN biathlete b ON r.numlicence=b.numlicence
    WHERE b.nom='Fillon Maillet' AND b.prenom='Quentin' AND r.place='1'
    GROUP BY e.saison
);


--13
SELECT DISTINCT b1.nom, b1.prenom,b2.nom,b2.prenom
FROM (biathlete b JOIN resultat r ON b.numlicence=r.numlicence) b1
JOIN
(biathlete b JOIN resultat r ON b.numlicence=r.numlicence) b2
ON b1.numepreuve=b2.numepreuve
WHERE b1.numlicence<b2.numlicence; --pour pas avoir de doublons

--14
SELECT e.nom,COALESCE(b.nom || ' '|| b.prenom , 'non saisie')
FROM resultat r RIGHT JOIN epreuve e ON r.numepreuve=e.numepreuve
LEFT JOIN biathlete b ON r.numlicence=b.numlicence
WHERE r.place=1 or r.place IS NULL;

--15
select b.nom,b.prenom from biathlete b
where numlicence IN
(
    select numlicence from resultat r1 where r1.place=1
    group by numlicence having count(r1.numepreuve) = (select count (r2.numepreuve)
    from resultat r2 where r1.numlicence=r2.numlicence)
);
