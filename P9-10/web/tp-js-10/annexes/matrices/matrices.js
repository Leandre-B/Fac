/*
 * Quand l'un des deux boutons radio est coché, remplace les 2 matrices
 * existantes par 2 matrices m x n identiques d'entiers tirés aléatoirement 
 * selon les dimensions et le type de matrices prescrits par les champs 
 * numériques et le bouton coché en appelant la fonction générerEtat().
 */

document.getElementById("integer").addEventListener("click", ()=>{
    générerEtat();
});

document.getElementById("binary").addEventListener("click", ()=>{
    générerEtat();
});

/*
 * Remplace les 2 matrices existantes par 2 matrices m x n identiques et
 * tirées aléatoirement à chaque changement de valeur des champs 'Lignes'
 * (m) ou 'Colonnes' (n) en appelant la fonction générerEtat().
 */

document.getElementById("rows").addEventListener("click", ()=>{
    générerEtat();
});

document.getElementById("columns").addEventListener("click", ()=>{
    générerEtat();
});


/*
 * Transpose la matrice modélisée par le tableau HTML 'table' passé en argument
 * si elle est carré en "transposant" le tableau (y compris ses libellés), affiche 
 * une alerte sinon.
 */
function transposer(table) {
    let N = parseInt(document.getElementById("rows").value)+1;
    let newT = Array(N);
    for(let i=0; i<N; ++i){
        newT[i] = Array(N);
        for(let j=0; j<N; ++j){
            newT[i][j] = table.rows[i].cells[j].innerText;
        }
    }
    for(let i=0; i<N; ++i){
        for(let j=0; j<N; ++j){
            table.rows[i].cells[j].innerText = newT[j][i];
        }
    }
}

/*
 * Transpose la matrice de l'élément de classe 'mat2' à chaque clic sur le
 * bouton 'Transposer' uniquement si la matrice est carré, émet une alerte
 * sinon. La transposition se fait en appelant la fonction transposer(table).
 */

document.querySelector(".transposer").addEventListener("click", ()=>{
    if(parseInt(document.getElementById("rows").value) == parseInt(document.getElementById("columns").value)){
        transposer(document.querySelector(".mat2 table"));
    }else{
        alert("Matrice non carré !");
    }
});


/*
 * Permute les lignes i et j (où i<j) du tableau HTML 'table'.
 */
function permuterLignes(table, i, j) {
    let N = parseInt(document.getElementById("columns").value)+1;
    for (let k = 0; k < N; k++) {
        let aux = table.rows[i].cells[k].innerText;
        table.rows[i].cells[k].innerText = table.rows[j].cells[k].innerText;
        table.rows[j].cells[k].innerText = aux;
    }
}

/*
 * Permute deux lignes tirées aléatoirement (y compris leurs libellés) dans la 
 * matrice de l'élément de classe 'mat2' à chaque clic sur le bouton 'Permuter'.
 * Les tirages aléatoires s'effectuent par appel à la fonction tirerEntier().
 * La permutation de lignes s'effectue par appel à la fonction permuterLignes().
 */
// A COMPLETER
document.querySelector(".permuter").addEventListener("click", ()=>{
    let table = document.querySelector(".mat2 table");
    let i = tirerEntier(1, parseInt(document.getElementById("rows").value));
    let j = tirerEntier(i, parseInt(document.getElementById("rows").value));
    permuterLignes(table, i, j);
});