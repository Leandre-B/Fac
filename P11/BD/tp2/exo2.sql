drop table AVION;
drop table PILOTE;
drop table VOL;


CREATE TABLE AVION(
    AvNum INTEGER, 
    Type INTEGER
);

CREATE TABLE PILOTE(
    PlNum INTEGER, 
    PlNom VARCHAR(100),
    PlPrenom VARCHAR(100)
);

CREATE TABLE VOL(
    VolNum INTEGER,
    PlNum INTEGER ,
    AvNum INTEGER ,
    HeureDep TIME,
    HeureArr TIME
);

INSERT INTO VOL VALUES
    (1, 1, 1, '01:00:00', '10:00:00'),
    (2, 7, 3, '01:00:00', '01:30:00'),
    (3, 5, 4, '01:00:00', '03:00:00'),
    (5, 2, 4, '04:00:00', '10:00:00'),
    (8, 2, 4, '06:00:00', '10:00:00'),
    (4, 2, 4, '01:00:00', '10:00:00');

drop function maj_vol;
CREATE FUNCTION maj_vol()
    RETURNS INTEGER AS
$$

DECLARE
    curs CURSOR FOR select * from VOL;
    rec RECORD;
    tot INTEGER;
BEGIN 
    tot :=0;
    OPEN curs;
    LOOP 
        FETCH curs INTO rec;
        EXIT WHEN NOT FOUND;
        
        IF rec.HeureArr IS NOT NULL AND rec.HeureDep IS NOT NULL AND (rec.HeureArr > rec.HeureDep) THEN
            IF (rec.avnum = 1 OR rec.avnum = 4) THEN
                UPDATE VOL SET HeureArr = HeureArr - (HeureArr - HeureDep )*0.1
                    WHERE CURRENT OF curs ;
                tot := tot + 1;
            ELSE IF (rec.avnum = 2 OR rec.avnum = 8) THEN
                UPDATE VOL SET HeureArr = HeureArr - (HeureArr - HeureDep )*0.15
                    WHERE CURRENT OF curs ;
                tot := tot + 1;
            END IF;
            END IF;
        END IF;
    END LOOP;
    
    CLOSE curs;
    RETURN tot;

END;

$$ LANGUAGE 'plpgsql';

select maj_vol();
select * from VOL;


drop function reduction(INTEGER, NUMERIC);
CREATE FUNCTION reduction(num_avion INTEGER, pourcentage_reduction NUMERIC)
    RETURNS void AS
$$
DECLARE
    curs CURSOR FOR SELECT * FROM VOL WHERE AvNum = num_avion;
    rec RECORD;
BEGIN
    OPEN curs;
    LOOP
        FETCH curs INTO rec;
        EXIT WHEN NOT FOUND;
    
        UPDATE VOL SET HeureArr = HeureArr - (HeureArr - HeureDep )*(pourcentage_reduction/100)
        WHERE CURRENT OF curs;

    END LOOP;

END;
$$ LANGUAGE 'plpgsql';



DROP FUNCTION info_avion(INTEGER);
CREATE FUNCTION info_avion(num_avion INTEGER)
    RETURNS RECORD AS
$$
DECLARE
    tot_vol INTEGER;
    duree_moy TIME;
    duree_tot TIME;
    infos RECORD;
BEGIN
    select into tot_vol COUNT(avnum) FROM VOL WHERE avnum = num_avion;
    select into duree_moy AVG(HeureArr - HeureDep) FROM VOL WHERE avnum = num_avion;
    duree_tot = duree_moy / tot_vol;
    select tot_vol, duree_moy, duree_tot INTO infos;
    

    RETURN infos;

END;
$$ LANGUAGE 'plpgsql';

select info_avion(4);