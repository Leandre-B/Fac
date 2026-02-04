<?php
if(isset($_POST["nom"]) && isset($_POST['prenom']) && isset($_POST['animal'])){
	echo "Nom : ".$_POST["nom"]."<br>";
	echo "Prénom : ".$_POST["prenom"]."<br>";
	echo "animal : ".$_POST["animal"]."<br>";
}

?>