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
$file = __DIR__."/etudiants.csv";
$separator = ";";
$enclosure = "\""; // !! fputscsv n'encadrera que les champs comportant espaces, tabs ou l'un des 3 caractères réservés
$escape = "";
$eol = PHP_EOL; // caractère de saut de ligne dépendant de l'OS ("\n" Linux/MacOS, "\r\n" Windows)
//ENREGISTREMENT
if(isset($_POST['envoi'])) {
    if(isset($_POST['nom']) && isset($_POST['prenom']) && isset($_POST['groupe'])) {
        $nom = trim($_POST['nom']);
        $prenom = trim($_POST['prenom']);
        $groupe = $_POST['groupe'];
        $rec = [$nom, $prenom, $groupe];
        if(file_exists($file) ) {
            if( ($stream=fopen($file,"a")) && flock($stream,LOCK_EX) ) {
                fputcsv($stream, $rec, $separator, $enclosure, $escape, $eol);
                flock($stream,LOCK_UN);
                fclose($stream);
                echo "<h3>",ucwords(strtolower($prenom))," ", ucwords(strtolower($nom))," : vous êtes inscrits dans le groupe ".$groupe."</h3>";
            } else {
                echo "Impossible d'ajouter des données au fichier !";
            }
        } else {
            if( ($stream=fopen($file,"w")) && flock($stream,LOCK_SH) ) {
                fputcsv( $stream, ["NOM", "PRENOM", "GROUPE"], $separator, $enclosure, $escape, $eol );
                fputcsv( $stream, $rec, $separator, $enclosure, $escape, $eol );
                flock($stream,LOCK_UN);
                fclose($stream);
            } else {
                echo "Impossible de créer le fichier !";
            }
        }
    }
}
//LECTURE DES DONNEES
if(isset($_POST['affiche'])) {
    if( ($stream=fopen($file,"r")) && flock( $stream, LOCK_EX )) {
        echo "<table border=\"2\"><tbody>";
        $tab = fgetcsv( $stream, null, $separator, $enclosure, $escape );
        echo "<thead><tr><th>" . implode("</th><th>", $tab) . "</th></tr></thead>";
        $i = 1;
        while( $tab = fgetcsv($stream, null, $separator, $enclosure, $escape) ) {
                $nom = $tab[0];
                $prenom = $tab[1];
                $groupe = $tab[2];
                $email = str_replace(" ","-",strtolower($prenom)) . "." . str_replace(" ","-", strtolower($nom)) . "@univ-angers.fr";
                echo "<tr><td>$i</td><td><a href=\"mailto: $email\" >$nom</a></td><td>$prenom</td><td>$groupe</td></tr>";
                $i++;
        }
        flock($stream,LOCK_UN);
        fclose($stream);
        echo "</tbody></table>";
    }
}
?>
</body>
</html>
