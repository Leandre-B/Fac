
CREATE TABLE Groupe(
    NomGroupe CHAR(5),
    IntituleGroupe VARCHAR(20),

    PRIMARY KEY (NomGroupe)
);

CREATE TABLE Etudiant(
    NumEt INTEGER,
    NomEt CHAR(30),
    PrenomEt VARCHAR(30),
    AdrEt CHAR(50),
    DatNais DATE,
    NomGr CHAR(5),

    PRIMARY KEY (NumEt),
    FOREIGN KEY (NomGr) REFERENCES Groupe(NomGroupe)
        ON DELETE CASCADE
);

CREATE TABLE Enseignant(
    NumEns CHAR(30),
    NomEns CHAR(30),

    PRIMARY KEY (NumEns)
);

CREATE TABLE Matiere(
    NomMat CHAR(15),
    Coef INTEGER,
    NumEns CHAR(30),

    PRIMARY KEY (NomMat),
    FOREIGN KEY (NumEns) REFERENCES Enseignant (NumEns)
        ON DELETE CASCADE
);

CREATE TABLE Controle (
    NumCont INTEGER,
    NomMat CHAR(15),
    DatConf DATE,
    Coef INTEGER,

    PRIMARY KEY (NumCont),
    FOREIGN KEY (NomMat) REFERENCES Matiere (NomMat)
        ON DELETE CASCADE
);

CREATE TABLE PassCont(
    NumEt INTEGER,
    NumCont INTEGER,
    Note FLOAT,

    PRIMARY KEY (NumEt, NumCont),

    FOREIGN KEY (NumEt) REFERENCES Etudiant(NumEt)
        ON DELETE CASCADE,

    FOREIGN KEY (NumCont) REFERENCES Controle (NumCont)
        ON DELETE CASCADE
);


CREATE SEQUENCE sqc_numEt START 1111;
CREATE SEQUENCE sqc_numCont;


ALTER TABLE Etudiant
ADD CONSTRAINT val_age
CHECK(DatNais<='01/01/2019' AND DatNais>='01/01/1990');
--CHECK(extract(year from age(DatNais)) between 1990 and 2009);
--datanaiss date check (extrect (year from age (datnaiss)) between 16 and 35)

ALTER TABLE Groupe
ADD CONSTRAINT val_groupe
CHECK (NomGroupe IN ('A1', 'A2', 'A3', 'A4', 'A5', 'A6'));

ALTER TABLE Controle
ADD CONSTRAINT val_coef_ctrl
CHECK (Coef>=1 and Coef<=3);

ALTER TABLE Matiere
ADD CONSTRAINT val_coef_mat
CHECK (Coef>=1 and Coef<=8);

ALTER TABLE Passcont
ADD CONSTRAINT val_note
CHECK(note>=0 and note<=20);



INSERT INTO Groupe VALUES
('A1', 'Informatique'),
('A2', 'Math-Info'),
('A3', 'Bio-Info'),
('A4', 'Chimie'),
('A5', 'Math');


INSERT INTO Etudiant VALUES
(nextval('sqc_numEt'), 'AHDJOUDJ', 'Yannick', 'Angers', TO_DATE('18/01/2003', 'DD/MM/YYYY'), 'A1'),
(nextval('sqc_numEt'), 'AMEUR', 'Adil', 'Cholet', TO_DATE('17/02/2002', 'DD/MM/YYYY'), 'A1'),
(nextval('sqc_numEt'), 'CALVAIRE', 'Isabelle', 'Nantes', TO_DATE('01/03/2004', 'DD/MM/YYYY'), 'A2'),
(nextval('sqc_numEt'), 'GHULAM', 'William', 'Cholet', TO_DATE('27/04/2004', 'DD/MM/YYYY'), 'A2'),
(nextval('sqc_numEt'), 'MIRMONT', 'Jean', 'Paris', TO_DATE('07/05/2002', 'DD/MM/YYYY'), 'A3'),
(nextval('sqc_numEt'), 'TOTO', 'Sylvie', 'Tours', TO_DATE('17/06/2001', 'DD/MM/YYYY'), 'A3'),
(nextval('sqc_numEt'), 'WINTERHA', 'Shahidah', 'Toulouse', TO_DATE('07/07/2003', 'DD/MM/YYYY'), 'A3');

INSERT INTO Enseignant VALUES
(1, 'Carter'),
(2, 'Clinton'),
(3, 'Bush'),
(4, 'Paolo'),
(5, 'Vissou'),
(6, 'Charlemagne'),
(7, 'Léandri');

INSERT INTO Matiere VALUES
('Algo 2', 2, 1),
('Algo 3', 3, 2),
('Math1', 6, 3),
('Gestion', 7, 4),
('TE', 7, 5),
('Math2', 6, 6),
('Anglais', 7, 7);

INSERT INTO Controle VALUES
(nextval('sqc_numCont'), 'Algo 2', TO_DATE('15/01/2023', 'DD/MM/YYYY'), 1),
(nextval('sqc_numCont'), 'Algo 2', TO_DATE('12/12/2022', 'DD/MM/YYYY'), 3),
(nextval('sqc_numCont'), 'Algo 3', TO_DATE('17/02/2023', 'DD/MM/YYYY'), 2),
(nextval('sqc_numCont'), 'Algo 3', TO_DATE('27/03/2023', 'DD/MM/YYYY'), 3),
(nextval('sqc_numCont'), 'Math1', TO_DATE('17/01/2023', 'DD/MM/YYYY'), 1),
(nextval('sqc_numCont'), 'Gestion', TO_DATE('07/02/2023', 'DD/MM/YYYY'), 2),
(nextval('sqc_numCont'), 'TE', TO_DATE('27/03/2023', 'DD/MM/YYYY'), 2),
(nextval('sqc_numCont'), 'Math2', TO_DATE('17/01/2023', 'DD/MM/YYYY'), 1),
(nextval('sqc_numCont'), 'Anglais', TO_DATE('27/01/2023', 'DD/MM/YYYY'), 2);

INSERT INTO Passcont VALUES
(1111, 1, 10),
(1112, 1, 20),
(1113, 1, 11.5),
(1114, 1, 3),
(1115, 1, 10.5),
(1116, 1, 12),
(1111, 2, 10.5),
(1112, 2, 6.6),
(1113, 2, 4.5),
(1114, 2, 9),
(1115, 2, 8.5),
(1116, 2, 2.5),
(1111, 3, 14.5),
(1112, 3, 11.5),
(1113, 3, 3.5),
(1114, 3, 12.5),
(1115, 3, 20),
(1116, 3, 9.5);


--12 set salle='Lou'||subtring(nomgroupe, 2, 1)