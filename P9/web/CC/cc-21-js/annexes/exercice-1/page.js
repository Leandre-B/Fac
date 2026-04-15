// Question 1 : l'option Maine-et-Loire est sélectionnée par défault
let opt = document.querySelector("option[value=\"49\"]");
opt.selected=true;

// Question 2 : les paragraphes de classe "info" sont mis en italique et de couleur grise
let p_info = document.querySelectorAll(".info");
Array.from(p_info).forEach(p =>{
    p.style.color = "grey";
    p.style.fontStyle = "italic";
});

// Question 3 : Tous les labels contenant un point d'interrogation sont mis en bleu
let labels = document.querySelectorAll("label");
Array.from(labels).forEach(l => {
    if(l.textContent.split('').includes("?")){
        l.style.color = "blue";
    }
        
});

// Question 4 : Le texte du paragraphe de la div d'identifiant "intro" est mis entre balise em (à l'exception du texte entre balise b)
let p = document.querySelector("#intro p");
let txt = "";
p.childNodes.forEach(c => {
    if(c.nodeName=="B")
        txt+="<b>"+c.textContent+"</b>"
    else
        txt+="<em>"+c.textContent+"</em>"
});
p.innerHTML = txt;

// Question 5 : Si l'âge saisi est inférieur à 18 masquer les deux questions concernant le permis de conduire
let age = parseInt(document.querySelector("input[name=\"age\"]").value);
console.log(age);
if(age<18){
    document.querySelector(".permis").hidden = true;
}

// Question 6 : Si l'utilisateur à coché Oui à la question "Avez-vous le permis de conduire ?" alors masquer la question d'après ("Si non, pourquoi ?")
if(document.querySelector("input[value=\"oui\"]").checked){
    document.querySelector("label[for=\"permisNon\"]").hidden = true;
    document.querySelector("input[name=\"permisNon\"]").hidden = true;
}