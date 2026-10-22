<?php

declare(strict_types=1);
require_once __DIR__ . '/../vendor/autoload.php';
use Acme\Employee;

function employee_raise(&$emp) {
    try {
        if($emp instanceof Employee) {
            $emp->setSalary($emp->getSalary() * 1.05);
        }else{
            throw new Error("Le paramètre n’est pas une instance de Employee", 1);
        }
    } catch (Throwable $th) {
        echo $th;
    }
}


?>