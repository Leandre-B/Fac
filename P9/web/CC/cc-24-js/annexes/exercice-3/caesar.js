// Question 1 - Récupérer les caractères contenus dans le tableau HTML d'identifiant "message-code"
// et les stocker dans un tableau JS.

//let mot = [ "Y", "o", "x", "s", "l", "!" ]; // Résultat attendu
//console.log(mot); //Vérification du résultat dans la console.

// Question 2 - Générer un tableau HTML qui contient le mot codé dans le tableau d'id "resultat".
// La ligne contiendra une première case TH vide. 
// Ensuite, chaque caractère du mot sera contenu dans un élément TH.

// Résultat attendu (HTML)
//<table id="resultat">
// <tr>
//     <th> </th>
//     <th>Y</th>
//     <th>o</th>
//     <th>x</th>
//     <th>s</th>
//     <th>l</th>
//     <th>!</th>
// </tr>
//</table>

// Question 3 - Ajouter 25 lignes dans le tableau corespondant aux 25 décalages possible du décalage de César en utilisant la fonction decalageAsciiChar. 
// La fonction decalage(car, dec) prend en paramètre un caractère et son décalage (entier) 
// et renvoie le caractère obtenu en appliquant le décalage. 
// Par exemple : decalage("A", 1) renvoie "B", decalage("A", 3) renvoie "D".

function decalageAsciiChar(car, dec){
    return car.charCodeAt(0)>64 && car.charCodeAt(0)<91 ? String.fromCharCode((car.charCodeAt(0)-65+dec)%26+65) : String.fromCharCode((car.charCodeAt(0)-97+dec)%26+97);
}

// Question 4 - Sans modifier le code des questions précédentes, supprimez la dernière colonne du tableau.

// Question 5 - Le mot décodé est "Bravo". 
// Trouvez le mot décodé dans le tableau HTML et ajoutez la classe "highlight" aux cases de ce mot.

// Question 6 - Appliquez la police de caractères "cursive" à tous les éléments TH de la page.
// Vous appliquerez également la police "serif" par défaut.
