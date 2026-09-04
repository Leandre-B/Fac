// 2 variables globales à modifier dans l'écouteur window.onload
var countries = {
    "names": [], // ["Afghanistan", ...]
    "codes": {}, // {"Afghanistan":"AF", ...}
    "flags": {} // {"Afghanistan":"data:image...", ...}
};

var continents = []; // [{"Asia":["Afghanistan","Armenia",...]}, ...]


window.addEventListener("load", (event) => {
    // Q1 Extraction des noms de pays à partir du tableau HTML
    countries.names = Array.from(document.querySelectorAll(".main td")).map((c) => c.id);
    console.log(countries.codes);

    // Q2 Extraction des codes de pays du fichier country_codes.json
    fetch('country_codes.json', {
        method: 'GET'
    })
        .then((response) => response.json())
        .then((country_codes) => {
            
            console.log('Success:', country_codes);
            country_codes.forEach((e) =>
                countries.codes[Object.entries(e)[0][0]] = Object.entries(e)[0][1]
            );
            return countries.codes;
        })
        .catch((error) => {
            console.error('Error:', error);
        });
    console.log(countries);

    // Q3 Extraction des continents de pays à partir du tableau country_continents (importé de country_continents.js) 
    
    let continents_name = new Set(country_continents.map((e) => e["continent"]));
    continents_name = Array.from(continents_name).sort();
    continents_name.forEach(c => {
        let obj = {};
        obj[c] = [];
        country_continents.forEach(cc => {
            if (Object.entries(cc)[1][1] == c)
                obj[c].push(Object.entries(cc)[0][1])
        });
        continents.push(obj);
    });

    //console.log(continents);

    // Q4 Extraction des drapeaux de pays à partir de la constante country_flags (importée de country_flags.js) 
    
    country_flags.forEach(e => {
        countries.flags[e["country"]] = e["flag_base64"];
    });

    //console.log(countries.flags);

    // Q5 Mise en forme CSS
    
    Array.from(document.querySelectorAll(".main td")).forEach((td) => {
        td.style.textAlign = "center";
        td.style.fontSize = "75%";
    }
    );
    document.querySelectorAll("div")[1].classList = "Row"
    document.querySelectorAll("div")[1].childNodes[1].classList = "side";



});



let handleSelectors = function () {
    // Q6 Gestion du menu
    
    document.getElementById("continents").addEventListener("click", (e) => {
        let continent = e.target.value;
        if (continent == 'all') {
            Array.from(document.querySelectorAll(".main td")).forEach((td) => { td.style.visibility = "visible"; })
        }
        else {
            Array.from(document.querySelectorAll(".main td")).forEach((td) => {
                td.style.visibility = "hidden";
                let pays = td.id;
                continents.forEach((c) => {
                    if (Object.entries(c)[0][0] == continent) {
                        Object.entries(c)[0][1].forEach(element => {
                            if (pays == element)
                                td.style.visibility = "visible";
                        });

                    }

                });
            });
        }
    });

}();


let handleRadios = function () {
    // Q7 gestion des boutons radio
    
    Array.from(document.querySelectorAll("input")).forEach((radio) => {
        radio.addEventListener("click", (e) => {
            let choix = e.target.value;
            Array.from(document.querySelectorAll(".main td")).forEach((td) => {
                if (choix == "noms") {
                    td.innerText = td.id;
                } else if (choix == "codes") {
                    td.innerText = countries.codes[td.id];
                } else if (choix == "drapeaux") {
                    td.innerText = td.id;
                    country_flags.forEach(element => {
                        if (Object.entries(element)[0][1] == td.id)
                            td.innerHTML = "<img class=\"flag\"src = \"" + Object.entries(element)[1][1] + "\">";
                    });
                }
            });
        });
    });


}();

let handleHeader = function f() {
    let tds = document.querySelectorAll("td");
    tds.forEach(function (td) {
        td.addEventListener("click", function (e) {
            let country_name = e.target.id;
            if (country_name) {
                fetch('country_features.php', {
                    method: 'POST',
                    body: new URLSearchParams("country_name=" + country_name),
                })
                    .then((response) => response.json())
                    .then((country) => {
                        console.log('Success:', country);
                        // Q8 clic sur cellule

                        let header = document.querySelector(".header");

                        let government = country["government"] == null ? "?" : country["government"];
                        let expectancy = country["expectancy"] == null ? "?" : country["expectancy"];
                        header.innerHTML = country_name + " : <break> government : " + government + ", expectancy" + country["expectancy"];


                        return country;
                    })
                    .catch((error) => {
                        console.error('Error:', error);
                    });
            }
        });
    });
}();