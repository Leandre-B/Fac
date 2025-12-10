CREATE SEQUENCE sqc_livre;
CREATE SEQUENCE sqc_ref_pers START 101;

CREATE TABLE auteur(
    nom VARCHAR(30),
    nom_complet VARCHAR(70),
    pays CHAR(3),
    siecle INTEGER,

    PRIMARY KEY (nom)
);


CREATE TABLE livre(
    reference INTEGER,
    titre VARCHAR(100),
    date_parution INTEGER,
    type_l VARCHAR(10) DEFAULT 'autre',
    nom VARCHAR(30),

    PRIMARY KEY(reference),
    FOREIGN KEY (nom) REFERENCES auteur(nom)
        ON DELETE CASCADE ON UPDATE CASCADE
);

ALTER TABLE livre
ADD CONSTRAINT val_type_l
CHECK (type_l IN ('roman','theatre', 'recit',  'autre'));


CREATE TABLE personnage(
    reference INTEGER,
    nom VARCHAR(50),
    metier VARCHAR(50),
    sexe CHAR(1),

    PRIMARY KEY (reference)
);

ALTER TABLE personnage
ADD CONSTRAINT val_sexe
CHECK (sexe IN ('F','M'));

CREATE TABLE participe(
    id_perso INTEGER,
    id_livre INTEGER,
    citation INTEGER,

    PRIMARY KEY (id_livre, id_perso),
    FOREIGN KEY (id_livre) REFERENCES livre(reference)
        ON DELETE CASCADE ON UPDATE CASCADE,
    FOREIGN KEY (id_perso) REFERENCES personnage(reference)
        ON DELETE CASCADE ON UPDATE CASCADE
);



INSERT INTO auteur VALUES
    ('Hugo' ,'Victor Hugo', 'FRA', 19),
    ('Shakespeare', 'William Shakespeare', 'GBR', 16)
;

INSERT INTO livre VALUES
    (nextval('sqc_livre'), 'Les Misérables' ,1862 ,'roman' ,'Hugo'),
    (nextval('sqc_livre'), 'Ruy Blas' ,NULL,'theatre', 'Hugo'),
    (nextval('sqc_livre'), 'Roméo et Juliette' ,1597 ,'theatre' ,'Shakespeare')
;

INSERT INTO personnage VALUES
(nextval('sqc_ref_pers'), 'Juliette', 'princesse', 'F'),
(nextval('sqc_ref_pers'), 'Roméo', 'prince', 'M'),
(nextval('sqc_ref_pers'),'Cosette', 'femme de ménage', 'F')
;

INSERT INTO participe VALUES
(101, 3, 134),
(102, 3, 112)
;


--Q3
UPDATE livre
set date_parution = 1400
WHERE date_parution IS NULL;

--Q4
ALTER TABLE livre
DROP CONSTRAINT val_type_l,
ADD CONSTRAINT val_type_l
CHECK (type_l IN ('roman','theatre', 'recit',  'autre', 'poesie'));

--Q5
INSERT INTO livre VALUES
(nextval('sqc_livre'), 'Le Grand Meaulnes', 1913, 'roman', 'Alain-Fournier' );
--clé 'Alain-Fournier' pas dans table auteur
--Solution : aujouter l'auteur 'Alain-Fournier' dans la table auteur

--Q6
INSERT INTO participe VALUES
((SELECT reference FROM personnage WHERE nom ='Cosette'),
 (SELECT reference FROM livre WHERE titre ='les Misérables'),
 324);
--marche pas car cosette pas dans la table personnage

--Q7
DELETE FROM livre
WHERE titre = 'Roméo et Juliette';

--Q8
CREATE TABLE LIVRE_AUTEUR AS(
    (SELECT l.titre, l.nom
    from livre l join auteur a
    on l.nom=a.nom
    )
);
