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
			margin: auto;
		}
	</style>
</head>

<body>
	<h2 align="center">Recherche d'articles</h2>

	<form action="" method="post">
		<input type="text" name="txt" value="<?php echo $_POST[ 'txt' ]; ?>">
		<select name="typeRecherche">
			<option value="contient" <?php if ( $_POST[ 'typeRecherche' ] === "contient" ) echo "selected"; ?>>Doit
				contenir</option>
			<option value="debut" <?php if ( $_POST[ 'typeRecherche' ] === "debut" ) echo "selected"; ?>>Au debut</option>
			<option value="fin" <?php if ( $_POST[ 'typeRecherche' ] === "fin" ) echo "selected"; ?>>À la fin</option>
		</select>
		<input type="submit" name="submit" value="Rechercher">
	</form>
	<br><br>

	<fieldset>
		<legend><strong>Résultat</strong></legend>

		<?php
		if ( isset( $_POST[ 'txt' ] ) && isset( $_POST[ 'typeRecherche' ] ) ) {

			$typeRecherche = $_POST[ 'typeRecherche' ];

			// 1-remplacer des characteres speciaux ( []()+ )
		

			// 2-generer le motif/pattern a chercher.
		

			// 3-ouvrir le fichier
		
			// boucle :
			// - 4-lire une ligne et supprimer la chaine '.pdf'
			// - 5-rechercher le pattern
		
			// 6-fermer le fichier
		
			}
		?>

	</fieldset>

</body>

</html>