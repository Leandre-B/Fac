<?php

// code HTML de champ texte mono-ligne
function text(string $libtexte, string $nomtexte): string
{
    // A COMPLETER
    return "<label for=\"$nomtexte\"> $libtexte </label>
            <input type=\"text\" id=\"$nomtexte\" name=\"$nomtexte\" />";
}

// code HTML de bouton de soumission
function submit(string $libsubmit, string $libreset): string
{
    // A COMPLETER
    return "<input type= \"submit\" value=\"$libsubmit\"/>
            <input type= \"reset\" value=\"$libreset\"/>";
}

#un libellé, du nom du champ et de sa valeur

// A ETENDRE

function radio(string $libRadio, string $nomRadio, string $valRadio): string
{
    return "<label for=\"$nomRadio\"> $libRadio </label>
            <input type=\"radio\" id=\"$nomRadio\" name=\"$nomRadio\" value=\"$valRadio\">";
}

function ouverture(string $send_to){
    return "<form action=\"$send_to\" method=\"post\">";
}

function fermeture(){
    return "</form>";
}

?>
