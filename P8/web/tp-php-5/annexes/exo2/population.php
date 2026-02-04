<?php

$str = <<<HTML
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>TP PHP 5.2 - Villes</title>
<style>
	table { border-collapse: collapse; }
	table, th, tr, td { border: 1px solid black;}
HTML;

if ($_GET["couleur"]=="orange"){
	$str.="table {background-color : orange;}";
}
if ($_GET["couleur"]=="blue"){
	$str.="table {background-color : cyan;}";
}

$str .= <<<HTML
	</style>
	</head>
	<body>
HTML;


$json=file_get_contents("villes.json");
$tab = json_decode( $json, true );
echo $str;

$couleur=$_GET["couleur"];
if ($couleur=="orange")
	uasort($tab, "cmp");

echo "<table>";

echo "<thead>";
echo "<tr>";

if ($couleur=="orange")
	echo "<th> <a href=\"population.php?couleur=blue\" > Nom </th>";
else
	echo "<th> <a href=\"population.php?couleur=orange\" > Nom </th>";

echo "<th> Région </th>";
echo "<th> Population </th>";
echo "<th> Préfecture </th>";
echo "</thead>";
echo "</tr>";

foreach ($tab as $k=>$v) {
	echo "<tr>";
	echo "<td>$k</td>";
	foreach ($v as $k2=>$v2) {
		if ($k2=="Préfecture"){
			if($v2)
				echo "<td>oui</td>";
			else
				echo "<td>non</td>";
		}else{
			echo "<td>$v2</td>";
		}
	}
	echo "</tr>";
}
echo "</table>";



function cmp ($a, $b) {
	if ($a["Région"]<$b["Région"]){
		return 1;
	}if ($a["Région"]==$b["Région"]){
		return $a["Population"]<$b["Population"];
	}else
		return -1;
}


?>
