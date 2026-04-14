words = ["a", "abat", "abbé", "abri", "abus", "ac.", "ace", "aces", "acte", "aéra", "aère", "aéré", "afin", "agi", "agio", "agir", "agis", "agit", "ah", "ai", "aida", "aide", "aidé", "aie", "aies", "aigu", "ail", "aile", "ailé", "aima", "aime", "aimé", "aine", "aîné", "air", "aire", "airs", "aise", "aisé", "ait", "al.", "aléa", "alfa", "alla", "allé", "allô", "aloi", "alto", "alu", "amas", "amen", "amer", "ami", "amie", "amis", "an", "and", "ange", "anis", "ans", "anse", "anus", "août", "apr.", "apte", "arc", "arcs", "ardu", "are", "ares", "aria", "arma", "arme", "armé", "art", "arts", "as", "au", "aube", "auge", "aune", "aura", "auto", "aux", "av.", "aval", "avec", "aveu", "avez", "avis", "avr.", "axa", "axe", "axé", "axée", "axer", "axes", "axés", "axez", "ayez", "azur"];

// Q1 Créer et afficher le tableau associant à chaque mot de `words` sa taille (nombre de caractères).
// Afficher ensuite la taille maximum des mots du tableau.
let sizes = null;
console.log("sizes");
console.table(sizes);
let lmax = null;
console.log("lmax=" + lmax);

// Q2 Filtrer le tableau `words` pour ne conserver que les mots de 2 caractères ou plus et ne comportant ni "i", ni "o", ni "u".
// Afficher le tableau résultant nommé `filtered` (51 mots).
let filtered = null;
console.log("filtered");
console.table(filtered);

// Q3 Créer le tableau où chaque mot de `filtered` a été remplacé par le mot inversant ses caractères (p. ex. "abat" devient "taba").
// Afficher le tableau résultant nommé `flipped`.
let flipped = null;
console.log("flipped");
console.table(flipped);

// Q4 Tronquer les mots de 4 caractères du tableau `flipped` en supprimant leur premier caractère et en laissant inchangés les autres mots.
// Afficher le tableau résultant nommé `truncated`.
let truncated = null;
console.log("truncated");
console.table(truncated);

// Q5 Trier le tableau `truncated` par longueur de mots croissante, et à longueur égale, en ordre alphabétique décroissant.
// Afficher le tableau résultant nommé `sorted`. La méthode localeCompare peut être utile.
let sorted = null;
console.log("sorted");
console.table(sorted);

// Q6 Supprimer les doublons du tableau `sorted` pour ne conserver qu'un exemplaire de chaque mot,
// sans utiliser l'idiome `[...new Set(sorted)]`.
// Afficher le tableau résultant nommé `unique` (34 mots).
let unique = [];
console.log("unique");
console.table(unique);
