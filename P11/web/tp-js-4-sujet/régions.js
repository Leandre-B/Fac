import {
    parseCSV,
    p_fetch
}
from "./utils.js";

/* 
Fichier CSV listant les régions françaises.
Définition des champs :
    https://www.insee.fr/fr/information/3363419#titre-bloc-26
*/
const url = "./data/régions.csv";

/* 
Promesse extrayant par Fetch le contenu du fichier CSV accessible à l'URL `url` 
et le renvoyant sous la forme d'un tableau d'objets représentant les régions.
Chaque objet a les propriétés suivantes :
- "code" : le numéro de la région (entier)
- "nom" : le nom de la région (chaîne).
Les objets sont triés dans l'ordre croissant des numéros de régions.
*/
export const p_régions =
    // A REMPLACER
    p_fetch(url, "csv")
        .then(réponse=>{
            let lignes = réponse.split("\n");
            console.log(lignes)
            let to_convert = "code;nom\n";
            for(let i =1; i<lignes.length; ++i) {
                to_convert += lignes[i].split(";")[0]+";"+lignes[i].split(";")[3]+"\n";
            }
            return parseCSV(to_convert,"\n", ";")
        });
    // Promise.resolve([]);