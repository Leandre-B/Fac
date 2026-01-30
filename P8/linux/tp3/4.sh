#!/bin/bash

# ./exif_mv.sh --src images --dest galerie --mask '*.jpg'
SAVEIFS=$IFS
ask=false
mask=*
while [[ $# -ne 0 ]];do
    case $1 in
        "--src")
            shift
            source=$1
            shift;;

        "--dest")
            shift
            destination=$1
            shift;;
        
        "--ask")
            shift
            ask=true
            shift;;

        "--mask")
            shift
            mask=$1
            shift;;

        "--help")
            printf "/4.sh --src [source] --dest [dest] (--help)\n"
            exit 1;;

        *)
            exit 1;;

    esac
done;

if ! [[ -d $source ]];then
    printf "Source is invalid\n"
    exit 1
fi

if [[ $destination == "" ]];then
    printf "Destination is invalid\n"
    exit 1
fi

for file in $(ls $source);do
    if [[ $file == $mask ]];then
        date=$(exiftool $source/$file | grep "Date/Time Original")
        date=${date//" "/" "}
        date=$(echo $date | cut -d " " -f4)
        date=${date//":"/" "}
        date=($date)
        #echo ${date[@]}

        if [[ ${#date[@]} -ne 0 ]];then
            mkdir $destination 2>/dev/null
            mkdir $destination/${date[0]} 2>/dev/null
            mkdir $destination/${date[0]}/${date[1]} 2>/dev/null
            mkdir $destination/${date[0]}/${date[1]}/${date[2]} 2>/dev/null

            cp $source/$file $destination/${date[0]}/${date[1]}/${date[2]}
        elif [[ $ask = "true" ]];then
                echo "Pas de date associé, veuillez en entrer une : "
                printf "Année : "
                read annee
                printf "Mois : "
                read mois
                printf "Jour : "
                read jour

                mkdir $destination 2>/dev/null
                mkdir $destination/$annee 2>/dev/null
                mkdir $destination/$annee/$mois 2>/dev/null
                mkdir $destination/$annee/$mois/$jour 2>/dev/null
                
                cp $source/$file $destination/$annee/$mois/$jour
                exiftool -overwrite_original -DateTimeOriginal="$annee:$mois:$jour 00:00:00" $destination/$annee/$mois/$jour/$file 
        fi
    fi
done


IFS=$SAVEIFS
