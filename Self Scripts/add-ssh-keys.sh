#!/bin/bash

echo "Run by preceeding with a dot '.' or source. Otherwise won't work"
echo "Starting ssh agent"
eval $(ssh-agent -s)
echo "Following items are available in ~/.ssh/"
ls ~/.ssh/
echo "Type the name of key you want to use"
read key_name
ssh-add ~/.ssh/$key_name
result=$?
if [ $result -eq 0 ]
then
    echo "Key added successfully"
else
    echo "Error occured"
fi
    