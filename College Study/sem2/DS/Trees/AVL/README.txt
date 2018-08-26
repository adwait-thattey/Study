This directory contains implementations of different Binary Search Trees
(BSTs), in particular vanilla (unbalanced) BSTs

1. bst.py: Vanilla BSTs.

   This is a revised version of bst.py from the previous recitation, which
   adds a few return values and support for ASCII art and random testing.


USAGE
-----

bst.py can be tested interactively from a UNIX shell as follows:

python bst.py 10 -- do 10 random insertions, printing BST at each step

Alternatively, you can specify explicit key values for particular test cases:

python bst.py 1 2 3 4 5 6 7 8 9 10 -- display bad behavior in BST

Alternatively, you can use them from a Python3 shell as follows:

>>> import bst
>>> t = bst.BST()
>>> print(t)
<empty tree>
>>> for i in range(4):
...   t.insert(i)
...
>>> print(t)
0
/\
 1
 /\
  2
  /\
   3
   /\
>>> t.delete_min()
>>> print(t)
1
/\
 2
 /\
  3
  /\


