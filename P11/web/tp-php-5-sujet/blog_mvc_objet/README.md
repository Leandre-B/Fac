# TP PHP MVC

## Basé sur le [document](http://bpesquet.developpez.com/tutoriels/php/evoluer-architecture-mvc/) et le [dépôt](http://github.com/bpesquet/MonBlog) de [Baptiste Pesquet](https://github.com/bpesquet)


## Installation

1. Installer `Twig 3.3`  avec `composer` en exécutant la commande suivante qui lira le fichier `composer.json` :

`[blog_mvc_objet]$ php composer.phar install` 

2. Créer la base de données `l3_dw_tp_php_mvc_blog` :

- soit à partir de phpmyadmin en important le fichier `./BD/l3_dw_tp_php_mvc_blog.sql`

- soit avec la commande qui suit en utilisant le compte `root` fourni par le conteneur Docker :

```
[blog_mvc_objet]$ mariadb -u root -p
Enter password: 
...
MariaDB [(none)]> CREATE DATABASE IF NOT EXISTS l3_dw_tp_php_mvc_blog CHARACTER SET=utf8mb4 COLLATE utf8mb4_unicode_ci;
Query OK, 1 row affected (0.000 sec)
MariaDB [(none)]> exit;
Bye
[blog_mvc_objet]$ mariadb -u root -p l3_dw_tp_php_mvc_blog < BD/l3_dw_tp_php_mvc_blog.sql 
Enter password: 
[blog_mvc_objet]$
```

- Visiter la [page d'accueil](http://localhost/l3/tp-php-mvc/annexes/blog_mvc_objet/index.php)
