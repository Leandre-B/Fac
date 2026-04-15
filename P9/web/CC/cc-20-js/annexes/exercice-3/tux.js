// Question 1 : Coloration
document.querySelector("body").style.backgroundColor="black";

//intro et sondage, respectivement, en orange et en rouge

document.getElementById("intro").style.backgroundColor="orange";
document.getElementById("sondage").style.backgroundColor="red";

for(let child of document.getElementById("intro").children){
    child.style.color = "white";
}

for(let child of document.getElementById("sondage").children){
    child.style.color = "white";
}

// Question 2 : Centrer images de la div intro
let imgs = document.querySelectorAll("#intro img");
Array.from(imgs).forEach(img => {
    img.classList = "center";
});

// Question 3 : Ajout indication sondage
let emails = document.querySelectorAll("[id=\"email\"]");
Array.from(emails).forEach(m => {
    m.value = "nom.prenom@univ-angers.fr";
});


let cases = document.querySelectorAll("[value=\"non\"]");
Array.from(cases).forEach(m => {
    m.checked = "checked";
});

let labels = document.querySelectorAll("label");
Array.from(labels).forEach(m => {
    console.log(m);
    if(m.getAttribute("for")=="oui")
        m.innerText = "Yes";
    if(m.getAttribute("for")=="non")
        m.innerText = "No";
});

// Question 4 : Ajout d'une description textuelle aux images
imgs = document.querySelectorAll("img");
Array.from(imgs).forEach(img => {

    
    let txt = "Image";
    let parent = img.parentNode;
    do{
        txt+=(" - " + parent.nodeName + " (" + parent.id + ")");
        parent = parent.parentNode;
    }while(parent.nodeName!="BODY")
    
    console.log(txt);
    let alt = document.createElement("alt");
    img.alt = txt;
    
});
