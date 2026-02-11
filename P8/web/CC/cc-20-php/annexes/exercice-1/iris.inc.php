<?php

/*
 * Permet de formatter le titre des colonnes
 * en séparant les mots par des espaces,
 * et en mettant les initiales en majuscules.
 */
function formatTitre(string $titre) : string {
	return ucwords(preg_replace('/_/', ' ', $titre));
}

/*
 * Permet de formatter les nombres (contenus dans un string) avec deux décimales.
 */
function formatNombre(string $nombre_str) : string {
	return number_format(floatval($nombre_str), 2);
}

/*
 * Permet de débuter un formulaire HTML.
 */
function debutForm(string $method, string $action='') : string {
	return '<form method="'.$method.'" action="'.$action.'">'."\n";
}

/*
 * Permet de terminer un formulaire HTML.
 */
function finForm() : string {
	return '</form>'."\n";
}

/*
 * Permet de créer un élément de formulaire HTML de type 'select'.
 * $name : nom pour récupérer la variable
 * $label : texte à afficher en label
 * $options : tableau associatif dont les valeurs représentent l'affichage des options, et les clés représentent les valeurs associées aux options
 * $selected : valeur de l'option sélectionnée par défaut
 */
function select(string $name, string $label, array $options, string $selected='') : string {
	$html = '';
	
	
	$html .= '<label for="'.$name.'">'.$label.'</label> ';
	
	$html .= '<select name="'.$name.'" id="'.$name.'">'."\n";
	$html .= '<option value="">Aucune</option>'."\n";
	foreach($options as $val => $display) {
		$sel = ($val == $selected) ? ' selected' : '';
		$html .= '<option value="'.$val.'"'.$sel.'>'.$display.'</option>'."\n";
	}
	$html .= '</select>'."\n";
	
	return $html;
}

/*
 * Permet de créer un élément de formulaire HTML de type 'number'.
 * $name : nom pour récupérer la variable
 * $label : texte à afficher en label
 * $step : "pas" de l'élément lors de l'utilisation des flèches
 * $value : valeur par défaut
 */
function number(string $name, string $label, $step=1, $value=0) : string {
	return '<label for="'.$name.'">'.$label.'</label> <input type="number" name="'.$name.'" id="'.$name.'" value="'.$value.'" step="'.$step.'" />'."\n";
}

/*
 * Permet de créer des éléments de formulaire HTML de type 'checkbox'.
 * $name : permet de récupérer la variable
 * $values : tableau associatif dont les valeurs représentent l'affichage des checkbox et les clés représentent les valeurs associées aux checkbox
 * $checked : tableau de valeurs qui doivent être sélectionnées par défaut
 *
 * Note : Chaque checkbox aura le même nom, ce qui va créer, lors de l'envoi du formulaire, un tableau en PHP qui contient toutes les valeurs cochées.
 */
function checkboxes(string $name, array $values, array $checked) : string {
	$html = '';
	foreach($values as $v) {
		$check = in_array($v, $checked) ? ' checked' : '';
		$html .= '<input type="checkbox" name="'.$name.'[]" id="'.$v.'" value="'.$v.'"'.$check.' /> <label for="'.$v.'">'.$v.'</label><br>'."\n";
	}
	return $html;
}

/*
 * Permet de créer un bouton de validation de formulaire HTML.
 * $name : nom pour récupérer la variable
 * $value : texte à afficher dans le bouton
 */
function submit(string $name, string $value) : string {
	return '<input type="submit" name="'.$name.'" value="'.$value.'" />'."\n";
}

/*
 * Permet de débuter un paragraphe HTML.
 */
function debutP() : string {
	return '<p>'."\n";
}

/*
 * Permet de terminer un paragraphe HTML.
 */
function finP() : string {
	return '</p>'."\n";
}
