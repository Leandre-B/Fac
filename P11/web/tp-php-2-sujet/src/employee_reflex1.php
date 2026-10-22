<?php

declare(strict_types=1);
require_once __DIR__ . '/../vendor/autoload.php';
use Acme\Manager;

$e = new Manager(1, 'Jean', 12000.1, 46);


$reflector = new ReflectionClass('Acme\Employee');

echo $reflector->getName(), '<br>';
if($reflector->getParentClass()) {
    $p = $reflector->getParentClass();
    echo $p->getName(), '<br>';
}
var_dump($reflector->getProperties());


echo get_class($e), '<br>';
echo get_parent_class($e), '<br>';
var_dump (get_object_vars($e));



?>