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


        if(!file_exists("employees.csv")) {
            fopen("employees.csv", "w");
            chmod("employees.csv", 0644);
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
            

        // Ecriture 
        if(isset($_POST["nom"], $_POST["salaire"], $_POST["age"])) {

            $f_content=file_get_contents("employees.csv");
            preg_match("/*;".$_POST["nom"].";*;".$_POST["age"]."/", $f_content, $match);
            print_r($match);
            echo "match ", $match;
            file_put_contents("employees.csv",
                $linecount.";".$_POST["nom"].";".$_POST["salaire"].";".$_POST["age"]."\n",
                FILE_APPEND | LOCK_EX
            );

        }

        $file = fopen("employees.csv", "r");
        // Lecture
        echo "<table>";
        $linecount = 0;
        while(!feof($file)){
            $line = fgets($file);
            $infos = explode(";", $line);
            if($linecount == 0){
                echo "<thead>";
            }else {
                echo "<tr>";
            }foreach ($infos as $i) {
                echo "<td>".$i."</td>";
            }
            
            if($linecount == 0){
                echo "</thead>";
            }else {
                echo "</tr>";
            }


            $linecount++;
        }

        echo "</table>";

        fclose($file);



    ?>
    </body>
</html>
