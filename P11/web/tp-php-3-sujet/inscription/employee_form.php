<!DOCTYPE html>
<html lang="fr">
    <head>
        <meta charset="utf-8"/>
        <title>TP PHP - Inscription d'employés</title>
    </head>
    <body style="background-color: #ffcc00;">
        <form action="<?php echo $_SERVER['PHP_SELF'] ?>" method="post">
        <fieldset>
            <legend><b>Inscrire un employé</b></legend>
            <label>Nom :&nbsp;&nbsp;&nbsp;&nbsp;</label>
            <input type="text" name="nom" value="" size="30" maxlength="60" required="required"/><br/><br/>
            
            <label>Salaire :&nbsp;</label>
            <input type="number" name="salaire" min="0" max="100000" step="5000" size="6" required="required"/><br/><br/>
            
            <label>Age :&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</label>
            <input type="number" name="age" min="18" max="100" size="6" required="required"/><br/><br/>
            
            <input type="submit" value="Inscrire" name="inscrire" />
            </fieldset>
        </form>
    <?php

        session_start();
        // Création du fichier si n'existe pas + récupération nb lignes
        if(!file_exists("employees.csv")) {
            fopen("employees.csv", "w");
            file_put_contents("employees.csv",
                "ID;NOM;SALAIRE;AGE\n",
                FILE_APPEND | LOCK_EX
            );
            $linecount = 1;
        } else {
            $linecount = -1;
            $handle = fopen("employees.csv", "r");
            while(!feof($handle)){
                $line = fgets($handle);
                $linecount++;
            }

            fclose($handle);
        }
            

        // Ecriture Formulaire dans CSV
        if(isset($_POST["nom"], $_POST["salaire"], $_POST["age"])) {
            if(isset($_SESSION[ $_POST["nom"].$_POST["age"] ])) {
                echo "La personne existe déjà<br>";
            } else {
                $_SESSION[ $_POST["nom"].$_POST["age"] ] = "set";
                $handle = fopen("employees.csv", "a");
                fputcsv($handle,
                    [$linecount, $_POST["nom"], $_POST["salaire"], $_POST["age"]],
                    ";"
                );
                fclose($handle);
            }
        }

        // Génération tableau HTML
        $handle = fopen("employees.csv", "r");
        
        echo "<table style=\"border: solid black;border-collapse: collapse;\">";
        $header = TRUE;
        while( ($data = fgetcsv($handle,0, ";")) !== FALSE){
            echo $header ? "<thead style=\"border: solid black;\">" : "<tr>";

            foreach ($data as $d) {
                echo "<td style=\"border: solid black;\">".$d."</td>";
            }

            echo $header ? "</thead>" : "</tr>";
        }

        echo "</table>";
        fclose($handle);



    ?>
    </body>
</html>
