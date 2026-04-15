// Q1
// Appliquez la police `Arial` au corps de la page.
// Incorporez le texte ``Tableau périodique des éléments chimiques'' 
// dans l’élément d'identifiant `titre-principal`.

document.querySelector("body").style.fontFamily="Arial";
document.getElementById("titre-principal").textContent = "Tableau périodique des éléments chimiques";

// Q2
// Cochez toutes les cases à cocher.
chcks = document.querySelectorAll("input[type=\"checkbox\"");
chcks.forEach(c => {
    c.checked=true;
});

// Q3
// Colorez les éléments de classe `Gaz_noble` en `lightblue` 
// sauf les libellés des cases à cocher qui sont dans cette classe.
gazNoble = document.querySelectorAll(".Gaz_noble");
gazNoble.forEach(g => {
    if(g.nodeName != "LABEL"){
        g.style.backgroundColor = "lightblue";
    }
});


// Q4
// Affichez en console les données (numéro, nom, symbole et masse) 
// contenues dans la 5ème cellule du tableau (le Béryllium).

let tds = document.querySelectorAll("td");
let be = tds[4];
console.log(be);
for(let e of be.children){
    if(e.nodeName=="SPAN")
        console.log(e.textContent);
    if(e.nodeName=="A"){
        console.log(e.title);
        console.log(e.textContent); 
    }
}

// Q5
// Implémentez la fonction `decolorer()` qui encadrera chaque cellule du tableau 
// appartenant à (au moins) une classe par une bordure de style `1px solid black`.
// Testez la fonction en cochant le bouton ``Noir et blanc'' ou en l'appelant dans 
// la console.

function decolorer(){
    document.querySelectorAll("td").forEach(td => {
        if(td.className!=""){
            td.style.border = "1px solid black";
        }
    });
}

decolorer();