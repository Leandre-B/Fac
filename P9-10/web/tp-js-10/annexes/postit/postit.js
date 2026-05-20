// A COMPLETER

function updateDate(){
    let div = document.getElementById("postit");
    let date = new Date();
    let day;
    switch (parseInt(date.getDay())) {
        case 1:
            day = "Lundi";
            break;
        case 2:
            day = "Mardi";
            break;
        case 3:
            day = "Mercredi";
            break;
        case 4:
            day = "Jeudi";
            break;
        case 5:
            day = "Vendredi";
            break;
        case 6:
            day = "Samedi";
            break;
        case 7:
            day = "Dimanche";
            break;
        default:
            day="NULL"
            break;
    }
    div.innerHTML = day + "<br>" + date.getHours() + ":" + date.getMinutes() + ":" + date.getSeconds();
}

setInterval(updateDate, 500);