// averell.nom="Dalton";
// joe.nom="Dalton";
// jack.nom="Dalton";
// william.nom="Dalton";

Dalton.prototype.nom="Dalton";
//Dalton.nom="Dalton";

Dalton.prototype.afficher = function (){
    console.log(this.prenom, this.nom);
};

let daltons=[averell, joe, jack, william];
// for(d of daltons){
//     d.afficher();
// }
daltons.map(d=>d.afficher());

console.log(william.hasOwnProperty("nom"));
for( prop in william){
    console.log(prop);
}

for( d in daltons ){
    console.log(d, daltons[d]);
}

delete Dalton.prototype.nom;

for( d in daltons ){
    console.log(d, daltons[d]);
}

(daltons.filter( d=>d.prenom[0]=='J')).map(truc => console.log(truc));

