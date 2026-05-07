let aside = document.querySelector("aside");
let button = document.querySelector("input");

button.addEventListener("click", ()=>{
    console.log("hey");
    if(aside.getAttribute("hidden") == "true")
        aside.removeAttribute("hidden");
    else
        aside.setAttribute("hidden", true);
});