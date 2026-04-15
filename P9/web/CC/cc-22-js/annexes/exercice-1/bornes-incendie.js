// Q1
// Supprimez le premier et le dernier élément du tableau `bornesIncendie`.
// Après ces suppressions, la taille de `bornesIncendie` est de 3474.

bornesIncendie.shift();
bornesIncendie.pop();

// Q2
// Affichez dans la console le nombre de bornes à incendie présentes 
// au sein de la commune dénommée `LES PONTS-DE-CE`.

let nb = 0;
bornesIncendie.forEach(b => {
    if(b.commune=="LES PONTS-DE-CE")
        nb++
});
console.log(nb);

// Q3
// Créez un tableau contenant un code, créé sur mesure, pour chaque borne. 
// Le code sera composé des 3 premières lettres de la commune 
// suivies d'un tiret et du numéro pompier (`num_pompier`).
let codes = [];
bornesIncendie.forEach(b => {
    codes.push(b.commune.slice(0, 3)+"_"+b.num_pompier);
});
console.log(codes);


// Q4
// Affichez dans une popup s'il existe au moins une borne incendie 
// dans une ville saisie par l'utilisateur. Attention : les noms de communes 
// sont stockés en majuscules dans le tableau `bornesIncendie`.

let ville = prompt("saisir ville : ");
let found = new Boolean(false);
for(let b of bornesIncendie){
    if(ville.toLowerCase()===b.commune.toLowerCase()){
        alert("Il existe au moins une borne incendie à "+b.ville)
        found=true;
        break;        
    }
}
if(found==false){
    alert("Il n'existe pas de borne incendie à "+ville)
}

// Q5
// Affichez dans la console le débit d'eau cumulé des bornes à incendie 
// du tableau `bornesIncendie`. Attention, pour certaines bornes, le débit prend 
// la valeur `null`.

let debit = 0;
bornesIncendie.forEach(b => {
    if(!isNaN(parseFloat(b.debit)))
        debit+=parseFloat(b.debit);
});
console.log(debit);

