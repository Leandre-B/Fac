

INSERT INTO Etudiant VALUES
(1111, 'AHDJOUDJ', 'Yannick', 'Angers', TO_DATE('18/01/03', 'DD/MM/YY'), 'A1'),
(1112, 'AMEUR', 'Adil', 'Cholet', TO_DATE('17/02/02', 'DD/MM/YY'), 'A1'),
(1113, 'CALVAIRE', 'Isabelle', 'Nantes', TO_DATE('01/03/04', 'DD/MM/YY'), 'A2'),
(1114, 'GHULAM', 'William', 'Cholet', TO_DATE('27/04/04', 'DD/MM/YY'), 'A2'),
(1115, 'MIRMONT', 'Jean', 'Paris', TO_DATE('07/05/02', 'DD/MM/YY'), 'A3'),
(1116, 'TOTO', 'Sylvie', 'Tours', TO_DATE('17/06/01', 'DD/MM/YY'), 'A3'),
(1117, 'WINTERHA', 'Shahidah', 'Toulouse', TO_DATE('07/07/03', 'DD/MM/YY'), 'A3');

INSERT INTO Groupe VALUES
('A1', 'Informatique'),
('A2', 'Math-Info'),
('A3', 'Bio-Info'),
('A4', 'Chimie'),
('A5', 'Math');

INSERT INTO Passcont VALUES
(1111, 1, 10),
(1112, 1, 20),
(1113, 1, 11.5),
(1114, 1, 3),
(1115, 1, 10.5),
(1116, 1, 12),
(1111, 2, 10.5),
(1112, 2, 6.6),
(1113, 2, 4.5),
(1114, 2, 9),
(1115, 2, 8.5),
(1116, 2, 2.5),
(1111, 3, 14.5),
(1112, 3, 11.5),
(1113, 3, 3.5),
(1114, 3, 12.5),
(1115, 3, 20),
(1116, 3, 9.5);

INSERT INTO Controle VALUES
(1, 'Algo', TO_DATE('15/01/23', 'DD/MM/YY'), 1),
(2, 'Algo', TO_DATE('12/12/22', 'DD/MM/YY'), 3),
(3, 'Algo', TO_DATE('17/02/23', 'DD/MM/YY'), 2),
(4, 'Algo', TO_DATE('27/03/23', 'DD/MM/YY'), 3),
(5, 'Math1', TO_DATE('17/01/23', 'DD/MM/YY'), 1),
(6, 'Gestion', TO_DATE('07/02/23', 'DD/MM/YY'), 2),
(7, 'TE', TO_DATE('27/03/23', 'DD/MM/YY'), 2),
(8, 'Math2', TO_DATE('17/01/23', 'DD/MM/YY'), 1),
(9, 'Anglais', TO_DATE('27/01/23', 'DD/MM/YY'), 2);

INSERT INTO Matiere VALUES
('Algo', 2, 1),
('Algo', 3, 2),
('Math1', 6, 3),
('Gestion', 7, 4),
('TE', 7, 5),
('Math2', 6, 6),
('Anglais', 7, 7);

INSERT INTO Enseignant VALUES
(1, 'Carter'),
(2, 'Clinton'),
(3, 'Bush'),
(4, 'Paolo'),
(5, 'Vissou'),
(6, 'Charlemagne'),
(7, 'Léandri');

