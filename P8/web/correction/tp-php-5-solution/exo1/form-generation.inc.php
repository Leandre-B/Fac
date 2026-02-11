<?php

// Code HTML de l'ouverture d'un formulaire
function form(string $action, string $methode, string $legend): string
{
    $code = "<form action=\"$action\" method=\"$methode\" >\n";
    $code .= "<fieldset><legend>$legend</legend>\n";
    return $code;
}

// code HTML de champ texte mono-ligne
function text(string $libtexte, string $nomtexte): string
{
    $code = "<label><b> $libtexte </b></label> <input type=\"text\" name=\"$nomtexte\" /><br />\n";
    return $code;
}

// code HTML de bouton radio
function radio(string $libradio, string $nomradio, string $valradio): string
{
    $code = "<label><b> $libradio </b></label><input type=\"radio\" name=\"$nomradio\" value=\"$valradio\" /><br />\n";
    return $code;
}

// code HTML de bouton de soumission
function submit(string $libsubmit, string $libreset): string
{
    $code = "<input type=\"submit\" value=\"$libsubmit\" />&nbsp;&nbsp;&nbsp;\n";
    $code .= "<input type=\"reset\" value=\"$libreset\" /><br />\n";
    return $code;
}

// Code HTML de la cloture d'un formulaire
function finform(): string
{
    $code = "</fieldset></form>\n";
    return $code;
}
?>
