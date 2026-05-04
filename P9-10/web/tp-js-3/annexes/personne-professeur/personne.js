function Personne(nom, prenom, age, interets){
    this.nom=nom;
    this.prenom=prenom;
    this.age=age;
    this.interets=interets;
}

Personne.prototype.salutation = function(){
    alert("Bonjour, je m'appelle "+this.prenom);
}

Personne.prototype.bio = function(){
    let int="";
    for(i of this.interets){
        int+=i+" ";
    }
    alert(this.prenom + " " + this.nom + " a " + this.age +" ans " + " et aime : "+int);
}

Personne.prototype.aurevoir = function(){
    alert(this.prenom + " est sorti. Au revoir !");
}

let jean = new Personne("Jean", "Devil", 12, ["ski", "cuisine"]);

// for(i in jean){
//     console.log(i);
// }

// jean.salutation();
// jean.bio();
// jean.aurevoir();