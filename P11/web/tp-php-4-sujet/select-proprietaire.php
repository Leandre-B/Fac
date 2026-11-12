<?php

require ("connexpdo.inc.php");
require_once ("js.php");

$pdo = connexpdo("voitures");
$qry="SELECT id_pers, nom, prenom FROM proprietaire";
try {
    $stt=$pdo->query($qry);
	$proprietaire=$stt->fetchAll(PDO::FETCH_NUM);
    echo "<label for=\"choix-personne\">Nom & prénom</label> ";
    echo "<select id=\"choix-personne\" name=\"personne\"> ";
    foreach($proprietaire as $p) {
        echo "<option value=\"".$p[0]."\">".$p[1]." ".$p[2]."</option>";
    }

    echo "</select>";
}catch (PDOException $e) {
    // var_dump($e);
    displayException($e);
    console($e->getMessage());
}

?>