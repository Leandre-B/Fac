<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <title>Historique apt</title>
    <style>
        .code{ color: blue; font-family: 'Courier New', Courier, monospace;}
        body{display: block;}
        h1{color: blueviolet; text-align: center;}
        div{ border: 2px solid blueviolet; margin: 8px auto; border-radius: 10px; background-color: rgba(138, 43, 223, 0.1); padding: 8px;}
        div>h2 {color: blueviolet; text-align: center;}
        table{ margin-right: 10px; margin-left: 8px;}
        th{ white-space: nowrap; vertical-align: text-top; text-align: right;}
    </style>
</head>
<body>
    <h1>Historique <span class="code">apt</span></h1>
    <?php
    // Partie 1 : fichier -> $logs (array)
    $i=0;
    $handle = fopen("history.log", "r");
    if (! $handle)
        die("Echec de l’ouverture du fichier");
    if (flock($handle, LOCK_SH)) { // verrou partagé en lecture
        while ( ($ligne = fgets($handle)) !== FALSE ){
            if($ligne!="\n"){
                $v=explode(": ", $ligne);
                array_push($logs[$i],array($v[0]=>$v[1]));
            }else{

                $i+=1;
                $ligne = fgets($handle);
                $v=explode(": ", $ligne);
                $logs[$i]=array($v[0]=>$v[1]);
            }

        }
    } else
        echo "Impossible de verrouiller l’accès";
    fclose( $handle );

    // Partie 2 : affichage HTML de $logs (array)
    // Si la partie 1 n'est pas réussie décommenter la ligne suivante (require) afin d'utiliser un tableau $logs fonctionnel
    // require("logs.php");

    foreach($logs as $k=>$v){
        echo "<div>";
        echo "<h2>";
        echo $v["Start-Date"];
        echo "</h2>";

        echo "<table>";
        echo "<tbody>";

        //------------
        $key=array("Commandline", "Requested-By", "Upgrade", "End-Date");
        print_r($v);
        $index=1;
        foreach($key as $vk){
            echo "<tr>";
            echo "<td>";
            echo $vk.":";
            echo "</td>";
            echo "<td>";
            if(array_key_exists($vk[$index], $v)){
                echo $v[$vk];
                $index+=1;    
            }
            else
                echo "nothing";
            echo "</td>";
            echo "</tr>";
        }

        echo "</tbody>";
        echo "</table>";

        echo "</div>";
    }
   
    ?>
</body>
</html>
