
/*
 * Askip pas ouf, Professeur.prototype.saluer = function(){ fonctionne pas avec ça
function Professeur(nom, prenom, age, interets, matiere){
    this.__proto__= new Personne(nom, prenom, age, interets);
    this.matiere=matiere;
}*/

function Professeur(nom, prenom, age, interets, matiere){
    Personne.call(this, nom, prenom, age, interets);
    this.matiere = matiere;
}

Professeur.prototype = Object.create(Personne.prototype);
Professeur.prototype.constructor = Professeur;

Professeur.prototype.saluer = function(){
    alert("Bonjour, mon nom est "+this.nom+" "+this.prenom+", et j'enseigne : " + this.matiere+".");
}

let hilbert = new Professeur("Mr", "Hilbert", 68, ["Histoire, Danse"], "Histoire");

hilbert.saluer();
hilbert.bio();

