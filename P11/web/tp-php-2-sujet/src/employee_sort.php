<?php

declare(strict_types=1);
require_once __DIR__ . '/../vendor/autoload.php';
use Acme\Employee;

// $employees = [
//         new Employee(1, 'Jean', 12000.1, 46),
//         new Employee(2, 'Michel', 1.0, 12),
//         new Employee(3, 'Louise', 9999999.9, 26)
//     ];

usort($employees, function($a, $b){return $a->getSalary() - $b->getSalary();});
// var_dump($employees);


?>