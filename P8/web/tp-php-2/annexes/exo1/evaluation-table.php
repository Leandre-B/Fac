<!DOCTYPE html>
<html lang="fr">
<head>
<meta charset="UTF-8"/>
<title>TP PHP 2.1 - Egalité et conversion</title>
<style>
        th {
            background-color: cyan;
        }

        th,
        td {
            border: 1px solid;
        }

        table {
            text-align: left;
            border: 2px solid;
            border-collapse: collapse;
        }
</style>
</head>
<body>
<?php
    $val = [
        "TRUE" => TRUE,
        "FALSE" => FALSE,
        "1" =>1,
        "0" =>0,
        "-1" =>-1,
        "\"1\"" => "1",
        "\"0\"" => "0",
        "\"-1\"" => "-1",
        "NULL" => NULL,
        "[]" => [],
        "\"\"" => ""
    ];

    $tabComparaison = [];
    foreach($val as $k1=>$v1){
        $ligne = [];
        foreach($val as $k2=>$v2){
            $ligne[$k2] = ($v1 == $v2);
        }
        $tabComparaison[$k1] = $ligne;
    }

    echo "<table>";
    echo "<th>==";
    foreach($tabComparaison as $k1=>$l){
        echo "<th>$k1";
    }
    foreach($tabComparaison as $k1=>$l){
        echo "<tr>";
        echo "<th>$k1";
        foreach($l as $k2=>$v){
            echo "<td>";
            if($v)
                echo "TRUE";
        }
    }
?>
</body>
</html>
