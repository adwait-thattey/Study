#!/bin/bash

#-----------------------------------tr---------------------------------------------------------

#lower to upper
tr "[a-z]" "[A-Z]"
tr '[:lower:]' '[:upper:]'

# space to tabs
tr [:space:] '\t'
tr '\s' '\t'

# reduce multiple space to single squeeze
tr -s [:space:] ' '
# delete specific character
tr -d 'c'
tr -d [:digit:] #delete digits
tr -cd [:digit:] #delete chars

#--------------------------------sed----------------------------------------------

#Replacing or substituting string

sed 's/stringA/stringB/' file

#Replace nth occurrence

sed 's/stringA/stringB/n' file

# Replace all

sed 's/stringA/stringB/g' file

# () for each starting letter

sed 's/\(\b[A-Z]\)/\(\1\)/g' file

# Replace in the nth line

sed 'n s/stringA/stringB/' file

# Replace in the range of lines

sed '1,n s/stringA/stringB/' file

sed '1,$ s/stringA/stringB/' file

# deleting a specific line

sed 'nd' file
sed '1, nd' file
#delete last line
sed '$d' file

#delete a pattern
sed '/pattern/d' file

#-------------------------------------------------grep---------------------------------------

#search 'string' in a file 

grep 'word' filename
grep 'word' *
grep -w 'word' * #exact word
#search without case sensitive

grep -i 'word' filename

#count matches

grep -c 'word' *
grep -l 'word' * #display filename


#-------------------------------------awk-------------------------------

#print matched line

awk '/manager/ {print}' filename

#print columnwise

awk '{print $a,$b}' filename 


