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

print_r ($_POST['person']);
echo "<br>";
echo "<br>";


// affiche_tableau($_POST['person']);

$stt=$idcom->query("SELECT * from Personne");
$bd_values = [];
$cpt = 0;
while ($record=$stt->fetch(PDO::FETCH_ASSOC)) {
	$bd_values[$cpt] = $record;
	$cpt++;
}
foreach ($bd_values as $key => $value) {
	array_shift($value);
}
affiche_tableau($bd_values);

?>
</body>
</html>
