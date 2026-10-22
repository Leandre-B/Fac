<?php

declare(strict_types=1);
require_once __DIR__ . '/../vendor/autoload.php';
use Acme\Manager;
use Acme\Employee;
use Acme\Team;

$employees = [
        new Employee(1, 'Jean', 12000.1, 46),
        new Employee(2, 'Michel', 1.0, 12),
        new Employee(3, 'Louise', 9999999.9, 26)
    ];
$m1 = new Manager(4, 'Manager1', 12,101);
$m1->add(3);
$m1->add(1);

$m2 = new Manager(5, 'Manager2', 34,909);
$m2->add(2);

$team = new Team($employees, [$m1, $m2]);
echo $team;

?>