<?php

require_once 'js.php'; 

/**
 * etablir_connexion_pdo()
 * 
 * @author Les intervenants du DevWeb
 * @param dbname Nom de la base de données à se connecter
 * @return object pdo
 */
function etablir_connexion_pdo(string $dbname)
{
    $sgbd = "mysql";
    $host = "localhost";
    $port = 3306;
    $charset = "UTF8";
    $user = ""; // TODO
    $pass = ""; // TODO
    try {
        $pdo = new pdo("$sgbd:host=$host;port=$port;dbname=$dbname;charset=$charset", $user, $pass, array(
            PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION
        ));
        return $pdo;
    } catch (PDOException $e) {
        displayException($e);
        exit();
    }
}

/**
 * ajouter_employee() 
 * 
 * @param name   Prenom et nom d'un employée
 * @param salary Salaire d'un employée
 * @param age    Age d'un employée
 * @return void
 */
function ajouter_employee(string $name, float $salaire, int $age) 
{
}

?>
