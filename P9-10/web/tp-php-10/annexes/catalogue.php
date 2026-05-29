<?php

// A COMPLETER: 
// Récupération des données de la bdd
require "connexion.php";
$pdo = etablir_connexion_bdd("l2_music");

$qry="SELECT * FROM album";
$stt=$pdo->query($qry);
$albums = $stt->fetchAll(PDO::FETCH_ASSOC);

$qry="SELECT * FROM song";
$stt=$pdo->query($qry);
$songs = $stt->fetchAll(PDO::FETCH_ASSOC);

?>

<!DOCTYPE html>
<html>

<head>
    <title>Catalogue Musical</title>
    <link rel="stylesheet" href="./utils/style.css">
</head>

<body>
    <div id="nav">
        <h1>Catalogue Musical</h1>
        <form method="post" action="<?php echo $_SERVER['PHP_SELF']; ?>">
            <input type="submit" class="nav-btn" name="voir" value="Voir catalogue">
            <input type="button" class="nav-btn" name="stats" value="Statistiques">
        </form>
    </div>

    <hr>

    <div id="contents">

        <div id="albums">
            <?php
            if(!empty($_POST["voir"])){
                $table =  "
                    <table>
                        <thead>
                        <th> Artiste</th>
                        <th> Album  </th>
                        <th> Année  </th>
                        <th> Action </th>
                ";
                foreach ($albums as $album) {
                    
                    $table .= "</tr>";
                    $table .= "
                        <td> ". $album["artist"] ."</td>
                        <td> ". $album["name"] ."</td>
                        <td> ". $album["year"] ."</td>
                        <td> <input type=\"button\" value=\"Détails\" onclick=afficherAlbumDetails(".$album["id"].",".$album["name"].")> </td>
                    ";
                    $table .= "</tr>";
                }
            }
            echo $table;
            ?>
        </div>

        <div id="songs">
            <h4 id="album-name"></h4>
            <?php
            if(!empty($_POST["voir"])){
                $ol = "<ol>";

                foreach ($songs as $song) {
                    $ol.="<li class=\"".$song["album_id"]."\">". $song["name"] ."(". $song["duration"] .")</li>";
                }
                $ol.="</ol>";
                echo $ol;
            }
            ?>
        </div>

        <script src="stats.js"></script>
        <script src="catalogue.js"></script>
    </div>
</body>

</html>