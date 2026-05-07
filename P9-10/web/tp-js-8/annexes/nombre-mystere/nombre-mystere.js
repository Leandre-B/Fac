let button = document.querySelector("button");
let result = document.querySelector("#resultat");
let input = document.querySelector("input");

let mysteryNumber = Math.floor(Math.random()*30);
let tent = 0;
//console.log(mysteryNumber);

button.addEventListener("click", ()=>{
    if(tent == 5){
        result.innerHTML = "Perdu ! Tentatives : " + tent;
        let img = document.createElement("img");
        img.src = "https://media.tenor.com/lyZro0MzHSoAAAAM/take-the-l.gif"
        img.style.width = "500px";
        img.style.height = "500px";
        result.appendChild(img);
    }else{
        if(isNaN(parseInt(input.value)))
            result.innerHTML = "PAS UN NOMBRE !!!";
        else
            tent++;
        if(parseInt(input.value) < mysteryNumber)
            result.innerHTML = "Trop bas ! ";
        else if(parseInt(input.value) > mysteryNumber)
            result.innerHTML = "Trop haut ! ";
        else if(parseInt(input.value) == mysteryNumber){
            result.innerHTML = "OUI OUI OUI OUI ! Tentatives : " + tent;
            let img = document.createElement("img");
            img.src = "https://media.tenor.com/K6nCU-HZwvMAAAAM/lepers-oui.gif"
            img.style.width = "500px";
            img.style.height = "500px";
            result.appendChild(img);
        }
    }w
});
