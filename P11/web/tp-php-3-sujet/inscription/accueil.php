<!DOCTYPE html>
<html lang="fr">
<head>
<meta charset="utf-8"/>
<title>TP PHP - Inscription d'employés</title>
</head>
<body style="background-color: #ffcc00;">
<a href="employee_form.php" > Employes </a>


 <?php

    $xml = new DOMDocument();
    $xml->load("employees.xml");
    $names = $xml->getElementsByTagName("name");

    echo "<table> <thead> <tr> <th> NOM </th> </tr> </thead>";
    foreach(range(0,$names->length-1) as $i) {
        $nom=$names->item($i)->nodeValue;
        echo "<tr> <td><a href=\"get_employee.php?name=".$nom."\" > ".$nom."</a> </tr> </td>";
    }


?>
</body>
</html>
