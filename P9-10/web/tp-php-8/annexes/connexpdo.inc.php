<?php

    function connexpdo($bd){
        $pdo = new PDO("mysql:host=localhost;port=3306;dbname=$bd;charset=UTF8","root", "");
        $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

        return $pdo;
    }

?>