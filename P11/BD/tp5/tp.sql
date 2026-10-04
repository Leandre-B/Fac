-- PERSONNE (NumSecu, Nom, Prenom, Sexe, DateNaiss)
drop type t_PERSONNE cascade;
create type t_PERSONNE as (
    NumSecu varchar(50),
    Nom varchar(50),
    Prenom varchar(50),
    Sexe char(1),
    DateNaiss DATE
);

create table PERSONNE of t_PERSONNE 
(primary key (NumSecu));

-- SOCIETE (CodeSoc, NomSoc, Adresse)
drop type t_SOCIETE cascade;
create type t_SOCIETE as (
    CodeSoc varchar(50),
    NomSoc varchar(50),
    Adresse varchar(100)
);

create table SOCIETE of t_SOCIETE
(primary key(CodeSoc));

-- SALARIE (PERSONNE, SOCIETE, Salaire)
drop table SALARIE;
create table SALARIE (
    PERSONNE t_PERSONNE,
    SOCIETE t_SOCIETE,
    Salaire integer
);

-- ACTION(PERSONNE, SOCIETE, dateAct, NbrAct, typeAct)
drop table ACTION;
create table ACTION (
    PERSONNE t_PERSONNE,
    SOCIETE t_SOCIETE,
    dateAct DATE,
    NbrAct integer,
    typeAct varchar,

    constraint c_typeAct check (typeAct = 'achat' OR typeAct = 'vente')
);
-- HISTO_Annuel_ACTIONNAIRE (PERSONNE, SOCIETE, Annee, NbrActTotal, Nbr_Achat,
-- Nbr_vente)

drop table HISTO_Annuel_ACTIONNAIRE;
create table HISTO_Annuel_ACTIONNAIRE (
    PERSONNE t_PERSONNE,
    SOCIETE t_SOCIETE,
    Annee integer,
    NbrActTotal integer,
    Nbr_Achat integer,
    Nbr_vente integer
);

INSERT INTO PERSONNE VALUES
('18506751', 'Dupont', 'Jean', 'M', '1985-06-12'),
('29003159', 'Martin', 'Sophie', 'F', '1990-03-15'),
('17811231', 'Durand', 'Thomas', 'M', '1978-11-23'),
('29507221', 'Bernard', 'Claire', 'F', '1995-07-22');

INSERT INTO SOCIETE
VALUES
('SOC001', 'TechCorp', '10 rue de Paris, Nantes'),
('SOC002', 'InnovData', '25 avenue Victor Hugo, Rennes'),
('SOC003', 'WebSolutions', '5 rue Nationale, Angers');

INSERT INTO SALARIE VALUES
(('18506751', 'Dupont', 'Jean', 'M', '1985-06-12'),
(('SOC001', 'TechCorp', '10 rue de Paris, Nantes'))
, 3200.00
),
(('29003159', 'Martin', 'Sophie', 'F', '1990-03-15'),
(('SOC001', 'TechCorp', '10 rue de Paris, Nantes'))
, 3500.00
),
(('17811231', 'Durand', 'Thomas', 'M', '1978-11-23'),
(('SOC002', 'InnovData', '25 avenue Victor Hugo, Rennes'))
, 2800.00
),
(('29507221', 'Bernard', 'Claire', 'F', '1995-07-22'),
(('SOC002', 'InnovData', '25 avenue Victor Hugo, Rennes'))
, 3000.00
);

drop function maj_histo_proc();
create function maj_histo_proc()
returns trigger as
$$
declare
    curs cursor for
    select * from HISTO_Annuel_ACTIONNAIRE h
    where h.PERSONNE = NEW.PERSONNE AND
          h.SOCIETE = NEW.SOCIETE AND
          h.Annee = EXTRACT(YEAR FROM NEW.dateAct)::integer

    ;

    rec record;
begin
    open curs;
    Loop
        fetch curs into rec;
        exit when not found;
        update HISTO_Annuel_ACTIONNAIRE
        set NbrActTotal = NbrActTotal + NEW.NbrAct
        where current of curs;
        IF NEW.typeAct = 'achat' THEN
            update HISTO_Annuel_ACTIONNAIRE
            set Nbr_Achat = Nbr_Achat + NEW.NbrAct
            where current of curs;
        ELSE IF NEW.typeAct = 'vente' THEN
            update HISTO_Annuel_ACTIONNAIRE
            set Nbr_vente = Nbr_vente + NEW.NbrAct
            where current of curs;
        END IF;
        END IF;
        return NULL;
    end loop;

    IF NEW.typeAct = 'achat' THEN
        insert into HISTO_Annuel_ACTIONNAIRE VALUES
        (NEW.PERSONNE, NEW.SOCIETE, EXTRACT(YEAR FROM NEW.dateAct)::integer,
        NEW.NbrAct, NEW.NbrAct, 0);
    ELSE IF NEW.typeAct = 'vente' THEN
        insert into HISTO_Annuel_ACTIONNAIRE VALUES
        (NEW.PERSONNE, NEW.SOCIETE, EXTRACT(YEAR FROM NEW.dateAct)::integer,
        NEW.NbrAct, 0, NEW.NbrAct);
    END IF;
    END IF;
    return NEW;

end;

$$ language 'plpgsql';


create trigger maj_histo
after insert on ACTION
for each row execute procedure maj_histo_proc();

insert into action values(
('29507221', 'Bernard', 'Claire', 'F', '1995-07-22'),
('SOC001', 'TechCorp', '10 rue de Paris, Nantes'),
'2026-05-20',
100,
'achat'
);

insert into action values(
('29507221', 'Bernard', 'Claire', 'F', '1995-07-22'),
('SOC001', 'TechCorp', '10 rue de Paris, Nantes'),
'2026-05-20',
50,
'vente'
);


drop function check_date_action_proc;
create function check_date_action_proc()
returns trigger as
$$
declare
begin
    IF NEW.dateAct < CURRENT_DATE THEN
        return NULL;
    END if;
    return NEW;
end;
$$ language 'plpgsql';

create trigger check_date_action
before insert OR update on ACTION
for each row execute procedure check_date_action_proc();

insert into action values(
('29507221', 'Bernard', 'Claire', 'F', '1995-07-22'),
('SOC001', 'TechCorp', '10 rue de Paris, Nantes'),
'2027-12-20',
50,
'vente'
);

insert into action values(
('29507221', 'Bernard', 'Claire', 'F', '1995-07-22'),
('SOC002', 'InnovData', '25 avenue Victor Hugo, Rennes'),
'2027-12-20',
50,
'achat'
);

insert into action values(
('18506751', 'Dupont', 'Jean', 'M', '1985-06-12'),
('SOC001', 'TechCorp', '10 rue de Paris, Nantes'),
'2027-12-20',
101,
'vente'
);

drop function f_5;
create function f_5(s varchar(50))
returns setof integer as
$$
declare
    curs cursor for
    select * from HISTO_Annuel_ACTIONNAIRE h
    where (h.SOCIETE).CodeSoc = s;
begin
    for rec in curs loop
        if rec.Nbr_Achat < rec.Nbr_vente THEN
            return next (rec.Annee);
        end if;
    end loop;
    return;
end;

$$ language 'plpgsql';

select * from f_5('SOC001');

drop function f_6();
create function f_6()
returns integer as
$$
declare
    tot integer;
    curs cursor for select * from SALARIE;
begin
    tot := 0;
    for rec in curs loop
         IF EXISTS (
            select h.annee from HISTO_Annuel_ACTIONNAIRE h
            where h.PERSONNE = rec.PERSONNE AND
            h.SOCIETE = rec.SOCIETE) THEN
            tot:= tot+1;
        END IF;
    end loop;
    return tot;
end;
$$ language 'plpgsql';

select * from f_6();


create type t_soc_annee as (
    CodeSoc varchar(50),
    annee integer
);

drop function f_7;
create function f_7()
returns setof t_soc_annee as
$$
declare
    test boolean;
    r t_soc_annee;
    les_hist_a cursor for select SOCIETE, annee from HISTO_Annuel_ACTIONNAIRE;
    les_hist cursor for select * from HISTO_Annuel_ACTIONNAIRE;
begin
    for h_a in les_hist_a loop
        test := true;
        for hist in les_hist loop
            IF hist.annee = h_a.annee AND hist.SOCIETE = h_a.SOCIETE THEN
                IF hist.PERSONNE IN (
                    SELECT s.PERSONNE
                    from SALARIE s
                    where s.SOCIETE != h_a.SOCIETE) THEN    
                test := false;
                END IF;
            END IF;
        end loop;
        if test THEN
            r.annee = h_a.annee; r.CodeSoc = (h_a.SOCIETE).CodeSoc;
            return next r;
        end if;
    end loop;
    return;
end;

$$ language 'plpgsql';

select * from f_7();



drop function f_8;
create function f_8(code varchar(50))
returns integer as
$$
declare
    max integer;
    cur integer;
    best_annee integer;
    curs cursor for select * from HISTO_Annuel_ACTIONNAIRE h
        where (h.SOCIETE).CodeSoc = code;
        
    ans cursor for select h.annee from HISTO_Annuel_ACTIONNAIRE h
        where (h.SOCIETE).CodeSoc = code;
begin
    max := 0;
    cur :=0;
    for an in ans loop
        for rec in curs loop
            IF rec.PERSONNE in (
                select s.PERSONNE from SALARIE s
                where (s.SOCIETE).CodeSoc = code
            ) AND an.annee = rec.annee THEN
                cur := cur+1;
            END IF;
        end loop;
        if cur > max THEN
            max := cur;
            best_annee = an.annee;
        end if;
    end loop;
    return best_annee;
end;
$$ language 'plpgsql';

select * from f_8('SOC001');




-- drop function f_9;
create function f_9(an integer)
returns setof PERSONNE as
$$
declare
    p PERSONNE;
    sort cursor for
        select PERSONNE, sum(NbrActTotal)
        from HISTO_Annuel_ACTIONNAIRE
        where annee = an
        group by PERSONNE
        order by sum(NbrActTotal) DESC;
    max integer;
begin
    max = -1;
    for rec in sort loop
        IF max = -1 THEN
            max = rec.sum;
            return next rec.PERSONNE;
        ELSE IF max = rec.sum then
            return next rec.PERSONNE;
        END IF;
        END IF;

    end loop;
    return;
end;
$$ language 'plpgsql';



drop function verif_3_proc;
create function verif_3_proc()
returns trigger as
$$
declare
begin
    IF (
        select  count(SOCIETE)
        from HISTO_Annuel_ACTIONNAIRE h
        where (h.PERSONNE).NumSecu = (NEW.PERSONNE).NumSecu AND
                h.annee == new.Annee
    ) >=3 then
        return NULL;
    end if;
    return NEW;
end;
$$ language 'plpgsql';

create trigger verif_3
before insert on HISTO_Annuel_ACTIONNAIRE
for each row execute procedure verif_3_proc();
