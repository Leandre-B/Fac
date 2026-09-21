
drop type t_elevage cascade;
create type t_elevage as (
    typeanimal varchar(100),
    agemin integer,
    nbrmax integer
);

drop type t_adresse cascade;
create type t_adresse as (
    nrue integer,
    rue varchar(50),
    ville varchar(50),
    code_postal integer
);

create table elevage of t_elevage;

drop table eleveur;
create table eleveur (
    numLicence integer,
    elevage t_elevage,
    adresse t_adresse
);

insert into elevage values
('bovin', 59, 5),
('porcin', 15, 100),
('ovin', 1, 9999),
('volaille', 1, 9),
('dragon', 999999999, 1);

insert into eleveur values
(2, null, row(1, 'laRue', 'Paris', 97351)),
(1, (select a from elevage a where typeanimal='bovin'), null),
(3, (select a from elevage a where typeanimal='ovin'), row(2, 'laRue', 'laVille', 97351));


update eleveur
set elevage = 
    (select e from elevage e
     where (e).typeanimal = 'porcin')
where numLicence = 2;

update eleveur
set adresse.ville = 'Bordeaux', 
    adresse.code_postal = 33000
where (elevage).typeanimal = 'porcin';


update eleveur
set adresse = null
where (adresse).ville = 'Paris';


drop function no_paris_proc();
create function no_paris_proc()
    returns trigger as
$$
DECLARE
BEGIN
    
    IF (NEW.adresse).ville = 'Paris' THEN
        raise notice '"%"', (NEW.adresse).ville;
        return NULL;
    END IF;
    return NEW;
END;
$$ LANGUAGE 'plpgsql';


create trigger no_paris_trig
BEFORE insert OR UPDATE
    on eleveur
    for each row execute PROCEDURE
        no_paris_proc();




update eleveur
set adresse = null
where (elevage).typeanimal = 'volaille';


drop function no_volaille_angers_proc();
create function no_volaille_angers_proc()
    returns trigger as
$$
DECLARE
BEGIN
    
    IF (NEW.elevage).typeanimal = 'volaille' AND
       (NEW.adresse).ville = 'Angers'
     THEN
        return NULL;
    END IF;
    return NEW;
END;
$$ LANGUAGE 'plpgsql';


create trigger no_volaille_angers_trig
BEFORE insert OR UPDATE
    on eleveur
    for each row execute PROCEDURE
        no_volaille_angers_proc();


