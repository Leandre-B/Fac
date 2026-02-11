<?php
$apiUrl = 'https://fr.wikipedia.org/w/api.php';
$params = [ 
    'action'      => 'query',
    'format'      => 'json',
    'titles'      => 'Paris',
    'prop'        => 'extracts',
    'exintro'     => true,
    'explaintext' => true,
    'exsentences' => 5
];

$queryString = http_build_query( $params );
$url         = $apiUrl . '?' . $queryString;
$response = file_get_contents( $url );
$data     = json_decode( $response, true );

if ( isset( $data[ 'query' ][ 'pages' ] ) ) {
    $pages = $data[ 'query' ][ 'pages' ];
    foreach ( $pages as $page ) {
        echo $page[ 'extract' ];
        }
    }
else {
    echo 'Aucun résultat trouvé.';
    }
?>
