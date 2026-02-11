<!DOCTYPE html>
<html lang="fr">

<head>
    <meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />
    <title>TP PHP 4.1 - Calculatrice</title>
</head>

<body>
    <!-- Code PHP -->
    <?php
$nb1 = "";
$nb2 = "";
$resultat = "";

if (isset($_POST["calcul"])) {
    if (!empty($_POST["nb1"]) && !empty($_POST["nb2"])) {
        $nb1 = (int) $_POST["nb1"];
        $nb2 = (int) $_POST["nb2"];
        switch ($_POST["calcul"]) {
            case "Addition x+y":
                $resultat = $nb1 + $nb2;
                break;
            case "Soustraction x-y":
                $resultat = $nb1 - $nb2;
                break;
            case "Division x/y":
                $resultat = $nb1 / $nb2;
                break;
            case "Puissance x^y":
                $resultat = pow($nb1, $nb2);
                break;
            default:
                break;
        }
    } else {
        echo "<h3>Rien reçu ! </h3>";
    }
}
?>
    <h3>Entrez deux nombres : </h3>
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
                                value="<?= $resultat ?>" disabled />
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
