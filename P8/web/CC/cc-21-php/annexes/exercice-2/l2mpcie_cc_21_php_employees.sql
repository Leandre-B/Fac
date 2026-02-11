-- phpMyAdmin SQL Dump
-- version 5.1.1
-- https://www.phpmyadmin.net/
--
-- Hôte : localhost
-- Généré le : lun. 28 fév. 2022 à 14:37
-- Version du serveur : 10.4.21-MariaDB
-- Version de PHP : 8.0.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données : `l2mpcie_cc_21_php_employees`
--
CREATE DATABASE IF NOT EXISTS `l2mpcie_cc_21_php_employees` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `l2mpcie_cc_21_php_employees`;

-- --------------------------------------------------------

--
-- Structure de la table `Employee`
--

CREATE TABLE `Employee` (
  `id` int(11) NOT NULL,
  `name` varchar(40) COLLATE utf8mb4_bin NOT NULL,
  `salary` float NOT NULL,
  `age` int(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

--
-- Déchargement des données de la table `Employee`
--

INSERT INTO `Employee` (`id`, `name`, `salary`, `age`) VALUES
(6, 'Geraldine Meyer', 872, 95),
(7, 'Idona Glenn', 4230, 25),
(8, 'Martena Hyde', 9776, 70),
(9, 'Colette Mcmillan', 6873, 37),
(10, 'Raya Cook', 6296, 45),
(11, 'Warren Hendrix', 6822, 62),
(12, 'Lionel Best', 345, 53),
(13, 'Louis Brown', 7477, 41),
(14, 'Ginger Wolf', 4137, 77),
(15, 'Sade May', 9829, 65),
(16, 'George Doyle', 4405, 97),
(17, 'Devin Sheppard', 3136, 70),
(18, 'Marah Witt', 551, 99),
(19, 'Jermaine Bowman', 6824, 94),
(20, 'Gabriel Romero', 940, 99),
(21, 'Roanna Carrillo', 5084, 61),
(22, 'Wayne Houston', 74, 69),
(23, 'Yuli Mccarthy', 8820, 76),
(24, 'Hamilton Stevens', 2958, 75),
(25, 'Halee Gay', 8932, 68),
(26, 'Curran Townsend', 927, 70),
(27, 'Lacy Marks', 8484, 28),
(28, 'Chaim Bright', 8067, 66),
(29, 'Byron Gordon', 2793, 92),
(30, 'Griffin Hickman', 4058, 71),
(31, 'Lyle Mcmillan', 1083, 84),
(32, 'Andrew Hess', 7823, 25),
(33, 'Alice Howe', 489, 60),
(34, 'Channing Lewis', 4423, 61),
(35, 'Rashad Harrison', 5598, 56),
(36, 'Castor Barlow', 1671, 37),
(37, 'Allistair Riddle', 4557, 30),
(38, 'Jane Woodard', 9649, 64),
(39, 'Jerome Flynn', 9881, 77),
(40, 'Melyssa Hunter', 3315, 79),
(41, 'Nathan Craig', 8729, 63),
(42, 'Arsenio Saunders', 3859, 35),
(43, 'Kane Franco', 434, 89),
(44, 'Amethyst Matthews', 1961, 66),
(45, 'Rebekah Lee', 8698, 81),
(46, 'Noah Booth', 7788, 75),
(47, 'Oren Dudley', 9985, 42),
(48, 'August Wynn', 103, 94),
(49, 'Eleanor Wells', 8637, 33),
(50, 'Brittany Figueroa', 9216, 29),
(51, 'Justin Fox', 9745, 35),
(52, 'Elaine Wilder', 270, 69),
(53, 'Nathaniel Reid', 200, 64),
(54, 'Kirsten Cobb', 9131, 87),
(55, 'Lacey Hobbs', 6971, 49),
(56, 'Kuame Myers', 7913, 40),
(57, 'Winifred Bush', 1969, 40),
(58, 'Gisela Williams', 6574, 94),
(59, 'Hector Blankenship', 7928, 28),
(60, 'Driscoll Fields', 4624, 87),
(61, 'Illana Fitzpatrick', 1484, 72),
(62, 'Britanni Cummings', 391, 72),
(63, 'Ciara Ortiz', 1415, 77),
(64, 'Kareem William', 8865, 78),
(65, 'Armand Jacobs', 3065, 29),
(66, 'Danielle Herman', 5013, 92),
(67, 'Blossom Woodard', 4128, 78),
(68, 'Angela Yang', 7137, 87),
(69, 'Felix Holder', 6001, 96),
(70, 'Nehru Bender', 5635, 83),
(71, 'Scott Hardy', 4910, 98),
(72, 'Colorado Levine', 6328, 52),
(73, 'Patrick Tillman', 1384, 60),
(74, 'Laith Ellis', 7404, 50),
(75, 'Chanda Mcmillan', 4159, 53),
(76, 'Moses Clarke', 3351, 44),
(77, 'Amery Chavez', 3545, 85),
(78, 'Wyatt Parks', 1048, 42),
(79, 'Vivian Browning', 2321, 68),
(80, 'Juliet Wyatt', 1325, 25),
(81, 'Zenaida Ballard', 1910, 88),
(82, 'Paul Long', 5681, 86),
(83, 'Armando Green', 6011, 28),
(84, 'Rina Nguyen', 324, 68),
(85, 'Megan Olsen', 8603, 74),
(86, 'Jenna Wolf', 6139, 48),
(87, 'Fletcher Lewis', 7232, 93),
(88, 'Tucker Barber', 7678, 77),
(89, 'Jared Haney', 4978, 43),
(90, 'Timon Rosario', 3072, 95),
(91, 'Elmo Mcfarland', 4049, 72),
(92, 'Briar Carter', 4592, 97),
(93, 'Liberty Hinton', 3151, 75),
(94, 'Shad Gibbs', 4675, 27),
(95, 'Lee Henson', 2233, 53),
(96, 'Ignacia Diaz', 7481, 51),
(97, 'Aristotle Byers', 8314, 49),
(98, 'Rachel Sweet', 9, 41),
(99, 'Rafael O\'connor', 8725, 71),
(100, 'Mollie Kemp', 9504, 31),
(101, 'Nyssa Rich', 4589, 77),
(102, 'Brett Larson', 3480, 51),
(103, 'Harding Owens', 5367, 38),
(104, 'Eugenia Pickett', 3469, 55),
(105, 'Maxwell Cameron', 3249, 28);

--
-- Index pour les tables déchargées
--

--
-- Index pour la table `Employee`
--
ALTER TABLE `Employee`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT pour les tables déchargées
--

--
-- AUTO_INCREMENT pour la table `Employee`
--
ALTER TABLE `Employee`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=106;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
