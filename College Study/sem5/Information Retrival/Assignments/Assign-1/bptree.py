import constants

class Node:
    
    class DataPointerPair:
        def __init__(self, data):
            self._pointer = None            
            self.data = data

        @property
        def pointer(self):
            return self._pointer

        @pointer.setter
        def pointer(self, value):
            if value and not isinstance(value, Node):
                raise TypeError("The pointer must point to a Node")

            self._pointer = value        

    def __init__(self, node_id):
        
        self.id = node_id
        self._parent = None
        self._right_child = None
        self._data_pointer_pairs = list()

    def __repr__(self):
        return str(f"<node {self.id}>")
    
    def __str__(self):
        return f"<node {self.id}> (rt:{str(repr(self.right_child))}) :"
    
    @property
    def parent(self):
        return self._parent

    @parent.setter
    def parent(self, value):
        if value and not isinstance(value,Node):
            raise TypeError("pointer must be of type Node")

        self._parent = value


    @property
    def right_child(self):
        return self._right_child

    @right_child.setter
    def right_child(self, value):
        if value and not isinstance(value,Node):
            raise TypeError("pointer must be of type Node")

        self._right_child = value

    @property
    def data_pointer_pairs(self):
        return self._data_pointer_pairs

    @data_pointer_pairs.setter
    def data_pointer_pairs(self, pairs):
        if len(pairs) > constants.btree_node_size:
            raise ValueError("No of pairs can not be greater than node size")

        self._data_pointer_pairs = pairs

    def add_data_pointer_pair(self,data,pointer):
        if len(self._data_pointer_pairs) >= constants.btree_node_size:
            raise ValueError("No of pairs can not be greater than node size")
        
        new_pair = self.DataPointerPair(data)
        new_pair.pointer = pointer

        self._data_pointer_pairs.append(new_pair)