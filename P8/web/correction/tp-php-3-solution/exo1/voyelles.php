<?php
// 1
$filename = 'Latin-Lipsum.txt';
$f = file_get_contents($filename);

// 2
$chars = str_split($f);

// 3
$vowels = [
    'a',
    'e',
    'i',
    'o',
    'u'
];
$vowels_in = array_filter($chars, function ($c) {
    global $vowels;
    return in_array($c, $vowels);
});
   

// 4
$vowels_count = [];
array_walk($vowels_in, function ($v) use (&$vowels_count) {
//    print_r($vowels_count);
    
    (!array_key_exists($v, $vowels_count)) ? $vowels_count[$v] = 1 : $vowels_count[$v] = $vowels_count[$v] + 1;
});

print_r($vowels_count);
?>