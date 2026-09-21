-- Logiciel : nlog, nomLog, dateAch, version, typeLog,prix, nbInstal
-- Installer : nposte, nLog, numIns, dateIns, delai

DROP TABLE Logiciel;
CREATE TABLE Logiciel (
    nlog INTEGER, 
    nomLog VARCHAR(50),
    dateAch DATE,
    version VARCHAR(50),
    typeLog VARCHAR(50),
    prix FLOAT,
    nbInstal INTEGER,

    PRIMARY KEY (nlog)

);

INSERT INTO Logiciel VALUES
    (1, 'Kate', '2003-09-10', '2.4', 'IDE', 9.80, 100),
    (4, 'Mulvad', '2010-12-09', '1.0', 'VPN', 1, 3),
    (5, 'Minecraft', '2000-12-25', '1.16.1', 'jeux', 20, 20); 

DROP TABLE Installer;
CREATE TABLE Installer (
    nposte INTEGER, 
    nLog INTEGER,
    numIns INTEGER,
    dateIns DATE,
    delai INTEGER,

    PRIMARY KEY (nposte, nLog)

);

INSERT INTO Installer VALUES
    (4, 4, 6 , '1999-01-09', NULL),
    (1, 5, 5 , '2000-12-26', NULL);


DROP FUNCTION CalculTemps;
CREATE FUNCTION CalculTemps()
    RETURNS VOID AS
$$
DECLARE
    curs CURSOR FOR select * from Installer;
    rec RECORD;
    dateAchat DATE;
BEGIN
    OPEN curs;
    LOOP
        FETCH curs INTO rec;
        EXIT WHEN NOT FOUND;
        SELECT INTO dateAchat dateAch FROM Logiciel WHERE nlog=rec.nlog;
        IF (rec.dateIns < dateAchat) THEN
            RAISE NOTICE
                'Incohérence %i date naze', rec.nposte;
        ELSE IF (rec.dateIns IS NULL OR dateAchat IS NULL) THEN
            RAISE NOTICE
                'Date(s) NULL';
        ELSE
            UPDATE Installer SET delai = (rec.dateIns - dateAchat)
            WHERE CURRENT OF curs;
            RAISE NOTICE
            'Mofication OK';
        END IF;
        END IF;

    END LOOP;
END;

$$ LANGUAGE 'plpgsql';
SELECT CalculTemps();   


-- Salle : nsalle, nomSalle, nbPoste, indIP
-- Poste : nposte, nomPoste, typePoste, nsalle, nblog
-- Segment : indIP, nomSegment, nbPoste

-- DROP TABLE Segment;
-- CREATE table Segment (
--     indIP INTEGER, 
--     nomSegment varchar(50),
--     nbPoste INTEGER,
-- )

DROP TABLE Salle;
CREATE TABLE Salle (
    nsalle INTEGER,
    nomSalle VARCHAR(50),
    nbPoste INTEGER,
    indIP INTEGER,

    PRIMARY KEY (nsalle)
);
insert into Salle VALUES
    (10, 'salle a', 30, 10),
    (23, 'salle b', 10, 10),
    (14, 'salle c', 20, 9);

DROP TABLE Poste;
CREATE TABLE Poste (
    nposte INTEGER,
    nomPoste VARCHAR(50),
    typePoste VARCHAR(50),
    nsalle INTEGER,
    nblog INTEGER,

    PRIMARY KEY (nposte)
);
insert into Poste values
    (1, 'Arch', 'linux', 10, 2),
    (2, 'Debian', 'linux', 23, 1),
    (3, 'Pop-OS', 'linux', 14, 1);

-- Segment : indIP, nomSegment, nbPoste
-- drop table Segment;
-- CREATE table Segment (
--     indIP INTEGER,
--     nomSegment varchar(50), 
--     nbPoste INTEGER
-- );


drop function installerLogSeg;
CREATE function installerLogSeg(
    ip INTEGER,
    nlogiciel INTEGER, 
    nomLog VARCHAR(50),
    dateAch DATE,
    version VARCHAR(50),
    typeLogiciel VARCHAR(50),
    prix FLOAT)
RETURNS VOID AS
$$
DECLARE
    curs CURSOR FOR 
        select * from Poste
        where nsalle IN (
            SELECT nsalle FROM Salle WHERE indIP = ip
        );
    rec RECORD;
    n INTEGER;
BEGIN

    IF EXISTS (select * from Logiciel where nlog = nlogiciel) THEN
        RAISE NOTICE 'Logiciel existe déjà';
        RETURN;
    END IF;

    IF NOT EXISTS (select * FROM Salle WHERE indIP = ip) THEN
        RAISE NOTICE 'IP inconnue';
        RETURN;
    END IF;

    IF NOT EXISTS (select * FROM Logiciel WHERE typeLogiciel IN (select typeLog FROM Logiciel)) THEN
        RAISE NOTICE 'Type logiciel inconnue';
        RETURN;
    END IF;



    n:=0;
    OPEN curs;
    LOOP
        FETCH curs INTO rec;
        EXIT WHEN NOT FOUND;
        insert into Installer values
            (nlogiciel, rec.nposte, 9999, NOW(), NULL);
        
        
        UPDATE Poste Set nblog = nblog+1 where nposte = rec.nposte;
        n:= n+1;

    END LOOP;
    close curs;
    INSERT INTO Logiciel VALUES
        (nlogiciel, nomLog, dateAch, version, typeLogiciel, prix, n);

END;
$$ LANGUAGE 'plpgsql';

SELECT installerLogSeg(10, 10, 'SAS', '1990-05-09', '9.9', 'jeux', 999.9);
select CalculTemps();


drop function updateLogiciel();
create function updateLogiciel()
    returns TRIGGER as
$$
DECLARE
BEGIN
    IF TG_OP = 'INSERT' THEN
        UPDATE poste set nblog = nblog+1 where nposte = NEW.nposte;
        UPDATE Logiciel set nbInstal = nbInstal+1 where nLog = NEW.nLog;
        RETURN NEW;
    ELSE IF TG_OP = 'DELETE' THEN
        UPDATE poste set nblog = nblog-1 where nposte = OLD.nposte;
        UPDATE Logiciel set nbInstal = nbInstal-1 where nLog = OLD.nLog;
        RETURN OLD;
    END IF;
    END IF;


END;
$$ LANGUAGE 'plpgsql';

-- màj de nbLog de la table Poste, et nbInstall de la table Logiciel
create trigger Trig_apres_DI_installer
    AFTER INSERT OR UPDATE OR DELETE  
        on Installer
    FOR EACH ROW
        EXECUTE PROCEDURE updateLogiciel();
    

-- Écrire le déclencheurs Trig_Après_DI_Poste sur la table Poste
-- permettant de mettre à jour automatique la colonne nbPoste 
-- de la table Salle, à chaque ajout ou suppression d'un nouveau poste

drop function updatePoste();
create function updatePoste()
    returns trigger as
$$
DECLARE
BEGIN

    IF TG_OP = 'INSERT' THEN
        UPDATE salle set nbPoste = nbPoste+1 where nsalle = NEW.nsalle;
        RETURN NEW;
    ELSE IF TG_OP = 'DELETE' THEN
        UPDATE salle set nbPoste = nbPoste-1 where nsalle = OLD.nsalle;
        RETURN OLD;
    END IF;
    END IF;

end;
$$ LANGUAGE 'plpgsql';

CREATE TRIGGER Trig_Après_DI_Poste
    AFTER INSERT OR UPDATE OR DELETE  
        on Poste
    FOR EACH ROW
        EXECUTE PROCEDURE updatePoste();


-- Écrire le déclencheurs Trig_Après_DI_Salle sur la table Salle 
-- permettant de mettre à jour automatique la colonne nbPoste de la 
-- table Segment, après la modification de la colonne nbPoste.

drop function updateSalle();
create function updateSalle()
    returns trigger as
$$
DECLARE
    nb_poste INTEGER;
BEGIN

    IF TG_OP = 'DELETE' THEN
        select into nb_poste COUNT(nposte) 
            from poste
            where nsalle = OLD.nsalle;
        -- RAISE NOTICE 'nb = %', nb_poste;
        DELETE from poste where nsalle = OLD.nsalle;
        -- UPDATE Segment set nbPoste = nbPoste - nb_poste where indIP = OLD.indIP;
        RETURN OLD;
    END IF;

end;
$$ LANGUAGE 'plpgsql';

CREATE TRIGGER Trig_Après_DI_Salle
    AFTER INSERT OR UPDATE OR DELETE  
        on Salle
    FOR EACH ROW
        EXECUTE PROCEDURE updateSalle();