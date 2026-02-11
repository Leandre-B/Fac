<?php
/**
 * Convertit les caractères réservés de HTML (& " ' < >) apparaissant dans la chaîne passée en paramètre
 * en entités HTML en laissant inchangées les sous-chaînes <code> et </code> si elles y figurent 
 * et renvoie la chaîne résultat.
 *
 * Exemples de conversion :
 *
 * Que fait l'instruction <code>include('file.php');</code> si <code>file.php</code> n'existe pas ?
 * =>
 * Que fait l&#039;instruction <code>include(&#039;file.php&#039;);</code> si <code>file.php</code> n&#039;existe pas ?
 *
 * <code>echo 234 <=> 123;</code>
 * =>
 * <code>echo 234 &lt;=&gt; 123;</code>
 *
 * @param string $statement La chaîne à convertir.
 * @return string La chaîne convertie.
 **/
function encodeStatement( string $statement ) : string
    {
    // QUESTION 3
    // A COMPLETER

    }
?>