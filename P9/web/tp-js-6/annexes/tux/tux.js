let body = document.getElementsByTagName("body")[0];
body.style.backgroundColor="black";

let intro  = document.getElementById("intro");
intro.style.backgroundColor="yellow";

let sondage  = document.getElementById("sondage");
sondage.style.backgroundColor="red";
// Question 2 : Centrer images de la div intro 
let intro_img = document.querySelectorAll("#intro img");
Array.from(intro_img).forEach(img => img.classList="center");

// Question 3 : Ajout indication sondage
let sond_mail = document.querySelectorAll("#sondage #email");
Array.from(sond_mail).forEach(m => m.setAttribute("value", "nom.prenom@univ-angers.fr"));


let sond_case_non = document.querySelectorAll("#sondage #non");
Array.from(sond_case_non).forEach(m => m.setAttribute("checked", "checked"));


let sond_case_oui_non = document.querySelectorAll("#sondage label");
Array.from(sond_case_oui_non).forEach(m => {
    if(m.getAttribute("for")=="non"){
        m.innerHTML="No";
    }
    if(m.getAttribute("for")=="oui"){
        m.innerHTML="Yes";
    }
});

// Question 4 : Ajout d'une description textuelle aux images

let img=document.getElementsByTagName("img");
for(let im of img){
    let alt="Image";
    let parent = im.parentNode;
    while(parent.nodeName!="BODY"){
        alt += ("- " + parent.nodeName + " (" +parent.getAttribute("id") + ")");
        parent=parent.parentNode;
    }
    im.setAttribute("alt", alt);
}