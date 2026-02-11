<?php
$question_answers =
    array(
        2 => // question n°2
        array(
            0 => '$x = null; echo gettype($x);', // énoncé de la question
            1 => array( 'ANSWER' => 'NULL', 'SOLUTION' => 1, // énoncé de la 1ère réponse (réponse solution)
            ),
            2 => array( 'ANSWER' => 'boolean', 'SOLUTION' => 0, // énoncé de la 2nde réponse
            ),
            3 => array( 'ANSWER' => 'undefined', 'SOLUTION' => 0, // énoncé de la 3ème réponse
            ),
        ),
        3 =>
        array(
            0 => 'Que fait l\'instruction require(\'file.php\'); si file.php n\'existe pas ?',
            1 => array( 'ANSWER' => 'Rien.', 'SOLUTION' => 0,
            ),
            2 => array( 'ANSWER' => 'Une erreur de niveau E_WARNING est émise.', 'SOLUTION' => 0,
            ),
            3 => array( 'ANSWER' => 'Une erreur fatale de niveau E_COMPILE_ERROR est émise.', 'SOLUTION' => 1,
            ),
        ),
    );
?>