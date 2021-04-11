#!/bin/bash

if [[ $# -eq 0 ]]
    then
        echo "Usage: ./create.sh <number>"
        exit 1
fi
touch "$1_incomplete.cpp"
cat ~/kickstart/template.cpp > "$1_incomplete.cpp"
