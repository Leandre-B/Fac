drop type t_pilote cascade;
create type t_pilote as (
    num_pilote VARCHAR(5),
    nom VARCHAR(50),
    prenom varchar(50)
);
drop type t_passager cascade;
create type t_passager as (
    num_pass VARCHAR(10),
    nom varchar(50),
    prenom varchar(50)
);

drop type t_avion cascade;
create type t_avion as (
    num_avion VARCHAR(10),
    type varchar(50),
    capacite integer
);

drop type t_trajet cascade;
create type t_trajet as (
    villeDepart varchar(50),
    villeArrive varchar(50)
);

drop type t_vol cascade;
create type t_vol as (
    numVol VARCHAR(50),
    pilote t_pilote,
    trajet t_trajet,
    avion t_avion,
    dateVol DATE
);

create table Pilote of t_pilote (
    primary key (num_pilote)
);
create table Passager of t_passager (
    primary key (num_pass)
);
create table Avion of t_avion (
    primary key (num_avion)
);

create table Trajet of t_trajet;
create table Vol of t_vol;

drop table Reservation;
create table Reservation (
    num_res varchar(10),
    passager t_passager,
    vol t_vol,
    num_place varchar(10)
);

insert into pilote values
('P1', 'Dupond', 'Philippe'),
('P2', 'Hamon', 'Elea');

insert into passager values
('PS001', 'Keyes', 'Daniel'),
('PS002', 'Levey', 'Anna');

insert into Avion values
('AV01', 'Boeing 777', 2),
('AV02', 'AirBus A330', 3);

insert into Trajet values
('Paris', 'Nice'),
('Nice', 'Londres');

insert into Vol values
-- ('AF231', ('P1', 'Dupond', 'Philippe'), ('Paris','Nice'), ('AV01', 'Boeing777', 3), '31/03/2021'),
('AF237', ('P2', 'Hamon', 'Eléa'), ('Paris','Nice'), ('AV01', 'Boeing777', 3), '27/03/2021');

insert into Reservation values
-- ('RB27', ('PS002', 'Levey', 'Anna'),NULL, 'A21'),
('RA22', ('PS001', 'Keyes', 'Daniel'),NULL, 'A22');

insert into Vol values
(
    'AF231', 
    (select p from pilote p where num_pilote='P1'),
    (select t from Trajet t where villeDepart='Nice' AND villeArrive='Londres'),
    (select a from Avion a where num_avion='AV01'),
    '31/03/2021'
),
(
    'AF900', 
    (select p from pilote p where num_pilote='P1'),
    (select t from Trajet t where villeDepart='Nice' AND villeArrive='Londres'),
    (select a from Avion a where num_avion='AV01'),
    '30/01/2022'
);


insert into Reservation values
(
    'RB27',
    (select p from passager p where num_pass='PS002'),
    NULL,
    'A21' 
);

--5
update Reservation 
set vol=(select v from vol v where numVol='AF231')
where num_res='RB27';

--6
-- delete from Vol
-- where (pilote).num_pilote = 'P1';
-- Pas de delete dans reservation

-- 7
drop function aff_trajet(plt varchar(10));
create function aff_trajet(plt varchar(10))
returns void as
$$
DECLARE
    curs CURSOR for 
        select * from Vol
        where (pilote).num_pilote = plt;
    rec record;
    nb_traj integer;
    most_recent DATE;
    ville VARCHAR(50);
BEGIN
    nb_traj := 0;
    open curs;
    most_recent := '01/01/1000';
    loop
        fetch curs into rec;
        exit when not found;
        if most_recent < rec.dateVol THEN
            most_recent := rec.dateVol;
            ville = (rec.trajet).villeArrive;
        end if;
            

        nb_traj := nb_traj +1;
    end loop;

    raise notice 'Nombre de trajet : %', nb_traj;
    raise notice 'Date dernier trajet : %', most_recent;
    raise notice 'Ville d arrivé associé : %', ville;
END;

$$ LANGUAGE 'plpgsql';

select aff_trajet('P1');

-- 8
create function most_trajet_ville(ville varchar(50))
returns t_pilote as 
$$
DECLARE
    curs cursor for 
        select * 
        from vol v
        where (v.trajet).villeArrive = ville 
        AND v.dateVol =
            (
                select max(v2.dateVol)
                from vol v2
                where v.pilote = v2.pilote AND
                    (v2.trajet).villeArrive = ville
            );
    best_pilote t_pilote;
    most integer;
    rec record;
BEGIN
    open curs;
    most :=0;
    loop
        fetch curs into rec;
        exit when not found;
        if most < 
            (select count(*) from vol
            where pilote = rec.pilote) then

            most = (select count(*) from vol
            where pilote = rec.pilote);
            best_pilote = rec.pilote;
        end if;

    end loop;
    return best_pilote;
END;
$$ LANGUAGE 'plpgsql';

select * from most_trajet_ville('Nice');

-- 9

drop function verif_vol_proc();
create function verif_vol_proc()
returns trigger as
$$
DECLARE
BEGIN
    IF (NEW.trajet).villeArrive IN (
        select (v.trajet).villeDepart from vol v
    ) THEN
        return NEW;
    end if;
    raise notice 'Pas de vol retour pour %!', (NEW.trajet).villeArrive;
    return NULL;
END;
$$ LANGUAGE 'plpgsql';

create trigger verif_vol
    before insert on vol
    for each row execute PROCEDURE 
        verif_vol_proc();

insert into Vol values
(
    'AF231', 
    (select p from pilote p where num_pilote='P1'),
    ('Nice', 'Nantes'),
    (select a from Avion a where num_avion='AV01'),
    '31/03/2021'
);

-- 10
drop function verif_maj_num_avion_proc();
create function verif_maj_num_avion_proc()
returns trigger as
$$
DECLARE
    nb_reserv integer;
BEGIN
    select into nb_reserv count(*) 
    from reservation r
    where r.vol = OLD;

    IF nb_reserv > 
        (select a.capacite
        from avion a
        where a.num_avion = (NEW.avion).num_avion) THEN

        raise notice 'pas assez de place dans l avion %',(NEW.avion).num_avion; 
        return NULL;
    end if;
    return NEW; 
END;
$$ LANGUAGE 'plpgsql';


create trigger verif_maj_num_avion
    before update on vol
    for each row execute PROCEDURE
        verif_maj_num_avion_proc();

insert into Reservation values
(
    'RA20',
    (select p from passager p where num_pass='PS002'),
    (select v from vol v where numVol='AF900'),
    'A20' 
),
(
    'RA21',
    (select p from passager p where num_pass='PS002'),
    (select v from vol v where numVol='AF900'),
    'A21' 
);


update vol
set avion =  ('AV01','Boeing 900000',2)
where numVol = 'AF900';


drop function f(n VARCHAR(50));

create function f(n varchar(50))
returns t_avion as
$$
DECLARE
    av t_avion;
BEGIN
    -- OK
    -- return (select avion from vol v
    -- where numVol = n);

    select into av v.avion from vol v
        where v.numVol = n;
    return av;
END;

$$ LANGUAGE 'plpgsql';

select * from f('AF900');