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

 media VARCHAR(6),
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