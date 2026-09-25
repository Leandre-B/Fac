import {
    Echantillon
} from "./échantillonneur.js";
import {
    tracerGrille,
    transformer,
    tracer,
    dessiner
} from "./traceur_proto.js";

export class Traceur {
    constructor(canevas, contexte, marge, maxXY) {
        // Le canevas
        this.canevas = canevas;

        // Largeur du canevas
        this.L = this.canevas.getAttribute("width");

        // Hauteur du canevas
        this.H = this.canevas.getAttribute("height");

        // Contexte 2D du canevas
        this.contexte = contexte;

        // Les marges horizontale (gauche/droite) et verticale (haute/basse) sous la forme 
        // {"X" : marge_horizontale, "Y": marge_verticale}
        this.marge = marge;

        /*
        Objet {"X" : Mx, "Y": My} où (Mx,My) sont les valeurs maximum pour (x,f(x)) qui seront acceptées en abscisse et ordonnée :
        - un point (maxXY.X,0) aura pour transformé sur le canevas le point situé à l'extrémité droite de l'axe des abscisses.
        - un point (0,maxXY.Y) aura pour transformé le point situé à l'extrémité haute de l'axe des ordonnées.
        */
        this.maxXY = maxXY;

        /*
        Objet {"X":rx, "Y":ry} où rx et ry sont les coefficients multiplicatifs à appliquer aux coordonnées (x,y)
        d'un point (avec -this.maxXY.X <= x <= this.maxXY.X, -this.maxXY.Y <= y <= this.maxXY.Y)
        pour obtenir le décalage en pixels (x*rx,y*ry) par rapport au centre du canevas (cad. l'origine du repère).
        Autrement dit, ajouter (x*rx,y*ry) à la position (u,v) en pixels du centre du canevas (this.repère['X'].centre[0])
        donnera la position du point (son transformé) sur le canevas.
        */
        this.rapportXY = {
            "X": ((this.L - (2 * this.marge.X))) / (2 * this.maxXY.X),
            "Y": ((this.H - (2 * this.marge.Y))) / (2 * this.maxXY.Y)
        };

        /*
        Les 2 points extrêmes et le centre de l'axe des X et l'axe des Y du repère, 
        chacun au format [u,v] où u et v sont les positions du point en pixels
        sur le canevas relativement au coin supérieur gauche. NB. X.centre === Y.centre
            {"X":
                {   "gauche": point du canevas correspondant à l'abscisse minimum,
                    "centre": point du canevas correspondant à l'origine du repère,
                    "droit": point du canevas correspondant à l'abscisse maximum
                },
            "Y":
                {   "bas": point du canevas correspondant à l'ordonnée minimum,
                    "centre": point du canevas correspondant à l'origine du repère,
                    "haut": point du canevas correspondant à l'ordonnée maximum
                }
            }
        */
        this.repère = {
            "X": {
                "gauche": [this.marge.X, Math.floor(this.H / 2)],
                "centre": [Math.floor(this.L / 2), Math.floor(this.H / 2)],
                "droit": [this.L - this.marge.X, Math.floor(this.H / 2)]
            },
            "Y": {
                "bas": [Math.floor(this.L / 2), this.H - this.marge.Y],
                "centre": [Math.floor(this.L / 2), Math.floor(this.H / 2)],
                "haut": [Math.floor(this.L / 2), this.marge.Y]
            }
        };
    }

    // Trace le repère (les 2 axes et leurs échelles de valeurs)
    tracerRepère() {
        // paramétrage du contexte
        this.contexte.strokeStyle = 'black';
        this.contexte.lineWidth = 2;
        this.contexte.setLineDash([]);

        // axe des abscisses
        this.contexte.beginPath();
        this.contexte.moveTo(this.repère.X.gauche[0], this.repère.X.gauche[1]);
        this.contexte.lineTo(this.repère.X.droit[0], this.repère.X.droit[1]);
        this.contexte.stroke();

        // axe des ordonnées
        this.contexte.beginPath();
        this.contexte.moveTo(this.repère.Y.bas[0], this.repère.Y.bas[1]);
        this.contexte.lineTo(this.repère.Y.haut[0], this.repère.Y.haut[1]);
        this.contexte.stroke();

        // échelle des abscisses (21 graduations)
        let uv = this.transformer(this.repère.X.gauche[0], this.repère.X.gauche[1]);
        this.contexte.moveTo(uv.X, uv.Y);
        this.contexte.stroke();
        for (let x = -this.maxXY.X; x <= this.maxXY.X; x += 2 * this.maxXY.X / 10) {
            let uvTexte = this.transformer(x, 0);
            this.contexte.fillText(parseFloat(x).toFixed(2).toString(), uvTexte.X - 10, uvTexte.Y + 10);
        }

        // échelle des ordonnées (21 graduations)
        uv = this.transformer(this.repère.Y.bas[0], this.repère.Y.bas[1]);
        this.contexte.moveTo(uv.X, uv.Y);
        this.contexte.stroke();
        for (let y = -this.maxXY.Y; y <= this.maxXY.Y; y += 2 * this.maxXY.Y / 10) {
            let uvTexte = this.transformer(0, y);
            this.contexte.fillText(parseFloat(y).toFixed(2).toString(), uvTexte.X - 10, uvTexte.Y + 10);
        }
    };

    // Trace la grille
    tracerGrille() {
        // A REMPLACER
        // paramétrage du contexte
        this.contexte.strokeStyle = 'grey';
        this.contexte.lineWidth = 2;
        this.contexte.setLineDash([5,10]);
        
        // grille - colonne
        let ecart = (this.repère.X.droit[0] - this.repère.X.gauche[0])/10;
        for (let x = this.repère.X.gauche[0]; x <= this.repère.X.droit[0]; x += ecart) {
            this.contexte.moveTo(x, this.repère.Y.haut[1]);
            this.contexte.lineTo(x, this.repère.Y.bas[1]);
            this.contexte.stroke();
        }

        // lignes
        for (let y = this.repère.Y.haut[1]; y <= this.repère.Y.bas[1]; y += ecart) {
            this.contexte.moveTo(this.repère.X.droit[0], y);
            this.contexte.lineTo(this.repère.X.gauche[0], y);
            this.contexte.stroke();
        }
    };

    /*
    Calcule le transformé (u,v) sur le canevas d'un point (x,y) et le renvoie au format {"X": u, "Y": v} par 
    - dimensionnement en appliquant les coefficients de this.rapportXY
    - et décalage par rapport au centre du canevas.
    Emet un message d'avertissement en console et renvoie {"X": false, "Y": false} pour tout point (x,y) hors-limite,
    cad. si l'une au moins de ses coordonnées vaut NaN ou +/-Infinity ou si |x| > this.maxXY.X ou |y| > this.maxXY.Y.
    */
    transformer(x, y) {
        //return transformer.call(this, x, y);
        // Check si point de base dans le domaine
        if( x < -this.maxXY.X || x > this.maxXY.X ||
            y < -this.maxXY.Y || y > this.maxXY.Y ||
            x == NaN  || y == NaN || 
            x == +Infinity || x == -Infinity ||
            y == +Infinity || y == -Infinity
            
         ){
            console.log(x, y, "hors limite");
            return {"X" : false, "Y" : false};
         }

        // transformé
        let u = x * this.rapportXY.X + this.L/2;
        let v = -y * this.rapportXY.Y + this.H/2;

        return {"X" : u, "Y" : v};

    };

    /*
    - Transforme le tableau P=[...,[u,v],...] de n points passé en paramètre en un tableau Q de n transformés 
    (positions sur le canevas) par appel à la méthode `this.transformer`.
    - Trace la courbe correspondante à Q en reliant les ordonnées des transformés successifs Q[i].Y et Q[i+1].Y) 
    par des segments (1<=i<n).
    Remarques :
    - Le tracé utilise la couleur CSS `strokeStyle`.
    - Une exception est levée si P ne vérifie pas P[i].X < P[i+1].X (1<=i<n).
    - Les points hors limite sont omis du tracé et donne lieu à un avertissement en console.
    */
    tracer(P, strokeStyle) {
        // A REMPLACER
        //return tracer.call(this, P, 
        // strokeStyle);
        //this.contexte.setLineDash([]);
        let Q = [];
        let lastX = NaN;
        P.forEach((element, i) => {
            if(lastX != NaN){
                lastX = element[0];
                Q.push(this.transformer(element[0], element[1]));
            }
            else
                if(i+1<P.length)
                    if(lastX < element[i+1])
                        console.log("Je leve une exeption !!!!")
                    else
                        Q.push(this.transformer(element[0], element[1]))
        });
        
        this.contexte.strokeStyle = strokeStyle;
        this.contexte.lineWidth = 1;

        this.contexte.beginPath();
        this.contexte.moveTo(Q[0].X, Q[0].Y);
        for(let i=1; i<Q.length; i++) {
            this.contexte.lineTo(Q[i].X, Q[i].Y);
        }
        this.contexte.stroke();  
        //console.log(Q);

    };

    /* 
    Procède en 3 étapes :
    (1) Génère pour la fonction réelle décrite par `meta_f` un échantillon de `n` points 
            dont les abscisses sont répartis à intervalles réguliers dans l'intervalle [-this.maxXY.X,this.maxXY.X]
    (2) Trace la courbe échantillonnée sur le canevas selon la fréquence renseignée par le visiteur
    (3) Ajoute le descripteur `meta_f` au tableau `log` et ajoute une ligne au tableau HTML 
    contenant la formulation algébrique de la fonction.

    Le descripteur `meta_f` est au format
    {
        "type": chaîne dans {"linéaire", "exponentiation", "racine", "e", "logarithme", "sinus"}
        "f": fonction de rappel JS implémentant la fonction décrite
        "paramètres": tableau (potentiellement vide) des paramètres de la fonction dans l'ordre des champs HTML correspondants
        "strokeStyle": code couleur CSS pour tracer et tabuler la fonction (p. ex. "orange" ou un code RGB "rgb(5,200,89)")
    }

    Remarques :
    - L'échantillonnage s'effectue par invocation de la méthode `points` sur une instance d'`Echantillon`.
    - Si la fréquence de tracé F (renseignée dans le champ du formulaire) est > 0, 
        le tracé est non-bloquant (cad. asynchrone en utilisant `setInterval`) et chaque segment de la courbe 
        est tracé toutes les F/10 secondes en commençant par le point le plus à gauche.
    - La ligne (mono-cellule) à ajouter au tableau HTML contiendra une chaîne de caractères construite à partir
        du type de la fonction et de la valeur de ses arguments (p. ex. "2x + 1", "3 sin(2Pix/4 + 1.07").
    - La couleur `meta_f.strokeStyle` est utlisée pour le tracé et comme couleur de fond de la ligne HTML.
    */
    dessiner(n, meta_f, log) {
        // A REMPLACER
        //return dessiner.call(this, n, meta_f, log);
        console.log("meta_f : ", meta_f);
        let echantillon = new Echantillon(meta_f.f, n, {"max" : this.maxXY.X, "min" : -this.maxXY.X});
        // Génération d'un échantillon de n points de la fonction f
        let points = echantillon.points();
        console.log(points);
        console.log(meta_f);

        let fréquence = document.querySelector("input[name=\"échantillon_f\"]").value;
        console.log(fréquence);
        // Tracé de l'échantillon
        if(fréquence > 0) {
            let p = 0;
            const interval = setInterval(() => {
                this.tracer(points.slice(p, p+2), meta_f.strokeStyle);
                p++;
                if(p >= n)
                    clearInterval(interval);
            }, fréquence/10*1000);
        }else {
            this.tracer(points, meta_f.strokeStyle);
        }

        // Log de la fonction et affichage dans le tableau
        let t = document.querySelector("table");
        let tr = document.createElement("tr");
        let type = meta_f.type;
        let param = meta_f.paramètres;
        if(type == "linéaire"){
            tr.innerText = param[0]+"x + "+param[1];
            tr.style.backgroundColor = meta_f.strokeStyle;
        }else if(type == "racine"){
            tr.innerHTML = "x<sup>1/"+param[0]+"</sup>";
            tr.style.backgroundColor = meta_f.strokeStyle;
            
        }else if(type == "exponentiation"){
            tr.innerHTML = "x<sup>"+param[0]+"</sup>";
            tr.style.backgroundColor = meta_f.strokeStyle;
        }else if(type == "e"){
            tr.innerHTML = "e<sup>x</sup>";
            tr.style.backgroundColor = meta_f.strokeStyle;
        }else if(type == "logarithme"){
            tr.innerHTML = "log10("+param[0]+"x)";
            tr.style.backgroundColor = meta_f.strokeStyle;
        }else if(type == "sinus"){
            tr.innerHTML = param[0]+" sin(2Πx/"+param[1]+" + "+param[2]+")";
            tr.style.backgroundColor = meta_f.strokeStyle;
        }
        console.log(type)
        t.appendChild(tr)
    };
}