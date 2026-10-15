<?php
// Création du tableau [..., "D" => ["Prix" => 22.71,"Taux" => 0.05], ...]




/**
 * renvoie un tableau au format ["Prix" => 22.71,"Taux" => 0.05]
 * où le prix est tiré aléatoirement dans [1,100]
 * et le taux est tiré aléatoirement dans le tableau de taux $tab_taux
 * 
 * NB. $tab_taux est passé en paramètre plutôt qu'utilisé comme une variable globale.
 * Ce qui permet d'utiliser indirectement cette fonction nommée comme fonction de rappel
 * dans les fonctions de type array_*.
 * 
 * return array
 **/
function creer_prix_articles($a, $tab_taux)
{
    global $tva;
    return array("Prix"=>rand(0, 100), "Taux"=>$tab_taux[rand(0, count($tab_taux)-1)]);
}
    
// initialisation de $prix_taux
    
$prix_taux = null;
$tab_taux = array(0.05,0.10,0.20);

$articles = range("A", "K");
$prix_taux = array_fill_keys(
    $articles, 0
);

$prix_taux = array_map("creer_prix_articles", $prix_taux, array_fill(0, count($prix_taux), $tab_taux));
// print_r($prix_taux);
?>