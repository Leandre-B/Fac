<?php
$apiUrl = 'https://fr.wikipedia.org/w/api.php?';
$parameters = [
    "action" => "query",
    "format" => "json",
    "titles" => "Angers",
    "prop" => "extracts",
    "exintro" => "true" ,
    "explaintext" => "true",
    "exsentences" => "5",
];
// Encodage des paramètres au format query-string
$apiUrl .= http_build_query($parameters);

// Envoi de la requête en HTTP GET par défaut
$response = file_get_contents($apiUrl);

if ($response === false)
    echo "Erreur lors de l’envoi de la requête !";
else {
    echo $response;
    // Conversion de la réponse au format JSON en tableau associatif
    $tab = json_decode($response, TRUE);
    print_r($tab);
}
/*
https://fr.wikipedia.org/w/api.php?action=query&format=json&titles=Paris&prop=extracts&exintro=true&explaintext=true&exsentences=5

target : 
https://fr.wikipedia.org/w/api.php?action=query&format=json&titles=Paris&prop=extracts&exintro=true&explaintext=true&exsentences=5
*/