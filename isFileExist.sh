#!/bin/bash
read -p "Enter filename: " file
if [ -e "$file" ]; then
    echo "File exists."
else
    echo "File does not exist."
fi
