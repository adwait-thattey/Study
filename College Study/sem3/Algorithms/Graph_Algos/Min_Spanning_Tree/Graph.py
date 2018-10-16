
class Graph:

    def __init__(self, adj_list=None):
        self.adj_list = dict()

        if adj_list:
            if not isinstance(adj_list, dict):
                raise ValueError("Incoming Adjacency List must be a dictionary")
            self.adj_list = adj_list

    def add_edge(self, v1, v2, weight):
        if v1 not in self.adj_list:
            self.adj_list[v1] = list()
        if v2 not in self.adj_list:
            self.adj_list[v2] = list()

        self.adj_list[v1].append((v2,weight))

    def sort(self, reverse = False):
        for v in self.adj_list.keys():
            self.adj_list[v].sort(key=lambda x: x[0], reverse=reverse)

    def __str__(self):
        ret_str = ""
        for v in sorted(list(self.adj_list.keys())):
            ret_str += str(v) + " : "
            for v2 in self.adj_list[v]:
                ret_str += str(v2) + ", "
            ret_str += "\n"
        
        return ret_str        
