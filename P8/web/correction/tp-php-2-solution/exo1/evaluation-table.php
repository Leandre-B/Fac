<!DOCTYPE html>
<html lang="fr">
<head>
<meta charset="UTF-8"/>
<title>TP PHP 2.1 - Egalité et conversion</title>
<style>
        th {
            background-color: cyan;
        }

        th,
        td {
            border: 1px solid;
        }

        table {
            text-align: left;
            border: 2px solid;
            border-collapse: collapse;
        }
</style>
</head>
<body>
<?php
// TABLEAU DE COMPARAISON AVEC ==
$v=["TRUE"=>TRUE,
    "FALSE"=>FALSE,
    "1"=>1,
    "0"=>0,
    "-1"=>-1,
    "\"1\""=>"1",
    "\"0\""=>"0",
    "\"-1\""=>"-1",
    "NULL"=>NULL,
    "[]"=>[],
    "\"\""=>""];

function b2s(bool $x) : string {if($x) return "TRUE"; else return "";}

//Début du tableau HTML
echo "<table>";
//Création de la première ligne
echo "<tr>";
echo "<th>==</th>";
foreach($v as $k=>$i) {
    echo "<th>$k</th>";
}
echo "</tr>";
//Création du corps de la table
foreach($v as $k=>$i) {
    echo "<tr>";
    echo "<th>$k</th>";
    foreach($v as $j) {
        echo "<td>".b2s($i==$j)."</td>";
    }
    echo "</tr>";
}
echo "</table>";
?>
</body>
</html>
