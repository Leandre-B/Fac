<?php


    if(null !== ($_GET["name"])) {
        $xml = new DOMDocument();
        $xml->load("employees.xml");
        $emp = $xml->getElementsByTagName("employee");

        foreach(range(0,$emp->length-1) as $i) {
            $nom=$emp->item($i);
            if($nom->getElementsByTagName("name")[0]->nodeValue == $_GET["name"]) {
                echo $nom->nodeValue;
            }
        }
    }

?>