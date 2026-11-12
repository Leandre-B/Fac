<!DOCTYPE html >
<html>
<head>
<meta charset="UTF-8" />
<title>Lecture de la table modele</title>
<style type="text/css">
table, tr, td, th {
	border-style: solid;
	border-color: red;
	background-color: yellow;
}
table {
	border-width: 3px;
	border-collapse: collapse;
}
tr, td, th {
	border-width: 1px;
}
</style>
</head>
<body>
<?php

	require ("connexpdo.inc.php");
	require_once ("js.php");

	try {
		$pdo = connexpdo("voitures");

		$qry="SELECT * FROM modele ORDER BY modele";
		$stt=$pdo->query($qry);
		$modeles=$stt->fetchAll(PDO::FETCH_NUM);

		echo "<table> <thead> 
			<tr>
				<th> Code modèle </th>
				<th> Modèle </th>
				<th> Carburant </th>
			</tr>
		</thead>";

		foreach($modeles as $record) {
			echo "<tr>";
			foreach($record as $item) {
				echo "<td>".$item."</td>";
			}
			echo "</tr>";
		}

	} catch (PDOException $e) {
		displayException($e);
		console($e->getMessage());
	}

?>
</body>
</html>