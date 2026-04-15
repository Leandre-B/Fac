//
// CC2 DevWeb L2 : Exercice 2
//

// À COMPLETER
function genererTableau() 
{   
    let span = document.createElement("span");
    let date = new Date();
    span.innerText = "Tableau généré le "+ date.toString();


    let lignes = parseInt(document.querySelectorAll("input")[0].value);
    let colonnes = parseInt(document.querySelectorAll("input")[1].value);

    if(lignes<1 || colonnes<1){
        let p = document.createElement("p");
        p.style.color = "red";
        p.innerText = "Erreur ! Vérifiez que le nombre de lignes ou colonnes soit supérieur à zero";
        document.querySelector("div").append(p);
        return;
    }

    let table = document.createElement("table");
    for(let i=0; i<lignes; i++){
        let tr = document.createElement("tr");
        for(let j=0; j<colonnes; j++){    
            let td = document.createElement("td");
            td.textContent = Math.round(Math.random() * 100);
            tr.append(td);
        }
        table.append(tr);
    }

    document.querySelector("div").append(span);
    document.querySelector("div").append(table);
}

// À COMPLETER
function supprimerOutput() 
{
    let tables = document.querySelectorAll("table");
    tables.forEach(t => {
        t.parentNode.removeChild(t);
    });

    let spans = document.querySelectorAll("span");
    spans.forEach(s => {
        s.parentNode.removeChild(s);
    });

    let ps = document.querySelectorAll("p");
    ps.forEach(p => {
        p.parentNode.removeChild(p);
    });
}
