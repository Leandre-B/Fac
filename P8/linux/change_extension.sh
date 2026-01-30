#!/bin/bash
if [[ $# = "0" ]];then
    printf "Bad usage. do -help : extension_to_replace_with\n"

    else
        if [[ $1 = "-help" ]];then
            printf "Usage : %s extension_to_replace extension_to_replace_with\n" $0
        else
            if [[ $# -lt 2 ]];then
                printf "Bad usage. do -help : extension_to_replace_with\n"
            else
                arg1=$1
                arg2=$2
                if [[ ${arg1:0:1} != "." ]] || [[ ${arg2:0:1} != "." ]];then
                    printf "Bad usage. do -help : extension_to_replace_with\n"
                else
                    tab=$(find -maxdepth 1 -name "*$1")
                    for v in ${tab[@]};do
                        mv $v ${v/$1/$2}
                    done
                fi
            fi
    fi
fi