#!/bin/bash
SAVEIFS=$IFS
IFS=$' '
duh=$(df -h)
chemin=${duh//" "/" "}
# echo $chemin
# echo

size=$(echo ${chemin[@]} | cut -d " " -f4)
chemin=$(echo ${chemin[@]} | cut -d " " -f6)

IFS=$'\n'
chemin=($chemin)
size=($size)

#sort by depth of chemin
#bubble sort
for (( i=1 ; i<${#chemin[@]}-1 ; i++ ));do
    for (( j=i+1 ; j<${#chemin[@]} ; j++ ));do
        folder1=${chemin[$i]}
        folder1=(${folder1//"/"/" "})
        folder2=${chemin[$j]}
        folder2=(${folder2//"/"/" "})

        if [[ ${#folder1} -lt ${#folder2} ]];then
            aux=${chemin[$i]}
            chemin[$i]=${chemin[$j]}
            chemin[$j]=$aux

            aux=${size[$i]}
            size[$i]=${size[$j]}
            size[$j]=$aux
        fi
    done
done

trouve=0
cpt=1

while [[ $trouve -eq 0 ]] && [[ $cpt -ne ${#chemin[@]} ]];do
    if [[ $(pwd) == ${chemin[$cpt]}* ]];then
        trouve=1
    fi
    cpt=$((cpt + 1))
done

printf "Repertoire : %s\nTaille dispo : %s\n" "${chemin[$(($cpt-1))]}" "${size[$(($cpt-1))]}"


IFS=$SAVEIFS
