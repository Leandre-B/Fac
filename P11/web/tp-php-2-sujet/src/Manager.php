<?php

declare(strict_types=1);
namespace Acme;
require_once __DIR__ . '/../vendor/autoload.php';


class Manager extends Employee implements IManager {
    private $subordonees;
    public function __construct(int $id, string $name,float $salary, int $age) {
        parent::__construct($id, $name, $salary, $age);
        $this->subordonees = array();
    }   
    public function add(int $employeeId) {
        array_push($this->subordonees, $employeeId);
    }
    public function getArrEmployeesId() : array {
        return $this->subordonees;
    }
};

?>