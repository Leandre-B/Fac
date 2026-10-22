<?php

declare(strict_types=1);
require_once __DIR__ . '/../vendor/autoload.php';
use Acme\Employee;
    
    $employees = [
        new Employee(1, 'Jean', 12000.1, 46),
        new Employee(2, 'Michel', 1.0, 12),
        new Employee(3, 'Louise', 9999999.9, 26)
    ];

    array_walk($employees, function($e){echo($e.'<br>');});

    $mean_salary = 0;
    array_walk($employees, function($e){ global $mean_salary; $mean_salary +=$e->getSalary();});
    $mean_salary /= count($employees);
    echo 'mean salary = '.$mean_salary.'<br>';
?>