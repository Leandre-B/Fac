/**
 * Q4.1 - Evènements
 * Gstionnaire d’évènements pour le bouton “Statistiques".
 */
document.querySelector("input[value=\"Statistiques\"]").addEventListener("click", (e)=>{
    lancerStats();
});

/*******/
function lancerStats() {

    /**
     * Q4.2
     * Stockez dans une variable nommée 'titres', de type Array, tous les élements <li> de la liste <ol> dans la section 'songs'.
     */
    let titres = document.querySelectorAll("ol li");

    console.log(titres.length);

    /**
     * Q4.3 
     * Dans une variable nommée 'albumTitres', filtrez le tableau précédent pour ne garder que les éléments qui sont affichés.
     */
    let albumTitres = [];
    Array.from(titres).filter(t => {
        if(t.style.display != "none"){
            albumTitres.push(t);
        }
    });
    console.log(albumTitres.length);

    let album = albumTitres;
    /**
     * Q4.4
     * Modifiez le tableau 'albumTitres' pour stocker les noms de titres.
     */

    albumTitres = albumTitres.map(alb =>
        alb.innerHTML.split('(')[0]
    );

    console.log(albumTitres);

    /**
     * Q4.5 
     * Dans une variable 'dureeTitres', de type Array, extrayez la durée de chaque titre.
     */
    let dureeTitres = (album).map(t=>t.innerHTML.split("(")[1].split(")")[0]);

    console.log(dureeTitres);

    /**
     * Q4.6
     * Dans une variable 'dureeTotale', de type Float, stockez la durée totale de l'album.
     */
    let dureeTotale = 0;
    dureeTitres.forEach(d => {
        dureeTotale+=parseFloat(d);
    });
    console.log(dureeTotale);

    /**
     * Q4.7
     * Lancez une alerte qui contient : le nom de l'album, le nombre de titres et la durée totale de l'album.
     */

}