<?php
//////////////////////////////////////////////////////////////////////////////////////////
// Q1.1 Extraire les disciplines du fichier "disciplines.json" sous forme de tableau indexé 
// contenant 1 tableau associatif par numéro de discipline.
// Voici le tableau attendu (à décommenter si vous ne répondez pas à la question) :
// $disciplines = [
//     1 => [ 
//         'discipline' => 'Mathématiques et leurs interactions',
//         'sous-disciplines' => [ 'Mathématiques et leurs interactions'] 
//     ],
//     2 => [
//         'discipline' => 'Physique',
//         'sous-disciplines' => [ 'Constituants élémentaires, physique théorique, plasmas chauds', 'Milieux denses, matériaux et composants', 'Milieux dilués et optique fondamentale', 'Physique et science des matériaux', ] 
//     ],
//     3 => [ 
//         'discipline' => 'Sciences de la terre et de l’univers, espace',
//         'sous-disciplines' => [ 'Astronomie, astrophysique', 'Sciences de la terre et de l’univers', 'Terre, enveloppes fluides', 'Terre solide et couches profondes', 'Terre solide et enveloppes superficielles', ]
//     ],
//     4 => [
//         'discipline' => 'Chimie',
//         'sous-disciplines' => [ 'Chimie des matériaux', 'Chimie et chimie physique', 'Chimie organique, minérale, industrielle', 'Chimie théorique, physique, analytique', 'Génie des matériaux', ]
//     ],
//     5 => [
//         'discipline' => 'Biologie, médecine et santé',
//         'sous-disciplines' => [ 'Aspects moléculaires et cellulaires de la biologie', 'Sciences de la vie et de la santé', 'Biomolécules, Pharmacologie, Thérapeutique', 'Physiologie, Biologie des organismes, populations, interactions', 'Recherche clinique, Innovation technologique, Santé publique', ]
//     ],
//     6 => [
//         'discipline' => 'Sciences humaines et humanités',
//         'sous-disciplines' => [ 'Cultures et langues régionales', 'Langue et littérature françaises', 'Langues et littératures anciennes', 'Langues et littératures anglaises et anglo-saxonnes', 'Langues et littératures arabes, chinoises, japonaises, hébraïques', 'Langues et littératures germaniques et scandinaves', 'Langues et littératures romanes : espagnol, italien, portugais, autres langues', 'Langues et littératures slaves', 'Lettres et langues', 'Littératures comparées', 'Sciences du langage : linguistique et phonétique générales', 'Arts : plastiques, spectacle, musique, esthétique, sciences et histoire de l’art', 'Épistémologie, histoire des sciences et des techniques', 'Éthique et déontologie', 'Philosophie', 'Théologie', ]
//     ]
// ];

//////////////////////////////////////////////////////////////////////////////////////////
// Q1.2 Récupérer les données <n° discipline, année de soutenance> soumises en HTTP POST, 
// ou, s'il s'agit du premier chargement du fichier en HTTP GET, utiliser les valeurs suivantes :
// - pour le numéro de discipline : le 1er numéro apparaissant dans le fichier "disciplines.json" (!! ne pas coder en dur !!)
// - pour l'année de soutenance : 2020 (à coder en dur) 
$numero_ds        = null;
$annee_soutenance = null;


//////////////////////////////////////////////////////////////////////////////////////////
// Q1.3 Extraire la discipline (tableau associatif) correspondant au n° de discipline.
// Voici un exemple de tableau attendu, ici pour la paire <1,2020> (à décommenter si vous ne répondez pas à la question) :
// $discipline = [ 
//     'discipline'       => 'Mathématiques et leurs interactions',
//     'sous-disciplines' => [ 'Mathématiques et leurs interactions' ]
// ];

//////////////////////////////////////////////////////////////////////////////////////////
// Q1.4 Extraire les statistiques de soutenances sous forme de tableau associatif 
// pour la paire <n° discipline, année de soutenance> par appel en HTTP GET à l'API 
// fournie par le fichier "./api/api.php" déployé sur votre serveur local.
// Les champs à fournir à ce fichier sont :
// - "numero_ds" : le n° de discipline
// - "annee_soutenance" : l'année de soutenance
//
// Voici le tableau attendu pour la paire <1,2020> (à décommenter si vous ne répondez pas à la question) :
// $ds_annee = [ 
//     'numero_ds'            => '1',
//     'annee_soutenance'     => '2020',
//     'nombre_soutenances'   => 30,
//     'nombre_soutenances_f' => 14,
//     'nombre_soutenances_h' => 16,
//     'moins_de_40_mois'     => 25,
//     'de_40_a_52_mois'      => 5,
//     'de_52_a_72_mois'      => 0,
//     'plus_de_6_ans'        => 0
// ];
?>

<!DOCTYPE html>
<html lang="fr">

<head>
    <meta charset="UTF-8">
    <title>Statistiques ED MathSTIC</title>
    <link rel="stylesheet" type="text/css" href="ed.css" />
</head>

<body>
    <h1>Statistiques de l'ED <span
            title="École doctorale Mathématiques et Sciences et Technologies de l'Information et de la Communication">MathSTIC</span>
    </h1>
    <form method="POST" action="<?= $_SERVER[ 'PHP_SELF' ] ?>">
        <label for="numero_ds">Discipline scientifique :</label>
        <select id="numero_ds" name="numero_ds">
            <?php
            //////////////////////////////////////////////////////////////////////////////////////////
            // Q1.5 Générer les options du menu déroulant où chaque option 
            // - correspond à une discipline,
            // - a pour attribut HTML `value` le numéro de la discipline,
            // - a pour noeud texte le nom de la discipline,
            // - et est préselectionnée si son numéro est égal au numéro par défaut ou à celui qui a été soumis 
            ?>
        </select>
        <br><br>

        <label for="annee_soutenance">Année de soutenance :</label>
        <input type="number" id="annee_soutenance" name="annee_soutenance" value="<?= $annee_soutenance ?>" min="2017"
            max="2023" required><br><br>

        <input type="submit" value="Rechercher">
    </form>

    <div class="container">
        <?php
        //////////////////////////////////////////////////////////////////////////////////////////
        // Q1.6 Affichez les statistiques extraites correspondant à la paire <n° discipline, année de soutenance>.
        // Pour chaque statistique, créez 2 éléments DIV :
        // - un pour le libellé de la statistique (p. ex. "nombre_soutenances")
        // - l'autre pour sa valeur (p. ex. 12)
        // Pour la première "ligne", créez 2 DIV donnant le nom de la discipline et son numéro.
        // Remplacez les tirets-bas '_' par une espace dans tous les libellés.
        
        // Exemple de code HTML à générer pour la paire <1,2020> :
            // <div>Mathématiques et leurs interactions</div>
            // <div>1</div>
            // <div>annee soutenance</div>
            // <div>2020</div>
            // <div>nombre soutenances</div>
            // <div>30</div>
            // <div>nombre soutenances f</div>
            // <div>14</div>
            // <div>nombre soutenances h</div>
            // <div>16</div>
            // <div>moins de 40 mois</div>
            // <div>25</div>
            // <div>de 40 a 52 mois</div>
            // <div>5</div>
            // <div>de 52 a 72 mois</div>
            // <div>0</div>
            // <div>plus de 6 ans</div>
            // <div>0</div>
        ?>
    </div>

</body>

</html>