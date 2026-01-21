#!/bin/bash

ch=$1
for (( i=0 ; i < ${#ch} ; i=i+1 )); do
    for(( j=0 ; j< ${ch:i:1} ; j=j+1 )); do
        echo -n "*"
    done
    echo ""
done