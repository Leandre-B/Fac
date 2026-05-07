let ajout = document.getElementById("ajouter");
let supprimer = document.getElementById("supprimer");

let div = document.getElementById("ici"); //RPZ Xxx_Raphael49_xxX
let ol;
let empty = new Boolean(true);

ajout.addEventListener("click", ()=>{
    if(empty){
        ol = document.createElement("ul");
        div.appendChild(ol);
        empty = false;
    }
    let li = document.createElement("li");
    li.innerHTML = prompt("ajouter un element");
    ol.appendChild(li);
});

supprimer.addEventListener("click", ()=> {
    div.removeChild(ol);
    empty = true;
});