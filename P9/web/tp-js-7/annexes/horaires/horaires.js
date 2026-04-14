// Question 1
// Ajout de la ligne d'en-têtes (horaires) au tableau HTML et suppression de la liste

let lis = document.querySelectorAll("li");

let table = document.querySelector("table");
let thead = document.createElement("thead")
for(li of lis ){ 
    let td = document.createElement("td");
    td.innerHTML = li.textContent;
    thead.appendChild(td);
}
table.insertBefore(thead, table.firstChild);

document.getElementById("axes").parentNode.removeChild(document.getElementById("axes"));


// Question 2
// Configuration des labels
var t_labels = [ "Neutre", "Interdit", "A éviter", "Préféré"];
var c_labels = [ "white", "red", "orange", "green"];

let labels = document.querySelectorAll("label");
for(let i=0; i<4; ++i){
    labels[i].innerText = t_labels[i];
    labels[i].style.backgroundColor = c_labels[i];
}

// Question 3
// Configuration des boutons radio

let inputs = document.querySelectorAll("input");
for(let i=0; i<4; ++i){
    inputs[i].name = "preference";
    inputs[i].value = c_labels[i];
}

// Question 4
// Ajout du bouton de soumission

let submit = document.createElement("input");
submit.type = "submit";
submit.name = "ok";
submit.value = "OK";

document.querySelector("fieldset").append(submit);

// Question 5
// Ajout de l'élément `form`

let form = document.createElement("form");
form.appendChild(document.querySelector("fieldset").cloneNode(true));
document.querySelector("body").append(form);