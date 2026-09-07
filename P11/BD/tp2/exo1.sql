drop table produit;
CREATE TABLE produit (

    numproduit INTEGER,
    Designation VARCHAR(100),
    Prix FLOAT,
    quantite INTEGER,

    PRIMARY KEY (numproduit)

);

INSERT INTO produit VALUES
    (0, 'oeuf', 40, 4),
    (1, 'patate', 1, 1000),
    (2, 'tomate', 402, 8),
    (4, 'parasole', NULL, 0);

drop function exo1;
drop table produit2;
CREATE FUNCTION exo1()
RETURNS void AS
$$

DECLARE
curs CURSOR FOR SELECT * FROM produit;  
rec RECORD;

BEGIN

CREATE TABLE produit2 (

    numproduit INTEGER,
    Designation VARCHAR(100),
    Prix FLOAT,
    quantite INTEGER,

    PRIMARY KEY (numproduit)

);

OPEN curs;
FETCH curs INTO rec;

IF NOT FOUND THEN
    INSERT INTO produit2 VALUES (0, 'Pas de produit', NULL, NULL);
    RETURN;
ELSE
    LOOP
        rec.Designation = UPPER(rec.Designation);
        IF rec.Prix IS NULL THEN
            rec.Prix = 0;
        END IF;
        
        IF rec.quantite > 50 THEN
            rec.Prix = rec.Prix * 0.3;
        END IF;

        IF rec.quantite < 10 AND rec.prix > 400 THEN
            rec.Prix = rec.Prix * 1.6;
        END IF;
        
        INSERT INTO produit2 VALUES (rec.numproduit, rec. Designation, rec.Prix, rec.quantite);

        FETCH curs INTO rec;
        EXIT WHEN NOT FOUND;
    END LOOP;
END IF;

CLOSE curs;



END;

$$ LANGUAGE 'plpgsql';

SELECT exo1();
select * from produit2;