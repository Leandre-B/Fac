-- Exercice 1
-- Un poste de travail (PC) est caractérisé par un numéro de série et une adresse IP, il est
-- géré par un seul administrateur désigné par un numéro, un nom et son age.
-- 1. Créer les types et les tables
-- 2. Insérer deux administrateurs A1 et A2 dans la table Administrateur et deux
-- ordinateurs PC1 et PC2 dans la table Ordinateur (sans le lier à un administrateur)
-- 3. Insérer le PC4 avec la commande Insert, et rattacher-le à son administrateur A1
-- 4. Modifier la base pour que le PC1 et le PC2 soit administrer par l’administrateur A2.
-- 5. Modifier la base pour que l'administrateur A2 s'occupe des PC branchés sur le
-- segment d'indicatif IP 193.54.227.
-- 6. Modifier la base pour que les PC gérés par A2 et branchés sur le segment
-- d'indicatif 193.54.227 n'ont plus besoin d'administrateur.
-- 7. Supprimer les PC de la table Ordinateur qui ne contiennent pas d’administrateur

drop type t_admin cascade;
create type t_admin as (
    num varchar(50),
    nom varchar(50),
    age integer
);

drop type t_pc cascade;
create type t_pc as (
    numSerie varchar(50),
    ip varchar(50),
    admin t_admin
);

create table pc of t_pc (
    primary key(ip)
);


create table admin of t_admin (
    primary key(num)
);

insert into admin values
('A1', 'Jean', 91),
('A2', 'Noé', 92);

insert into pc values
('PC1', '123.456.689', null),
('PC1', '193.54.227', null);

insert into pc values
('PC4', '987.654.321', (select a from admin a where num='A1'));

update pc 
set admin=(select a from admin a where num='A2')
where numSerie = 'PC1';

update pc p
set admin=null
where ip = '193.54.227' AND (p.admin).num = 'A2';

delete from pc
where admin is null;


