<?php

declare(strict_types=1); 
namespace Acme;
require_once __DIR__ . '/../vendor/autoload.php';

    class Employee implements IEmployee{
        private $id ;
        public $name;
        protected $salary;
        private $age;
        public function __construct($id, $name, $salary, $age){
            $this->id = $id;
            $this->name = $name;
            $this->salary = $salary;
            $this->age = $age;
        }
        
        public function getId() :int {
            return $this->id;
        }
        public function getName() :string{
            return $this->name;
        }
        public function getSalary() :float{
            return $this->salary;
        }
        public function getAge() :int{
            return $this->age;
        }

        public function setId(int $id) {
            $this->id = $id;
        }
        public function setName(string $name) {
            $this->name = $name;
        }
        public function setSalary(float $salary) {
            $this->salary = $salary;
        }
        public function setAge(int $age) {
            $this->$age = $age;
        }
        public function __toString() : string {
            return 'id='.$this->id.' '.
                    'name='.$this->name.' '.
                    'age='.$this->age.' '.
                    'salary='.$this->salary;
        }
    
    };


?>