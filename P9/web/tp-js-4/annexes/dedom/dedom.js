
//supprime form et titre associé grace a la méthode previousElementSibling
let form=document.getElementsByTagName("form")[0]; //elem form, sinon form + autre chose lié au form
(form.previousElementSibling).parentNode.removeChild(form.previousElementSibling);
form.parentNode.removeChild(form);

//centre texte tableau et ajoute bodure
Array.from(document.getElementsByTagName("td")).forEach(td=>{
    td.style.textAlign="center";
    td.style.border="solid 1px magenta";
});

document.getElementsByTagName("table")[0].style.borderCollapse="collapse";

//remove intro et titre associé
let intro=document.getElementById("intro");
intro.nextElementSibling.parentNode.removeChild(intro.nextElementSibling);
intro.parentNode.removeChild(intro);

//applique font cursive au elem du sommaire si commence par D, sinon, affiche icone
Array.from(document.getElementsByTagName("ol")[0].childNodes).forEach(li=>{
    let txt = li.textContent;
    if(txt[0]=='D'){
        li.style.font="Cursive";
    }else if(li.nodeType==1){
        li.textContent="\u26A0";
    }
});

//centre tout les titres h2
Array.from(document.getElementsByTagName("h2")).forEach(h=>{
    h.style.textAlign="center";
})