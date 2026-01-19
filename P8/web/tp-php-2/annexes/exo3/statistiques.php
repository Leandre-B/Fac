<!DOCTYPE html>
<html lang="fr">
<head>
<meta charset="UTF-8"/>
<title>TP PHP 2.3 - Statistiques</title>
<style type="text/css">
    div {position:fixed; top:10px; left:50%; border:1px black solid;}
    .hautsalaire {background-color:orange;}
    .bassalaire {background-color:lightblue;}
</style>
<body>
<?php
require("tabEmployees.php");

$ageMoyen = 0;// Age moyen des employés
foreach($employees as $k=>$v){
    $ageMoyen = $ageMoyen + $v["age"];
}
$ageMoyen = $ageMoyen/count($employees);

function sort_age($a, $b){
    return $a["age"]<$b["age"];
}
usort($employees, "sort_age");


$salaireMoyen = 0; // Salaire moyen des plus de 55 ans
$nb_plus50 = 0;
foreach($employees as $emp){
    if($emp["age"]<50)
        break;
    $nb_plus50 ++;
    $salaireMoyen = $salaireMoyen + $emp["salary"];
}
$salaireMoyen = $salaireMoyen/$nb_plus50;

$tenRichest = array(); // Tableau contenant les 10 employés ayant le plus haut salaire
function sort_salary($a, $b){
    return $a["salary"]<$b["salary"];
}
usort($employees, "sort_salary");

for($i=0; $i<10; $i++){
    $tenRichest[] = $employees[$i]["name"]." (".$employees[$i]["salary"].")";
}


// A COMPLETER
// Q1 : age moyen de tous les employés

// Q2 : salaire moyen des employés de plus de 55 ans

// Q3 : Les 10 plus haut salaire
// Exemple : $tenRichest = ["Oren Dudley (9985 €)", "Jerome Flynn (9881 €)", ...]


// Affichage des 3 variables remplies dans les réponses aux questions 1 à 3
echo "<p>Age moyen des employés : ".round($ageMoyen,2)." ans</p>";
echo "<p>Salaire moyen des employés de plus de 55 ans : ".round($salaireMoyen,2)." €</p>";
echo "<p>Top 10 des plus haut salaire : <ol>";
foreach($tenRichest as $e) echo "<li>$e</li>";
echo "</ol></p>";
?>
</body>
</html>
