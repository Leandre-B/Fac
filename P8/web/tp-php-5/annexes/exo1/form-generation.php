<?php 
    require_once("form-generation.inc.php");
?>

<!DOCTYPE html>
<html>
<head>
<title>TP PHP 5.1 - Génération de formulaire</title>
</head>
<body>
<?php
    echo ouverture("traiter.php");                      echo "<br>";
    echo text("Votre nom", "prenom");                   echo "<br>";
    echo text("Votre prenommmm UwU", "nom");            echo "<br>";
    echo radio("Chat meow :3", "animal", "chat");      echo "<br>";
    echo radio("Chien Wouf wouf", "animal", "chien");   echo "<br>";
    echo submit("submit", "reset");                     echo "<br>";
    fermeture();                                        echo "<br>";
?>
 </body>
</html>
