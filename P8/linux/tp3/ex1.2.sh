#!/bin/bash

for v in $(find / -regex ".*\.\(png\|pdf\)"  2>/dev/null -size +1M);
do
    echo $(du -h $v | cut -f 1) " # " $v
done