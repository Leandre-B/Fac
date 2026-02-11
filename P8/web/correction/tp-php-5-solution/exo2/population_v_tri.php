<?php
$filename = __DIR__ . "/villes.json";
$villes   = json_decode( file_get_contents( $filename ), true );

function cmp($a, $b)
{
    if ($a["Région"] <=> $b["Région"])
        return $b["Région"] <=> $a["Région"];
    else
        return $b["Population"] <=> $a["Population"];
}

uasort($villes, "cmp");

$str     = <<<HTML
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>TP PHP 5.2 - Villes</title>
<style>
	table { border-collapse: collapse; }
	table, th, tr, td { border: 1px solid black;}
</style>
</head>
<body>
HTML;
$str .= "<table>";
$headers = [ "Nom", "Region", "Population", "Préfecture" ];
$str .= "<tr>" . "<th>" . implode( "</th><th>", $headers ) . "</th>" . "</tr>";
foreach ( $villes as $nom => $infos ) {
    $row = [ $nom, $infos[ "Région" ], $infos[ "Population" ], $infos[ "Préfecture" ] ? "oui" : "non" ];
    $str .= "<tr>" . "<td>" . implode( "</td><td>", $row ) . "</td>" . "</tr>";
    }
$str .= "</table>";
$str .= "</body></html>";
echo $str;
?>
