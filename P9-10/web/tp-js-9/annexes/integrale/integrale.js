// Variable fonctionnelle JS dénotant et implémentant la fonction choisie par le visiteur 
let f = function(x) {
    return x;
};

// Force l'option linear au rechargement de la page
document.querySelector("option[value=\"linear\"]").selected = true;

// Ecouteur du menu déroulant
let selectlistener = document.querySelector("#fx").addEventListener("change", function(e) {
    if(e.currentTarget.value == "quadratic")
        f = function(x){return x*x;};
    else //[0]
        f = function(x){return x;};
});


// Renvoie le tableau a = [x1 + ((i * (x2 - x1)) / n) | i = 0..n] 
// qui segmente [x1,x2] en n intervalles contigus et de mêmes tailles
function segmentation(x1, x2, n) {
    let a = [];
    for (let i = 0 ; i <= n ; i++) {
         a[i] = x1 + ((i * (x2 - x1)) / n);
    }

    return a;
}

// Renvoie l'approximation de la valeur de l'intégrale de f sur [x1,x2]
// obtenue par la méthode des rectangles à GAUCHE basée sur une décomposition en n intervalles
function integrale_rectangle_gauche(f, x1, x2, n) {
    let a = segmentation(x1, x2, n);
    r = 0.0;
    for (let i = 0; i < n; ++i) {
        r += Math.abs(f(a[i]));
    }

    return (r * (x2 - x1)) / n;
}

// Renvoie l'approximation de la valeur de l'intégrale de f sur [x1,x2]
// obtenue par la méthode des rectangles à DROITE basée sur une décomposition en n intervalles
function integrale_rectangle_droite(f, x1, x2, n) {
    let a = segmentation(x1, x2, n);
    let r = a.reduce(
        (acc, curr) => acc + Math.abs(f(curr)), 0
    );
    return (r * (x2 - x1)) / n;
}

// Renvoie l'approximation de la valeur de l'intégrale de f sur [x1,x2] par la méthode des trapèzes
function integrale_trapeze(f, x1, x2, n) {
    return (integrale_rectangle_gauche(f, x1, x2, n) + integrale_rectangle_droite(f, x1, x2, n)) / 2;
}

// Renvoie l'approximation de la valeur de l'intégrale de f sur [x1,x2] par la méthode de Simpson
function integrale_simpson(f, x1, x2, n) {
    let a = segmentation(x1, x2, n);
    let r = 0.0;
    for (let i = 0; i < n; ++i) {
        r += (a[i + 1] - a[i]) / 6 * (f(a[i]) + 4 * f((a[i] + a[i + 1]) / 2) + f(a[i + 1]));
    }

    return r;
}

// Ecouteur du bouton "calculer"
// A COMPLETER
let btn_calc = document.querySelector("input[value=\"calculer\"]");
btn_calc.addEventListener("click", ()=>{
    let x1 = (parseInt(document.getElementById("x1").value));
    let x2 = (parseInt(document.getElementById("x2").value));
    let interval = parseInt(document.getElementById("itv").value);
    
    document.getElementById("meth1").value=integrale_rectangle_droite(f, x1, x2, interval);
    document.getElementById("meth2").value=integrale_trapeze(f, x1, x2, interval);
    document.getElementById("meth3").value=integrale_simpson(f, x1, x2, interval);
})

// Ecouteur du bouton "effacer"
// A COMPLETER
let btn_eff = document.querySelector("input[value=\"effacer\"");
btn_eff.addEventListener("click", ()=>{
    document.getElementById("x2").value    ="";
    document.getElementById("x1").value    =""
    document.getElementById("meth1").value ="";
    document.getElementById("meth2").value ="";
    document.getElementById("meth3").value ="";
});