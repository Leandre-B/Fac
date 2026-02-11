<?php
require("tabEmployees.php");

$ageMoyen = 0;// Age moyen des employés
$salaireMoyen = 0; // Salaire moyen des plus de 55 ans

$tenRichest = array(); // Tableau contenant les 10 employés ayant le plus haut salaire

// TODO
// Q1 : age moyen de tous les employés


// TODO
// Q2 : salaire moyen des employés de plus de 55 ans


// TODO
// Q3 : Les 10 plus haut salaire
// Exemple : $tenRichest = ["Oren Dudley (9985 €)", "Jerome Flynn (9881 €)", ...]



// Affichage des 3 variables remplies dans les réponses aux questions 1 à 3
echo "<p>Age moyen des employés : ".round($ageMoyen,2)." ans</p>";
echo "<p>Salaire moyen des employés de plus de 55 ans : ".round($salaireMoyen,2)." €</p>";
echo "<p>Top 10 des plus haut salaire : <ol>";
foreach($tenRichest as $e) echo "<li>$e</li>";
echo "</ol></p>";
?>
