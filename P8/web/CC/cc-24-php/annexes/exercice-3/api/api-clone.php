<?php
// En-tête de la réponse HTTP signifiant que ce fichier renvoie du JSON
// NE PAS MODIFIER, NI FAIRE PRECEDER PAR D'AUTRES INSCRUTIONS
header( 'Content-Type: application/json' );

// - Lire le fichier "soutenances.json"
// - Décoder la réponse JSON en tableau indexé (de tableaux associatifs)
// - Récupérer le n° de discipline soumis en HTTP GET
// - Récupérer l'année de soutenance soumise en HTTP GET
// - Extraire, s'il existe, l'enregistrement correspondant à la paire <n° discipline, année de soutenance>
// et renvoyer ce tableau en JSON, sinon renvoyer le tableau vide en JSON
?>