
<?php
    include("connexpdo.inc.php");
    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $pdo = connexpdo("l2_sportifs");
        $nom = $_POST["nom"];
        $prenom = $_POST["prenom"];
        $mail = $_POST["mail"];
        $departement = $_POST["departement"];
        
        $qry = "INSERT INTO personne (nom , mail, prenom, depart) VALUES
            (?, ?, ?, ?) 	 
        ";
        $prep = $pdo->prepare($qry);
        $data = array($nom, $prenom, $mail, $departement);
        
        try{
            $prep->execute($data);
            echo("<script> alert(\"Inscription réussi ! \")</script>");
        }catch(PDOException){
            echo("<script> alert(\"Valeurs invalides\")</script>");
        }
    }

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Formulaire</title>
</head>
<body>
    <form action="<?= $_SERVER["PHP_SELF"] ?>" method="post">
        <fieldset>
            <legend> Formulaire d'inscription</legend>
            <label>Nom</label>
            <input name="nom" type="text">
            <br>

            <label>Prenom</label>
            <input name="prenom" type="text">
            <br>

            <label>Département</label>
            <input name="departement" type="number" min="0" max="95">
            <br>

            <label>Mail</label>
            <input name="mail" type="email" min="0" max="95">
            <br>

            <input type="submit" value="Envoyer">

        </fieldset>
    </form>
</body>
</html>
