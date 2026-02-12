<?php
# Extraction du fichier JSON
$json = file_get_contents("meteorites.json");
$M0 = json_decode($json, true);


# Question 1
# Créer le tableau $M1 en supprimant dans chaque élément du tableau $M0 le sous-tableau de clé "geometry".
# $M0 = [ ..., ['geometry' => [...], 'properties' => [...]], ... ]
# $M1 = [ ..., ['properties' => [...]], ... ]

// A COMPLETER

foreach ($M0 as $k => $v) {
    $aux=$v;
    unset($aux["geometry"]);
    $M1[]=$aux;
}


require_once(__DIR__ . "/solutions/M1.php");
echo 'M1 : ' . (($M1 ?? '') === $M1_solution ? "OK" : "KO") . "<br />";


# Question 2
# Créer le tableau $M2 en remplaçant chaque élément de $M1 qui est un tableau associant la clé 'properties' 
# à un tableau associatif par ce tableau associatif.
# $M1 = [ ..., [['properties' => ['name' => '..', ..., 'id' => '..']], ... ]
# $M2 = [ ..., ['name' => '..', ..., 'id' => '..'], ... ]

// A COMPLETER
foreach ($M1 as $k => $v) {
    $M2[]=$v["properties"];
}


require_once(__DIR__ . "/solutions/M2.php");
echo 'M2 : ' . (($M2 ?? '') === $M2_solution ? "OK" : "KO") . "<br />";


# Question 3
# A partir du tableau $M2, créer le tableau $FR ne contenant que les météorites tombées en France (clé 'country_code' de valeur 'FR').

// A COMPLETER
foreach ($M2 as $k => $v) {
    if($v["country_code"]=="FR"){
        $FR[$k]=$v;
    }
}

require_once(__DIR__ . "/solutions/FR.php");
echo 'FR : ' . (($FR ?? '') === $FR_solution ? "OK" : "KO") . "<br />";


# Question 4
# Trier le tableau $M2 par masse de météorite croissante (clé 'mass_g') et stocker dans la variable $maxMass la masse de la météorite la plus lourde.

// A COMPLETER
function sortMass($a, $b){
    if($a["mass_g"]>$b["mass_g"]){
        return 1;
    }else
        return -1;
}
uasort($M2, "sortMass");
$aux=$M2;
$maxMass=array_pop($aux)["mass_g"];

echo 'maxMass : ' . ($maxMass ?? '') . "<br />";


# Question 5
# Calculer la masse totale en kgs (arrondie à l'entier inférieur) des météorites listées dans $M2 et stocker le résultat dans la variable $totalMass.

// A COMPLETER
$totalMass=0;
foreach ($M2 as $k => $v) {
    $totalMass+=$v["mass_g"];
}
$totalMass=round($totalMass/count($M2), 0);
echo 'totalMass : ' . ($totalMass ?? '') . "<br />";
