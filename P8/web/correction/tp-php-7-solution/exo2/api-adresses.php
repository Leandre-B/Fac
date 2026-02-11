<?php
// en-tête de la réponse HTTP signifiant que le fichier renvoie du JSON
header( 'Content-Type: application/json' );
// URL de l'API
$apiUrl = 'https://api-adresse.data.gouv.fr/search/';
// Récupération du champ contenant les mots-clés relatifs aux adresses à rechercher
if ( ! $rue = ( $_POST[ "rue" ] ?? "" ) ) {
    die( "Aucun mot-clé fourni !" );
    }

// Chemin vers le fichier INI contenant les 2 autres paramètres de la requête HTTP
$iniFile = __DIR__ . '/api-adresses.ini';

// Lecture du fichier INI
if ( ( $config = parse_ini_file( $iniFile, true ) ) === false ) {
    die( 'Erreur lors de la lecture du fichier INI.' );
    }
// Paramètres de la requête HTTP
$params = [ 
    'q'     => $rue,
    'type'  => $config[ 'paramètres' ][ 'type' ],
    'limit' => $config[ 'paramètres' ][ 'limit' ]
];
// Construction de la chaîne de requête
$queryString = http_build_query( $params );
// Construction de l'URL
$url = $apiUrl . '?' . $queryString;
// Envoi de la requête
try {
    $json = file_get_contents( $url );
    if ( ! $json ) {
        throw new Exception("Echec de la requête $url");
        }
    }
catch (Exception $e ) {
    die( $e );
    }
    
// Décodage de la réponse JSON en tableau associatif
$villes = json_decode( $json, true );
// Filtrage du tableau et renvoi au format JSON du type :
// [
//     {
//         "address": "rue Evariste Galois 29200 Brest",
//         "lng": -4.481212,
//         "lat": 48.413073
//     },
//     {
//         "address": "Allée Evariste Galois 18000 Bourges",
//         "lng": 2.357755,
//         "lat": 47.077523
//     },
// ....
/// ]


$jsontab = [];
foreach ( $villes[ "features" ] as $ville ) {
    $jsontab[] = [ 
        "address" => $ville[ "properties" ][ "label" ],
        "lng"     => $ville[ "geometry" ][ "coordinates" ][ 0 ],
        "lat"     => $ville[ "geometry" ][ "coordinates" ][ 1 ],
    ];
    }
echo json_encode( $jsontab );
?>