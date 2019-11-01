import re

text = "A quick fox jumps over the lazy dog"
ll = ['abc', 'aabgd', 'xyzw']
doc = """
    \d Digit [0-9]
    \D non digit [^0-9]
    \s any space character like \t \n etc
    \S non whitespace character
    \w any alphanumeric char
    \W any non-alphanumeric

"""

p = re.compile('abc*')

print(p.match('abcabc'))