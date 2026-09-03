drop sequence if exists  numnag;
drop sequence if exists numep ;
drop sequence if exists numOff ;

drop table if exists resultat;
drop table if exists categorie_epreuve;
drop table if exists officiel;
drop table if exists nageur;
drop table if exists club;

create sequence numnag minvalue 101;
create sequence numep ;
create sequence numOff ;

create table club
(
Nclub varchar(50) primary key,
Region varchar(100)
);

create table nageur
(
NumeroNag int primary key,
NomNag  varchar(50),
PrenomNag varchar(50),
AnneedeNaissance int,
Sexe char(1),
Nomclub varchar(30),
foreign key (Nomclub) references club(Nclub),
constraint lesexe  check (Sexe in ('M','F'))
);

create table officiel 
(
NumeroOff int primary key,
NomOff  varchar(50),
PrenomOff  varchar(50),
Degre char(1),
Nomclub varchar(50),
foreign key (Nomclub) references club(Nclub),
constraint ledegre  check (Degre in ('A','B','C','D'))
);


create table categorie_epreuve
(
NumeroEp int primary key,
Type varchar(50),
Niveau varchar(50),
constraint leltype check(Type in ('Parcours à sec', 'Propulsion technique', 'Technique')),
constraint leniveau check(Niveau in ('Synchro Découverte', 'Synchro Argent', 'Synchro Or'))
);


create table resultat
(
NumeroNag int references nageur,
NumeroEp int references categorie_epreuve,
Annee int,
NumeroOff int references officiel,
Note real,
primary key (NumeroNag, NumeroEp, Annee, NumeroOff),
constraint lanote check(Note between 0 and 10)
);


insert into club (Nclub, Region )values
('ANGERS NAT SYNCHRO','PAYS DE LA LOIRE'),
('LEO-LAGRANGE NANTES','PAYS DE LA LOIRE'),
('US LA FLECHE','PAYS DE LA LOIRE'),
('CN ST BRIEUC','BRETAGNE'),
('C PAUL BERT RENNES','BRETAGNE'),
('NATATION ARTISTIQUE TOURS','CENTRE VAL DE LOIRE'),
('SYNCHRO RIPAULT VAL DE L INDRE','CENTRE VAL DE LOIRE'),
('ACQUA SYNCHRO BASTIA','CORSE'),
('BN STRASBOURG','GRAND-EST'),
('ONDINES CARAIBES BAIE MAHAULT','GUADELOUPE'),
('NS HELLEMMES','HAUTS-DE-FRANCE'),
('STADE FRANCAIS','ILE-DE-FRANCE'), 
('ANS LES AQUARINES','ILE-DE-FRANCE'),
('GPS CORBEIL ESSONNES','ILE-DE-FRANCE'),
('LES AQUANAUTES','LA REUNION'),
('CAEN SYNCHRO','NORMANDIE'),
('GIRONDINS DE BORDEAUX','NOUVELLE-AQUITAINE'),
('COLOMIERS NAT SYNCHRO','OCCITANIE'),
('CHENOVE NATATION','BOURGOGNE FRANCHE COMTE')
;


insert into  categorie_epreuve (NumeroEp, Type, Niveau)values
(nextval('numep'),'Parcours à sec','Synchro Découverte'),
(nextval('numep'),'Propulsion technique','Synchro Découverte'),
(nextval('numep'),'Technique','Synchro Découverte'),
(nextval('numep'),'Parcours à sec','Synchro Argent'),
(nextval('numep'),'Propulsion technique','Synchro Argent'),
(nextval('numep'),'Technique','Synchro Argent'),
(nextval('numep'),'Parcours à sec','Synchro Or'),
(nextval('numep'),'Propulsion technique','Synchro Or'),
(nextval('numep'),'Technique','Synchro Or')

;

insert into  officiel  (NumeroOFF,NomOFF,PrenomOFF, Degre, Nomclub ) values
(nextval('numOff'),'LALE', 'Christine', 'A','ANGERS NAT SYNCHRO'),
(nextval('numOff'),'CHAFES ', 'Rachel', 'B','ANGERS NAT SYNCHRO'),
(nextval('numOff'),'MEYET', ' Barbara', 'C','LEO-LAGRANGE NANTES'),
(nextval('numOff'),'LANDAIS ', 'Florence', 'D','LEO-LAGRANGE NANTES'),
(nextval('numOff'),'HELLARD', ' Sylvie', 'A','STADE FRANCAIS'),
(nextval('numOff'),'NEDELEC ', 'Marie', 'A','NATATION ARTISTIQUE TOURS'),
(nextval('numOff'),'LEFEBURE', ' Evelyne', 'D','LES AQUANAUTES'),
(nextval('numOff'),'POCHET', ' Isabelle', 'C','CAEN SYNCHRO'),
(nextval('numOff'),'VIALARET', ' Maryléne', 'B','COLOMIERS NAT SYNCHRO'),
(nextval('numOff'),'GROSSET', ' Christine', 'B','ANS LES AQUARINES'),
(nextval('numOff'),'SENOT', ' Nathalie', 'A','BN STRASBOURG'),
(nextval('numOff'), 'NICOL', ' Celine', 'A','ANGERS NAT SYNCHRO'),
(nextval('numOff'),' HUGUENET', 'Aurore ', 'A','SYNCHRO RIPAULT VAL DE L INDRE'),
(nextval('numOff'),'BRIHAULT ', 'Caroline ', 'C','NATATION ARTISTIQUE TOURS'),
(nextval('numOff'),'ROSELET ', 'Mélanie ', 'A','LEO-LAGRANGE NANTES')

;

insert into  nageur (NumeroNag,NomNag,PrenomNag,anneedeNaissance,sexe,Nomclub)values
(nextval('numNag'),'DELHUMEAU',' Valentine',2008, 'F', 'ANGERS NAT SYNCHRO'  ),
(nextval('numNag'), 'LECOURT','Clément', 2008 , 'M', 'ANGERS NAT SYNCHRO' ),
(nextval('numNag'), 'MALECOT',' Lilou',2009,'F', 'ANGERS NAT SYNCHRO' ),
(nextval('numNag'),'BELIN','Clara',2005,'F', 'LEO-LAGRANGE NANTES'),
(nextval('numNag'),'BELIN','Lola',2005,'F','NATATION ARTISTIQUE TOURS'),
(nextval('numNag'), 'FORESTIER','Jeanne',2001,'F','SYNCHRO RIPAULT VAL DE L INDRE'),
(nextval('numNag'),'JOLY','Lilou',2001,'F','BN STRASBOURG'),
(nextval('numNag'),'MALO','Léna',2004,'F','BN STRASBOURG'),
(nextval('numNag'),'MORTIER','Lise',2006,'F','CAEN SYNCHRO'),
(nextval('numNag'),'PAILLUSSON ','Audrey',2001,'F','NATATION ARTISTIQUE TOURS'),
(nextval('numNag'),'ROBERT',' Julien', 2006, 'M', 'LEO-LAGRANGE NANTES'),
(nextval('numNag'),'SCHEIBER','Youna',2003,'F','NATATION ARTISTIQUE TOURS'),
(nextval('numNag'),'POTTIN','Katell',2003,'F','ANS LES AQUARINES'),
(nextval('numNag'),'AUTEFORT',' Paulin',2013,'M','ANS LES AQUARINES'),
(nextval('numNag'),'EZZAHOUI','Salma',2005,'F','COLOMIERS NAT SYNCHRO'),
(nextval('numNag'),'LOREAU','Zoé',2007,'F','LES AQUANAUTES'),
(nextval('numNag'),'NERRIERE',' Louna',2012,'F','STADE FRANCAIS'),
(nextval('numNag'),'POUIVET',' Malia',2011,'F','CAEN SYNCHRO'),
(nextval('numNag'),'ROUGET',' Soline',2007,'F','STADE FRANCAIS'),
(nextval('numNag'),'SALAH ','Chloe',2008,'F','ANGERS NAT SYNCHRO' ),
(nextval('numNag'),'SANAOUI ','Kenza',2004,'F','NATATION ARTISTIQUE TOURS'),
(nextval('numNag'),'CAILLETON ','Elona',2000,'F','LEO-LAGRANGE NANTES'),
(nextval('numNag'),'GREGOIRE ','Thais',2001,'M','ANS LES AQUARINES'),
(nextval('numNag'),'ROUTHIAU ','Zelie',2007,'F','NATATION ARTISTIQUE TOURS'),
(nextval('numNag'),'BRUCELLE ','Justine',2002,'F','BN STRASBOURG'),
(nextval('numNag'),'CABARET ','Margot',2005,'F','ANGERS NAT SYNCHRO' ),
(nextval('numNag'),'EVEILLEAU ','Ambre',2004,'F','SYNCHRO RIPAULT VAL DE L INDRE'),
(nextval('numNag'),'FROUIN ','Lana',2001,'F','BN STRASBOURG'),
(nextval('numNag'),'RADIGUE ','Liyana',2009,'F','ANS LES AQUARINES'),
(nextval('numNag'),'MARQUES',' Romane',2005,'F','LEO-LAGRANGE NANTES'),
(nextval('numNag'),'MARQUES ','Axel',2003,'M','NATATION ARTISTIQUE TOURS'),
(nextval('numNag'),'MAINGUY ','Angele',2008,'F','ANGERS NAT SYNCHRO' ),
(nextval('numNag'),'HOUDAYER ','Camille',2007,'M','CAEN SYNCHRO'),
(nextval('numNag'),'FROUIN',' Lana',2009,'F','CAEN SYNCHRO'),
(nextval('numNag'),'EVEILLEAU ','Thomas',2010,'M','LEO-LAGRANGE NANTES')
;

insert into resultat(numeroNag, NumeroEp, Annee , NumeroOff, Note) values
(102,1,2021,2,3.5001),
(102,1,2021,5,5.5100),
(102,1,2021,10,4.5123),
(102,1,2021,14,3.5001),
(103,1,2021,14,6.5001),
(103,1,2021,10,6.5123),
(103,1,2021,5,7.5100),
(103,1,2021,2,6.5001),
(112,1,2021,2,3.5001),
(112,1,2021,5,1.5100),
(112,1,2021,10,1.5123),
(112,1,2021,14,2.5001),
(113,1,2021,14,7.5001),
(113,1,2021,10,6.5123),
(113,1,2021,5,7.5100),
(113,1,2021,2,6.5001),
(102,2,2021,2,3.5001),
(102,2,2021,5,5.5100),
(102,2,2021,10,4.5123),
(102,2,2021,14,3.5001),
(103,2,2021,14,6.5001),
(103,2,2021,10,6.5123),
(103,2,2021,5,7.5100),
(103,2,2021,2,6.5001),
(112,2,2021,2,3.5001),
(112,2,2021,5,1.5100),
(112,2,2021,10,1.5123),
(112,2,2021,14,2.5001),
(113,2,2021,14,7.5001),
(113,2,2021,10,6.5123),
(113,2,2021,5,7.5100),
(113,2,2021,2,6.5001),
(102,1,2022,2,3.5001),
(102,1,2022,5,5.5100),
(102,1,2022,10,4.5123),
(102,1,2022,14,3.5001),
(103,1,2022,14,6.5001),
(103,1,2022,10,6.5123),
(103,1,2022,5,7.5100),
(103,1,2022,2,6.5001),
(112,1,2022,2,0),
(112,1,2022,5,1.5100),
(112,1,2022,10,1.5123),
(112,1,2022,14,2.5001),
(113,1,2022,14,7.5001),
(113,1,2022,10,6.5123),
(113,1,2022,5,7.5100),
(113,1,2022,2,6.5001),
(102,2,2022,2,3.5001),
(102,2,2022,5,5.5100),
(102,2,2022,10,0),
(102,2,2022,14,3.5001),
(103,2,2022,14,6.5001),
(103,2,2022,10,6.5123),
(103,2,2022,5,7.5100),
(103,2,2022,2,6.5001),
(112,2,2022,2,3.5001),
(112,2,2022,5,1.5100),
(112,2,2022,10,1.5123),
(112,2,2022,14,2.5001),
(113,2,2022,14,7.5001),
(113,5,2022,10,6.5123),
(113,5,2022,5,7.5100),
(113,2,2022,2,6.5001),
(102,6,2022,2,3.5001),
(102,6,2022,5,5.5100),
(102,6,2022,10,4.5123),
(102,6,2022,14,3.5001),
(103,6,2022,14,6.5001),
(103,6,2022,10,6.5123),
(103,6,2022,5,7.5100),
(103,6,2022,2,6.5001),
(112,6,2022,2,3.5001),
(112,5,2022,5,1.5100),
(112,6,2022,10,1.5123),
(112,6,2022,14,2.5001),
(113,6,2022,14,7.5001),
(113,6,2022,10,6.5123),
(113,4,2022,5,7.5100),
(113,6,2022,2,6.5001)
;
/*
select * from club;
select * from nageur;
select * from officiel;


select * from resultat;
*/

