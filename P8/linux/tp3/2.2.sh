# !/ bin / bash
NomFichier=" "
NomSortie=" "
Recursif=0

nb=0
while [[ $# -gt 0 ]];
do
    case $1 in

        "-r")
            Recursif=1
            ;;

        "-fichier")
            shift
            NomFichier=$1
            ;;

        "-sortie")
            shift
            NomSortie=$1
            ;;

        "-help")
            echo "-r : recursif"
            echo "-fichier nom_fichier_entre"
            echo "-sortie nom_fichier_sortie"
    esac
    shift
done


echo " Récursif : $Recursif "
echo " Fichier d'entrée : $NomFichier "
echo " Fichier de sortie : $NomSortie "