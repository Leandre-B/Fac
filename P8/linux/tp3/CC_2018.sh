#!/bin/bash
SAVEIFS=$IFS

pourcentage () {
    printf "["
    for (( i=0 ; i<$1/10 ; i++ ));do
        printf "#"
    done
    for (( i=$(($1/10 +1)) ; i<=10 ; i++ ));do
        printf "."
    done
    printf "]"
}
option=""
sort=0

while [[ $# -ne 0 ]];do
    case $1 in
        "-h")
            option="$option -h"
            shift
            ;;

        "-l")
            option="$option -l"
            shift
            ;;

        "--total")
            option="$option --total"
            shift
            ;;

        "--sort")
            sort=1
            shift
            ;;

        "--help")
            echo "Usage : dfbar [-h] [-l] [--total] [--sort] [--help]";;

        *)
            echo "Error: unsupported option: $1"


    esac
done

IFS=$'\n'
df="df$option"
printf "\"$df\""
df=$($df)
i=0
for ligne in $df;do
    prct=$(echo $ligne | grep -o "[0-9]*%" | cut -d "%" -f1)
    if [[ $prct == "" ]];then
        prct="          "
    else
        pourcentage "$prct"
    fi
    result[$i]="$prct $ligne"
done

echo ${result[@]}

IFS=$SAVEIFS