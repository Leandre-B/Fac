<?php

function getContinents() {
    $file = __DIR__ . "/data/continent_codes.json";
    $file_contents = file_get_contents($file);
    return json_decode($file_contents, true);
}
// converts any array $tab of continents [["EU" => "Europe"], ...] into [["code" => "EU", "nom" => "Europe"], ...]
function rekey($tab) {
    return
    array_values( // re-indexes array numerically
        array_map(function($v) use($tab) { // 2nd parameter of callback is NOT the current element's key with array_map (as opposed to other array_* functions ...) 
            return ["code"=>array_search($v, $tab), "nom"=>$v]; // so search key with array_search passing array with `use`
        },
        $tab)
    );
}


## LIST DES PAYS D'UN CONTINENT

function getCountries() {
    $file = __DIR__ . "/data/country_continents.json";
    $file_contents = file_get_contents($file);
    return json_decode($file_contents, true);
}

function getCountriesCodes() {
    $file = __DIR__ . "/data/country_codes.json";
    $file_contents = file_get_contents($file);
    return json_decode($file_contents, true);
}


// get fields from path or body or else set to false
$ccode = $_GET["ccode"] ?? ($_POST["ccode"] ?? false);
$pcode = $_GET["pcode"] ?? ($_POST["pcode"] ?? false);
$cname = $_GET["cname"] ?? ($_POST["cname"] ?? false);

if($controller === "countries" && $method === "list") {
    $continents = getContinents();

    if(! key_exists($ccode, $continents)) {
        echo "Countries list: continent code does not exist";
        http_response_code(400);
        exit();
    }
    $cname = $continents[$ccode];

    $countries = getCountries();
    $countries = array_filter($countries, 
        function ($v) {
            global $cname;
            return ($v["continent"]==$cname);
        }
    );
    $countries = array_map(
        function ($v) {
            return ($v["country"]);
        },$countries
    );
    
    $c = array();
    foreach($countries as $v) array_push($c, $v);
    echo (json_encode($c));
    exit();
}


## ACCEDER A UN PAYS D'UN CONTINENT
if($controller === "countries" && $method === "read") {
    $continents = getContinents();

    if(! key_exists($ccode, $continents)) {
        echo "Countries of continent: continent code does not exist";
        http_response_code(400);
        exit();
    }

    $cname = $continents[$ccode];
    $countries_code = getCountriesCodes();
    // print_r($countries_code);

    $elegible_c = array();
    foreach($countries_code as $k=>$v) {
        foreach($v as $k2=>$v2) {
            if($v2 == $pcode)
                array_push($elegible_c, $k2);
        }
    }
    // print_r($elegible_c);

    $continents = array_filter($continents, 
        function($c) {print_r($c);}
    );
    
    echo (json_encode($elegible_c));
    exit();
}

 ?>