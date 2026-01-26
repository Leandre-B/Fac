#!/bin/bash

SAVEIFS=$IFS
IFS=$'\n'
t=($( cat $1 ))
for ligne in ${t[@]};do
    printf "<%s>\n" "$ligne"
done

IFS=$SAVEIFS
