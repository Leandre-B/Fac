<!DOCTYPE html>
<html dir="ltr" lang="fr-FR">
<head>
<meta charset="utf-8" />
<title>Langues et voyelles</title>
<style>
legend {
  font-family: "Arial Black", "Arial", "Times New Roman";
}

input[type=submit]:hover, input[type=reset]:hover {
  background: black;
  color: white;
}

table {
  margin-top: 10px;
}

table, td, th {
  border: 1px solid blue;
  border-collapse: collapse;
  text-align: left;
}

th, td {
  width: 70px;
}
</style>
</head>
<body>
   <form method="post" action="langues.php">
      <fieldset>
         <legend> Choix de langues </legend>
         <input type="checkbox" name="an" value="anglais" />
         <label for="temps"> Anglais </label>
         <input type="checkbox" name="fr" value="français" />
         <label for="correspondance"> Français </label>
         <input type="checkbox" name="ga" value="gallois" />
         <label for="tarif"> Gallois </label>
         <input type="checkbox" name="sa" value="samoan" />
         <label for="horaire"> Samoan </label>
         <input type="checkbox" name="zo" value="zoulou" />
         <label for="affluence"> Zoulou </label>
      </fieldset>
      <input type="submit" value="Soumettre" />
   </form>
<?php
// A COMPLETER
?>
</body>
</html>
