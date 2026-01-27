<!DOCTYPE html>
<html lang="fr">

<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
    <title>TP PHP 4.1 - Calculatrice</title>
</head>

<body>
    <!-- A INSERER : CODE PHP POUR TRAITER LE FORMULAIRE -->
    <?php
        $nb1=htmlspecialchars($_POST["nb1"] ?? 0);
        $nb2=htmlspecialchars($_POST["nb2"] ?? 0);
        $result=htmlspecialchars($_POST["result"] ?? 0);
        $calcul=htmlspecialchars($_POST["calcul"] ?? "");

        if($calcul==="Addition x+y")
            $result = intval($nb1) + intval($nb2);
        else if($calcul==="Soustraction x-y")
            $result = intval($nb1) - intval($nb2);
        else if($calcul==="Division x/y")
            if(intval($nb2)!=0)
                $result = intval($nb1) / intval($nb2);
            else
                $result = 0;
        else if($calcul==="Puissance x^y")
            $result = intval($nb1) ** intval($nb2);
    ?>
    <h3>Entrez deux nombres : </h3>
    <!-- A MODIFIER : CODE PHP POUR AFFICHER ARGUMENTS ET RESULTAT EVENTUELS  -->
    <form action="<?= $_SERVER["PHP_SELF"] ?>" method="post">
        <fieldset>
            <legend>Calculatrice en ligne</legend>
            <table>
                <tbody>
                    <tr>
                        <td><label><b> Nombre 1 </b></label> <input type="number" step="1" name="nb1" size="30"
                                value="<?= $nb1 ?>" />
                        </td>
                    </tr>
                    <tr>
                        <td><label><b> Nombre 2 </b></label> <input type="number" step="1" name="nb2" size="30"
                                value="<?= $nb2 ?>" />
                        </td>
                    </tr>
                    <tr>
                        <td><label><b> Résultat </b></label> <input type="number" step="1" name="result" size="30"
                                value="<?= $result ?>" disabled />
                        </td>
                    </tr>   
                    <tr>
                        <td><label><b> Choisissez ! </b></label> <input type="submit" name="calcul"
                                value="Addition x+y" />&nbsp;&nbsp;&nbsp;
                            <input type="submit" name="calcul" value="Soustraction x-y" />&nbsp;&nbsp;&nbsp;
                            <input type="submit" name="calcul" value="Division x/y" />&nbsp;&nbsp;&nbsp;
                            <input type="submit" name="calcul" value="Puissance x^y" />&nbsp;&nbsp;&nbsp;
                        </td>
                    </tr>
                </tbody>
            </table>
        </fieldset>
    </form>
</html>
