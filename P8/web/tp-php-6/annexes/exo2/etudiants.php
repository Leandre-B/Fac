<!DOCTYPE html>
<html lang="fr">
    <head>
        <meta charset="utf-8"/>
        <title>TP PHP 6.2 - Formulaire d'inscription étudiants</title>
    </head>
    <body style="background-color: #ffcc00;">
        <form action="<?php echo $_SERVER['PHP_SELF'] ?>" method="post">
            <fieldset>
                <legend><b>Inscrivez-vous ou affichez la liste des étudiants</b></legend>
                <label>Nom :&nbsp;&nbsp;&nbsp;&nbsp;</label>
                <input type="text" name="nom" value="Didact" size=30/><br/><br/>
                <label>Prénom : </label>
                <input type="text" name="prenom" value="Otto" size=30/><br/><br/>
                <label>Groupe :&nbsp;</label>
                <select name="groupe"  required="required">
                <option value="I1" selected="selected">I1</option>
                <option value="I2">I2</option>
                <option value="I3">I3</option>
                <option value="I4">I4</option>
                <option value="I5">I5</option>
                <option value="I6">I6</option>
                </select><br/><br/>
                <input type="submit" value="S'inscrire" name="envoi" />
                <input type="submit" value="Lister" name="affiche" />
            </fieldset>
        </form>
        <?php
            if(isset($_POST["envoi"]) && isset($_POST["nom"]) && isset($_POST["prenom"])){
                $nom=($_POST["nom"]);
                $prenom=($_POST["prenom"]);
                $groupe=($_POST["groupe"]);
                $file=fopen("etudiants.csv", "a");
                fputcsv($file, [$nom, $prenom, $groupe], ';');
                fclose($file);

            }

            $affiche=isset($_POST["affiche"]);
            if($affiche){
                $file=fopen("etudiants.csv", "r+");
                $csv=[];
                while ( ($ligne = fgetcsv($file, null,";", '"')) !== FALSE ){
                    $csv[]=$ligne;
                }
                echo "<table>";
                echo "<thead>";
                echo "<tr>";
                echo "<th>";
                    echo "ID";
                    echo "</th>";
                foreach($csv[0] as $l){
                    echo "<th>";
                    echo $l;
                    echo "</th>";
                }
                echo "</tr>";
                echo "</thead>";
                echo "<tbody>";
                foreach($csv as $k=>$v){
                    echo "<tr>";
                    if($k!=0){
                        echo "<td>";
                        echo $k;
                        echo "</td>";
                        foreach($v as $k2=>$v2){
                            echo "<td>";
                            if($k2==0){
                                echo "<a href=\"mailto:$v[1].$v2@etud.univ-angers.fr\">";
                            }
                            echo $v2;
                            echo "</td>";
                        }
                    }
                    echo "</tr>";
                }
                echo "</tbody>";
                echo "</table>";
            }

        ?>
    </body>
</html>
