<!DOCTYPE html>
<html>
<head>
	<title>Iris</title>
	<style>
	#formulaires {
		display:flex;
		flex-direction: row;
		margin-bottom: 1em;
	}
	#formulaires div {
		padding-top: 1em;
		padding-bottom: 1em;
	}
	#form_tri {
		flex-grow: 1;
		background-color: #ffd9d9;
	}
	#form_filtre_float {
		flex-grow: 4;
		background-color: #c6d4c6;
		display: flex;
	}
	#form_filtre_float form {
		flex-grow: 1;
		padding-left:1em;
	}
	#form_filtre_float form:not(:first-child) {
		border-left:1px solid black;
	}
	#form_filtre_str {
		flex-grow: 2;
		background-color: #d6d6ff;
	}
	table {
		width:100%;
		border-collapse:collapse;
	}
	td, th {
		border: 1px solid black;
	}
	tr:nth-child(odd) {
		background-color: #f1f1f1;
	}
	tr:nth-child(even) {
		background-color: #ffffff;
	}
	tr:first-child {
		background-color: #b1b1b1;
	}
	tr:hover:not(:first-child) {
		background-color: #d1d1d1;
	}
	input[type=number] {
		max-width:5em;
	}
	</style>
</head>
<body>

<?php
// Affichages HTML
$html_form_tri = '';
$html_form_filtre_float = '';
$html_form_flitre_str = '';
$html_table = '';

// Noms de colonnes
$float_cols = array('sepal_length', 'sepal_width', 'petal_length', 'petal_width'); // colonnes de type float
define('COL_VARIETY', 'variety'); // colonne de type string
$varieties = array('Setosa', 'Versicolor', 'Virginica'); // liste des variétés

// VOTRE CODE EN-DESSOUS
	
// VOTRE CODE AU-DESSUS
?>

<h1>Jeu de données des Iris de Fisher</h1>

<div id="formulaires">
	<div id="form_tri">
	<?php echo $html_form_tri; ?>
	</div>

	<div id="form_filtre_float">
	<?php echo $html_form_filtre_float; ?>
	</div>

	<div id="form_filtre_str">
	<?php echo $html_form_flitre_str; ?>
	</div>
</div>

<?php echo $html_table; ?>

</body>
</html>
