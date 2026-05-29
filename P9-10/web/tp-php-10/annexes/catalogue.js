/** 
 * Q3.1 
 * Instruction pour cacher tous les éléments dans la liste ordonnée qui contient les titres des albums.
 */
document.querySelectorAll("li").forEach((li)=>{
    li.style.display = 'none';
});


/**
 * Q3.2
 * Affiche le nom de l'album (entre guillemets doubles) dans l'élément de balise <h4> existant.
 * @param {String} albumName 
 */
function afficherTitre(albumName) {
    document.getElementById("album-name").innerText = albumName;
}



/**
 * Q3.3
 * Affiche ou cache des titres (élements de liste) selon l'album choisi.
 * @param {int} idAlbum ID de l'album 
 */
function afficherPlaylist(idAlbum) {
    document.querySelectorAll("li").forEach((li)=>{
        if(li.classList == idAlbum){
            li.style.display = 'list-item';
        }else{
            li.style.display = 'none';
        }
    });
}

function afficherAlbumDetails(idAlbum, albumName) {
    afficherTitre(albumName);
    afficherPlaylist(idAlbum);
}