#!/bin/bash


t=($(ls))
echo
echo ${t[@]}
echo
for(( i=0 ; $i<${#t[@]}-1; i++ )); do
    for (( j=i ; j<${#t[@]} ; j++));do
        if [[ ${#t[$j]} -gt ${#t[$i]} ]];then
            aux=${t[i]}
            t[i]=${t[j]}
            t[j]=$aux
        fi
    done
done

echo ${t[@]}
echo

for(( i=0 ; i<${#t[@]} ; i=$i+2 ));do
    printf "indice : %s | string : %s\n" $i ${t[$i]}
done

echo