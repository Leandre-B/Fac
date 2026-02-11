<?php

function fichier_a_tableau($csv) {
    $file=fopen($csv, "r");
    $entete=$ligne = fgetcsv($file, null, ',');
    while(($ligne = fgetcsv($file, null, ',')) !== FALSE){
        $tab_csv[]=array_combine($entete, $ligne);

    }
    return $tab_csv;
}

function nettoyer_email($string) {
    preg_match("/<([^>]*)>/", $string, $result);
    echo $result[1];
    $string=str_replace(';' ,"", $result[1]);
    $string=str_replace('&' ,"", $string);
    $string=str_replace('*' ,"", $string);
    return $string;
}

function generer_html_table_vertical($mails) {
    echo "<table>";
    echo "<tbody>";
    foreach ($mails as $k=>$v) {

        echo "<tr>", "<td>", $k, "</td>", "<td>", $v, "</td>", "</tr>";

    }
    echo "</table>";
    echo "</tbody>";
}


?>
