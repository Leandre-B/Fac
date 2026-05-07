let ol = document.querySelector("ol");

ol.addEventListener("click", (e)=>{
    let new_text = prompt("Entrer le nouveau texte : ");
    e.target.innerHTML = new_text;

})