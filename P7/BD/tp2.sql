CREATE TABLE societe(
 CodeSoc INTEGER,
 Nom CHAR(15) NOT NULL,
 Adresse VARCHAR(50),
 PRIMARY KEY (CodeSoc)
);


CREATE TABLE campagne(
 
 CodeCamp CHAR(6),
 Titre VARCHAR(50),
 CodeSoc INTEGER,
 Produit VARCHAR(20),
 Cible CHAR(4),

 FOREIGN KEY(CodeSoc) REFERENCES societe (CodeSoc),
 PRIMARY KEY (CodeCamp)
);

ALTER TABLE campagne
ADD CONSTRAINT val_cible
CHECK (cible IN ('ENF', 'ADO', 'MM50', 'TOUS'));

CREATE TABLE spot(

 CodeSpot CHAR(3),
 Libelle VARCHAR(30),
 Duree INTEGER,
 CodeCamp CHAR(6) NOT NULL,

 FOREIGN KEY(CodeCamp) REFERENCES campagne (CodeCamp),
 PRIMARY KEY (CodeSpot)

);

CREATE TABLE tarif(

 media VARCHAR(10),
 moment VARCHAR(20),
 prix INTEGER,

 PRIMARY KEY(media, moment)
);

ALTER TABLE tarif
ADD CONSTRAINT val_media
CHECK (media IN ('TF1', 'FRANCE2', 'FRANCE3', 'CANAL+', 'M6', 'C8')),
ADD CONSTRAINT val_moment
CHECK ( moment IN ('JOUR', 'DEBSOIR', 'SOIR', 'FINS'));

CREATE TABLE programmation(
 CodeSpot CHAR(3),
 media VARCHAR(10),
 moment VARCHAR(20),
 datep DATE,

 FOREIGN KEY(CodeSpot) REFERENCES spot (CodeSpot),
 FOREIGN KEY(media, moment) REFERENCES tarif (media, moment),
 PRIMARY KEY (CodeSpot, media, moment, datep)
);

INSERT INTO societe VALUES
 (101, 'Nescafé', '523 rue des grains Paris 13'),
 (102, 'CIC', '5 rue du brigand Paris 15'),
 (120, 'Peaugot', '36 avenue de la routourne Angers')
;

INSERT INTO campagne VALUES
 ('NE025','Nespresso-Clooney',101,'Café','MM50'),
 ('P208P','208-Pinocchio' ,120,'Voiture','TOUS'),
 ('BA75','Le monde bouge',102, 'Banque','MM50')
;

INSERT INTO spot VALUES
 ('NS1','Rencontre au bar',135,'NE025'),
 ('NS2','Soirée',115,'NE025'),
 ('P12','Mobile',60,'BA75'),
 ('P13','Premier emploir',75,'BA75'),
 ('P14','Séjour étranger',45,'BA75')
;

INSERT INTO tarif VALUES
 ('TF1', 'SOIR' ,500),
 ('TF1' ,'DEBSOIR' ,400),
 ('FRANCE2', 'JOUR' ,50),
 ('FRANCE3' ,'JOUR' ,50),
 ('FRANCE3' ,'DEBSOIR', 200)
;

INSERT INTO programmation VALUES
 ('NS1', 'TF1' ,'SOIR', to_date('18/02/25', 'DD/MM/YY')),
 ('NS1', 'FRANCE3' ,'JOUR', to_date('20/02/25', 'DD/MM/YY')),
 ('NS2', 'TF1' ,'DEBSOIR', to_date('20/02/25', 'DD/MM/YY')),
 ('P12', 'TF1' ,'DEBSOIR', to_date('19/02/25', 'DD/MM/YY')),
 ('P13', 'TF1' ,'DEBSOIR', to_date('20/02/25', 'DD/MM/YY')),
 ('P13', 'FRANCE3' ,'DEBSOIR', to_date('20/02/25', 'DD/MM/YY'))
;


--Q2
-- \dt, select* from ........


--Q3
ALTER TABLE tarif
DROP CONSTRAINT val_media,
ADD CONSTRAINT val_media
CHECK (media IN ('TF1', 'FRANCE2', 'FRANCE3', 'CANAL+', 'M6', 'Novo 19'));

INSERT INTO tarif VALUES
 ('Novo 19', 'FINS' ,50),
 ('Novo 19' ,'SOIR' ,80);

 --Q4
 UPDATE spot
 SET Libelle='Recontre en soirée'
 WHERE CodeSpot='NS2';

 --Q5
 INSERT INTO societe VALUES
 (100,'Adidas');

 --Q6
INSERT INTO programmation VALUES
('NS3','TF1', 'SOIR', to_date('18/02/25', 'DD/MM/YY'));
--erreur car clé 'NS3' n'existe pas comme clé dans la relation spot

--Q7
INSERT INTO spot VALUES
('NS3','A la maison',NULL,(SELECT CodeCamp FROM campagne WHERE Titre='Nespresso-Clooney'));

--Q8
CREATE TABLE SPOT2
AS(
    SELECT Libelle, Duree
    FROM spot
);

--Q9
CREATE TABLE client(
    numc CHAR(6),
    nomc VARCHAR(30),
    anneenaissc NUMERIC(4),
    villec VARCHAR(40),

    PRIMARY KEY(numc)
);


INSERT INTO client VALUES
('CLI001', 'Jean', '1975', '75006 Paris'),
('CLI002', 'Paul', '1978', '75003 Paris'),
('CLI003', 'Vincent', '1984', '94200 Evry'),
('CLI004', 'Pierre', '1970', '92400 Courbevoie'),
('CLI005', 'Daniel', '1963', '44112 Nantes');


CREATE TABLE employe(
    numc CHAR(6),
    CodeSoc INTEGER,

    PRIMARY KEY(numc, CodeSoc),
    FOREIGN KEY (numc) REFERENCES client (numc),
    FOREIGN KEY (CodeSoc) REFERENCES societe (CodeSoc)
);


INSERT INTO employe VALUES
((SELECT numc FROM client WHERE nomc='Daniel'),
(SELECT CodeSoc FROM societe WHERE nom='Nescafé'));



--Q10
--1. Code de tous les spots passant sur TF1 le 20 février 2025.
CREATE VIEW Q1
AS(
    SELECT CodeSpot
    FROM programmation
    WHERE media='TF1' and datep='20/02/2025'
);

--2. Libellé et durée de tous les spots de la campagne « Nespresso-Clooney ».
CREATE VIEW Q2
AS(
    SELECT Libelle, duree
    FROM spot
    WHERE CodeCamp IN(
        SELECT CodeCamp
        FROM campagne
        WHERE titre='Nespresso-Clooney'
    )
);

--3. Code et libellé (classés par ordre alphabétique) 
--des spots visant les ménagères de moins de 50 ans.
CREATE VIEW Q3
AS(
    SELECT s.CodeSpot, s.libelle
    FROM spot s JOIN campagne c
    ON s.CodeCamp=c.CodeCamp
    WHERE c.cible='MM50'
    ORDER BY s.CodeSpot ASC
);

--4. Code et titre des campagnes dont au moins un spot passe en début de soirée.
CREATE VIEW Q4
AS(
    SELECT DISTINCT c.CodeCamp, c.titre
    FROM spot s JOIN campagne c
    ON s.CodeCamp=c.CodeCamp
    JOIN programmation p
    ON p.CodeSpot = s.CodeSpot
    WHERE p.moment='DEBSOIR'
);

--5. Code et titre des campagnes dont tous les spots passent en début de soirée.
CREATE VIEW Q5
AS(
    SELECT DISTINCT c.CodeCamp, c.titre
    FROM spot s JOIN campagne c
    ON s.CodeCamp=c.CodeCamp
    JOIN programmation p
    ON p.CodeSpot = s.CodeSpot
    WHERE p.moment='DEBSOIR' and c.CodeCamp NOT IN(
        SELECT DISTINCT c.CodeCamp
        FROM spot s JOIN campagne c
        ON s.CodeCamp=c.CodeCamp
        JOIN programmation p
        ON p.CodeSpot = s.CodeSpot
        WHERE p.moment!='DEBSOIR'
    )
);

--6. Titre des campagnes dont au moins un spot est diffusé le 20 février 2025 
--sur TF1 sans être diffusé sur une autre chaîne le même jour.
CREATE VIEW Q6
AS(
    SELECT DISTINCT c.titre
    FROM spot s JOIN campagne c
    ON s.CodeCamp=c.CodeCamp
    JOIN programmation p
    ON p.CodeSpot = s.CodeSpot
    WHERE p.datep='20/02/25'
);



--7. Code, libellé et coût des spots qui ont été facturés plus de 40 000 euros.
CREATE VIEW Q7
AS(
    SELECT DISTINCT s.CodeSpot, s.libelle,t.prix
    FROM tarif t JOIN programmation p
    ON t.media = p.media AND t.moment = p.moment
    JOIN spot s ON s.CodeSpot = p.CodeSpot
    WHERE t.prix>40;
);

--8. Moyenne des prix pratiqués par chaque média.
CREATE VIEW Q8
AS(
    SELECT media, AVG(Prix)
    FROM tarif
    GROUP BY media
);

--9. Libellés/(titres?) des campagnes qui sont passées sur toutes les chaînes
CREATE VIEW Q9
AS(
    SELECT c.titre
    FROM spot s JOIN campagne c
    ON s.CodeCamp=c.CodeCamp
    JOIN programmation p
    ON p.CodeSpot = s.CodeSpot
    GROUP BY c.titre
    HAVING COUNT(DISTINCT p.media) = (
        SELECT COUNT(DISTINCT media)
        FROM programmation
    )
);