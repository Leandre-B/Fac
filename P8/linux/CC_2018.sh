#!/bin/bash
SAVEIFS=$IFS

function print_pourcentage (){
    local i
    printf "["
    for (( i=0 ; i<$1/10 ; i++ ));do
        printf "#"
    done
    for (( i=$(($1/10 +1)) ; i<=10 ; i++ ));do
        printf "."
    done
    printf "]"
}

cmd=(df)
sort=0

while [[ $# -ne 0 ]];do
    case $1 in
        "-h")
            cmd+=(-h)
            ;;

        "-l")
            cmd+=(-l)
            ;;

        "--total")
            cmd+=(--total)
            ;;

        "--sort")
            sort=1
            ;;

        "--help")
            echo "Usage : dfbar [-h] [-l] [--total] [--sort] [--help]"
            ;;

        *)
            echo "Error: unsupported option: $1"
            exit
    esac
    shift
done

IFS=$'\n'

echo ${cmd[@]}
result=($(${cmd[@]}))
size=($(${cmd[@]}))

if [[ $sort -eq 1 ]];then
    for (( i=1; i<$((${#size[@]})); i++ ));do
        size[$i]=$(echo ${result[$i]}| grep -o "[0-9]*%" | cut -d "%" -f1)
    done


    for (( i=1; i<$((${#result[@]}-1)); i++ ));do
        for (( j=$i; j<${#result[@]}; j++ ));do
            if [[ ${size[$i]} -lt ${size[$j]} ]];then
                aux=${result[$i]}
                result[$i]=${result[$j]}
                result[$j]=$aux

                aux=${size[$i]}
                size[$i]=${size[$j]}
                size[$j]=$aux
            fi

        done

    done

fi

for (( i=0; i<$((${#result[@]})); i++ ));do
    prct=$(echo ${result[$i]} | grep -o "[0-9]*%" | cut -d "%" -f1)
    if [[ $prct == "" ]];then
        echo "          "
    else
        print_pourcentage "$prct"
    fi
    echo ${result[$i]}
done


IFS=$SAVEIFS