// Mode strict
"use strict";


// Imports
import {
    Traceur
} from "./traceur.js";
import {
    regénérerTracés_,
    tracer_
} from "./courbes_proto.js";


//////////////////////////////////////////////////////////////////////////////////////////
// Construction d'un traceur
let canevas = document.querySelector('canvas');
let contexte = canevas.getContext("2d");
let marge = {
    "X": 20,
    "Y": 20
};

let maxXY = {
    "X": parseInt(document.querySelector("input[name='max_x']").value),
    "Y": parseInt(document.querySelector("input[name='max_y']").value)
};


let traceur = new Traceur(canevas, contexte, marge, maxXY);
console.dir(traceur);
traceur.tracerRepère();

// Initialisation du log
let log = [];


//////////////////////////////////////////////////////////////////////////////////////////
// Test : trace la fonction identité sur un échantillon de 10 points en couleur orange 
let test = function() {
    // Taille de l'échantillon
    let n = 10;

    // La fonction à tracer
    let f = function(x) {
        return x;
    };

    // Descripteur de la fonction
    let meta_f = {
        "type": "linéaire",
        "f": f,
        "paramètres": [1, 0],
        "strokeStyle": "rgb(255, 165, 0)"
    };

    // Trace la fonction, enregistre son descriptif dans le log et l'affiche dans le tableau HTML
    traceur.dessiner(n, meta_f, log);
}();


//////////////////////////////////////////////////////////////////////////////////////////
// Trace la courbe d'une fonction dès que sa case est cochée dans le formulaire
tracer(traceur, log);


/*
    Met en place un écouteur sur les cases à cocher et si une case est cochée :
    - (1) construit le descripteur de fonction à partir des paramètres renseignés dans le formulaire
            (voir la fonction de test ou la méthode Traceur.dessiner pour le format de descripteur attendu)
            et en générant un code RGB aléatoire à l'aide de la fonction `rgb()`
    - (2) dessine la fonction en invoquant la méthode `dessiner` sur l'objet `traceur`en lui passant
            la taille de l'échantillon renseignée dans le formulaire, le descripteur et le log passé en argument
            (voir la méthode Traceur.dessiner)
    - (3) laisse la case cochée pendant 2 secondes avant de la décocher.
*/
function tracer(traceur, log) {
    document.getElementsByClassName("fonctions")[0].addEventListener("click", e =>{
        
        if(e.target.type== "checkbox"){
            console.log(e.target)
            if(!e.target.checked){
                e.target.checked = true
                return;
            }
            let n = document.getElementsByName("échantillon_n")[0].value;
            let type = e.target.value;
            let param = []
            let sibling = e.target.nextElementSibling;
            while(sibling.nodeName !== "BR") {
                if(sibling.nodeName == "INPUT" || sibling.nodeName == "SELECT"){
                    param.push(sibling.value)
                }
                sibling = sibling.nextElementSibling;
            }
            console.log(param)
            console.log(type)
            let f;
            if(type == "linéaire"){
                f = (x) => (parseInt(x)*parseInt(param[0]) + parseInt(param[1]));
            }else if(type == "exponentiation"){
                f = (x) => (Math.pow(parseInt(x), parseInt(param[0])));
            }else if(type == "racine"){
                f = (x) => (Math.pow(parseInt(x), (1/parseInt(param[0]))));
            }else if(type == "e"){
                f = (x) => (Math.exp(parseInt(x)));
            }else if(type == "logarithme"){
                f = (x) => (Math.log(parseInt(x) / Math.log(param[0])));
            }else if(type == "sinus"){
                f = (x) => (param[0] * Math.sin(2*Math.PI*parseInt(x)/param[1] + param[2]))
            }
            console.log("f(2) : ", f(2))
            let meta_f = {
                "type": type,
                "f": f,
                "paramètres": param,
                "strokeStyle": rgb()
            };
            console.log(n);
            traceur.dessiner(n, meta_f, log);
            log.push(meta_f);

            setTimeout(() => {
                e.target.checked = false;
            }, 2000);
        }

        
    })

}


// Génère un code rgb aléatoire sous forme de chaîne de caractères, p. ex. "rgb(10,240,89)"
function rgb() {
    let r = Math.floor(Math.random() * 256);
    let g = Math.floor(Math.random() * 256);
    let b = Math.floor(Math.random() * 256);
    return "rgb("+r.toString()+","+g.toString()+","+b.toString()+")";  
}


//////////////////////////////////////////////////////////////////////////////////////////
// Regénération du canevas au clic sur le bouton "Regénérer".
regénérerTracés(log);

/*
    Met en place un écouteur sur les clics du bouton de soumission qui, le cas échéant,
    (1) supprime le canevas existant et le remplace par un canevas de même dimension
    (2) construit une instance de Traceur pour ce canevas selon les coordonnées max renseignées dans le formulaire
    (3) trace le repère et éventuellement la grille si le bouton radio a été coché
    (4) redessine les courbes de toutes les fonctions figurant dans le log 
*/
function regénérerTracés(log) {
    // A REMPLACER

    document.querySelector("button[type=\"submit\"]").addEventListener("click", (e)=>{

        let trs = document.querySelectorAll("tr");
        Array.from(trs).forEach((e)=>{
            e.parentNode.removeChild(e)
        });

        canevas = document.querySelector('canvas');
        let parent = canevas.parentNode;
        canevas.parentNode.removeChild(canevas);
        
        let newCaneva = document.createElement("canvas");
        newCaneva.width = 600; newCaneva.height = 600;
        document.querySelector(".courbes").appendChild(newCaneva)

        let contexte = newCaneva.getContext("2d");
        let marge = {
            "X": 20,
            "Y": 20
        };

        let maxXY = {
            "X": parseInt(document.querySelector("input[name='max_x']").value),
            "Y": parseInt(document.querySelector("input[name='max_y']").value)
        };

        let traceur = new Traceur(newCaneva, contexte, marge, maxXY);
        console.dir(traceur);
        traceur.tracerRepère();
        if(document.querySelector(".paramètres[name=\"grille\"]").checked) {
            traceur.tracerGrille();
        }
        console.log("log : " , log)
        let n = document.getElementsByName("échantillon_n")[0].value;
        for(let i =  0; i<log.length; i++){
            traceur.dessiner(n, log[i], log);
        }

    });

    // regénérerTracés_(log);
}



// Gestion du curseur
document.getElementsByName("échantillon_n")[0].onchange =
    function() {
        document.getElementsByName("échantillon_taille")[0].value = this.value;
    };