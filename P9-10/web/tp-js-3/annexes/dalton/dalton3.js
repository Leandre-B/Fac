function Famille(nom){
    if(nom==undefined)
        this.nom="";
    else
        this.nom=nom;
    this.membres=[];
}

let DALTON=new Famille("Dalton");

Famille.prototype.ajouter = function(obj){
    this.membres.push(obj.prenom);
};

DALTON.ajouter(averell);
Famille.prototype.ajouter.call(DALTON, jack);
[joe, william].map(d=>DALTON.ajouter(d));

Famille.prototype.afficher = function(){
    console.log(this.nom);
    this.membres.map(d=> console.log(d));
};

DALTON.afficher();