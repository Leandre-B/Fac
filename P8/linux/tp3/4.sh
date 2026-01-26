#!/bin/bash

# ./exif_mv.sh --src images --dest galerie - mask '*.jpg'
SAVEIFS=$IFS

directory="../images"
target="images"

for file in $(ls $directory);do
    date=$(exiftool $directory/$file | grep "Date/Time Original")
    date=${date//" "/" "}
    date=$(echo $date | cut -d " " -f4)
    date=${date//":"/" "}
    date=($date)
    echo ${date[@]}

    if [[ ${#date[@]} -ne 0 ]];then
        mkdir $target 2>/dev/null
        mkdir $target/${date[0]} 2>/dev/null
        mkdir $target/${date[0]}/${date[1]} 2>/dev/null
        mkdir $target/${date[0]}/${date[1]}/${date[2]} 2>/dev/null

        cp $directory/$file $target/${date[0]}/${date[1]}/${date[2]}
        else
            echo "Pas de date associé"
    fi
done


IFS=$SAVEIFS
