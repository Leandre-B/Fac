<?php
$contentBody="Ceci est le texte de ma partie body";


function writeContentHeader(string $title, string $content){
    echo "<h1>$title</h1><p>$content</p>";
}

function writeContentBody(string $title){
    echo "<h1>$title</h1><p>A COMPLETER</p>";
}

function writeContentFooter(string $title, int $timestamp){
    echo "<h1>$title</h1><p>Nous sommes le A COMPLETER et il est A COMPLETER</p>";
}
?>