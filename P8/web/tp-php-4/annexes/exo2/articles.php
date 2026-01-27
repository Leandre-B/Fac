<!DOCTYPE html>
<html>
<head>
    <title>Recherche d'articles</title>
    <style>
        html {
            font-size: small;
        }
		form {
			text-align: center;
		}
		fieldset {
			border: 1px solid blue;
			width: 80%;
			margin:auto;
		}
    </style>
</head>
<body>
    <h2 align="center">Recherche d'articles</h2>
	<form action="" method="post">
		<!-- A MODIFIER POUR, LE CAS ECHEANT, RE-AFFICHER LE MOTIF ET L'OPTION CHOISIE -->
		<input type="text" name="motif"/>
		<label for="auteur">Par auteur/année</label>
		<input type="radio" name="cible" id="auteur" value="auteur" default/>
		<label for="titre">Par titre</label>
		<input type="radio" name="cible" id="titre" value="titre"/>
		<input type="submit" name="submit" value="Rechercher">
	</form>
	<br><br>
	<fieldset>
	<legend><strong>Résultat</strong></legend>
    <?php

		$motif = "/".htmlspecialchars($_POST["motif"] ?? "*")."/";
		echo $motif;
		echo "<br><br><br><br>";

		//preg_match($motif,$ch1,$result);
		$choix = htmlspecialchars($_POST["cible"] ?? "");
		echo $choix;

		$fic = fopen("articles.txt", "r");
		while ( ($ligne = fgets($fic)) !== FALSE )
			$txt[]= $ligne;
		//print_r($txt);
		foreach ($txt as $v){
			if($choix==="titre"){
				preg_match("/\\[.*\\]/",$v,$a_rechercher_v);
				$a_rechercher_v = $a_rechercher_v[0];
				echo $a_rechercher_v;
			}

			if (preg_match($motif,$a_rechercher_v)==1){
				echo $v;
				echo "<br>";
			}

		}

    ?>
	</fieldset>
</body>
</html>