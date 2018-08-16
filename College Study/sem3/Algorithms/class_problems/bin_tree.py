#!/usr/bin/python3
"""
"""


class Node:
    """A node in the vanilla BST tree."""

    def __init__(self, k, parent=None):
        """Creates a node.
        
        Args:
            parent: The node's parent.
            k: key of the node.
        """
        self.key = k
        self.parent = parent
        self.left = None
        self.right = None

    def _str(self):
        """Internal method for ASCII art."""
        label = str(self.key)
        if self.left is None:
            left_lines, left_pos, left_width = [], 0, 0
        else:
            left_lines, left_pos, left_width = self.left._str()
        if self.right is None:
            right_lines, right_pos, right_width = [], 0, 0
        else:
            right_lines, right_pos, right_width = self.right._str()
        middle = max(right_pos + left_width - left_pos + 1, len(label), 2)
        pos = left_pos + middle // 2
        width = left_pos + middle + right_width - right_pos
        while len(left_lines) < len(right_lines):
            left_lines.append(' ' * left_width)
        while len(right_lines) < len(left_lines):
            right_lines.append(' ' * right_width)
        if (middle - len(label)) % 2 == 1 and self.parent is not None and \
                self is self.parent.left and len(label) < middle:
            label += '.'
        label = label.center(middle, '.')
        if label[0] == '.': label = ' ' + label[1:]
        if label[-1] == '.': label = label[:-1] + ' '
        lines = [' ' * left_pos + label + ' ' * (right_width - right_pos),
                 ' ' * left_pos + '/' + ' ' * (middle - 2) +
                 '\\' + ' ' * (right_width - right_pos)] + \
                [left_line + ' ' * (width - left_width - right_width) + right_line
                 for left_line, right_line in zip(left_lines, right_lines)]
        return lines, pos, width

    def __str__(self):
        return '\n'.join(self._str()[0])


class BinTree:
    def __init__(self, items=None):
        self.root = None
        self.count = 0
        if items is not None:
            self.insert(items)

    def __str__(self):
        if self.root is None:
            return '<empty tree>'
        return str(self.root)

    def insert(self, items):
        if items is None:
            return

        if self.root is None:
            self.root = Node(items[0])
            items.pop(0)
            self.count = 1

        for x in items:
            bin_pos = bin(self.count + 1)
            bin_string = str(bin_pos)[3:]
            # print("bin_pos", bin_string)
            pos = self.root
            for i in range(len(bin_string)-1):
                if str(bin_string[i]) == '0':
                    pos = pos.left
                else:
                    pos = pos.right

            if pos.left is None:
                new_node = Node(x, parent=pos)
                pos.left = new_node
            elif pos.right is None:
                pos.right = Node(x, parent=pos)

            self.count+=1