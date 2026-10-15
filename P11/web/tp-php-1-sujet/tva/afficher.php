<?php
// Calcul et génération taxe et coût TTC par article sous forme de ligne de tableau HTML
// $value : valeur de type array d'un élément du tableau $prix_taux
// $key : clé de type string d'un élément du tableau $prix_taux
// $param : paramètre additionnel de type string (couleur de fond CSS)
//
function taxe($value, $key, $param)
{
    $taxe = $value["Prix"] * $value["Taux"];
    $ttc =  $value["Prix"] + $taxe;

    $html = <<<IDF
    <tr> 
        <td> $key </td>
        <td> {$value['Prix']} </td>
        <td> {$value['Taux']} </td>
        <td> $taxe </td>
        <td style="background-color : red"> $ttc </td>
    </tr>
    IDF;
    echo $html;
}

// Génération de tableau HTML
//
function generer_tableau($prix_taux)
{
    echo <<<IDF
        <table>
            <tr>
                <th> Article </td>
                <th> Prix </td>
                <th> <a href=tableau.php> Taux T.V.A. <a> </td>
                <th> Taxe </td>
                <th> Coût TTC </td>
            </tr>
    IDF;
    array_walk($prix_taux, 'taxe', "");
    echo "</table>";
}

// tri du tableau
usort($prix_taux, 
    function($a, $b) {
        if($a["Taux"]<$b["Taux"]) return -1;
        if($a["Taux"]>$b["Taux"]) return 1;
        return $b["Prix"] - $a["Prix"];
    }
);

// Affichage du tableau
generer_tableau($prix_taux);
?>