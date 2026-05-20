<!DOCTYPE html >
<html>
<head>
<meta charset="UTF-8" />
<title>Liste des inscrits</title>
<style type="text/css">
table, th, td {
	border-collapse: collapse;
	border-style: solid;
	border-width: 1px;
	text-align: left;
}

td {
	width: 100px;
}
</style>
</head>
<body>
<?php
require ("connexpdo.inc.php");
require ("afficher-tableau.php");
$idcom = connexpdo("l2_tp_personne");

// A COMPLETER
// $_POST['person'] est le tableau associatif des champs transmis

$new_pesonne = [];
$new_pesonne["GENRE"] 		= $_POST['person']['gender'] == "H" ? "Homme" : "Femme";
$new_pesonne["NOM"] 		= $_POST['person']['lastName'];
$new_pesonne["NOM"] 		= $_POST['person']['firstName'];
$new_pesonne["PRENOM"]	 	= $_POST['person']['lastName'];
$new_pesonne["AGE"] 		= (int)$_POST['person']['age'];
$new_pesonne["LOGIN"] 		= $_POST['person']['login'];
$new_pesonne["MOTDEPASSE"]	= $_POST['person']['password'];
if($_POST['person']["country"] == "us")
	$new_pesonne["PAYS"] = "ETATS-UNIS";
else if($_POST['person']["country"] == "fr")
	$new_pesonne["PAYS"] = "FRANCE";
else if($_POST['person']["country"] == "en")
	$new_pesonne["PAYS"] = "ANGLETERRE";
$new_pesonne["NEWSLETTER"] 	= array_key_exists("news", $_POST) ? 1 : 0;


$stt=$idcom->query("SELECT * from Personne");

$idcom->query("INSERT INTO Personne (ID,GENRE ,NOM ,PRENOM, AGE, LOGIN, MOTDEPASSE, PAYS, NEWSLETTER) VALUE("
	."NULL,'".$new_pesonne["GENRE"]."','".$new_pesonne["NOM"]."','".$new_pesonne["PRENOM"]."',".$new_pesonne["AGE"].",'"
	.$new_pesonne["LOGIN"]."','".
	$new_pesonne["MOTDEPASSE"]."','".$new_pesonne["PAYS"]."',".$new_pesonne["NEWSLETTER"]
	.")");

$personnes=$stt->fetchall(PDO::FETCH_ASSOC);
foreach ($personnes as &$value) {
	array_shift($value); //delete les champs ID
}
array_push($personnes, $new_pesonne);
affiche_tableau($personnes);

echo "<br><a href=\"formulaire.html\" >Retour au formulaire</a>"

?>
</body>
</html>
