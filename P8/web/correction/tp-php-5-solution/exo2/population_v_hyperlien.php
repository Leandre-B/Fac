<?php
$filename = __DIR__ . "/villes.json";
$villes   = json_decode( file_get_contents( $filename ), true );

function cmp( $a, $b )
    {
    if ( $a[ "Région" ] <=> $b[ "Région" ] )
        return $b[ "Région" ] <=> $a[ "Région" ];
    else
        return $b[ "Population" ] <=> $a[ "Population" ];
    }

function trier(array &$villes, bool $flag)
{
    function ncmp($a,$b) { return -cmp($a, $b);}
    $flag ? uasort($villes, "cmp") : uasort($villes, "ncmp");
}

if (isset($_GET['orange'])) {
    $clic = "rouge";
    trier($villes, false);
    $bkg = "orange";
} else {
    $clic = "orange";
    trier($villes, true);
    $bkg = "red";
}

$str = <<<HTML
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
$str .= "<table style=\"background-color:$bkg\">";
$str .= "<tr>" . "<th>" . "<a href=\"population_v_hyperlien.php?$clic=1\">Nom</a>" . "</th>" . "<th>" . "Region" . "</th>" . "<th>" . "Population" . "</th>" . "<th>" . "Préfecture" . "</th>" . "</tr>";
foreach ( $villes as $nom => $infos ) {
    $row = [ $nom, $infos[ "Région" ], $infos[ "Population" ], $infos[ "Préfecture" ] ? "oui" : "non" ];
    $str .= "<tr>" . "<td>" . implode( "</td><td>", $row ) . "</td>" . "</tr>";
    }
$str .= "</table>";
$str .= "</body></html>";
echo $str;
?>
