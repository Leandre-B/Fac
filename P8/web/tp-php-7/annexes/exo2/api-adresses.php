<?php
// en-tête de la réponse HTTP signifiant que ce fichier renvoie du JSON

header( 'Content-Type: application/json' );
// URL de l'API
$apiUrl = 'https://api-adresse.data.gouv.fr/search/';

// Récupération du champ contenant les mots-clés relatifs aux adresses à rechercher

if ( ! $rue = ( $_POST[ "rue" ] ?? "" ) ) {
    die( "Aucun mot-clé fourni !" );
}


// Chemin vers le fichier INI contenant les 2 autres paramètres de la requête HTTP
$ini_file="api-adresses.ini";

// Lecture du fichier INI
$ini_array = parse_ini_file($ini_file);
//print_r($ini_array);

// Tableau des paramètres de la chaîne de requête HTTP
$url="https://api-adresse.data.gouv.fr/search/?";
$parameters = [
    "q"     => $rue,
    "type"  => $ini_array["type"],
    "limit" => $ini_array["limit"]
];

// Construction de la chaîne de requête
$apiUrl .= "?".http_build_query($parameters);
//echo $apiUrl;

// Construction de l'URL complète
$request=$apiUrl;

// Envoi de la requête
$response = file_get_contents($request);

// Décodage de la réponse JSON en tableau associatif
if ($response === false)
    echo "Erreur lors de l’envoi de la requête !";
else {
    // Conversion de la réponse au format JSON en tableau associatif
    $tab = json_decode($response, TRUE);
    //print_r($tab["features"]);
}

foreach ($tab["features"] as $k=>$v){
    $json[] = ["address" => $v["properties"]["label"], 
               "lng" => $v["geometry"]["coordinates"][0],
               "lat" => $v["geometry"]["coordinates"][1]];
}

print_r(json_encode($json));

?>