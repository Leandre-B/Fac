<?php

require_once __DIR__ . '/data/questions.php';

/**
 * Extrait $n$ éléments du tableau de questions défini dans ./data/questions.php.
 * L'extraction dépend du paramètre $n :
 * - si $n est un entier, $n questions sont tirées aléatoirement dans le tableau,
 * - si $n est un tableau d'entiers, ces entiers correspondent aux numéros des questions à extraire.
 * 
 * NB. La fonction ne gère pas les erreurs résultant d'un type ou d'une valeur incorrecte pour $n 
 * (p. ex. chaîne, entier ou tableau ne correspondant pas à des numéros valides). 
 * 
 * L'extraction renvoie le tableau des questions sélectionnées en préservant les indices (numéros).
 * Exemple de tableau renvoyé pour $n=[1,5] :
 *
 * Array
 * (
 *  [1] => Que fait l'instruction <code>include('file.php');</code> si <code>file.php</code> n'existe pas ?
 *  [5] => <code>$x =''; var_dump(empty($x));</code>
 * )
 *
 * @param int|int[] $n Nombre de questions à tirer aléatoirement ou tableau des numéros de
 * questions à extraire.
 * @return string[] Un tableau dont chaque élément associe l'énoncé d'une question à son numéro.
 **/
function questions( $n ): array
    {
    // QUESTION 1
    // A COMPLETER

    }
?>