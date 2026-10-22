<?php


declare(strict_types=1);
namespace Acme;
require_once __DIR__ . '/../vendor/autoload.php';

class Team{
    private $employees;
    private $managers;

    public function __construct($emps, $managers) {
        $this->employees = $emps;
        $this->managers = $managers;
    }

    // public function __construct() {
    //     $this->employees = array();
    //     $this->managers = array();
    // }

    public function __toString() {
        $str = '';
        foreach($this->employees as $e){
            $str.= 'employee : '. $e. '<br>';
        }
        
        foreach($this->managers as $m){
            $str.='employee : '.$m.'<br>subordinates=[ ';
            foreach($m->getArrEmployeesId() as $subId){
                foreach($this->employees as $e){
                    if($e->getId() == $subId) {
                        $str.=$e->getName().' ';
                    }
                }
            }
            $str.=']<br>';
        }
        return $str;
    }
};

?>