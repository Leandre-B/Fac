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
function creer_prix_articles($tab_taux)
{}

// initialisation de $prix_taux
$prix_taux = null;
?>