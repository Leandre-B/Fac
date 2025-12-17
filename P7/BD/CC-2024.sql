CREATE table lutin(
    nom varchar(50),
    couleur varchar(20),
    age integer,
    anciennete integer,

    primary key(nom, couleur)
);

create sequence sqc_num_traineau start 1001;
CREATE table traineau(
    numero integer,
    nom varchar(50),
    capacite integer,
    nbrennes integer,
    nomlutin varchar(50),
    couleurlutin varchar(20),

    constraint cstr_nbrennes check(nbrennes IN (2, 4, 6, 8)),

    FOREIGN KEY (nomlutin, couleurlutin) REFERENCES lutin(nom, couleur)
    ON UPDATE CASCADE,

    primary key (numero)
);

create table cadeau(
    numero integer,
    nom varchar(50),
    categorie varchar(20),
    nomlutin varchar(50),
    couleurlutin varchar(20),

    primary key (numero),

    FOREIGN KEY (nomlutin, couleurlutin) REFERENCES lutin(nom, couleur)
    ON UPDATE CASCADE
);

create table chargement(
    numtraineau integer,
    numcadeau integer,
    nbexemp integer,

    primary key(numtraineau, numcadeau),
    FOREIGN key (numcadeau) REFERENCES cadeau(numero)
    ON UPDATE CASCADE,
    FOREIGN key (numtraineau) REFERENCES traineau(numero)
    ON UPDATE CASCADE
);

insert into lutin values
('Chantejuste' ,'rouge', 145286 ,12540),
('Ritfort' ,'vert', 385942, 41258),
('Chantejuste' ,'jaune', 241933 ,null);

insert into traineau values
(nextval('sqc_num_traineau') ,'Zéphyr puissant' ,250 ,4, 'Chantejuste', 'rouge');

insert into cadeau values
(12345 ,'Dinos magiques 100 pièces', 'puzzle' ,'Chantejuste', 'rouge'),
(98765, 'Les Loups-garous de Thiercelieux', 'jeu de société', 'Ritfort' ,'vert');

INSERT into chargement values
(1001 ,98765 ,3);

UPDATE lutin
set anciennete=124856
where nom='Chantejuste';

alter table traineau
drop constraint cstr_nbrennes;

ALTER table traineau
add constraint cstr_nbrennes
check(nbrennes IN (2, 4, 6, 8, 12));

insert into lutin values
('Mangetrop','bleu', 245638, 84201);

INSERT into cadeau values
(656565, 'Les Animaux des pyrénées', 'livre', 'Mangetrop','bleu' );


INSERT into chargement
select t.numero, c.numero, 5
from traineau t, cadeau c
where c.nom = 'Dinos magiques 100 pièces';

delete from lutin
where nom = 'Chantejuste' and couleur = 'rouge';

UPDATE traineau
set numero = 1
where nom = 'Zéphyr puissant';

create view traineau_dinos as
select t.nom
from traineau t join chargement c
on t.numero = c.numtraineau
join cadeau cad on cad.numero = c.numcadeau
where cad.nom='Dinos magiques 100 pièces';

create view NB_TRAINEAU_LUTIN as
select l.nom, l.couleur, count(t.numero)
from lutin l join traineau t
on l.nom = t.nomlutin and
    l.couleur = t.couleurlutin
group by l.nom, l.couleur
having count(t.numero) != 0;

create view CT_LUTIN as
select t.nomlutin, t.couleurlutin
from traineau t join chargement c
on t.numero = c.numtraineau
join cadeau cad on cad.numero = c.numcadeau
where t.nomlutin = cad.nomlutin and
    t.couleurlutin = cad.couleurlutin;

create view MAX_TRAINEAU_LUTIN as
select nomlutin, couleurlutin, count(numero)
from traineau
GROUP by nomlutin, couleurlutin
having count(numero) >=ALL(
    select count(numero)
    from traineau
    GROUP by nomlutin, couleurlutin
);

drop table lutin;

