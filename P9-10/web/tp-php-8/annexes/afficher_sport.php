<?php

    $nom =  $_GET["nom"];

    include("connexpdo.inc.php");
    $pdo = connexpdo("l2_sportifs");

    $stt = $pdo->query("SELECT DISTINCT nom, prenom, design FROM personne p
                        JOIN pratique pr ON p.id_personne = pr.id_personne
                        JOIN sport s ON pr.id_sport = s.id_sport
                        WHERE nom=\"$nom\"
    ");

    $records = ($stt->fetchAll(PDO::FETCH_ASSOC));

    echo "<table style>";
    echo "<thead>";
    foreach($records[0] as $k => $r){
        echo "<th>".$k;
    }

    foreach($records as $row){
        echo "<tr>";
        foreach($row as $k => $data){
            if($k == "nom"){
                echo "<td><a href=\"afficher_sport.php?nom=".$data."\" >".$data."</a>";
            }else
                echo "<td>".$data;
        }
    }
?>

<style>
table, th , tr,  td{
    border : solid blue 1px;
    border-collapse: collapse;
}
</style>