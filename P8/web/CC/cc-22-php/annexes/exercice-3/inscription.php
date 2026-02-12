<?php
  $club_exclus = ['CDK85', 'ASRennes', 'ABC89', 'AKA95'];
  $categorie_age = [
    'benjamin' => [10,11],
    'minime'   => [12,13],
    'cadet'    => [14,15],
    'junior'   => [16,17],
    'senior'   => range(18,35)
  ];




  $nom=isset($_POST["nom"]) ? $_POST["nom"] : "";
  $prenom=isset($_POST["prenom"]) ? $_POST["prenom"] : "";

  $good_age=false;
  $age=$_POST["age"];
  $cat=$_POST["categorie"];
  if ($cat=="senior"){
    foreach($categorie_age['senior'] as $i){
      if ($i==intval($age)){
        $good_age=true;
      }
    }
  }
  else if ($age >=$categorie_age[$cat][0] && $age<=$categorie_age[$cat][1] ){
    $good_age=true;
  }

  $club=$_POST["club"];
  $err_club=true;
  foreach($club_exclus as $c){
    if($c!=$club)
      $err_club=false;
  }

?>


<!DOCTYPE html>
<html lang="fr">

<head>
  <meta charset="UTF-8" />
  <meta http-equiv="X-UA-Compatible" content="IE=edge" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <style>
    body {
      font-family: Arial, sans-serif;
      background-color: #eeeeee;
    }
    fieldset {
        padding: 20px 10px 10px 20px;
    }
    input,
    select {
      margin-bottom: 10px;
    }
    legend,
    input[type="submit"] {
      font-weight: bold;
    }
    .ok {
      color: green;
    }
    .error {
      color: red;
    }
  </style>
  <title>Exercice 3 - Formulaires</title>
</head>

<body>
  <?php

  ?>
  <form action="" method="POST">
    <fieldset>
      <legend>Inscription compétiteur</legend>
      <label for="nom">Nom: </label>
      <?php $v = htmlspecialchars($_POST["nom"] ?? "");?>
      <input type="text" name="nom" id="nom" value="<?php $v ?>"/>
      <br />
      <label for="nom">Prénom: </label>
      <?php $v = htmlspecialchars($_POST["prenom"] ?? "");?>
      <input type="text" name="prenom" id="prenom" value="<?php $v ?>"/>
      <br />
      <label for="nom">Age: </label>
      <input type="number" name="age" id="age" value=""/>
      <br />
      <label for="categorie">Catégorie: </label>
      <select name="categorie" id="categorie">
        <option value="benjamin">Benjamin</option>
        <option value="minime">Minime</option>
        <option value="cadet">Cadet</option>
        <option value="junior">Junior</option>
        <option value="senior">Sénior</option>
      </select>
      <br />
      <label for="club">Club: </label>
      <input type="text" name="club" id="club" />
      <br />
      <input type="submit" name="submit" value="Inscrire" />
    </fieldset>
  </form>

    <div id="messages">
      <?php
        
        if(($nom=="" || $prenom=="")){
            echo "Pas de nom et/ou prenom";
        }
        else if(!$good_age){
          echo "Compétiteur non inscrit. Erreur : L’age indiqué ne correspond pas à la catégorie demandée";
        }
        else if($err_club){
          echo "ompétiteur non inscrit. Erreur : Le club ".$club."ne participe pas à cette compétition";
        }else
          echo "Compétiteur inscrit(e) : ".$_POST["nom"].", ".$_POST["prenom"];
      ?>
    </div>
  </body>
</html>