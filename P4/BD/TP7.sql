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
