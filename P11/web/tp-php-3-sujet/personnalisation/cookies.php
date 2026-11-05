<!DOCTYPE html>
<html>

<head>
    <meta charset="UTF-8" />
    <title>TP PHP - Personnalisation avec cookies</title>
    <style type="text/css">
        <?php


            $colors = ["background-color" => $_POST["fond"], "color" => $_POST["texte"]];
            foreach ($colors as $k_c => $c) {
                if(isset($c))
                {
                    if($c!="") {
                        setcookie($k_c, $c, time()+10 );
                        echo "body {".$k_c.": ".$c.";}";
                    }else{
                        if(isset($_COOKIE[$k_c])) {
                            echo "body {".$k_c.": ".$c.";}";
                        }
                    }
                }
                else
                {
                    if(isset($_COOKIE[$k_c])) {
                        echo "body {".$k_c.": ".$c.";}";
                    }
                }
            }

        ?>
        legend {
            font-weight: bold;
            font-family: cursive;
        }

        label {
            font-weight: bold;
            font-style: italic;
        }
    </style>
</head>

<body>
    <form method="post" action="cookies.php">
        <fieldset>
            <legend>Choisissez vos couleurs (mot clé ou code)</legend>
            <label>Couleur de fond
                <input type="text" name="fond" />
            </label><br /><br />
            <label>Couleur de texte
                <input type="text" name="texte" />
            </label><br />
            <input type="submit" value="Envoyer" />&nbsp;&nbsp;
            <input type="reset" value="Effacer" />
        </fieldset>
    </form>
</body>

</html>