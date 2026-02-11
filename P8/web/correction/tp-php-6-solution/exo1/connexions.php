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

// Ecriture des dates
if( ! ($stream = fopen(__DIR__ . "/connex.txt", "a")) ) {
    die("Impossible de créer ou accéder au fichier en écriture");
}
if( ! flock($stream, LOCK_EX) ) { // verrou exclusif
    die( "Impossible d'acquérir un verrou exclusif en écriture" );
}
$date = time();
fwrite($stream, $date . PHP_EOL);
flock($stream, LOCK_UN); // déverrouiller
fclose($stream);

// Lecture des données
if( ! ($stream = fopen(__DIR__ . "/connex.txt", "r"))) {
    die( "Impossible d'accéder au fichier en lecture" );
}
flock($stream, LOCK_SH); // verrou partagé
while ($date = fgets($stream)) {
    $tab[] = $date;
}
// Elimination des doublons
$tabstat = array_values(array_unique($tab));
// Affiche les dates et les heures des connexions
foreach ($tabstat as $valeur) {
    echo date("d/M H:i:s", substr($valeur,0,-1)) . "<br />";
}
flock($stream, LOCK_UN);
fclose($stream);
?>
</body>
</html>
