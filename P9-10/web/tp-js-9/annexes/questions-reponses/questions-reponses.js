let question = document.getElementById("question");
let reponse = document.getElementById("reponse");

let button = document.getElementById("bt");

let first_click = true;
let x = 0, y = 0, ans = 0;
button.addEventListener("click", ()=>{
    if(first_click){
        reponse.innerText = ""; 
        x = Math.floor(Math.random()*15);
        y = Math.floor(Math.random()*15);
        ans = x + y;
        question.innerText = "Combien font "+ x + " + " + y + "?";

        button.value = "Montrer la réponse";
        button.style.backgroundColor = "salmon";
        first_click = false; 
    }else{ //second click
        reponse.innerHTML = "Réponse : "+ ans; 

        button.value = "Créer une question";
        button.style.backgroundColor = "green";
        first_click = true;
    }
})