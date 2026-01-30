#!/bin/bash

nombre=$1

for (( i=0 ; i<${#nombre} ; i++ )); do

    for(( j=0 ; j<${nombre:i:1} ; j++ ));do
        printf "*"
    done
    echo
done