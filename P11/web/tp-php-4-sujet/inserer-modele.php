<!DOCTYPE html >
<html>
<head>
<meta charset="UTF-8" />
<title>Saisissez les caractéristiques du modèle</title>
</head>
<body>
	<form action="<?php echo $_SERVER['PHP_SELF'];?>" method="post"
		enctype="application/x-www-form-urlencoded">
		<fieldset>
			<legend>
				<b>Modèle de voiture</b>
			</legend>
			<table>
				<tr>
					<td>Code :</td>
					<td><input type="text" name="id_modele" size="40" maxlength="30"/></td>
				</tr>
				<tr>
					<td>Nom du modèle :</td>
					<td><input type="text" name="modele" size="40" maxlength="30"/></td>
				</tr>
				<tr>
					<td>Carburant : <select name="carburant">
							<option value="essence">Essence</option>
							<option value="diesel">Diesel</option>
							<option value="gpl">G.P.L.</option>
							<option value="électrique">Electrique</option>
					</select></td>
				</tr>
				<tr>
					<td><input type="reset" value=" Effacer "></td>
					<td><input type="submit" value=" Envoyer "></td>
				</tr>
			</table>
		</fieldset>
	</form>
<?php
require ("connexpdo.inc.php");
require_once ("js.php");
 if(isset($_POST["id_modele"]) && isset($_POST["modele"]) && isset($_POST["carburant"])) {
	$id = $_POST["id_modele"];
	$modele = $_POST["modele"];
	$carbu = $_POST["carburant"];
	$pdo = connexpdo("voitures");
	$qry="INSERT INTO modele VALUES (?,?,?)";
	$stt=$pdo->prepare($qry);
	try {
		$stt->execute([$id, $modele, $carbu]);
		alert("insertion réussi");
	}catch (PDOException $e) {
		// var_dump($e);
		displayException($e);
		console($e->getMessage());
	}
 }

?>
</body>
</html>