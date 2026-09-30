
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
 '09/21/2026',
 4,
 'vente'
),((2, 'Mr', 'Jean', 'M', '01/01/1960'),
 (5678, 'Arch', 'une super adresse'),
 '10/21/2025',
 4,
 'achat'
),((1, 'Le', 'Andrée', 'F', '01/01/1999'),
 (1234, 'U', '2 place bordillon, Angers, 4900'),
 '11/21/2026',
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

-- 6
drop function nb_no_action();
create function nb_no_action() returns integer as
$$
DECLARE
BEGIN
    return (select count(*) from salarie as s where (s.personne, s.societe) not in (select personne, societe from action ));
    
END;
$$ LANGUAGE 'plpgsql';


-- 7
drop function soc_salarie_actio();
create function soc_salarie_actio()
returns table(nomSoc varchar(50), annee integer) as
$$
DECLARE
BEGIN
    return query(
    select (h.societe).nomsoc, h.annee
    from histo_annuel_actionnaire h
    where not exists (
        select h2.societe, h2.annee
        from histo_annuel_actionnaire h2
        where h.societe = h2.societe AND
        h.annee = h2.annee AND
        h2.personne not in 
        (
            select personne from salarie s
            where s.societe = h2.societe
        )
    ));
END;
$$ LANGUAGE 'plpgsql';


-- 8
-- Écrire une fonction qui prend en paramètre une société et affiche 
-- l'année durant laquelle il y avait le plus de salariés actionnaires

drop function annee_most_sala(societe_t);
create function annee_most_sala(soc societe_t)
returns table(annee integer) as
$$
DECLARE
BEGIN
    return query (
        select h.annee from histo_annuel_actionnaire h
        where h.societe = soc AND h.personne IN (
            select personne from salarie s where s.societe = soc
        )
        group by h.annee 
        order by h.annee DESC
        LIMIT 1
        
    );
END;
$$ LANGUAGE 'plpgsql';


-- 9
drop function most_action(integer);
create function most_action(a integer)
returns table(personnes varchar) as
$$
DECLARE
BEGIN
    return query (
        select (h.personne).nom from histo_annuel_actionnaire h
        where h.annee = a
        group by h.personne 
        order by SUM(h.nbracttotal) = (
            select SUM(h.nbracttotal) from histo_annuel_actionnaire h
            where h.annee = a
            group by h.personne 
            order by SUM(h.nbracttotal)
            LIMIT 1
        )
        
    );
END;
$$ LANGUAGE 'plpgsql';


drop function no_more_than_3_proc();
create function no_more_than_3_proc()
returns trigger as
$$
DECLARE
BEGIN

    IF NEW.societe NOT IN 
        (
            select h.societe
            from histo_annuel_actionnaire h
            where h.personne = NEW.personne
            AND h.annee = EXTRACT(YEAR FROM NEW.dateAct)
        )
        AND
        (
            select count(*)
            from histo_annuel_actionnaire h
            where h.personne = NEW.personne
            AND h.annee = EXTRACT(YEAR FROM NEW.dateAct)
        ) >=3
    THEN
        return NULL;
    END IF;
    return NEW;
END;
$$ LANGUAGE 'plpgsql';

create trigger no_more_than_3
before insert or update on action
    for each row execute PROCEDURE
        no_more_than_3_proc();
