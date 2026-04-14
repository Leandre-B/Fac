// Q1: Créez le tableau `employésAlpha` à partir du tableau d'employés
// en supprimant le champ `adresse` de chaque élement,
// en ordonnant les champs comme suit `prénom`, `NOM`, `salaire`,
// et en mettant en majuscules clé et valeur du champ `NOM`.

// A COMPLETER
const employésAlpha = null;

JSON.stringify(employésAlpha) ===
    JSON.stringify(employésAlphaSolution) ?
    (document.getElementById(
        "res-1"
    ).innerHTML += " OK") :
    (document.getElementById(
        "res-1"
    ).innerHTML += " KO");

// Q2: Remplacez le prénom de l'avant dernière employé par "Mélanie", 
// puis ordonnez le tableau par salaire décroissant
// en stockant le résultat dans le tableau `employésBeta`.

// A COMPLETER
let employésBeta = null;

JSON.stringify(employésBeta) ===
    JSON.stringify(employésBetaSolution) ?
    (document.getElementById(
        "res-2"
    ).innerHTML += " OK") :
    (document.getElementById(
        "res-2"
    ).innerHTML += " KO");

// Q3: Calculez le nombre d'employés et le salaire moyen (arrondi à l'entier le plus proche),
// et stockez ces valeurs dans les variables `nbEmployés` et `salaireMoyen`, respectivement.

// A COMPLETER
let nbEmployés = null;
let salaireMoyen = null;

JSON.stringify(nbEmployés) ===
    JSON.stringify(
        nbEmployésSolution
    ) &&
    JSON.stringify(salaireMoyen) ===
    JSON.stringify(salaireMoyenSolution) ?
    (document.getElementById(
        "res-3"
    ).innerHTML += " OK") :
    (document.getElementById(
        "res-3"
    ).innerHTML += " KO");

// Q4: Comptez le nombre de employés ayant un salaire supérieur à 2600 ou supérieur au salaire moyen.

// A COMPLETER
const nbEmployésSalaireSupérieur =
    null;

JSON.stringify(
        nbEmployésSalaireSupérieur
    ) ===
    JSON.stringify(
        nbEmployésSalaireSupérieurSolution
    ) ?
    (document.getElementById(
        "res-4"
    ).innerHTML += " OK") :
    (document.getElementById(
        "res-4"
    ).innerHTML += " KO");

// Q5: Créez un nouveau tableau `employésGamma` à partir de `employésBeta` contenant un nouveau champ
// 'salaire annuel' sachant que chaque employé obtient une prime anuelle de 600€.

// A COMPLETER
const employésGamma = null;

JSON.stringify(employésGamma) ===
    JSON.stringify(employésGammaSolution) ?
    (document.getElementById(
        "res-5"
    ).innerHTML += " OK") :
    (document.getElementById(
        "res-5"
    ).innerHTML += " KO");