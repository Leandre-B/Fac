CREATE TABLE joueurs(
    pays VARCHAR(30),
    nummaillot INTEGER,
    nom VARCHAR(50),
    prenom VARCHAR(50),
    annaiss INTEGER,
    nbsel INTEGER,

    PRIMARY KEY (pays, nummaillot)
);

ALTER TABLE joueurs
ADD CONSTRAINT range_nummaillot
CHECK (nummaillot BETWEEN 1 AND 26),
ADD CONSTRAINT val_nbsel
CHECK (nbsel IS NOT NULL);

CREATE TABLE match(
    num INTEGER,
    pays1 VARCHAR(30),
    pays2 VARCHAR(30),
    tour VARCHAR,

    PRIMARY KEY (num)
);

CREATE SEQUENCE sqc_num_match;

ALTER TABLE match
ADD CONSTRAINT val_tour
CHECK (tour IN (
    'premier tour',
    'huitième',
    'quart',
    'demi',
    'finale'
    )
);

CREATE TABLE buts(
    nummatch INTEGER,
    paysj VARCHAR(30),
    numj INTEGER,
    nummitemps INTEGER,
    minute_m INTEGER,

    PRIMARY KEY (nummatch, paysj, numj, nummitemps, minute_m),

    FOREIGN KEY (nummatch) REFERENCES match(num),
    FOREIGN KEY (paysj, numj) REFERENCES joueurs(pays, nummaillot)

);

ALTER TABLE buts
ADD CONSTRAINT val_nummitemps
CHECK (nummitemps IN (1, 2));

INSERT INTO joueurs VALUES
('France' ,10 ,'Mbappé', 'Kylian', NULL, 63),
('Brésil' ,7, 'Paqueta' ,'Lucas' ,1997 ,37),
('Corée du Sud' ,7 ,'Son' ,'Heung-Min' ,1992 ,109),
('Pologne' ,9 ,'Lewandowski', 'Robert' ,1988 ,138),
('France' ,9 ,'Giroud', 'Olivier' ,1986 ,117);


INSERT INTO match VALUES
(nextval('sqc_num_match'), 'France' ,'Australie', 'premier tour'),
(nextval('sqc_num_match'), 'Brésil', 'Corée du Sud', 'huitième'),
(nextval('sqc_num_match') ,'France','Brésil' ,'finale')
;

INSERT INTO buts VALUES
(1, 'France', 10 ,2 ,23),
(1, 'France', 9 ,1 ,32),
(2, 'Brésil', 7 ,1 ,13)
;

--3
UPDATE joueurs
set annaiss = 1998
where nom = 'Mbappé';

--4
ALTER TABLE match
DROP CONSTRAINT val_tour;

ALTER TABLE match
ADD CONSTRAINT val_tour
CHECK (tour IN (
    'premier tour',
    'huitième',
    'quart',
    'demi',
    'finale',
    'troisième place'
    )
);

--5
INSERT INTO match VALUES
(nextval('sqc_num_match'), 'France' ,'Pologne', 'huitième');

--6
INSERT INTO buts
    select m.num, j.pays, j.nummaillot, 2, 29
    from joueurs j, match m
    where j.nom = 'Mbappé' AND j.prenom='Kylian'
    and m.pays1='France' and m.pays2='Pologne' and
    m.tour = 'huitième'
;

INSERT INTO buts
    select m.num, j.pays, j.nummaillot, 2, 46
    from joueurs j, match m
    where j.nom = 'Mbappé' AND j.prenom='Kylian'
    and m.pays1='France' and m.pays2='Pologne' and
    m.tour = 'huitième'
;

--7
ALTER TABLE joueurs
ADD an_select INTEGER;

--8
UPDATE joueurs
SET an_select = 2018
WHERE nom='Paqueta' and prenom='Lucas';

--9
DELETE FROM joueurs
WHERE nom='Mbappé' and prenom='Kylian';

--10
CREATE VIEW but_jeunes AS
select *
from buts b join joueurs j
on b.paysj = j.pays and b.numj = j.nummaillot
where j.annaiss>1997;

--11
CREATE VIEW but_france AS

    select j.nom, j.prenom, b.cpt
    from joueurs j join (
        SELECT COUNT(*) as cpt, numj, paysj
        from buts
        group by paysj, numj
        having paysj = 'France'
    ) b
    on b.paysj = j.pays and b.numj = j.nummaillot
    where b.paysj='France'
;

--12
select nom, prenom
from but_france
where cpt =(
    select max(cpt)
    from but_france
);