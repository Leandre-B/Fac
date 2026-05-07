let input = document.querySelectorAll("input");
let check = document.querySelector("#check")
let uncheck = document.querySelector("#uncheck")

check.addEventListener("click", ()=>{
    Array.from(input).forEach(checkbox => {
        checkbox.checked = true;
        console.log(checkbox);
    });
});


uncheck.addEventListener("click", ()=>{
    Array.from(input).forEach(checkbox => {
        checkbox.checked = false;
    });
});