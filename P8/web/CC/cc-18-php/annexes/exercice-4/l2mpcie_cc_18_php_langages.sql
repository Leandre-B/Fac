-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost
-- Généré le : ven. 12 mars 2021 à 06:46
-- Version du serveur :  5.7.20
-- Version de PHP : 7.4.5

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `l2mpcie_cc_18_php_langages`
--

-- --------------------------------------------------------

--
-- Structure de la table `VOYELLES`
--

CREATE TABLE `VOYELLES` (
  `LANGUE` varchar(8) COLLATE utf8mb4_bin DEFAULT NULL,
  `o` int(3) DEFAULT NULL,
  `e` int(3) DEFAULT NULL,
  `i` int(3) DEFAULT NULL,
  `u` int(3) DEFAULT NULL,
  `a` int(3) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

--
-- Déchargement des données de la table `VOYELLES`
--

INSERT INTO `VOYELLES` (`LANGUE`, `o`, `e`, `i`, `u`, `a`) VALUES
('anglais', 248, 355, 222, 107, 198),
('français', 178, 435, 240, 212, 201),
('gallois', 152, 264, 221, 107, 266),
('samoan', 248, 308, 334, 208, 656),
('zoulou', 203, 298, 311, 274, 411);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
