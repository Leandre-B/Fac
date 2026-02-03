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
		<?php $motif = htmlspecialchars($_POST["motif"] ?? ".*"); ?>
		<input type="text" name="motif" value="<?= $motif ?>"/>
		<?php
		foreach(["auteur", "titre"] as $v) {
			$cheked[$v] = ($_POST["cible"] ?? "")===$v ? "checked" : ""; 
		}
		?>
		<label for="auteur">Par auteur/année</label>
		<input type="radio" name="cible" id="auteur" value="auteur" <?= $cheked['auteur'] ?>/>
		<label for="titre">Par titre</label>
		<input type="radio" name="cible" id="titre" value="titre" <?= $cheked['titre'] ?>/>
		<input type="submit" name="submit" value="Rechercher">
	</form>
	<br><br>
	<fieldset>
	<legend><strong>Résultat</strong></legend>
    <?php

		$motif = "/".$motif."/";
		$choix = htmlspecialchars($_POST["cible"] ?? "");

		$fic = fopen("articles.txt", "r");
		while ( ($ligne = fgets($fic)) !== FALSE )
			$txt[]= $ligne;
		//print_r($txt);
		$match=[];
		foreach ($txt as $v){
			//trouve index ']'
			$i=0;
			while($v[$i]!=']')
				++$i;

			$subtr_v="";
			if($choix=="auteur")
				$subtr_v=substr($v, 0, $i);
			else if($choix=="titre")
				$subtr_v=substr($v, $i);

			//echo $subtr_v;
			if (preg_match($motif,$subtr_v)==1){
				$match[]=$v;
			}
		}

		foreach($match as $k=>$v){
			preg_match('/[0-9]{4}\]/', $v, $year);
			preg_match('/\[[A-z]*/', $v, $name);
			preg_match('/\].*/', $v, $titre);
			$match[$k] = substr($year[0],0,4)." (".(substr($name[0],1)).") : ".substr($titre[0],1);
		}

		function cmp($a, $b){
			return $a>$b;
		}

		usort($match, "cmp");
		foreach($match as $k=>$v){
			echo $match[$k];
			echo "<br>";
		}

    ?>
	</fieldset>
</body>
</html>