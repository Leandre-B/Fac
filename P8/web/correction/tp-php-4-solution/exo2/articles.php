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
		<?php $value = $_POST[ 'motif' ] ?? ""; ?>
		<input type="text" name="motif" value="<?= $value ?>">
		<label for="auteur">Par auteur/année</label>
		<?php
			$checked1 = "checked";
			$checked2 = "";
			if ( ($_POST[ 'cible' ] ?? "") === "titre") {
				$checked1 = "";
				$checked2 = "checked";
			}
		?>
		<input type="radio" name="cible" id="auteur" value="auteur" <?= $checked1 ?>/>
		<label for="titre">Par titre</label>
		<input type="radio" name="cible" id="titre" value="titre" <?= $checked2 ?>/>
		<input type="submit" name="submit" value="Rechercher">
	</form>
	<br><br>

	<fieldset>
	<legend><strong>Résultat</strong></legend>

    <?php
		if (isset($_POST['motif']) && isset($_POST['cible'])) {
			$motif   = '/' . $_POST[ 'motif' ] . '/';
			$cible = $_POST['cible'];
			$articles = [];
	        if( ($fp = fopen("articles.txt","r"))
				&& flock($fp,LOCK_SH) ) {
				while( ! feof($fp) ) {
					$line = fgets($fp);
					$tab = explode("]", $line); // [ <auteurannee>, <titre>]
					// print_r($tab);
					$tab[0] = substr($tab[0], 1); // supression de [
					$tab[1] = trim($tab[1]);
					if($checked1) { // recherche sur auteur/année
						$match = preg_match($motif, $tab[0]);
					} else {// recherche sur titre
						$match = preg_match($motif, $tab[1]);
					}
					if ($match) {
						$line1 = preg_replace('/^\[([a-zA-Z]+)([^\]]+)\](.+)$/', '$2 ($1) : $3', $line);
						$articles[] = $line1;
					}    	        
				}
				flock($fp,LOCK_UN);
				fclose($fp);
				sort($articles);
				echo implode("<br>", $articles);
			}
		}
    ?>

	</fieldset>
	
</body>
</html>
