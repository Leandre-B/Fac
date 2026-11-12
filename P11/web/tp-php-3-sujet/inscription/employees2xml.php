<?php


$xml = (new DOMImplementation())-> createDocument(
    null,
    null,
    (new DOMImplementation())-> createDocumentType(
        "employees",
        null,
        "employees.dtd"
    )
);

$xml->xmlVersion="1.0";
$xml->encoding="UTF-8";
$xml->formatOutput=TRUE;


$employees=$xml->createElement("employees","");


$handle = fopen("employees.csv", "r");
        
$header = TRUE;
while( ($data = fgetcsv($handle,0, ";")) !== FALSE){
    if(!$header){
        
        $employee=$xml->createElement("employee","");

        $id=$xml->createElement("id",$data[0]);
        $employee->appendChild($id);

        $nom=$xml->createElement("name",$data[1]);
        $employee->appendChild($nom);

        $salary=$xml->createElement("salary",$data[2]);
        $employee->appendChild($salary);

        $age=$xml->createElement("age",$data[3]);
        $employee->appendChild($age);

        $employees->appendChild($employee);
    } else
        $header = FALSE;

    echo $header ? "</thead>" : "</tr>";
}

$xml->appendChild($employees);


$xml->save('employees.xml');
$xml->saveXML();

if($xml->validate() === false) {
    echo "XML non valide<br>";
}

?>