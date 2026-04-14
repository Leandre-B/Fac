/*
    Elements = Array [
        {
            element: "nom de l'élément HTML",
            attributs: Array [
                {
                    nom: "nom de l'attribut de l'élément HTML",
                    valeur: "valeur de l'attribut"
                },
                ...
            ],
            fils: Elements
        },
        ...
    ] ;
    
    `Elements` ne contient pas d'élément textuel
*/
var films = [
    {element: "div", attributs: [{nom: "class", valeur: "row isotope pt-4"}, {nom: "style", valeur: "position: relative; height: 1655.58px;"}], fils: [
        {element: "div", attributs: [{nom: "class", valeur: "col-6 col-sm-4 col-md-3 bloc-film text-center mb-4 nouveautes "}, {nom: "style", valeur: "position: absolute; left: 0px; top: 24px;"}], fils: [
            {element: "div", attributs: [{nom: "class", valeur:"shadowed position-relative"}], fils: [
                {element: "img", attributs: [{nom: "onload", valeur: "this.style.opacity='1';"},{nom: "src", valeur: "./exo4_files/horssaison.jpg"},{nom: "alt", valeur: "HORS-SAISON de Stéphane Brizé"}, {nom: "width", valeur: "157"}, {nom: "height", valeur: "209"}, {nom: "class", valeur: "img-fluid img-thumbnail w-100 fade"}, {nom: "style", valeur: "opacity: 1;"}], fils: []}
            ]}
        ]},
        {element: "div", attributs: [{nom: "class", valeur: "col-6 col-sm-4 col-md-3 bloc-film text-center mb-4 nouveautes "}, {nom: "style", valeur: "position: absolute; left: 180px; top: 24px;"}], fils: [
            {element: "div", attributs: [{nom: "class", valeur:"shadowed position-relative"}], fils: [
                {element: "img", attributs: [{nom: "onload", valeur: "this.style.opacity='1';"},{nom: "src", valeur: "./exo4_files/jeunefilleetlespaysans.jpg"},{nom: "alt", valeur: "LA JEUNE FILLE ET LES PAYSANS de DK Welchman &amp; Hugh Welchman"}, {nom: "width", valeur: "157"}, {nom: "height", valeur: "209"}, {nom: "class", valeur: "img-fluid img-thumbnail w-100 fade"}, {nom: "style", valeur: "opacity: 1;"}], fils: []}
            ]}
        ]},
        {element: "div", attributs: [{nom: "class", valeur: "col-6 col-sm-4 col-md-3 bloc-film text-center mb-4 nouveautes "}, {nom: "style", valeur: "position: absolute; left: 360px; top: 24px;"}], fils: [
            {element: "div", attributs: [{nom: "class", valeur:"shadowed position-relative"}], fils: [
                {element: "img", attributs: [{nom: "onload", valeur: "this.style.opacity='1';"},{nom: "src", valeur: "./exo4_files/bisrepetita.jpg"},{nom: "alt", valeur: "BIS REPETITA de Émilie Noblet"}, {nom: "width", valeur: "157"}, {nom: "height", valeur: "209"}, {nom: "class", valeur: "img-fluid img-thumbnail w-100 fade"}, {nom: "style", valeur: "opacity: 1;"}], fils: []}
            ]}
        ]},
        {element: "div", attributs: [{nom: "class", valeur: "col-6 col-sm-4 col-md-3 bloc-film text-center mb-4 nouveautes "}, {nom: "style", valeur: "position: absolute; left: 540px; top: 24px;"}], fils: [
            {element: "div", attributs: [{nom: "class", valeur:"shadowed position-relative"}], fils: [
                {element: "img", attributs: [{nom: "onload", valeur: "this.style.opacity='1';"},{nom: "src", valeur: "./exo4_files/unefamille2024.jpg"},{nom: "alt", valeur: "UNE FAMILLE de Christine Angot"}, {nom: "width", valeur: "157"}, {nom: "height", valeur: "209"}, {nom: "class", valeur: "img-fluid img-thumbnail w-100 fade"}, {nom: "style", valeur: "opacity: 1;"}], fils: []}
            ]}
        ]}
    ]}
];

// Q1 - Implémenter la fonction `creerElement(element, attributs)` qui retourne un Objet correspond à l'élément HTML avec ses attributs 
function creerElement(element, attributs) {
}


// Q2 - Implémenter la fonction `creerDOM(elements)` qui à partir d'Elements retourne la liste des Objets correspondants aux éléments HTML avec leurs attributs et leurs fils
function creerDOM(elements) {
}

// Q3 - Implémenter la fonction `creerFilms` qui ajoute à l'élément identifié par 'films' tous les éléments de la variable `films` définie en haut de ce document
function creerFilms() {
}
creerFilms();

// Q4 - Implémenter la fonction `supprimer(classe)` qui supprime du DOM le premier élément qui a pour classe `classe`.
function supprimer(classe) {
}

