
drop type personne_t cascade;
create type personne_t as (
    NumSecu integer,
    nom varchar(50),
    prenom varchar(50),
    sexe CHAR(1),
    datenaiss DATE
);
drop type societe_t cascade;
create type societe_t as (
    codesoc integer,
    nomsoc varchar(50),
    adresse varchar(50) -- type adresse mais flemme
);

create table personne of personne_t (
    primary key(NumSecu)
);

create table societe of societe_t (
    primary key (codesoc)
);

drop table salarie;
create table salarie (
    personne personne_t,
    societe societe_t,
    salaire integer,
    primary key (societe, personne)
);

drop table action;
create table action(
    personne personne_t,
    societe societe_t,
    dateAct DATE,
    nbrAct integer,
    typeAction varchar(50),

    primary key (personne, societe, dateAct)
    
);
drop table histo_annuel_actionnaire;
create table histo_annuel_actionnaire (
    personne personne_t,
    societe societe_t,
    annee integer,
    nbracttotal integer,
    nbr_achat integer,
    nbr_vente integer,

    primary key (personne, societe, annee)
);

insert into societe values
(1234, 'U', '2 place bordillon, Angers, 4900'),
(5678, 'Arch', 'une super adresse');

insert into personne values
(1, 'Le', 'Andrée', 'F', '01/01/1999'),
(2, 'Mr', 'Jean', 'M', '01/01/1960');

insert into salarie values
((select p from personne p where NumSecu = 1), 
 (select s from societe s where codesoc = 5678),
  10000
),
((select p from personne p where NumSecu = 2), 
 (select s from societe s where codesoc = 5678),
  99999
);



-- 3

drop function update_histo();
create function update_histo() returns trigger as
$$
DECLARE
BEGIN
    IF (select count(*) from histo_annuel_actionnaire 
        where NEW.personne = histo_annuel_actionnaire.personne AND
              NEW.societe  = histo_annuel_actionnaire.societe) = 0
    THEN
        IF NEW.typeAction = 'vente' THEN
            insert into histo_annuel_actionnaire values
            (NEW.personne, NEW.societe, date_part('year', NEW.dateAct), NEW.nbrAct, 0, NEW.nbrAct);
        ELSE
            insert into histo_annuel_actionnaire values
            (NEW.personne, NEW.societe, date_part('year', NEW.dateAct), NEW.nbrAct, NEW.nbrAct, 0);
        END IF;
    ELSE
        IF NEW.typeAction = 'vente' THEN
            update histo_annuel_actionnaire
            set nbracttotal = nbracttotal+NEW.nbrAct, 
                nbr_vente = nbr_vente + NEW.nbrAct
            where NEW.personne = histo_annuel_actionnaire.personne AND
                  NEW.societe  = histo_annuel_actionnaire.societe;
        ELSE
            update histo_annuel_actionnaire
            set nbracttotal = nbracttotal+NEW.nbrAct, 
                nbr_achat = nbr_achat + NEW.nbrAct
            where NEW.personne = histo_annuel_actionnaire.personne AND
                  NEW.societe  = histo_annuel_actionnaire.societe;
        END IF;
    END IF;
    return NEW;
END;
$$ LANGUAGE 'plpgsql';


create trigger update_histo_trigger
before insert on action
    for each row execute PROCEDURE
        update_histo();

insert into action values
((1, 'Le', 'Andrée', 'F', '01/01/1999'),
 (5678, 'Arch', 'une super adresse'),
 '21/09/2026',
 4,
 'vente'
);


-- 4

drop function check_insert_action();
create function check_insert_action() returns trigger as
$$
DECLARE
BEGIN
    IF NEW.dateAct < CURRENT_DATE THEN
        return NULL;
    END IF;
    return NEW;
END;
$$ LANGUAGE 'plpgsql';


create trigger check_insert_action_trigger
before insert or update on action
    for each row execute PROCEDURE
        check_insert_action();


-- 5
drop function check_action(societe_t);
create function check_action(s societe_t) returns void as
$$
DECLARE
    curs cursor for select * from histo_annuel_actionnaire
    where societe = s;
    rec record;
BEGIN
    open curs;
    loop
        fetch curs into rec;
        exit when not found;
        IF rec.nbr_achat < rec.nbr_vente THEN
            raise notice '%', s;
        END IF;
    end loop;
    close curs;

END;
$$ LANGUAGE 'plpgsql';
