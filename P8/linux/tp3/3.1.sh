#!/bin/bash

tab=($(ls))
echo ${tab[@]}

#bubble sort
for (( i=0 ; i<${#tab}-1 ; i=i+1 ));do
    for (( j=1 ; j<${#tab} ; j=j+1 ));do
        a=${tab[i]}
        b=${tab[j]}
        if [[ ${#a} -gt ${#b} ]]
        then
            temp=${tab[i]}
            tab[i]=${tab[j]}
            tab[j]=$temp
        fi
    done
done
echo ""
echo ${tab[@]}