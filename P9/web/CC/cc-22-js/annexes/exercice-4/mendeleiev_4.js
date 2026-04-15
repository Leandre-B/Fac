// Q1
// Complétez l'implémentation de la fonction `estElement` qui prend en argument une cellule du tableau
// et détermine si elle contient ou non des données.
// Précisément, la fonction retournera `true` si :
// - la cellule n'est pas vide (autrement dit, elle a au moins 1 noeud enfant), et
// - le nom indiqué dans la cellule est différent de `*` et `**`.
// Testez la fonction en console qui retournera `true` sur la 1ère cellule du tableau 
// et faux sur la 59ème cellule.
function estElement(td) {
    if(td.children.length==0)
        return false;
    for(let e of td.children){
        if(e.nodeName=="A"){
            if(e.innerText=="*" || e.innerText=="**")
                return false;
        }
    }
    return true;
}

// Q2
// La fonction `transformerTableau` vise à remplacer le tableau périodique
// par un nouveau tableau HTML contenant une ligne par élément atomique,
// chaque ligne étant décomposée en 4 cellules contenant, respectivement,
// le numéro, nom, symbole et masse de l'élément.
// L'implémentation partielle qui vous est donnée crée le tableau et sa ligne d'en-têtes. 
// Votre implémentation devra donc récupérer les données correspondant à chaque élément,
// créer et ajouter la ligne de l'élément au tableau,
// ajouter ce dernier à la page, puis supprimer le tableau d'origine.
// Utilisez la fonction `estElement` développée en question précédente 
// pour ne traiter que les  cellules ``non vides'' du tableau d'origine.
function transformerTableau() {
    // tableau
    var tableHTML = document.createElement("table");
    tableHTML.id = "tabular";
    // en-têtes du tableau
    var rowHTML = document.createElement("tr");
    const headers = ["Numero", "Nom", "Symbole", "Masse"];
    for (const i in headers) {
        let headerHTML = document.createElement("th");
        headerHTML.innerText = headers[i];
        rowHTML.appendChild(headerHTML);
    }
    tableHTML.appendChild(rowHTML);

    for(let td of document.querySelectorAll("td")){
        if(estElement(td)){
            let tr = document.createElement("tr");
            for(let e of td.children){
                if(e.nodeName!="BR"){
                    let td = document.createElement("td");
                    if(e.nodeName=="SPAN")
                        td.textContent = (e.textContent);
                    if(e.nodeName=="A"){
                        td.textContent = (e.title);

                        let td2 = document.createElement("td");
                        td2.textContent = (e.textContent); 
                        tr.appendChild(td2);
                    }
                    tr.appendChild(td);
                }
            }
            tableHTML.appendChild(tr);
        }
    }

    document.getElementById("mendeleiev").parentNode.removeChild(document.getElementById("mendeleiev"))
    document.querySelector("body").appendChild(tableHTML);
    
}

transformerTableau();