

if [[ $# -lt 2 ]];then
    echo "Manque d'argument."
    echo "Usage : fusion.sh <output> <data>"
fi

header=0; # Pour récupérer une seule fois le header
file_name=$1
shift
while [[ $# -gt 0 ]];
do
    # Si on a pas encore récupéré le header
    if [[ $header -eq 0 ]];then
        header=1
        cat $1 > $file_name # On met le fichier en sortie
    fi

    # On met le reste dans un fichier annexe pour le traitement
        tail -n +2 $1 > TEMP_data_conv.txt

    # Si le fichier est en ISO-8859 / Latin-1
    is_latin1=$(file $1 | grep 'ISO-8859')
    if [[ ${#is_latin1} -gt 0 ]]; then
        # On le convertie en UTF-8
        iconv -f latin1 -t utf8 -o TEMP_data_conv.txt TEMP_data_conv.txt
    fi

    # Si le fichier n'est pas en CSV
    is_CSV=$(file $1 | grep 'CSV')
    if [[ ${#is_CSV} -eq 0 ]]; then
        sed -i 's/;/,/g' TEMP_data_conv.txt # On remplace les ';' par des ','
    fi

    # Push la date bien formatée dans le fichier de sortie
    cat TEMP_data_conv.txt >> $file_name


    rm TEMP_data_conv.txt
    shift

done