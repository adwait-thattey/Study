"""
This is my solution for the contraction algorithm to find min cut as discussed in the Stanford Course 1 Algorithms.
It works for undirected graphs

n: Number of vertices
m: Total number of edges
k: Number of edges in min-cut

There are 3 steps

1. Preprocessing: It sorts the adjacency list so as to better identify duplicates
2. Select random edge: It selects 2 random vertices, i.e selects 1 random edge
3. Delete all edges between these 2 vertices to remove self loops
4. Merge all entries of vertex 2 into vertex 1 and delete the row of vertex 2. Sort list of vertex again.
5. Finds out all instances of vertex 2 in the entire graph and changes them to vertex 1
6. Repeats step 2-5 until number of vertices has reduced to 2

There is only some probability of getting a correct answer. But repeating this procedure (n**2)log(n) times ensures that we get correct answer at least once.


"""
import random
from copy import deepcopy
from math import log2

class Graph:
    def __init__(self,graph_file):
        """
        @param graph_file : A file containing the adjacency list

        This creates a graph object with the adjacency list. The preprocessing step is also done here
        """
        self.adjacency_list = dict()
        F = open(graph_file)
        for line in F:
            line = line.split()
            key = line[0]
            line = line[1:]
            line.sort()            
            self.adjacency_list[key] = line 
            self.remove_self_loops(key)  

    def select_random_edge(self):
        """
        @return: A tuple containing vertex1 and vertex2 i.e. a random key and a random index from list of that key
        """
        vertex1 = random.choice(list(self.adjacency_list.keys()))
        vertex2 = random.choice(self.adjacency_list[vertex1])
        return(vertex1,vertex2)

    def remove_edges_between_vertex(self,vertex1,vertex2):
        """
        Removes all edges between given 2 vertices. (Used to remove self loops during contraction)
        """    
        while True:
            try:
                self.adjacency_list[vertex1].remove(vertex2)
            except ValueError:
                break

        while True:
            try:
                self.adjacency_list[vertex2].remove(vertex1)
            except ValueError:
                break        
    
    def contract_vertices(self,vertex1,vertex2):
        """
        Performs contraction between given 2 vertices. After this only vertex 1 will remain. Vertex 2 gets merged into vertex1
        """
        self.remove_edges_between_vertex(vertex1,vertex2)
        if len(self.adjacency_list[vertex2]) > 0:
            self.adjacency_list[vertex1].extend(self.adjacency_list[vertex2])
            self.adjacency_list[vertex1].sort()
            
            zero_list = self.adjacency_list[vertex2][0]
            self.adjacency_list[zero_list] = [vertex1 if elem==vertex2 else elem for elem in self.adjacency_list[zero_list]]

            for i in range(1,len(self.adjacency_list[vertex2])):
                if self.adjacency_list[vertex2][i] == self.adjacency_list[vertex2][i-1]:
                    continue

                cur_v = self.adjacency_list[vertex2][i]

                self.adjacency_list[cur_v] = [vertex1 if elem==vertex2 else elem for elem in self.adjacency_list[cur_v]]

        del(self.adjacency_list[vertex2])

    def remove_self_loops(self,vertex1):
        """
        @param vertex1: A key of the dictionary. Removes all self loops for this vertex only. Requires that the list is sorted
        """
        try:
            pos = self.adjacency_list[vertex1].index(vertex1)
            while self.adjacency_list[vertex1][pos]==vertex1:
                self.adjacency_list[vertex1].pop(pos)
        except ValueError:
            pass    

    def ret_min_cut(self):
        """
        Performs contractions until only 2 vertices remain and returns number of edges remaining between them.   
        """
        while len(self.adjacency_list) > 2:
            v1,v2 = self.select_random_edge()
            self.contract_vertices(v1,v2)

        first_key = list(self.adjacency_list.keys())[0]
        return len(self.adjacency_list[first_key])

def start(file_name):
    G = Graph(file_name)
    Graph_copy = deepcopy(G)
    n = len(G.adjacency_list)
    count = n*n*log2(n)

    min_cut = G.ret_min_cut()
    while count > 0:
        count-=1
        random.seed()
        G = deepcopy(Graph_copy)
        cur_min_cut = G.ret_min_cut()
        if cur_min_cut < min_cut :
            min_cut = cur_min_cut

    return min_cut

if __name__=="__main__":
    import sys
    try:
        filename = sys.argv[1]
    except:
        raise ValueError("No Valid File Provided")

    print(start(filename))        
