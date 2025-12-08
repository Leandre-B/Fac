
CREATE TABLE Groupe(
    NomGroupe VARCHAR(5),
    IntituleGroupe VARCHAR(20),

    PRIMARY KEY (NomGroupe)
);

CREATE TABLE Etudiant(
    NumEt INTEGER,
    NomEt VARCHAR(30),
    PrenomEt VARCHAR(30),
    AdrEt VARCHAR(50),
    DatNais DATE,
    NomGr VARCHAR(5),

    PRIMARY KEY (NumEt),
    FOREIGN KEY (NomGr) REFERENCES Groupe(NomGroupe)
        ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE Enseignant(
    NumEns VARCHAR(30),
    NomEns VARCHAR(30),

    PRIMARY KEY (NumEns)
);

CREATE TABLE Matiere(
    NomMat VARCHAR(15),
    Coef INTEGER,
    NumEns VARCHAR(30),

    PRIMARY KEY (NomMat),
    FOREIGN KEY (NumEns) REFERENCES Enseignant (NumEns)
        ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE Controle (
    NumCont INTEGER,
    NomMat VARCHAR(15),
    DatConf DATE,
    Coef INTEGER,

    PRIMARY KEY (NumCont),
    FOREIGN KEY (NomMat) REFERENCES Matiere (NomMat)
        ON DELETE CASCADE ON UPDATE CASCADE
);

CREATE TABLE PassCont(
    NumEt INTEGER,
    NumCont INTEGER,
    Note FLOAT,

    PRIMARY KEY (NumEt, NumCont),

    FOREIGN KEY (NumEt) REFERENCES Etudiant(NumEt)
        ON DELETE CASCADE ON UPDATE CASCADE,

    FOREIGN KEY (NumCont) REFERENCES Controle (NumCont)
        ON DELETE CASCADE ON UPDATE CASCADE
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
(6, 'VARCHARlemagne'),
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

INSERT INTO PassCont VALUES
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

--2 fonctionne pas car trop vieux
-- INSERT INTO Etudiant VALUES
-- (1200, 'ZIDANE', 'Zinedine', 'Marseille','23/06/1972','A1');

--3 fonctionne pas -> cle A6 dans groupe inexistant
--INSERT INTO Etudiant VALUES
--(1200, 'MBAPPE', 'Kylian', 'Madrir','20/12/1998','A6');

--4
INSERT INTO groupe VALUES
('A6', 'Football');

--5 là fonctionne
INSERT INTO Etudiant VALUES
(1200, 'MBAPPE', 'Kylian', 'Madrir',TO_DATE('20/12/1998', 'DD/MM/YYYY'),'A6');

--6 fontionne pas -> cle etudiant num 1118 n'existe pas
--INSERT INTO PassCont VALUES
--(1118, 1, 15);

--7
INSERT INTO etudiant VALUES
(nextval('sqc_numEt'), 'DOUE', 'Désiré', 'Paris', '3/06/2005', 'A1');

--8 fontionne maintenant
INSERT INTO PassCont VALUES
(1118, 1, 15);

--9
UPDATE Enseignant
SET NumEns=101
WHERE NomEns='Carter';

--10
INSERT INTO etudiant VALUES
(nextval('sqc_numEt'), 'CAMAVINGA', 'Eduardo', 'Madrid', '10/10/2002',
(select nomgroupe from groupe where IntituleGroupe='Informatique'));

--11
ALTER TABLE groupe
ADD salle VARCHAR(5);

--12
UPDATE groupe
set salle = 'L00' || (substring(nomgroupe, 2, 1));

--13
UPDATE PassCont
set note = note + 1
where NumCont IN(
    select NumCont
    from Passcont
    group by NumCont
    having avg(note)<8
);

--14
CREATE VIEW v14 AS(
    select NumEt, NomEt, NomGr
    from etudiant
    order by NomGr
);

--15
select e.nomet, p.note, c.NomMat
from etudiant e join PassCont p
on e.NumEt=p.NumEt
join Controle c
on c.NumCont=p.NumCont
order by e.nomet;

--16
select p.note
from etudiant e join PassCont p
on e.NumEt=p.NumEt
join Controle c
on c.NumCont=p.NumCont
where c.DatConf = TO_DATE('12/12/2022', 'DD/MM/YYYY') and e.nomet='TOTO'
    and c.NomMat='Algo 2';

--17
select nomet
from etudiant
where substring(nomet, 1, 1) IN ('a', 'A');

--18
select m.Coef as CoefMat, c.Coef as CoefCtrl
from PassCont p join Controle c
ON p.NumCont = c.NumCont
join Matiere m on m.NomMat=c.NomMat
where p.note=20;

--19
select e.nomet
from etudiant e join PassCont p
on e.NumEt=p.NumEt
join Controle c
on c.NumCont=p.NumCont
where c.DatConf = TO_DATE('12/12/2022', 'DD/MM/YYYY')
    and c.NomMat='Algo 2'
    and p.note>=(
        select avg(p.note)
        from PassCont p join Controle c
        on c.NumCont=p.NumCont
        group by c.NomMat
        having c.NomMat = 'Algo 2'
);

--20
select e.NomEns
from Enseignant e join Matiere m
on e.NumEns = m.NumEns
join Controle c on c.NomMat = m.NomMat
where c.NumCont in(
    select NumCont
    from PassCont
);

--21
select nomet
from etudiant
where adret not in(
    'Angers', 'Cholet', 'tours'
);

--22
INSERT INTO PassCont VALUES
(1114, 4, 6),
(1116, 4, 18);


select e.nomet
from etudiant e join PassCont p
on e.NumEt=p.NumEt
join Controle c
on c.NumCont=p.NumCont
where c.DatConf = TO_DATE('27/03/2023', 'DD/MM/YYYY')
    and c.NomMat='Algo 3'
    and p.note>(
        select p.note
        from etudiant e join PassCont p
        on e.NumEt=p.NumEt
        join Controle c
        on c.NumCont=p.NumCont
        where c.DatConf = TO_DATE('27/03/2023', 'DD/MM/YYYY')
        and c.NomMat='Algo 3' and e.nomet = 'GHULAM'
);

--23
select e.nomet
from etudiant e join PassCont p
on e.NumEt=p.NumEt
join Controle c
on c.NumCont=p.NumCont
where
p.note<10 and
c.DatConf = TO_DATE('27/03/2023', 'DD/MM/YYYY')
and c.NomMat='Algo 3'

INTERSECT

select e.nomet
from etudiant e join PassCont p
on e.NumEt=p.NumEt
join Controle c
on c.NumCont=p.NumCont
where
p.note<10 and
c.DatConf = TO_DATE('12/12/2022', 'DD/MM/YYYY')
and c.NomMat='Algo 2'
;


--24
select min(note), max(note), avg(note)
from PassCont;

--25
select e.nomet, e.PrenomEt, min(note), max(note), avg(note)
from etudiant e join PassCont p
on e.numet=p.numet
group by e.numet;

--26
select e.nomgr, min(note), max(note), avg(note)
from etudiant e join PassCont p
on e.numet=p.numet
group by e.NomGr;

--27
SELECT c.nomat, avg(note), min(note), max(note)
from PassCont p join Controle c
on p.NumCont=c.NumCont
group by NomMat;

--28
select sum(note*coef)/sum(c.coef) as moyenne
from PassCont p join Controle c
on p.NumCont=c.NumCont;

--29
select nomet, sum(note*coef)/sum(c.coef) as moyenne
from PassCont p join Controle c
on p.NumCont=c.NumCont
join etudiant e
on e.numet=p.NumEt
group by nomet;

--30
select nomet, sum(note*coef)/sum(c.coef) as moyenne
from PassCont p join Controle c
on p.NumCont=c.NumCont
right join etudiant e
on e.numet=p.NumEt
group by nomet;

--31
select count(nomet), adret
from etudiant
group by adret;

--32
select numcont, count(numcont) as cpt
from PassCont p
where note>=10
group by p.numcont;

--33
select nomet
from PassCont p join Controle c
on p.NumCont=c.NumCont
join etudiant e
on e.numet=p.NumEt
EXCEPT(
    select nomet
    from PassCont p join Controle c
    on p.NumCont=c.NumCont
    join etudiant e
    on e.numet=p.NumEt
    WHERE note<10
);

--34
select numcont
from PassCont p
join etudiant e
on e.numet=p.NumEt
where nomgr='A1'
EXCEPT(
    select numcont
    from PassCont p
    join etudiant e
    on e.numet=p.NumEt
    where nomgr='A1' and note<10
);

--35
select numcont
from PassCont
where note>10
group by numcont
having count(numet) >= ALL(
    select count(numet)
    from PassCont
    where note>10
    group by numcont
);

--36
select NomMat
from PassCont p join Controle c
on c.numcont = p.numcont
where note>10
group by numcont
having count(numet) >= ALL(
    select count(numet)
    from PassCont
    where note>10
    group by numcont
);

--37
select numcont
from PassCont p
group by NumCont
having avg(note)<= ALL(
    select avg(note)
    from PassCont p
    group by NumCont
);
