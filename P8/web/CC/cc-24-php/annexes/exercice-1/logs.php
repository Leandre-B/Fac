<?php
# Exercice 1
require_once("solutions/00_logs_bruts.php");

# Question 1
# Créez le tableau associatif $cpt_logs contenant le nombre de logs pour chaque niveau de criticité (DEBUG,
# ERROR, FATAL, INFO, WARNING), dans l’ordre alphabétique. Les clés du tableau doivent être les niveaux de
# criticité, et les valeurs doivent être le nombre de logs correspondants.

$cpt_logs = ["DEBUG" =>0, "ERROR" =>0, "FATAL" =>0, "INFO" =>0, "WARNING" =>0];

foreach ($logs_bruts as $k=>$v) {
    $cpt_logs[$v[1]]++;
}

//print_r($cpt_logs); 


require_once("solutions/01_cpt_logs.php");
echo $cpt_logs === $cpt_logs_solution ? "Q1 OK\n" : "Q1 KO\n";

# Question 2
# Triez le tableau $logs_bruts et stockez le résultat dans la variable $logs en respectant les règles suivantes :
#   — par ordre croissant de timestamp (au format yyyy-mm-dd HH:MM),
#   — en cas d’égalité, par ordre alphabétique du niveau de criticité.


# A COMPLETER

function sortlog($a, $b){
    if($a[0]>$b[0])
        return 1;
    if($a[0]<$b[0])
        return -1;
    else{
        if($a[1]>$b[1])
            return 1;
        if($a[1]<$b[1])
            return -1;
        else 
            return 0;
    }
}
$logs=$logs_bruts;
usort($logs, "sortlog");

//print_r($logs);

echo '<br>';
require_once("solutions/02_logs.php");
echo $logs === $logs_solution ? "Q2 OK" : "Q2 KO";

# Question 3
# À partir du tableau trié $logs, stockez dans la variable $premier_debug le premier log de niveau DEBUG.

$premier_debug = [];
# A COMPLETER
foreach ($logs as $k=>$v){
    if($v[1]=="DEBUG"){
        $premier_debug=$v;
        break;
    }
}


echo '<br>';
require_once("solutions/03_premier_debug.php");
echo $premier_debug === $premier_debug_solution ? "Q3 OK" : "Q3 KO";


# Question 4
# Calculez la longueur moyenne des messages de type ERROR, arrondie à 2 chiffres après la virgule, et stockez le
# résultat dans la variable $avg_len_msg_error

$avg_len_msg_error = 0;
# A COMPLETER
$cpt=0;
foreach ($logs as $k=>$v){
    if($v[1]=="ERROR"){
        $avg_len_msg_error=strlen($v[2])+$avg_len_msg_error;
        $cpt++;
    }
}

$avg_len_msg_error=round($avg_len_msg_error/$cpt, 2);


echo '<br>';
require_once("solutions/04_avg_len_msg_error.php");
echo $avg_len_msg_error === $avg_len_msg_error_solution ? "Q4 OK" : "Q4 KO";

# Question 5
# Créez la variable $cpt_dates contenant le nombre de dates uniques (au format yyyy-mm-dd) ayant au moins
# un log dans le fichier logs.txt.

$cpt_dates = 0;
# A COMPLETER
$date=[];
foreach ($logs as $k=>$v){
    $date[]=substr($v[0], 0, 10);
}
$date=array_unique($date);
$cpt_dates=count($date);


echo '<br>';
require_once("solutions/05_cpt_dates.php");
echo $cpt_dates === $cpt_dates_solution ? "Q5 OK" : "Q5 KO";



# Question bonus
# Reproduisez la variable $logs_bruts dans la variable $mes_logs_bruts à partir du fichier
# logs.txt

$mes_logs_bruts = [];
# A COMPLETER

// Source - https://stackoverflow.com/a/6159705
// Posted by Yanick Rochon
// Retrieved 2026-02-11, License - CC BY-SA 3.0

$lignes = file("logs.txt");

foreach ($lignes as $v){
    $elem[0]=substr($v, 1, 16);

    preg_match("/([A-Z]+:)/",$v,$result[0]);
    $elem[1]=substr($result[0][0], 0, strlen($result[0][0])-1);

    preg_match("/: .*/",$v,$result[0]);
    $elem[2]=substr($result[0][0], 2, strlen($result[0][0])-2);

    $mes_logs_bruts[]=$elem;
}
echo "<br>";
echo "<br>";
echo "<br>";

foreach ($mes_logs_bruts as $k=>$v){
    if ($mes_logs_bruts[$k]!==$logs_bruts[$k]){
        echo $k;
        echo "<br>";
        print_r($mes_logs_bruts[$k]);
        echo "<br>";
        print_r($logs_bruts[$k]);

        echo "<br>";
        echo "<br>";
    }
}
echo $mes_logs_bruts === $logs_bruts ? "Q bonus OK" : "Q bonus KO";
?>