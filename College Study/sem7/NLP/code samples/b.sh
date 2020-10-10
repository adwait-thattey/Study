#!/bin/bash

#-----------------------------------tr---------------------------------------------------------

#lower to upper
#tr "[a-z]" "[A-Z]" < para.txt


# count number of .txt files in a folder


for file in *.txt; do
  echo "${file##*/}"

  sed "1 s/^/This is my first line ${file##*/}\n/" *.txt >> final
done
