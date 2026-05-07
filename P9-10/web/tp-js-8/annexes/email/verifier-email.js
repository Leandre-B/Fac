var email1 = document.querySelector("#email-1");
var email2 = document.querySelector("#email-2");


function compare(){
    if(email1.value == email2.value){
        email1.classList = "green";
        email2.classList = "green";
    }else{
        email1.classList = "red";
        email2.classList = "red";
    }
}

email2.addEventListener("keyup", compare);
email2.addEventListener("blur", compare);