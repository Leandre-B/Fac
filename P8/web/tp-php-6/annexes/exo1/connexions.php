<!DOCTYPE html>
<html lang="fr">
<head>
<meta charset="utf-8" />
<title>TP PHP 6.1 - Fichier de log</title>
</head>
<body>
<?php
    // Définit le fuseau horaire
    date_default_timezone_set('Europe/Brussels');

    // A COMPLETER

    $file=fopen("connex.txt", "a+");
    $t=time();
    $date=date("d/M H:i:s",$t)."\n";
    fwrite($file, $date);

    $file=fopen("connex.txt", "r");
    while ( ($ligne = fgets($file)) !== FALSE ){
			echo $ligne;
            echo "<br>";
    }
?>
</body>
</html>
