CREATE TABLE CLUB (
    NClub VARCHAR(50),
    Region VARCHAR(100),

    PRIMARY KEY (NClub)
);

CREATE SEQUENCE num_nag_sqc START 101;
CREATE TABLE Nageur (
    NumeroNag INTEGER,
    NomNag VARCHAR(50),
    PrenomNag VARCHAR(50),
    AnneedeNaissance INTEGER,
    Sexe CHAR(1),
    Nomclub VARCHAR(50),

    CONSTRAINT sexe_value CHECK (Sexe == 'M' OR Sexe == 'F'),
    PRIMARY KEY (NumeroNag),
    FOREIGN KEY (Nomclub) REFERENCES CLUB(NClub)
);


CREATE SEQUENCE NumeroEp_sqc;
CREATE TABLE CATEGORIE_EPREUVE(
    NumeroEp INTEGER,
    TypeEp VARCHAR(50) NOT NULL,
    Niveau VARCHAR(50) NOT NULL,

    CONSTRAINT type_value CHECK (
        TypeEp = 'Parcours a sec' OR 
        TypeEp = 'Propulsion technique' OR
        TypeEp = 'Technique'),
    CONSTRAINT Niveau_val CHECK (
        Niveau = 'Synchro Decouverte' OR
        Niveau = 'Synchro Argent' OR 
        Niveau = 'Synchro Or'
    )
    PRIMARY KEY (NumeroEp),
);

CREATE SEQUENCE numeroOff_sqc;
CREATE TABLE OFFICIEL (
    NumeroOff INTEGER,
    NomOff VARCHAR(50),
    PrenomOff VARCHAR(50),
    Degre CHAR(1) DEFAULT('D'),
    Nomclub VARCHAR(50),

    CONSTRAINT degre_value CHECK (
        Degre = 'A' OR
        Degre = 'B' OR
        Degre = 'C' OR
        Degre = 'D'
    ),

    PRIMARY KEY(NumeroOff),
    FOREIGN KEY (Nomclub) REFERENCES CLUB(NClub),
);

CREATE TABLE RESULTATS (
    NumeroNag INTEGER,
    NumeroEp INTEGER,
    Annee INTEGER,
    NumeroOff INTEGER,
    Note FLOAT,

    CONSTRAINT note_val CHECK (
        Note >= 0 AND Note <= 10
    ),

    PRIMARY KEY (NumeroNag, NumeroEp, Annee, NumeroOff),
    FOREIGN KEY (NumeroNag) REFERENCES Nageur(NumeroNag),
    FOREIGN KEY (NumeroEp) REFERENCES CATEGORIE_EPREUVE(NumeroEp),
    FOREIGN KEY (NumeroOff) REFERENCES OFFICIEL(NumeroOff)
);

-- 2
INSERT INTO CLUB VALUES
    ('Angers Nat Synchro', 'Pays de la Loire');


-- 3

INSERT INTO NAGEUR VALUES
    (nextval(num_nag_sqc), 'ROBERT', 'Léna', 2006, 'F', 'Angers Nat Synchro'),
    (nextval(num_nag_sqc), 'LECOURT', 'Clément', 2008, 'M', 'Angers Nat Synchro');

-- 4

INSERT INTO NAGEUR VALUES
    (nextval('num_nag_sqc'), 'CHAFFES', 'Lila', 2006, 'F', 'Angers Nat Synchro');

INSERT INTO CLUB VALUES
    ('Leo Lagrange Nantes', 'Pays de la Loire');

INSERT INTO OFFICIEL(NumeroOff, NomOff, PrenomOff, Nomclub) VALUES
    (nextval('numeroOff_sqc'), 'BOZEC', 'Rachel', 'Leo Lagrange Nantes');

INSERT INTO CATEGORIE_EPREUVE VALUES
    (nextval('NumeroEp_sqc'), 'Propulsion technique', 'Synchro Or');

INSERT INTO RESULTATS VALUES 
    (
        (SELECT NumeroNag FROM NAGEUR WHERE NomNag='CHAFFES' AND PrenomNag='Lila'), 
        (SELECT NumeroEp FROM CATEGORIE_EPREUVE WHERE TypeEp='Propulsion technique' AND Niveau='Synchro Or'),
        2023,
        (SELECT NumeroOff FROM OFFICIEL WHERE NomOff='BOZEC' AND PrenomOff='Rachel'),
        7.8
    )
;

-- 5
UPDATE OFFICIEL
SET Degre = 'A'
WHERE NomOff = 'BOZEC' AND PrenomOff = 'Rachel';

-- 6
ALTER TABLE CATEGORIE_EPREUVE
DROP CONSTRAINT Niveau_val;

ALTER TABLE CATEGORIE_EPREUVE
ADD CONSTRAINT Niveau_val CHECK (
        Niveau = 'Synchro Decouverte' OR
        Niveau = 'Synchro Argent' OR 
        Niveau = 'Synchro Or' OR
        Niveau = 'Enfant'
);

-- Si cascade facile.... :(((
DELETE FROM RESULTATS WHERE NumeroNag = (
    SELECT NumeroNag FROM Nageur WHERE NomNag='CHAFFES' AND PrenomNag='Lila'
);
DELETE FROM Nageur WHERE NomNag='CHAFFES' AND PrenomNag='Lila';


-- 7
DROP TABLE CLUB CASCADE;




-- PART 2 --
--1. Noms et prénoms des nageuses d’Angers Nat Synchro.
SELECT nomnag, prenomnag
FROM NAGEUR
WHERE Nomclub='ANGERS NAT SYNCHRO';


--2. Noms et prénoms des nageurs de la région des Pays de la Loire.
SELECT nomnag, prenomnag
FROM NAGEUR n join club c ON n.nomclub = c.nclub
WHERE c.region='PAYS DE LA LOIRE';


--3. Liste triée par note des nageurs ayant participé à l’épreuve Parcours à sec en Synchro Argent en
--2021 (noms et prénoms des nageurs et nom de leur club).

SELECT nomnag, prenomnag, nomclub
FROM RESULTAT r JOIN CATEGORIE_EPREUVE c ON r.NumeroEp=c.NumeroEp
JOIN NAGEUR n ON r.NumeroNag=n.NumeroNag
WHERE c.type ='Parcours à sec' AND c.niveau='Synchro Argent'
ORDER BY note ASC;

--4. Noms et prénoms des officiels qui ont jugé des épreuves de Synchro Argent.
SELECT DISTINCT NomOff, PrenomOff
FROM OFFICIEL o JOIN RESULTAT r ON o.NumeroOff=r.NumeroOff
JOIN CATEGORIE_EPREUVE c ON r.NumeroEp=c.NumeroEp
WHERE niveau='Synchro Argent';

--5. Noms et prénoms des officiels qui ont jugé uniquement des épreuves de Synchro Argent.
-- PAS SUR A REVOIR !!!!!!!!
SELECT DISTINCT NomOff, PrenomOff
FROM OFFICIEL o JOIN RESULTAT r ON o.NumeroOff=r.NumeroOff
JOIN CATEGORIE_EPREUVE c ON r.NumeroEp=c.NumeroEp
WHERE niveau='Synchro Argent' AND o.NumeroOff NOT IN (
    SELECT DISTINCT o.NumeroOff
    FROM OFFICIEL o JOIN RESULTAT r ON o.NumeroOff=r.NumeroOff
    JOIN CATEGORIE_EPREUVE c ON r.NumeroEp=c.NumeroEp
    WHERE niveau!='Synchro Argent'
    )
;
-- PAS SUR A REVOIR !!!!!!!!
-- PAS SUR A REVOIR !!!!!!!!
-- PAS SUR A REVOIR !!!!!!!!
-- PAS SUR A REVOIR !!!!!!!!
-- PAS SUR A REVOIR !!!!!!!!




--6. Nombre des officiels degré «A» de la région Centre Val de Loire.
SELECT COUNT(NomOff)
FROM OFFICIEL
GROUP BY degre
HAVING degre='A';

--7. Moyenne de chaque nageur pour chaque épreuve (numéro du nageur, numéro de l’épreuve et
--moyenne associée).
SELECT numeronag, numeroep, AVG(note) as moyenne
FROM RESULTAT
GROUP BY numeronag, numeroep;
SELECT nomnag, prenomnag
FROM NAGEUR n JOIN RESULTAT r ON n.numeronag=r.numeronag;


--8. Moyenne de chaque nageur pour chaque épreuve (nom et prénom du nageur, type et niveau de
--l’épreuve et moyenne associée).
SELECT nomnag, prenomnag, type, niveau, AVG(note)
FROM NAGEUR n JOIN RESULTAT r ON n.numeronag=r.numeronag
JOIN CATEGORIE_EPREUVE c ON r.numeroep=c.numeroep
GROUP BY nomnag, prenomnag, type, niveau;

--9. Moyenne de chaque nageur pour chaque épreuve lorsque l’épreuve a été validée (moyenne >=5)
--(nom et prénom du nageur, type et niveau de l’épreuve et moyenne associée).
SELECT nomnag, prenomnag, type, niveau, AVG(note) as moyenne
FROM NAGEUR n JOIN RESULTAT r ON n.numeronag=r.numeronag
JOIN CATEGORIE_EPREUVE c ON r.numeroep=c.numeroep
GROUP BY nomnag, prenomnag, type, niveau, annee
HAVING AVG(note) >=5;

--10. Nombre de nageurs du club BN Strasbourg qui ont validé toutes les épreuves qu’ils ont passées.
SELECT nomnag, prenomnag, type, niveau, AVG(note) as moyenne
FROM NAGEUR n JOIN RESULTAT r ON n.numeronag=r.numeronag
JOIN CATEGORIE_EPREUVE c ON r.numeroep=c.numeroep
WHERE n.nomclub = 'BN STRASBOURG'
GROUP BY nomnag, prenomnag, type, niveau, annee
HAVING AVG(note) >=5;

--11. Couples des noms et prénoms des nageurs ayant participé à une même épreuve la même année.
SELECT DISTINCT n1.nomnag, n1.prenomnag, T2.nomnag, T2.prenomnag
FROM NAGEUR n1 JOIN RESULTAT r ON n1.numeronag=r.numeronag
JOIN (
    SELECT nomnag, prenomnag, annee, numeroep
    FROM NAGEUR n JOIN RESULTAT r ON n.numeronag=r.numeronag
) T2 ON T2.annee=r.annee AND T2.numeroep=r.numeroep
WHERE n1.nomnag < T2.nomnag;

--12. Noms des clubs avec noms et prénoms de leurs nageurs (liste complète des clubs incluant les clubs
--qui n’ont pas de nageurs).