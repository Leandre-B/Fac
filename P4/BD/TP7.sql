-- ====1====
SELECT nom,prenom,qualif,salaire
FROM personnels
WHERE salaire > (SELECT salaire
FROM personnels
WHERE prenom='Claude' AND nom='DETANTE');

--====2====
SELECT nom,prenom,sx,datnais,qualif
FROM personnels
WHERE qualif= (SELECT qualif
FROM personnels
WHERE prenom='Claude' AND nom='DETANTE');

--====3====
SELECT nom,prenom,qualif,datnais
FROM personnels
WHERE datnais<ALL (SELECT datnais
FROM personnels
WHERE qualif='CHEF INFIRMIERE' AND sx='2');

--====4====
SELECT p.nom,p.prenom,p.qualif
FROM conges
JOIN
(
    SELECT *
    FROM personnels
    WHERE qualif='AIDE SOIGNANTE' AND sx='2'
) p
ON conges.codpers=p.codpers;

--====5=====
SELECT nom,prenom
FROM personnels
WHERE qualif='INTERNE'
AND
codserv NOT IN
(
    select codserv
    FROM personnels
    WHERE qualif='CHEF DE CLINIQUE'
);

--====6====
SELECT p.nom,p.prenom,p.qualif
FROM personnels p
WHERE codpers NOT IN
(
    SELECT c.codpers
    FROM consultations c JOIN patients pt
    ON c.codpat=pt.codpat
    WHERE pt.prenom='David' and pt.nom='MARQUET'
)
AND p.codserv IN
(
    SELECT codserv
    FROM services
    WHERE nom='CARDIOLOGIE'
);


--====7====
SELECT p.nom,p.prenom,p.qualif
FROM personnels p
WHERE p.codsup IN
(
    SELECT codsup
    FROM personnels
    WHERE prenom='Corinne' and nom='MARTIN'
)
AND p.codserv IN
(
    SELECT codserv
    FROM personnels
    WHERE prenom='Corinne' and nom='MARTIN'
);

--====8====
--somme salaire, moyenne heures supp
SELECT SUM(salaire),AVG(hsupp)
FROM personnels
WHERE codserv IN (
    SELECT codserv
    FROM services
    WHERE nom='CARDIOLOGIE'
);

--====9====
SELECT nom,prenom,qualif,salaire
FROM personnels
WHERE salaire IN
(
    SELECT MAX(salaire)
    FROM personnels
);

--====10====
SELECT ROUND(AVG(salaire),2),qualif
FROM personnels
GROUP BY qualif
ORDER BY AVG(salaire);

--====11====
SELECT ROUND(AVG(salaire),2),qualif
FROM personnels
GROUP BY qualif
HAVING AVG(salaire)>10000;

--====12====
Moyennes pour chaque service des salaires et des vacations des assistants, des internes et des docteurs
(nom du service, profession, moyenne des salaires de cette profession dans ce service, moyenne des
traitements)

SELECT s.nom,t.qualif,t.avg_s,t.avg_h
FROM (SELECT qualif,AVG(salaire) avg_s,AVG(hsupp) avg_h,codserv
FROM personnels
GROUP BY codserv,qualif) t JOIN services s
ON t.codserv=s.codserv;

