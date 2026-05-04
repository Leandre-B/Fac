// Q1 - Créez un tableau JS qui stocke chaque triplet d'entiers figurant dans une ligne du tableau HTML sous la forme d'un tableau JS à 3 éléments.
// Ce tableau ne doit contenir ni les en-têtes, ni les noms de continents.
// Tableau attendu : [[48,3,5],[0,0,1],[31,12,6],[29,10,6],[13,10,14],[7,7,14],[12,0,2]]

let t = [];
let tds = document.querySelectorAll("tbody td");
let cpt=0;
let r = [];
for(let td of tds){
    if(!isNaN(parseInt(td.textContent))){
        cpt++;
        r.push(parseInt(td.textContent));
        if(cpt==3){
            cpt=0;
            t.push(r);
        }
    }
}

console.log(t);


// Q2 Créez un tableau JS qui stocke chaque ligne du tableau HTML, sauf la ligne d'en-têtes, sous la forme d'un objet
// ayant 4 propriétés dénommées continent, republic, monarchy et other.
// Tableau attendu :
// [
// {
// "continent": "Africa",
// "republic": 48,
// "monarchy": 3,
// "other": 5
// },
// {
// "continent": "Antarctica",
// "republic": 0,
// "monarchy": 0,
// "other": 1
// },
// {
// "continent": "Asia",
// "republic": 31,
// "monarchy": 12,
// "other": 6
// },
// {
// "continent": "Europe",
// "republic": 29,
// "monarchy": 10,
// "other": 6
// },
// {
// "continent": "North America",
// "republic": 13,
// "monarchy": 10,
// "other": 14
// },
// {
// "continent": "Oceania",
// "republic": 7,
// "monarchy": 7,
// "other": 14
// },
// {
// "continent": "South America",
// "republic": 12,
// "monarchy": 0,
// "other": 2
// }
// ]


let t_obj = [];
let trs= document.querySelectorAll("tr");
let first= new Boolean(true);
for(let th of trs){
    if(first)
        first=false;
    else{
        let obj = new Object;
        obj.continent = th.cells[0].textContent;
        obj.republic = th.cells[1].textContent;
        obj.monarchy = th.cells[2].textContent;
        obj.other = th.cells[3].textContent;
        t_obj.push(obj);
    }
}
console.log(t_obj);

// Q3 - Fonction effacerFormattage() 
// Applique à toute cellule du tableau HTML contenant un entier la mise en forme suivante : 
// son fond est blanc, le texte est en noir, et la graisse (weight) des chiffres est normale.

function effacerFormattage() {
    for(let td of tds){
        if(!isNaN(parseInt(td.textContent))){
            td.style.backgroundColor = "white";
            td.style.color = "black";
            td.style.fontWeight = "normal";
        }
    }
}

// Q4 - Fonction formaterMinMax(ncol) 
// Prend en entrée un numéro de colonne du tableau HTML (ncol) et applique aux 2 cellules contenant les valeurs minimale et maximale de la colonne la mise en forme suivante :
// - le texte est en gras,
// - le texte est de couleur rouge pour la valeur minimale et vert clair pour la valeur maximale,
// - le fond est de couleur rose pour la valeur minimale et vert pour la valeur maximale.

function formaterMinMax(ncol){
    let trs = document.querySelectorAll("tbody tr");
    let min = trs[0].cells[ncol];
    let max = trs[0].cells[ncol];
    for(let tr of trs){
        if(parseFloat(tr.cells[ncol].textContent) < parseInt(min.textContent))
            min=tr.cells[ncol];
        if(parseFloat(tr.cells[ncol].textContent) > parseInt(max.textContent))
            max=tr.cells[ncol];
    }
    min.style.fontWeight = "bold";
    max.style.fontWeight = "bold";
    max.style.color = "LightGreen";
    min.style.color = "red";
    min.style.backgroundColor = "pink";
    max.style.backgroundColor = "green";
}


// Q5 - Remplacez le texte des en-têtes du tableau HTML ``Republic'', ``Monarchy'' et ``Other'' par des boutons (éléments 
// button ou input de type button). Chaque bouton affiche le même texte que l’en-tête qu'il remplace.

let ths = document.querySelectorAll("th");
first=true;
for(let th of ths){
    if(first)
        first=false;
    else{
        let txt = th.textContent;
        th.innerHTML = "<input type<input type=\"button\" value=\""+txt+"\">";
    }
}


// A COMPLETER
let th = document.querySelectorAll("th");
th.forEach(function(header,index) {
    if (index > 0) 
    {
        btn = header.firstElementChild;
        btn.addEventListener("click", function(event) {
            effacerFormattage();
            formaterMinMax(index);
        });
    }
})
