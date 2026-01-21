#!/bin/bash

for f in $(find -name "*jpeg");
do
    mv $f "${f/jpeg/jpg}"
done