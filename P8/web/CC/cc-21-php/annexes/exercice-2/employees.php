<?php

// A COMPLETER

?>


<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8" />
        <title>CC PHP 2022</title>
    </head>
    <body>
        <form method="post">
            <fieldset>
                <legend> Employés </legend>
                <label for="nom">Nom: </label>
                <input type="text" name="nom" id="nom">
                <br>
                <label for="prenom">Prénom: </label>
                <input type="text" name="prenom" id="prenom">
                <br>
                <label for="salaire">Salaire: </label>
                <input type="text" name="salaire" id="salaire" pattern="[0-9]{1,}\.{0,}[0-9]{0,2}" title="Salaire: Nombre decimal (deux chiffres après la virgule)">
                <br>
                <label for="age">Age: </label>
                <input type="text" name="age" id="age" pattern="[0-9]{2}" title="Age: Deux chiffres">
                <br><br>
                <input type="submit" name="inserer" value="Inserer">
                <input type="reset" name="reset" value="Nettoyer">
                <!-- A COMPLETER -->
                <p>(... employés ajoutés)</p>
            </fieldset>
        </form>
    </body>
</html>
