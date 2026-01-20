<?php

// A COMPLETER

$texte = strtolower(file_get_contents("Latin-Lipsum.txt"));
//echo $texte;

//======== 1 ======
$vowels_count = ["a" => 0, "e" => 0, "i" => 0, "o" => 0, "u" => 0];

$tstart = microtime(true);
for( $i = 0; $i < strlen($texte); $i++ ){
    if(array_key_exists($texte[$i], $vowels_count)){
        $vowels_count[$texte[$i]]++;
    }

}
$tstop = microtime(true);
echo(($tstop - $tstart) *1000)."ms";
//============



// TEST
print_r($vowels_count);
?>