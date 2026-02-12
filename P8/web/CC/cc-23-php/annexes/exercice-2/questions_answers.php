<?php

/**
 * Extrait les réponses du fichier answers.csv qui sont associées au tableau de questions passé
 * en paramètre et les renvoie sous forme de tableau associatif.
 * Chaque élément du tableau résultat correspond à une question et à ses réponses :
 * - la clé de cet élément est le numéro de la question (colonne QUESTION),
 * - sa valeur est un tableau indicé dont
 * -- le premier élément est l'énoncé de la question et a pour indice 0
 * -- les éléments suivants d'incides 1,2, ... correspondent aux réponses associées à la question,
 * chacun étant un tableau associant les clés 'ANSWER' et 'SOLUTION' aux champs correspondants dans le fichier CSV.
 * 
 * Exemple.
 * Pour le tableau suivant passé en paramètre
 * 
 * Array
 * (
 *  [1] => Que fait l'instruction <code>include('file.php');</code> si <code>file.php</code> n'existe pas ?
 *  [5] => <code>$x =''; var_dump(empty($x));</code>
 * )
 *
 * la fonction renvoie le tableau
 * 
 * Array
 * (
 *  [1] => Array
 *      (
 *          [0] => Que fait l'instruction <code>include('file.php');</code> si <code>file.php</code> n'existe pas ?
 *          [1] => Array
 *              (
 *                  [ANSWER] => Rien
 *                  [SOLUTION] => 0
 *              )
 *          [2] => Array
 *              (
 *                  [ANSWER] => Une erreur de niveau <code>E_WARNING</code> est émise.
 *                  [SOLUTION] => 1
 *              )
 *          [3] => Array
 *              (
 *                  [ANSWER] => Une erreur fatale de niveau <code>E_COMPILE_ERROR</code> est émise.
 *                  [SOLUTION] => 0
 *              )
 *      )
 *
 *  [5] => Array
 *      (
 *          [0] => <code>$x =''; var_dump(empty($x));</code>
 *          [1] => Array
 *              (
 *                  [ANSWER] => <code>bool(false)</code>
 *                  [SOLUTION] => 0
 *              )
 *          [2] => Array
 *              (
 *                  [ANSWER] => <code>bool(true)</code>
 *                  [SOLUTION] => 1
 *              )
 *      )
 *  )
 *
 * @param string[] Tableau indicé dont chaque élément associe l'énoncé d'une question à son numéro.
 * @return mixed[][] Un tableau de questions-réponses.
 **/
function questionsAnswers(array $questions): array
{
    // QUESTION 2
    // A COMPLETER
    if (! $handle = fopen("./data/answers.csv", "r"))
        die("Echec de l’ouverture du fichier");
    else {
        $ligne = fgetcsv($handle, null, "\t");
        while (($ligne = fgetcsv($handle, null, "\t")) !== FALSE)
            $csv[] = $ligne;
        fclose($handle);
    }
    foreach($questions as $k=>$v){
        $answers[$k]=array(0 => $v);
        foreach($csv as $kc=>$vc){
            if($k==$vc[0]){
                array_push($answers[$k], array( "ANSWER" => $vc[1] , "SOLUTION" => $vc[2]));
            }
        }
    }
    return $answers;
}
